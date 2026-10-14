/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_scan_step_and_lock @ 03065e3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 500 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_scan_step_and_lock(void)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  vfo_display_state *pvVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  char cVar10;
  int iVar11;
  undefined1 auStack_50 [52];
  
  iVar11 = get_current_mode_state2();
  if (iVar11 != 0) {
    set_flag_byte_03064328(4);
    vfo_load_side_config();
    settings_bitfield_remap_0x2d();
    puVar6 = PTR_DAT_03065ff8;
    PTR_DAT_03065ff8[0x1d] = 0;
    puVar6[0x1c] = 0;
    busy_wait_delay_loop_counted(auStack_50);
    memcpy_ck803s(p_vfo_display_state,auStack_50,0x33);
    set_flag_byte_03064328(3);
  }
  *(undefined1 *)PTR_DAT_03066000 = 0;
  pbVar3 = (byte *)PTR_DAT_03066004;
  pbVar4 = (byte *)PTR_DAT_03066000;
  pbVar5 = PTR_DAT_03065ff4;
  if ((byte)PTR_DAT_03065ff4[5] <= *(byte *)PTR_DAT_03066004) {
    *(undefined1 *)PTR_DAT_03066004 = 0;
    pbVar3 = (byte *)PTR_DAT_03066004;
    pbVar4 = (byte *)PTR_DAT_03066000;
    pbVar5 = PTR_DAT_03065ff4;
  }
  do {
    *pbVar5 = *pbVar5 & 0xfd | 2;
    ui_event_notify_alt(0x18);
    cVar10 = call_setup_connect_with_retry();
    if (cVar10 != '\x01') break;
    bVar1 = *pbVar3;
    *pbVar3 = bVar1 + 1;
    if (pbVar5[5] <= (byte)(bVar1 + 1)) {
      *pbVar3 = 0;
    }
    bVar1 = *pbVar4;
    *pbVar4 = bVar1 + 1;
  } while ((byte)(bVar1 + 1) < pbVar5[5]);
  PTR_DAT_03066008[1] = PTR_DAT_03066008[1] & 0xfe | (byte)p_dm32_settings_block04[0x2d] >> 7;
  puVar9 = PTR_DAT_03066014;
  puVar8 = PTR_DAT_03066010;
  pvVar7 = p_vfo_display_state;
  if (cVar10 == '\0') {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      uVar2 = *(undefined4 *)p_vfo_display_state;
      *(char *)PTR_DAT_03066010 = (char)uVar2;
      *(char *)((int)puVar8 + 1) = (char)((uint)uVar2 >> 8);
      *(char *)((int)puVar8 + 2) = (char)((uint)uVar2 >> 0x10);
      *(char *)((int)puVar8 + 3) = (char)((uint)uVar2 >> 0x18);
      uVar2 = *(undefined4 *)&pvVar7->field_0x4_0;
      *(char *)(puVar8 + 1) = (char)uVar2;
      *(char *)((int)puVar8 + 5) = (char)((uint)uVar2 >> 8);
      *(char *)((int)puVar8 + 6) = (char)((uint)uVar2 >> 0x10);
      *(char *)((int)puVar8 + 7) = (char)((uint)uVar2 >> 0x18);
      *(byte *)((int)puVar8 + 0xd) =
           *(byte *)((int)puVar8 + 0xd) & 0xc0 | pvVar7->flags_0xd & 0xf |
           (pvVar7->flags_0xd >> 4 & 1) << 4;
      *PTR_DAT_03065ff4 = *PTR_DAT_03065ff4 & 0xf7 | 8;
    }
    else {
      uVar2 = *(undefined4 *)p_vfo_display_state;
      *(char *)PTR_DAT_03066014 = (char)uVar2;
      *(char *)((int)puVar9 + 1) = (char)((uint)uVar2 >> 8);
      *(char *)((int)puVar9 + 2) = (char)((uint)uVar2 >> 0x10);
      *(char *)((int)puVar9 + 3) = (char)((uint)uVar2 >> 0x18);
      uVar2 = *(undefined4 *)&pvVar7->field_0x4_0;
      *(char *)(puVar9 + 1) = (char)uVar2;
      *(char *)((int)puVar9 + 5) = (char)((uint)uVar2 >> 8);
      *(char *)((int)puVar9 + 6) = (char)((uint)uVar2 >> 0x10);
      *(char *)((int)puVar9 + 7) = (char)((uint)uVar2 >> 0x18);
      *(byte *)((int)puVar9 + 0xd) =
           *(byte *)((int)puVar9 + 0xd) & 0xc0 | pvVar7->flags_0xd & 0xf |
           (pvVar7->flags_0xd >> 4 & 1) << 4;
      *PTR_DAT_03065ff4 = *PTR_DAT_03065ff4 & 0xef | 0x10;
    }
    puVar6 = PTR_DAT_03065ff4;
    *PTR_DAT_03065ff4 = *PTR_DAT_03065ff4 & 0xfb | 4;
    puVar6[4] = puVar6[*(byte *)PTR_DAT_03066004 + 8];
  }
  else {
    *(byte *)PTR_DAT_03066180 = *(byte *)PTR_DAT_03066180 & 0xfb;
    ui_event_notify_alt(0x19);
    ui_mode_group2_flag_set(4,1);
  }
  *(byte *)PTR_DAT_03066180 = *(byte *)PTR_DAT_03066180 & 0xfd;
  return;
}

