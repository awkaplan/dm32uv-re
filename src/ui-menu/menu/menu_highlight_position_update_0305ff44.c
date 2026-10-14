/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_highlight_position_update @ 0305ff44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_highlight_position_update(int param_1__w,int param_2)

{
  byte param_1 = (byte)param_1__w;
  char cVar1;
  int iVar2;
  byte *pbVar3;
  char cVar4;
  
  iVar2 = keypad_dispatch_not_inhibited();
  if (((iVar2 != 0) && ((PTR_DAT_0306015c[8] & 1) == 0)) && ((*PTR_DAT_03060160 & 2) == 0)) {
    if (param_1 < 0x29) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
      pbVar3 = PTR_LAB_030b7380_1_03060164;
      do {
        if (param_1 <= *pbVar3) goto LAB_0305ff8e;
        cVar4 = cVar4 + '\x01';
        pbVar3 = pbVar3 + 1;
      } while (cVar4 != '\x14');
      cVar4 = '\x13';
    }
LAB_0305ff8e:
    if ((*PTR_DAT_03060160 & 0x40) == 0) {
      cVar1 = read_byte_field_0302e120();
      if ((((cVar1 == '\x02') || (cVar1 == '\t')) ||
          ((*(char *)PTR_DAT_03060168 == '\0' || (*(char *)PTR_DAT_03060168 == 'w')))) &&
         ((*(char *)PTR_DAT_0306016c != cVar4 || (param_2 != 0)))) {
        *(char *)PTR_DAT_0306016c = cVar4;
        signal_meter_bargraph_draw(0,cVar4,0xffff);
      }
    }
  }
  return;
}

