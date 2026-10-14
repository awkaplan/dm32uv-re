/* st7789v_madctl_regnum.h - generated from specs/rdl/st7789v_madctl.rdl by tools/src/dm32_patch_tools/gen_rdl.py; do not edit.
 *
 * Wire register numbers and command opcodes for a chip that is not memory-mapped.
 * Rule: a register's number is its `wire_addr` property if set, else its address offset
 * within its parent block divided by its width in bytes. For SPI NOR flashes the status
 * and ID registers are selected by opcode, so their wire_addr is the opcode that READS them.
 * The `cmd` block is the command set: one pseudo-register per opcode at offset ==
 * opcode (SystemRDL enum members cannot carry evidence properties, registers can).
 * [CONFIDENCE] after each entry is the register's confidence; the evidence behind it (datasheet
 * section, stock-firmware call sites, hardware reads) is in specs/generated/json/st7789v_madctl.json.
 */
#ifndef ST7789V_MADCTL_REGNUM_H
#define ST7789V_MADCTL_REGNUM_H

/* registers */
enum st7789v_madctl_reg {
    ST7789V_MADCTL_MADCTL = 0x36, /* MADCTL [CONFIRMED] (wire_addr) */
};

#endif /* ST7789V_MADCTL_REGNUM_H */
