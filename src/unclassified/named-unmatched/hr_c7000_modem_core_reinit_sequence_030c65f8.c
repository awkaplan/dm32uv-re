/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hr_c7000_modem_core_reinit_sequence @ 030c65f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 246 bytes
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

void hr_c7000_modem_core_reinit_sequence(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  dword dVar6;
  dword dVar7;
  undefined4 *puVar8;
  int iVar9;
  
  puVar8 = PTR_DAT_030c67f0;
  dVar6 = SystemControl_Type_11000000.RF_MODE;
  *PTR_DAT_030c67f0 = dVar6;
  dVar6 = SystemControl_Type_11000000.WORK_MODE;
  puVar8[1] = dVar6;
  dVar6 = SystemControl_Type_11000000.AUDIO_CONTROL;
  dVar7 = SystemControl_Type_11000000.FM_PTT;
  puVar8[3] = dVar7;
  puVar8[2] = dVar6;
  iVar9 = _DAT_030c67f4;
  dVar6 = SystemControl_Type_11000000.SYS_INTERP_MASK;
  puVar8[4] = dVar6;
  dVar6 = SystemControl_Type_11000000.SYS_SOFT_RSTN;
  uVar1 = *(undefined1 *)(iVar9 + 0xd2);
  uVar2 = *(undefined1 *)(iVar9 + 0xd3);
  uVar3 = *(undefined1 *)(iVar9 + 0xcb);
  uVar4 = *(undefined1 *)(iVar9 + 0xcc);
  uVar5 = *(undefined1 *)(iVar9 + 0xc9);
  *(undefined1 *)((int)puVar8 + 0x1d) = *(undefined1 *)(iVar9 + 0xcf);
  *(undefined1 *)((int)puVar8 + 0x19) = uVar2;
  *(undefined1 *)((int)puVar8 + 0x1a) = uVar3;
  *(undefined1 *)(puVar8 + 7) = uVar5;
  puVar8[5] = dVar6;
  *(undefined1 *)(puVar8 + 6) = uVar1;
  *(undefined1 *)((int)puVar8 + 0x1b) = uVar4;
  dVar6 = SystemControl_Type_11000000.SYS_SOFT_RSTN;
  SystemControl_Type_11000000.SYS_SOFT_RSTN = dVar6 & 0xfffffff7;
  dVar6 = SystemControl_Type_11000000.SYS_SOFT_RSTN;
  SystemControl_Type_11000000.SYS_SOFT_RSTN = dVar6 & 0xffffffef;
  func_0x030ddcf8(10);
  *(byte *)(iVar9 + 0xd2) = *(byte *)(iVar9 + 0xd2) & 0xfe;
  func_0x030ddcf8(100);
  *(byte *)(iVar9 + 0xd2) = *(byte *)(iVar9 + 0xd2) & 0xfd;
  *(undefined1 *)(iVar9 + 0xd3) = 0x40;
  *(undefined1 *)(iVar9 + 0xcb) = 0x40;
  *(byte *)(iVar9 + 0xcc) = *(byte *)(iVar9 + 0xcc) | 0x40;
  *(undefined1 *)(iVar9 + 0xc9) = 0xc0;
  *(byte *)(iVar9 + 0xcf) = *(byte *)(iVar9 + 0xcf) & 0xef;
  func_0x030ddcf8(100);
  *(byte *)(iVar9 + 0xcf) = *(byte *)(iVar9 + 0xcf) & 0x7f;
  SystemControl_Type_11000000.SYS_INTERP_MASK = 0;
  SystemControl_Type_11000000.RF_MODE = 0x10e0;
  SystemControl_Type_11000000.WORK_MODE = 0x80;
  dVar6 = SystemControl_Type_11000000.AUDIO_CONTROL;
  SystemControl_Type_11000000.AUDIO_CONTROL = dVar6 & 0xfffffffe;
  SystemControl_Type_11000000.FM_PTT = 1;
  func_0x030ddcf8(0x32);
  return;
}

