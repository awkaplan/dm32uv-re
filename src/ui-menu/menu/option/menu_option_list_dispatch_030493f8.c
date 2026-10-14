/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_dispatch @ 030493f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 196 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_list_dispatch(uint index,void *list,void *ctx)

{
  uint uVar1;
  int iVar2;
  undefined1 local_1c;
  undefined1 uStack_1b;
  byte bStack_1a;
  byte bStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  byte bStack_16;
  byte bStack_15;
  
  flash_field_read_cached(4,0x500,&local_1c,8);
  *(undefined2 *)list = 0;
  uVar1 = vfo_active_side_mode_nibble();
  iVar2 = get_current_mode_state1();
  if (iVar2 != 0) {
    uVar1 = p_vfo_freq_display_state->flags_0x10 >> 5 & 3;
  }
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) {
    if ((uVar1 == 0) || (uVar1 == 2)) {
      uStack_1b = 0;
      uStack_18 = 0;
      bStack_16 = bStack_16 & 199;
      bStack_15 = bStack_15 & 0xf5;
      bStack_19 = bStack_19 & 0x9e;
      bStack_1a = bStack_1a & 0x9f;
    }
    else if ((uVar1 == 1) || (uVar1 == 3)) {
      bStack_16 = bStack_16 & 0xfb;
    }
  }
  else {
    uStack_18 = 0;
    uStack_17 = 0;
  }
  if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
    bStack_16 = bStack_16 & 0xfc;
    local_1c = 0;
  }
  if ((index & 0xff) < 0x33) {
                    /* WARNING: Could not recover jumptable at 0x030494ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_030494c8[index & 0xff] & 0xfffffffe))();
    return;
  }
  return;
}

