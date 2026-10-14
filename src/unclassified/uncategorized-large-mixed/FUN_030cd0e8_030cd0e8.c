/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030cd0e8 @ 030cd0e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 326 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x030cd300) */

undefined4
FUN_030cd0e8(undefined2 *param_1,short *param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6,short param_7,short param_8,short param_9,short param_10)

{
  short sVar1;
  short *psVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  ushort *puVar7;
  
  iVar4 = (int)param_8;
  if (param_9 < iVar4) {
    iVar5 = param_9 * 2;
    psVar6 = (short *)(param_5 + iVar5);
    puVar7 = (ushort *)(param_6 + iVar5);
    iVar5 = 0;
    psVar2 = psVar6;
    sVar3 = param_9;
    do {
      while( true ) {
        sVar1 = *psVar2;
        sVar3 = sVar3 + 1;
        psVar2 = psVar2 + 1;
        if (sVar1 != param_10) break;
        if (iVar5 < (int)((uint)*puVar7 << 0x10)) {
          iVar5 = (uint)*puVar7 << 0x10;
        }
        puVar7 = puVar7 + 1;
        if (iVar4 <= sVar3) goto LAB_030cd156;
      }
      puVar7 = puVar7 + 1;
    } while (sVar3 < iVar4);
LAB_030cd156:
    if (iVar5 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    u16_buffer_fill_memset(param_1,0,0x100);
    sVar3 = *psVar6;
    while( true ) {
      if (sVar3 == param_10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      param_9 = param_9 + 1;
      psVar6 = psVar6 + 1;
      if (iVar4 <= param_9) break;
      sVar3 = *psVar6;
    }
    *param_2 = param_7 + 0x17;
  }
  else {
    u16_buffer_fill_memset(param_1,0,0x100);
  }
  *param_2 = -0x20;
  param_1[0x100] = *param_1;
  return 0;
}

