/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_state_main_task_loop @ 03060754 (file base 0x03000000; code starts at 0x03001000)
 * Size: 252 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_state_main_task_loop(void)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  radio_mode_state_0003e318 *prVar4;
  void *flaggrp;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  byte bVar9;
  undefined1 auStack_28 [4];
  
  iVar8 = DAT_0306087c;
  puVar7 = PTR_call_active_flag_03060878;
  iVar6 = DAT_03060874;
  iVar5 = DAT_03060870;
  flaggrp = DAT_0306086c;
  prVar4 = p_radio_mode_state_0003e318;
  puVar3 = PTR_DAT_03060858;
  puVar2 = PTR_DAT_03060850;
  do {
    do {
      do {
        do {
          OSFlagPend_wrapper_consume(flaggrp,0x100,0,0,auStack_28);
          OSFlagPost_wrapper_clr(flaggrp,0x100);
          SUBPIECE_SET(uVar1, 0, 1, prVar4->flags_0x2);
          SUBPIECE_SET(uVar1, 1, 1, prVar4->flags_0x3);
        } while ((uVar1 & 0x4010) != 0x10);
      } while (((((*(char *)(iVar5 + 1) == '\x02') || ((*(byte *)(iVar6 + 1) & 2) != 0)) ||
                (*(char *)(iVar5 + 1) == '\x04')) ||
               (((*puVar7 & 10) != 0 || ((prVar4->flags_0x7 & 2) != 0)))) ||
              (((prVar4->flags_0x4 & 8) != 0 ||
               (((*puVar7 & 0x40) != 0 || ((*(byte *)(iVar8 + 0x2b) & 8) != 0))))));
      bVar9 = *(byte *)((int)puVar2 + 3);
    } while (((bVar9 & 2) != 0) && ((bVar9 & 10) != 10));
    bVar9 = vfo_display_debounce_and_hw_flag_clear();
    puVar3[0x1d] = puVar3[0x1d] & 0xfb | (bVar9 & 1) << 2;
    bVar9 = *(byte *)puVar2;
    if ((bVar9 & 0x42) == 0x40) {
      puVar3[0x1d] = puVar3[0x1d] & 0xfb;
    }
    if ((bVar9 & 0x20) != 0) {
      if ((puVar3[0x1d] & 4) == 0) {
        PTR_DAT_03060880[0x21] = 0;
      }
    }
    tx_state_transition_and_supervisory_tick();
  } while( true );
}

