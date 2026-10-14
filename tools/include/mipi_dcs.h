/*
 * mipi_dcs.h - MIPI Display Command Set (DCS) opcodes understood by the DM-32UV's panel
 * controller, for patch code and for typing the stock LCD command writer in Ghidra.
 *
 * WHAT THIS IS. The panel sits on the HR_C7000's i8080 port: a command byte is a 32-bit store of
 * the zero-extended byte to 0x12000000, a parameter or pixel byte the same to 0x12000004
 * (lcd_write_command @0x0002c1cc, lcd_write_data @0x0002c1d8, IRAM; both `st.w`). The opcodes
 * below are the standard (vendor-independent) half of its command set. The vendor half is in
 * st7789v.h; MADCTL's bit fields are in specs/rdl/st7789v_madctl.rdl; the stock init sequence is
 * specs/lcd/st7789v_stock_init.txt.
 *
 * SOURCES. Every opcode here is listed in at least one of the two controller datasheets below,
 * and the opcode values agree between them; the section and PDF page for each is on its line.
 *   [HX] Himax HX8353-E datasheet V01 (v0.1), April 2012, chapter 8.2 (command list).
 *   [ST] Sitronix ST7789V datasheet Version 1.3, 2014/03, section 9.1 (system function commands).
 *   The DM-32UV's controller matches the ST7789V (specs/lcd/README.md); HX8353E is the part this
 *   repo used to name, kept as a second source because every opcode value agrees.
 * Opcodes the MIPI DCS standard defines but neither datasheet lists (DSC/compression, 3D, DDB/PPS
 * reads, colour-channel reads, image checksums) are left out on purpose: nothing here is
 * included without a document that says this kind of controller implements it.
 *
 * NAMING. The MIPI_DCS_* names follow the convention of the Linux kernel's
 * include/video/mipi_display.h (enum of MIPI DCS commands), checked against the v6.12 tag on
 * 2026-10-11: every name and value below matches that header. This file was written from the
 * two datasheets above, not copied from it (the Linux header is GPL-2.0; opcode names and values
 * are facts of the MIPI standard). The datasheets' own mnemonics are given in the comments.
 *
 * STOCK USE (DM32.00.01.048, traced by disassembly and confirmed under QEMU, 2026-10-11):
 *   EXIT_SLEEP_MODE, SET_TEAR_ON (param 0x00), SET_ADDRESS_MODE (0xC0 or 0x00), SET_PIXEL_FORMAT
 *   (0x05 = 16 bits/pixel), ENTER_INVERT_MODE, SET_DISPLAY_ON in the panel init @0x03017d4c;
 *   SET_COLUMN_ADDRESS / SET_PAGE_ADDRESS / WRITE_MEMORY_START for every draw (display_set_window
 *   @0x03017c38 via 0x03017be8 / 0x03017c10, lcd_ram_write_begin @0x0301790c). The corpus also names lcd_write_command_arg28h
 *   @0x03017918 (SET_DISPLAY_OFF) and lcd_write_command_arg29h @0x03017924 (SET_DISPLAY_ON),
 *   and FUN_03017930 / FUN_03017940 send ENTER_SLEEP_MODE / EXIT_SLEEP_MODE each followed by a
 *   120 ms delay; none of these four has a recorded caller in meta/xrefs.json.
 *
 * C99, no includes, no typedefs that collide with dm32_patch_api.h or hr_c7000_regs.h.
 */
#ifndef MIPI_DCS_H
#define MIPI_DCS_H

enum mipi_dcs_cmd {
    /* No parameters; also the delay marker in Linux panel-mipi-dbi command files. */
    MIPI_DCS_NOP                    = 0x00, /* NOP        [HX 8.2.1 p.109] [ST 9.1.1 p.162] */
    MIPI_DCS_SOFT_RESET             = 0x01, /* SWRESET    [HX 8.2.2 p.110] [ST 9.1.2 p.163] */

    /* Status reads (read-only; i8080 RD strobe). */
    MIPI_DCS_GET_DISPLAY_ID         = 0x04, /* RDDIDIF (HX), RDDID (ST) [HX 8.2.3 p.111] [ST 9.1.3 p.165] */
    MIPI_DCS_GET_DISPLAY_STATUS     = 0x09, /* RDDST      [HX 8.2.4 p.112] [ST 9.1.4 p.167] */
    MIPI_DCS_GET_POWER_MODE         = 0x0A, /* RDDPM      [HX 8.2.5 p.115] [ST 9.1.5 p.170] */
    MIPI_DCS_GET_ADDRESS_MODE       = 0x0B, /* RDDMADCTL  [HX 8.2.6 p.117] [ST 9.1.6 p.172] */
    MIPI_DCS_GET_PIXEL_FORMAT       = 0x0C, /* RDDCOLMOD  [HX 8.2.7 p.119] [ST 9.1.7 p.174] */
    MIPI_DCS_GET_DISPLAY_MODE       = 0x0D, /* RDDIM      [HX 8.2.8 p.121] [ST 9.1.8 p.176] */
    MIPI_DCS_GET_SIGNAL_MODE        = 0x0E, /* RDDSM      [HX 8.2.9 p.123] [ST 9.1.9 p.178] */
    MIPI_DCS_GET_DIAGNOSTIC_RESULT  = 0x0F, /* RDDSDR     [HX 8.2.10 p.124] [ST 9.1.10 p.180] */

    /* Power and display modes. Stock waits 120 ms after EXIT_SLEEP_MODE. */
    MIPI_DCS_ENTER_SLEEP_MODE       = 0x10, /* SLPIN      [HX 8.2.11 p.125] [ST 9.1.11 p.182] */
    MIPI_DCS_EXIT_SLEEP_MODE        = 0x11, /* SLPOUT     [HX 8.2.12 p.126] [ST 9.1.12 p.184] */
    MIPI_DCS_ENTER_PARTIAL_MODE     = 0x12, /* PTLON      [HX 8.2.13 p.128] [ST 9.1.13 p.186] */
    MIPI_DCS_ENTER_NORMAL_MODE      = 0x13, /* NORON      [HX 8.2.14 p.129] [ST 9.1.14 p.187] */
    MIPI_DCS_EXIT_INVERT_MODE       = 0x20, /* INVOFF     [HX 8.2.15 p.130] [ST 9.1.15 p.188] */
    MIPI_DCS_ENTER_INVERT_MODE      = 0x21, /* INVON      [HX 8.2.16 p.131] [ST 9.1.16 p.190] */
    MIPI_DCS_SET_GAMMA_CURVE        = 0x26, /* GAMSET     [HX 8.2.17 p.132] [ST 9.1.17 p.192] */
    MIPI_DCS_SET_DISPLAY_OFF        = 0x28, /* DISPOFF    [HX 8.2.18 p.133] [ST 9.1.18 p.194] */
    MIPI_DCS_SET_DISPLAY_ON         = 0x29, /* DISPON     [HX 8.2.19 p.134] [ST 9.1.19 p.196] */

    /* Frame-memory window and access. CASET/RASET take 4 parameter bytes: start[15:8],
     * start[7:0], end[15:8], end[7:0], ends inclusive. */
    MIPI_DCS_SET_COLUMN_ADDRESS     = 0x2A, /* CASET      [HX 8.2.20 p.135] [ST 9.1.20 p.198] */
    MIPI_DCS_SET_PAGE_ADDRESS       = 0x2B, /* RASET      [HX 8.2.21 p.137] [ST 9.1.21 p.200] */
    MIPI_DCS_WRITE_MEMORY_START     = 0x2C, /* RAMWR      [HX 8.2.22 p.139] [ST 9.1.22 p.202] */
    MIPI_DCS_WRITE_LUT              = 0x2D, /* RGBSET, colour LUT [HX 8.2.23 p.140]; not in ST7789V */
    MIPI_DCS_READ_MEMORY_START      = 0x2E, /* RAMRD      [HX 8.2.24 p.141] [ST 9.1.23 p.204] */
    MIPI_DCS_SET_PARTIAL_ROWS       = 0x30, /* PTLAR      [HX 8.2.25 p.142] [ST 9.1.24 p.206] */
    MIPI_DCS_SET_SCROLL_AREA        = 0x33, /* VSCRDEF    [HX 8.2.26 p.144] [ST 9.1.25 p.208] */
    MIPI_DCS_SET_TEAR_OFF           = 0x34, /* TEOFF      [HX 8.2.27 p.147] [ST 9.1.26 p.211] */
    MIPI_DCS_SET_TEAR_ON            = 0x35, /* TEON, 1 param: TEM bit 0 (0 = V-blank only)
                                               [HX 8.2.28 p.148] [ST 9.1.27 p.213] */
    MIPI_DCS_SET_ADDRESS_MODE       = 0x36, /* MADCTL, 1 param, see st7789v_madctl.rdl
                                               [HX 8.2.29 p.149] [ST 9.1.28 p.215] */
    MIPI_DCS_SET_SCROLL_START       = 0x37, /* VSCSAD     [HX 8.2.30 p.151] [ST 9.1.29 p.218] */
    MIPI_DCS_EXIT_IDLE_MODE         = 0x38, /* IDMOFF     [HX 8.2.31 p.152] [ST 9.1.30 p.220] */
    MIPI_DCS_ENTER_IDLE_MODE        = 0x39, /* IDMON      [HX 8.2.32 p.153] [ST 9.1.31 p.222] */
    MIPI_DCS_SET_PIXEL_FORMAT       = 0x3A, /* COLMOD, 1 param, MIPI_DCS_PIXEL_FMT_* below
                                               [HX 8.2.33 p.154] [ST 9.1.32 p.224] */
    MIPI_DCS_WRITE_MEMORY_CONTINUE  = 0x3C, /* WRMEMC     [ST 9.1.33 p.225]; not in HX8353E */
    MIPI_DCS_READ_MEMORY_CONTINUE   = 0x3E, /* RDMEMC     [ST 9.1.34 p.227]; not in HX8353E */
    MIPI_DCS_SET_TEAR_SCANLINE      = 0x44, /* STE        [ST 9.1.35 p.229]; not in HX8353E */
    MIPI_DCS_GET_SCANLINE           = 0x45, /* GSCAN      [ST 9.1.36 p.231]; not in HX8353E */

    /* Brightness / CABC (ST7789V only; stock never sends these). */
    MIPI_DCS_SET_DISPLAY_BRIGHTNESS = 0x51, /* WRDISBV    [ST 9.1.37 p.233] */
    MIPI_DCS_GET_DISPLAY_BRIGHTNESS = 0x52, /* RDDISBV    [ST 9.1.38 p.235] */
    MIPI_DCS_WRITE_CONTROL_DISPLAY  = 0x53, /* WRCTRLD    [ST 9.1.39 p.237] */
    MIPI_DCS_GET_CONTROL_DISPLAY    = 0x54, /* RDCTRLD    [ST 9.1.40 p.239] */
    MIPI_DCS_WRITE_POWER_SAVE       = 0x55, /* WRCACE     [ST 9.1.41 p.241] */
    MIPI_DCS_GET_POWER_SAVE         = 0x56, /* RDCABC     [ST 9.1.42 p.243] */
    MIPI_DCS_SET_CABC_MIN_BRIGHTNESS = 0x5E, /* WRCABCMB  [ST 9.1.43 p.245] */
    MIPI_DCS_GET_CABC_MIN_BRIGHTNESS = 0x5F  /* RDCABCMB  [ST 9.1.44 p.247] */
};

/* SET_PIXEL_FORMAT parameter, low 3 bits = MCU (DBI) interface format. Bits 6:4 select the RGB
 * (DPI) interface format on ST7789V and are 0 in stock's 0x05. Both datasheets list only these
 * three codes for the MCU interface (ST7789V adds 111 = "16M truncated").
 * [HX 8.2.33 p.154] [ST 9.1.32 p.224] */
#define MIPI_DCS_PIXEL_FMT_12BIT 3
#define MIPI_DCS_PIXEL_FMT_16BIT 5   /* stock: COLMOD 0x05, RGB565, two bytes per pixel, high first */
#define MIPI_DCS_PIXEL_FMT_18BIT 6   /* power-on default on both controllers */

#endif /* MIPI_DCS_H */
