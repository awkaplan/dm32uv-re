/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: serial_password_command_handler @ 0302b2b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 262 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-uart
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void serial_password_command_handler(void)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 auStack_34 [4];
  char cStack_30;
  char cStack_2f;
  char cStack_2e;
  char acStack_2d [17];
  char cStack_1c;
  char acStack_1b [7];
  
  iVar1 = (*(code *)(*PTR_DAT_0302b33c & 0xfffffffe))(&cStack_30,10,50000,auStack_34);
  if ((iVar1 == 10) && (cStack_30 == 'P')) {
    if (cStack_2f == 'W') {
      flash_field_read_cached(4,0x43b,&cStack_1c,8);
    }
    else if (cStack_2f == 'R') {
      flash_field_read_cached(4,0x443,&cStack_1c,8);
    }
    if ((byte)(cStack_1c - 1U) < 0xfe) {
      pcVar3 = acStack_1b;
      uVar4 = 1;
      do {
        if (0xfd < (byte)(*pcVar3 - 1U)) break;
        uVar4 = uVar4 + 1 & 0xff;
        pcVar3 = pcVar3 + 1;
      } while (uVar4 != 8);
    }
    else {
      uVar4 = 0;
    }
    if ((byte)(cStack_2e - 1U) < 0xfe) {
      pcVar3 = acStack_2d;
      uVar5 = 1;
      do {
        if (0xfd < (byte)(*pcVar3 - 1U)) break;
        uVar5 = uVar5 + 1 & 0xff;
        pcVar3 = pcVar3 + 1;
      } while (uVar5 != 8);
    }
    else {
      uVar5 = 0;
    }
    uVar6 = PTR_DAT_0302b520[2];
    uVar2 = strlen_ck803s(uVar6);
    if (((uVar4 == uVar2) &&
        (iVar1 = buffer_compare_memcmp_style(uVar6,&cStack_2e,uVar4), iVar1 == 0)) ||
       ((uVar4 == uVar5 &&
        (iVar1 = buffer_compare_memcmp_style(&cStack_1c,&cStack_2e,uVar4), iVar1 == 0)))) {
      cStack_30 = '\x06';
      (*(code *)(PTR_DAT_0302b520[1] & 0xfffffffe))(&cStack_30,1);
    }
    else {
      cStack_30 = '\x15';
      (*(code *)(PTR_DAT_0302b520[1] & 0xfffffffe))(&cStack_30,1);
    }
  }
  return;
}

