/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_stored_setting_load_and_dispatch @ 03064f54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined1 flash_stored_setting_load_and_dispatch(uint param_1)

{
  undefined1 uVar1;
  char local_c;
  undefined1 uStack_b;
  
  flash_field_read_cached(4,((param_1 & 0xff) + 0x8f) * 2,&local_c,2);
  if ((byte)(local_c - 1U) < 4) {
    uVar1 = factory_service_command_dispatch(local_c,uStack_b);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

