/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_struct_bitfield_unpack_and_reset_variant5 @ 030250aa (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void config_struct_bitfield_unpack_and_reset_variant5(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte bStack00000008;
  byte bStack00000009;
  uint in_stack_0000000c;
  byte bStack00000010;
  byte bStack00000011;
  
  puVar1 = PTR_DAT_03025218;
  *(byte *)PTR_DAT_03025218 = bStack00000008 >> 7;
  *(byte *)((int)puVar1 + 1) = bStack00000008 >> 6 & 1;
  *(byte *)((int)puVar1 + 6) = bStack00000009 >> 4;
  puVar1[0xb] = (_bStack00000008 >> 0x10 & 0xff) * 0x10000 + (_bStack00000008 >> 0x18) * 0x100 +
                (in_stack_0000000c & 0xff);
  puVar1[0xc] = (in_stack_0000000c >> 8 & 0xff) * 0x10000 +
                (in_stack_0000000c >> 0x10 & 0xff) * 0x100 + (in_stack_0000000c >> 0x18);
  *(byte *)(puVar1 + 3) = bStack00000010 & 0x7f;
  *(byte *)((int)puVar1 + 0x11) = bStack00000011 >> 6;
  *(byte *)((int)puVar1 + 0x12) = bStack00000011 >> 3 & 7;
  *(byte *)((int)puVar1 + 0x13) = bStack00000011 & 7;
  *(undefined1 *)(puVar1 + 1) = 1;
  *(byte *)((int)puVar1 + 0x3d) = bStack00000010 & 0x7f;
  if ((_bStack00000010 & 0x7f) != 0) {
    *(undefined1 *)((uint)*(byte *)p_dmr_call_config_state + p_dmr_config_unpack_state + 2) = 1;
  }
  puVar1 = PTR_DAT_03025394;
  *(undefined1 *)(PTR_DAT_03025394 + 0xf) = 0;
  puVar1[0xe1] = 0;
  puVar1[0xe3] = 0;
  *(undefined1 *)(puVar1 + 0xe5) = 0;
  puVar2 = PTR_DAT_03025394;
  if (*(char *)((int)puVar1 + 0xb) == '\x01') {
    PTR_DAT_03025394[0xdf] = 0;
    memset_bytes((int)puVar2 + 0x3e,0xff,0x14);
  }
  if ((*(char *)(PTR_DAT_03025394 + 1) == '\x01') && (*(char *)(PTR_DAT_03025394 + 3) == '\0')) {
    OSFlagPost_wrapper_set_passthrough(0x80);
  }
  return;
}

