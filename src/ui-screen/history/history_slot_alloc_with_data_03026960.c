/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_slot_alloc_with_data @ 03026960 (file base 0x03000000; code starts at 0x03001000)
 * Size: 144 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 history_slot_alloc_with_data(char *param_1)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = history_slot_allocate();
  if (iVar2 == 0) {
    OSTimeDly_ms_wrapper(0x3c);
    iVar2 = history_slot_allocate();
    if (iVar2 == 0) {
      return 1;
    }
  }
  *(undefined1 *)(iVar2 + 2) = 0;
  *(undefined1 *)(iVar2 + 3) = 2;
  memset_bytes(iVar2 + 5,0,0x18);
  *(undefined1 *)(iVar2 + 5) = 0x30;
  *(undefined1 *)(iVar2 + 6) = 0;
  *(char *)(iVar2 + 7) = (char)*(undefined2 *)(param_1 + 0x2a);
  *(char *)(iVar2 + 8) = (char)((uint)*(undefined4 *)(param_1 + 0x28) >> 8);
  *(char *)(iVar2 + 9) = (char)*(undefined4 *)(param_1 + 0x28);
  *(char *)(iVar2 + 10) = (char)*(undefined2 *)(param_1 + 0x2e);
  *(char *)(iVar2 + 0xb) = (char)((uint)*(undefined4 *)(param_1 + 0x2c) >> 8);
  *(char *)(iVar2 + 0xc) = (char)*(undefined4 *)(param_1 + 0x2c);
  cVar1 = *param_1;
  *(char *)(iVar2 + 0xd) = cVar1 << 7;
  bVar3 = param_1[1] << 6 | cVar1 << 7;
  *(byte *)(iVar2 + 0xd) = bVar3;
  bVar3 = bVar3 | param_1[0x1c] << 5;
  *(byte *)(iVar2 + 0xd) = bVar3;
  bVar3 = param_1[0x12] << 3 | bVar3;
  *(byte *)(iVar2 + 0xd) = bVar3;
  *(byte *)(iVar2 + 0xd) = bVar3 | param_1[0x13] & 7U;
  history_slot_link_append(iVar2);
  return 0;
}

