/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_log_record_append_compact @ 03062d2c (file base 0x03000000; code starts at 0x03001000)
 * Size: 342 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gps_log_record_append_compact(undefined4 param_1,undefined2 param_2)

{
  void *mutex;
  undefined4 uVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  undefined1 local_78;
  undefined1 uStack_77;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined1 auStack_30 [10];
  ushort local_26;
  
  local_26 = 0;
  uVar1 = flash_block_id_resolve_locked(1);
  flash_block_read((ushort)uVar1,0,&local_26,2);
  mutex = p_ucos_mutex_0003944c;
  if (local_26 < 0x33) {
    if (local_26 == 0x32) {
      uVar4 = 0x14;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    os_sem_pend_ms(p_ucos_mutex_0003944c,0);
    spi_flash_sector_erase(uVar1);
    local_26 = 0;
    flash_page_tag_write(uVar1,1);
    os_sem_post(mutex);
    uVar4 = 0;
  }
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar2 = flash_block_id_resolve_helper1();
  flash_page_tag_write(uVar2,0x7f);
  if (uVar4 < local_26) {
    uVar5 = 0;
    uVar3 = uVar4;
    do {
      spi_flash_read_seq(uVar1,uVar3 * 0x50 + 0x10,&local_78,0x50);
      spi_flash_program_pagesplit(uVar2,uVar5 * 0x50 + 0x10,&local_78,0x50);
      uVar3 = uVar3 + 1 & 0xff;
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar3 < local_26);
  }
  uVar4 = local_26 - uVar4;
  local_26 = uVar4;
  memcpy_bytes_iram(&local_78,param_1,param_2);
  uStack_32 = (undefined1)PTR_DAT_03062e8c[0x12];
  uStack_31 = (undefined1)((ushort)PTR_DAT_03062e8c[0x12] >> 8);
  memcpy_bytes_iram(auStack_30,PTR_DAT_03062e8c + 0x14,8);
  spi_flash_program_pagesplit(uVar2,uVar4 * 0x50 + 0x10,&local_78);
  local_26 = local_26 + 1;
  spi_flash_read_seq(uVar1,0,&local_78,0x10);
  uStack_77 = (undefined1)(local_26 >> 8);
  local_78 = (undefined1)local_26;
  spi_flash_program_pagesplit(uVar2,0,&local_78,0x10);
  flash_page_tag_write(uVar2,1);
  flash_page_tag_write(uVar1,0);
  flash_page_invalidate_range();
  os_sem_post(p_ucos_mutex_0003944c);
  return;
}

