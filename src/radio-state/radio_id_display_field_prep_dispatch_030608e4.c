/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_id_display_field_prep_dispatch @ 030608e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_id_display_field_prep_dispatch(void)

{
  undefined1 *puVar1;
  
  puVar1 = PTR_DAT_030609a4;
  radio_id_entry_read_by_stored_index(PTR_DAT_030609a4);
  if (*puVar1 == '\0') {
    *(byte *)PTR_DAT_030609a8 = *(byte *)PTR_DAT_030609a8 & 0xfe;
  }
  contact_name_field_encode_to_display_buffer
            (*(byte *)PTR_DAT_030609a8 & 1,*(byte *)PTR_DAT_030609a8 >> 2 & 0xf,
             (int)PTR_DAT_030609a8 + 1);
  return;
}

