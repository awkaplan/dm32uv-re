/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_setup_state_machine_task @ 0301e9cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 216 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0301eb2c) */
/* WARNING: Removing unreachable block (ram,0x0301eb58) */
/* WARNING: Removing unreachable block (ram,0x0301eb30) */
/* WARNING: Removing unreachable block (ram,0x0301eb3c) */
/* WARNING: Removing unreachable block (ram,0x0301eb40) */
/* WARNING: Removing unreachable block (ram,0x0301eb34) */
/* WARNING: Removing unreachable block (ram,0x0301eb48) */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_call_setup_state_machine_task(void)

{
  call_setup_sm_state *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_28 [4];
  
  puVar5 = PTR_DAT_0301ea78;
  puVar4 = PTR_DAT_0301ea74;
  iVar3 = DAT_0301ea70;
  puVar2 = PTR_DAT_0301ea6c;
  pcVar1 = p_call_setup_sm_state;
  do {
    iVar6 = osflag_pend_consume_generic(3,0,0,auStack_28);
    if (iVar6 == 1) {
      *puVar2 = (uint)*(byte *)(iVar3 + 0x58);
      os_flag_post_clear_0300c8d8(1);
      if (((byte)*puVar4 < 4) && ((*puVar5 & 0x40) != 0)) {
        *puVar5 = *puVar5 & 0xbf;
        if (puVar5[3] == '\x06') {
          pcVar1->flags_0x18 = pcVar1->flags_0x18 & 0xef | 0x10;
        }
        dialog_state_set_substate(2);
        OSTimeDly_ms_wrapper(0x3c);
      }
      uVar7 = (uint)(byte)*puVar4;
      if (uVar7 < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x0301ea58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(PTR_PTR_0301ea80[uVar7] & 0xfffffffe))();
        return;
      }
    }
    if (iVar6 == 2) {
      os_flag_post_clear_0300c8d8(2);
      dmr_ber_frame_compare_and_report();
    }
  } while( true );
}

