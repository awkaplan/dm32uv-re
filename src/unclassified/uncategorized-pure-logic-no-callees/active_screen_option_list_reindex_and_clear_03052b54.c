/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: active_screen_option_list_reindex_and_clear @ 03052b54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void active_screen_option_list_reindex_and_clear(void)

{
  char *pcVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  
  *(undefined2 *)PTR_DAT_03052c7c = 0;
  puVar2 = PTR_DAT_03052c7c;
  piVar3 = (int *)*p_active_screen_option_ptr_array;
  if (*(char *)*piVar3 != '\0') {
    uVar4 = 1;
    do {
      *(short *)puVar2 = (short)uVar4;
      pcVar1 = (char *)(*piVar3 + uVar4);
      uVar4 = uVar4 + 1 & 0xffff;
    } while (*pcVar1 != '\0');
  }
  *(undefined1 *)PTR_DAT_03052c84 = 0;
  *(undefined2 *)PTR_DAT_03052c88 = 0;
  *(undefined2 *)PTR_DAT_03052c8c = 0;
  return;
}

