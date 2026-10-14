/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_lookup_channel_icon_and_bank @ 03054f44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 564 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_lookup_channel_icon_and_bank(byte *param_1)

{
  char cVar1;
  vfo_display_state *pvVar2;
  vfo_display_state *pvVar3;
  byte bVar4;
  
  pvVar3 = p_vfo_display_state;
  pvVar2 = p_vfo_display_state;
  cVar1 = *(char *)PTR_DAT_03054fc4;
  if (cVar1 == '\0') {
    if ((p_radio_mode_state_0003e318->flags_0x3 & 8) == 0) {
      *(ushort *)PTR_DAT_03054fb4 = *(byte *)PTR_DAT_03054fbc + 0xd0;
    }
    else {
      *(ushort *)PTR_DAT_03054fb4 = *(byte *)PTR_DAT_03054fbc + 0x40;
    }
    cVar1 = *(char *)PTR_DAT_03054fbc;
    if (cVar1 == '\0') {
      bVar4 = 0;
    }
    else if (cVar1 == '\n') {
      bVar4 = 0;
    }
    else if (cVar1 == '\x05') {
      bVar4 = 0;
    }
    else if (cVar1 == '\x01') {
      bVar4 = 1;
    }
    else if (cVar1 == '\v') {
      bVar4 = 1;
    }
    else if (cVar1 == '\x06') {
      bVar4 = 1;
    }
    else if (cVar1 == '\x02') {
      bVar4 = 2;
    }
    else if (cVar1 == '\f') {
      bVar4 = 2;
    }
    else if (cVar1 == '\a') {
      bVar4 = 2;
    }
    else if (cVar1 == '\x03') {
      bVar4 = 3;
    }
    else if (cVar1 == '\r') {
      bVar4 = 3;
    }
    else if (cVar1 == '\b') {
      bVar4 = 3;
    }
    else {
      bVar4 = 4;
    }
  }
  else {
    bVar4 = *(byte *)PTR_DAT_0305513c;
    if (bVar4 == 0xf) {
      *(undefined2 *)PTR_DAT_03055140 = 0x16;
      bVar4 = 2;
    }
    else if (bVar4 == 0x30) {
      *(undefined2 *)PTR_DAT_03055140 = 0x16;
      bVar4 = 2;
    }
    else if (bVar4 == 0x4c) {
      *(undefined2 *)PTR_DAT_03055140 = 0x16;
      bVar4 = 0;
    }
    else if (bVar4 == 0x4d) {
      *(undefined2 *)PTR_DAT_03055140 = 0x16;
      bVar4 = 2;
    }
    else if (bVar4 == 0x4e) {
      *(undefined2 *)PTR_DAT_03055140 = 0x16;
      bVar4 = 4;
    }
    else if (cVar1 == '\x02') {
      bVar4 = bVar4 - 0x10;
      if ((p_radio_mode_state_0003e318->flags_0x3 & 8) == 0) {
        *(ushort *)PTR_DAT_03055140 = bVar4 + 0xa6;
      }
      else {
        *(ushort *)PTR_DAT_03055140 = bVar4 + 0x17;
      }
    }
    else if (bVar4 == 0x1a) {
      *(undefined2 *)PTR_DAT_03055140 = 0x27;
      bVar4 = 2;
    }
    else if ((byte)(bVar4 - 0x1b) < 6) {
      if ((p_radio_mode_state_0003e318->flags_0x3 & 8) == 0) {
        *(ushort *)PTR_DAT_03055140 = bVar4 + 0x90;
      }
      else {
        *(ushort *)PTR_DAT_03055140 = bVar4 - 2;
      }
      pvVar2 = p_vfo_display_state;
      if (bVar4 == 0x1e) {
        bVar4 = 0;
      }
      else if (bVar4 == 0x1b) {
        bVar4 = 0;
      }
      else if (bVar4 == 0x1f) {
        bVar4 = 2;
      }
      else if (bVar4 == 0x1c) {
        bVar4 = 2;
      }
      else {
        bVar4 = 4;
      }
      p_vfo_display_state->field_0x13_0 = 0xff;
      pvVar2->field_0x14 = 0xff;
    }
    else if (cVar1 == '\x06') {
      p_vfo_display_state->field_0x13_0 = 0x30;
      pvVar2->field_0x14 = 0x12;
      *(undefined2 *)PTR_DAT_03055140 = 0x201;
      bVar4 = 2;
    }
    else if (cVar1 == '\a') {
      p_vfo_display_state->field_0x13_0 = 0x23;
      pvVar2->field_0x14 = 0x80;
      *(undefined2 *)PTR_DAT_03055140 = 0x202;
      bVar4 = 2;
    }
    else if (cVar1 == '\t') {
      p_vfo_display_state->field_0x11_0 = 0xff;
      pvVar2->field_0x12 = 0xff;
      bVar4 = bVar4 - 0x35;
      *(ushort *)PTR_DAT_03055140 = bVar4 + 100;
    }
    else if (cVar1 == '\n') {
      p_vfo_display_state->field_0x11_0 = 0xff;
      pvVar2->field_0x12 = 0xff;
      bVar4 = bVar4 - 0x3a;
      *(ushort *)PTR_DAT_03055140 = bVar4 + 0x69;
    }
    else if (cVar1 == '\v') {
      p_vfo_display_state->field_0x11_0 = 0xff;
      pvVar2->field_0x12 = 0xff;
      bVar4 = bVar4 - 0x3f;
      *(ushort *)PTR_DAT_03055140 = bVar4 + 0xe0;
    }
    else if (cVar1 == '\f') {
      p_vfo_display_state->field_0x11_0 = 0xff;
      pvVar3->field_0x12 = 0xff;
      bVar4 = bVar4 + 0xbc;
      *_DAT_030551ac = bVar4 + 0xe5;
    }
    else if (cVar1 == '\x13') {
      bVar4 = 2;
    }
    else {
      bVar4 = 0;
    }
  }
  *param_1 = bVar4;
  return;
}

