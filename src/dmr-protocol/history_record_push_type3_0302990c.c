/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_record_push_type3 @ 0302990c (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void history_record_push_type3(void *record)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = history_slot_allocate();
  if (iVar2 == 0) {
    OSTimeDly_ms_wrapper(0x46);
    iVar2 = history_slot_allocate();
    if (iVar2 == 0) {
      return;
    }
  }
  *(undefined1 *)(iVar2 + 2) = 0;
  *(undefined1 *)(iVar2 + 3) = 3;
  memset_bytes(iVar2 + 5,0,0x18);
  uVar3 = *(byte *)record - 4 & 0xff;
  if (0x39 < uVar3) {
    history_slot_link_append(iVar2);
    if ((p_call_setup_sm_state_aux->mode_0x1 == 4) &&
       ((((cVar1 = *(char *)record, cVar1 == '\x04' || (cVar1 == '\'')) || (cVar1 == '\x1f')) ||
        ((cVar1 == '\x1d' || ((cVar1 == '$' && (-1 < *(char *)((int)record + 7))))))))) {
      history_record_push();
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x03029950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(PTR_PTR_03029968[uVar3] & 0xfffffffe))();
  return;
}

