/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_history_record_append_with_date @ 0305878c (file base 0x03000000; code starts at 0x03001000)
 * Size: 622 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_history_record_append_with_date(uint param_1)

{
  int iVar1;
  ushort uVar2;
  undefined4 uVar3;
  ushort *puVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  undefined4 in_stack_00000004;
  undefined4 in_stack_0000000c;
  ushort in_stack_00000054;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4b;
  char local_45 [4];
  undefined1 uStack_41;
  undefined1 uStack_40;
  char cStack_3f;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  ushort local_34;
  ushort local_32;
  
  param_1 = param_1 & 0xff;
  iVar7 = param_1 - 1;
  iVar6 = *(int *)(PTR_LAB_03058910 + param_1 * 4);
  uVar2 = flash_block_id_resolve_locked(PTR_LAB_03058910[iVar7]);
  os_sem_pend_ms(p_ucos_mutex_000334c4,0);
  uVar2 = uVar2 & 0xff;
  flash_block_read(uVar2,0,DAT_03058914,0x17);
  if (*(byte *)(iVar6 + 4) < 0x14) {
    puVar4 = (ushort *)local_45;
    local_32 = fixed21_slot_table_remove_last_used(param_1);
    if (local_45[0] == '\0') {
      os_sem_post(p_ucos_mutex_000334c4);
      flash_record_erase_and_clear_cache(param_1);
      return;
    }
  }
  else {
    memcpy_bytes_iram(&local_32,DAT_03058918,2);
    flash_block_read(uVar2,(uint)local_32,&local_34,2);
    if (0x13 < (((local_34 >> 7) - 1) * 9 + (local_34 & 0x7f) / 0xe & 0xff)) goto LAB_030589b2;
    puVar4 = &local_34;
    memcpy_bytes_iram(DAT_03058918,puVar4,2);
    *(char *)(iVar6 + 4) = *(char *)(iVar6 + 4) + -1;
  }
  if (param_1 == 1) {
    in_stack_0000000c = in_stack_00000004;
  }
  local_45[1] = 0;
  local_45[2] = 0;
  local_45[3] = (char)in_stack_0000000c;
  uStack_41 = (undefined1)((uint)in_stack_0000000c >> 8);
  uStack_40 = (undefined1)((uint)in_stack_0000000c >> 0x10);
  uVar3 = rtc_decode_calendar_date();
  iVar1 = DAT_03058918;
  uStack_4f = (undefined1)((uint)uVar3 >> 8);
  uStack_4e = (undefined1)((uint)uVar3 >> 0x10);
  uStack_4b = (undefined1)((uint)puVar4 >> 8);
  cStack_3f = (char)((uint)puVar4 >> 0x10) + (char)((uint)puVar4 / 0x640000) * -100;
  uStack_3e = 0x14;
  uStack_3d = uStack_4b;
  uStack_3c = SUB41(puVar4,0);
  uStack_3b = (undefined1)uVar3;
  uStack_3a = uStack_4f;
  uStack_39 = uStack_4e;
  uStack_38 = (undefined1)((in_stack_00000054 & 0xff) / 10);
  uStack_37 = (undefined1)(in_stack_00000054 / 10 >> 8);
  if (*(char *)(iVar6 + 4) == '\0') {
    if ((((local_32 >> 7) - 1) * 9 + (local_32 & 0x7f) / 0xe & 0xff) < 0x14) {
      memcpy_bytes_iram(DAT_03058918,&local_32,2);
      flash_page_read_modify_write
                (PTR_LAB_03058910[iVar7],0,iVar1 + -0x15,0x17,local_32,local_45 + 1,0xe);
LAB_03058990:
      *(char *)(iVar6 + 4) = *(char *)(iVar6 + 4) + '\x01';
      if ((param_1 == 1) && (PTR_DAT_03058a7c[0x12] != -1)) {
        PTR_DAT_03058a7c[0x12] = PTR_DAT_03058a7c[0x12] + '\x01';
      }
      os_sem_post(p_ucos_mutex_000334c4);
      return;
    }
  }
  else {
    memcpy_bytes_iram(&local_34,DAT_03058a78,2);
    if (1 < *(byte *)(iVar6 + 4)) {
      bVar5 = 1;
      do {
        flash_block_read(uVar2,(uint)local_34,&local_34,2);
        bVar5 = bVar5 + 1;
      } while (bVar5 < *(byte *)(iVar6 + 4));
    }
    if (((((local_32 >> 7) - 1) * 9 + (local_32 & 0x7f) / 0xe & 0xff) < 0x14) &&
       ((((local_34 >> 7) - 1) * 9 + (local_34 & 0x7f) / 0xe & 0xff) < 0x14)) {
      flash_record_commit_3field
                (PTR_LAB_03058a84[iVar7],0,DAT_03058a88,0x17,(uint)local_32,local_45 + 1,0xe,
                 (uint)local_34,&local_32,2);
      goto LAB_03058990;
    }
  }
LAB_030589b2:
  os_sem_post(p_ucos_mutex_000334c4);
  flash_record_erase_and_clear_cache(param_1);
  return;
}

