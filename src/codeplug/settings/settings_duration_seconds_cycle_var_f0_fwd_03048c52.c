/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_duration_seconds_cycle_var_f0_fwd @ 03048c52 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_duration_seconds_cycle_var_f0_fwd(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  ushort uVar5;
  
  puVar1 = p_active_screen_state_word;
  iVar2 = cyclic_value_step(*(undefined1 *)p_active_screen_state_word,0xf0,0,0);
  *(char *)puVar1 = (char)iVar2;
  settings_duration_seconds_display(iVar2 * 0x1e);
  if (1 < (byte)(*(char *)PTR_DAT_03048ee0 - 1U)) {
    return;
  }
  bVar4 = *(char *)PTR_DAT_03048ee4 + 1;
  uVar5 = (ushort)bVar4;
  *(byte *)PTR_DAT_03048ee4 = bVar4;
  if (bVar4 < 6) {
    if (5 < bVar4) {
      return;
    }
    uVar3 = 1 << ((int)(char)bVar4 & 0x3fU);
    if ((uVar3 & 0x30) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0x18 + (ushort)bVar4 * 0xc
      ;
      return;
    }
    if ((uVar3 & 0xc) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0xc + (ushort)bVar4 * 0xc;
      return;
    }
    if ((uVar3 & 3) == 0) {
      return;
    }
  }
  else {
    *(undefined1 *)PTR_DAT_03048ee4 = 0;
    uVar5 = 0;
  }
  *(ushort *)p_text_entry_current_char = uVar5 * 0xc + *(short *)PTR_DAT_03048ee8;
  return;
}

