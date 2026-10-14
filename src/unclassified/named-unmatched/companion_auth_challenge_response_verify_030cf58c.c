/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: companion_auth_challenge_response_verify @ 030cf58c (file base 0x03000000; code starts at 0x03001000)
 * Size: 1238 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

char companion_auth_challenge_response_verify(int param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 auStack_28 [4];
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  int iStack_20;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  char cStack_19;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  uStack_1a = 0x87;
  iStack_18 = 0;
  do {
    if (1 < iStack_18) {
      return cStack_19;
    }
    uStack_1b = uStack_1a;
    if (*_DAT_030cf670 == '\0') {
      for (iStack_10 = 0; iStack_10 < 0x10; iStack_10 = iStack_10 + 1) {
        _DAT_030cf66c[iStack_10] = 0;
      }
      bitbang_bus_scan_buffer_for_match(0x7a,0x80,_DAT_030cf66c,8);
      FUN_030c6774(1);
      bitbang_bus_scan_buffer_for_match(0x7a,0x20,_DAT_030cf66c,1);
      FUN_030c6774(1);
      *_DAT_030cf66c = 0x83;
      bitbang_bus_scan_buffer_for_match(0x7a,0x22,_DAT_030cf66c,1);
      FUN_030c6774(1);
      cStack_19 = func_0x030cf1d0();
      if (cStack_19 != '\0') {
        return cStack_19;
      }
      FUN_030c6774(1);
      cStack_19 = func_0x030ce4dc();
      if (cStack_19 != '\0') {
        return cStack_19;
      }
      cStack_19 = func_0x030cf3b8();
      if (cStack_19 != '\0') {
        return cStack_19;
      }
    }
    for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
      *(undefined1 *)(_DAT_030cf914 + iStack_10 * 2) = *(undefined1 *)(param_1 + iStack_10);
      iVar3 = iStack_10 * 2;
      uVar1 = rng_seed_from_fm_voice_bytes();
      *(undefined1 *)(_DAT_030cf914 + iVar3 + 1) = uVar1;
    }
    cStack_19 = bitbang_bus_scan_buffer_for_match(0x7a,uStack_1b,_DAT_030cf914,0x10);
    if (cStack_19 != '\0') {
      return cStack_19;
    }
    FUN_030c6774(5);
    cVar2 = companion_chip_serial_command_sequence(0x7a,uStack_1b,_DAT_030cf918,0x10);
    if (cVar2 != '\0') {
      return cVar2;
    }
    auStack_28[0] = *(undefined1 *)(_DAT_030cf918 + 3);
    auStack_28[1] = *(undefined1 *)(_DAT_030cf918 + 4);
    auStack_28[2] = *(undefined1 *)(_DAT_030cf918 + 5);
    auStack_28[3] = *(undefined1 *)(_DAT_030cf918 + 6);
    uStack_24 = *(undefined1 *)(_DAT_030cf918 + 10);
    uStack_23 = *(undefined1 *)(_DAT_030cf918 + 0xc);
    uStack_22 = *(undefined1 *)(_DAT_030cf918 + 0xd);
    uStack_21 = *(undefined1 *)(_DAT_030cf918 + 0xe);
    *_DAT_030cf91c = 0;
    _DAT_030cf91c[1] = 0;
    if (iStack_18 != 0) {
      auStack_28[0] = *(undefined1 *)(_DAT_030cf918 + 3);
      auStack_28[1] = *(undefined1 *)(_DAT_030cf918 + 4);
      auStack_28[2] = *(undefined1 *)(_DAT_030cf918 + 5);
      auStack_28[3] = *(undefined1 *)(_DAT_030cf918 + 6);
      uStack_24 = *(undefined1 *)(_DAT_030cf918 + 10);
      uStack_23 = *(undefined1 *)(_DAT_030cf918 + 0xc);
      uStack_22 = *(undefined1 *)(_DAT_030cf918 + 0xd);
      uStack_21 = *(undefined1 *)(_DAT_030cf918 + 0xe);
      *_DAT_030cf91c = 0;
      _DAT_030cf91c[1] = 0;
    }
    uStack_2b = 0;
    uStack_2c = 0;
    iStack_20 = 1;
    cStack_19 = '\0';
    for (iStack_10 = 0; iStack_10 < iStack_20; iStack_10 = iStack_10 + 1) {
      func_0x030cec48(auStack_28,param_2,&uStack_2c,8,0x80,2);
      for (iStack_14 = 0; iStack_14 < 8; iStack_14 = iStack_14 + 1) {
        auStack_28[iStack_14] = *(undefined1 *)(param_2 + iStack_14);
      }
    }
    for (iStack_10 = 0; iStack_10 < 8; iStack_10 = iStack_10 + 1) {
      if (*(char *)(param_1 + iStack_10) != *(char *)(param_2 + iStack_10)) {
        cStack_19 = '2';
        break;
      }
    }
    if (cStack_19 == '\0') {
      *_LAB_030cfa80 = 1;
      return '\0';
    }
    iStack_18 = iStack_18 + 1;
  } while( true );
}

