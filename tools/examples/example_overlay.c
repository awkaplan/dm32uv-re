/*
 * example_overlay.c - minimal, buildable proof that new UI code can drive the stock display.
 *
 * Draws a filled banner with a label over the current screen. This is deliberately the
 * smallest useful thing: it touches ONLY display primitives (no state-machine mutation), so
 * it is safe to call from an existing redraw path without owning a screen-mode ID.
 *
 * Build (from tools/examples/, with ../include on the compiler's search path):
 *   cskybuild.sh csky-abiv2-elf-gcc -mcpu=ck803s -I../include -c example_overlay.c -o example_overlay.o
 * Output: example_overlay.o -> link + objcopy to a raw .bin yourself.
 *
 * NOT PART OF THE OVERLAY BUILD: build_overlay_image.py assembles only overlay_trampoline.S,
 * which draws its own banner inline (blue rect 30,60-210,80 + "CLAUDE") and never calls this
 * file. This is a C variant of that banner (note the different rectangle), kept as a reference
 * for the C half of a larger patch; the Snake example (snake/) shows a complete C build + link.
 *
 * NOTE on -I../include: this only resolves if your toolchain wrapper mounts/exposes paths above
 * this directory. docker/cskybuild.sh (this repo's own, for use INSIDE its Docker image) does,
 * since the whole repo is mounted together - see docker/docker-compose.yml. A wrapper that only
 * mounts the current directory (some external cskybuild.sh variants do this) will need a local
 * copy of dm32_ui.h instead.
 */
#include "dm32_ui.h"

#define BANNER_BG    0x001F   /* blue   */
#define BANNER_TEXT  0xFFFF   /* white  */

/* Main UI window is CASET 23..216 x RASET 50..209 (194x160) per the emulator trace in
 * docs/subsystems/display-lcd-driver.md -- keep the overlay inside it. */
void ui_overlay_banner(const char *msg)
{
    display_fill_rect(23, 50, 216, 72, BANNER_BG);
    display_draw_string_gb2312(28, 56, msg, 0, BANNER_BG);
}

/* Same idea, but also announces a screen mode + requests a redraw. Only call this if you have
 * actually allocated a mode ID (see dm32_ui.h / the screen-mode enum doc). */
void ui_overlay_claim_screen(u8 mode, const char *msg)
{
    ui_overlay_banner(msg);
    ui_set_screen_mode(mode, UI_REDRAW_REQUEST);
}
