/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_multikey_digit_dispatch @ 0305a468 (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_list_multikey_digit_dispatch(char param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 auStack_8 [4];
  
  puVar3 = PTR_DAT_0305a5f4;
  puVar2 = p_text_entry_buffer_alias;
  cVar1 = *(char *)((int)PTR_DAT_0305a5ec + 3);
  if (cVar1 == '\x01') {
    if (*(char *)PTR_DAT_0305a5ec == '\x03') {
      *(char *)p_text_entry_buffer_alias = param_1 + '0';
      scan_list_scroll_update(puVar2);
    }
  }
  else if (cVar1 == '\0') {
    scan_list_name_edit_input_handler();
  }
  else if (cVar1 == '\x02') {
    if (*(char *)PTR_DAT_0305a5ec == '\x03') {
      *(char *)PTR_DAT_0305a5f4 = param_1;
      os_post_message_opt_validated(p_ucos_queue_inputq,puVar3,4,0,auStack_8);
    }
  }
  else if ((cVar1 == '\x03') && (*(char *)PTR_DAT_0305a5ec == '\x03')) {
    *(char *)PTR_DAT_0305a5f4 = param_1;
    os_post_message_opt_validated(p_ucos_queue_inputq,puVar3,4,0,auStack_8);
  }
  return;
}

