/* GENERATED FILE - do not edit by hand.
 *
 * Struct layouts recovered during reverse engineering.
 * A named field is one whose offset a cited source confirmed; unnamed padding is emitted
 * as explicit reserved arrays and is NOT asserted to be unused - it is merely unrecovered.
 */
#ifndef DM32_STRUCTS_H
#define DM32_STRUCTS_H

#include "types.h"

/* ---- Enumerations ----
 *
 * Names for register numbers, opcodes and command bytes. A function parameter typed
 * with one of these prints the name at every call site that passes a constant, e.g.
 * `fd6818b_reg_write(FD6818_PAGE0_REG_38H, ...)`. In C each is an ordinary `int`
 * enumeration whatever width the analysis database records for it. */

/* fd6818_page0 - 104 constants. */
typedef enum {
    FD6818_PAGE0_REG_00H = 0x00,  /* Chip ID / soft reset [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_01H = 0x01,  /* Revision ID [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_02H = 0x02,  /* Interrupt vector / interrupt clear [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_03H = 0x03,  /* Enable bits (FD6818 only) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_04H = 0x04,  /* Function enables [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_07H = 0x07,  /* CTCSS frequency word [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_08H = 0x08,  /* CDCSS code [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_09H = 0x09,  /* DTMF/SELCALL detector coefficients [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X0A = 0x0A,  /* REG_0x0A (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0BH = 0x0B,  /* DTMF/SELCALL received code [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0CH = 0x0C,  /* Status [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_0X0D = 0x0D,  /* REG_0x0D (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X0E = 0x0E,  /* REG_0x0E (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X10 = 0x10,  /* REG_0x10 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X11 = 0x11,  /* REG_0x11 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X12 = 0x12,  /* REG_0x12 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_13H = 0x13,  /* AGC gain step (FD6818B) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X14 = 0x14,  /* REG_0x14 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_18H = 0x18,  /* MIC PGA gain [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_19H = 0x19,  /* PA bias output [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_1AH = 0x1A,  /* Band select [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X1F = 0x1F,  /* REG_0x1F (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X20 = 0x20,  /* REG_0x20 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X21 = 0x21,  /* REG_0x21 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_22H = 0x22,  /* Crystal-range setting [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_23H = 0x23,  /* AF DAC level [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_24H = 0x24,  /* MCBSP input select / DTMF companion (disputed) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_25H = 0x25,  /* GPIO output enable / value [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_26H = 0x26,  /* GPIO0-3 output select [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_27H = 0x27,  /* GPIO4-7 output select [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_28H = 0x28,  /* GPIO input / PA gain [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_0X29 = 0x29,  /* REG_0x29 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X2B = 0x2B,  /* REG_0x2B (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_2CH = 0x2C,  /* External LNA gain / RX 300 Hz response [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_2DH = 0x2D,  /* RX 300 Hz response [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X30 = 0x30,  /* Enable bits (FD6818B) [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_31H = 0x31,  /* TOT timer [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X32 = 0x32,  /* REG_0x32 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X33 = 0x33,  /* REG_0x33 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_34H = 0x34,  /* Clock gating / index selectors 3-6 [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_35H = 0x35,  /* Clock gating / index selectors 0-2 [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X37 = 0x37,  /* REG_0x37 (undocumented, RX/TX mode) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_38H = 0x38,  /* Frequency, low word [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_39H = 0x39,  /* Frequency, high word [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_3AH = 0x3A,  /* Bandwidth (withdrawn) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_3BH = 0x3B,  /* Crystal frequency, low [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_3CH = 0x3C,  /* Crystal frequency, high [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_3DH = 0x3D,  /* Crystal-range constant [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X3E = 0x3E,  /* REG_0x3E (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_3FH = 0x3F,  /* Interrupt mask [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_40H = 0x40,  /* FM deviation [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_41H = 0x41,  /* Crystal-range constant 2 [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_43H = 0x43,  /* RX filter / TX audio bandwidth [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_44H = 0x44,  /* FM demod gain / DISC mode [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X45 = 0x45,  /* REG_0x45 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_46H = 0x46,  /* VOX thresholds [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_47H = 0x47,  /* AF output path / TX digital gain [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_48H = 0x48,  /* CIC mode (BYPASS) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X49 = 0x49,  /* REG_0x49 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X4A = 0x4A,  /* REG_0x4A (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_4BH = 0x4B,  /* CIC mode 2 (BYPASS) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X4E = 0x4E,  /* REG_0x4E (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_4FH = 0x4F,  /* Noise squelch thresholds [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_50H = 0x50,  /* TX audio mute / limit [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_51H = 0x51,  /* Sub-audio control [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_52H = 0x52,  /* Sub-audio tail / CTCSS detect [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_53H = 0x53,  /* Audio digital gains [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_54H = 0x54,  /* Scrambler / FSK rate [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X55 = 0x55,  /* REG_0x55 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_56H = 0x56,  /* FSK CRC polynomial [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X58 = 0x58,  /* REG_0x58 (undocumented, FSK) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_59H = 0x59,  /* FSK control [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5AH = 0x5A,  /* FSK sync bytes 0-1 [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5BH = 0x5B,  /* FSK sync bytes 2-3 [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5CH = 0x5C,  /* FSK type byte [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5DH = 0x5D,  /* FSK length [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5EH = 0x5E,  /* FSK FIFO thresholds [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5FH = 0x5F,  /* FSK FIFO data [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_60H = 0x60,  /* Sub-audio detect [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_61H = 0x61,  /* SNR [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_62H = 0x62,  /* RSSI (two taps) [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_0X63 = 0x63,  /* REG_0x63 (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_64H = 0x64,  /* VOX amplitude [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_65H = 0x65,  /* Relative RSSI / noise [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_67H = 0x67,  /* Squelch RSSI [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X68 = 0x68,  /* REG_0x68 (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X69 = 0x69,  /* REG_0x69 (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X6A = 0x6A,  /* REG_0x6A (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_70H = 0x70,  /* Tone generator enables / gains [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_71H = 0x71,  /* TONE1 frequency [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_72H = 0x72,  /* TONE2 frequency [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_73H = 0x73,  /* AFC [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X74 = 0x74,  /* REG_0x74 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_75H = 0x75,  /* MCBSP control [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_76H = 0x76,  /* MCBSP data path [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X77 = 0x77,  /* REG_0x77 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_78H = 0x78,  /* RSSI squelch thresholds [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_79H = 0x79,  /* VOX close threshold [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_7AH = 0x7A,  /* VOX delay [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X7B = 0x7B,  /* REG_0x7B (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X7C = 0x7C,  /* REG_0x7C (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_7DH = 0x7D,  /* RX digital gain [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_7EH = 0x7E,  /* DC filters [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_7FH = 0x7F,  /* Page select [DATASHEET] (wire_addr) */
} fd6818_page0;

/* fd6818_page1 - 20 constants. */
typedef enum {
    FD6818_PAGE1_REG_87H = 0x07,  /* Compander amplitude [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_90H = 0x10,  /* Soft mute [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_91H = 0x11,  /* 1050 Hz decode setting [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_94H = 0x14,  /* DTMF/SELCALL detect [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_96H = 0x16,  /* RX DISC gain / RX compander [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_97H = 0x17,  /* MIC sensitivity / TX compander [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_98H = 0x18,  /* RX expander [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_99H = 0x19,  /* TX compressor [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_9AH = 0x1A,  /* Compander timing [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_9BH = 0x1B,  /* Audio filter bypasses [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_9CH = 0x1C,  /* DISC-mode setting [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_9DH = 0x1D,  /* TX audio path select [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A1H = 0x21,  /* Audio response filter A1 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A2H = 0x22,  /* Audio response filter A2 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A3H = 0x23,  /* Audio response filter A3 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A4H = 0x24,  /* Audio response filter A4 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A7H = 0x27,  /* DISC-mode setting 2 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_B0H = 0x30,  /* TX 300 Hz response B0 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_B1H = 0x31,  /* TX 300 Hz response B1 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_B6H = 0x36,  /* Sub-audio filters / gains [DATASHEET] (wire_addr) */
} fd6818_page1;

/* gd25q80_cmd - 35 constants. */
typedef enum {
    GD25Q80_CMD_WRITE_STATUS = 0x01,  /* Write Status Register (WRSR) [STRUCTURAL] DESTRUCTIVE */
    GD25Q80_CMD_PAGE_PROGRAM = 0x02,  /* Page Program (PP) [STRUCTURAL] DESTRUCTIVE */
    GD25Q80_CMD_READ_DATA = 0x03,  /* Read Data [DATASHEET] */
    GD25Q80_CMD_WRITE_DISABLE = 0x04,  /* Write Disable (WRDI) [STRUCTURAL] */
    GD25Q80_CMD_READ_STATUS_LO = 0x05,  /* Read Status Register S7-S0 [STRUCTURAL] */
    GD25Q80_CMD_WRITE_ENABLE = 0x06,  /* Write Enable (WREN) [STRUCTURAL] */
    GD25Q80_CMD_FAST_READ = 0x0B,  /* Fast Read [DATASHEET] */
    GD25Q80_CMD_SECTOR_ERASE = 0x20,  /* Sector Erase (SE) [STRUCTURAL] DESTRUCTIVE */
    GD25Q80_CMD_QUAD_PAGE_PROGRAM = 0x32,  /* Quad Page Program [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_READ_STATUS_HI = 0x35,  /* Read Status Register S15-S8 [STRUCTURAL] */
    GD25Q80_CMD_DUAL_OUTPUT_FAST_READ = 0x3B,  /* Dual Output Fast Read [DATASHEET] */
    GD25Q80_CMD_PROGRAM_SECURITY_REGISTERS = 0x42,  /* Program Security Registers [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_ERASE_SECURITY_REGISTERS = 0x44,  /* Erase Security Registers [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_READ_SECURITY_REGISTERS = 0x48,  /* Read Security Registers [DATASHEET] */
    GD25Q80_CMD_VOLATILE_SR_WRITE_ENABLE = 0x50,  /* Write Enable for Volatile Status Register [DATASHEET] */
    GD25Q80_CMD_BLOCK_ERASE_32K = 0x52,  /* Block Erase 32 KB [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_READ_SFDP = 0x5A,  /* Read Serial Flash Discoverable Parameter [DATASHEET] */
    GD25Q80_CMD_CHIP_ERASE_60 = 0x60,  /* Chip Erase (60h) [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_ENABLE_RESET = 0x66,  /* Enable Reset [DATASHEET] */
    GD25Q80_CMD_QUAD_OUTPUT_FAST_READ = 0x6B,  /* Quad Output Fast Read [DATASHEET] */
    GD25Q80_CMD_PROGRAM_ERASE_SUSPEND = 0x75,  /* Program/Erase Suspend (PES) [DATASHEET] */
    GD25Q80_CMD_SET_BURST_WITH_WRAP = 0x77,  /* Set Burst with Wrap [DATASHEET] */
    GD25Q80_CMD_PROGRAM_ERASE_RESUME = 0x7A,  /* Program/Erase Resume (PER) [DATASHEET] */
    GD25Q80_CMD_MANUFACTURER_DEVICE_ID = 0x90,  /* Read Manufacturer / Device ID (REMS) [DATASHEET] */
    GD25Q80_CMD_RESET = 0x99,  /* Reset [DATASHEET] */
    GD25Q80_CMD_READ_IDENTIFICATION = 0x9F,  /* Read Identification (RDID) [DATASHEET] */
    GD25Q80_CMD_HIGH_PERFORMANCE_MODE = 0xA3,  /* High Performance Mode (HPM) [DATASHEET] */
    GD25Q80_CMD_RELEASE_DEEP_POWER_DOWN_ID = 0xAB,  /* Release from Deep Power-Down / Read Device ID [DATASHEET] */
    GD25Q80_CMD_DEEP_POWER_DOWN = 0xB9,  /* Deep Power-Down [DATASHEET] */
    GD25Q80_CMD_DUAL_IO_FAST_READ = 0xBB,  /* Dual I/O Fast Read [DATASHEET] */
    GD25Q80_CMD_CHIP_ERASE_C7 = 0xC7,  /* Chip Erase (C7h) [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_BLOCK_ERASE_64K = 0xD8,  /* Block Erase 64 KB [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_QUAD_IO_WORD_FAST_READ = 0xE7,  /* Quad I/O Word Fast Read [DATASHEET] */
    GD25Q80_CMD_QUAD_IO_FAST_READ = 0xEB,  /* Quad I/O Fast Read [DATASHEET] */
    GD25Q80_CMD_CONTINUOUS_READ_MODE_RESET = 0xFF,  /* Continuous Read Mode Reset [DATASHEET] */
} gd25q80_cmd;

/* gd25q80_id - 1 constants. */
typedef enum {
    GD25Q80_ID_JEDEC_ID = 0x9F,  /* JEDEC ID [DATASHEET] (wire_addr) */
} gd25q80_id;

/* gd25q80_status - 2 constants. */
typedef enum {
    GD25Q80_STATUS_SR1 = 0x05,  /* Status Register S7-S0 [STRUCTURAL] (wire_addr) written by 01h (first data byte), after 06h (non-volatile) or 50h (volatile) */
    GD25Q80_STATUS_SR2 = 0x35,  /* Status Register S15-S8 [STRUCTURAL] (wire_addr) written by 01h (second data byte; a one-byte 01h clears CMP and QE), after 06h or 50h. No 31h on this part */
} gd25q80_status;

/* lcd_cmd - 59 constants. */
typedef enum {
    MIPI_DCS_NOP = 0x00,  /* NOP [HX 8.2.1 p.109] [ST 9.1.1 p.162] */
    MIPI_DCS_SOFT_RESET = 0x01,  /* SWRESET [HX 8.2.2 p.110] [ST 9.1.2 p.163] */
    MIPI_DCS_GET_DISPLAY_ID = 0x04,  /* RDDIDIF (HX), RDDID (ST) [HX 8.2.3 p.111] [ST 9.1.3 p.165] */
    MIPI_DCS_GET_DISPLAY_STATUS = 0x09,  /* RDDST [HX 8.2.4 p.112] [ST 9.1.4 p.167] */
    MIPI_DCS_GET_POWER_MODE = 0x0A,  /* RDDPM [HX 8.2.5 p.115] [ST 9.1.5 p.170] */
    MIPI_DCS_GET_ADDRESS_MODE = 0x0B,  /* RDDMADCTL [HX 8.2.6 p.117] [ST 9.1.6 p.172] */
    MIPI_DCS_GET_PIXEL_FORMAT = 0x0C,  /* RDDCOLMOD [HX 8.2.7 p.119] [ST 9.1.7 p.174] */
    MIPI_DCS_GET_DISPLAY_MODE = 0x0D,  /* RDDIM [HX 8.2.8 p.121] [ST 9.1.8 p.176] */
    MIPI_DCS_GET_SIGNAL_MODE = 0x0E,  /* RDDSM [HX 8.2.9 p.123] [ST 9.1.9 p.178] */
    MIPI_DCS_GET_DIAGNOSTIC_RESULT = 0x0F,  /* RDDSDR [HX 8.2.10 p.124] [ST 9.1.10 p.180] */
    MIPI_DCS_ENTER_SLEEP_MODE = 0x10,  /* SLPIN [HX 8.2.11 p.125] [ST 9.1.11 p.182] */
    MIPI_DCS_EXIT_SLEEP_MODE = 0x11,  /* SLPOUT [HX 8.2.12 p.126] [ST 9.1.12 p.184] */
    MIPI_DCS_ENTER_PARTIAL_MODE = 0x12,  /* PTLON [HX 8.2.13 p.128] [ST 9.1.13 p.186] */
    MIPI_DCS_ENTER_NORMAL_MODE = 0x13,  /* NORON [HX 8.2.14 p.129] [ST 9.1.14 p.187] */
    MIPI_DCS_EXIT_INVERT_MODE = 0x20,  /* INVOFF [HX 8.2.15 p.130] [ST 9.1.15 p.188] */
    MIPI_DCS_ENTER_INVERT_MODE = 0x21,  /* INVON [HX 8.2.16 p.131] [ST 9.1.16 p.190] */
    MIPI_DCS_SET_GAMMA_CURVE = 0x26,  /* GAMSET [HX 8.2.17 p.132] [ST 9.1.17 p.192] */
    MIPI_DCS_SET_DISPLAY_OFF = 0x28,  /* DISPOFF [HX 8.2.18 p.133] [ST 9.1.18 p.194] */
    MIPI_DCS_SET_DISPLAY_ON = 0x29,  /* DISPON [HX 8.2.19 p.134] [ST 9.1.19 p.196] */
    MIPI_DCS_SET_COLUMN_ADDRESS = 0x2A,  /* CASET [HX 8.2.20 p.135] [ST 9.1.20 p.198] */
    MIPI_DCS_SET_PAGE_ADDRESS = 0x2B,  /* RASET [HX 8.2.21 p.137] [ST 9.1.21 p.200] */
    MIPI_DCS_WRITE_MEMORY_START = 0x2C,  /* RAMWR [HX 8.2.22 p.139] [ST 9.1.22 p.202] */
    MIPI_DCS_WRITE_LUT = 0x2D,  /* RGBSET, colour LUT [HX 8.2.23 p.140]; not in ST7789V */
    MIPI_DCS_READ_MEMORY_START = 0x2E,  /* RAMRD [HX 8.2.24 p.141] [ST 9.1.23 p.204] */
    MIPI_DCS_SET_PARTIAL_ROWS = 0x30,  /* PTLAR [HX 8.2.25 p.142] [ST 9.1.24 p.206] */
    MIPI_DCS_SET_SCROLL_AREA = 0x33,  /* VSCRDEF [HX 8.2.26 p.144] [ST 9.1.25 p.208] */
    MIPI_DCS_SET_TEAR_OFF = 0x34,  /* TEOFF [HX 8.2.27 p.147] [ST 9.1.26 p.211] */
    MIPI_DCS_SET_TEAR_ON = 0x35,  /* TEON, 1 param: TEM bit 0 (0 = V-blank only) [HX 8.2.28 p.148] [ST 9.1.27 p.213] */
    MIPI_DCS_SET_ADDRESS_MODE = 0x36,  /* MADCTL, 1 param, see st7789v_madctl.rdl [HX 8.2.29 p.149] [ST 9.1.28 p.215] */
    MIPI_DCS_SET_SCROLL_START = 0x37,  /* VSCSAD [HX 8.2.30 p.151] [ST 9.1.29 p.218] */
    MIPI_DCS_EXIT_IDLE_MODE = 0x38,  /* IDMOFF [HX 8.2.31 p.152] [ST 9.1.30 p.220] */
    MIPI_DCS_ENTER_IDLE_MODE = 0x39,  /* IDMON [HX 8.2.32 p.153] [ST 9.1.31 p.222] */
    MIPI_DCS_SET_PIXEL_FORMAT = 0x3A,  /* COLMOD, 1 param, MIPI_DCS_PIXEL_FMT_* below [HX 8.2.33 p.154] [ST 9.1.32 p.224] */
    MIPI_DCS_WRITE_MEMORY_CONTINUE = 0x3C,  /* WRMEMC [ST 9.1.33 p.225]; not in HX8353E */
    MIPI_DCS_READ_MEMORY_CONTINUE = 0x3E,  /* RDMEMC [ST 9.1.34 p.227]; not in HX8353E */
    MIPI_DCS_SET_TEAR_SCANLINE = 0x44,  /* STE [ST 9.1.35 p.229]; not in HX8353E */
    MIPI_DCS_GET_SCANLINE = 0x45,  /* GSCAN [ST 9.1.36 p.231]; not in HX8353E */
    MIPI_DCS_SET_DISPLAY_BRIGHTNESS = 0x51,  /* WRDISBV [ST 9.1.37 p.233] */
    MIPI_DCS_GET_DISPLAY_BRIGHTNESS = 0x52,  /* RDDISBV [ST 9.1.38 p.235] */
    MIPI_DCS_WRITE_CONTROL_DISPLAY = 0x53,  /* WRCTRLD [ST 9.1.39 p.237] */
    MIPI_DCS_GET_CONTROL_DISPLAY = 0x54,  /* RDCTRLD [ST 9.1.40 p.239] */
    MIPI_DCS_WRITE_POWER_SAVE = 0x55,  /* WRCACE [ST 9.1.41 p.241] */
    MIPI_DCS_GET_POWER_SAVE = 0x56,  /* RDCABC [ST 9.1.42 p.243] */
    MIPI_DCS_SET_CABC_MIN_BRIGHTNESS = 0x5E,  /* WRCABCMB [ST 9.1.43 p.245] */
    MIPI_DCS_GET_CABC_MIN_BRIGHTNESS = 0x5F,  /* RDCABCMB [ST 9.1.44 p.247] */
    ST7789V_PORCTRL = 0xB2,  /* porch: BPA, FPA, PSEN, BPB|FPB, BPC|FPC. default 0C 0C 00 33 33, stock 0C 0C 00 33 33 (= default) [ST 9.2.3 p.263] */
    ST7789V_GCTRL = 0xB7,  /* gate: VGHS[6:4], VGLS[2:0]. default 35h; stock 56h (VGH 14.06 V, VGL -11.38 V) [ST 9.2.6 p.268-269] */
    ST7789V_VCOMS = 0xBB,  /* VCOM, 25 mV steps from 0.1 V. default 20h (0.9 V); stock 17h (0.675 V) [ST 9.2.9 p.273-274] */
    ST7789V_LCMCTRL = 0xC0,  /* XOR masks over MADCTL/INVON/GS: XMY XBGR XINV XMX XMH XMV XGS. default 2Ch; stock 2Ch (= default) [ST 9.2.10 p.275] */
    ST7789V_VDVVRHEN = 0xC2,  /* VDV/VRH from commands: CMDEN, then FFh. default 01h FFh; stock sends only the first parameter, 01h [ST 9.2.12 p.277] */
    ST7789V_VRHS = 0xC3,  /* VRH set. default 0Bh; stock 0Bh (= default) [ST 9.2.13 p.278-279] */
    ST7789V_FRCTRL2 = 0xC6,  /* normal-mode frame rate: NLA[7:5] inversion, RTNA[4:0]. default 0Fh; stock EFh (NLA 111 = column inversion, RTNA 0Fh = 60 Hz with the default porches) [ST 9.2.16 p.284-285] */
    ST7789V_PWCTRL1 = 0xD0,  /* power: fixed A4h, then AVDD[7:6] AVCL[5:4] VDS[1:0]. default A4h 81h; stock sends D0h A7h (one parameter, not the documented A4h - unexplained) and then D0h A4h A1h (AVDD 6.8 V, AVCL -4.8 V, VDDS 2.3 V) [ST 9.2.21 p.290-291] */
    ST7789V_UNDOC_CMD_D6 = 0xD6,  /* not in ST7789V v1.3 / ST7789VW v1.0; sent by stock after PWCTRL1 (D6h A1h), meaning unknown */
    ST7789V_RDID1 = 0xDA,  /* [ST 9.1.46 p.250] */
    ST7789V_RDID2 = 0xDB,  /* [ST 9.1.47 p.251] */
    ST7789V_RDID3 = 0xDC,  /* [ST 9.1.48 p.252] */
    ST7789V_PVGAMCTRL = 0xE0,  /* positive gamma, 14 params. stock 70 03 08 07 08 15 30 54 47 3A 15 14 2B 2E [ST 9.2.24 p.294-295] */
    ST7789V_NVGAMCTRL = 0xE1,  /* negative gamma, 14 params. stock 70 06 0A 09 06 03 2F 44 47 38 12 15 29 2F [ST 9.2.25 p.296-297] */
} lcd_cmd;

/* rda5807m_reg - 15 constants. */
typedef enum {
    RDA5807M_REG_00H = 0x00,  /* CHIPID [DATASHEET] (wire_addr) */
    RDA5807M_REG_02H = 0x02,  /* Control [CONFIRMED] (wire_addr) */
    RDA5807M_REG_03H = 0x03,  /* Channel [CONFIRMED] (wire_addr) */
    RDA5807M_REG_04H = 0x04,  /* Control 2 [CONFIRMED] (wire_addr) */
    RDA5807M_REG_05H = 0x05,  /* Volume / seek threshold [CONFIRMED] (wire_addr) */
    RDA5807M_REG_06H = 0x06,  /* Open mode [CONFIRMED] (wire_addr) */
    RDA5807M_REG_07H = 0x07,  /* Blend / band option [CONFIRMED] (wire_addr) */
    RDA5807M_REG_08H = 0x08,  /* Direct frequency [CONFIRMED] (wire_addr) */
    RDA5807M_REG_09H = 0x09,  /* 09H [CONFIRMED] (wire_addr) */
    RDA5807M_REG_0AH = 0x0A,  /* Status [CONFIRMED] (wire_addr) */
    RDA5807M_REG_0BH = 0x0B,  /* RSSI / RDS status [DATASHEET] (wire_addr) */
    RDA5807M_REG_0CH = 0x0C,  /* RDSA [DATASHEET] (wire_addr) */
    RDA5807M_REG_0DH = 0x0D,  /* RDSB [DATASHEET] (wire_addr) */
    RDA5807M_REG_0EH = 0x0E,  /* RDSC [DATASHEET] (wire_addr) */
    RDA5807M_REG_0FH = 0x0F,  /* RDSD [DATASHEET] (wire_addr) */
} rda5807m_reg;

/* st7789v_madctl_reg - 1 constants. */
typedef enum {
    ST7789V_MADCTL_MADCTL = 0x36,  /* MADCTL [CONFIRMED] (wire_addr) */
} st7789v_madctl_reg;

/* w25q128jv_cmd - 43 constants. */
typedef enum {
    W25Q128JV_CMD_WRITE_STATUS_1 = 0x01,  /* Write Status Register-1 [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_PAGE_PROGRAM = 0x02,  /* Page Program [CONFIRMED] DESTRUCTIVE */
    W25Q128JV_CMD_READ_DATA = 0x03,  /* Read Data [CONFIRMED] */
    W25Q128JV_CMD_WRITE_DISABLE = 0x04,  /* Write Disable [DATASHEET] */
    W25Q128JV_CMD_READ_STATUS_1 = 0x05,  /* Read Status Register-1 [CONFIRMED] */
    W25Q128JV_CMD_WRITE_ENABLE = 0x06,  /* Write Enable [CONFIRMED] */
    W25Q128JV_CMD_FAST_READ = 0x0B,  /* Fast Read [DATASHEET] */
    W25Q128JV_CMD_WRITE_STATUS_3 = 0x11,  /* Write Status Register-3 [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_READ_STATUS_3 = 0x15,  /* Read Status Register-3 [DATASHEET] */
    W25Q128JV_CMD_SECTOR_ERASE = 0x20,  /* Sector Erase (4 KB) [CONFIRMED] DESTRUCTIVE */
    W25Q128JV_CMD_WRITE_STATUS_2 = 0x31,  /* Write Status Register-2 [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_QUAD_PAGE_PROGRAM = 0x32,  /* Quad Input Page Program [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_READ_STATUS_2 = 0x35,  /* Read Status Register-2 [DATASHEET] */
    W25Q128JV_CMD_INDIVIDUAL_LOCK = 0x36,  /* Individual Block/Sector Lock [DATASHEET] */
    W25Q128JV_CMD_INDIVIDUAL_UNLOCK = 0x39,  /* Individual Block/Sector Unlock [DATASHEET] */
    W25Q128JV_CMD_FAST_READ_DUAL_OUTPUT = 0x3B,  /* Fast Read Dual Output [DATASHEET] */
    W25Q128JV_CMD_READ_BLOCK_LOCK = 0x3D,  /* Read Block/Sector Lock [DATASHEET] */
    W25Q128JV_CMD_PROGRAM_SECURITY_REGISTER = 0x42,  /* Program Security Register [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_ERASE_SECURITY_REGISTER = 0x44,  /* Erase Security Register [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_READ_SECURITY_REGISTER = 0x48,  /* Read Security Register [DATASHEET] */
    W25Q128JV_CMD_READ_UNIQUE_ID = 0x4B,  /* Read Unique ID [DATASHEET] */
    W25Q128JV_CMD_VOLATILE_SR_WRITE_ENABLE = 0x50,  /* Write Enable for Volatile Status Register [DATASHEET] */
    W25Q128JV_CMD_BLOCK_ERASE_32K = 0x52,  /* Block Erase (32 KB) [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_READ_SFDP = 0x5A,  /* Read SFDP Register [DATASHEET] */
    W25Q128JV_CMD_CHIP_ERASE_60 = 0x60,  /* Chip Erase (60h) [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_ENABLE_RESET = 0x66,  /* Enable Reset [DATASHEET] */
    W25Q128JV_CMD_FAST_READ_QUAD_OUTPUT = 0x6B,  /* Fast Read Quad Output [DATASHEET] */
    W25Q128JV_CMD_ERASE_PROGRAM_SUSPEND = 0x75,  /* Erase / Program Suspend [DATASHEET] */
    W25Q128JV_CMD_SET_BURST_WITH_WRAP = 0x77,  /* Set Burst with Wrap [DATASHEET] */
    W25Q128JV_CMD_ERASE_PROGRAM_RESUME = 0x7A,  /* Erase / Program Resume [DATASHEET] */
    W25Q128JV_CMD_GLOBAL_LOCK = 0x7E,  /* Global Block/Sector Lock [DATASHEET] */
    W25Q128JV_CMD_MANUFACTURER_DEVICE_ID = 0x90,  /* Manufacturer / Device ID [DATASHEET] */
    W25Q128JV_CMD_MANUFACTURER_DEVICE_ID_DUAL_IO = 0x92,  /* Manufacturer / Device ID Dual I/O [DATASHEET] */
    W25Q128JV_CMD_MANUFACTURER_DEVICE_ID_QUAD_IO = 0x94,  /* Manufacturer / Device ID Quad I/O [DATASHEET] */
    W25Q128JV_CMD_GLOBAL_UNLOCK = 0x98,  /* Global Block/Sector Unlock [DATASHEET] */
    W25Q128JV_CMD_RESET_DEVICE = 0x99,  /* Reset Device [DATASHEET] */
    W25Q128JV_CMD_READ_JEDEC_ID = 0x9F,  /* Read JEDEC ID [CONFIRMED] */
    W25Q128JV_CMD_RELEASE_POWER_DOWN_ID = 0xAB,  /* Release Power-down / Device ID [DATASHEET] */
    W25Q128JV_CMD_POWER_DOWN = 0xB9,  /* Power-down [DATASHEET] */
    W25Q128JV_CMD_FAST_READ_DUAL_IO = 0xBB,  /* Fast Read Dual I/O [DATASHEET] */
    W25Q128JV_CMD_CHIP_ERASE_C7 = 0xC7,  /* Chip Erase (C7h) [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_BLOCK_ERASE_64K = 0xD8,  /* Block Erase (64 KB) [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_FAST_READ_QUAD_IO = 0xEB,  /* Fast Read Quad I/O [DATASHEET] */
} w25q128jv_cmd;

/* w25q128jv_drv_e - 4 constants. */
typedef enum {
    W25Q128JV_DRV_PCT_100 = 0x00,  /* 100% output driver strength */
    W25Q128JV_DRV_PCT_75 = 0x01,  /* 75% */
    W25Q128JV_DRV_PCT_50 = 0x02,  /* 50% */
    W25Q128JV_DRV_PCT_25 = 0x03,  /* 25% (datasheet default) */
} w25q128jv_drv_e;

/* w25q128jv_id - 2 constants. */
typedef enum {
    W25Q128JV_ID_UNIQUE_ID = 0x4B,  /* Unique ID [DATASHEET] (wire_addr) */
    W25Q128JV_ID_JEDEC_ID = 0x9F,  /* JEDEC ID [CONFIRMED] (wire_addr) */
} w25q128jv_id;

/* w25q128jv_status - 3 constants. */
typedef enum {
    W25Q128JV_STATUS_SR1 = 0x05,  /* Status Register-1 [CONFIRMED] (wire_addr) written by 01h after 06h (non-volatile bits) or after 50h (volatile copies); a second data byte after 01h also writes SR2 */
    W25Q128JV_STATUS_SR3 = 0x15,  /* Status Register-3 [DATASHEET] (wire_addr) written by 11h after 06h (non-volatile) or 50h (volatile) */
    W25Q128JV_STATUS_SR2 = 0x35,  /* Status Register-2 [DATASHEET] (wire_addr) written by 31h after 06h (non-volatile) or 50h (volatile); or the second data byte of 01h */
} w25q128jv_status;

/* ADC_Type - 72 bytes, 18 recovered fields. */
typedef struct {
    dword ADC_CTRL;  /* 0x0000: 0x00 ADC Control registers. DS §5.9.5.1 p.411. FW: 0 reads, 3 writes. Reset 0x0 (DS). */
    dword ADC_INTR_DELTA;  /* 0x0004: 0x04 ADC Interruption error range. DS §5.9.5.2 p.411. Reset 0x0 (DS). */
    dword ADC_INTR;  /* 0x0008: 0x08 ADC Interrupt Control Register. DS §5.9.5.3 p.411. FW: 0 reads, 1 write. Reset 0x0 (DS). */
    dword ADC_INTR_STA;  /* 0x000c: 0x0c ADC Interrupt Status Register. DS §5.9.5.4 p.413. */
    dword ADC_SCAN_TIME;  /* 0x0010: 0x10 ADC Scan interval setting. DS §5.9.5.5 p.415. Reset 0x2c (DS). */
    dword ADC_START;  /* 0x0014: 0x14 ADC start up. DS §5.9.5.6 p.415. FW: 0 reads, 1 write. Reset 0x0 (DS). */
    dword ADC_CTRL_STATE;  /* 0x0018: 0x18 ADC Control and Status Registers. DS §5.9.5.7 p.415. FW: 3 reads, 0 writes. Reset 0x0 (DS). */
    dword ADC_INTR_THRESHOLD;  /* 0x001c: 0x1c ADC Interrupt initial value. DS §5.9.5.8 p.417. Printed ADC_INTR_THRESHOLE (typo); the reserved row is printed */
    dword ADC_CTRL_STOP;  /* 0x0020: 0x20 ADC Configuration registers. DS §5.9.5.9 p.417. FW: 0 reads, 3 writes. Reset 0x0 (DS). */
    dword ADC_CH_VLD;  /* 0x0024: 0x24 ADC Channel Configuration Register. DS §5.9.5.10 p.419. FW: 0 reads, 2 writes. Note: Single scan mode, ADC_CH_ */
    dword ADC_PD_SEOC_TIME;  /* 0x0028: 0x28 ADC Power-off time register. DS §5.9.5.11 p.419. FW: 0 reads, 1 write. Reset 0xa20 (DS). */
    dword ADC_P2S_EN;  /* 0x002c: 0x2c ADC Serial data output register. DS §5.9.5.12 p.419. FW: 0 reads, 1 write. Reset 0x0 (DS). */
    dword ADC_DATA_AB;  /* 0x0030: 0x30 ADC Channel AB Scan Value. DS §5.9.5.13 p.420. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
    dword ADC_DATA_CD;  /* 0x0034: 0x34 ADC Channel CD Scan Value. DS §5.9.5.14 p.421. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
    dword ADC_DATA_EF;  /* 0x0038: 0x38 ADC Channel EF Scan Value. DS §5.9.5.15 p.421. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
    dword ADC_DATA_GH;  /* 0x003c: 0x3c ADC Channel GH Scan Value. DS §5.9.5.16 p.421. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
    dword ADC_CTRL_VERID;  /* 0x0040: 0x40 ADC Version Register. DS §5.9.5.17 p.421. Reset 0x20151216 (DS). */
    dword ADC_DIR_DAT_OP;  /* 0x0044: 0x44 ADC EOC Then directly output ADC. DS §5.9.5.18 p.421. Reset 0x0 (DS). */
} ADC_Type;

/* CODEC_Type - 49 bytes, 43 recovered fields. */
typedef struct {
    byte SR1;  /* 0x0000: 0x00 Status Register. DS §6.5.2.1 p.443. Reset 0x0 (DS). */
    byte SR2;  /* 0x0001: 0x01 Status Register. DS §6.5.2.2 p.445. Reset 0x0 (DS). */
    byte RESERVED_2[5];  /* 0x0002: 0x2-0x6 */
    byte MR;  /* 0x0007: 0x07 ADC Mute control. DS §6.5.2.3 p.445. Reset 0x0 (DS). */
    byte AICR_DAC;  /* 0x0008: 0x08 DAC Audio interface control. DS §6.5.2.4 p.446. Reset 0xd3 (DS). */
    byte AICR_ADC;  /* 0x0009: 0x09 ADC Audio interface control. DS §6.5.2.5 p.447. Reset 0xd3 (DS). */
    byte RESERVED_10[1];  /* 0x000a: 0xa-0xa */
    byte CR_MIC1;  /* 0x000b: 0x0b MIC1 Control registers. DS §6.5.2.6 p.448. Reset 0x30 (DS). */
    byte CR_MIC2;  /* 0x000c: 0x0c MIC2 Control registers. DS §6.5.2.7 p.449. Reset 0x30 (DS). */
    byte CR_DAC;  /* 0x000d: 0x0d DAC Control registers. DS §6.5.2.8 p.449. Reset 0xb0 (DS). */
    byte RESERVED_14[1];  /* 0x000e: 0xe-0xe */
    byte CR_ADC;  /* 0x000f: 0x0f ADC Control registers. DS §6.5.2.9 p.449. Reset 0xb0 (DS). */
    byte CR_MIX;  /* 0x0010: 0x10 Digital Aliasing Control Register. DS §6.5.2.10 p.450. Window onto four indirect mixer registers (address in m */
    byte DR_MIX;  /* 0x0011: 0x11 Digital Aliasing Control Indirect. DS §6.5.2.11 p.452. Reset 0x0 (DS). */
    byte CR_VIC;  /* 0x0012: 0x12 Codec sleep Mode Control Register. DS §6.5.2.12 p.454. Reset 0xf (DS). */
    byte CR_CK;  /* 0x0013: 0x13 MCLK Control registers. DS §6.5.2.13 p.454. Reset 0x40 (DS). */
    byte FCR_DAC;  /* 0x0014: 0x14 DAC Sampling Clock Configuration. DS §6.5.2.14 p.454. Reset 0x0 (DS). */
    byte SFCCR_DAC;  /* 0x0015: 0x15 DS §6.5.2.15 p.454. Reset 0x0 (DS). */
    byte SFFCR_DAC;  /* 0x0016: 0x16 DS §6.5.2.16 p.455. Reset 0x0 (DS). */
    byte FCR_ADC;  /* 0x0017: 0x17 ADC Sampling Clock Configuration. DS §6.5.2.17 p.456. Reset 0x0 (DS). */
    byte CR_TIMER_h;  /* 0x0018: 0x18 Counter high 8 bits. DS §6.5.2.18 p.456. Reset 0x0 (DS). */
    byte CR_TIMER_l;  /* 0x0019: 0x19 Counter lower 8 bits. DS §6.5.2.19 p.456. Reset 0x0 (DS). */
    byte ICR;  /* 0x001a: 0x1a Interrupt Control Register. DS §6.5.2.20 p.456. Reset 0x0 (DS). */
    byte IMR;  /* 0x001b: 0x1b Interrupt Mask Control registers. DS §6.5.2.21 p.458. Reset 0xff (DS). */
    byte IFR;  /* 0x001c: 0x1c Interrupt flag definition. DS §6.5.2.22 p.458. Reset 0x0 (DS). */
    byte IMR2;  /* 0x001d: 0x1d Timer flag MASK Control registers. DS §6.5.2.23 p.458. Reset 0xff (DS). */
    byte IFR2;  /* 0x001e: 0x1e Timer flag definition. DS §6.5.2.24 p.459. Reset 0x0 (DS). */
    byte GCR_DACL;  /* 0x001f: 0x1f DAC Gain Control. DS §6.5.2.25 p.460. Reset 0x0 (DS). */
    byte GCR_DACR;  /* 0x0020: 0x20 DS §6.5.2.26 p.460. Reset 0x0 (DS). */
    byte RESERVED_33[2];  /* 0x0021: 0x21-0x22 */
    byte GCR_MIC1;  /* 0x0023: 0x23 Mic1 Gain Control. DS §6.5.2.27 p.462. Reset 0x0 (DS). */
    byte RESERVED_36[1];  /* 0x0024: 0x24-0x24 */
    byte GCR_ADCL;  /* 0x0025: 0x25 ADC Gain Control. DS §6.5.2.28 p.462. Reset 0x0 (DS). */
    byte GCR_ADCR;  /* 0x0026: 0x26 DS §6.5.2.29 p.462. Reset 0x0 (DS). */
    byte GCR_MIXDACL;  /* 0x0027: 0x27 Aliasing DAC Gain Control. DS §6.5.2.30 p.463. Reset 0x0 (DS). */
    byte GCR_MIXDACR;  /* 0x0028: 0x28 DS §6.5.2.31 p.464. Reset 0x0 (DS). */
    byte GCR_MIXADCL;  /* 0x0029: 0x29 Aliasing ADC Gain Control. DS §6.5.2.32 p.464. Reset 0x0 (DS). */
    byte GCR_MIXADCR;  /* 0x002a: 0x2a DS §6.5.2.33 p.465. Reset 0x0 (DS). */
    byte CR_DAC_AGC;  /* 0x002b: 0x2b DAC Gain Control Register. DS §6.5.2.34 p.466. Reset 0x0 (DS). */
    byte DR_DAC_AGC;  /* 0x002c: 0x2c DAC AGC Read and write data of indirect. DS §6.5.2.35 p.466. Indirect DAC1 DRC registers (index in CR_DAC_AGC) */
    byte RESERVED_45[2];  /* 0x002d: 0x2d-0x2e */
    byte CR_ADC_AGC;  /* 0x002f: 0x2f ADC Gain Control Register. DS §6.5.2.36 p.468. Reset 0x0 (DS). */
    byte DR_ADC_AGC;  /* 0x0030: 0x30 ADC AGC Read and write data of indirect. DS §6.5.2.37 p.468. Indirect ADC AGC registers (index in CR_ADC_AGC): */
} CODEC_Type;

/* DAC_Type - 24 bytes, 6 recovered fields. */
typedef struct {
    dword DAC_PD_CTRL;  /* 0x0000: 0x00 DAC Enable. DS §5.10.5.1 p.423. FW: 0 reads, 1 write. Reset 0x7 (DS). */
    dword DAC_PD_MODE_EN;  /* 0x0004: 0x04 DAC Low power enable. DS §5.10.5.2 p.423. FW: 0 reads, 1 write. Reset 0x7 (DS). */
    dword DAC_DATA_A;  /* 0x0008: 0x08 DAC Channel A data. DS §5.10.5.3 p.425. FW: 0 reads, 2 writes. Reset 0x0 (DS). */
    dword DAC_DATA_B;  /* 0x000c: 0x0c DAC Channel B data. DS §5.10.5.4 p.425. FW: 0 reads, 2 writes. Reset 0x0 (DS). */
    dword DAC_DATA_C;  /* 0x0010: 0x10 DAC Channel C data. DS §5.10.5.5 p.425. FW: 0 reads, 2 writes. Reset 0x0 (DS). */
    dword DAC_CTRL_VERID;  /* 0x0014: 0x14 DAC Controller version. DS §5.10.5.6 p.425. Reset 0x20160229 (DS). */
} DAC_Type;

/* GPIO_Type - 124 bytes, 14 recovered fields. */
typedef struct {
    dword SWPORTA_DR;  /* 0x0000: 0x00 Port A output data. DS §5.7.5.1 p.381. FW: 16 reads, 11 writes. Reset 0x0 (DS). */
    dword SWPORTA_DDR;  /* 0x0004: 0x04 Control port A data direction. DS §5.7.5.2 p.381. FW: 22 reads, 19 writes. Reset 0x0 (DS). */
    dword RESERVED_8[10];  /* 0x0008: 0x8-0x2f */
    dword INTEN;  /* 0x0030: 0x30 Interrupt enable. DS §5.7.5.3 p.383. FW: 10 reads, 10 writes. Reset 0x0 (DS). */
    dword INTMASK;  /* 0x0034: 0x34 Controls whether to mask interrupts. DS §5.7.5.4 p.383. FW: 3 reads, 3 writes. Reset 0x0 (DS). */
    dword INTTYPE_LEVEL;  /* 0x0038: 0x38 Controls the interrupt type of port A. DS §5.7.5.5 p.383. FW: 9 reads, 9 writes. Reset 0x0 (DS). */
    dword INT_POLARITY;  /* 0x003c: 0x3c Controls the polarity of the interrupt on port A. DS §5.7.5.6 p.383. FW: 11 reads, 11 writes. Reset 0x0 (DS). */
    dword INTSTATUS;  /* 0x0040: 0x40 Port A interrupt status. DS §5.7.5.7 p.383. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
    dword RAW_INTSTATUS;  /* 0x0044: 0x44 port A before masking. DS §5.7.5.8 p.383. Reset 0x0 (DS). */
    dword DEBOUNCE;  /* 0x0048: 0x48 Debounce Enable Register. DS §5.7.5.9 p.385. FW: 0 reads, 2 writes. Printed RO; the stock firmware writes it ( */
    dword PORTA_EOI;  /* 0x004c: 0x4c PORTA interrupt clear register. 0 : Do not clear interrupt; 1 : Clearing Break. DS §5.7.5.10 p.385. FW: 0 read */
    dword EXT_PORTA;  /* 0x0050: 0x50 When port A is configured as input, read this register to read the input data. DS §5.7.5.11 p.385. FW: 7 reads */
    dword RESERVED_84[9];  /* 0x0054: 0x54-0x77 */
    dword INTR_BOTH_EDGE;  /* 0x0078: 0x78 1 : Dual-edge triggered interrupt 0 : Non-double-edge triggered interrupt. DS §5.7.5.12 p.385. FW: 6 reads, 6 */
} GPIO_Type;

/* I2C_Type - 164 bytes, 33 recovered fields. */
typedef struct {
    dword IC_CON;  /* 0x0000: 0x00 I2C Control registers. DS §5.1.6.1 p.226. Reset 0x7d (DS). */
    dword IC_TAR;  /* 0x0004: 0x04 I2C Destination Address Register. DS §5.1.6.2 p.228. Reset 0x55 (DS). */
    dword RESERVED_8[2];  /* 0x0008: 0x8-0xf */
    dword IC_DATA_CMD;  /* 0x0010: 0x10 I2C Send and receive data buffers and. DS §5.1.6.3 p.228. Reset 0x0 (DS). */
    dword RESERVED_20[2];  /* 0x0014: 0x14-0x1b */
    dword IC_FS_SCL_HCNT;  /* 0x001c: 0x1c Fast SCL High level count. DS §5.1.6.4 p.228. Reset 0x5a (DS). */
    dword IC_FS_SCL_LCNT;  /* 0x0020: 0x20 Fast SCL Low level count. DS §5.1.6.5 p.228. Reset 0xa0 (DS). */
    dword RESERVED_36[2];  /* 0x0024: 0x24-0x2b */
    dword IC_INTR_STAT;  /* 0x002c: 0x2c Interrupt Status. DS §5.1.6.6 p.230. Reset 0x0 (DS). */
    dword IC_INTR_MASK;  /* 0x0030: 0x30 Interrupt mask. DS §5.1.6.7 p.230. Reset 0x8ff (DS). */
    dword IC_RAW_INTR_STAT;  /* 0x0034: 0x34 Raw interrupt status. DS §5.1.6.8 p.230. Reset 0x0 (DS). */
    dword IC_RX_TL;  /* 0x0038: 0x38 Receive FIFO threshold. DS §5.1.6.9 p.232. Reset 0x6 (DS). */
    dword IC_TX_TL;  /* 0x003c: 0x3c Transmit FIFO threshold. DS §5.1.6.10 p.233. Reset 0x6 (DS). */
    dword IC_CLR_INTR;  /* 0x0040: 0x40 Clear Interrupt. DS §5.1.6.11 p.233. Reset 0x0 (DS). */
    dword IC_CLR_RX_UNDER;  /* 0x0044: 0x44 Clear interrupt RX_UNDER. DS §5.1.6.12 p.234. Reset 0x0 (DS). */
    dword IC_CLR_RX_OVER;  /* 0x0048: 0x48 Clear interrupt RX_OVER. DS §5.1.6.13 p.234. Reset 0x0 (DS). */
    dword IC_CLR_TX_OVER;  /* 0x004c: 0x4c Clear interrupt TX_OVER. DS §5.1.6.14 p.234. Reset 0x0 (DS). */
    dword IC_CLR_RD_REQ;  /* 0x0050: 0x50 Clear interrupt RD_REQ. DS §5.1.6.15 p.234. Reset 0x0 (DS). */
    dword IC_CLR_TX_ABRT;  /* 0x0054: 0x54 Clear interrupt TX_ABRT. DS §5.1.6.16 p.234. Reset 0x0 (DS). */
    dword IC_CLR_RX_DONE;  /* 0x0058: 0x58 Clear interrupt RX_DONE. DS §5.1.6.17 p.236. Reset 0x0 (DS). */
    dword IC_CLR_ACTIVITY;  /* 0x005c: 0x5c Clear interrupt activity. DS §5.1.6.18 p.236. Reset 0x0 (DS). */
    dword IC_CLR_STOP_DET;  /* 0x0060: 0x60 Clear interrupt STOP_DET. DS §5.1.6.19 p.236. Reset 0x0 (DS). */
    dword IC_CLR_START_DET;  /* 0x0064: 0x64 Clear interrupt START_DET. DS §5.1.6.20 p.236. Reset 0x0 (DS). */
    dword RESERVED_104[1];  /* 0x0068: 0x68-0x6b */
    dword IC_ENABLE;  /* 0x006c: 0x6c I2C Enable register. DS §5.1.6.21 p.236. Reset 0x0 (DS). */
    dword IC_STATUS;  /* 0x0070: 0x70 I2C Status Register. DS §5.1.6.22 p.238. Reset 0x6 (DS). */
    dword IC_TXFLR;  /* 0x0074: 0x74 Transmit FIFO water level register. DS §5.1.6.23 p.238. Reset 0x0 (DS). */
    dword IC_RXFLR;  /* 0x0078: 0x78 Receive FIFO water level register. DS §5.1.6.24 p.238. Reset 0x0 (DS). */
    dword RESERVED_124[1];  /* 0x007c: 0x7c-0x7f */
    dword IC_TX_ABRT_SOURCE;  /* 0x0080: 0x80 I2C Transfer end status register. DS §5.1.6.25 p.240. Reset 0x0 (DS). */
    dword RESERVED_132[6];  /* 0x0084: 0x84-0x9b */
    dword IC_ENABLE_STATUS;  /* 0x009c: 0x9c I2C Enable Status Register. DS §5.1.6.26 p.242. Reset 0x0 (DS). */
    dword IC_START;  /* 0x00a0: 0xa0 Control data starts sending. DS §5.1.6.27 p.242. Reset 0x0 (DS). */
} I2C_Type;

/* I80_Type - 48 bytes, 10 recovered fields. */
typedef struct {
    dword INDEX;  /* 0x0000: 0x00 Addressing register. DS §5.3.5.1 p.266. FW: 0 reads, 1 write. Reset 0x0 (DS). */
    dword DATA;  /* 0x0004: 0x04 Data register. DS §5.3.5.2 p.266. FW: 0 reads, 1 write. Reset 0x0 (DS). */
    dword RESERVED_8[2];  /* 0x0008: 0x8-0xf */
    dword WCFG;  /* 0x0010: 0x10 Write timing parameter configuration. DS §5.3.5.3 p.266. FW: 0 reads, 1 write. Reset 0x10101 (DS). */
    dword RCFG;  /* 0x0014: 0x14 Read timing parameter configuration. DS §5.3.5.4 p.266. The datasheet prints the reserved row as [31:0], overl */
    dword RESERVED_24[2];  /* 0x0018: 0x18-0x1f */
    dword SCFG;  /* 0x0020: 0x20 Configuration registers. DS §5.3.5.5 p.268. Reset 0x0 (DS). */
    dword RESERVED_36[1];  /* 0x0024: 0x24-0x27 */
    dword UNDOC_0x28;  /* 0x0028: 0x28 Not in the datasheet's I80 register table. The stock firmware reads and writes it (FW: 1 read, 1 write). Role */
    dword AC_MODE;  /* 0x002c: 0x2c Bus Mode Register. DS §5.3.5.6 p.268. Reset 0x0 (DS). */
} I80_Type;

/* PIC_Type - 144 bytes, 33 recovered fields. */
typedef struct {
    dword PIC_MODE;  /* 0x0000: 0x00 Trigger mode select, sources 0-31. DS §4.7.6.1 p.172. FW: 0 reads, 2 writes. Bit n is source 0+n (sources 0-31 */
    dword PIC_PO;  /* 0x0004: 0x04 Trigger polarity select, sources 0-31. DS §4.7.6.2 p.172. FW: 0 reads, 2 writes. Bit n is source 0+n (sources */
    dword PIC_MASK;  /* 0x0008: 0x08 Interrupt mask, sources 0-31. DS §4.7.6.3 p.173. FW: 2 reads, 4 writes. Bit n is source 0+n (sources 0-31). Th */
    dword PIC_VECTOR;  /* 0x000c: 0x0c Interrupt vector base address. DS §4.7.6.4 p.174. Source x is delivered to the CPU as vector x + vector0; with */
    dword PIC_COW1;  /* 0x0010: 0x10 End of interruption. DS §4.7.6.5 p.174. The hand-maintained entry this replaced guessed a 'clear-on-write ack' */
    dword PIC_PRIOR0_3;  /* 0x0014: 0x14 Priority counter initial values, sources 0-3. DS §4.7.6.6 p.174. Sources 0-3 are unassigned, TIMER_1, TIMER_2, */
    dword PIC_PRIOR4_7;  /* 0x0018: 0x18 Priority counter initial values, sources 4-7. DS §4.7.6.7 p.176. Sources 4-7 are TIMER_4, TIMER_5, TIMER_6, I2 */
    dword PIC_PRIOR8_11;  /* 0x001c: 0x1c Priority counter initial values, sources 8-11. DS §4.7.6.8 p.176. Sources 8-11 are I2C0, I2C2, UART1, UART2; o */
    dword PIC_PRIOR12_15;  /* 0x0020: 0x20 Priority counter initial values, sources 12-15. DS §4.7.6.9 p.176. Sources 12-15 are UART0, UART3, GPIOB, GPIO */
    dword PIC_PRIOR16_19;  /* 0x0024: 0x24 Priority counter initial values, sources 16-19. DS §4.7.6.10 p.176. Sources 16-19 are SPI0, GPIOC, PWM, RTC; o */
    dword PIC_PRIOR20_23;  /* 0x0028: 0x28 Priority counter initial values, sources 20-23. DS §4.7.6.11 p.177. Sources 20-23 are SDIO, USB, SPI1, SPI2; o */
    dword PIC_PRIOR24_27;  /* 0x002c: 0x2c Priority counter initial values, sources 24-27. DS §4.7.6.12 p.178. Sources 24-27 are LCSFC, DAC, ADC, PCM_rd_ */
    dword PIC_PRIOR28_31;  /* 0x0030: 0x30 Priority counter initial values, sources 28-31. DS §4.7.6.13 p.178. Sources 28-31 are PCM_wr_data_interp, Syst */
    dword PIC_COW2;  /* 0x0034: 0x34 Control registers. DS §4.7.6.14 p.178. Not an upper-bank sibling of PIC_COW1, as the hand-maintained entry thi */
    dword PIC_SYNC;  /* 0x0038: 0x38 Asynchronous Process Control Register. DS §4.7.6.15 p.179. Offset also in DRV bsp_vic.h. Reset 0x0 (DS). */
    dword PIC_FFLAG_L;  /* 0x003c: 0x3c Fast-interrupt select, sources 0-31. DS §4.7.6.16 p.180. Bit n is source 0+n (sources 0-31). The datasheet pri */
    dword PIC_RECORD_SEL;  /* 0x0040: 0x40 Selects the source whose requests PIC_INT_CNT counts. DS §4.7.6.17 p.180. Section heading prints PIC_INT_RECOR */
    dword PIC_INT_ST;  /* 0x0044: 0x44 Interrupt request record, sources 0-31. DS §4.7.6.18 p.180. FW: 0 reads, 2 writes. Bit n is source 0+n (source */
    dword PIC_INT_ST_1;  /* 0x0048: 0x48 Interrupt request record, sources 32-63. DS §4.7.6.19 p.181. FW: 0 reads, 2 writes. Bit n is source 32+n (sour */
    dword PIC_INT_CNT;  /* 0x004c: 0x4c Interrupt source interrupt count. DS §4.7.6.20 p.181. Section heading prints PIC_INT_ST_CNT at offset 0x48, wh */
    dword RESERVED_80[4];  /* 0x0050: 0x50-0x5f */
    dword PIC_MODE_1;  /* 0x0060: 0x60 Trigger mode select, sources 32-63 (Register Table 5 prints 'Height 32', i.e. the high 32). DS §4.7.6.21 p.182 */
    dword PIC_PO_1;  /* 0x0064: 0x64 Trigger polarity select, sources 32-63 (Register Table 5 prints 'Height 32', i.e. the high 32). DS §4.7.6.22 p */
    dword PIC_MASK_1;  /* 0x0068: 0x68 Interrupt mask, sources 32-63 (Register Table 5 prints 'Height 32', i.e. the high 32). DS §4.7.6.23 p.182. FW: */
    dword PIC_PRIOR32_35;  /* 0x006c: 0x6c Priority counter initial values, sources 32-35. DS §4.7.6.24 p.182. Sources 32-35 are Rf_tx_inter, Rf_rx_inter */
    dword PIC_PRIOR36_39;  /* 0x0070: 0x70 Priority counter initial values, sources 36-39. DS §4.7.6.25 p.184. Sources 36-39 are SlaveSPI2, Codec_interp, */
    dword PIC_PRIOR40_43;  /* 0x0074: 0x74 Priority counter initial values, sources 40-43. DS §4.7.6.26 p.184. Sources 40-43 are unassigned, unassigned, */
    dword PIC_PRIOR44_47;  /* 0x0078: 0x78 Priority counter initial values, sources 44-47. DS §4.7.6.27 p.184. Sources 44-47 are unassigned, unassigned, */
    dword PIC_PRIOR48_51;  /* 0x007c: 0x7c Priority counter initial values, sources 48-51. DS §4.7.6.28 p.185. Sources 48-51 are unassigned, unassigned, */
    dword PIC_PRIOR52_55;  /* 0x0080: 0x80 Priority counter initial values, sources 52-55. DS §4.7.6.29 p.185. Sources 52-55 are unassigned, unassigned, */
    dword PIC_PRIOR56_59;  /* 0x0084: 0x84 Priority counter initial values, sources 56-59. DS §4.7.6.30 p.186. Sources 56-59 are unassigned, unassigned, */
    dword PIC_PRIOR60_63;  /* 0x0088: 0x88 Priority counter initial values, sources 60-63. DS §4.7.6.31 p.186. Sources 60-63 are unassigned, unassigned, */
    dword PIC_FFLAG_H;  /* 0x008c: 0x8c Fast-interrupt select, sources 32-63 (Register Table 5 prints 'Height 32', i.e. the high 32). DS §4.7.6.32 p.1 */
} PIC_Type;

/* PWM_Type - 4084 bytes, 19 recovered fields. */
typedef struct {
    dword PWM0_CFG;  /* 0x0000: 0x00 PWM0 Configuration registers. DS §5.8.5.1 p.391. Reset 0x0 (DS). */
    dword PWM0_RPT;  /* 0x0004: 0x04 PWM0 ONE_SHOT Number of. DS §5.8.5.2 p.392. Reset 0x0 (DS). */
    dword PWM0_PER;  /* 0x0008: 0x08 PWM0 The periodic waveform lasts for. DS §5.8.5.3 p.393. Reset 0x0 (DS). */
    dword PWM0_FP;  /* 0x000c: 0x0c PWM0 The number of beats that the. DS §5.8.5.4 p.393. Reset 0x0 (DS). */
    dword PWM0_STATUS;  /* 0x0010: 0x10 PWM0 Status Register. DS §5.8.5.5 p.393. Reset 0x0 (DS). */
    dword RESERVED_20[3];  /* 0x0014: 0x14-0x1f */
    dword PWM1_CFG;  /* 0x0020: 0x20 PWM1 Configuration registers. DS §5.8.5.6 p.393. Reset 0x0 (DS). */
    dword PWM1_RPT;  /* 0x0024: 0x24 PWM1 ONE_SHOT Number of. DS §5.8.5.7 p.395. Reset 0x0 (DS). */
    dword PWM1_PER;  /* 0x0028: 0x28 PWM1 The periodic waveform lasts for. DS §5.8.5.8 p.395. Reset 0x0 (DS). */
    dword PWM1_FP;  /* 0x002c: 0x2c PWM1 The number of beats that the. DS §5.8.5.9 p.395. Reset 0x0 (DS). */
    dword PWM1_STATUS;  /* 0x0030: 0x30 PWM1 Status Register. DS §5.8.5.10 p.396. Reset 0x0 (DS). */
    dword RESERVED_52[3];  /* 0x0034: 0x34-0x3f */
    dword PWM2_CFG;  /* 0x0040: 0x40 PWM2 Configuration registers. DS §5.8.5.11 p.397. Reset 0x0 (DS). */
    dword PWM2_RPT;  /* 0x0044: 0x44 PWM2 ONE_SHOT Number of. DS §5.8.5.12 p.397. Reset 0x0 (DS). */
    dword PWM2_PER;  /* 0x0048: 0x48 PWM2 The periodic waveform lasts for. DS §5.8.5.13 p.399. Reset 0x0 (DS). */
    dword PWM2_FP;  /* 0x004c: 0x4c PWM2 The number of beats that the. DS §5.8.5.14 p.399. Reset 0x0 (DS). */
    dword PWM2_STATUS;  /* 0x0050: 0x50 PWM2 Status Register. DS §5.8.5.15 p.399. Reset 0x0 (DS). */
    dword RESERVED_84[999];  /* 0x0054: 0x54-0xfef */
    dword PWM_INTR_STA;  /* 0x0ff0: 0xff0 DS §5.8.5.16 p.399. Reset 0x0 (DS). */
} PWM_Type;

/* SDIO_Type - 516 bytes, 38 recovered fields. */
typedef struct {
    dword CTRL;  /* 0x0000: 0x00 Control registers. DS §5.5.5.1 p.305. Note: H/S Represents hardware reset and software reset Reset 0x0 (DS). */
    dword PWREN;  /* 0x0004: 0x04 Power-on enable register. DS §5.5.5.2 p.307. Reset 0x0 (DS). */
    dword CLKDIV;  /* 0x0008: 0x08 Clock divider register. DS §5.5.5.3 p.307. Reset 0x0 (DS). */
    dword CLKSRC;  /* 0x000c: 0x0c Clock source register. DS §5.5.5.4 p.307. Reset 0x0 (DS). */
    dword CLKENA;  /* 0x0010: 0x10 Clock enable register. DS §5.5.5.5 p.309. Reset 0x0 (DS). */
    dword TMOUT;  /* 0x0014: 0x14 Timeout register. DS §5.5.5.6 p.309. Reset 0xffffff40 (DS). */
    dword CTYPE;  /* 0x0018: 0x18 Card Type Register. DS §5.5.5.7 p.309. Reset 0x0 (DS). */
    dword BLKSIZ;  /* 0x001c: 0x1c Block size register. DS §5.5.5.8 p.310. Reset 0x200 (DS). */
    dword BYTCNT;  /* 0x0020: 0x20 Byte Count Register. DS §5.5.5.9 p.310. Reset 0x200 (DS). */
    dword INTMASK;  /* 0x0024: 0x24 Interrupt Mask Register. DS §5.5.5.10 p.311. Reset 0x0 (DS). */
    dword CMDARG;  /* 0x0028: 0x28 Instruction content segment register. DS §5.5.5.11 p.311. Reset 0x0 (DS). */
    dword CMD;  /* 0x002c: 0x2c Command register. DS §5.5.5.12 p.311. Reset 0x20000000 (DS). */
    dword RESP0;  /* 0x0030: 0x30 Response reply register 0. DS §5.5.5.13 p.314. Reset 0x0 (DS). */
    dword RESP1;  /* 0x0034: 0x34 Response reply register 1. DS §5.5.5.14 p.315. Reset 0x0 (DS). */
    dword RESP2;  /* 0x0038: 0x38 Response reply register 2. DS §5.5.5.15 p.315. Reset 0x0 (DS). */
    dword RESP3;  /* 0x003c: 0x3c Response reply register 3. DS §5.5.5.16 p.315. Reset 0x0 (DS). */
    dword MINTSTS;  /* 0x0040: 0x40 Interrupt Mask Register. DS §5.5.5.17 p.315. Note: MISTATUS = RINTSTS and INTMASK Reset 0x0 (DS). */
    dword RINTSTS;  /* 0x0044: 0x44 Interrupt Status Register. DS §5.5.5.18 p.317. Reset 0x0 (DS). */
    dword STATUS;  /* 0x0048: 0x48 Status register, mainly used to check the. DS §5.5.5.19 p.318. Reset 0x406 (DS). */
    dword FIFOTH;  /* 0x004c: 0x4c FIFO Threshold Register. DS §5.5.5.20 p.319. Bit 27 is not listed in the datasheet (reserved). Reset 0x7f0000 */
    dword CDETECT;  /* 0x0050: 0x50 Card detection register. DS §5.5.5.21 p.321. */
    dword WRTPRT;  /* 0x0054: 0x54 Write protection register. DS §5.5.5.22 p.321. */
    dword RESERVED_88[1];  /* 0x0058: 0x58-0x5b */
    dword TCBCNT;  /* 0x005c: 0x5c CIU Byte transmitted by the module Number. DS §5.5.5.23 p.321. Reset 0x0 (DS). */
    dword TBBCNT;  /* 0x0060: 0x60 Host with BIU_FIFO byte of interaction data. DS §5.5.5.24 p.321. Reset 0x0 (DS). */
    dword DEBNCE;  /* 0x0064: 0x64 Card detection bounce register (unit is. DS §5.5.5.25 p.322. Reset 0xffffff (DS). */
    dword USRID;  /* 0x0068: 0x68 User ID Register. DS §5.5.5.26 p.323. Reset 0x45700311 (DS). */
    dword VERID;  /* 0x006c: 0x6c Soft core version ID register. DS §5.5.5.27 p.323. Reset 0x5342250a (DS). */
    dword HCON;  /* 0x0070: 0x70 Hardware Configuration Registers. DS §5.5.5.28 p.323. Reset 0xc44cc1 (DS). */
    dword RESERVED_116[1];  /* 0x0074: 0x74-0x77 */
    dword RST_n;  /* 0x0078: 0x78 Hard reset register. DS §5.5.5.29 p.323. Reset 0x1 (DS). */
    dword RESERVED_124[33];  /* 0x007c: 0x7c-0xff */
    dword CardThrCtl;  /* 0x0100: 0x100 Card read threshold enable register. DS §5.5.5.30 p.323. Reset 0x0 (DS). */
    dword Back_end_power;  /* 0x0104: 0x104 Back_end Power register. DS §5.5.5.31 p.325. Reset 0x0 (DS). */
    dword RESERVED_264[2];  /* 0x0108: 0x108-0x10f */
    dword ENABLE_SHIFT;  /* 0x0110: 0x110 Conversion Phase Control Register. DS §5.5.5.32 p.325. Reset 0x0 (DS). */
    dword RESERVED_276[59];  /* 0x0114: 0x114-0x1ff */
    dword DATA;  /* 0x0200: 0x200 DS §5.5.5.33 p.325. Reset 0x0 (DS). */
} SDIO_Type;

/* SSI_Type - 100 bytes, 23 recovered fields. */
typedef struct {
    dword CTRLR0;  /* 0x0000: 0x00 Transmission mode and frame length. DS §5.2.5.1 p.254. The datasheet gives master and slave interpretations of */
    dword CTRLR1;  /* 0x0004: 0x04 Number of received data frames. DS §5.2.5.2 p.256. Reset 0x0 (DS). */
    dword SSIENR;  /* 0x0008: 0x08 SPI module enable. DS §5.2.5.3 p.256. FW: 0 reads, 1 write. Reset 0x0 (DS). */
    dword RESERVED_12[1];  /* 0x000c: 0xc-0xf */
    dword SER;  /* 0x0010: 0x10 slave Chip select enable. DS §5.2.5.4 p.256. Reset 0x0 (DS). */
    dword BAUDR;  /* 0x0014: 0x14 Clock enable and frequency division. DS §5.2.5.5 p.256. Reset 0x0 (DS). */
    dword TXFTLR;  /* 0x0018: 0x18 Transmit FIFO threshold. DS §5.2.5.6 p.258. FW: 0 reads, 1 write. Reset 0x0 (DS). */
    dword RXFTLR;  /* 0x001c: 0x1c Receive FIFO threshold. DS §5.2.5.7 p.258. FW: 0 reads, 1 write. Reset 0x0 (DS). */
    dword TXFLR;  /* 0x0020: 0x20 Number of data in the transmit FIFO. DS §5.2.5.8 p.258. Reset 0x0 (DS). */
    dword RXFLR;  /* 0x0024: 0x24 Number of data in receive FIFO. DS §5.2.5.9 p.258. Reset 0x0 (DS). */
    dword SR;  /* 0x0028: 0x28 SPI module status. DS §5.2.5.10 p.258. Reset 0x6 (DS). */
    dword IMR;  /* 0x002c: 0x2c Interrupt mask register. DS §5.2.5.11 p.260. FW: 0 reads, 1 write. Reset 0x3f (DS). */
    dword ISR;  /* 0x0030: 0x30 Masked interrupt register. DS §5.2.5.12 p.260. Reset 0x0 (DS). */
    dword RISR;  /* 0x0034: 0x34 Unmasked interrupt register. DS §5.2.5.13 p.260. Reset 0x0 (DS). */
    dword TXOICR;  /* 0x0038: 0x38 Transmit FIFO overflow Interrupt clear. DS §5.2.5.14 p.260. Reset 0x0 (DS). */
    dword RXOICR;  /* 0x003c: 0x3c Receive FIFO overflow Interrupt clear. DS §5.2.5.15 p.262. Reset 0x0 (DS). */
    dword RXUICR;  /* 0x0040: 0x40 Receive FIFO underflow Interrupt clear. DS §5.2.5.16 p.262. Reset 0x0 (DS). */
    dword RESERVED_68[1];  /* 0x0044: 0x44-0x47 */
    dword ICR;  /* 0x0048: 0x48 Clear ssi_txo_intr , ssi_rxu_intr , ssi_rxo_intr. DS §5.2.5.17 p.262. Reset 0x0 (DS). */
    dword RESERVED_76[3];  /* 0x004c: 0x4c-0x57 */
    dword IDR;  /* 0x0058: 0x58 Module ID Register. DS §5.2.5.18 p.262. Reset 0x11223344 (DS). */
    dword SSI_COMP_VERSION;  /* 0x005c: 0x5c Version number. DS §5.2.5.19 p.262. Reset 0x3331312a (DS). */
    dword DR;  /* 0x0060: 0x60 Data transmit / receive FIFO interface. DS §5.2.5.20 p.263. Printed RO in the datasheet, but it is the TX/RX F */
} SSI_Type;

/* SystemControl_Type - 1388 bytes, 119 recovered fields. */
typedef struct {
    dword SYS_SOFT_RSTN;  /* 0x0000: 0x00 per-module soft reset, self-clearing (DS §4.1.4.1 p.70) */
    dword CLK_MGR_REG0x04;  /* 0x0004: 0x04 PLL/clock-switch control (DS §4.2.5.1 p.78) */
    dword CLK_MGR_REG0x08;  /* 0x0008: 0x08 APLL config; divider fields only (DS §4.2.5.2 p.79) */
    dword CLK_MGR_REG0x0c;  /* 0x000c: 0x0c apll_frac[23:0] (DS §4.2.5.3 p.81) */
    dword CLK_MGR_REG0x10;  /* 0x0010: 0x10 BPLL config; divider fields only (DS §4.2.5.4 p.81) */
    dword CLK_MGR_REG0x14;  /* 0x0014: 0x14 bpll_frac[23:0] (DS §4.2.5.5 p.82) */
    dword CLK_MGR_REG0x18;  /* 0x0018: 0x18 clock divider numerators (DS §4.2.5.6 p.83) */
    dword CLK_MGR_REG0x1c;  /* 0x001c: 0x1c 32k/192k fractional dividers; bits not transcribed */
    dword CLK_MGR_REG0x20;  /* 0x0020: 0x20 codec MCLK + 8k/512k dividers; bits not transcribed */
    dword CLK_MGR_REG0x24;  /* 0x0024: 0x24 DAC/ADC/SDIO dividers, bus ratios; bits not transcribed */
    dword CLK_MGR_REG0x28;  /* 0x0028: 0x28 SDIO/USB dividers; bits not transcribed */
    dword CLK_MGR_REG0x2c;  /* 0x002c: 0x2c clock-gate enables; bits not transcribed */
    dword LCSFC_BAUDR;  /* 0x0030: 0x30 LCSFC SPI clock divider (DS §4.4.4.1 p.93) */
    dword IO_DIPLEX0;  /* 0x0034: 0x34 pad mux bank 0: JTAG/I2C/UART/PWM (DS §4.4.4.4 p.93) */
    dword IO_DIPLEX1;  /* 0x0038: 0x38 pad mux bank 1: SPI0/1, TDMA/BS lines, PTB2-6 (DS §4.4.4.5 p.97) */
    dword IO_DIPLEX2;  /* 0x003c: 0x3c pad mux bank 2: CLK_OUT/LCD/ADC/DAC (DS §4.4.4.6 p.101) */
    dword RESERVED_0x40;  /* 0x0040: 0x40 = DS IOMGR_REN_REG0, pull-ups (DS §4.4.4.7 p.105); FW @0x0301d5f8 */
    dword RESERVED_68[1];  /* 0x0044: 0x44-0x47 */
    dword RESERVED_0x48;  /* 0x0048: 0x48 = DS IOMGR_REN_REG2, PTB pull-ups (DS §4.4.4.9 p.113) */
    dword RESERVED_76[4];  /* 0x004c: 0x4c-0x5b */
    dword QUAD_ENABLE;  /* 0x005c: 0x5c LCSFC quad-mode enable (DS §4.4.4.3 p.93) */
    dword RESERVED_96[4];  /* 0x0060: 0x60-0x6f */
    dword DAC_CONTROL;  /* 0x0070: 0x70 baseband DAC control (DS §4.6.5.1 p.146) */
    dword ADC_CONTROL;  /* 0x0074: 0x74 baseband ADC control (DS §4.6.5.2 p.146) */
    dword RESERVED_120[2];  /* 0x0078: 0x78-0x7f */
    dword AUDIO_CONTROL;  /* 0x0080: 0x80 audio path routing (DS §4.6.5.3 p.148) */
    dword AUDIO_BUFFER_CLR;  /* 0x0084: 0x84 vocoder buffer clear (DS §4.6.5.4 p.150) */
    dword LINEOUT_CTRL;  /* 0x0088: 0x88 line-out enables (DS §4.6.5.5 p.150) */
    dword CODEC_I2C_MUX;  /* 0x008c: 0x8c codec control interface (DS §4.6.5.6 p.150) */
    dword RESERVED_144[28];  /* 0x0090: 0x90-0xff */
    dword WORK_MODE;  /* 0x0100: 0x100 baseband working mode (DS §4.6.5.7 p.151) */
    dword RF_MODE;  /* 0x0104: 0x104 RF interface mode (DS §4.6.5.8 p.152) */
    dword SIG_CENTER;  /* 0x0108: 0x108 TX/RX IQ DC-bias setting (DS §9.2.2.3 p.496) */
    dword TX_IF_FREQ;  /* 0x010c: 0x10c TX IF frequency word (DS §9.2.2.4 p.497) */
    dword RF_CONTROL;  /* 0x0110: 0x110 RF TX/RX interrupt advance (DS §9.2.2.5 p.498) */
    dword RF_MOD_BIAS_CTRL;  /* 0x0114: 0x114 TX signal amplitude adjustment (DS §9.2.2.6 p.498) */
    dword DEV_LIMITER;  /* 0x0118: 0x118 TX frequency-deviation threshold (DS §9.2.2.7 p.498) */
    dword RSSI_BIAS_VALUE;  /* 0x011c: 0x11c Signal-energy detection value and ADC DC-bias detection (DS §9.2.2.8 p.498) */
    dword THRESHOLD_VALUE;  /* 0x0120: 0x120 Sync-detection threshold (DS §9.2.2.9 p.499) */
    dword RESERVED_292[1];  /* 0x0124: 0x124-0x127 */
    dword PHASE_OUT;  /* 0x0128: 0x128 Phase-input amplitude detection in AF receive mode (DS §9.2.2.10 p.500) */
    dword SEND_DATA_SYNC_H;  /* 0x012c: 0x12c TX data sync pattern, high half (DS §9.2.2.11 p.500) */
    dword SEND_DATA_SYNC_L;  /* 0x0130: 0x130 TX data sync pattern, low half (see SEND_DATA_SYNC_H) (DS §9.2.2.12 p.500) */
    dword SEND_RC_SYNC_H;  /* 0x0134: 0x134 TX RC (reverse channel) sync pattern, high half (DS §9.2.2.13 p.502) */
    dword SEND_RC_SYNC_L;  /* 0x0138: 0x138 TX RC sync pattern, low half (DS §9.2.2.14 p.502) */
    dword RECV_MS_SYNC_H;  /* 0x013c: 0x13c RX MS data sync pattern, high half (DS §9.2.2.15 p.502) */
    dword RECV_MS_SYNC_L;  /* 0x0140: 0x140 RX MS data sync pattern, low half (DS §9.2.2.16 p.502) */
    dword RECV_BS_SYNC_H;  /* 0x0144: 0x144 RX BS data sync pattern, high half (DS §9.2.2.17 p.503) */
    dword RECV_BS_SYNC_L;  /* 0x0148: 0x148 RX BS data sync pattern, low half (DS §9.2.2.18 p.504) */
    dword RECV_TDMA1_SYNC_H;  /* 0x014c: 0x14c RX TDMA1 data sync pattern, high half (DS §9.2.2.19 p.504) */
    dword RECV_TDMA1_SYNC_L;  /* 0x0150: 0x150 RX TDMA1 data sync pattern, low half (DS §9.2.2.20 p.504) */
    dword RECV_TDMA2_SYNC_H;  /* 0x0154: 0x154 RX TDMA2 data sync pattern, high half (DS §9.2.2.21 p.505) */
    dword RECV_TDMA2_SYNC_L;  /* 0x0158: 0x158 RX TDMA2 data sync pattern, low half (DS §9.2.2.22 p.506) */
    dword RECV_RC_SYNC_H;  /* 0x015c: 0x15c RX RC data sync pattern, high half (DS §9.2.2.23 p.506) */
    dword RECV_RC_SYNC_L;  /* 0x0160: 0x160 RX RC data sync pattern, low half (DS §9.2.2.24 p.506) */
    dword RESERVED_356[1];  /* 0x0164: 0x164-0x167 */
    dword REG_0x168;  /* 0x0168: 0x168 not in DS; FW writes 0x14/0x98 (@0x03023760, 0x030237ba, 0x0302172c) */
    dword RESERVED_364[17];  /* 0x016c: 0x16c-0x1af */
    dword RX_IF_FREQ;  /* 0x01b0: 0x1b0 RX IF frequency word (DS §9.2.2.43 p.515) */
    dword RF_RECV_DELAY;  /* 0x01b4: 0x1b4 RX channel delay offset (DS §9.2.2.44 p.515) */
    dword MODEM_AK_CLK_CALB;  /* 0x01b8: 0x1b8 AK2401 clock adjustment control (DS §9.2.2.45 p.515) */
    dword AK2401_ADC_STATE;  /* 0x01bc: 0x1bc AK2401 ADC receive status (DS §9.2.2.46 p.516) */
    dword RESERVED_448[100];  /* 0x01c0: 0x1c0-0x34f */
    dword PI_CRC_MASK;  /* 0x0350: 0x350 PI frame CRC16 mask and initial value (DS §10.2.2.2 p.529) */
    dword RS_H_MASK;  /* 0x0354: 0x354 RS(12,9) code mask for the voice LC header (DS §10.2.2.3 p.529) */
    dword RS_H_INIT;  /* 0x0358: 0x358 RS code initial value for the voice LC header (DS §10.2.2.4 p.530) */
    dword RS_T_MASK;  /* 0x035c: 0x35c RS code mask for the terminator (DS §10.2.2.5 p.531) */
    dword RS_T_INIT;  /* 0x0360: 0x360 RS code initial value for the terminator (DS §10.2.2.6 p.531) */
    dword CSBK_CRC_MASK;  /* 0x0364: 0x364 CSBK CRC16 mask and initial value (DS §10.2.2.7 p.531) */
    dword MBCH_CRC_MASK;  /* 0x0368: 0x368 MBC header CRC16 mask and initial value (DS §10.2.2.8 p.531) */
    dword DATAH_CRC_MASK;  /* 0x036c: 0x36c Data header CRC16 mask and initial value (DS §10.2.2.9 p.531) */
    dword REG_0x370;  /* 0x0370: 0x370 not in DS; FW register_init writes 0xf0 (@0x030236d2) */
    dword REG_0x374;  /* 0x0374: 0x374 not in DS; FW register_init writes 0x1ff (@0x030236da) */
    dword REG_0x378;  /* 0x0378: 0x378 not in DS; FW register_init writes 0x10f (@0x030236e2) */
    dword REG_0x37c;  /* 0x037c: 0x37c not in DS; FW register_init writes 0 (@0x030236e6) */
    dword CRC8_INIT;  /* 0x0380: 0x380 Short LC CRC8 initial value (DS §10.2.2.10 p.533) */
    dword LOCAL_CC;  /* 0x0384: 0x384 Local colour code for TX and RX, voice-frame EMB PI setting (DS §10.2.2.11 p.533) */
    dword VOICE_EMB_CTRL;  /* 0x0388: 0x388 Voice frame F EMB fill settings (DS §10.2.2.12 p.533) */
    dword SCRAMBLE_REG;  /* 0x038c: 0x38c Basic voice-scrambling key (DS §10.2.2.13 p.534) */
    dword RX_TYPE_INFO;  /* 0x0390: 0x390 Received frame information (DS §10.2.2.14 p.535) */
    dword RX_INFO;  /* 0x0394: 0x394 Received RC frame information (DS §10.2.2.15 p.537) */
    dword SYS_INTERP_LIST;  /* 0x0398: 0x398 layer-2 interrupt vector list (DS §4.6.5.9 p.156) */
    dword SYS_INTERP_MASK;  /* 0x039c: 0x39c Mask for SYS_INTERP_LIST (DS §4.6.5.10 p.156) */
    dword SYS_INTERP_CLEAR;  /* 0x03a0: 0x3a0 Clear for SYS_INTERP_LIST (write 1 to clear) (DS §4.6.5.11 p.160) */
    dword LAYER3_INTERP_LIST;  /* 0x03a4: 0x3a4 layer-3 interrupt vector list (DS §4.6.5.12 p.160) */
    dword LAYER3_INTERP_MASK;  /* 0x03a8: 0x3a8 Mask for LAYER3_INTERP_LIST (DS §4.6.5.13 p.162) */
    dword LAYER3_INTERP_CLEAR;  /* 0x03ac: 0x3ac Clear for LAYER3_INTERP_LIST (DS §4.6.5.14 p.165) */
    dword INTERP_CLEAR;  /* 0x03b0: 0x3b0 30 ms/RF/PCM interrupt clear (DS §4.6.5.15 p.166) */
    dword INTERP_CLEAR_AUX;  /* 0x03b4: 0x3b4 not in DS; FW writes 0x1800 (cps_serial_field_rw_* family) */
    dword RESERVED_952[18];  /* 0x03b8: 0x3b8-0x3ff */
    dword LAYER2_CONTROL;  /* 0x0400: 0x400 L2 mode control (DS §9.2.2.48 p.517, §10.2.2.16 p.537) */
    dword LAYER2_SLOTON;  /* 0x0404: 0x404 L2 timeslot switch (DS §10.2.2.17 p.539) */
    dword LAYER2_TXRX_CTRL;  /* 0x0408: 0x408 L2 TX/RX control (DS §9.2.2.49 p.517, §10.2.2.18 p.541) */
    dword LAYER2_SLOT_CNT;  /* 0x040c: 0x40c L2 slot count initial value (DS §10.2.2.19 p.543) */
    dword RESERVED_1040[1];  /* 0x0410: 0x410-0x413 */
    dword LAYER2_SLOT_UPDATE;  /* 0x0414: 0x414 L2 slot update (DS §10.2.2.21 p.544) */
    dword LAYER2_SEND_TYPE;  /* 0x0418: 0x418 L2 TX frame type (DS §10.2.2.22 p.545) */
    dword LAYER2_STATUS;  /* 0x041c: 0x41c L2 slot status, RO (DS §10.2.2.23 p.549) */
    dword RESERVED_1056[1];  /* 0x0420: 0x420-0x423 */
    dword LAYER2_SLOT_PRE;  /* 0x0424: 0x424 L2 interrupt pre-position (DS §10.2.2.24 p.549) */
    dword RESERVED_1064[54];  /* 0x0428: 0x428-0x4ff */
    dword FM_BANDWIDTH;  /* 0x0500: 0x500 FM bandwidth and filter settings (DS §11.2.2.2 p.592) */
    dword FM_DEV_COEF;  /* 0x0504: 0x504 FM deviation coefficient (DS §11.2.2.3 p.594) */
    dword RESERVED_1288[1];  /* 0x0508: 0x508-0x50b */
    dword SUBVOICE_COEF;  /* 0x050c: 0x50c Sub-audio (CTCSS/CDCSS) coefficient (DS §11.2.2.5 p.594) */
    dword FM_MOD;  /* 0x0510: 0x510 FM modulation control (DS §11.2.2.6 p.595) */
    dword RESERVED_1300[1];  /* 0x0514: 0x514-0x517 */
    dword CTCSS_ADDR;  /* 0x0518: 0x518 CTCSS tone selection (DS §11.2.2.7 p.596) */
    dword RESERVED_1308[2];  /* 0x051c: 0x51c-0x523 */
    dword SELCALL_TONE;  /* 0x0524: 0x524 Selective-call tone (DS §11.2.2.10 p.598) */
    dword TONE_SEND_CTRL;  /* 0x0528: 0x528 Tone transmit control (DS §11.2.2.11 p.598) */
    dword RESERVED_1324[9];  /* 0x052c: 0x52c-0x54f */
    dword FM_TONE1;  /* 0x0550: 0x550 FM tone generator 1 (DS §11.2.2.21 p.602) */
    dword FM_TONE2;  /* 0x0554: 0x554 FM tone generator 2 (DS §11.2.2.22 p.604) */
    dword FM_TONE3;  /* 0x0558: 0x558 FM tone generator 3 (DS §11.2.2.23 p.604) */
    dword FM_TONE4;  /* 0x055c: 0x55c FM tone generator 4 (DS §11.2.2.24 p.604) */
    dword FM_PTT;  /* 0x0560: 0x560 FM PTT control (DS §11.2.2.25 p.604) */
    dword RESERVED_1380[1];  /* 0x0564: 0x564-0x567 */
    dword FM_DECODE_FLAG2;  /* 0x0568: 0x568 FM decode flags 2 (DS §11.2.2.27 p.605) */
} SystemControl_Type;

/* TIMER_CH_Type - 20 bytes, 5 recovered fields. */
typedef struct {
    dword LoadCount;  /* 0x0000: +0x00 reload value */
    dword CurrentValue;  /* 0x0004: +0x04 live down-counter (RO) */
    dword ControlReg;  /* 0x0008: +0x08 bit0 enable, bit1 mode(periodic), bit2 int_mask */
    dword EOI;  /* 0x000c: +0x0c read to clear this channel's interrupt (RO) */
    dword IntStatus;  /* 0x0010: +0x10 this channel's masked interrupt status (RO) */
} TIMER_CH_Type;

/* TIMER_Type - 176 bytes, 6 recovered fields. */
typedef struct {
    TIMER_CH_Type CH[6];  /* 0x0000: Timer1..Timer6 @ +0x00,+0x14,+0x28,+0x3c,+0x50,+0x64; CONFIRMED live+datasheet */
    dword RESERVED_120[10];  /* 0x0078: 0x78-0x9f */
    dword TimersIntStatus;  /* 0x00a0: 0xa0 all-channel masked interrupt status (RO) */
    dword TimersEOI;  /* 0x00a4: 0xa4 read to clear all channels' interrupts (RO) */
    dword TimersRawIntStatus;  /* 0x00a8: 0xa8 all-channel unmasked raw interrupt status (RO) */
    dword TIMERS_COMP_VERSION;  /* 0x00ac: 0xac DesignWare IP component version (RO) */
} TIMER_Type;

/* UART_Type - 136 bytes, 10 recovered fields. */
typedef struct {
    dword RBR_THR_DLL;  /* 0x0000: 0x00 Receive buffer register. DS §5.4.5.1 p.274. FW: 2 reads, 7 writes. Reset 0x0 (DS). */
    dword IER_DLH;  /* 0x0004: 0x04 Interrupt enable register. DS §5.4.5.5 p.275. FW: 0 reads, 2 writes. Reset 0x0 (DS). */
    dword IIR_FCR;  /* 0x0008: 0x08 Interrupt Flag Register. DS §5.4.5.6 p.277. FW: 0 reads, 2 writes. Reset 0x1 (DS). */
    dword LCR;  /* 0x000c: 0x0c Line Control Register. DS §5.4.5.8 p.279. FW: 4 reads, 2 writes. Bit 5 (stick parity) is reserved and reads as */
    dword MCR;  /* 0x0010: 0x10 Modem Control registers. DS §5.4.5.9 p.281. Reset 0x0 (DS). */
    dword LSR;  /* 0x0014: 0x14 Line Status Register. DS §5.4.5.10 p.281. FW: 5 reads, 0 writes. Reset 0x60 (DS). */
    dword RESERVED_24[25];  /* 0x0018: 0x18-0x7b */
    dword USR;  /* 0x007c: 0x7c FIFO Status Flags. DS §5.4.5.11 p.283. FW: 4 reads, 0 writes. Reset 0x0 (DS). */
    dword TFL;  /* 0x0080: 0x80 The amount of data in the transmit FIFO. DS §5.4.5.12 p.285. Reset 0x0 (DS). */
    dword RFL;  /* 0x0084: 0x84 DS §5.4.5.13 p.285. Reset 0x0 (DS). */
} UART_Type;

/* USB_Type - 20484 bytes, 91 recovered fields. */
typedef struct {
    dword RESERVED_1[2];  /* 0x0000: 0x0-0x7 */
    dword GAHBCFG;  /* 0x0008: 0x08 AHB Configuration , global AHB Configuration. DS §5.6.5.1 p.336. Reset 0x0 (DS). */
    dword GUSBCFG;  /* 0x000c: 0x0c USB Configuration , Global USB Configuration. DS §5.6.5.2 p.338. Reset 0x1440 (DS). */
    dword GRSTCTL;  /* 0x0010: 0x10 Reset , global reset control register. DS §5.6.5.3 p.338. Reset 0x80000000 (DS). */
    dword GINTSTS;  /* 0x0014: 0x14 Interrupt , global interrupt status register. DS §5.6.5.4 p.340. */
    dword GINTMSK;  /* 0x0018: 0x18 Interrupt Mask , global interrupt mask. DS §5.6.5.5 p.343. Reset 0x0 (DS). */
    dword GRXSTSR;  /* 0x001c: 0x1c DS §5.6.5.6 p.344. Note: GRXSTSP For POP only The header information seems to be not POPable Data information */
    dword GRXSTSP;  /* 0x0020: 0x20 DS §5.6.5.6 p.344. Same layout as GRXSTSR; reading GRXSTSP also pops the entry. Note: GRXSTSP For POP only The */
    dword GRXFSIZ;  /* 0x0024: 0x24 Receive FIFO Size , RxFIFO Allocate control. DS §5.6.5.7 p.346. Reset 0x80 (DS). */
    dword GNPTXFSIZ;  /* 0x0028: 0x28 DS §5.6.5.8 p.346. Reset 0x800080 (DS). */
    dword RESERVED_44[3];  /* 0x002c: 0x2c-0x37 */
    dword GGPIO;  /* 0x0038: 0x38 General Purpose IO , general IO register. DS §5.6.5.9 p.346. Reset 0x40080000 (DS). */
    dword GUID;  /* 0x003c: 0x3c User ID , user ID register. DS §5.6.5.10 p.348. Reset 0x45700322 (DS). */
    dword GSNPSID;  /* 0x0040: 0x40 Synopsys ID , version number read-only. DS §5.6.5.11 p.348. Reset 0x4f54270a (DS). */
    dword GHWCFG1;  /* 0x0044: 0x44 User HW Config1 , soft core configuration. DS §5.6.5.12 p.349. Reset 0x264 (DS). */
    dword GHWCFG2;  /* 0x0048: 0x48 User HW Config2 , soft core configuration. DS §5.6.5.13 p.349. Reset 0x2288d114 (DS). */
    dword GHWCFG3;  /* 0x004c: 0x4c User HW Config3 , soft core configuration. DS §5.6.5.14 p.349. Reset 0x7a0400 (DS). */
    dword GHWCFG4;  /* 0x0050: 0x50 User HW Config4 , soft core configuration. DS §5.6.5.15 p.351. Reset 0xa300020 (DS). */
    dword GUSRSTS;  /* 0x0054: 0x54 User States , user-defined observation signals. DS §5.6.5.16 p.351. Reset 0x10700000 (DS). */
    dword RESERVED_88[43];  /* 0x0058: 0x58-0x103 */
    dword DIEPTXF1;  /* 0x0104: 0x104 DS §5.6.5.17 p.353. IN endpoint 1 TxFIFO size/start. Register Table 19 places DIEPTXF1 at 0x104 and DIEPTXF3 a */
    dword DIEPTXF3;  /* 0x0108: 0x108 DS §5.6.5.17 p.353. IN endpoint 3 TxFIFO size/start. Register Table 19 places DIEPTXF1 at 0x104 and DIEPTXF3 a */
    dword RESERVED_268[445];  /* 0x010c: 0x10c-0x7ff */
    dword DCFG;  /* 0x0800: 0x800 Device Configuration , device overall. DS §5.6.5.18 p.353. Reset 0x200000 (DS). */
    dword DCTL;  /* 0x0804: 0x804 Device Control , device overall control. DS §5.6.5.19 p.355. Reset 0x0 (DS). */
    dword DSTS;  /* 0x0808: 0x808 Device Status , device overall status. DS §5.6.5.20 p.357. Reset 0x2 (DS). */
    dword RESERVED_2060[1];  /* 0x080c: 0x80c-0x80f */
    dword DIEPMSK;  /* 0x0810: 0x810 equipment. DS §5.6.5.21 p.358. Reset 0x0 (DS). */
    dword DOEPMSK;  /* 0x0814: 0x814 DS §5.6.5.22 p.359. Reset 0x0 (DS). */
    dword DAINT;  /* 0x0818: 0x818 the device. DS §5.6.5.23 p.359. Reset 0x0 (DS). */
    dword DAINTMSK;  /* 0x081c: 0x81c DS §5.6.5.24 p.360. Reset 0x0 (DS). */
    dword RESERVED_2080[4];  /* 0x0820: 0x820-0x82f */
    dword DTHRCTL;  /* 0x0830: 0x830 Device Threshold Control , device threshold. DS §5.6.5.25 p.360. Reset 0x8100020 (DS). */
    dword DIEPEMPMSK;  /* 0x0834: 0x834 DS §5.6.5.26 p.360. Reset 0x0 (DS). */
    dword RESERVED_2104[50];  /* 0x0838: 0x838-0x8ff */
    dword DIEPCTL0;  /* 0x0900: 0x900 EP0. DS §5.6.5.27 p.361. Reset 0x8000 (DS). */
    dword RESERVED_2308[1];  /* 0x0904: 0x904-0x907 */
    dword DIEPINT0;  /* 0x0908: 0x908 DS §5.6.5.28 p.363. Endpoint 0 instance of DIEPINT0/1/3 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2316[1];  /* 0x090c: 0x90c-0x90f */
    dword DIEPTSIZ0;  /* 0x0910: 0x910 Device IN Endpoint0 Transfer Size , device IN. DS §5.6.5.29 p.363. Reset 0x0 (DS). */
    dword DIEPDMA0;  /* 0x0914: 0x914 DS §5.6.5.30 p.365. Endpoint 0 instance of DIEPDMA0/1/3 (stride 0x20). Reset 0x0 (DS). */
    dword DTXFSTS0;  /* 0x0918: 0x918 DS §5.6.5.31 p.365. Endpoint 0 instance of DTXFSTS0/1/3 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2332[1];  /* 0x091c: 0x91c-0x91f */
    dword DIEPCTL1;  /* 0x0920: 0x920 DS §5.6.5.36 p.369. Endpoint 1 instance of DIEPCTL1/3 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2340[1];  /* 0x0924: 0x924-0x927 */
    dword DIEPINT1;  /* 0x0928: 0x928 DS §5.6.5.28 p.363. Endpoint 1 instance of DIEPINT0/1/3 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2348[1];  /* 0x092c: 0x92c-0x92f */
    dword DIEPTSIZ1;  /* 0x0930: 0x930 DS §5.6.5.37 p.373. Endpoint 1 instance of DIEPTSIZ1/3 (stride 0x20). Reset 0x0 (DS). */
    dword DIEPDMA1;  /* 0x0934: 0x934 DS §5.6.5.30 p.365. Endpoint 1 instance of DIEPDMA0/1/3 (stride 0x20). Reset 0x0 (DS). */
    dword DTXFSTS1;  /* 0x0938: 0x938 DS §5.6.5.31 p.365. Endpoint 1 instance of DTXFSTS0/1/3 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2364[9];  /* 0x093c: 0x93c-0x95f */
    dword DIEPCTL3;  /* 0x0960: 0x960 DS §5.6.5.36 p.369. Endpoint 3 instance of DIEPCTL1/3 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2404[1];  /* 0x0964: 0x964-0x967 */
    dword DIEPINT3;  /* 0x0968: 0x968 DS §5.6.5.28 p.363. Endpoint 3 instance of DIEPINT0/1/3 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2412[1];  /* 0x096c: 0x96c-0x96f */
    dword DIEPTSIZ3;  /* 0x0970: 0x970 DS §5.6.5.37 p.373. Endpoint 3 instance of DIEPTSIZ1/3 (stride 0x20). Reset 0x0 (DS). */
    dword DIEPDMA3;  /* 0x0974: 0x974 DS §5.6.5.30 p.365. Endpoint 3 instance of DIEPDMA0/1/3 (stride 0x20). Reset 0x0 (DS). */
    dword DTXFSTS3;  /* 0x0978: 0x978 DS §5.6.5.31 p.365. Endpoint 3 instance of DTXFSTS0/1/3 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2428[97];  /* 0x097c: 0x97c-0xaff */
    dword DOEPCTL0;  /* 0x0b00: 0xb00 DS §5.6.5.32 p.365. Reset 0x8000 (DS). */
    dword RESERVED_2820[1];  /* 0x0b04: 0xb04-0xb07 */
    dword DOEPINT0;  /* 0x0b08: 0xb08 DS §5.6.5.33 p.367. Endpoint 0 instance of DOEPINT0/2/4 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2828[1];  /* 0x0b0c: 0xb0c-0xb0f */
    dword DOEPTSIZ0;  /* 0x0b10: 0xb10 OUT. DS §5.6.5.34 p.369. Reset 0x0 (DS). */
    dword DOEPDMA0;  /* 0x0b14: 0xb14 DS §5.6.5.35 p.369. Endpoint 0 instance of DOEPDMA0/2/4 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2840[10];  /* 0x0b18: 0xb18-0xb3f */
    dword DOEPCTL2;  /* 0x0b40: 0xb40 DS §5.6.5.38 p.373. Endpoint 2 instance of DOEPCTL2/4 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2884[1];  /* 0x0b44: 0xb44-0xb47 */
    dword DOEPINT2;  /* 0x0b48: 0xb48 DS §5.6.5.33 p.367. Endpoint 2 instance of DOEPINT0/2/4 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2892[1];  /* 0x0b4c: 0xb4c-0xb4f */
    dword DOEPTSIZ2;  /* 0x0b50: 0xb50 DS §5.6.5.39 p.376. Endpoint 2 instance of DOEPTSIZ2/4 (stride 0x20). Reset 0x0 (DS). */
    dword DOEPDMA2;  /* 0x0b54: 0xb54 DS §5.6.5.35 p.369. Endpoint 2 instance of DOEPDMA0/2/4 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2904[10];  /* 0x0b58: 0xb58-0xb7f */
    dword DOEPCTL4;  /* 0x0b80: 0xb80 DS §5.6.5.38 p.373. Endpoint 4 instance of DOEPCTL2/4 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2948[1];  /* 0x0b84: 0xb84-0xb87 */
    dword DOEPINT4;  /* 0x0b88: 0xb88 DS §5.6.5.33 p.367. Endpoint 4 instance of DOEPINT0/2/4 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2956[1];  /* 0x0b8c: 0xb8c-0xb8f */
    dword DOEPTSIZ4;  /* 0x0b90: 0xb90 DS §5.6.5.39 p.376. Endpoint 4 instance of DOEPTSIZ2/4 (stride 0x20). Reset 0x0 (DS). */
    dword DOEPDMA4;  /* 0x0b94: 0xb94 DS §5.6.5.35 p.369. Endpoint 4 instance of DOEPDMA0/2/4 (stride 0x20). Reset 0x0 (DS). */
    dword RESERVED_2968[154];  /* 0x0b98: 0xb98-0xdff */
    dword PCGCCTL;  /* 0x0e00: 0xe00 gating. DS §5.6.5.40 p.377. Reset 0x0 (DS). */
    dword RESERVED_3588[127];  /* 0x0e04: 0xe04-0xfff */
    dword DEVEP0FF;  /* 0x1000: 0x1000 DS §5.6.4 p.334. Endpoint 0 data FIFO push/pop window (4 KB at 0x1000). Listed in Register Table 19 only. */
    dword RESERVED_4100[1023];  /* 0x1004: 0x1004-0x1fff */
    dword DEVEP1FF;  /* 0x2000: 0x2000 DS §5.6.4 p.334. Endpoint 1 data FIFO push/pop window (4 KB at 0x2000). Listed in Register Table 19 only. */
    dword RESERVED_8196[1023];  /* 0x2004: 0x2004-0x2fff */
    dword DEVEP2FF;  /* 0x3000: 0x3000 DS §5.6.4 p.334. Endpoint 2 data FIFO push/pop window (4 KB at 0x3000). Listed in Register Table 19 only. */
    dword RESERVED_12292[1023];  /* 0x3004: 0x3004-0x3fff */
    dword DEVEP3FF;  /* 0x4000: 0x4000 DS §5.6.4 p.334. Endpoint 3 data FIFO push/pop window (4 KB at 0x4000). Listed in Register Table 19 only. */
    dword RESERVED_16388[1023];  /* 0x4004: 0x4004-0x4fff */
    dword DEVEP4FF;  /* 0x5000: 0x5000 DS §5.6.4 p.334. Endpoint 4 data FIFO push/pop window (4 KB at 0x5000). Listed in Register Table 19 only. */
} USB_Type;

/* WDG_Type - 24 bytes, 6 recovered fields. */
typedef struct {
    dword WDG_LOCK;  /* 0x0000: 0x00 Watchdog Lock Register. DS §4.10.5.1 p.216. Reset 0x1 (DS). */
    dword WDG_OT_LOAD_H;  /* 0x0004: 0x04 DS §4.10.5.2 p.216. Reset 0x7 (DS). */
    dword WDG_OT_LOAD_L;  /* 0x0008: 0x08 DS §4.10.5.3 p.216. The datasheet marks WDG_OT_LOAD_L read-only while its high half (WDG_OT_LOAD_H) is read-wr */
    dword WDG_RST_LOAD;  /* 0x000c: 0x0c Watchdog reset time initial value. DS §4.10.5.4 p.218. */
    dword WDG_EN;  /* 0x0010: 0x10 Watchdog enable. DS §4.10.5.5 p.218. Reset 0x0 (DS). */
    dword WDG_KNOCK;  /* 0x0014: 0x14 Watchdog feeding register. DS §4.10.5.6 p.218. Reset 0x0 (DS). */
} WDG_Type;

/* call_setup_sm_state - 27 bytes, 9 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte field_0x1;  /* 0x0001 */
    unsigned char _pad_0002[3];  /* offset 0x0002: not yet recovered */
    byte field_0x5;  /* 0x0005 */
    unsigned char _pad_0006[6];  /* offset 0x0006: not yet recovered */
    byte field_0xc_0;  /* 0x000c */
    unsigned char _pad_000d[3];  /* offset 0x000d: not yet recovered */
    byte caller_dmr_id_0;  /* 0x0010 */
    unsigned char _pad_0011[3];  /* offset 0x0011: not yet recovered */
    byte field_0x14;  /* 0x0014 */
    byte field_0x15;  /* 0x0015: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_0016[1];  /* offset 0x0016: not yet recovered */
    byte field_0x17;  /* 0x0017 */
    byte flags_0x18;  /* 0x0018 */
    byte flags_0x19;  /* 0x0019 */
    byte field_0x1a;  /* 0x001a */
} call_setup_sm_state;

/* call_setup_sm_state_aux - 177 bytes, 21 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte mode_0x1;  /* 0x0001 */
    byte field_0x2;  /* 0x0002 */
    byte field_0x3;  /* 0x0003 */
    byte field_0x4;  /* 0x0004 */
    byte field_0x5;  /* 0x0005 */
    unsigned char _pad_0006[1];  /* offset 0x0006: not yet recovered */
    byte field_0x7;  /* 0x0007 */
    byte field_0x8;  /* 0x0008 */
    unsigned char _pad_0009[1];  /* offset 0x0009: not yet recovered */
    byte field_0xa;  /* 0x000a: referenced by the corpus at this offset; purpose not recovered */
    byte field_0xb;  /* 0x000b */
    unsigned char _pad_000c[7];  /* offset 0x000c: not yet recovered */
    byte field_0x13;  /* 0x0013 */
    byte field_0x14;  /* 0x0014 */
    byte field_0x15;  /* 0x0015 */
    byte field_0x16;  /* 0x0016 */
    unsigned char _pad_0017[2];  /* offset 0x0017: not yet recovered */
    byte field_0x19;  /* 0x0019 */
    byte field_0x1a;  /* 0x001a */
    byte field_0x1b;  /* 0x001b */
    byte field_0x1c;  /* 0x001c: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_001d[5];  /* offset 0x001d: not yet recovered */
    byte field_0x22;  /* 0x0022 */
    byte field_0x23;  /* 0x0023 */
    byte field_0x24_0;  /* 0x0024 */
    unsigned char _pad_0025[7];  /* offset 0x0025: not yet recovered */
    byte field_0x2c_0;  /* 0x002c */
    unsigned char _pad_002d[127];  /* offset 0x002d: not yet recovered */
    byte field_0xac_0;  /* 0x00ac */
    unsigned char _pad_00ad[3];  /* offset 0x00ad: not yet recovered */
    byte field_0xb0;  /* 0x00b0 */
} call_setup_sm_state_aux;

/* dialog_flags_from_flash - 65 bytes, 28 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte flags_0x1;  /* 0x0001 */
    byte field_0x2;  /* 0x0002 */
    unsigned char _pad_0003[1];  /* offset 0x0003: not yet recovered */
    byte field_0x4_0;  /* 0x0004 */
    unsigned char _pad_0005[3];  /* offset 0x0005: not yet recovered */
    byte field_0x8_0;  /* 0x0008 */
    unsigned char _pad_0009[3];  /* offset 0x0009: not yet recovered */
    byte field_0xc;  /* 0x000c: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_000d[15];  /* offset 0x000d: not yet recovered */
    byte field_0x1c_0;  /* 0x001c */
    byte flags_0x1d;  /* 0x001d */
    byte flags_0x1e;  /* 0x001e */
    byte flags_0x1f;  /* 0x001f */
    byte field_0x20;  /* 0x0020 */
    byte field_0x21;  /* 0x0021 */
    unsigned char _pad_0022[2];  /* offset 0x0022: not yet recovered */
    byte field_0x24_0;  /* 0x0024 */
    unsigned char _pad_0025[3];  /* offset 0x0025: not yet recovered */
    byte field_0x28_0;  /* 0x0028 */
    byte field_0x29;  /* 0x0029: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_002a[3];  /* offset 0x002a: not yet recovered */
    byte flags_0x2d;  /* 0x002d */
    byte field_0x2e;  /* 0x002e */
    byte flags_0x2f;  /* 0x002f */
    byte field_0x30;  /* 0x0030 */
    byte field_0x31;  /* 0x0031: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x32;  /* 0x0032 */
    byte field_0x33;  /* 0x0033 */
    byte field_0x34_0;  /* 0x0034 */
    unsigned char _pad_0035[1];  /* offset 0x0035: not yet recovered */
    byte field_0x36_0;  /* 0x0036 */
    unsigned char _pad_0037[1];  /* offset 0x0037: not yet recovered */
    byte field_0x38;  /* 0x0038 */
    byte field_0x39;  /* 0x0039: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x3a;  /* 0x003a */
    byte field_0x3b;  /* 0x003b */
    byte field_0x3c;  /* 0x003c */
    byte field_0x3d;  /* 0x003d */
    byte field_0x3e;  /* 0x003e */
    byte field_0x3f;  /* 0x003f */
    byte field_0x40;  /* 0x0040 */
} dialog_flags_from_flash;

/* dialog_history_ui_state - 2571 bytes, 6 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte field_0x1;  /* 0x0001: referenced by the corpus at this offset; purpose not recovered */
    byte index_0x2;  /* 0x0002 */
    byte field_0x3;  /* 0x0003 */
    byte field_0x4;  /* 0x0004 */
    unsigned char _pad_0005[2563];  /* offset 0x0005: not yet recovered */
    byte field_0xa08;  /* 0x0a08 */
    byte field_0xa09;  /* 0x0a09 */
    byte field_0xa0a;  /* 0x0a0a */
} dialog_history_ui_state;

/* dm32_settings_block04 - 818 bytes, 37 recovered fields. */
typedef struct {
    byte power_on_interface;  /* 0x0000 */
    unsigned char _pad_0001[18];  /* offset 0x0001: not yet recovered */
    byte field_0x13;  /* 0x0013: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_0014[10];  /* offset 0x0014: not yet recovered */
    byte auto_power_off;  /* 0x001e */
    unsigned char _pad_001f[1];  /* offset 0x001f: not yet recovered */
    byte alert_tone_flags_1;  /* 0x0020 */
    byte alert_tone_flags_2;  /* 0x0021 */
    unsigned char _pad_0022[7];  /* offset 0x0022: not yet recovered */
    byte field_0x29;  /* 0x0029: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_002a[3];  /* offset 0x002a: not yet recovered */
    byte field_0x2d;  /* 0x002d: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_002e[3];  /* offset 0x002e: not yet recovered */
    byte field_0x31;  /* 0x0031: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x32;  /* 0x0032 */
    byte display_flags;  /* 0x0033 */
    byte callsign_colour;  /* 0x0034 */
    byte standby_text_colour;  /* 0x0035 */
    unsigned char _pad_0036[2];  /* offset 0x0036: not yet recovered */
    byte field_0x38;  /* 0x0038 */
    byte field_0x39;  /* 0x0039 */
    byte zone_a_colour;  /* 0x003a */
    byte field_0x3b;  /* 0x003b */
    unsigned char _pad_003c[4];  /* offset 0x003c: not yet recovered */
    byte gps_flags;  /* 0x0040 */
    unsigned char _pad_0041[4];  /* offset 0x0041: not yet recovered */
    byte field_0x45_toggle_bit0;  /* 0x0045 */
    unsigned char _pad_0046[22];  /* offset 0x0046: not yet recovered */
    byte field_0x5c;  /* 0x005c: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_005d[3];  /* offset 0x005d: not yet recovered */
    byte digital_decode_flags;  /* 0x0060 */
    unsigned char _pad_0061[4];  /* offset 0x0061: not yet recovered */
    byte digital_settings_flags;  /* 0x0065 */
    unsigned char _pad_0066[1];  /* offset 0x0066: not yet recovered */
    byte field_0x67_packed_flags;  /* 0x0067 */
    unsigned char _pad_0068[24];  /* offset 0x0068: not yet recovered */
    byte vfo_embedded_flags;  /* 0x0080 */
    unsigned char _pad_0081[4];  /* offset 0x0081: not yet recovered */
    byte lock_flags;  /* 0x0085 */
    byte auto_keypad_lock_delay;  /* 0x0086 */
    byte sk1_short_func;  /* 0x0087 */
    byte sk1_long_func;  /* 0x0088 */
    byte sk2_short_func;  /* 0x0089 */
    byte sk2_long_func;  /* 0x008a */
    unsigned char _pad_008b[2];  /* offset 0x008b: not yet recovered */
    byte p1_short_func;  /* 0x008d */
    byte p1_long_func;  /* 0x008e */
    byte p2_short_func;  /* 0x008f */
    byte p2_long_func;  /* 0x0090 */
    unsigned char _pad_0091[2];  /* offset 0x0091: not yet recovered */
    byte long_press_time;  /* 0x0093 */
    unsigned char _pad_0094[12];  /* offset 0x0094: not yet recovered */
    byte opaque_language_blob_0;  /* 0x00a0 */
    byte field_0xa1;  /* 0x00a1 */
    unsigned char _pad_00a2[1];  /* offset 0x00a2: not yet recovered */
    byte field_0xa3;  /* 0x00a3 */
    byte field_0xa4;  /* 0x00a4 */
    byte field_0xa5;  /* 0x00a5 */
    unsigned char _pad_00a6[603];  /* offset 0x00a6: not yet recovered */
    byte aprs_scheduled_send_time;  /* 0x0301 */
    byte field_0x302_toggle_maybe_aprs_related;  /* 0x0302 */
    unsigned char _pad_0303[46];  /* offset 0x0303: not yet recovered */
    byte field_0x331_toggle_companion_of_0x302;  /* 0x0331 */
} dm32_settings_block04;

/* dmr_call_config_state - 20 bytes, 8 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte field_0x1;  /* 0x0001: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x2;  /* 0x0002 */
    byte field_0x3;  /* 0x0003 */
    byte field_0x4;  /* 0x0004 */
    byte field_0x5;  /* 0x0005 */
    byte field_0x6;  /* 0x0006: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x7;  /* 0x0007 */
    byte field_0x8;  /* 0x0008: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x9;  /* 0x0009 */
    byte field_0xa;  /* 0x000a: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_000b[4];  /* offset 0x000b: not yet recovered */
    byte field_0xf;  /* 0x000f: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x10;  /* 0x0010 */
    unsigned char _pad_0011[2];  /* offset 0x0011: not yet recovered */
    byte field_0x13;  /* 0x0013 */
} dmr_call_config_state;

/* dmr_status_flags - 20 bytes, 6 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte field_0x1;  /* 0x0001 */
    byte field_0x2;  /* 0x0002 */
    byte field_0x3;  /* 0x0003 */
    byte field_0x4;  /* 0x0004: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_0005[3];  /* offset 0x0005: not yet recovered */
    byte field_0x8_0;  /* 0x0008 */
    unsigned char _pad_0009[3];  /* offset 0x0009: not yet recovered */
    byte field_0xc;  /* 0x000c */
    unsigned char _pad_000d[3];  /* offset 0x000d: not yet recovered */
    byte field_0x10_0;  /* 0x0010 */
    unsigned char _pad_0011[3];  /* offset 0x0011: not yet recovered */
} dmr_status_flags;

/* menu_screen_state - 9 bytes, 8 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte index_0x1;  /* 0x0001 */
    byte index_0x2;  /* 0x0002 */
    byte index_0x3;  /* 0x0003 */
    byte index_0x4;  /* 0x0004 */
    byte index_0x5;  /* 0x0005 */
    byte index_0x6;  /* 0x0006 */
    byte field_0x7;  /* 0x0007 */
    byte field_0x8;  /* 0x0008 */
} menu_screen_state;

/* radio_mode_state_0003e318 - 10 bytes, 9 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte field_0x1;  /* 0x0001 */
    byte flags_0x2;  /* 0x0002 */
    byte flags_0x3;  /* 0x0003 */
    byte flags_0x4;  /* 0x0004 */
    byte flags_0x5;  /* 0x0005 */
    byte flags_0x6;  /* 0x0006 */
    byte flags_0x7;  /* 0x0007 */
    byte field_0x8;  /* 0x0008 */
    byte field_0x9;  /* 0x0009 */
} radio_mode_state_0003e318;

/* rda5807m_shadow_t - 8 bytes, 4 recovered fields. */
typedef struct {
    byte r02[2];  /* 0x0000: 02H control: DHIZ DMUTE MONO BASS ... SEEKUP SEEK ... ENABLE */
    byte r03[2];  /* 0x0002: 03H CHAN[15:6] DIRECT_MODE TUNE BAND[3:2] SPACE[1:0] */
    byte r04[2];  /* 0x0004: 04H DE, SOFTMUTE_EN, AFCD */
    byte r05[2];  /* 0x0006: 05H INT_MODE, SEEKTH[11:8], VOLUME[3:0] */
} rda5807m_shadow_t;

/* state_0003ff3c - 4 bytes, 3 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte field_0x1;  /* 0x0001 */
    byte field_0x2;  /* 0x0002 */
    byte field_0x3;  /* 0x0003 */
} state_0003ff3c;

/* tx_ptt_ui_state - 104 bytes, 20 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte field_0x1;  /* 0x0001 */
    byte field_0x2;  /* 0x0002 */
    byte field_0x3;  /* 0x0003 */
    byte field_0x4;  /* 0x0004 */
    byte field_0x5;  /* 0x0005 */
    byte field_0x6;  /* 0x0006 */
    byte field_0x7;  /* 0x0007 */
    byte field_0x8;  /* 0x0008 */
    byte field_0x9;  /* 0x0009 */
    byte flags_0xa;  /* 0x000a */
    byte flags_0xb;  /* 0x000b */
    byte field_0xc;  /* 0x000c */
    unsigned char _pad_000d[3];  /* offset 0x000d: not yet recovered */
    byte field_0x10_0;  /* 0x0010 */
    unsigned char _pad_0011[3];  /* offset 0x0011: not yet recovered */
    byte field_0x14;  /* 0x0014 */
    unsigned char _pad_0015[3];  /* offset 0x0015: not yet recovered */
    byte field_0x18_0;  /* 0x0018 */
    unsigned char _pad_0019[3];  /* offset 0x0019: not yet recovered */
    byte field_0x1c;  /* 0x001c */
    unsigned char _pad_001d[17];  /* offset 0x001d: not yet recovered */
    byte field_0x2e;  /* 0x002e */
    unsigned char _pad_002f[16];  /* offset 0x002f: not yet recovered */
    byte field_0x3f;  /* 0x003f: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_0040[31];  /* offset 0x0040: not yet recovered */
    byte field_0x5f;  /* 0x005f */
    byte field_0x60_0;  /* 0x0060 */
    unsigned char _pad_0061[3];  /* offset 0x0061: not yet recovered */
    byte field_0x64_0;  /* 0x0064 */
    byte field_0x65;  /* 0x0065: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_0066[2];  /* offset 0x0066: not yet recovered */
} tx_ptt_ui_state;

/* vfo_display_state - 51 bytes, 18 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte field_0x1;  /* 0x0001 */
    byte field_0x2;  /* 0x0002 */
    byte field_0x3;  /* 0x0003 */
    byte field_0x4_0;  /* 0x0004 */
    byte field_0x5;  /* 0x0005: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x6;  /* 0x0006: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x7;  /* 0x0007: referenced by the corpus at this offset; purpose not recovered */
    byte flags_0x8;  /* 0x0008 */
    byte flags_0x9;  /* 0x0009 */
    byte field_0xa;  /* 0x000a */
    byte field_0xb;  /* 0x000b: referenced by the corpus at this offset; purpose not recovered */
    byte field_0xc;  /* 0x000c */
    byte flags_0xd;  /* 0x000d */
    byte field_0xe;  /* 0x000e */
    byte field_0xf;  /* 0x000f */
    byte field_0x10;  /* 0x0010: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x11_0;  /* 0x0011 */
    byte field_0x12;  /* 0x0012: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x13_0;  /* 0x0013 */
    byte field_0x14;  /* 0x0014: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x15;  /* 0x0015 */
    byte field_0x16;  /* 0x0016 */
    unsigned char _pad_0017[1];  /* offset 0x0017: not yet recovered */
    byte field_0x18;  /* 0x0018: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x19;  /* 0x0019 */
    unsigned char _pad_001a[1];  /* offset 0x001a: not yet recovered */
    byte field_0x1b;  /* 0x001b */
    byte field_0x1c;  /* 0x001c: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_001d[3];  /* offset 0x001d: not yet recovered */
    byte field_0x20;  /* 0x0020: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_0021[3];  /* offset 0x0021: not yet recovered */
    byte field_0x24;  /* 0x0024: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_0025[3];  /* offset 0x0025: not yet recovered */
    byte field_0x28;  /* 0x0028: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_0029[3];  /* offset 0x0029: not yet recovered */
    byte field_0x2c;  /* 0x002c: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_002d[3];  /* offset 0x002d: not yet recovered */
    byte field_0x30;  /* 0x0030: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x31_0;  /* 0x0031 */
    byte field_0x32;  /* 0x0032: referenced by the corpus at this offset; purpose not recovered */
} vfo_display_state;

/* vfo_freq_display_state - 95 bytes, 23 recovered fields. */
typedef struct {
    unsigned char _pad_0000[1];  /* offset 0x0000: not yet recovered */
    byte field_0x1;  /* 0x0001 */
    byte field_0x2;  /* 0x0002 */
    unsigned char _pad_0003[1];  /* offset 0x0003: not yet recovered */
    byte field_0x4;  /* 0x0004 */
    unsigned char _pad_0005[1];  /* offset 0x0005: not yet recovered */
    byte field_0x6;  /* 0x0006 */
    byte field_0x7;  /* 0x0007: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x8_0;  /* 0x0008 */
    unsigned char _pad_0009[1];  /* offset 0x0009: not yet recovered */
    byte field_0xa_0;  /* 0x000a */
    unsigned char _pad_000b[1];  /* offset 0x000b: not yet recovered */
    byte field_0xc;  /* 0x000c */
    byte field_0xd;  /* 0x000d */
    byte field_0xe;  /* 0x000e */
    byte field_0xf;  /* 0x000f */
    byte flags_0x10;  /* 0x0010 */
    byte field_0x11;  /* 0x0011 */
    byte field_0x12;  /* 0x0012 */
    byte field_0x13;  /* 0x0013 */
    byte field_0x14_0;  /* 0x0014 */
    unsigned char _pad_0015[1];  /* offset 0x0015: not yet recovered */
    byte field_0x16_0;  /* 0x0016 */
    unsigned char _pad_0017[43];  /* offset 0x0017: not yet recovered */
    byte field_0x42;  /* 0x0042: referenced by the corpus at this offset; purpose not recovered */
    unsigned char _pad_0043[9];  /* offset 0x0043: not yet recovered */
    byte field_0x4c;  /* 0x004c */
    unsigned char _pad_004d[7];  /* offset 0x004d: not yet recovered */
    byte field_0x54_0;  /* 0x0054 */
    unsigned char _pad_0055[1];  /* offset 0x0055: not yet recovered */
    byte field_0x56;  /* 0x0056 */
    unsigned char _pad_0057[1];  /* offset 0x0057: not yet recovered */
    byte field_0x58;  /* 0x0058: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x59;  /* 0x0059: referenced by the corpus at this offset; purpose not recovered */
    byte field_0x5a_0;  /* 0x005a */
    unsigned char _pad_005b[1];  /* offset 0x005b: not yet recovered */
    byte field_0x5c;  /* 0x005c */
    byte field_0x5d;  /* 0x005d */
    byte field_0x5e;  /* 0x005e */
} vfo_freq_display_state;

#endif /* DM32_STRUCTS_H */
