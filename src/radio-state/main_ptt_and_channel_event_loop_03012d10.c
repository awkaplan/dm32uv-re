/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: main_ptt_and_channel_event_loop @ 03012d10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 260 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void main_ptt_and_channel_event_loop(void)

{
  void *flaggrp;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  void *pvVar8;
  undefined1 auStack_28 [4];
  
  iVar7 = DAT_03012e74;
  puVar6 = PTR_DAT_03012e70;
  iVar5 = DAT_03012e6c;
  puVar4 = PTR_DAT_03012e68;
  iVar3 = DAT_03012e64;
  iVar2 = DAT_03012e60;
  puVar1 = PTR_DAT_03012e5c;
  flaggrp = DAT_03012e58;
  do {
    do {
      while( true ) {
        pvVar8 = flaggrp;
        OSFlagPend_wrapper_consume(flaggrp,0x18,0,0,auStack_28);
        *puVar1 = pvVar8;
        if (((uint)pvVar8 & 8) == 0) break;
        OSFlagPost_wrapper_clr(flaggrp,8);
        if ((*(byte *)(iVar2 + 0x16) & 1) != 0) {
          dialog_show_number_or_alt();
          *(byte *)(iVar2 + 0x16) = *(byte *)(iVar2 + 0x16) & 0xfe;
          *(byte *)(iVar3 + 1) = *(byte *)(iVar3 + 1) & 0xf7;
          *(byte *)(iVar3 + 0x2d) = *(byte *)(iVar3 + 0x2d) & 0xf3;
          *(byte *)PTR_DAT_03012e78 = *(byte *)PTR_DAT_03012e78 & 0x7f;
        }
        ptt_press_handler();
      }
    } while ((((uint)pvVar8 & 0x10) == 0) ||
            (OSFlagPost_wrapper_clr(flaggrp,0x10), (*puVar4 & 2) != 0));
    if ((*(byte *)(iVar5 + 8) & 0xf0) == 0x10) {
      call_teardown_and_history_dispatch();
    }
    else {
      if (((*(byte *)PTR_call_active_flag_03012e7c & 8) != 0) &&
         (channel_switch_teardown_and_apply(0), (PTR_DAT_03012e80[6] & 2) != 0)) {
        PTR_DAT_03012e80[6] = PTR_DAT_03012e80[6] & 0xfd;
        ui_event_notify(0x1b);
      }
      call_teardown_and_history_dispatch();
    }
    *(undefined1 *)puVar6 = 0;
    *(byte *)(iVar7 + 1) = *(byte *)(iVar7 + 1) & 0xfc;
  } while( true );
}

