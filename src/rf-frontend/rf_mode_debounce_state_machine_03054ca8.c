/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_mode_debounce_state_machine @ 03054ca8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 188 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rf_mode_debounce_state_machine(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bVar4;
  
  if ((ushort)PTR_DAT_03054d48[2] < 800) {
    PTR_DAT_03054d48[2] = PTR_DAT_03054d48[2] + 1;
    if (PTR_DAT_03054d3c[1] == '\x02') {
      rf_transceiver_mode_init(1);
    }
    puVar1 = PTR_DAT_03054d3c;
    PTR_DAT_03054d3c[1] = 0;
    *puVar1 = 0;
  }
  else {
    bVar4 = (p_dm32_settings_block04[0x31] & 3) * '\x02' | (byte)p_dm32_settings_block04[0x30] >> 7;
    if (bVar4 == 2) {
      bVar4 = 0x12;
    }
    else if (bVar4 == 3) {
      bVar4 = 0x1e;
    }
    else {
      bVar4 = 0xc;
    }
    if (*PTR_DAT_03054d3c == 0) {
      rf_transceiver_mode_init(0);
    }
    else if ((6 < (byte)*PTR_DAT_03054d3c) && (PTR_DAT_03054d3c[1] != '\x02')) {
      iVar3 = get_current_mode_state2();
      puVar2 = PTR_DAT_03054dc0;
      if (iVar3 == 0) {
        fd6818b_partial_display_mode_reconfigure();
      }
      else if (PTR_DAT_03054d3c[2] == '\x01') {
        PTR_DAT_03054d3c[2] = 0;
        fd6818b_partial_display_mode_reconfigure();
      }
      else {
        *(undefined1 *)((int)PTR_DAT_03054dc0 + 2) = 1;
        *(undefined1 *)puVar2 = 0;
        rf_transceiver_mode_init(0);
      }
    }
    if (*(byte *)PTR_DAT_03054dc0 < bVar4) {
      *(byte *)PTR_DAT_03054dc0 = *(byte *)PTR_DAT_03054dc0 + 1;
    }
    else {
      *(undefined1 *)PTR_DAT_03054dc0 = 0;
    }
  }
  return;
}

