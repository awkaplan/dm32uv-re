/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_record_table_reclaim_or_count_empty @ 03058a0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_record_table_reclaim_or_count_empty(void)

{
  undefined *puVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  char acStack_3c [21];
  char acStack_27 [3];
  
  OSSemCreate_shared_name_wrapper(p_ucos_mutex_000334c4,1);
  puVar1 = PTR_LAB_03058a84;
  iVar4 = 0;
  piVar5 = PTR_LAB_03058a8c;
  do {
    flash_field_read_cached(puVar1[iVar4],0,acStack_3c,0x17);
    cVar2 = '\0';
    pcVar3 = acStack_3c;
    do {
      if (*pcVar3 == '\0') {
        cVar2 = cVar2 + '\x01';
      }
      pcVar3 = pcVar3 + 1;
    } while (pcVar3 != acStack_27);
    if (cVar2 == '\0') {
      *(undefined1 *)(*piVar5 + 4) = 0;
      flash_record_erase_and_clear_cache(iVar4 + 1);
    }
    else {
      *(char *)(*piVar5 + 4) = cVar2 + -1;
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar4 != 3);
  return;
}

