/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030cda30 @ 030cda30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1636 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x030cdee6) */
/* WARNING: Removing unreachable block (ram,0x030cdeea) */
/* WARNING: Removing unreachable block (ram,0x030cdf44) */
/* WARNING: Removing unreachable block (ram,0x030cdf5e) */
/* WARNING: Removing unreachable block (ram,0x030ce31a) */
/* WARNING: Removing unreachable block (ram,0x030cdf6e) */
/* WARNING: Removing unreachable block (ram,0x030ce33a) */
/* WARNING: Removing unreachable block (ram,0x030ce37a) */
/* WARNING: Removing unreachable block (ram,0x030ce33e) */
/* WARNING: Removing unreachable block (ram,0x030ce320) */
/* WARNING: Removing unreachable block (ram,0x030cdf78) */
/* WARNING: Removing unreachable block (ram,0x030cdf8e) */
/* WARNING: Removing unreachable block (ram,0x030ce374) */
/* WARNING: Removing unreachable block (ram,0x030cdf92) */
/* WARNING: Removing unreachable block (ram,0x030cdf94) */
/* WARNING: Removing unreachable block (ram,0x030cdf9a) */
/* WARNING: Removing unreachable block (ram,0x030cdfc0) */
/* WARNING: Removing unreachable block (ram,0x030cdfd8) */
/* WARNING: Removing unreachable block (ram,0x030cdfdc) */
/* WARNING: Removing unreachable block (ram,0x030ce366) */
/* WARNING: Removing unreachable block (ram,0x030cdfee) */
/* WARNING: Removing unreachable block (ram,0x030cdf3e) */
/* WARNING: Removing unreachable block (ram,0x030ce288) */
/* WARNING: Removing unreachable block (ram,0x030ce28e) */
/* WARNING: Removing unreachable block (ram,0x030cdffa) */
/* WARNING: Removing unreachable block (ram,0x030ce2ca) */
/* WARNING: Removing unreachable block (ram,0x030ce00a) */
/* WARNING: Removing unreachable block (ram,0x030ce012) */
/* WARNING: Removing unreachable block (ram,0x030ce1ea) */
/* WARNING: Removing unreachable block (ram,0x030ce23e) */
/* WARNING: Removing unreachable block (ram,0x030ce268) */
/* WARNING: Removing unreachable block (ram,0x030ce07c) */
/* WARNING: Removing unreachable block (ram,0x030ce082) */
/* WARNING: Removing unreachable block (ram,0x030ce13c) */
/* WARNING: Removing unreachable block (ram,0x030ce19e) */
/* WARNING: Removing unreachable block (ram,0x030ce1ca) */
/* WARNING: Removing unreachable block (ram,0x030ce08c) */
/* WARNING: Removing unreachable block (ram,0x030cdee0) */
/* WARNING: Removing unreachable block (ram,0x030cdf00) */
/* WARNING: Removing unreachable block (ram,0x030ce2f0) */
/* WARNING: Removing unreachable block (ram,0x030cdeec) */
/* WARNING: Removing unreachable block (ram,0x030cdd28) */
/* WARNING: Removing unreachable block (ram,0x030ce0fc) */
/* WARNING: Removing unreachable block (ram,0x030cdd3e) */
/* WARNING: Removing unreachable block (ram,0x030cdb74) */
/* WARNING: Removing unreachable block (ram,0x030ce0aa) */
/* WARNING: Removing unreachable block (ram,0x030cdb86) */
/* WARNING: Type propagation algorithm not settling */

void FUN_030cda30(undefined4 param_1,int param_2__w,int param_3,int param_4,int param_5,int param_6__w)

{
  short param_2 = (short)param_2__w;
  short param_6 = (short)param_6__w;
  bool bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iStack_354;
  undefined1 auStack_31c [336];
  undefined1 auStack_1cc [418];
  short asStack_2a [3];
  
  uVar6 = *(uint *)(param_5 + 8) & uRam030cdd4c;
  bVar1 = (*(uint *)(param_4 + 8) & uRam030cdd4c) != 0;
  if (param_2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  asStack_2a[1] = 0xf;
  fixed_point_signed_divide_16bit(0x40000000,1,0,0xf,asStack_2a + 1);
  if (uVar6 != 0) {
    if (bVar1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (bVar1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  array_copy_u16(auStack_31c,param_3,0xa8,*(undefined2 *)(param_4 + 0xc));
  u16_buffer_fill_memset(auStack_1cc,0,0xa8);
  iStack_354 = param_3 + 0x1cc;
  u16_buffer_fill_memset(auStack_31c,0,0x150);
  uVar2 = *(ushort *)(param_4 + 0xc);
  if (uVar2 == 0x4000000) {
    iVar7 = -1;
  }
  else {
    iVar7 = ((uint)uVar2 * -0x20 >> 5 & 0xffff ^ 0x8000) - 0x8000;
  }
  sVar3 = *(short *)(param_4 + 0x84);
  sVar4 = *(short *)(param_4 + 4);
  uVar8 = *(undefined4 *)(param_4 + 0x80);
  if (uVar2 == 0) {
    if (param_6 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    iVar5 = fixed_point_signed_divide_16bit(0,0xfffffffc,0,0xfffffffc,asStack_2a);
    uVar6 = (uint)(short)(asStack_2a[0] + -0xf);
    if ((int)uVar6 < 0) {
      iVar5 = (iVar5 << 0x10) >> (-uVar6 & 0x3f);
    }
    else {
      iVar5 = (iVar5 << 0x10) << (uVar6 & 0x3f);
    }
    sVar4 = FUN_030cd0e8(iStack_354,param_3 + 0x1ca,iVar7,param_3 + 0x15a,uVar8,param_4 + 0x10,
                         (int)sVar3,(int)sVar4,iVar5 + 0x8000 >> 0x10,2);
    if (sVar4 != 0) {
      if ((int)((uint)*(ushort *)(param_4 + 0xe) << 0x10) >> 8 != 0x100000) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      fixed_point_freq_scale_and_accumulate_into_buffer
                (auStack_31c,0,0xf,(int)*(short *)(param_4 + 0xc),iStack_354,
                 (int)*(short *)(param_3 + 0x1ca));
    }
    *(undefined4 *)(param_3 + 0x150) = 0;
    array_copy_u16(param_3,auStack_31c,0xa8);
    *(undefined4 *)(param_3 + 0x154) = 0;
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

