/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_flash_log_append_2byte @ 030105d0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 174 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-spi
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_log_append_2byte(undefined4 param_1)

{
  undefined2 uVar1;
  short sVar2;
  short sVar3;
  char *pcVar4;
  short sVar5;
  char *pcVar6;
  undefined1 local_18;
  undefined1 uStack_17;
  
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar1 = flash_page_tag_search(1,0xa5);
  pcVar4 = PTR_DAT_030107cc;
  spi_flash_read_seq(uVar1,0,PTR_DAT_030107cc,0xff0);
  sVar2 = 0;
  pcVar6 = pcVar4;
  do {
    if ((*pcVar6 == -1) && (pcVar6[1] == -1)) {
      sVar5 = sVar2;
      if (sVar2 != 0xff0) goto LAB_0301065e;
      goto LAB_03010624;
    }
    sVar2 = sVar2 + 2;
    pcVar6 = pcVar6 + 2;
  } while (sVar2 != 0xff0);
  sVar2 = 0;
LAB_03010624:
  uVar1 = flash_page_tag_search(1,0xa6);
  spi_flash_read_seq(uVar1,0,PTR_DAT_030107cc,0xff0);
  sVar3 = 0;
  do {
    if ((*pcVar4 == -1) && (sVar5 = sVar3, pcVar4[1] == -1)) break;
    sVar3 = sVar3 + 2;
    pcVar4 = pcVar4 + 2;
    sVar5 = sVar2;
  } while (sVar3 != 0xff0);
LAB_0301065e:
  local_18 = (undefined1)param_1;
  uStack_17 = (undefined1)((uint)param_1 >> 8);
  spi_flash_program_pagesplit(uVar1,sVar5,&local_18,2);
  os_sem_post(p_ucos_mutex_0003944c);
  return;
}

