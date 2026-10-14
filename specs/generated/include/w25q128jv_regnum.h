/* w25q128jv_regnum.h - generated from specs/rdl/w25q128jv.rdl by tools/src/dm32_patch_tools/gen_rdl.py; do not edit.
 *
 * Wire register numbers and command opcodes for a chip that is not memory-mapped.
 * Rule: a register's number is its `wire_addr` property if set, else its address offset
 * within its parent block divided by its width in bytes. For SPI NOR flashes the status
 * and ID registers are selected by opcode, so their wire_addr is the opcode that READS them.
 * The `cmd` block is the command set: one pseudo-register per opcode at offset ==
 * opcode (SystemRDL enum members cannot carry evidence properties, registers can).
 * [CONFIDENCE] after each entry is the register's confidence; the evidence behind it (datasheet
 * section, stock-firmware call sites, hardware reads) is in specs/generated/json/w25q128jv.json.
 */
#ifndef W25Q128JV_REGNUM_H
#define W25Q128JV_REGNUM_H

/* Status registers */
enum w25q128jv_status {
    W25Q128JV_STATUS_SR1 = 0x05, /* Status Register-1 [CONFIRMED] (wire_addr) written by 01h after 06h (non-volatile bits) or after 50h (volatile copies); a second data byte after 01h also writes SR2 */
    W25Q128JV_STATUS_SR2 = 0x35, /* Status Register-2 [DATASHEET] (wire_addr) written by 31h after 06h (non-volatile) or 50h (volatile); or the second data byte of 01h */
    W25Q128JV_STATUS_SR3 = 0x15, /* Status Register-3 [DATASHEET] (wire_addr) written by 11h after 06h (non-volatile) or 50h (volatile) */
};

/* Identification */
enum w25q128jv_id {
    W25Q128JV_ID_JEDEC_ID  = 0x9F, /* JEDEC ID [CONFIRMED] (wire_addr) */
    W25Q128JV_ID_UNIQUE_ID = 0x4B, /* Unique ID [DATASHEET] (wire_addr) */
};

/* Instruction set (opcodes) */
enum w25q128jv_cmd {
    W25Q128JV_CMD_WRITE_STATUS_1                 = 0x01, /* Write Status Register-1 [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_PAGE_PROGRAM                   = 0x02, /* Page Program [CONFIRMED] DESTRUCTIVE */
    W25Q128JV_CMD_READ_DATA                      = 0x03, /* Read Data [CONFIRMED] */
    W25Q128JV_CMD_WRITE_DISABLE                  = 0x04, /* Write Disable [DATASHEET] */
    W25Q128JV_CMD_READ_STATUS_1                  = 0x05, /* Read Status Register-1 [CONFIRMED] */
    W25Q128JV_CMD_WRITE_ENABLE                   = 0x06, /* Write Enable [CONFIRMED] */
    W25Q128JV_CMD_FAST_READ                      = 0x0B, /* Fast Read [DATASHEET] */
    W25Q128JV_CMD_WRITE_STATUS_3                 = 0x11, /* Write Status Register-3 [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_READ_STATUS_3                  = 0x15, /* Read Status Register-3 [DATASHEET] */
    W25Q128JV_CMD_SECTOR_ERASE                   = 0x20, /* Sector Erase (4 KB) [CONFIRMED] DESTRUCTIVE */
    W25Q128JV_CMD_WRITE_STATUS_2                 = 0x31, /* Write Status Register-2 [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_QUAD_PAGE_PROGRAM              = 0x32, /* Quad Input Page Program [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_READ_STATUS_2                  = 0x35, /* Read Status Register-2 [DATASHEET] */
    W25Q128JV_CMD_INDIVIDUAL_LOCK                = 0x36, /* Individual Block/Sector Lock [DATASHEET] */
    W25Q128JV_CMD_INDIVIDUAL_UNLOCK              = 0x39, /* Individual Block/Sector Unlock [DATASHEET] */
    W25Q128JV_CMD_FAST_READ_DUAL_OUTPUT          = 0x3B, /* Fast Read Dual Output [DATASHEET] */
    W25Q128JV_CMD_READ_BLOCK_LOCK                = 0x3D, /* Read Block/Sector Lock [DATASHEET] */
    W25Q128JV_CMD_PROGRAM_SECURITY_REGISTER      = 0x42, /* Program Security Register [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_ERASE_SECURITY_REGISTER        = 0x44, /* Erase Security Register [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_READ_SECURITY_REGISTER         = 0x48, /* Read Security Register [DATASHEET] */
    W25Q128JV_CMD_READ_UNIQUE_ID                 = 0x4B, /* Read Unique ID [DATASHEET] */
    W25Q128JV_CMD_VOLATILE_SR_WRITE_ENABLE       = 0x50, /* Write Enable for Volatile Status Register [DATASHEET] */
    W25Q128JV_CMD_BLOCK_ERASE_32K                = 0x52, /* Block Erase (32 KB) [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_READ_SFDP                      = 0x5A, /* Read SFDP Register [DATASHEET] */
    W25Q128JV_CMD_CHIP_ERASE_60                  = 0x60, /* Chip Erase (60h) [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_ENABLE_RESET                   = 0x66, /* Enable Reset [DATASHEET] */
    W25Q128JV_CMD_FAST_READ_QUAD_OUTPUT          = 0x6B, /* Fast Read Quad Output [DATASHEET] */
    W25Q128JV_CMD_ERASE_PROGRAM_SUSPEND          = 0x75, /* Erase / Program Suspend [DATASHEET] */
    W25Q128JV_CMD_SET_BURST_WITH_WRAP            = 0x77, /* Set Burst with Wrap [DATASHEET] */
    W25Q128JV_CMD_ERASE_PROGRAM_RESUME           = 0x7A, /* Erase / Program Resume [DATASHEET] */
    W25Q128JV_CMD_GLOBAL_LOCK                    = 0x7E, /* Global Block/Sector Lock [DATASHEET] */
    W25Q128JV_CMD_MANUFACTURER_DEVICE_ID         = 0x90, /* Manufacturer / Device ID [DATASHEET] */
    W25Q128JV_CMD_MANUFACTURER_DEVICE_ID_DUAL_IO = 0x92, /* Manufacturer / Device ID Dual I/O [DATASHEET] */
    W25Q128JV_CMD_MANUFACTURER_DEVICE_ID_QUAD_IO = 0x94, /* Manufacturer / Device ID Quad I/O [DATASHEET] */
    W25Q128JV_CMD_GLOBAL_UNLOCK                  = 0x98, /* Global Block/Sector Unlock [DATASHEET] */
    W25Q128JV_CMD_RESET_DEVICE                   = 0x99, /* Reset Device [DATASHEET] */
    W25Q128JV_CMD_READ_JEDEC_ID                  = 0x9F, /* Read JEDEC ID [CONFIRMED] */
    W25Q128JV_CMD_RELEASE_POWER_DOWN_ID          = 0xAB, /* Release Power-down / Device ID [DATASHEET] */
    W25Q128JV_CMD_POWER_DOWN                     = 0xB9, /* Power-down [DATASHEET] */
    W25Q128JV_CMD_FAST_READ_DUAL_IO              = 0xBB, /* Fast Read Dual I/O [DATASHEET] */
    W25Q128JV_CMD_CHIP_ERASE_C7                  = 0xC7, /* Chip Erase (C7h) [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_BLOCK_ERASE_64K                = 0xD8, /* Block Erase (64 KB) [DATASHEET] DESTRUCTIVE */
    W25Q128JV_CMD_FAST_READ_QUAD_IO              = 0xEB, /* Fast Read Quad I/O [DATASHEET] */
};

/* Opcodes marked `destructive` in specs/rdl/w25q128jv.rdl (erase, program, status-register and
 * security-register writes): flag every call site that sends one. */
#define W25Q128JV_CMD_DESTRUCTIVE_COUNT 12
#define W25Q128JV_CMD_DESTRUCTIVE_LIST 0x01, 0x02, 0x11, 0x20, 0x31, 0x32, 0x42, 0x44, 0x52, 0x60, 0xC7, 0xD8
#define W25Q128JV_CMD_IS_DESTRUCTIVE(op) ((op) == 0x01 || (op) == 0x02 || (op) == 0x11 || (op) == 0x20 || (op) == 0x31 || (op) == 0x32 || (op) == 0x42 || (op) == 0x44 || (op) == 0x52 || (op) == 0x60 || (op) == 0xC7 || (op) == 0xD8)

/* encode enum drv_e */
enum w25q128jv_drv_e {
    W25Q128JV_DRV_PCT_100 = 0, /* 100% output driver strength */
    W25Q128JV_DRV_PCT_75  = 1, /* 75% */
    W25Q128JV_DRV_PCT_50  = 2, /* 50% */
    W25Q128JV_DRV_PCT_25  = 3, /* 25% (datasheet default) */
};

#endif /* W25Q128JV_REGNUM_H */
