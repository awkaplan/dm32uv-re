/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_connect_with_retry @ 0301fed0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 332 bytes
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

undefined4 call_setup_connect_with_retry(void)

{
  call_setup_sm_state *pcVar1;
  call_setup_sm_state_aux *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  int iStack_28;
  
  iVar5 = dmr_call_config_state_not_idle();
  if (iVar5 == 0) {
    uVar7 = 0;
  }
  else {
    iVar6 = dmr_call_config_state_not_idle();
    puVar4 = PTR_DAT_0301ff94;
    iVar3 = _DAT_0301ff90;
    iVar5 = _DAT_0301ff8c;
    pcVar2 = p_call_setup_sm_state_aux;
    pcVar1 = p_call_setup_sm_state;
    if (iVar6 == 1) {
      bVar8 = 0;
      do {
        os_flag_post_clear_0300c784(0x18000000);
        *(byte *)(iVar5 + 7) = *(byte *)(iVar5 + 7) & 0xfd | 2;
        if (((pcVar1->flags_0x19 & 1) != 0) || ((*(byte *)(iVar3 + 5) & 4) != 0)) break;
        history_record_build_type3(0xffffff,*(undefined4 *)&pcVar2->field_0x24_0);
        *(undefined1 *)pcVar1 = 2;
        if ((*(char *)PTR_DAT_0301ff98 != '\0') || ((*puVar4 & 4) == 0)) {
          ui_mode_dispatch(6);
        }
        modem_mode_select(1,2);
        osflag_pend_consume_with_decisecond_timeout(0x10000000,0,300,&iStack_28);
        iVar6 = noop_stub_0300c434();
        if (iVar6 == iStack_28) {
          os_flag_post_clear_0300c784(0x10000000);
          break;
        }
        bVar8 = bVar8 + 1;
      } while (bVar8 != 3);
    }
    else {
      bVar8 = 0;
    }
    PTR_DAT_0302012c[7] = PTR_DAT_0302012c[7] & 0xfd;
    if ((p_call_setup_sm_state->flags_0x19 & 1) == 0) {
      if ((PTR_DAT_03020134[5] & 4) == 0) {
        if (bVar8 < 3) {
          if ((*(char *)PTR_DAT_03020138 == '\0') && ((*(byte *)PTR_DAT_0302013c & 4) != 0)) {
            uVar7 = 0;
          }
          else {
            ui_mode_group2_flag_set(4,4);
            uVar7 = 0;
          }
        }
        else {
          p_call_setup_sm_state->field_0x5 = 0;
          uVar7 = 1;
        }
      }
      else {
        OSFlagPost_wrapper_set_passthrough(0x1000);
        ui_mode_group2_flag_set(4,1);
        p_call_setup_sm_state->field_0x5 = 0;
        uVar7 = 1;
      }
    }
    else {
      OSFlagPost_wrapper_set_passthrough(0x1000);
      ui_mode_group2_flag_set(4,1);
      p_call_setup_sm_state->field_0x5 = 0;
      uVar7 = 1;
    }
  }
  return uVar7;
}

