/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypress_counter_persist_and_dialog_tick @ 03014f34 (file base 0x03000000; code starts at 0x03001000)
 * Size: 250 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void keypress_counter_persist_and_dialog_tick(void)

{
  int iVar1;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  if ((*(byte *)PTR_DAT_03015038 & 6) == 6) {
    if (*(char *)PTR_DAT_03015040 == '\x1a') {
      if (*(ushort *)PTR_DAT_03015044 < 0x3ff) {
        *(ushort *)PTR_DAT_03015044 = *(ushort *)PTR_DAT_03015044 + 1;
      }
      else {
        *(undefined2 *)PTR_DAT_03015044 = 0;
      }
      uStack_8 = (undefined1)*(undefined2 *)PTR_DAT_03015044;
      uStack_7 = (undefined1)((ushort)*(undefined2 *)PTR_DAT_03015044 >> 8);
      flash_block_write(2,*(undefined2 *)PTR_DAT_03015048,&uStack_8,2);
    }
    else {
      if ((byte)(*(char *)PTR_DAT_03015040 - 0x21U) < 0xc) {
        if ((*(ushort *)PTR_DAT_03015044 & 0x3f) < 0x3f) {
          *(ushort *)PTR_DAT_03015044 = (*(ushort *)PTR_DAT_03015044 & 0x3f) + 1;
        }
        else {
          *(undefined2 *)PTR_DAT_03015044 = 0;
        }
        uStack_8 = (undefined1)*(undefined2 *)PTR_DAT_03015044;
      }
      else {
        if (*(ushort *)PTR_DAT_03015044 < 0xff) {
          *(ushort *)PTR_DAT_03015044 = *(ushort *)PTR_DAT_03015044 + 1;
        }
        uStack_8 = (undefined1)*(undefined2 *)PTR_DAT_03015044;
      }
      flash_block_write(2,*(undefined2 *)PTR_DAT_03015048,&uStack_8,1);
    }
    byte_code_range_dispatch_to_fnptr_table();
  }
  else if ((((*(byte *)PTR_call_active_flag_0301504c & 8) == 0) &&
           ((((*(byte *)PTR_call_active_flag_0301504c & 2) == 0 || ((*PTR_DAT_0301503c & 1) != 0))
            && (iVar1 = ui_dialog_tick_scheduler(0), iVar1 != 0)))) &&
          ((*(byte *)PTR_DAT_03015038 & 0x10) != 0)) {
    *(byte *)PTR_DAT_03015038 = *(byte *)PTR_DAT_03015038 & 0x7f | 0x80;
    request_display_refresh(4);
  }
  return;
}

