/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_record_load_from_block4 @ 0301163c (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_record_load_from_block4(uint param_1)

{
  undefined4 *puVar1;
  ushort block_id;
  undefined1 uStack_18;
  undefined2 uStack_17;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  byte bStack_12;
  
  block_id = flash_block_id_resolve_locked(4);
  if (((param_1 & 0xff) - 1 & 0xff) < 0x10) {
    flash_block_read(block_id,(param_1 & 0xff) * 0x10 + 0x4f9,&uStack_18,7);
    puVar1 = PTR_DAT_0301180c;
    *(undefined2 *)((int)PTR_DAT_0301180c + 2) = uStack_17;
    *(ushort *)(puVar1 + 2) = (ushort)bStack_15 * 0x1e;
    *(byte *)(puVar1 + 0x36) = *(byte *)(puVar1 + 0x36) & 0x7f | 0x80;
    if ((ushort)((ushort)bStack_15 * 0x1e) == 0) {
      *(byte *)(puVar1 + 0x36) = *(byte *)(puVar1 + 0x36) & 0x7f;
    }
    PTR_DAT_0301180c[1] = (uint)bStack_12 << 0x10 | (uint)bStack_14 | (uint)bStack_13 << 8;
  }
  else {
    *(byte *)(PTR_DAT_0301180c + 0x36) = *(byte *)(PTR_DAT_0301180c + 0x36) & 0x7f;
  }
  return;
}

