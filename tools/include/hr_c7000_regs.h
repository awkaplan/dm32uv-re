/*
 * hr_c7000_regs.h - the HR_C7000 peripheral registers that DM-32UV firmware patches touch.
 * HAND-MAINTAINED. Deliberately small: pin mux (IO_DIPLEX0/1/2), GPIOA/B/C, the PIC mask and
 * status words, TIMER, WDG and the ADC data registers. Nothing else.
 *
 * SOURCE OF TRUTH. The full register map is data/registers/: HR_C7000-DM32.svd (every register
 *   with its datasheet section/page and firmware evidence) and HR_C7000-DM32.h (the same map as
 *   C), with provenance, conventions and the datasheet errors corrected in data/registers/
 *   README.md. In that map SystemControl and TIMER are hand-maintained and everything else is
 *   generated from the HR_C7000 v2.7 English guide. This header copies only what patches need
 *   and adds the DM-32 traps from this repo's docs. Its IO_DIPLEX2 per-field layout was
 *   transcribed for this header from DS 4.4.4.6 (p.101-105); the map now carries the same
 *   layout for IO_DIPLEX0-2 (SYSCTL_IO_DIPLEXn_* in its header). If the map changes, re-check
 *   the entries here against it.
 *
 * CONFIDENCE TAGS (every entry carries one or more):
 *   [DS]   HR_C7000 v2.7 English guide (HR_C7000_v2.7_en.pdf, 734 pages), section and PDF page.
 *   [FW]   read in the stock DM32.00.01.048 program image (load base 0x03000000) at the address
 *          given. "[FW, checked]" means re-disassembled with tools/src/dm32_patch_tools/
 *          cs_disasm.py while writing this header (2026-10-10).
 *   [HW]   observed on a real DM-32UV.
 *   [QEMU] behaviour of this repo's -M dm32 model (vendor/dm32uv-qemu).
 *   [DOC]  taken from a doc in this repo that cites its own evidence (docs/, tools/examples/).
 *   [INF]  inferred, not directly confirmed. Treat it as a hypothesis.
 *
 * TYPES. No typedefs of u32/uint32_t here: dm32_patch_api.h and dm32_ui.h each typedef
 * u8/u16/u32 without a guard, and data/registers/HR_C7000-DM32.h typedefs uint32_t. Registers are
 * spelled `volatile unsigned int` (what u32 is on CK803S), through the HRC_U32 macro, so this
 * header can be included before or after any of them. Every macro and struct tag is prefixed
 * HRC_/hrc_ so nothing collides with the generated include/dm32/structs.h (GPIO_Type, WDG_Type,
 * TIMER_Type, PIC_Type, ADC_Type) or with data/registers/HR_C7000-DM32.h's GPIOA_BASE etc.
 *
 * STYLE matches dm32_patch_api.h: an address cast to a pointer, used as `*HRC_IO_DIPLEX2 |= x`.
 * The dense blocks (GPIO, TIMER, WDG, ADC) also get a struct, used as `HRC_GPIOB->EXT_PORTA`.
 *
 * Runtime MMIO only. Nothing here is per-unit data and nothing here writes flash.
 */
#ifndef HR_C7000_REGS_H
#define HR_C7000_REGS_H

#define HRC_U32 unsigned int
#define HRC_REG32(addr) ((volatile HRC_U32 *)(addr))

/* C99-compatible compile-time check (no _Static_assert, no <stddef.h>). */
#define HRC_STATIC_ASSERT(name, cond) typedef char hrc_static_assert_##name[(cond) ? 1 : -1]
#define HRC_OFFSETOF(type, member) __builtin_offsetof(type, member)
HRC_STATIC_ASSERT(u32_is_32_bits, sizeof(HRC_U32) == 4);

/* ==========================================================================================
 * SystemControl @ 0x11000000: pin multiplexing (IO_DIPLEX0/1/2)
 *
 * Every pad of the SoC has one function select here. The general rule [DS 4.4.4.4-4.4.4.6,
 * p.93-105]: each field's all-ones value selects the pad's GPIO function (GPIO_PTxN = bank x,
 * bit N), and each field resets to its GPIO value, except the five JTAG selects in IO_DIPLEX0
 * [4:0], which reset to 0 = JTAG. A pad must be switched away from GPIO before its peripheral
 * (LCD, ADC, SPI, UART...) sees it; GPIO registers do nothing to a pad that is muxed away.
 * ========================================================================================== */
#define HRC_SYSCTL_BASE  0x11000000u
#define HRC_IO_DIPLEX0   HRC_REG32(HRC_SYSCTL_BASE + 0x34u) /* [DS 4.4.4.4 p.93-97] */
#define HRC_IO_DIPLEX1   HRC_REG32(HRC_SYSCTL_BASE + 0x38u) /* [DS 4.4.4.5 p.97-101] */
#define HRC_IO_DIPLEX2   HRC_REG32(HRC_SYSCTL_BASE + 0x3cu) /* [DS 4.4.4.6 p.101-105][FW] */

/* IO_DIPLEX0 summary [DS 4.4.4.4 p.93-97] (field value 1, or 3 for 2-bit fields, = GPIO):
 *   [31] ptb7 (GPIOB 7 / AK_ADC_SDO)     [30:20] reserved
 *   [19:17] PWM_2..PWM_0 (GPIOA 17..15)
 *   [16:15] UART3_TXD (GPIOA 14)         [14:13] UART3_RXD (GPIOA 13)
 *   [12:9]  UART2_TXD/RXD, UART1_TXD/RXD (GPIOA 12..9)
 *   [8:5]   I2C1_SDA/SCL, I2C0_SDA/SCL (GPIOA 8..5)
 *   [4:0]   JTAG RST_N/TDO/TDI/TCK/TMS (GPIOA 4..0); reset 0 = JTAG. Setting these loses JTAG.
 * IO_DIPLEX1 summary [DS 4.4.4.5 p.97-101]:
 *   [31:27] ptb6..ptb2 (GPIOB 6..2 / AK codec ADC_SCLK, ADC_FS, DAC_SDI, DAC_SCLK, DAC_FS);
 *           the guide prints bit 30's name as "PTB4", a typo for ptb5_sel.
 *   [26:19] TIME_SLOT_T/R_INTER, BS_INTER_OUT/IN (GPIOA 31..28), 2 bits each
 *   [18:9]  SPI1 MISO/MOSI/SCLK/CSN_1/CSN_0 (GPIOA 27..23), 2 bits each
 *   [8:0]   SPI0 MISO/MOSI/SCLK (2 bits each), CSN_1 (1 bit), CSN_0 (2 bits) (GPIOA 22..18)
 * Patches should not need to write IO_DIPLEX0/1; they are here so a read can be decoded. */
#define HRC_IO_DIPLEX0_JTAG_Msk  0x0000001fu  /* [DS] 0 = JTAG (reset), 1 = GPIOA 0..4 */

/* IO_DIPLEX2 fields [DS 4.4.4.6 p.101-105]. Pad = the GPIO it becomes at the all-ones value. */
#define HRC_IO_DIPLEX2_CLK_OUT_SEL_Msk  0x00000003u /* [1:0] 3 GPIOC0, 2 RTC_CLK, 1 PLLB, 0 PLLA */
                                                    /* [2] reserved */
#define HRC_IO_DIPLEX2_LCD_CS_SEL_Msk   0x00000018u /* [4:3] 3 GPIOC3, 2/1 SPI2_CS slave/master, 0 LCD_CS */
#define HRC_IO_DIPLEX2_LCD_RS_SEL_Msk   0x00000060u /* [6:5] 3 GPIOC4, 2/1 SPI2_SCLK s/m, 0 LCD_RS */
#define HRC_IO_DIPLEX2_LCD_WR_SEL_Msk   0x00000080u /* [7]   1 GPIOC5, 0 LCD_WR */
#define HRC_IO_DIPLEX2_LCD_RD_SEL_Msk   0x00000100u /* [8]   1 GPIOC6, 0 LCD_RD */
#define HRC_IO_DIPLEX2_LCD_DB0_SEL_Msk  0x00000600u /* [10:9] 3 GPIOC7, 2/1 SPI2_MISO s/m, 0 LCD_DB0 */
#define HRC_IO_DIPLEX2_LCD_DB1_SEL_Msk  0x00001800u /* [12:11] 3 GPIOC8, 2/1 SPI2_MOSI s/m, 0 LCD_DB1 */
#define HRC_IO_DIPLEX2_LCD_DB2_SEL_Msk  0x00002000u /* [13] 1 GPIOC9,  0 LCD_DB2 */
#define HRC_IO_DIPLEX2_LCD_DB3_SEL_Msk  0x00004000u /* [14] 1 GPIOC10, 0 LCD_DB3 */
#define HRC_IO_DIPLEX2_LCD_DB4_SEL_Msk  0x00008000u /* [15] 1 GPIOC11, 0 LCD_DB4 */
#define HRC_IO_DIPLEX2_LCD_DB5_SEL_Msk  0x00010000u /* [16] 1 GPIOC12, 0 LCD_DB5 */
#define HRC_IO_DIPLEX2_LCD_DB6_SEL_Msk  0x00020000u /* [17] 1 GPIOC13, 0 LCD_DB6 */
#define HRC_IO_DIPLEX2_LCD_DB7_SEL_Msk  0x00040000u /* [18] 1 GPIO, 0 LCD_DB7. The guide prints
                                                     * GPIO_PTC24 (also claimed by bit 28);
                                                     * GPIOC14 by the pattern [INF]. */
#define HRC_IO_DIPLEX2_ADC_IN_SEL_Pos   19u         /* [26:19] bit 19+n: 1 GPIOC(15+n), 0 ADCn_IN */
#define HRC_IO_DIPLEX2_ADC_IN_SEL(n)    (1u << (HRC_IO_DIPLEX2_ADC_IN_SEL_Pos + (n)))
#define HRC_IO_DIPLEX2_DAC_VOUT_SEL_Msk 0x38000000u /* [29:27] DAC_VOUT_MCUC/B/A: 1 GPIOC25/24/23 */
                                                    /* [31:30] reserved */
#define HRC_IO_DIPLEX2_RESET_VALUE      0x3ffffffbu /* [DS] every field at its GPIO default */

/* ------------------------------------------------------------------------------------------
 * HARDWARE TRAP: KEYPAD SCAN vs LCD DATA BUS (read before calling the stock keypad scan)
 *
 * The LCD data pads DB0..DB4 are GPIOC 7..11, the keypad lines the scan drives. They cannot be
 * the LCD bus and keypad lines at the same time:
 *   - Every stock keypad scan (keypad_scan_and_map_pressed_key @0x03013660) first calls
 *     0x03012e14, which does  IO_DIPLEX2 |= 0xfe00  (DB0..DB4 to GPIO), then clears GPIOC
 *     SWPORTA_DR bits 7..11 and makes pins 0x47..0x4b outputs.        [FW, checked]
 *     (Corpus name: keypad_scan_begin_mux_rows_drive_low @0x03012e14; its body is the mux claim.)
 *   - lcd_bus_restore_after_keypad_scan @0x0301cad0 (dm32_patch_api.h) undoes it:
 *         IO_DIPLEX2 &= 0xffff01ff   (i.e. &= ~0xfe00)                   [FW, checked]
 *   - The panel init lcd_controller_power_on_init_sequence @0x03017d4c claims all panel pads
 *     with IO_DIPLEX2 &= 0xfff80107 (literal at 0x03017f4c).            [FW, checked]
 *   - A patch that scans and does not restore leaves DB0..DB4 on GPIO, so every following LCD
 *     write misses the panel: it freezes white until the next power cycle. [HW: Snake v21,
 *     2026-10-10, tools/examples/snake/HISTORY.md v22]. The QEMU model now forces LCD data to
 *     white while IO_DIPLEX2 & 0xfe00 is non-zero.                       [QEMU, docs/qemu-workflow.md]
 * Rule: call lcd_bus_restore_after_keypad_scan() after EVERY scan, before the next LCD write,
 * inside the LCD/keypad semaphore hold (dm32_patch_api.h, docs/keypad-input.md). Do not
 * hand-write IO_DIPLEX2 for this; call the stock function so the two stay in step.
 * Note: the 0xfe00 mask is exactly HRC_IO_DIPLEX2_LCD_DB0..DB4_SEL. The datasheet confirms the
 * shared pads are GPIOC 7..11 (LCD_DB0..4 = GPIO_PTC7..11), not the GPIOB row inputs; this
 * settles open item 6 in docs/patch-patterns.md in favour of HISTORY.md v22.
 * ------------------------------------------------------------------------------------------ */
#define HRC_IO_DIPLEX2_KEYPAD_SCAN_GPIO 0x0000fe00u /* DB0..DB4 to GPIO; set by the scan [FW] */
#define HRC_IO_DIPLEX2_LCD_PANEL_PADS   0x0007fef8u /* ~0xfff80107: CS, RS, WR, DB0..DB7 [FW] */
#define HRC_LCD_BUS_IS_ON_GPIO() ((*HRC_IO_DIPLEX2 & HRC_IO_DIPLEX2_KEYPAD_SCAN_GPIO) != 0u)

/* ==========================================================================================
 * GPIOA/B/C: Synopsys DesignWare APB GPIO, one bank per block    [DS 5.7, p.377-385]
 *
 * Every register is one bit per pin. "Port A" in the names is the DesignWare IP's port A,
 * which is the only port each bank has: GPIOB's data register is still SWPORTA_DR.
 * Firmware pin numbers: pin = bank * 32 + bit, bank 0 = A, 1 = B, 2 = C; flash labels such as
 * "pin 0x47" mean GPIOC bit 7. [FW, checked: gpio_pin_set_output_level @0x0301d184 picks the
 * bank by pin < 0x20 / < 0x40, clears the pin's INTEN/INTTYPE_LEVEL/INT_POLARITY bits, sets
 * its SWPORTA_DDR bit, then sets or clears SWPORTA_DR.]
 * ========================================================================================== */
#define HRC_GPIOA_BASE 0x14020000u /* [DS Register Table 20 p.379] PIC source 15 */
#define HRC_GPIOB_BASE 0x14100000u /* [DS Register Table 21 p.380] PIC source 14 */
#define HRC_GPIOC_BASE 0x14110000u /* [DS Register Table 22 p.381] PIC source 17 */
#define HRC_GPIO_PIN(bank, bit) ((bank) * 32u + (bit))

typedef struct hrc_gpio {
    volatile HRC_U32 SWPORTA_DR;       /* 0x00 output data. [DS 5.7.5.1 p.381] */
    volatile HRC_U32 SWPORTA_DDR;      /* 0x04 direction, 1 = output. [DS 5.7.5.2 p.381; the
                                        * polarity is not printed there: FW, checked, at 0x0301d184
                                        * which sets the bit to drive a pin] */
    volatile HRC_U32 RESERVED_08[10];  /* 0x08-0x2f */
    volatile HRC_U32 INTEN;            /* 0x30 interrupt enable. [DS 5.7.5.3 p.383] */
    volatile HRC_U32 INTMASK;          /* 0x34 interrupt mask. [DS 5.7.5.4 p.383] */
    volatile HRC_U32 INTTYPE_LEVEL;    /* 0x38 interrupt type, level or edge. [DS 5.7.5.5 p.383] */
    volatile HRC_U32 INT_POLARITY;     /* 0x3c interrupt polarity. [DS 5.7.5.6 p.383] */
    volatile const HRC_U32 INTSTATUS;  /* 0x40 masked interrupt status (RO). [DS 5.7.5.7 p.383] */
    volatile const HRC_U32 RAW_INTSTATUS; /* 0x44 status before masking (RO). [DS 5.7.5.8 p.383] */
    volatile HRC_U32 DEBOUNCE;         /* 0x48 debounce enable. Printed RO; the stock firmware
                                        * writes it on all three banks. [DS 5.7.5.9 p.385][FW] */
    volatile HRC_U32 PORTA_EOI;        /* 0x4c write 1 to clear an interrupt. Printed RO; it is
                                        * written by stock. [DS 5.7.5.10 p.385][FW] */
    volatile const HRC_U32 EXT_PORTA;  /* 0x50 pin input levels (RO). Read inputs HERE, not at
                                        * SWPORTA_DR. [DS 5.7.5.11 p.385][FW: IRAM 0x2c588
                                        * gpio_read_input_bit, per vendor/dm32uv-qemu
                                        * hw/gpio/dm32_gpio.c][QEMU] */
    volatile HRC_U32 RESERVED_54[9];   /* 0x54-0x77. No LS_SYNC at 0x60: the chip's own table
                                        * does not list it (SystemControl register table). The
                                        * generated include/dm32/structs.h still names it. */
    volatile HRC_U32 INTR_BOTH_EDGE;   /* 0x78 1 = both-edge interrupt; set INTTYPE_LEVEL to edge
                                        * first, write 0 when unused. [DS 5.7.5.12 p.385] */
} hrc_gpio_t;
HRC_STATIC_ASSERT(gpio_ddr, HRC_OFFSETOF(hrc_gpio_t, SWPORTA_DDR) == 0x04);
HRC_STATIC_ASSERT(gpio_inten, HRC_OFFSETOF(hrc_gpio_t, INTEN) == 0x30);
HRC_STATIC_ASSERT(gpio_eoi, HRC_OFFSETOF(hrc_gpio_t, PORTA_EOI) == 0x4c);
HRC_STATIC_ASSERT(gpio_ext, HRC_OFFSETOF(hrc_gpio_t, EXT_PORTA) == 0x50);
HRC_STATIC_ASSERT(gpio_both, HRC_OFFSETOF(hrc_gpio_t, INTR_BOTH_EDGE) == 0x78);
HRC_STATIC_ASSERT(gpio_size, sizeof(hrc_gpio_t) == 0x7c);

#define HRC_GPIOA ((hrc_gpio_t *)HRC_GPIOA_BASE)
#define HRC_GPIOB ((hrc_gpio_t *)HRC_GPIOB_BASE)
#define HRC_GPIOC ((hrc_gpio_t *)HRC_GPIOC_BASE)

/* The two keypad registers, pointer style. */
#define HRC_GPIOB_EXT_PORTA    HRC_REG32(HRC_GPIOB_BASE + 0x50u) /* keypad lines are read here */
#define HRC_GPIOC_SWPORTA_DR   HRC_REG32(HRC_GPIOC_BASE + 0x00u) /* keypad lines are driven here */

/* Keypad wiring (4x4 matrix plus an Up/Down column), as the stock scan uses it.
 *   Read lines:   GPIOB bits 17..20, read at GPIOB EXT_PORTA; all ones = nothing pressed.
 *                 [FW per tools/examples/snake/HISTORY.md: the scan returns 0 at once when
 *                 this 4-bit field reads all ones]
 *   Driven lines: GPIOC bits 7..11 (pins 0x47..0x4b), one at a time; bit 11 carries Up/Down.
 *                 [FW, checked: 0x03012e14 clears GPIOC DR bits 0xf80 and configures pins
 *                 0x47..0x4b; scan-code table in docs/keypad-input.md, QEMU run r37]
 *   Codes 7 and 4 are GPIOB bits 20 / 19 read low with every driven line high. They are NOT
 *   the arrows (identity unconfirmed). [DOC: docs/keypad-input.md, HISTORY.md]
 * Do not bit-bang these: call keypad_scan_and_map_pressed_key and read the trap above.
 * Doc disagreements this header does not resolve: snake_game.c says the scan drives GPIOC
 * 7..12, and docs/keypad-input.md gives the drive level as both active-high and driven low. */
#define HRC_KEYPAD_READ_MASK   0x001e0000u /* GPIOB bits 17..20 */
#define HRC_KEYPAD_DRIVE_MASK  0x00000f80u /* GPIOC bits 7..11 = LCD_DB0..DB4 pads */

/* Interrupts on GPIOB/GPIOC: DS 5.7.3 (p.379) says only port A has interrupts and ports B, C,
 * D "can only be used as normal input and output pins". Table 30 nevertheless gives GPIOB and
 * GPIOC their own PIC sources (14, 17). Unresolved; do not rely on GPIOB/C interrupts. */

/* ==========================================================================================
 * PIC: programmable interrupt controller @ 0x17000000    [DS 4.7, p.166-187]
 *
 * This is the real interrupt controller; the CK803S built-in VIC at 0xE000E100 is unused by
 * stock. [data/registers/HR_C7000-DM32.svd, PIC description]
 *
 * SOURCE vs VECTOR (the classic mistake, made in this project more than once):
 *   source n is bit n of PIC_MASK / PIC_INT_ST (n = 0..31) or bit n-32 of PIC_MASK_1 /
 *   PIC_INT_ST_1 (n = 32..63). The CPU sees source n as VECTOR n + 32 (PIC_VECTOR resets to 32).
 *   Stock's dispatcher indexes its ISR table (IRAM 0x00045514) by vector - 32 = source.
 *   [DS Table 30 p.168-169; DS 4.7.6.4 p.174][FW: docs/rtos-and-memory.md]
 *   Stock's irq_controller_unmask_and_register_handler @0x0306cf70 takes a VECTOR. [FW]
 * Mask polarity: bit = 1 masks the source; all sources are masked at reset (0xffffffff).
 * Unmask = clear the bit. [DS 4.7.6.3 p.173][HW, 2026-10-01: clearing PIC_MASK bit 1 made the
 * TIMER_1 tick ISR fire; clearing PIC_MASK_1 bit 1 (source 33) did not]
 * All Table 30 sources are level-triggered, active high. [DS Table 30]
 * A patch should not normally write these: they are shared with every stock ISR, and a
 * read-modify-write from task context can race an ISR that updates the same word.
 * ========================================================================================== */
#define HRC_PIC_BASE      0x17000000u
#define HRC_PIC_MODE      HRC_REG32(HRC_PIC_BASE + 0x00u) /* trigger mode, sources 0-31 [DS 4.7.6.1 p.172] */
#define HRC_PIC_PO        HRC_REG32(HRC_PIC_BASE + 0x04u) /* polarity, sources 0-31 [DS 4.7.6.2 p.172] */
#define HRC_PIC_MASK      HRC_REG32(HRC_PIC_BASE + 0x08u) /* mask, sources 0-31 [DS 4.7.6.3 p.173][FW][HW] */
#define HRC_PIC_VECTOR    HRC_REG32(HRC_PIC_BASE + 0x0cu) /* vector base, reset 32 [DS 4.7.6.4 p.174] */
#define HRC_PIC_COW1      HRC_REG32(HRC_PIC_BASE + 0x10u) /* end-of-interrupt (WO) [DS 4.7.6.5 p.174] */
#define HRC_PIC_INT_ST    HRC_REG32(HRC_PIC_BASE + 0x44u) /* request record, sources 0-31, write 1
                                                           * to clear [DS 4.7.6.18 p.180][FW] */
#define HRC_PIC_INT_ST_1  HRC_REG32(HRC_PIC_BASE + 0x48u) /* request record, sources 32-63, W1C
                                                           * [DS 4.7.6.19 p.181][FW] */
#define HRC_PIC_MODE_1    HRC_REG32(HRC_PIC_BASE + 0x60u) /* trigger mode, sources 32-63 [DS 4.7.6.21 p.182] */
#define HRC_PIC_PO_1      HRC_REG32(HRC_PIC_BASE + 0x64u) /* polarity, sources 32-63 [DS 4.7.6.22 p.182] */
#define HRC_PIC_MASK_1    HRC_REG32(HRC_PIC_BASE + 0x68u) /* mask, sources 32-63 [DS 4.7.6.23 p.182][FW][HW] */

#define HRC_PIC_VECTOR_OF_SOURCE(src) ((src) + 32u)
#define HRC_PIC_SOURCE_OF_VECTOR(vec) ((vec) - 32u)
/* Which mask/status word holds a source, and its bit there. */
#define HRC_PIC_MASK_REG(src)   (((src) < 32u) ? HRC_PIC_MASK : HRC_PIC_MASK_1)
#define HRC_PIC_INT_ST_REG(src) (((src) < 32u) ? HRC_PIC_INT_ST : HRC_PIC_INT_ST_1)
#define HRC_PIC_BIT(src)        (1u << ((src) & 31u))

/* Table 30 sources this header's peripherals use [DS Table 30 p.168-169]. Full list:
 * data/registers/HR_C7000-DM32.svd, PIC description. */
#define HRC_PIC_SRC_TIMER_1  1u   /* TIMER.CH[0], the uC/OS-III tick, vector 33 [DS][HW] */
#define HRC_PIC_SRC_TIMER_2  2u
#define HRC_PIC_SRC_TIMER_3  3u
#define HRC_PIC_SRC_TIMER_4  4u
#define HRC_PIC_SRC_TIMER_5  5u
#define HRC_PIC_SRC_TIMER_6  6u   /* TIMER.CH[5], the 10 Hz UI tick, vector 38 [DOC: rtos-and-memory.md] */
#define HRC_PIC_SRC_GPIOB    14u  /* vector 46 */
#define HRC_PIC_SRC_GPIOA    15u  /* vector 47 */
#define HRC_PIC_SRC_GPIOC    17u  /* vector 49 */
#define HRC_PIC_SRC_ADC      26u  /* vector 58 */

/* ==========================================================================================
 * TIMER @ 0x14000000: DesignWare APB timer, 6 channels, 32-bit down-counters  [DS 4.8 p.187-196]
 *
 * Channel stride 0x14. Datasheet TIMER_n (1-based) = CH[n-1] here = PIC source n.
 * [DS Register Table 6 p.188-189; HW: live register dump from a
 * radio, not shipped]. The guide's Table 6 prints Timer5 and Timer6 at 0x3c-0x4c, a copy of
 * Timer4's rows; the stride puts them at 0x50 and 0x64.
 *
 * CH[0] IS THE uC/OS-III TICK. Do not reprogram, disable or EOI it. Live values on a real
 * radio: LoadCount = 0xcd140, ControlReg = 0x03 (enabled, periodic, unmasked). [HW]
 * At the 100 Hz tick (docs/rtos-and-memory.md) that load implies an 84 MHz timer clock
 * (11.9 ns, as that doc says). [INF from HW + DOC]
 * CH[5] (TIMER_6) drives the UI tick. [DOC: docs/rtos-and-memory.md]
 * Which of CH[1..4] stock uses is not established: do not assume any channel is free.
 * [QEMU: vendor/dm32uv-qemu docs/coverage.md calls channels 1-3 unverified]
 * ========================================================================================== */
#define HRC_TIMER_BASE 0x14000000u

typedef struct hrc_timer_ch {
    volatile HRC_U32 LoadCount;           /* +0x00 reload value [DS 4.8.5.1 p.189] */
    volatile const HRC_U32 CurrentValue;  /* +0x04 live down-counter [DS 4.8.5.2 p.189] */
    volatile HRC_U32 ControlReg;          /* +0x08 see HRC_TIMER_CTRL_* [DS 4.8.5.3 p.189] */
    volatile const HRC_U32 EOI;           /* +0x0c READ to clear this channel's interrupt
                                           * [DS 4.8.5.4 p.190-191] */
    volatile const HRC_U32 IntStatus;     /* +0x10 masked interrupt status [DS 4.8.5.5 p.191] */
} hrc_timer_ch_t;

typedef struct hrc_timer {
    hrc_timer_ch_t CH[6];                     /* 0x00, 0x14, 0x28, 0x3c, 0x50, 0x64 */
    volatile HRC_U32 RESERVED_78[10];         /* 0x78-0x9f */
    volatile const HRC_U32 TimersIntStatus;   /* 0xa0 all channels, masked [DS Table 6] */
    volatile const HRC_U32 TimersEOI;         /* 0xa4 READ clears ALL channels, the tick
                                               * included: never read this from a patch */
    volatile const HRC_U32 TimersRawIntStatus;/* 0xa8 all channels, unmasked */
    volatile const HRC_U32 TIMERS_COMP_VERSION; /* 0xac DesignWare IP version */
} hrc_timer_t;
HRC_STATIC_ASSERT(timer_ch_size, sizeof(hrc_timer_ch_t) == 0x14);
HRC_STATIC_ASSERT(timer_ch5, HRC_OFFSETOF(hrc_timer_t, CH[5]) == 0x64);
HRC_STATIC_ASSERT(timer_intst, HRC_OFFSETOF(hrc_timer_t, TimersIntStatus) == 0xa0);
HRC_STATIC_ASSERT(timer_size, sizeof(hrc_timer_t) == 0xb0);

#define HRC_TIMER ((hrc_timer_t *)HRC_TIMER_BASE)
#define HRC_TIMER_CTRL_ENABLE    0x1u /* [0] [DS] */
#define HRC_TIMER_CTRL_PERIODIC  0x2u /* [1] TimerMode, 1 = user-defined (reload from LoadCount);
                                       * polarity per DesignWare convention [INF], consistent with
                                       * the tick's live 0x03 [HW] */
#define HRC_TIMER_CTRL_INT_MASK  0x4u /* [2] 1 = this channel's interrupt masked [DS] */
#define HRC_TIMER_TICK_CHANNEL   0u   /* [HW] */

/* ==========================================================================================
 * WDG: watchdog @ 0x14010000    [DS 4.10 p.212-218]
 *
 * Writes are locked: write HRC_WDG_UNLOCK_KEY to WDG_LOCK to enable writes to ALL watchdog
 * registers; writing any other value re-locks. Reading WDG_LOCK: 0 = unlocked, 1 = locked.
 * Feed: write HRC_WDG_FEED_KEY to WDG_KNOCK (the timeout counter restarts). [DS 4.10.5.1,
 * 4.10.5.6 p.216-218]. Whether a feed also needs the unlock first is implied by "all registers"
 * but not stated for WDG_KNOCK specifically [INF]. A timeout resets the whole chip; default
 * timeout ~60 s, reset pulse ~20 ms. [DS]
 * What stock does is NOT established: a literal search of the program image and the IRAM dump
 * finds neither 0x5ada7200 nor 0x55aadd22 (2026-10-10), and the base 0x14010000 appears only
 * as two literals (0x0302e1ea, 0x0305728c) not traced to a consumer (CLAUDE.md gotcha 2: a
 * literal hit is not a call site). The Snake v10 "freeze" was a livelock that never reset
 * (HISTORY.md), so there is no evidence here of the watchdog biting. This repo's QEMU model maps
 * 0x14010000 as plain RAM (vendor/dm32uv-qemu hw/csky/dm32.c), so it never bites under emulation
 * either. [QEMU]
 * Do not enable the watchdog from a patch. If a long blocking patch loop ever resets the radio
 * on hardware, check whether stock runs the watchdog before suspecting anything else.
 * ========================================================================================== */
#define HRC_WDG_BASE 0x14010000u

typedef struct hrc_wdg {
    volatile HRC_U32 WDG_LOCK;            /* 0x00 key register, reset 0x1 = locked [DS 4.10.5.1 p.216] */
    volatile HRC_U32 WDG_OT_LOAD_H;       /* 0x04 timeout count high [2:0], reset 0x7 [DS 4.10.5.2 p.216] */
    volatile const HRC_U32 WDG_OT_LOAD_L; /* 0x08 timeout count low, reset 0xc0000000; printed RO
                                           * while its high half is RW [DS 4.10.5.3 p.217] */
    volatile HRC_U32 WDG_RST_LOAD;        /* 0x0c reset-pulse length [24:0], reset 0x03f80000
                                           * [DS 4.10.5.4 p.218] */
    volatile HRC_U32 WDG_EN;              /* 0x10 [0] 1 = running, reset 0 [DS 4.10.5.5 p.218] */
    volatile HRC_U32 WDG_KNOCK;           /* 0x14 write the feed key [DS 4.10.5.6 p.218] */
} hrc_wdg_t;
HRC_STATIC_ASSERT(wdg_knock, HRC_OFFSETOF(hrc_wdg_t, WDG_KNOCK) == 0x14);

#define HRC_WDG ((hrc_wdg_t *)HRC_WDG_BASE)
#define HRC_WDG_UNLOCK_KEY 0x5ada7200u /* [DS 4.10.5.1] */
#define HRC_WDG_FEED_KEY   0x55aadd22u /* [DS 4.10.5.6] */

/* ==========================================================================================
 * ADC: CPU-side 10-bit ADC, channels A..H    [DS 5.9 p.400-423]
 *
 * Each data register holds a pair: the first channel in [9:0], the second in [25:16].
 * [DS 5.9.5.13-5.9.5.16 p.420-421]. Channel index n = letter 'A' + n: stock's reader table at
 * 0x030ada14 maps n = 0..7 to AB low, AB high, CD low, CD high, ... GH high. [FW, checked]
 * (The corpus names those readers adc_read_chK_low10 / _high9, where K is the register pair,
 * not the channel, and "high9" is wrong: zext r4,r4,0x19,0x10 is bits [25:16], 10 bits, per
 * CLAUDE.md gotcha 3.)
 * Channel C is ADC_DATA_CD & 0x3ff. Stock's battery-voltage path reads it (index 2).
 * [FW, checked: 0x0301cbc0][QEMU: vendor/dm32uv-qemu hw/misc/dm32_adc.c, note 2026-10-09].
 * Scaling to volts is not established here.
 *
 * The data registers only change when a conversion is started; there is no free-running scan
 * in stock. Reading ADC_DATA_CD directly gives the result of stock's LAST read of that channel.
 * For a fresh value call the stock reader instead of driving the ADC yourself:
 *   adc_read_channel_dispatch @0x0301cb44, u32 (*)(u8 channel), returns the 10-bit value, 0 for
 *   channel >= 8. It pends the ADC semaphore at 0x0003a474 (OSSemPend wrapper 0x0300c500,
 *   timeout 0 = forever), waits for ADC_CTRL_STATE bits [5:0] to clear (writing ADC_CTRL_STOP = 2
 *   while busy), writes ADC_CH_VLD = 1 << channel and ADC_START = 1, waits again, reads the
 *   pair register, posts the semaphore. [FW, checked]. Task context only (it blocks). Not yet
 *   in dm32_patch_api.h.
 * A pad must also be muxed to the ADC: IO_DIPLEX2 bit 19+n clear (HRC_IO_DIPLEX2_ADC_IN_SEL).
 * [DS 4.4.4.6][QEMU: a GPIO-muxed pad reads 0, as on silicon]. ADCn_IN = channel 'A'+n is
 * the model's assumption, not a datasheet statement [INF].
 * ========================================================================================== */
#define HRC_ADC_BASE 0x140d0000u /* [DS] PIC source 26 */

typedef struct hrc_adc {
    volatile HRC_U32 ADC_CTRL;            /* 0x00 [DS 5.9.5.1 p.411] */
    volatile HRC_U32 ADC_INTR_DELTA;      /* 0x04 [DS 5.9.5.2 p.411] */
    volatile HRC_U32 ADC_INTR;            /* 0x08 [DS 5.9.5.3 p.411] */
    volatile const HRC_U32 ADC_INTR_STA;  /* 0x0c [DS 5.9.5.4 p.413] */
    volatile HRC_U32 ADC_SCAN_TIME;       /* 0x10 [DS 5.9.5.5 p.415] */
    volatile HRC_U32 ADC_START;           /* 0x14 write 1 to start [DS 5.9.5.6 p.415][FW] */
    volatile HRC_U32 ADC_CTRL_STATE;      /* 0x18 stock waits for & 0x3f == 0 [DS 5.9.5.7 p.415][FW] */
    volatile HRC_U32 ADC_INTR_THRESHOLD;  /* 0x1c [DS 5.9.5.8 p.417] */
    volatile HRC_U32 ADC_CTRL_STOP;       /* 0x20 [DS 5.9.5.9 p.417][FW] */
    volatile HRC_U32 ADC_CH_VLD;          /* 0x24 channel select, 1 << n [DS 5.9.5.10 p.419][FW] */
    volatile HRC_U32 ADC_PD_SEOC_TIME;    /* 0x28 [DS 5.9.5.11 p.419] */
    volatile HRC_U32 ADC_P2S_EN;          /* 0x2c [DS 5.9.5.12 p.419] */
    volatile const HRC_U32 ADC_DATA_AB;   /* 0x30 A [9:0], B [25:16] [DS 5.9.5.13 p.420][FW] */
    volatile const HRC_U32 ADC_DATA_CD;   /* 0x34 C [9:0], D [25:16] [DS 5.9.5.14 p.421][FW] */
    volatile const HRC_U32 ADC_DATA_EF;   /* 0x38 E [9:0], F [25:16] [DS 5.9.5.15 p.421][FW] */
    volatile const HRC_U32 ADC_DATA_GH;   /* 0x3c G [9:0], H [25:16] [DS 5.9.5.16 p.421][FW] */
    volatile const HRC_U32 ADC_CTRL_VERID;/* 0x40 reads 0x20151216 [DS 5.9.5.17 p.421] */
} hrc_adc_t;
HRC_STATIC_ASSERT(adc_data_ab, HRC_OFFSETOF(hrc_adc_t, ADC_DATA_AB) == 0x30);
HRC_STATIC_ASSERT(adc_data_cd, HRC_OFFSETOF(hrc_adc_t, ADC_DATA_CD) == 0x34);
HRC_STATIC_ASSERT(adc_verid, HRC_OFFSETOF(hrc_adc_t, ADC_CTRL_VERID) == 0x40);

#define HRC_ADC ((hrc_adc_t *)HRC_ADC_BASE)
#define HRC_ADC_DATA_CD   HRC_REG32(HRC_ADC_BASE + 0x34u)
#define HRC_ADC_LO10(word) ((word) & 0x3ffu)          /* first channel of a pair */
#define HRC_ADC_HI10(word) (((word) >> 16) & 0x3ffu)  /* second channel of a pair */
/* Last latched channel C value, no conversion started (see the block comment above). */
#define HRC_ADC_CHANNEL_C_LAST() HRC_ADC_LO10(*HRC_ADC_DATA_CD)

#endif /* HR_C7000_REGS_H */
