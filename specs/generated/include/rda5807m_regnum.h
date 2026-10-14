/* rda5807m_regnum.h - generated from specs/rdl/rda5807m.rdl by tools/src/dm32_patch_tools/gen_rdl.py; do not edit.
 *
 * Wire register numbers and command opcodes for a chip that is not memory-mapped.
 * Rule: a register's number is its `wire_addr` property if set, else its address offset
 * within its parent block divided by its width in bytes. For SPI NOR flashes the status
 * and ID registers are selected by opcode, so their wire_addr is the opcode that READS them.
 * The `cmd` block is the command set: one pseudo-register per opcode at offset ==
 * opcode (SystemRDL enum members cannot carry evidence properties, registers can).
 * [CONFIDENCE] after each entry is the register's confidence; the evidence behind it (datasheet
 * section, stock-firmware call sites, hardware reads) is in specs/generated/json/rda5807m.json.
 */
#ifndef RDA5807M_REGNUM_H
#define RDA5807M_REGNUM_H

/* registers */
enum rda5807m_reg {
    RDA5807M_REG_00H = 0x00, /* CHIPID [DATASHEET] (wire_addr) */
    RDA5807M_REG_02H = 0x02, /* Control [CONFIRMED] (wire_addr) */
    RDA5807M_REG_03H = 0x03, /* Channel [CONFIRMED] (wire_addr) */
    RDA5807M_REG_04H = 0x04, /* Control 2 [CONFIRMED] (wire_addr) */
    RDA5807M_REG_05H = 0x05, /* Volume / seek threshold [CONFIRMED] (wire_addr) */
    RDA5807M_REG_06H = 0x06, /* Open mode [CONFIRMED] (wire_addr) */
    RDA5807M_REG_07H = 0x07, /* Blend / band option [CONFIRMED] (wire_addr) */
    RDA5807M_REG_08H = 0x08, /* Direct frequency [CONFIRMED] (wire_addr) */
    RDA5807M_REG_09H = 0x09, /* 09H [CONFIRMED] (wire_addr) */
    RDA5807M_REG_0AH = 0x0A, /* Status [CONFIRMED] (wire_addr) */
    RDA5807M_REG_0BH = 0x0B, /* RSSI / RDS status [DATASHEET] (wire_addr) */
    RDA5807M_REG_0CH = 0x0C, /* RDSA [DATASHEET] (wire_addr) */
    RDA5807M_REG_0DH = 0x0D, /* RDSB [DATASHEET] (wire_addr) */
    RDA5807M_REG_0EH = 0x0E, /* RDSC [DATASHEET] (wire_addr) */
    RDA5807M_REG_0FH = 0x0F, /* RDSD [DATASHEET] (wire_addr) */
};

#endif /* RDA5807M_REGNUM_H */
