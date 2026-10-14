/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: roam_zone_record_init @ 03065c58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 432 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void roam_zone_record_init(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 local_20;
  undefined4 uStack_1c;
  uint auStack_18 [2];
  
  *(undefined1 *)PTR_DAT_03065e08 = 0;
  *(undefined1 *)PTR_DAT_03065e0c = 0;
  flash_field_read_cached(0x65,0,&local_20,4);
  puVar2 = PTR_DAT_03065e10;
  *(char *)((int)PTR_DAT_03065e10 + 7) = (char)local_20;
  *puVar2 = *puVar2 & 0xff0000ff | (local_20 >> 0x10 & 0xff) * 0x3c00;
  *(char *)((int)puVar2 + 3) = SUBPIECE(local_20, 3, 1);
  puVar2 = PTR_DAT_03065e10;
  if ((0x3f < ((local_20 & 0xff) - 1 & 0xff)) || (0x3f < (byte)(SUBPIECE(local_20, 3, 1) - 1U))) {
    *(undefined1 *)((int)PTR_DAT_03065e10 + 5) = 1;
    *(undefined1 *)((int)puVar2 + 6) = 1;
    *(undefined1 *)((int)puVar2 + 3) = 1;
    *(undefined1 *)((int)puVar2 + 7) = 1;
    local_20 = 0x1010001;
    flash_block_write(0x65,0,&local_20,4);
    memset_bytes(&local_20,0,0x10);
    if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
      SUBPIECE_SET(local_20, 0, 1, (char)DAT_03065e24);
      SUBPIECE_SET(local_20, 1, 1, SUBPIECE(DAT_03065e24, 1, 1));
      SUBPIECE_SET(local_20, 2, 1, SUBPIECE(DAT_03065e24, 2, 1));
      SUBPIECE_SET(local_20, 3, 1, SUBPIECE(DAT_03065e24, 3, 1));
      SUBPIECE_SET(uStack_1c, 0, 1, (char)DAT_03065e28);
      SUBPIECE_SET(uStack_1c, 1, 1, SUBPIECE(DAT_03065e28, 1, 1));
      SUBPIECE_SET(uStack_1c, 2, 1, SUBPIECE(DAT_03065e28, 2, 1));
      SUBPIECE_SET(uStack_1c, 3, 1, SUBPIECE(DAT_03065e28, 3, 1));
      auStack_18[0] = CONCAT13(SUBPIECE(auStack_18[0], 3, 1),0x3120);
    }
    else {
      SUBPIECE_SET(local_20, 0, 1, s_Roam_Zone_1_03065e18[0]);
      SUBPIECE_SET(local_20, 1, 1, s_Roam_Zone_1_03065e18[1]);
      SUBPIECE_SET(local_20, 2, 1, s_Roam_Zone_1_03065e18[2]);
      SUBPIECE_SET(local_20, 3, 1, s_Roam_Zone_1_03065e18[3]);
      SUBPIECE_SET(uStack_1c, 0, 1, s_Roam_Zone_1_03065e18[4]);
      SUBPIECE_SET(uStack_1c, 1, 1, s_Roam_Zone_1_03065e18[5]);
      SUBPIECE_SET(uStack_1c, 2, 1, s_Roam_Zone_1_03065e18[6]);
      SUBPIECE_SET(uStack_1c, 3, 1, s_Roam_Zone_1_03065e18[7]);
      SUBPIECE_SET(auStack_18[0], 0, 1, s_Roam_Zone_1_03065e18[8]);
      SUBPIECE_SET(auStack_18[0], 1, 1, s_Roam_Zone_1_03065e18[9]);
      SUBPIECE_SET(auStack_18[0], 2, 1, s_Roam_Zone_1_03065e18[10]);
      SUBPIECE_SET(auStack_18[0], 3, 1, s_Roam_Zone_1_03065e18[0xb]);
    }
    flash_block_write(0x65,0x10,&local_20,0x10);
    local_20 = CONCAT22(SUBPIECE(local_20, 2, 2),0x101);
    flash_block_write(0x65,0x20,&local_20,2);
    if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
      SUBPIECE_SET(local_20, 0, 1, (char)DAT_03065e24);
      SUBPIECE_SET(local_20, 1, 1, SUBPIECE(DAT_03065e24, 1, 1));
      SUBPIECE_SET(local_20, 2, 1, SUBPIECE(DAT_03065e24, 2, 1));
      SUBPIECE_SET(local_20, 3, 1, SUBPIECE(DAT_03065e24, 3, 1));
      uStack_1c = DAT_03065e30;
      auStack_18[0] = CONCAT13(SUBPIECE(auStack_18[0], 3, 1),0x3120);
    }
    else {
      SUBPIECE_SET(local_20, 0, 1, s_Roam_Zone_1_03065e18[0]);
      SUBPIECE_SET(local_20, 1, 1, s_Roam_Zone_1_03065e18[1]);
      SUBPIECE_SET(local_20, 2, 1, s_Roam_Zone_1_03065e18[2]);
      SUBPIECE_SET(local_20, 3, 1, s_Roam_Zone_1_03065e18[3]);
      uStack_1c = DAT_03065e2c;
      auStack_18[0] = CONCAT22(SUBPIECE(auStack_18[0], 2, 2),0x31);
    }
    flash_block_write(0x66,0,&local_20,0x10);
    local_20 = 0x44000000;
    uStack_1c = 0x43900000;
    auStack_18[0] = auStack_18[0] & 0xffff0000;
    flash_block_write(0x66,0x10,&local_20,10);
    flash_field_write_cached(0x66,0xff0,1);
  }
  puVar2 = PTR_DAT_03065e10;
  sVar1 = (*(byte *)((int)PTR_DAT_03065e10 + 3) - 1) * 0x21;
  flash_field_read_cached(0x65,sVar1 + 0x20,&local_20,1);
  *(char *)((int)puVar2 + 5) = (char)local_20;
  flash_field_read_cached(0x65,sVar1 + 0x21,puVar2 + 2,0x10);
  flash_field_read_cached(0x66,0xff0,&local_20,1);
  *(char *)((int)puVar2 + 6) = (char)local_20;
  return;
}

