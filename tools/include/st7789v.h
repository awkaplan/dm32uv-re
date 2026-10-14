/*
 * st7789v.h - vendor (non-MIPI-DCS) commands of the DM-32UV's LCD controller, for patch code and
 * for typing the stock LCD command writer (lcd_write_command @0x0002c1cc, IRAM) in Ghidra.
 * Standard opcodes: mipi_dcs.h. MADCTL bits: specs/rdl/st7789v_madctl.rdl. Stock init sequence
 * and the identification argument in full: specs/lcd/ (README.md, st7789v_stock_init.txt).
 *
 * WHICH CONTROLLER. The stock panel init (lcd_controller_power_on_init_sequence @0x03017d4c) sends
 * B2h B7h BBh C0h C2h C3h C6h D0h E0h E1h with the opcodes, parameter counts and (for B2h, C0h,
 * C3h) exactly the power-on defaults of the Sitronix ST7789V, a 240RGB x 320 controller, and the
 * firmware draws into a 240 x 320 frame. They do not fit the Himax HX8353E this repo used to name
 * (see the HX8353E block at the end of this file). CONFIDENCE: STRUCTURAL - from the command
 * stream only. Genuine ST7789V or a compatible clone is open: nobody has read the controller ID
 * (RDDID 04h, or RDID1-3 DAh-DCh) on a real radio, and the module marking is not recorded.
 *
 * SOURCES.
 *   [ST] Sitronix ST7789V datasheet Version 1.3, 2014/03, 9.2 "system function command table 2"
 *        (PDF page = printed page). Public; cited by section, not copied.
 *   [HX] Himax HX8353-E datasheet V01 (v0.1), April 2012, 8.2.37-8.2.51.
 *   [FW] stock DM32.00.01.048, lcd_controller_power_on_init_sequence @0x03017d4c (disassembly).
 *   [QEMU] the same function run under this repo's -M dm32 model with gdb breakpoints on the
 *          command/data writers (2026-10-11): byte stream identical to the disassembly.
 *
 * C99, no includes, no typedefs that collide with dm32_patch_api.h, hr_c7000_regs.h or
 * mipi_dcs.h.
 */
#ifndef ST7789V_H
#define ST7789V_H

/* ------------------------------------------------------------------------------------------
 * ST7789V command table 2 - the vendor commands stock sends, in the order the init sends them.
 * "default" is the ST7789V power-on value; "stock" is what DM32.00.01.048 writes [FW] [QEMU].
 * Names are the datasheet's mnemonics.
 * ------------------------------------------------------------------------------------------ */
enum st7789v_cmd {
    ST7789V_PORCTRL   = 0xB2, /* porch: BPA, FPA, PSEN, BPB|FPB, BPC|FPC. default 0C 0C 00 33 33,
                                 stock 0C 0C 00 33 33 (= default)          [ST 9.2.3 p.263] */
    ST7789V_GCTRL     = 0xB7, /* gate: VGHS[6:4], VGLS[2:0]. default 35h; stock 56h
                                 (VGH 14.06 V, VGL -11.38 V)               [ST 9.2.6 p.268-269] */
    ST7789V_VCOMS     = 0xBB, /* VCOM, 25 mV steps from 0.1 V. default 20h (0.9 V); stock 17h
                                 (0.675 V)                                 [ST 9.2.9 p.273-274] */
    ST7789V_LCMCTRL   = 0xC0, /* XOR masks over MADCTL/INVON/GS: XMY XBGR XINV XMX XMH XMV XGS.
                                 default 2Ch; stock 2Ch (= default)        [ST 9.2.10 p.275] */
    ST7789V_VDVVRHEN  = 0xC2, /* VDV/VRH from commands: CMDEN, then FFh. default 01h FFh; stock
                                 sends only the first parameter, 01h       [ST 9.2.12 p.277] */
    ST7789V_VRHS      = 0xC3, /* VRH set. default 0Bh; stock 0Bh (= default) [ST 9.2.13 p.278-279] */
    ST7789V_FRCTRL2   = 0xC6, /* normal-mode frame rate: NLA[7:5] inversion, RTNA[4:0]. default
                                 0Fh; stock EFh (NLA 111 = column inversion, RTNA 0Fh = 60 Hz
                                 with the default porches)                 [ST 9.2.16 p.284-285] */
    ST7789V_PWCTRL1   = 0xD0, /* power: fixed A4h, then AVDD[7:6] AVCL[5:4] VDS[1:0]. default
                                 A4h 81h; stock sends D0h A7h (one parameter, not the documented
                                 A4h - unexplained) and then D0h A4h A1h (AVDD 6.8 V, AVCL -4.8 V,
                                 VDDS 2.3 V)                               [ST 9.2.21 p.290-291] */
    ST7789V_PVGAMCTRL = 0xE0, /* positive gamma, 14 params. stock 70 03 08 07 08 15 30 54 47 3A
                                 15 14 2B 2E                               [ST 9.2.24 p.294-295] */
    ST7789V_NVGAMCTRL = 0xE1, /* negative gamma, 14 params. stock 70 06 0A 09 06 03 2F 44 47 38
                                 12 15 29 2F                               [ST 9.2.25 p.296-297] */
    /* Module ID reads (standard-command chapter, not MIPI DCS opcodes). Never sent by stock;
     * reading them on hardware would identify the part. */
    ST7789V_RDID1     = 0xDA, /* [ST 9.1.46 p.250] */
    ST7789V_RDID2     = 0xDB, /* [ST 9.1.47 p.251] */
    ST7789V_RDID3     = 0xDC  /* [ST 9.1.48 p.252] */
};

/* Stock also sends D6h A1h after PWCTRL1. D6h is not documented in ST7789V v1.3 (command table
 * 2, p.253-254) nor in ST7789VW v1.0 (2017/09); its meaning is unknown. Named only so a Ghidra
 * enum covers every opcode the stock writer receives. */
#define ST7789V_UNDOC_CMD_D6 0xD6

/* ------------------------------------------------------------------------------------------
 * HX8353E (Himax) - NOT THIS RADIO'S CONTROLLER. Kept because the DemoUV008 reference tree
 * (HX8353E.h) and this repo's earlier analysis assumed it, and because each mismatch below is
 * part of the evidence. Stock never sends any of these with these meanings.
 *   - SETEXTC (B9h FFh 83h 53h), needed before the HX8353E's extended commands unless its EXTC
 *     pin is strapped high, is never sent [HX 8.2.43 p.170].
 *   - Stock B2h has 5 parameters (SETDISPLAY: 3), C0h 1 (SETSTBA: 6), BBh 1 (SETOTP's first
 *     parameter is the OTP access key AAh/55h), C3h 1 (SETTID writes the module ID), D0h is
 *     written (GETHID is a read of ID 53h), E0h 14 (SETGAMMA: 19); E1h B7h C2h C6h D6h do not
 *     exist on the HX8353E.
 *   - HX8353E frame memory is at most 132 x 162 [HX 1 p.5, 2 p.6]; stock draws 240 x 320.
 * ------------------------------------------------------------------------------------------ */
enum hx8353e_cmd {
    HX8353E_SETOSC     = 0xB0, /* [HX 8.2.37 p.158] */
    HX8353E_SETPOWER   = 0xB1, /* [HX 8.2.38 p.159] */
    HX8353E_SETDISPLAY = 0xB2, /* 3 params [HX 8.2.39 p.162] */
    HX8353E_SETCYC     = 0xB4, /* [HX 8.2.40 p.164] */
    HX8353E_SETBGP     = 0xB5, /* [HX 8.2.41 p.167] */
    HX8353E_SETCOM     = 0xB6, /* [HX 8.2.42 p.169] */
    HX8353E_SETEXTC    = 0xB9, /* 3 params, FFh 83h 53h enables [HX 8.2.43 p.170] */
    HX8353E_SETOTP     = 0xBB, /* [HX 8.2.44 p.171] */
    HX8353E_SETSTBA    = 0xC0, /* 6 params [HX 8.2.45 p.172] */
    HX8353E_SETTID     = 0xC3, /* [HX 8.2.46 p.175] */
    HX8353E_SETPANEL   = 0xCC, /* 1 param [HX 8.2.47 p.176] */
    HX8353E_GETHID     = 0xD0, /* read, ID 53h [HX 8.2.48 p.177] */
    HX8353E_SETGAMMA   = 0xE0, /* 19 params [HX 8.2.49 p.178] */
    HX8353E_SETSPIREAD = 0xFE, /* [HX 8.2.50 p.179] */
    HX8353E_GETSPIREAD = 0xFF  /* [HX 8.2.51 p.180] */
};

#endif /* ST7789V_H */
