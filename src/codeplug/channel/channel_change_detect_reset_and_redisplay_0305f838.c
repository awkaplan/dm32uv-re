/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_change_detect_reset_and_redisplay @ 0305f838 (file base 0x03000000; code starts at 0x03001000)
 * Size: 136 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_change_detect_reset_and_redisplay(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  char acStack_38 [4];
  char acStack_34 [4];
  undefined1 auStack_30 [12];
  
  byte_table_derive_from_const_seed(auStack_30);
  data_block_checksum4(auStack_30,acStack_34);
  mutex_guarded_call_generic3arg(0x10c,acStack_38,4);
  puVar1 = PTR_DAT_0305f8c4;
  iVar3 = 0;
  PTR_DAT_0305f8c4[4] = PTR_DAT_0305f8c4[4] & 0xbf;
  uVar2 = _DAT_0305f8c8;
  do {
    if (acStack_38[iVar3] != acStack_34[iVar3]) {
      tx_led_or_tone_off_conditional_variant_030609ec();
      tx_led_or_tone_off_conditional();
      display_clear_fullscreen();
      display_draw_number_centered_dispatch(0x46,0xffff,0,uVar2);
      puVar1[4] = puVar1[4] & 0xbf | 0x40;
      OSTimeDly_ms_wrapper(1000);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  return;
}

