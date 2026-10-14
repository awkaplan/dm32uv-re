/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_tx_contact_field_read @ 030560ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined2 vfo_tx_contact_field_read(char param_1)

{
  ushort block_id;
  uint offset;
  byte local_c;
  undefined1 uStack_b;
  
  block_id = flash_block_id_resolve_locked(0x43);
  if (param_1 == '\0') {
    offset = 0xffa;
  }
  else {
    offset = 0xffc;
  }
  flash_block_read(block_id,offset,&local_c,2);
  return CONCAT11(local_c >> 4,uStack_b);
}

