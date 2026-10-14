/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c0754 @ 030c0754 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c0754(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    if (*(char *)(param_2 + 0x34) == '\x02') {
      *(undefined **)(param_2 + 0xc4) = PTR_s_Task_Q_030c08b4;
    }
    else {
      puVar1 = PTR_LAB_030c08b0;
      if (*(char *)(param_2 + 0x34) == '\a') {
        puVar1 = PTR_s_Task_Sem_030c08ac;
      }
      *(undefined **)(param_2 + 0xc4) = puVar1;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 8) + 0x20);
  }
  return;
}

