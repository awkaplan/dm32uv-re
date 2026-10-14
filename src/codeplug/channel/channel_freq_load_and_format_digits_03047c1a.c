/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_freq_load_and_format_digits @ 03047c1a (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_freq_load_and_format_digits(void)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  puVar2 = PTR_DAT_03047d2c;
  bVar1 = PTR_DAT_03047d2c[4];
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = *(undefined4 *)puVar2;
  *(undefined1 *)PTR_active_screen_subtype_03047d08 = puVar2[5];
  if (*(char *)PTR_DAT_03047d28 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  init_field_pair_0x20_5();
  channel_record_load_by_index();
  memcpy_ck803s(&stack0x00000034,&stack0x00000000,0x33);
  p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0x9f | 0x60;
  uVar3 = bcd_frequency_decode(&stack0x00000050,4);
  pcVar5 = PTR_DAT_03047d34 + -7;
  pcVar4 = PTR_DAT_03047d34;
  do {
    *pcVar4 = (char)uVar3 + (char)(uVar3 / 10) * -10 + '0';
    pcVar4 = pcVar4 + -1;
    uVar3 = uVar3 / 10;
  } while (pcVar4 != pcVar5);
  *(undefined1 *)PTR_DAT_03047d38 = 7;
  *(undefined2 *)p_text_entry_current_char = 0x6c;
  return;
}

