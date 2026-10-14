/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: screen_option_template_load_id_generic @ 030427b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void screen_option_template_load_id_generic(void)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = PTR_DAT_03042928;
  *(undefined1 *)p_active_screen_option_count = PTR_DAT_03042928[4];
  *p_active_screen_option_ptr_array = *(undefined4 *)puVar1;
  *(undefined1 *)PTR_active_screen_subtype_03042934 = puVar1[5];
  *(undefined1 *)PTR_DAT_03042938 = 1;
  uVar2 = flash_read_4byte_mutex_guarded();
  *PTR_DAT_0304293c = uVar2;
  if (uVar2 - 1 < 50000) {
    *(undefined2 *)p_active_screen_index_list = 2;
  }
  else {
    *(undefined2 *)p_active_screen_index_list = 0;
  }
  if ((uint)*PTR_DAT_03042944 < uVar2) {
    uVar2 = *PTR_DAT_03042944 + 1;
    *PTR_DAT_03042948 = uVar2;
    if (8 < uVar2) {
      *PTR_DAT_03042948 = 8;
    }
  }
  else if (uVar2 == 0) {
    *PTR_DAT_03042944 = 0;
    *PTR_DAT_03042948 = 1;
  }
  else {
    *PTR_DAT_03042944 = uVar2 - 1;
    *PTR_DAT_03042948 = uVar2;
    if (8 < uVar2) {
      *PTR_DAT_03042948 = 8;
    }
  }
  return;
}

