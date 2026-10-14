/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: volume_setting_load_clamp_apply @ 030557e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: audio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void volume_setting_load_clamp_apply(void)

{
  undefined4 *puVar1;
  ushort block_id;
  char cStack_c;
  char cStack_b;
  
  block_id = flash_block_id_resolve_locked(2);
  flash_block_read(block_id,0x20a,&cStack_c,2);
  *(char *)PTR_DAT_030558c8 = cStack_c;
  if (0xe < (byte)(cStack_c - 1U)) {
    *(undefined1 *)PTR_DAT_030558c8 = 0xd;
  }
  *(char *)PTR_DAT_030558cc = cStack_b;
  if (0x3e < (byte)(cStack_b - 1U)) {
    *(undefined1 *)PTR_DAT_030558cc = 0x27;
  }
  puVar1 = PTR_DAT_030558d0;
  *(undefined1 *)PTR_DAT_030558d0 = *(undefined1 *)PTR_DAT_030558cc;
  rda5807m_set_volume(*(undefined1 *)PTR_DAT_030558c8);
  tone_or_volume_step_lookup(*(undefined1 *)puVar1);
  mmio_11000088_bool_set(1);
  return;
}

