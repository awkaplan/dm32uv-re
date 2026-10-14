/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: recording_count_scan @ 03010cf8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

short recording_count_scan(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  short *psVar3;
  short sVar4;
  short *psVar5;
  
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar2 = flash_page_tag_search(1,0xa5);
  puVar1 = PTR_DAT_03010e04;
  spi_flash_read_seq(uVar2,0,PTR_DAT_03010e04,0xff0);
  psVar5 = PTR_DAT_03010e08;
  if (*puVar1 == -1) {
    sVar4 = 0;
  }
  else {
    sVar4 = 1;
    psVar3 = PTR_DAT_03010e08;
    do {
      if (*psVar3 == -1) {
        if (sVar4 != 0x7f8) goto LAB_03010dac;
        break;
      }
      sVar4 = sVar4 + 1;
      psVar3 = psVar3 + 1;
    } while (sVar4 != 0x7f8);
    uVar2 = flash_page_tag_search(1,0xa6);
    puVar1 = PTR_DAT_03010e04;
    spi_flash_read_seq(uVar2,0,PTR_DAT_03010e04,0xff0);
    if (*puVar1 == -1) {
      sVar4 = 0x7f8;
    }
    else {
      sVar4 = 0x7f9;
      do {
        if (*psVar5 == -1) break;
        sVar4 = sVar4 + 1;
        psVar5 = psVar5 + 1;
      } while (sVar4 != 0xff0);
    }
  }
LAB_03010dac:
  os_sem_post(p_ucos_mutex_0003944c);
  return sVar4;
}

