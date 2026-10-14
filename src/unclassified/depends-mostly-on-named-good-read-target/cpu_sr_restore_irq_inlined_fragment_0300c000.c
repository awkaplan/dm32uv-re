/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: cpu_sr_restore_irq_inlined_fragment @ 0300c000 (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void cpu_sr_restore_irq_inlined_fragment(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar5 = puRam0300c0bc;
  uVar4 = UNK_0300c0b0;
  control_register_write(UNK_0300c0b0,param_1);
  control_register_write(uRam0300c0b8,UNK_0300c0b0);
  puRam0300c0bc[1] = 1;
  *puVar5 = 4;
  puVar5[2] = uRam0300c0c0;
  *puVar5 = *puVar5 | 1;
  puVar6 = puRam0300c0c8;
  puVar7 = puRam0300c0cc;
  puVar1 = puRam0300c0d4;
  for (puVar8 = puRam0300c0c4; puRam0300c0d4 = puVar1, puVar2 = puRam0300c0d8,
      puVar3 = puRam0300c0d0, puVar8 < puVar6; puVar8 = puVar8 + 1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar1 = puRam0300c0d4;
  }
  for (; puVar3 < puVar1; puVar3 = puVar3 + 1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
  }
  if ((uint)(iRam0300c0e0 - (int)puRam0300c0dc) >> 2 != 0) {
    *puRam0300c0dc = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x0002e158(param_1,uVar4);
  stub();
  stub();
  return;
}

