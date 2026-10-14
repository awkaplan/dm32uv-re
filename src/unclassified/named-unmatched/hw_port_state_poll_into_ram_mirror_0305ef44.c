/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hw_port_state_poll_into_ram_mirror @ 0305ef44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 468 bytes
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

void hw_port_state_poll_into_ram_mirror(void)

{
  int iVar1;
  undefined4 *puVar2;
  byte bStack_10;
  undefined1 uStack_f;
  byte bStack_d;
  
  iVar1 = _DAT_0305f118;
  mutex_guarded_call_generic3arg(0xa0,_DAT_0305f118,1);
  mutex_guarded_call_generic3arg(0x80,&bStack_d,1);
  *(byte *)(iVar1 + -1) = *(byte *)(iVar1 + -1) & 0xfe;
  if ((bStack_d & 1) != 0) {
    *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xfe | 1;
  }
  *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xfd;
  if ((bStack_d & 2) != 0) {
    *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xfd | 2;
  }
  *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xfb;
  if ((bStack_d & 4) != 0) {
    *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xfb | 4;
  }
  *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xf7;
  if ((bStack_d & 8) != 0) {
    *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xf7 | 8;
  }
  *(byte *)((int)PTR_DAT_0305f11c + 3) = *(byte *)((int)PTR_DAT_0305f11c + 3) & 0xfe;
  if ((bStack_d & 0x20) != 0) {
    *(byte *)((int)PTR_DAT_0305f11c + 3) = *(byte *)((int)PTR_DAT_0305f11c + 3) & 0xfe | 1;
  }
  puVar2 = PTR_DAT_0305f11c;
  *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xef;
  if ((bStack_d & 0x40) != 0) {
    *(byte *)puVar2 = *(byte *)puVar2 & 0xef | 0x10;
  }
  mutex_guarded_call_generic3arg(0x81,&bStack_d,1);
  *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xdf;
  if ((bStack_d & 1) != 0) {
    *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xdf | 0x20;
  }
  *(byte *)((int)PTR_DAT_0305f11c + 3) = *(byte *)((int)PTR_DAT_0305f11c + 3) & 0xfd;
  if ((bStack_d & 2) != 0) {
    *(byte *)((int)PTR_DAT_0305f11c + 3) = *(byte *)((int)PTR_DAT_0305f11c + 3) & 0xfd | 2;
  }
  *(byte *)((int)PTR_DAT_0305f11c + 3) = *(byte *)((int)PTR_DAT_0305f11c + 3) & 0xfb;
  if ((bStack_d & 4) != 0) {
    *(byte *)((int)PTR_DAT_0305f11c + 3) = *(byte *)((int)PTR_DAT_0305f11c + 3) & 0xfb | 4;
  }
  puVar2 = PTR_DAT_0305f11c;
  *(byte *)((int)PTR_DAT_0305f11c + 3) = *(byte *)((int)PTR_DAT_0305f11c + 3) & 0xf7;
  if ((bStack_d & 8) != 0) {
    *(byte *)((int)puVar2 + 3) = *(byte *)((int)puVar2 + 3) & 0xf7 | 8;
  }
  mutex_guarded_call_generic3arg(0x82,&bStack_d,1);
  *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xbf;
  if ((bStack_d & 0x10) != 0) {
    *(byte *)PTR_DAT_0305f11c = *(byte *)PTR_DAT_0305f11c & 0xbf | 0x40;
  }
  mutex_guarded_call_generic3arg(0xa1,&bStack_10,2);
  *(byte *)PTR_DAT_0305f120 = bStack_10;
  *(undefined1 *)PTR_DAT_0305f124 = uStack_f;
  if ((4 < bStack_10) && (bStack_10 != 0xa5)) {
    *(undefined1 *)PTR_DAT_0305f120 = 0xa5;
  }
  return;
}

