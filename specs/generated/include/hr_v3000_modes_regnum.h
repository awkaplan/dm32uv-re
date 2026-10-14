/* hr_v3000_modes_regnum.h - generated from specs/rdl/hr_v3000_modes.rdl by tools/src/dm32_patch_tools/gen_rdl.py; do not edit.
 *
 * Wire register numbers and command opcodes for a chip that is not memory-mapped.
 * Rule: a register's number is its `wire_addr` property if set, else its address offset
 * within its parent block divided by its width in bytes. For SPI NOR flashes the status
 * and ID registers are selected by opcode, so their wire_addr is the opcode that READS them.
 * The `cmd` block is the command set: one pseudo-register per opcode at offset ==
 * opcode (SystemRDL enum members cannot carry evidence properties, registers can).
 * [CONFIDENCE] after each entry is the register's confidence; the evidence behind it (datasheet
 * section, stock-firmware call sites, hardware reads) is in specs/generated/json/hr_v3000_modes.json.
 */
#ifndef HR_V3000_MODES_REGNUM_H
#define HR_V3000_MODES_REGNUM_H

/* registers */
enum hr_v3000_modes_reg {
    HR_V3000_MODES_ECMODE = 0x05, /* ECMODE [DATASHEET] (wire_addr) */
    HR_V3000_MODES_DCMODE = 0x06, /* DCMODE [DATASHEET] (wire_addr) */
};

#endif /* HR_V3000_MODES_REGNUM_H */
