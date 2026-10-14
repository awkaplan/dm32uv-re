/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_request_init @ 03059860 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_request_init(ushort param_1)

{
  *(undefined2 *)PTR_DAT_03059958 = 0x20;
  *(undefined2 *)p_text_entry_current_char = 5;
  memset_bytes(p_text_entry_buffer,0,0x154);
  *(undefined1 *)PTR_DAT_03059964 = 0;
  *(undefined1 *)PTR_DAT_03059968 = 1;
  *(undefined1 *)p_text_entry_current_char_alias = 0;
  *(ushort *)PTR_DAT_03059970 = param_1 & 0xff;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    *(undefined1 *)((int)PTR_DAT_03059978 + 3) = 0;
    *(undefined1 *)PTR_DAT_0305997c = 2;
  }
  else {
    *(undefined1 *)((int)PTR_DAT_03059978 + 3) = 2;
    *(undefined1 *)PTR_DAT_0305997c = 0;
  }
  *(undefined1 *)PTR_DAT_03059980 = 0;
  *(undefined1 *)PTR_DAT_03059984 = 0;
  *(undefined1 *)PTR_DAT_03059988 = 0;
  *(undefined1 *)PTR_DAT_03059978 = 3;
  *(undefined1 *)PTR_DAT_0305998c = 0;
  return;
}

