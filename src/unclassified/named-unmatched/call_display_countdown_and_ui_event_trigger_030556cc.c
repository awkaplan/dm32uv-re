/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_display_countdown_and_ui_event_trigger @ 030556cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 258 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_display_countdown_and_ui_event_trigger(void)

{
  char cVar1;
  byte bVar2;
  undefined1 *puVar3;
  ushort uVar4;
  
  puVar3 = PTR_DAT_030557d4;
  if (((PTR_DAT_030557d4[6] & 1) != 0) || ((*(byte *)p_dialog_flags_from_flash & 1) != 0)) {
    if (PTR_DAT_030557d4[7] != '\0') {
      *PTR_DAT_030557d4 = 0;
      puVar3[7] = 0;
      *(undefined2 *)(puVar3 + 2) = 0;
      if ((*(byte *)p_dialog_flags_from_flash & 1) == 0) {
        if (PTR_DAT_030557d8[0x35] == 0) {
          PTR_DAT_030557d4[6] = PTR_DAT_030557d4[6] & 0xfe;
          return;
        }
        *(ushort *)(PTR_DAT_030557d4 + 4) = (ushort)(byte)PTR_DAT_030557d8[0x35] * 0xf;
      }
      else {
        bVar2 = p_dialog_flags_from_flash->field_0x2c;
        *(ushort *)(PTR_DAT_030557d4 + 4) = (ushort)bVar2;
        if ((((byte)PTR_DAT_030557d8[0x35] - 1 & 0xff) < 0x16) &&
           (uVar4 = ((byte)PTR_DAT_030557d8[0x35] - 1) * 5 + 0xf, uVar4 < bVar2)) {
          *(ushort *)(PTR_DAT_030557d4 + 4) = uVar4;
        }
      }
    }
    cVar1 = *PTR_DAT_030557d4;
    *PTR_DAT_030557d4 = cVar1 + 1U;
    puVar3 = PTR_DAT_030557d4;
    if (99 < (byte)(cVar1 + 1U)) {
      *PTR_DAT_030557d4 = 0;
      uVar4 = *(short *)(puVar3 + 2) + 1;
      *(ushort *)(puVar3 + 2) = uVar4;
      if ((uint)uVar4 < (uint)*(ushort *)(puVar3 + 4)) {
        if ((uint)uVar4 == (uint)*(ushort *)(puVar3 + 4) - (uint)(byte)PTR_DAT_030557d8[0x37]) {
          ui_event_notify(0x15);
        }
      }
      else {
        if ((*(byte *)p_dialog_flags_from_flash & 1) == 0) {
          PTR_DAT_030557d4[6] = PTR_DAT_030557d4[6] & 0xfd | 2;
        }
        if ((*(char *)PTR_DAT_030557dc != '\0') && ((PTR_DAT_030557e0[8] & 0xf0) == 0)) {
          write_field_and_mbox_post(1,100);
        }
        OSFlagPost_wrapper_set(_DAT_030557e4,0x10);
      }
    }
  }
  return;
}

