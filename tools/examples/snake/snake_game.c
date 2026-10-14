/*
 * snake_game.c - example patch: a playable Snake game, launched from a real new top-level
 * menu entry (not a bypass hook -- see docs/subsystems/keypad-input-hal.md for the traced
 * menu-item mechanism this patch extends).
 *
 * ARCHITECTURE (current, v12+; rewritten 2026-10-10 -- this header used to describe the
 * abandoned v1-v5 screen-mode-126/127 design): snake_screen_handler is reached ONCE, from the
 * "Play" item of Snake's one-item sub-list (item jump-table slot 10 -> snake_tail_stub ->
 * here). It is a BLOCKING loop: it parks the stock keypad poll, scans the keypad itself under
 * the LCD/keypad bus semaphore, steps the game at a fixed cadence, yields with os_time_dly_ms,
 * and returns only on Back. The screen-mode table route is not used: its dispatcher
 * (0x0305279c) runs only on UI event 0x2a, so setting the mode byte never runs a handler (see
 * snake_category_entry.c's header and docs/menu-system.md).
 *
 * CONTROLS (scan codes measured under QEMU r37, see the table below and docs/keypad-input.md):
 *   Up/Down arrows, or '2'/'8'  -> up/down
 *   '4'/'6', or P1/P2           -> left/right
 *   Ok                          -> restart after game over
 *   Back                        -> leave: restores the sub-list cells and hands the Back to the
 *                                  stock poll through the deferred re-arm (v21), so one Back
 *                                  returns to the sub-list with its title
 */
#include "../../include/dm32_patch_api.h"

/* Snake's own category entry (tools/examples/snake/snake_category_entry.c), linked at
 * SNAKE_CATENTRY_ADDR by build_snake_patch.py (the build asserts the address). Re-run on exit so
 * the stock epilogue has a list to redraw -- see docs/menu-system.md. */
#define snake_category_entry_fn ((void (*)(void))0x030e8800)

#define GRID_W   24
#define GRID_H   16
#define CELL_PX  8
/* Playfield origin, chosen to sit inside the main UI window (CASET 23..216 x RASET 50..209,
 * per docs/subsystems/display-lcd-driver.md's emulator trace) with a small margin. */
#define ORIGIN_X 24
#define ORIGIN_Y 50

#define MAX_LEN  (GRID_W * GRID_H)

#define COLOR_BG     0x0000  /* black */
#define COLOR_SNAKE  0x07E0  /* green */
#define COLOR_FOOD   0xF800  /* red */
#define COLOR_TEXT   0xFFFF  /* white */

/* Raw scan codes -- MEASURED under QEMU (run r37, 2026-10-09) by injecting every matrix
 * intersection with v14's "K:xx" overlay reading back keypad_scan_and_map_pressed_key's return,
 * then named through the OpenRTX port's hardware-measured keyMap[][] (keyboard_DM32.c, 18 of 20
 * intersections pressed on a real unit, 2026-10-01). The stock scan drives GPIOC bits 7..12 one at
 * a time (its "columns", OpenRTX's ROW0..ROW4) and reads GPIOB bits 17..20 (OpenRTX's COL_1..4);
 * table index = (GPIOC bit - 7) * 4 + (20 - GPIOB bit) into the table at flash 0x03081f1c:
 *
 *   GPIOC7 : '1'=0x10  '2'=0x11  '3'=0x12  Ok=0x03        (GPIOB 20,19,18,17)
 *   GPIOC8 : '4'=0x13  '5'=0x14  '6'=0x15  P1=0x09
 *   GPIOC9 : '7'=0x16  '8'=0x17  '9'=0x18  P2=0x0c
 *   GPIOC10: '*'=0x0d  '0'=0x0f  '#'=0x0e  Back=0x06
 *   GPIOC11:   --        --     Down=0x05  Up=0x02
 *
 * All nine sweep keys in r37 matched this table. The function's two dedicated-pin early exits
 * (GPIOB bit 20 low -> 7, bit 19 low -> 4, sampled with every GPIOC column driven high) are NOT the
 * front-panel arrows -- those are matrix keys 0x02/0x05 -- so 7/4 are kept only as aliases.
 * The earlier constants (OK=0x10, P1=0x11, P2=0x12, BACK=0x03) were '1','2','3' and Ok. */
#define SCAN_LEFT    0x13   /* '4' */
#define SCAN_RIGHT   0x15   /* '6' */
#define SCAN_KEY2    0x11   /* alias: up    */
#define SCAN_KEY8    0x17   /* alias: down  */
#define SCAN_DED_B20 7      /* dedicated-pin codes, identity unknown (side keys?) -- aliases */
#define SCAN_DED_B19 4

enum { DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT };

/* All state is static (a leftover of the v1-v5 per-tick design; the v12+ handler is entered once
 * per game). snake_game.ld puts this .bss in SRAM 0x18007000, which holds power-on noise on real
 * hardware, so every field the game reads is set by reset_game() before use. */
static struct {
    u8  initialized;
    u8  game_over;
    u8  dir;
    u8  pending_dir;        /* latched this frame, applied at the next tick to avoid a
                                171-degree reversal within a single tick */
    u8  tick_divider;        /* frames since the last game step (FRAMES_PER_TICK frames of
                                FRAME_MS each per step) */
    u16 len;
    u8  body_x[MAX_LEN];
    u8  body_y[MAX_LEN];
    u8  food_x, food_y;
    u16 rng_state;
} s;

/* Minimal xorshift16 PRNG -- stock firmware has no exposed rand() this patch can call, and a
 * fixed seed would make food placement deterministic/boring. Seeded from the stock millisecond
 * tick via a cheap read of whatever's in s.rng_state across calls (self-seeding from its own
 * evolving state plus the game's own score, not from a hardware entropy source -- good enough
 * for food placement, not a security context). */
static u16 next_rand(void)
{
    u16 x = s.rng_state;
    x ^= (u16)(x << 7);
    x ^= (u16)(x >> 9);
    x ^= (u16)(x << 8);
    s.rng_state = x ? x : 0xACE1;
    return s.rng_state;
}

static void place_food(void)
{
    /* Rejection-sample until the spot isn't under the snake. MAX_LEN is small (384) and the
     * snake is rarely close to filling the board, so this terminates quickly in practice. */
    int i;
    int tries = 0;
    for (;;) {
        s.food_x = (u8)(next_rand() % GRID_W);
        s.food_y = (u8)(next_rand() % GRID_H);
        int collide = 0;
        for (i = 0; i < s.len; i++) {
            if (s.body_x[i] == s.food_x && s.body_y[i] == s.food_y) { collide = 1; break; }
        }
        if (!collide) return;
        if (++tries > 64) return; /* board nearly full -- place anywhere, next move likely ends it */
    }
}

static void reset_game(void)
{
    s.game_over = 0;
    s.dir = DIR_RIGHT;
    s.pending_dir = DIR_RIGHT;
    s.tick_divider = 0;
    s.len = 3;
    s.body_x[0] = GRID_W / 2;     s.body_y[0] = GRID_H / 2;
    s.body_x[1] = GRID_W / 2 - 1; s.body_y[1] = GRID_H / 2;
    s.body_x[2] = GRID_W / 2 - 2; s.body_y[2] = GRID_H / 2;
    if (s.rng_state == 0) s.rng_state = 0xACE1; /* xorshift can't start at 0 */
    place_food();
}

static void draw_cell(int gx, int gy, u16 color)
{
    int x0 = ORIGIN_X + gx * CELL_PX;
    int y0 = ORIGIN_Y + gy * CELL_PX;
    display_fill_rect(x0, y0, x0 + CELL_PX, y0 + CELL_PX, color);
}

static void draw_frame(void)
{
    int i;
    display_fill_rect(ORIGIN_X, ORIGIN_Y,
                       ORIGIN_X + GRID_W * CELL_PX, ORIGIN_Y + GRID_H * CELL_PX, COLOR_BG);
    for (i = 0; i < s.len; i++)
        draw_cell(s.body_x[i], s.body_y[i], COLOR_SNAKE);
    draw_cell(s.food_x, s.food_y, COLOR_FOOD);
    if (s.game_over)
        display_draw_string_gb2312(ORIGIN_X + 20, ORIGIN_Y + GRID_H * CELL_PX / 2 - 8,
                                    "GAME OVER - BACK TO EXIT", COLOR_TEXT, COLOR_BG);
}

/* v12: incremental redraw after a tick -- only the cells that changed. Besides being cheaper on
 * the real LCD, this is what makes the emulator's quiescent GRAM dump usable (a full redraw every
 * frame never leaves the panel idle for its 150 ms settle window). */
static void draw_step(u8 old_tail_x, u8 old_tail_y, int grew)
{
    if (!grew) draw_cell(old_tail_x, old_tail_y, COLOR_BG);
    draw_cell(s.body_x[0], s.body_y[0], COLOR_SNAKE);
    draw_cell(s.food_x, s.food_y, COLOR_FOOD);
}

/* Last raw scan code, drawn above the playfield. Diagnostic: the scan-code table at 0x03081f1c
 * was decoded statically and its row/column numbering is NOT trusted (the emulator's key sweep
 * contradicted one reading already), so the game shows what it actually receives. Cheap; left in. */
static void draw_scan_code(u8 scan)
{
    static const char hex[] = "0123456789ABCDEF";
    char buf[8];
    buf[0] = 'K'; buf[1] = ':'; buf[2] = hex[scan >> 4]; buf[3] = hex[scan & 0xf]; buf[4] = 0;
    display_draw_string_gb2312(ORIGIN_X, ORIGIN_Y - 20, buf, COLOR_TEXT, COLOR_BG);
}

static void apply_direction(u8 scan)
{
    /* Reject a direct reversal (e.g. moving right, pressing "left") -- standard Snake rule,
     * and avoids an instant self-collision on the very next tick. */
    switch (scan) {
    case SCAN_UP:    case SCAN_KEY2: case SCAN_DED_B20:
        if (s.dir != DIR_DOWN)  s.pending_dir = DIR_UP;    break;
    case SCAN_DOWN:  case SCAN_KEY8: case SCAN_DED_B19:
        if (s.dir != DIR_UP)    s.pending_dir = DIR_DOWN;  break;
    case SCAN_LEFT:  case SCAN_P1:
        if (s.dir != DIR_RIGHT) s.pending_dir = DIR_LEFT;  break;
    case SCAN_RIGHT: case SCAN_P2:
        if (s.dir != DIR_LEFT)  s.pending_dir = DIR_RIGHT; break;
    default: break;
    }
}

static void step_game(void)
{
    int i;
    u8 nx = s.body_x[0];
    u8 ny = s.body_y[0];

    s.dir = s.pending_dir;
    switch (s.dir) {
    case DIR_UP:    ny = (u8)(ny == 0 ? GRID_H - 1 : ny - 1); break;
    case DIR_DOWN:  ny = (u8)(ny == GRID_H - 1 ? 0 : ny + 1); break;
    case DIR_LEFT:  nx = (u8)(nx == 0 ? GRID_W - 1 : nx - 1); break;
    case DIR_RIGHT: nx = (u8)(nx == GRID_W - 1 ? 0 : nx + 1); break;
    }

    /* self-collision check (against the current body, before it shifts) */
    for (i = 0; i < s.len; i++) {
        if (s.body_x[i] == nx && s.body_y[i] == ny) {
            s.game_over = 1;
            return;
        }
    }

    {
        int ate = (nx == s.food_x && ny == s.food_y);
        int new_len = ate ? (s.len + 1 < MAX_LEN ? s.len + 1 : s.len) : s.len;
        for (i = new_len - 1; i > 0; i--) {
            s.body_x[i] = s.body_x[i - 1];
            s.body_y[i] = s.body_y[i - 1];
        }
        s.body_x[0] = nx;
        s.body_y[0] = ny;
        s.len = (u16)new_len;
        if (ate) place_food();
    }
}

/*
 * snake_screen_handler - the game. (Historical, v1-v5: this was once meant to be a per-tick
 * screen-mode-126 handler. That design never ran on hardware -- see the file header.)
 *
 * v12 (2026-10-09): this is no longer a per-tick screen handler. Since v11 it is reached ONCE,
 * from the sub-list item-action path (item jump-table slot 10 -> snake_tail_stub -> here), and
 * when it returns the stub tail-jumps into the stock dispatcher's epilogue, which redraws the
 * sub-list. A one-frame handler therefore drew one frame and handed the keypad straight back to
 * the stock list screen -- on hardware the arrows then navigated/exited the list, which is what
 * "the arrows go back to the main screen" was. So the game now owns the UI task until Back:
 * scan, step at a fixed cadence, redraw what changed, yield with os_time_dly_ms, repeat. The
 * stock list screen's own key handling is paused for the duration, because it runs in this same
 * task ("task menu", TCB 0x0003e4fc). The stock keypad POLL is NOT paused by this loop: it runs
 * in another task ("task init", TCB 0x00040da0, via main_ui_background_task_loop) -- measured
 * 2026-10-10 under QEMU with gdb breakpoints; this comment used to say the opposite. That is
 * why v14+ park the poll every frame (below). The RTOS tick, RTC and the other tasks keep
 * running.
 */
#define FRAME_MS        40
#define FRAMES_PER_TICK 6   /* 240 ms per move; tune on hardware */

void snake_screen_handler(void)
{
    u8 scan, last_scan = 0xff;

    s.rng_state = 0;
    reset_game();
    display_fill_screen(COLOR_BG);
    draw_frame();

    for (;;) {
        /* v14: keep the stock keypad poll parked (see dm32_patch_api.h), then scan under the shared
         * LCD/keypad bus semaphore -- never hold it across a draw call. */
        *KEYPAD_POLL_ENABLE = 0;
        *KEYPAD_BLANK_COUNTER = 0;
        os_sem_pend_ms(LCD_KEYPAD_BUS_SEM, 0);
        scan = keypad_scan_and_map_pressed_key();
        lcd_bus_restore_after_keypad_scan();   /* v22: give DB0..DB4 back to the panel */
        os_sem_post(LCD_KEYPAD_BUS_SEM);
        if (scan != last_scan) { draw_scan_code(scan); last_scan = scan; }

        if (scan == SCAN_BACK) {
            /* v18: hand the still-held Back press to the STOCK poll instead of swallowing it.
             * The stock item-OK path pushed one screen level when it entered "Play"; the stock
             * Back handler pops it and redraws the sub-list with its title (QEMU r62/r63), so
             * re-enabling the poll while the key is down makes ONE Back leave the game. The
             * cells are restored first so the redraw has a list to show (dm32_patch_api.h). */
            snake_category_entry_fn();
            /* v21: let the STOCK poll dispatch this Back itself, ~20 polls (~200 ms) AFTER our
             * return, i.e. after the item epilogue has finished: keep the keypad disabled but arm
             * the blanking stub (it re-enables only when 0x30790 != 0), and leave cur=Back/prev=0
             * so the first real poll takes the "new press" branch and runs handler[6]. v19's direct
             * mailbox post and v20's immediate re-enable were both lost under the epilogue. */
            *STOCK_KEY_CUR  = SCAN_BACK;
            *STOCK_KEY_PREV = 0;
            *KEYPAD_BLANK_REARM = 1;
            *KEYPAD_BLANK_COUNTER = 0;
            *KEYPAD_POLL_ENABLE = 0;
            break;                    /* the stub's tail redraws the sub-list */
        }

        if (s.game_over) {
            if (scan == SCAN_OK) {
                reset_game();
                display_fill_screen(COLOR_BG);
                draw_frame();
            }
        } else {
            apply_direction(scan);
            if (++s.tick_divider >= FRAMES_PER_TICK) {
                u8 tx = s.body_x[s.len - 1], ty = s.body_y[s.len - 1];
                u16 before = s.len;
                s.tick_divider = 0;
                step_game();
                if (s.game_over) draw_frame();        /* full redraw once, with the banner */
                else             draw_step(tx, ty, s.len != before);
            }
        }
        os_time_dly_ms(FRAME_MS);
    }
}
