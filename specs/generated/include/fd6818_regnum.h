/* fd6818_regnum.h - generated from specs/rdl/fd6818.rdl by tools/src/dm32_patch_tools/gen_rdl.py; do not edit.
 *
 * Wire register numbers and command opcodes for a chip that is not memory-mapped.
 * Rule: a register's number is its `wire_addr` property if set, else its address offset
 * within its parent block divided by its width in bytes. For SPI NOR flashes the status
 * and ID registers are selected by opcode, so their wire_addr is the opcode that READS them.
 * The `cmd` block is the command set: one pseudo-register per opcode at offset ==
 * opcode (SystemRDL enum members cannot carry evidence properties, registers can).
 * [CONFIDENCE] after each entry is the register's confidence; the evidence behind it (datasheet
 * section, stock-firmware call sites, hardware reads) is in specs/generated/json/fd6818.json.
 */
#ifndef FD6818_REGNUM_H
#define FD6818_REGNUM_H

/* Page 0 */
enum fd6818_page0 {
    FD6818_PAGE0_REG_00H  = 0x00, /* Chip ID / soft reset [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_01H  = 0x01, /* Revision ID [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_02H  = 0x02, /* Interrupt vector / interrupt clear [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_03H  = 0x03, /* Enable bits (FD6818 only) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_04H  = 0x04, /* Function enables [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_07H  = 0x07, /* CTCSS frequency word [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_08H  = 0x08, /* CDCSS code [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_09H  = 0x09, /* DTMF/SELCALL detector coefficients [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X0A = 0x0A, /* REG_0x0A (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0BH  = 0x0B, /* DTMF/SELCALL received code [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0CH  = 0x0C, /* Status [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_0X0D = 0x0D, /* REG_0x0D (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X0E = 0x0E, /* REG_0x0E (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X10 = 0x10, /* REG_0x10 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X11 = 0x11, /* REG_0x11 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X12 = 0x12, /* REG_0x12 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_13H  = 0x13, /* AGC gain step (FD6818B) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X14 = 0x14, /* REG_0x14 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_18H  = 0x18, /* MIC PGA gain [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_19H  = 0x19, /* PA bias output [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_1AH  = 0x1A, /* Band select [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X1F = 0x1F, /* REG_0x1F (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X20 = 0x20, /* REG_0x20 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X21 = 0x21, /* REG_0x21 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_22H  = 0x22, /* Crystal-range setting [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_23H  = 0x23, /* AF DAC level [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_24H  = 0x24, /* MCBSP input select / DTMF companion (disputed) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_25H  = 0x25, /* GPIO output enable / value [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_26H  = 0x26, /* GPIO0-3 output select [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_27H  = 0x27, /* GPIO4-7 output select [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_28H  = 0x28, /* GPIO input / PA gain [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_0X29 = 0x29, /* REG_0x29 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X2B = 0x2B, /* REG_0x2B (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_2CH  = 0x2C, /* External LNA gain / RX 300 Hz response [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_2DH  = 0x2D, /* RX 300 Hz response [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X30 = 0x30, /* Enable bits (FD6818B) [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_31H  = 0x31, /* TOT timer [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X32 = 0x32, /* REG_0x32 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X33 = 0x33, /* REG_0x33 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_34H  = 0x34, /* Clock gating / index selectors 3-6 [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_35H  = 0x35, /* Clock gating / index selectors 0-2 [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X37 = 0x37, /* REG_0x37 (undocumented, RX/TX mode) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_38H  = 0x38, /* Frequency, low word [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_39H  = 0x39, /* Frequency, high word [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_3AH  = 0x3A, /* Bandwidth (withdrawn) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_3BH  = 0x3B, /* Crystal frequency, low [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_3CH  = 0x3C, /* Crystal frequency, high [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_3DH  = 0x3D, /* Crystal-range constant [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X3E = 0x3E, /* REG_0x3E (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_3FH  = 0x3F, /* Interrupt mask [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_40H  = 0x40, /* FM deviation [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_41H  = 0x41, /* Crystal-range constant 2 [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_43H  = 0x43, /* RX filter / TX audio bandwidth [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_44H  = 0x44, /* FM demod gain / DISC mode [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X45 = 0x45, /* REG_0x45 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_46H  = 0x46, /* VOX thresholds [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_47H  = 0x47, /* AF output path / TX digital gain [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_48H  = 0x48, /* CIC mode (BYPASS) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X49 = 0x49, /* REG_0x49 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X4A = 0x4A, /* REG_0x4A (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_4BH  = 0x4B, /* CIC mode 2 (BYPASS) [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X4E = 0x4E, /* REG_0x4E (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_4FH  = 0x4F, /* Noise squelch thresholds [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_50H  = 0x50, /* TX audio mute / limit [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_51H  = 0x51, /* Sub-audio control [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_52H  = 0x52, /* Sub-audio tail / CTCSS detect [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_53H  = 0x53, /* Audio digital gains [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_54H  = 0x54, /* Scrambler / FSK rate [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X55 = 0x55, /* REG_0x55 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_56H  = 0x56, /* FSK CRC polynomial [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X58 = 0x58, /* REG_0x58 (undocumented, FSK) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_59H  = 0x59, /* FSK control [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5AH  = 0x5A, /* FSK sync bytes 0-1 [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5BH  = 0x5B, /* FSK sync bytes 2-3 [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5CH  = 0x5C, /* FSK type byte [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5DH  = 0x5D, /* FSK length [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5EH  = 0x5E, /* FSK FIFO thresholds [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_5FH  = 0x5F, /* FSK FIFO data [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_60H  = 0x60, /* Sub-audio detect [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_61H  = 0x61, /* SNR [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_62H  = 0x62, /* RSSI (two taps) [CONFIRMED] (wire_addr) */
    FD6818_PAGE0_REG_0X63 = 0x63, /* REG_0x63 (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_64H  = 0x64, /* VOX amplitude [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_65H  = 0x65, /* Relative RSSI / noise [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_67H  = 0x67, /* Squelch RSSI [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X68 = 0x68, /* REG_0x68 (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X69 = 0x69, /* REG_0x69 (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X6A = 0x6A, /* REG_0x6A (undocumented, read) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_70H  = 0x70, /* Tone generator enables / gains [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_71H  = 0x71, /* TONE1 frequency [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_72H  = 0x72, /* TONE2 frequency [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_73H  = 0x73, /* AFC [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X74 = 0x74, /* REG_0x74 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_75H  = 0x75, /* MCBSP control [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_76H  = 0x76, /* MCBSP data path [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X77 = 0x77, /* REG_0x77 (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_78H  = 0x78, /* RSSI squelch thresholds [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_79H  = 0x79, /* VOX close threshold [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_7AH  = 0x7A, /* VOX delay [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_0X7B = 0x7B, /* REG_0x7B (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_0X7C = 0x7C, /* REG_0x7C (undocumented) [STRUCTURAL] (wire_addr) */
    FD6818_PAGE0_REG_7DH  = 0x7D, /* RX digital gain [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_7EH  = 0x7E, /* DC filters [DATASHEET] (wire_addr) */
    FD6818_PAGE0_REG_7FH  = 0x7F, /* Page select [DATASHEET] (wire_addr) */
};

/* Page 1 */
enum fd6818_page1 {
    FD6818_PAGE1_REG_87H = 0x07, /* Compander amplitude [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_90H = 0x10, /* Soft mute [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_91H = 0x11, /* 1050 Hz decode setting [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_94H = 0x14, /* DTMF/SELCALL detect [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_96H = 0x16, /* RX DISC gain / RX compander [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_97H = 0x17, /* MIC sensitivity / TX compander [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_98H = 0x18, /* RX expander [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_99H = 0x19, /* TX compressor [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_9AH = 0x1A, /* Compander timing [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_9BH = 0x1B, /* Audio filter bypasses [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_9CH = 0x1C, /* DISC-mode setting [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_9DH = 0x1D, /* TX audio path select [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A1H = 0x21, /* Audio response filter A1 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A2H = 0x22, /* Audio response filter A2 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A3H = 0x23, /* Audio response filter A3 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A4H = 0x24, /* Audio response filter A4 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_A7H = 0x27, /* DISC-mode setting 2 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_B0H = 0x30, /* TX 300 Hz response B0 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_B1H = 0x31, /* TX 300 Hz response B1 [DATASHEET] (wire_addr) */
    FD6818_PAGE1_REG_B6H = 0x36, /* Sub-audio filters / gains [DATASHEET] (wire_addr) */
};

#endif /* FD6818_REGNUM_H */
