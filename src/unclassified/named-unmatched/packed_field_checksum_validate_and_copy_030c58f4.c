/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: packed_field_checksum_validate_and_copy @ 030c58f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 174 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 packed_field_checksum_validate_and_copy(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uStack_20;
  byte bStack_1f;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  
  uVar1 = hamming23_syndrome_error_correct(*param_1 >> 1,0x17);
  uVar2 = hamming23_syndrome_error_correct(param_1[1] >> 1,0x17);
  uVar3 = hamming23_syndrome_error_correct(param_1[2] >> 1,0x17);
  bStack_1f = (byte)(uVar2 >> 0x13) & 0xf | (byte)((uVar1 >> 0xb) << 4);
  uStack_20 = (undefined1)(uVar1 >> 0xf);
  uStack_1e = (undefined1)(uVar2 >> 0xb);
  uStack_1d = (undefined1)(uVar3 >> 0xf);
  uVar1 = ccitt_crc4_stream_update(0,0x20,&uStack_20);
  if (((uVar1 ^ 0xf) & 0xff) != (uVar3 >> 0xb & 0xf)) {
    func_0x060d1774(_DAT_030c59a4,7,0);
    func_0x060d1774(&uStack_20,4,1);
    return 1;
  }
  func_0x030dec8c(param_2,&uStack_20,4);
  func_0x060d1774(_DAT_030c59a8,6,0);
  func_0x060d1774(&uStack_20,4,1);
  return 0;
}

