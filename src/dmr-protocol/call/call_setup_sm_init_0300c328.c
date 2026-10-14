/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_sm_init @ 0300c328 (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_setup_sm_init(void)

{
  undefined4 *puVar1;
  call_setup_sm_state_aux *pcVar2;
  
  puVar1 = PTR_DAT_0300c3dc;
  PTR_DAT_0300c3dc[1] = _DAT_0300c3e0;
  puVar1[2] = _DAT_0300c3e4;
  *(undefined1 *)puVar1 = 1;
  puVar1[4] = _DAT_0300c3e8;
  puVar1[5] = _DAT_0300c3ec;
  *(undefined1 *)(puVar1 + 3) = 1;
  puVar1[7] = _DAT_0300c3f0;
  puVar1[8] = _DAT_0300c3f4;
  *(undefined1 *)(puVar1 + 6) = 1;
  puVar1[10] = _DAT_0300c3f8;
  puVar1[0xb] = _DAT_0300c3fc;
  *(undefined1 *)(puVar1 + 9) = 1;
  puVar1[0xd] = _DAT_0300c400;
  puVar1[0xe] = _DAT_0300c404;
  *(undefined1 *)(puVar1 + 0xc) = 1;
  memset_bytes(puVar1 + 0x12,0,6);
  *(undefined1 *)(puVar1 + 0x1c) = 5;
  *(undefined1 *)((int)puVar1 + 0x71) = 0;
  *(undefined1 *)(puVar1 + 0x1d) = 0;
  puVar1[0x1e] = 0;
  memset_bytes((int)puVar1 + 0x4e,0,0x22);
  *(undefined1 *)((int)puVar1 + 0x4e) = 1;
  *(undefined1 *)((int)puVar1 + 0x4f) = 2;
  *(undefined1 *)((int)puVar1 + 0x73) = 1;
  *(undefined1 *)((int)puVar1 + 0x72) = 1;
  pcVar2 = p_call_setup_sm_state_aux;
  p_call_setup_sm_state_aux->field_0x4 = 1;
  pcVar2->field_0x3 = 1;
  return;
}

