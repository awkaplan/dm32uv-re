/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_background_periodic_subtask_dispatcher @ 030131e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 482 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_background_periodic_subtask_dispatcher(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (((*(byte *)(PTR_DAT_030133c8 + 1) & 0x10) != 0) &&
     (cVar1 = PTR_DAT_030133cc[0x405], PTR_DAT_030133cc[0x405] = cVar1 + 1U,
     puVar2 = PTR_DAT_030133cc, 0x1d < (byte)(cVar1 + 1U))) {
    PTR_DAT_030133cc[0x405] = 0;
    puVar2[0x406] = puVar2[0x406] ^ 1;
    display_toggle_box_or_bitmap_by_flag();
  }
  if (((*(byte *)(PTR_DAT_030133c8 + 1) & 0x80) != 0) &&
     (cVar1 = *(char *)PTR_DAT_030133d0, *(byte *)PTR_DAT_030133d0 = cVar1 + 1U,
     0x31 < (byte)(cVar1 + 1U))) {
    *(byte *)(PTR_DAT_030133c8 + 1) = *(byte *)(PTR_DAT_030133c8 + 1) & 0x7f;
    *(undefined1 *)PTR_DAT_030133d0 = 0;
    if ((PTR_DAT_030133d4[0x43] & 0x20) != 0) {
      write_event_record_and_notify(0x27,PTR_DAT_030133d4[0x26]);
    }
  }
  call_teardown_tx_release_sequence();
  if ((((*(char *)((int)PTR_DAT_030133d8 + 3) != '\0') && ((*(byte *)PTR_DAT_030133d8 & 0x10) == 0))
      && ((*(byte *)PTR_call_active_flag_030133dc & 8) == 0)) &&
     ((PTR_DAT_030133e0[0x16] & 0x20) == 0)) {
    if (*(char *)((int)PTR_DAT_030133d8 + 3) == '\x01') {
      local_beep_tone_burst();
    }
    else {
      local_beep_frontend_init_and_burst();
    }
    puVar3 = PTR_DAT_030133d8;
    *(undefined1 *)((int)PTR_DAT_030133d8 + 3) = 0;
    if (*(char *)((int)puVar3 + 2) != '\0') {
      flash_quad_enable_and_system_reset();
    }
  }
  cVar1 = PTR_DAT_030133e4[1];
  PTR_DAT_030133e4[1] = cVar1 + 1U;
  if (9 < (byte)(cVar1 + 1U)) {
    PTR_DAT_030133e4[1] = 0;
    ui_background_flag_post_0x4000();
    ui_flag_post_0x40000_if_check();
    if ((PTR_DAT_030133e8[2] & 2) != 0) {
      if ((byte)PTR_DAT_030133e4[0x1b] < 5) {
        PTR_DAT_030133e4[0x1b] = PTR_DAT_030133e4[0x1b] + 1;
      }
      else {
        PTR_DAT_030133e4[0x1b] = 0;
        PTR_DAT_030133e8[2] = PTR_DAT_030133e8[2] & 0xfd;
        memset_bytes(_DAT_030133ec,0,10);
        write_field_and_mbox_post(1,100);
      }
    }
    if ((((*(byte *)PTR_call_active_flag_030133dc & 10) == 0) &&
        ((*(byte *)((int)PTR_DAT_030133c8 + 1) & 2) == 0)) &&
       (((byte)PTR_DAT_030133f0[1] < 2 &&
        (((PTR_DAT_030133f4[8] & 1) == 0 && ((*(byte *)PTR_DAT_030133c8 & 2) == 0)))))) {
      battery_monitor_adc_tick();
    }
    if ((((*(byte *)PTR_DAT_030133c8 & 0x42) == 0) &&
        (iVar4 = keypad_dispatch_not_inhibited(), iVar4 != 0)) && ((PTR_DAT_030133f4[8] & 1) == 0))
    {
      analog_digital_channel_tracking_sync();
    }
    if ((((PTR_DAT_030133f8[0x2b] & 8) == 0) && ((PTR_DAT_030133fc[3] & 1) == 0)) &&
       ((PTR_DAT_030133e0[0x10] & 8) == 0)) {
      if (((*(byte *)((int)PTR_DAT_030133c8 + 3) & 2) == 0) ||
         ((*(byte *)((int)PTR_DAT_030133c8 + 3) & 10) == 10)) {
        rssi_rolling_average_meter_update();
      }
    }
  }
  return;
}

