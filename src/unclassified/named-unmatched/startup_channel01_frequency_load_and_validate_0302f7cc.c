/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: startup_channel01_frequency_load_and_validate @ 0302f7cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 234 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void startup_channel01_frequency_load_and_validate(void)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  byte bStack_19;
  char cStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  byte bStack_15;
  char cStack_14;
  
  uVar2 = flash_block_id_resolve_locked(0x11);
  flash_block_read(uVar2 & 0xff,0xe00,&uStack_1c,9);
  *(undefined1 *)PTR_DAT_0302f954 = uStack_1c;
  puVar1 = PTR_DAT_0302f958;
  bcd_frequency_bound_clamp(1,PTR_DAT_0302f958[2],&uStack_1b);
  bcd_frequency_bound_clamp(0,puVar1[3],&bStack_19);
  bcd_frequency_bound_clamp(1,*puVar1,&uStack_17);
  bcd_frequency_bound_clamp(0,puVar1[1],&bStack_15);
  puVar1 = PTR_DAT_0302f95c;
  *(byte *)PTR_DAT_0302f95c = bStack_19 << 4;
  *(byte *)((int)puVar1 + 1) = bStack_19 >> 4 | cStack_18 << 4;
  *(undefined1 *)((int)puVar1 + 2) = uStack_1b;
  *(undefined1 *)((int)puVar1 + 3) = uStack_1a;
  bcd_frequency_pair_validate_and_store(1);
  puVar1 = PTR_DAT_0302f960;
  *(byte *)PTR_DAT_0302f960 = bStack_15 << 4;
  *(byte *)((int)puVar1 + 1) = bStack_15 >> 4 | cStack_14 << 4;
  *(undefined1 *)((int)puVar1 + 2) = uStack_17;
  *(undefined1 *)((int)puVar1 + 3) = uStack_16;
  bcd_frequency_pair_validate_and_store(0);
  flash_block_read(uVar2 & 0xff,0xe10,&uStack_1c,1);
  puVar1 = PTR_DAT_0302f964;
  *(undefined1 *)((int)PTR_DAT_0302f964 + 0x5e) = uStack_1c;
  flash_field_read_cached(0x11,0,puVar1,1);
  if (0x20 < *(byte *)puVar1) {
    *(undefined1 *)puVar1 = 0x20;
  }
  puVar1 = PTR_DAT_0302f964;
  *(byte *)(PTR_DAT_0302f964 + 4) = *(byte *)(PTR_DAT_0302f964 + 4) & 0x7f;
  *(undefined1 *)((int)puVar1 + 3) = 6;
  return;
}

