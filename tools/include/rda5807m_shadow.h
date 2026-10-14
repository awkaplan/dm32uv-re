/*
 * rda5807m_shadow.h - the stock firmware's RDA5807M FM-tuner driver: its RAM shadow of the
 * tuner's registers, the related RAM cells, the init table, and the driver entry points.
 * DM32.00.01.048 only (load base 0x03000000; IRAM addresses are absolute).
 *
 * Register map and field meanings: specs/rdl/rda5807m.rdl (RDA5807M datasheet Rev 1.0, May 2011,
 * section 6). Why a shadow exists: the chip has no register address on the wire. Every write
 * transfer starts at register 02H and auto-increments (high byte first), so changing 05H means
 * rewriting 02H, 03H, 04H and 05H; the driver keeps the last values of those four registers in
 * RAM and resends them [RDA5807M v1.0, 2.5 p.5].
 *
 * CONFIDENCE TAGS (same convention as hr_c7000_regs.h):
 *   [FW]   read in the stock program image by disassembly (tools/src/dm32_patch_tools/lookup.py,
 *          cs_disasm.py), 2026-10-11.
 *   [QEMU] observed under this repo's -M dm32 model, stock image, gdb-stub breakpoints on the
 *          driver, 2026-10-11 (boot only: init, then power-down).
 *   [INF]  inferred, not confirmed.
 * Nothing below has been exercised from patch code on a real radio.
 *
 * THE CORPUS NAMES WERE WRONG for most of this driver (they predated its identification; renamed 2026-10-11): e.g.
 * rda5807m_i2c_send_byte (formerly peripheral_reset_pulse_shift_pattern) is the I2C byte sender, rda5807m_seek_up (formerly tone1_freq_word_record_send) is
 * the seek, rda5807m_seek_complete_poll (formerly battery_level_sample_display_and_flash_save) is the seek-completion poll,
 * rda5807m_fm_on / rda5807m_fm_off (formerly tx_key_tone_start_and_enable / tx_disable_caller_noarg) turn the FM radio on / off. The names
 * here are what the code does; the corpus address is given for each.
 *
 * C99, no includes, no typedefs that collide with dm32_patch_api.h (which typedefs u8/u16/u32).
 */
#ifndef RDA5807M_SHADOW_H
#define RDA5807M_SHADOW_H

/* ------------------------------------------------------------------------------------------
 * Bus. GPIO bit-banged I2C, 7-bit address 0x10 [RDA5807M v1.0, 2.5 p.5].
 * ------------------------------------------------------------------------------------------ */
#define RDA5807M_I2C_ADDR      0x10
#define RDA5807M_I2C_WRITE     0x20  /* [FW] sent by 0x0306559c; [QEMU] first byte of every write */
#define RDA5807M_I2C_READ      0x21  /* [FW] sent by 0x03065628 */
#define RDA5807M_PIN_SDIO      0x19  /* GPIOA bit 25 (logical GPIO id 0x19) [FW] */
#define RDA5807M_PIN_SCLK      0x1A  /* GPIOA bit 26 [FW] */
#define RDA5807M_WRITE_START   0x02  /* first register of every write transfer [RDA 2.5 p.5] */
#define RDA5807M_READ_START    0x0A  /* first register of every read transfer [RDA 2.5 p.5] */

/* ------------------------------------------------------------------------------------------
 * The shadow: registers 02H-05H exactly as the next write transfer sends them, i.e. each 16-bit
 * register BIG-ENDIAN (high byte at the lower address). Not a uint16_t array: the CPU is
 * little-endian. 8 bytes at IRAM 0x00040108 (zero-initialised RAM above the load image) [FW]:
 *   - init 0x0306565c copies the init table's first 8 bytes here after sending the table;
 *   - tune 0x030656ec and seek 0x03065860 store the 02H/03H bytes they send into r02/r03;
 *   - power-down 0x030657c0 stores 0x80 0x00 into r02;
 *   - volume 0x03065694 sets r05[1] low nibble (VOLUME), turns r02[0] == 0xC3 into 0xC0, then
 *     sends all 8 bytes.
 * Reading it gives the last-written values, never the chip's status (that is 0AH/0BH).
 * ------------------------------------------------------------------------------------------ */
typedef struct rda5807m_shadow {
    unsigned char r02[2];  /* 02H control: DHIZ DMUTE MONO BASS ... SEEKUP SEEK ... ENABLE */
    unsigned char r03[2];  /* 03H CHAN[15:6] DIRECT_MODE TUNE BAND[3:2] SPACE[1:0] */
    unsigned char r04[2];  /* 04H DE, SOFTMUTE_EN, AFCD */
    unsigned char r05[2];  /* 05H INT_MODE, SEEKTH[11:8], VOLUME[3:0] */
} rda5807m_shadow_t;

typedef char rda5807m_shadow_is_8_bytes[(sizeof(rda5807m_shadow_t) == 8) ? 1 : -1];

#define RDA5807M_SHADOW        ((volatile rda5807m_shadow_t *)0x00040108)  /* [FW] [QEMU] */
#define RDA5807M_REG_HI(r)     ((r)[0])
#define RDA5807M_REG_LO(r)     ((r)[1])
#define RDA5807M_REG_U16(r)    ((unsigned short)(((r)[0] << 8) | (r)[1]))

/* ------------------------------------------------------------------------------------------
 * Related RAM cells [FW].
 * ------------------------------------------------------------------------------------------ */
/* Current FM frequency in 10 kHz units (e.g. 10110 = 101.10 MHz). Tune and the seek poll take
 * and store it; the seek poll also saves it to the settings in flash (block 4 +0x702, packed BCD
 * by 0x03065918). */
#define RDA5807M_FREQ_10KHZ    ((volatile unsigned short *)0x00040104)
/* Bit 1: band of the last tune. Set when the frequency was >= 76.00 MHz (BAND 2, 76-108 MHz,
 * base 7600), clear below (BAND 3 with 07H bit 9 = 1, 65-76 MHz, base 6500). The seek and the
 * seek poll choose their base from it. */
#define RDA5807M_BAND_FLAGS    ((volatile unsigned char *)0x00040114)
#define RDA5807M_BAND_HIGH     0x02
/* uC/OS-III object taken (OSSemPend wrapper 0x0300c500, timeout 0 = forever) and released
 * (0x0300c53c) around every driver transfer except the bare status read. A patch talking to the
 * tuner directly must take it too. */
#define RDA5807M_BUS_LOCK      ((void *)0x0003b9d0)

/* ------------------------------------------------------------------------------------------
 * Init table [FW]: 0x7a = 122 bytes in program flash, sent after START+0x20 as registers 02H to
 * 3EH, high byte first [QEMU: byte-identical on the wire]. Register: value
 *   02 c001  03 001a  04 0400  05 86af  06 4000  07 56c6  08 0000  09 0000
 *   0a 0000  0b 0000  0c 0000  0d 0000  0e 0000  0f 0000  10 0006  11 0019
 *   12 2a11  13 002e  14 2a30  15 b83c  16 9000  17 2a91  18 8412  19 00a8
 *   1a c400  1b e000  1c 301d  1d 816a  1e 4608  1f 0086  20 0661  21 0000
 *   22 109e  23 24c9  24 0408  25 0608  26 e105  27 3b6c  28 2bec  29 090f
 *   2a 3414  2b 1450  2c 096d  2d 2d96  2e 01da  2f 2a7b  30 0821  31 13d5
 *   32 4891  33 00bc  34 0896  35 153c  36 0b80  37 25c7  38 0000  39 3c58
 *   3a 2a50  3b 262c  3c 0608  3d 0200  3e 0000
 * 10H-3EH are undocumented in RDA5807M v1.0. The datasheet says the address counter wraps after
 * 3AH; the table runs to 3EH anyway (open question, see rda5807m.rdl).
 * ------------------------------------------------------------------------------------------ */
#define RDA5807M_STOCK_INIT_TABLE     ((const unsigned char *)0x030b790c)
#define RDA5807M_STOCK_INIT_TABLE_LEN 0x7a

/* 03H as stock computes it (always 50 kHz spacing, SPACE = 10b) for a frequency f in 10 kHz
 * units: low byte 0x1E/0x1A for a tune (TUNE set), 0x0E/0x0A for a seek. [FW 0x030656ec,
 * 0x03065860] */
#define RDA5807M_STOCK_CHAN(f) \
    ((unsigned short)((((f) < 7600 ? (int)(f) - 6500 : (int)(f) - 7600) / 5) & 0x3ff))
#define RDA5807M_STOCK_TUNE_R03(f) \
    ((unsigned short)((RDA5807M_STOCK_CHAN(f) << 6) | ((f) < 7600 ? 0x1E : 0x1A)))

/* ------------------------------------------------------------------------------------------
 * Driver entry points [FW] (C-SKY ABIv2: r0 = first argument). All but the status read take
 * RDA5807M_BUS_LOCK themselves - do not call them while holding it. [QEMU] for init and
 * power_down only (both run at boot, from radio_boot_full_init_sequence @0x0305f2c8).
 * ------------------------------------------------------------------------------------------ */
/* Manifest name rda5807m_init (was FUN_0306565c). Sends the init table, fills the shadow. Takes no lock. [QEMU] */
#define rda5807m_init \
    ((void (*)(void))0x0306565c)
/* now rda5807m_set_volume (formerly corpus peripheral_gpio_reset_and_configure). VOLUME = vol & 0xf, rewrites 02H-05H. */
#define rda5807m_set_volume \
    ((void (*)(unsigned char vol))0x03065694)
/* rda5807m_tune(f_10khz): f_10khz is the frequency in 10 kHz units (10110 = 101.10 MHz). Manifest name
 * (was corpus device_setting_frame_send_16bit). Writes 02H = 0xC001 and 03H = RDA5807M_STOCK_TUNE_R03(f)
 * and sets/clears RDA5807M_BAND_HIGH. Callers include the FM-on path 0x0306578c. */
#define rda5807m_tune \
    ((void (*)(unsigned short f_10khz))0x030656ec)
/* rda5807m_seek_up(f_10khz): f_10khz in 10 kHz units, the seek start frequency. Manifest name (was corpus
 * tone1_freq_word_record_send). Writes 02H = 0xC301 (seek up, wrap at band edge) and 03H
 * from f with TUNE clear, band from RDA5807M_BAND_FLAGS. Completion is polled by the caller. */
#define rda5807m_seek_up \
    ((void (*)(unsigned short f_10khz))0x03065860)
/* now rda5807m_power_down (formerly corpus mutex_guarded_reset_sequence). Writes 02H = 0x8000 only (ENABLE = 0, muted). */
#define rda5807m_power_down \
    ((void (*)(void))0x030657c0)
/* Manifest name rda5807m_read_reg_0a (was FUN_03065638). Reads 2 bytes = register 0AH into out[0] (high) and out[1] (low).
 * Takes NO lock: its only caller (0x03065bb8) holds RDA5807M_BUS_LOCK around it. */
#define rda5807m_read_reg_0a \
    ((void (*)(unsigned char out[2]))0x03065638)

#endif /* RDA5807M_SHADOW_H */
