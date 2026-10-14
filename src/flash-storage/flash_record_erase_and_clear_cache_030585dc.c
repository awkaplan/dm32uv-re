/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_record_erase_and_clear_cache @ 030585dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_record_erase_and_clear_cache(uint param_1)

{
  undefined *puVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  char local_24 [24];
  
  pcVar2 = local_24;
  os_sem_pend_ms(p_ucos_mutex_000334c4,0);
  puVar1 = PTR_LAB_030586dc;
  cVar3 = '\0';
  do {
    *pcVar2 = cVar3;
    cVar3 = cVar3 + '\x01';
    pcVar2 = pcVar2 + 1;
  } while (cVar3 != '\x15');
  iVar4 = (param_1 & 0xff) - 1;
  flash_block_write(PTR_LAB_030586dc[iVar4],0,local_24);
  *(undefined1 *)(*(int *)(puVar1 + iVar4 * 4 + 4) + 4) = 0;
  os_sem_post(p_ucos_mutex_000334c4);
  return;
}

