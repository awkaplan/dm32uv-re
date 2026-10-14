/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_state_machine_step_with_timeout @ 03020f70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 226 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int call_setup_state_machine_step_with_timeout(void)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iStack_18;
  char cStack_11;
  
  iVar2 = call_setup_state_machine_step(3,p_call_setup_sm_state_aux->field_0x8,&cStack_11);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else if (cStack_11 == '\x01') {
    iVar2 = FUN_030273f4();
    if (iVar2 == 0) {
      if (*(int *)&p_call_setup_sm_state->field_0xc_0 - 0xfffff0U < 0x10) {
        iVar2 = 7;
      }
      else {
        iVar2 = FUN_03023ae8();
        if ((iVar2 == 0) && (*(int *)&p_call_setup_sm_state->field_0xc_0 == 0xff)) {
          iVar2 = 7;
        }
        else {
          os_flag_post_clear_0300c784(0x20000200);
          FUN_03029ce8();
          *(undefined1 *)p_call_setup_sm_state = 2;
          puVar1 = PTR_DAT_0302104c;
          PTR_DAT_0302104c[5] = 1;
          uVar3 = osflag_pend_consume_with_decisecond_timeout(0x20000200,0,3000,&iStack_18);
          puVar1[5] = 0;
          iVar2 = noop_stub_0300c42c();
          if (iVar2 == iStack_18) {
            iVar2 = 7;
          }
          else {
            iVar2 = noop_stub_0300c434();
            if (iVar2 == iStack_18) {
              if ((uVar3 & 0x20000000) == 0) {
                if ((uVar3 & 0x200) != 0) {
                  iVar2 = 0;
                }
              }
              else if ((p_call_setup_sm_state->field_0x9 & 0x30) == 0x10) {
                iVar2 = 0;
              }
              else {
                iVar2 = 7;
              }
            }
          }
        }
      }
    }
  }
  else {
    iVar2 = 1;
  }
  return iVar2;
}

