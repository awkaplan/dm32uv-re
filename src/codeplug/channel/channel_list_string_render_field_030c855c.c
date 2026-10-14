/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_list_string_render_field @ 030c855c (file base 0x03000000; code starts at 0x03001000)
 * Size: 176 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined2
channel_list_string_render_field(undefined4 param_1,int param_2,short param_3,int param_4)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  short *psVar6;
  undefined2 auStack_b4 [72];
  
  if (*(short *)(param_4 + 0x42) == 0) {
    return *(undefined2 *)(param_4 + 0x34);
  }
  *(undefined2 *)(param_4 + 0x36) = PTR_DAT_030c860c[param_3];
  sVar1 = pack_u16_array_low_bits_to_bitfield(param_2,0xc);
  uVar3 = func_0x030d2a7c((int)sVar1,0xc);
  uVar3 = unpack_bits_lsb_first_to_u16_array(uVar3,auStack_b4,0x18);
  sVar2 = pack_u16_array_low_bits_to_bitfield(param_2 + 0x18,0xc);
  uVar4 = func_0x030d2a7c((int)sVar2,0xb);
  iVar5 = unpack_bits_lsb_first_to_u16_array(uVar4,uVar3,0x17);
  lcg_conditional_reflect_u16_array(iVar5 + -0x2e,0x17,(int)sVar1,1);
  sVar1 = *(short *)(param_4 + 0x36) + -0x18;
  if (sVar1 != 0) {
    array_copy_u16(iVar5,param_2 + 0x30,(int)sVar1);
  }
  if (0 < param_3) {
    psVar6 = _FUN_030c8610;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
      auStack_b4[sVar1] = 0;
    } while (psVar6 != _FUN_030c8610 + (ushort)(param_3 - 1) + 1);
  }
  func_0x030d2cc4(param_1,auStack_b4);
  return *(undefined2 *)(param_4 + 0x34);
}

