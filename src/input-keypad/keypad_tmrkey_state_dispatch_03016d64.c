/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_tmrkey_state_dispatch @ 03016d64 (file base 0x03000000; code starts at 0x03001000)
 * Size: 254 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void keypad_tmrkey_state_dispatch(void)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  undefined4 *puVar4;
  radio_mode_state_0003e318 *prVar5;
  undefined1 auStack_c [4];
  
  puVar4 = PTR_DAT_03016e70;
  if (*(char *)((int)PTR_DAT_03016e70 + 0x2a) != '\x03') {
    return;
  }
  *(undefined1 *)((int)PTR_DAT_03016e70 + 0x2a) = 2;
  OSTmr_state_dispatch_callback(p_ucos_tmr_tmrkey,0,0,auStack_c);
  cVar3 = *(char *)((int)puVar4 + 0x29);
  if (cVar3 == '\x1d') {
    puVar4[0xb] = puVar4[6];
  }
  else if (cVar3 == '\x1e') {
    PTR_DAT_03016e70[0xb] = PTR_DAT_03016e70[5];
  }
  else if (cVar3 == '\x1f') {
    PTR_DAT_03016e70[0xb] = PTR_DAT_03016e70[7];
  }
  else if (cVar3 == '\x15') {
    PTR_DAT_03016e70[0xb] = PTR_DAT_03016e70[8];
  }
  else if (cVar3 == '\x16') {
    PTR_DAT_03016e70[0xb] = PTR_DAT_03016e70[9];
    prVar5 = p_radio_mode_state_0003e318;
    if ((*(char *)PTR_active_screen_subtype_03016e80 == '\n') ||
       (*(char *)PTR_active_screen_subtype_03016e80 == '\b')) {
      bVar2 = p_radio_mode_state_0003e318->flags_0x5;
      pbVar1 = &p_radio_mode_state_0003e318->flags_0x6;
      p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0xf;
      prVar5->flags_0x6 = *pbVar1 & 0x83;
      prVar5->flags_0x5 = bVar2 & 2;
      history_entry_stage();
      write_field_and_mbox_post(1,0x2a);
      return;
    }
    if ((6 < *(byte *)PTR_DAT_03016e88) && (*(byte *)PTR_DAT_03016e88 < 0x46)) {
      write_field_and_mbox_post(1,100);
      return;
    }
  }
  else if (cVar3 == '\x05') {
    PTR_DAT_03016e70[0xb] = PTR_codeplug_defaults_or_field_post_03016e8c;
  }
  set_flag_bits_and_post_os_flag_0x8000(8);
  return;
}

