/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_key_and_menu_event_dispatch_loop @ 030152cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 294 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_key_and_menu_event_dispatch_loop(void)

{
  char cVar1;
  void *flaggrp;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_28 [4];
  
  iVar5 = DAT_030153c0;
  iVar4 = DAT_030153bc;
  iVar3 = DAT_030153b8;
  iVar2 = DAT_030153b4;
  flaggrp = DAT_030153b0;
  do {
    OSFlagPend_wrapper_consume(flaggrp,2,0,0,auStack_28);
    OSFlagPost_wrapper_clr(flaggrp,2);
    if ((*(byte *)(iVar2 + 4) & 1) != 0) {
      *(byte *)(iVar2 + 4) = *(byte *)(iVar2 + 4) & 0xfe;
    }
    if ((*(byte *)(iVar2 + 4) & 2) != 0) {
      key_event_state_clear_preserve_bit0();
      settings_set_menu_hold_interval(*(undefined1 *)(iVar3 + 0x3a));
      ui_event_notify_alt(1);
      *(byte *)(iVar2 + 4) = *(byte *)(iVar2 + 4) & 0xfd;
    }
    if ((*(byte *)(iVar2 + 4) & 4) != 0) {
      *(byte *)(iVar2 + 4) = *(byte *)(iVar2 + 4) & 0xfb;
      call_setup_mode_flag_dispatch();
    }
    if ((*(byte *)(iVar2 + 4) & 8) != 0) {
      *(byte *)(iVar2 + 4) = *(byte *)(iVar2 + 4) & 0xf7;
      vfo_freq_display_refresh();
    }
    if ((*(byte *)(iVar2 + 4) & 0x10) != 0) {
      *(byte *)(iVar2 + 4) = *(byte *)(iVar2 + 4) & 0xef;
      if ((byte)(*(char *)(iVar4 + 0x29) - 0x15U) < 2) {
        cVar1 = *(char *)(iVar5 + 1);
        if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x02')) {
          if (*(undefined **)(iVar4 + 0x2c) !=
              PTR_scan_group14_resume_or_stop_status_update_030153c4) {
            tx_gate_write_call_record(0);
            dialog_history_menu_step_and_refresh();
            goto LAB_03015416;
          }
        }
        (*(code *)(*(uint *)(iVar4 + 0x2c) & 0xfffffffe))();
      }
      else if ((byte)(*(char *)(iVar4 + 0x29) - 0x1dU) < 3) {
        cVar1 = *(char *)(iVar5 + 1);
        if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x02')) {
          if (*(undefined **)(iVar4 + 0x2c) !=
              PTR_scan_group14_resume_or_stop_status_update_03015560) {
            if ((*(byte *)(iVar3 + 0x30) & 8) == 0) {
              (*(code *)((uint)*(undefined **)(iVar4 + 0x2c) & 0xfffffffe))();
            }
            else {
              tx_gate_write_call_record(0);
              dialog_history_menu_step_and_refresh();
            }
            goto LAB_03015416;
          }
        }
        (*(code *)(*(uint *)(iVar4 + 0x2c) & 0xfffffffe))();
      }
      else {
        (*(code *)(*(uint *)(iVar4 + 0x2c) & 0xfffffffe))();
      }
    }
LAB_03015416:
    if ((*(byte *)(iVar2 + 4) & 0x20) != 0) {
      *(byte *)(iVar2 + 4) = *(byte *)(iVar2 + 4) & 0xdf;
    }
  } while( true );
}

