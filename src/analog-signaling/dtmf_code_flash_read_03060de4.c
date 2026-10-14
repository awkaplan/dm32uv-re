/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_code_flash_read @ 03060de4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dtmf_code_flash_read(char param_1,uint param_2,uint param_3,void *param_4)

{
  ushort block_id;
  
  param_3 = param_3 & 0xff;
  block_id = flash_block_id_resolve_locked(6);
  if (param_1 == '\0') {
    flash_block_read(block_id,0x110,param_4,param_3);
  }
  else if (param_1 == '\x01') {
    flash_block_read(block_id,0x120,param_4,param_3);
  }
  else if (param_1 == '\x02') {
    flash_block_read(block_id,((param_2 & 0xff) - 1) * 0x10 & 0xfff0,param_4,param_3);
  }
  return;
}

