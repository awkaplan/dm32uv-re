/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_state_and_tag_dispatcher @ 03010bd4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 258 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint flash_state_and_tag_dispatcher(char param_1)

{
  void *pvVar1;
  undefined2 uVar2;
  uint uVar3;
  char *pcVar4;
  uint unaff_r5;
  char *pcVar5;
  
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  if (param_1 == '\0') {
    unaff_r5 = flash_tagged_record_bitlength_scan();
    if (unaff_r5 == 0) {
      channel_bitmap_flash_rebuild();
      unaff_r5 = flash_tagged_record_bitlength_scan();
    }
    pvVar1 = p_ucos_mutex_0003944c;
    if ((uint)*PTR_DAT_03010cec < unaff_r5) {
      if ((PTR_DAT_03010cf0[0x2b] & 4) != 0) {
        os_sem_post(p_ucos_mutex_0003944c);
        recording_stop_tx_finalize();
        recording_stop_rx_finalize();
        os_sem_pend_ms(pvVar1,0);
      }
      pvVar1 = p_ucos_mutex_0003944c;
      os_sem_post(p_ucos_mutex_0003944c);
      flash_dual_range_invalidate();
      os_sem_pend_ms(pvVar1,0);
      unaff_r5 = flash_tagged_record_bitlength_scan();
    }
  }
  else if (param_1 == '\x01') {
    uVar2 = flash_page_tag_search(1,0xa5);
    pcVar4 = PTR_DAT_03010cf4;
    spi_flash_read_seq(uVar2,0,PTR_DAT_03010cf4,0xff0);
    uVar3 = 0;
    pcVar5 = pcVar4;
    do {
      if ((*pcVar5 == -1) && (pcVar5[1] == -1)) {
        unaff_r5 = uVar3 >> 1;
        if (uVar3 != 0xff0) goto LAB_03010ccc;
        break;
      }
      uVar3 = uVar3 + 2 & 0xffff;
      pcVar5 = pcVar5 + 2;
    } while (uVar3 != 0xff0);
    uVar3 = flash_page_tag_search(1,0xa6);
    unaff_r5 = uVar3 & 0xffff;
    spi_flash_read_seq(unaff_r5,0,PTR_DAT_03010cf4,0xff0);
    uVar3 = 0;
    do {
      if ((*pcVar4 == -1) && (pcVar4[1] == -1)) {
        unaff_r5 = uVar3 + 0xff0 >> 1 & 0x7fff;
        break;
      }
      uVar3 = uVar3 + 2 & 0xffff;
      pcVar4 = pcVar4 + 2;
    } while (uVar3 != 0xff0);
  }
LAB_03010ccc:
  os_sem_post(p_ucos_mutex_0003944c);
  return unaff_r5;
}

