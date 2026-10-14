/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: analog_digital_channel_tracking_sync @ 03061cfc (file base 0x03000000; code starts at 0x03001000)
 * Size: 364 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void analog_digital_channel_tracking_sync(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  if ((byte)PTR_DAT_03061e54[6] < 10) {
    PTR_DAT_03061e54[6] = PTR_DAT_03061e54[6] + 1;
    return;
  }
  if ((*(byte *)PTR_call_active_flag_03061e58 & 8) == 0) {
    if ((*(byte *)PTR_call_active_flag_03061e58 & 2) == 0) goto LAB_03061d44;
    bVar1 = *(byte *)((int)PTR_DAT_03061e5c + 1);
  }
  else {
    bVar1 = *(byte *)((int)PTR_DAT_03061e5c + 1);
  }
  if ((bVar1 & 2) == 0) {
    return;
  }
LAB_03061d44:
  iVar4 = keypad_dispatch_not_inhibited();
  if ((((iVar4 != 0) && ((*(byte *)PTR_DAT_03061e60 & 4) == 0)) &&
      ((PTR_DAT_03061e64[0x30] & 1) != 0)) && ((*(byte *)((int)PTR_DAT_03061e68 + 1) & 2) == 0)) {
    uVar2 = PTR_LAB_03061e6c[(byte)PTR_DAT_03061e64[0x5e]];
    uVar5 = adc_read_channel_dispatch(1);
    puVar3 = PTR_DAT_03061e5c;
    if (uVar2 < uVar5) {
      if ((*(byte *)((int)PTR_DAT_03061e5c + 1) & 1) == 0) {
        *(byte *)((int)PTR_DAT_03061e5c + 1) = *(byte *)((int)PTR_DAT_03061e5c + 1) & 0xfe | 1;
      }
      else {
        event_queue_reset();
        if ((((*(byte *)PTR_call_active_flag_03061e58 & 10) == 0) &&
            ((*(byte *)((int)PTR_DAT_03061e5c + 1) & 2) == 0)) &&
           (iVar4 = ui_dialog_tick_scheduler(1), iVar4 != 0)) {
          *(byte *)((int)PTR_DAT_03061e5c + 1) = *(byte *)((int)PTR_DAT_03061e5c + 1) & 0xfd | 2;
          request_display_refresh(4);
        }
        *(undefined1 *)PTR_DAT_03061e5c = 0;
      }
    }
    else if (uVar5 < uVar2) {
      *(byte *)((int)PTR_DAT_03061e5c + 1) = *(byte *)((int)PTR_DAT_03061e5c + 1) & 0xfe;
      if (*(byte *)puVar3 < (byte)PTR_DAT_03061e64[0x5f]) {
        *(byte *)PTR_DAT_03061e5c = *(byte *)puVar3 + 1;
      }
      else if (((*(byte *)((int)PTR_DAT_03061e5c + 1) & 2) != 0) &&
              ((*(byte *)PTR_DAT_03061e68 & 0x80) == 0)) {
        if (((PTR_DAT_03061e70[1] & 3) == 1) && ((PTR_DAT_03061e70[0x20] & 0x10) != 0)) {
          *(byte *)PTR_DAT_03061e68 = *(byte *)PTR_DAT_03061e68 & 0x7f;
        }
        else {
          PTR_DAT_03061e88[1] = PTR_DAT_03061e88[1] & 0xfd;
          request_display_refresh(8);
        }
      }
    }
  }
  return;
}

