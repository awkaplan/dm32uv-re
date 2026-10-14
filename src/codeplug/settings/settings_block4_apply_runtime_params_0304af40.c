/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_block4_apply_runtime_params @ 0304af40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 316 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_block4_apply_runtime_params(void)

{
  byte *pbVar1;
  ushort block_id;
  byte abStack_10 [3];
  byte bStack_d;
  
  block_id = flash_block_id_resolve_locked(4);
  flash_block_read(block_id,0x61,&bStack_d,1);
  func_0x0301e880(bStack_d);
  flash_block_read(block_id,0x62,&bStack_d,1);
  if (bStack_d == 0) {
    bStack_d = 1;
  }
  func_0x0301e8bc((bStack_d - 1) * 0x1e + 300 & 0xfffe);
  flash_block_read(block_id,99,&bStack_d,1);
  if (bStack_d < 9) {
    if (bStack_d == 0) {
      bStack_d = 1;
    }
  }
  else {
    bStack_d = 8;
  }
  func_0x0301e8c4(bStack_d);
  pbVar1 = _DAT_0304b080;
  flash_block_read(block_id,100,_DAT_0304b080,1);
  if (0x11 < *pbVar1) {
    *pbVar1 = 0;
  }
  *_DAT_0304b080 = *_DAT_0304b080 + 2;
  func_0x0301e8cc();
  func_0x0301e8a4(3);
  func_0x0301e8ac(3);
  func_0x0301e8b4(0x14);
  flash_block_read(block_id,0x60,abStack_10,1);
  if ((abStack_10[0] & 1) == 0) {
    *(byte *)(_DAT_0304b084 + 0x32) = *(byte *)(_DAT_0304b084 + 0x32) & 0xf7;
  }
  else {
    *(byte *)(_DAT_0304b084 + 0x32) = *(byte *)(_DAT_0304b084 + 0x32) & 0xf7 | 8;
  }
  if ((abStack_10[0] & 2) == 0) {
    *(byte *)(_DAT_0304b084 + 0x32) = *(byte *)(_DAT_0304b084 + 0x32) & 0xef;
  }
  else {
    *(byte *)(_DAT_0304b084 + 0x32) = *(byte *)(_DAT_0304b084 + 0x32) & 0xef | 0x10;
  }
  write_two_bit_flags_0301eef8
            (*(byte *)(_DAT_0304b084 + 0x32) >> 4 & 1,*(byte *)(_DAT_0304b084 + 0x32) >> 3 & 1);
  return;
}

