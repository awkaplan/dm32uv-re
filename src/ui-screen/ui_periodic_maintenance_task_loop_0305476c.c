/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_periodic_maintenance_task_loop @ 0305476c (file base 0x03000000; code starts at 0x03001000)
 * Size: 462 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_periodic_maintenance_task_loop(void)

{
  void *flaggrp;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 auStack_28 [4];
  
  puVar7 = PTR_DAT_03054958;
  iVar6 = DAT_03054954;
  iVar5 = DAT_03054950;
  puVar4 = PTR_DAT_0305494c;
  iVar3 = DAT_03054948;
  iVar2 = DAT_03054944;
  puVar1 = PTR_DAT_03054940;
  flaggrp = DAT_0305493c;
  do {
    do {
      while( true ) {
        OSFlagPend_wrapper_consume(flaggrp,0x20000,0,0,auStack_28);
        OSFlagPost_wrapper_clr(flaggrp,0x20000);
        if (puVar1[1] != '\0') {
          puVar1[1] = puVar1[1] + -1;
        }
        call_hold_led_debounce_dual_timer_tick();
        if ((((*(byte *)(iVar2 + 0x16) & 1) != 0) && ((*puVar1 & 0x80) == 0)) &&
           ((*(byte *)(iVar3 + 1) & 8) == 0)) {
          if ((byte)puVar1[5] < 6) {
            puVar1[5] = puVar1[5] + 1;
          }
          else if ((*(byte *)(iVar2 + 0x16) & 0x40) == 0) {
            dialog_show_and_clear_bits();
          }
        }
        if ((*puVar4 & 2) == 0) break;
        if (*(char *)PTR_DAT_0305495c == '\x12') {
          channel_change_tx_led_reset();
        }
      }
      call_setup_timeout_countdown();
    } while (((*puVar4 & 0x40) != 0) || ((*(byte *)(iVar5 + 0x2b) & 8) != 0));
    if ((((*(char *)(iVar6 + 0x12) == '\0') &&
         (((puVar4[1] & 2) == 0 && ((*(byte *)(iVar2 + 4) & 4) == 0)))) &&
        ((*puVar7 == '\0' || (0x3f < (byte)*puVar7)))) &&
       ((iVar8 = get_current_mode_state2(), iVar8 == 0 ||
        (iVar8 = get_current_mode_state2(), iVar8 == 1)))) {
      if ((*(byte *)PTR_DAT_03054960 & 4) != 0) {
        if (((*(byte *)PTR_DAT_03054964 & 1) != 0) &&
           (((*(byte *)PTR_DAT_03054968 & 0x40) != 0 || ((*(byte *)PTR_DAT_03054964 & 4) != 0)))) {
          gps_display_periodic_refresh_tick();
        }
      }
      if ((((*(byte *)PTR_DAT_0305496c & 1) != 0) || (*(char *)PTR_DAT_03054970 != '\0')) &&
         (*(char *)((int)PTR_DAT_0305496c + 5) != '\0')) {
        channel_scan_dwell_timer_tick();
      }
    }
    iVar8 = keypad_dispatch_not_inhibited();
    if (((iVar8 != 0) && ((PTR_DAT_03054974[8] & 1) == 0)) && ((*(byte *)(iVar2 + 0x10) & 8) == 0))
    {
      if (((byte)PTR_DAT_03054978[1] < 2) && ((*(byte *)PTR_call_active_flag_0305497c & 10) == 0)) {
        tick_counter_and_event_log();
      }
      status_field_multi_step_state_machine();
      display_update_datetime(0);
    }
    iVar8 = keypad_dispatch_not_inhibited();
    if (iVar8 != 0) {
      call_timeout_and_tx_state_tick();
      menu_exit_timer_tick();
    }
    if (((*puVar7 == '\0') && (iVar8 = keypad_dispatch_not_inhibited(), iVar8 != 0)) &&
       ((puVar4[3] & 2) == 0)) {
      countdown_timer_tick_standby_trigger();
    }
  } while( true );
}

