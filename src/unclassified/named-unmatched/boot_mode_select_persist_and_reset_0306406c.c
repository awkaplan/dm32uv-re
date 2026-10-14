/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: boot_mode_select_persist_and_reset @ 0306406c (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void boot_mode_select_persist_and_reset(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  
  cVar1 = *(char *)((int)PTR_DAT_03064174 + 2);
  if (cVar1 == '\x01') {
    iVar3 = read_byte_field_0305dbf4();
    if (iVar3 == 0xa6) {
      settings_write_0xf00_wrapper(0xa0);
    }
  }
  else if (cVar1 == '\x02') {
    settings_write_0xf00_wrapper(0xa6);
  }
  else if (cVar1 == '\x03') {
    iVar3 = read_byte_field_0305dbf4();
    if (iVar3 == 0xa5) {
      settings_write_0xf00_wrapper(0xa0);
    }
  }
  else if (cVar1 == '\x04') {
    settings_write_0xf00_wrapper(0xa5);
  }
  puVar2 = PTR_DAT_03064174;
  if (*(char *)((int)PTR_DAT_03064174 + 2) != '\0') {
    cVar1 = PTR_DAT_03064178[0xb];
    if (cVar1 == '\0') {
      flash_quad_enable_and_system_reset();
    }
    else {
      *(undefined1 *)((int)PTR_DAT_03064174 + 3) = 1;
      if (cVar1 == '\x02') {
        *(byte *)puVar2 = *(byte *)puVar2 & 0xef | 0x10;
        PTR_DAT_0306417c[5] = PTR_DAT_0306417c[4];
      }
    }
  }
  return;
}

