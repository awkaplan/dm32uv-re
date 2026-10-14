/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_request_enqueue @ 0301eb70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_request_enqueue(uint request_id,void *arg)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_0301ec0c;
  *(char *)PTR_DAT_0301ec0c = (char)request_id;
  puVar1[1] = arg;
  if ((*(byte *)p_dialog_flags_from_flash & 1) == 0) {
    tx_abort_on_condition();
  }
  OSFlagPost_wrapper_set_fixed_grp_variant_0300c7c0(1);
  return;
}

