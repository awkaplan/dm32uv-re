/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_read_4byte_mutex_guarded @ 03033778 (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 flash_read_4byte_mutex_guarded(void)

{
  undefined4 local_c;
  
  local_c = 0;
  flash_read_mutex_guarded(*PTR_DAT_03033858,&local_c,4);
  return local_c;
}

