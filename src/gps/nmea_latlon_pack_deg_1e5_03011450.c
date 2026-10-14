/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: nmea_latlon_pack_deg_1e5 @ 03011450 (file base 0x03000000; code starts at 0x03001000)
 * Size: 130 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: gps
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int nmea_latlon_pack_deg_1e5(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar5 = 0;
  uVar1 = strtod_ascii_to_double();
  uVar6 = uVar5;
  soft_double_multiply();
  softdouble_to_int32();
  soft_double_from_int();
  uVar2 = soft_double_multiply();
  soft_double_sub(uVar1,uVar5,uVar2,uVar6);
  soft_double_divide();
  uVar1 = soft_double_add();
  *param_2 = uVar1;
  param_2[1] = uVar5;
  uVar6 = uVar5;
  iVar3 = soft_double_to_int();
  uVar2 = soft_double_pack_constant_two();
  soft_double_sub(uVar1,uVar5,uVar2,uVar6);
  soft_double_multiply();
  soft_double_conditional_add_or_sub();
  iVar4 = soft_double_to_int();
  return iVar3 * 0x800000 + iVar4;
}

