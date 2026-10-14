/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_queue_drain_and_stop @ 0302357c (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void modem_queue_drain_and_stop(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  do {
    iVar4 = ucos_sem_00037820_pend();
  } while (iVar4 == 0);
  do {
    iVar4 = ucos_mutex_0003644c_pend();
  } while (iVar4 == 0);
  do {
    iVar4 = ucos_mutex_00035f50_pend();
    puVar2 = PTR_DAT_03023770;
  } while (iVar4 == 0);
  SystemControl_Type_11000000.SYS_SOFT_RSTN = 0x1fc;
  iVar4 = PTR_DAT_03023770[0x29];
  puVar1 = PTR_DAT_03023770;
  while (PTR_DAT_03023770 = puVar1, iVar4 != 0) {
    puVar2[0x29] = *(undefined4 *)(iVar4 + 0x20);
    clear_byte_at_ptr();
    puVar1 = PTR_DAT_03023770;
    iVar4 = puVar2[0x29];
  }
  puVar1[0x2b] = 0;
  iVar4 = puVar1[0x2a];
  while (iVar4 != 0) {
    puVar1[0x2a] = *(undefined4 *)(iVar4 + 0x20);
    clear_byte_at_ptr();
    iVar4 = puVar1[0x2a];
  }
  PTR_DAT_03023770[0x2c] = 0;
  puVar3 = PTR_DAT_03023774;
  PTR_DAT_03023774[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  puVar3[0xf] = 0;
  puVar3[0x10] = 0;
  puVar3[0x11] = 0;
  puVar3[0x12] = 0;
  puVar3[0x13] = 0;
  puVar3[9] = 0;
  PTR_DAT_03023778[2] = 0;
  modem_stop();
  return;
}

