/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rda5807m_seek_complete_poll @ 03065bb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
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

void rda5807m_seek_complete_poll(void)

{
  ushort uVar1;
  byte bStack_c;
  undefined1 uStack_b;
  
  os_sem_pend_ms(_DAT_03065c44,0);
  rda5807m_read_reg_0a(&bStack_c);
  if ((bStack_c & 0x60) == 0x40) {
    PTR_DAT_03065c48[2] = PTR_DAT_03065c48[2] & 0xfd;
    uVar1 = CONCAT11(bStack_c,uStack_b) & 0x3ff;
    if ((*(byte *)PTR_DAT_03065c4c & 2) == 0) {
      *(ushort *)PTR_DAT_03065c50 = uVar1 * 5 + 0x1964;
    }
    else {
      *(ushort *)PTR_DAT_03065c50 = uVar1 * 5 + 0x1db0;
    }
    bStack_c = bStack_c & 3;
    battery_value_display_format((uint)~(int)(char)PTR_DAT_03065c54[0x2d] >> 0x1f);
    bcd_pack_and_write_flash_block4_0x702(*(undefined2 *)PTR_DAT_03065c50);
  }
  os_sem_post(_DAT_03065c44);
  return;
}

