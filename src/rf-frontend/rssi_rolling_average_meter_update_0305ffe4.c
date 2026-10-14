/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rssi_rolling_average_meter_update @ 0305ffe4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rssi_rolling_average_meter_update(void)

{
  undefined4 *puVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  
  iVar3 = vfo_display_state_nibble_bits_check();
  if (iVar3 == 0) {
    if ((*(byte *)PTR_call_active_flag_03060178 & 1) == 0) {
      menu_highlight_position_update(0,0);
    }
  }
  else {
    uVar2 = reg_0x67_lower9_read();
    puVar1 = PTR_DAT_03060170;
    if (0xff < uVar2) {
      uVar2 = 0xff;
    }
    puVar4 = (undefined4 *)((int)PTR_DAT_03060170 + 9);
    puVar6 = PTR_DAT_03060170;
    do {
      *(undefined1 *)puVar6 = *(undefined1 *)((int)puVar6 + 1);
      pbVar7 = (byte *)PTR_DAT_03060170;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    } while (puVar6 != puVar4);
    *(char *)((int)PTR_DAT_03060170 + 9) = (char)uVar2;
    uVar5 = 0;
    do {
      uVar5 = uVar5 + *pbVar7 & 0xffff;
      pbVar7 = pbVar7 + 1;
    } while (pbVar7 != (byte *)((int)puVar1 + 10));
    *(char *)PTR_DAT_03060174 = (char)(uVar5 / 10);
    if ((PTR_DAT_03060160[1] & 8) == 0) {
      menu_highlight_position_update(uVar5 / 10 & 0xff,0);
    }
  }
  return;
}

