/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gb2312_glyph_flash_offset_read @ 03010ec4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 126 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
gb2312_glyph_flash_offset_read(byte *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *PTR_DAT_03010fc4;
  uVar1 = (uint)param_1[1];
  uVar2 = (uint)*param_1;
  if (uVar2 == 0xa9) {
    if (0xa0 < uVar1) {
      param_4 = (uVar1 + 0x79) * 0x20 + iVar3;
    }
  }
  else if (((uVar2 + 0x5f & 0xff) < 3) && (0xa0 < uVar1)) {
    param_4 = (uVar2 * 0x5e + uVar1 + -0x3bbf) * 0x20 + iVar3;
  }
  else if (((uVar2 + 0x50 & 0xff) < 0x48) && (0xa0 < uVar1)) {
    param_4 = (uVar1 + uVar2 * 0x5e + -0x3df3) * 0x20 + iVar3;
  }
  flash_read_mutex_guarded(param_4,param_1,0x20);
  return 0;
}

