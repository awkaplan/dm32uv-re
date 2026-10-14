/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_config_load_validate_writeback @ 03058620 (file base 0x03000000; code starts at 0x03001000)
 * Size: 346 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_block_config_load_validate_writeback(uint param_1,char param_2)

{
  undefined4 *puVar1;
  int iVar2;
  ushort block_id;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  uint unaff_r9;
  ushort local_28;
  ushort local_26;
  
  param_1 = param_1 & 0xff;
  iVar4 = param_1 - 1;
  iVar5 = *(int *)(PTR_LAB_030586dc + param_1 * 4);
  block_id = flash_block_id_resolve_locked(PTR_LAB_030586dc[iVar4]);
  os_sem_pend_ms(p_ucos_mutex_000334c4,0);
  puVar1 = PTR_DAT_030586d4;
  if ((*(char *)(iVar5 + 4) == '\0') || (param_2 == '\0')) {
    os_sem_post(p_ucos_mutex_000334c4);
    flash_record_erase_and_clear_cache(param_1);
    return;
  }
  cVar7 = *(char *)(iVar5 + 4) + '\x01';
  bVar8 = cVar7 - param_2;
  flash_block_read(block_id,0,PTR_DAT_030586d4,0x17);
  memcpy_bytes_iram(&local_26,(int)puVar1 + 0x15,2);
  if (bVar8 == 1) {
    flash_block_read(block_id,(uint)local_26,&local_28,2);
    iVar2 = DAT_030586e0;
    memcpy_bytes_iram(DAT_030586e0,&local_28,2);
    iVar3 = fixed21_slot_table_insert_after_last_used(param_1,local_26);
    flash_block_write(PTR_LAB_030586dc[iVar4],0,iVar2 + -0x15,0x17);
  }
  else {
    local_28 = local_26;
    if (cVar7 != param_2) {
      bVar6 = 0;
      do {
        unaff_r9 = (uint)local_26;
        local_26 = local_28;
        flash_block_read(block_id,(uint)local_28,&local_28,2);
        bVar6 = bVar6 + 1;
      } while (bVar6 < bVar8);
    }
    if (0x13 < (((unaff_r9 >> 7 & 0xffff) - 1) * 9 + (unaff_r9 & 0x7f) / 0xe & 0xff))
    goto LAB_0305873a;
    iVar3 = fixed21_slot_table_insert_after_last_used(param_1,local_26);
    flash_page_read_modify_write(PTR_LAB_03058910[iVar4],0,DAT_03058914,0x17,unaff_r9,&local_28,2);
  }
  if (iVar3 != 0) {
    *(char *)(iVar5 + 4) = *(char *)(iVar5 + 4) + -1;
    os_sem_post(p_ucos_mutex_000334c4);
    return;
  }
LAB_0305873a:
  os_sem_post(p_ucos_mutex_000334c4);
  flash_record_erase_and_clear_cache(param_1);
  return;
}

