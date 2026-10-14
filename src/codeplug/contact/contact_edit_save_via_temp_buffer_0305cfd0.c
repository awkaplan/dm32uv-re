/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_edit_save_via_temp_buffer @ 0305cfd0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_edit_save_via_temp_buffer(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  void *pvVar3;
  
  pvVar3 = malloc_best_fit(300);
  puVar2 = PTR_DAT_0305d018;
  memcpy_bytes_iram(pvVar3,p_text_entry_buffer,*(undefined1 *)PTR_DAT_0305d018);
  puVar1 = PTR_DAT_0305d00c;
  buffer_prepend_3byte_le(*(undefined4 *)PTR_DAT_0305d00c,pvVar3,*(undefined1 *)puVar2);
  contact_edit_save_flow1(pvVar3,*(byte *)puVar2 + 3,3,puVar1[8]);
  heap_free_with_adjacent_coalesce(pvVar3);
  return;
}

