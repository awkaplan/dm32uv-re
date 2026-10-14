/* gd25q80_regnum.h - generated from specs/rdl/gd25q80.rdl by tools/src/dm32_patch_tools/gen_rdl.py; do not edit.
 *
 * Wire register numbers and command opcodes for a chip that is not memory-mapped.
 * Rule: a register's number is its `wire_addr` property if set, else its address offset
 * within its parent block divided by its width in bytes. For SPI NOR flashes the status
 * and ID registers are selected by opcode, so their wire_addr is the opcode that READS them.
 * The `cmd` block is the command set: one pseudo-register per opcode at offset ==
 * opcode (SystemRDL enum members cannot carry evidence properties, registers can).
 * [CONFIDENCE] after each entry is the register's confidence; the evidence behind it (datasheet
 * section, stock-firmware call sites, hardware reads) is in specs/generated/json/gd25q80.json.
 */
#ifndef GD25Q80_REGNUM_H
#define GD25Q80_REGNUM_H

/* Status register */
enum gd25q80_status {
    GD25Q80_STATUS_SR1 = 0x05, /* Status Register S7-S0 [STRUCTURAL] (wire_addr) written by 01h (first data byte), after 06h (non-volatile) or 50h (volatile) */
    GD25Q80_STATUS_SR2 = 0x35, /* Status Register S15-S8 [STRUCTURAL] (wire_addr) written by 01h (second data byte; a one-byte 01h clears CMP and QE), after 06h or 50h. No 31h on this part */
};

/* Identification */
enum gd25q80_id {
    GD25Q80_ID_JEDEC_ID = 0x9F, /* JEDEC ID [DATASHEET] (wire_addr) */
};

/* Instruction set (opcodes) */
enum gd25q80_cmd {
    GD25Q80_CMD_WRITE_STATUS               = 0x01, /* Write Status Register (WRSR) [STRUCTURAL] DESTRUCTIVE */
    GD25Q80_CMD_PAGE_PROGRAM               = 0x02, /* Page Program (PP) [STRUCTURAL] DESTRUCTIVE */
    GD25Q80_CMD_READ_DATA                  = 0x03, /* Read Data [DATASHEET] */
    GD25Q80_CMD_WRITE_DISABLE              = 0x04, /* Write Disable (WRDI) [STRUCTURAL] */
    GD25Q80_CMD_READ_STATUS_LO             = 0x05, /* Read Status Register S7-S0 [STRUCTURAL] */
    GD25Q80_CMD_WRITE_ENABLE               = 0x06, /* Write Enable (WREN) [STRUCTURAL] */
    GD25Q80_CMD_FAST_READ                  = 0x0B, /* Fast Read [DATASHEET] */
    GD25Q80_CMD_SECTOR_ERASE               = 0x20, /* Sector Erase (SE) [STRUCTURAL] DESTRUCTIVE */
    GD25Q80_CMD_QUAD_PAGE_PROGRAM          = 0x32, /* Quad Page Program [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_READ_STATUS_HI             = 0x35, /* Read Status Register S15-S8 [STRUCTURAL] */
    GD25Q80_CMD_DUAL_OUTPUT_FAST_READ      = 0x3B, /* Dual Output Fast Read [DATASHEET] */
    GD25Q80_CMD_PROGRAM_SECURITY_REGISTERS = 0x42, /* Program Security Registers [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_ERASE_SECURITY_REGISTERS   = 0x44, /* Erase Security Registers [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_READ_SECURITY_REGISTERS    = 0x48, /* Read Security Registers [DATASHEET] */
    GD25Q80_CMD_VOLATILE_SR_WRITE_ENABLE   = 0x50, /* Write Enable for Volatile Status Register [DATASHEET] */
    GD25Q80_CMD_BLOCK_ERASE_32K            = 0x52, /* Block Erase 32 KB [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_READ_SFDP                  = 0x5A, /* Read Serial Flash Discoverable Parameter [DATASHEET] */
    GD25Q80_CMD_CHIP_ERASE_60              = 0x60, /* Chip Erase (60h) [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_ENABLE_RESET               = 0x66, /* Enable Reset [DATASHEET] */
    GD25Q80_CMD_QUAD_OUTPUT_FAST_READ      = 0x6B, /* Quad Output Fast Read [DATASHEET] */
    GD25Q80_CMD_PROGRAM_ERASE_SUSPEND      = 0x75, /* Program/Erase Suspend (PES) [DATASHEET] */
    GD25Q80_CMD_SET_BURST_WITH_WRAP        = 0x77, /* Set Burst with Wrap [DATASHEET] */
    GD25Q80_CMD_PROGRAM_ERASE_RESUME       = 0x7A, /* Program/Erase Resume (PER) [DATASHEET] */
    GD25Q80_CMD_MANUFACTURER_DEVICE_ID     = 0x90, /* Read Manufacturer / Device ID (REMS) [DATASHEET] */
    GD25Q80_CMD_RESET                      = 0x99, /* Reset [DATASHEET] */
    GD25Q80_CMD_READ_IDENTIFICATION        = 0x9F, /* Read Identification (RDID) [DATASHEET] */
    GD25Q80_CMD_HIGH_PERFORMANCE_MODE      = 0xA3, /* High Performance Mode (HPM) [DATASHEET] */
    GD25Q80_CMD_RELEASE_DEEP_POWER_DOWN_ID = 0xAB, /* Release from Deep Power-Down / Read Device ID [DATASHEET] */
    GD25Q80_CMD_DEEP_POWER_DOWN            = 0xB9, /* Deep Power-Down [DATASHEET] */
    GD25Q80_CMD_DUAL_IO_FAST_READ          = 0xBB, /* Dual I/O Fast Read [DATASHEET] */
    GD25Q80_CMD_CHIP_ERASE_C7              = 0xC7, /* Chip Erase (C7h) [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_BLOCK_ERASE_64K            = 0xD8, /* Block Erase 64 KB [DATASHEET] DESTRUCTIVE */
    GD25Q80_CMD_QUAD_IO_WORD_FAST_READ     = 0xE7, /* Quad I/O Word Fast Read [DATASHEET] */
    GD25Q80_CMD_QUAD_IO_FAST_READ          = 0xEB, /* Quad I/O Fast Read [DATASHEET] */
    GD25Q80_CMD_CONTINUOUS_READ_MODE_RESET = 0xFF, /* Continuous Read Mode Reset [DATASHEET] */
};

/* Opcodes marked `destructive` in specs/rdl/gd25q80.rdl (erase, program, status-register and
 * security-register writes): flag every call site that sends one. */
#define GD25Q80_CMD_DESTRUCTIVE_COUNT 10
#define GD25Q80_CMD_DESTRUCTIVE_LIST 0x01, 0x02, 0x20, 0x32, 0x42, 0x44, 0x52, 0x60, 0xC7, 0xD8
#define GD25Q80_CMD_IS_DESTRUCTIVE(op) ((op) == 0x01 || (op) == 0x02 || (op) == 0x20 || (op) == 0x32 || (op) == 0x42 || (op) == 0x44 || (op) == 0x52 || (op) == 0x60 || (op) == 0xC7 || (op) == 0xD8)

#endif /* GD25Q80_REGNUM_H */
