/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rssi_sql_meter_tick_increment @ 03037f94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 174 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rssi_sql_meter_tick_increment(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  
  if (((PTR_DAT_03038048[0xa09] == 'J') || (cVar1 = PTR_DAT_03038048[0xa08], cVar1 == '\x0f')) ||
     (cVar1 == '\x12')) {
    write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_03038048[2] + DAT_0303804c),0);
  }
  else {
    if (PTR_DAT_03038048[0xa09] == '\x1a') {
      if (*(ushort *)PTR_DAT_03038050 < 0x3ff) {
        *(ushort *)PTR_DAT_03038050 = *(ushort *)PTR_DAT_03038050 + 1;
      }
      else {
        *(undefined2 *)PTR_DAT_03038050 = 0;
      }
    }
    else if ((cVar1 == '\x05') || ((byte)(cVar1 - 9U) < 4)) {
      if (*(ushort *)PTR_DAT_03038050 < 0xff) {
        *(ushort *)PTR_DAT_03038050 = *(ushort *)PTR_DAT_03038050 + 1;
      }
      else {
        *(undefined2 *)PTR_DAT_03038050 = 0;
      }
    }
    else if (*(ushort *)PTR_DAT_03038050 < 0xff) {
      *(ushort *)PTR_DAT_03038050 = *(ushort *)PTR_DAT_03038050 + 1;
    }
    puVar3 = PTR_DAT_03038050;
    diag_rssi_sql_numeric_draw(3,*(undefined2 *)PTR_DAT_03038050);
    puVar2 = PTR_DAT_03038048;
    write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_03038048[2] + DAT_0303804c),0);
    (*(code *)(PTR_DAT_03038054[(byte)puVar2[0xa08]] & 0xfffffffe))(*(undefined2 *)puVar3);
  }
  return;
}

