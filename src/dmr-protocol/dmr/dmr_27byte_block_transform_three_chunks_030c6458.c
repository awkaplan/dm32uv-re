/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_27byte_block_transform_three_chunks @ 030c6458 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_27byte_block_transform_three_chunks(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 auStack_c8 [144];
  undefined1 auStack_38 [28];
  
  func_0x030dec8c(auStack_38,param_1,0x1b);
  iVar1 = _DAT_030c65e4;
  iVar2 = 0;
  do {
    puVar3 = auStack_38 + iVar2 * 9;
    func_0x030de010(auStack_c8,puVar3,0x31);
    channel_list_string_render_field
              (auStack_c8,auStack_c8,(int)*(short *)(iVar1 + 0x1738),_DAT_030c65e8);
    func_0x030de0b4(puVar3,auStack_c8,0x48);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 3);
  func_0x030dec8c(param_1,auStack_38,0x1b);
  return;
}

