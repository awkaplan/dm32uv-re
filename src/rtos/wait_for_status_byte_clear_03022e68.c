/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: wait_for_status_byte_clear @ 03022e68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void wait_for_status_byte_clear(int param_1__w)

{
  ushort param_1 = (ushort)param_1__w;
  undefined1 *puVar1;
  ushort uVar2;
  
  puVar1 = PTR_DAT_03022e94;
  if (param_1 != 0) {
    uVar2 = 0;
    do {
      if ((puVar1[1] != '\0') && ((*puVar1 & 1) != 0)) {
        return;
      }
      tx_forbid_flag_clear_call();
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_1);
  }
  return;
}

