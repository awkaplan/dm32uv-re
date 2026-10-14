/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_stop @ 03023428 (file base 0x03000000; code starts at 0x03001000)
 * Size: 168 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void modem_stop(void)

{
  dword dVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((p_call_setup_sm_state->field_0x1 != 0) || ((*(byte *)p_call_active_flag & 1) != 0)) {
    OSFlagPost_wrapper_set_fixed_grp(4);
  }
  dmr_call_config_reset_and_flag();
  modem_control_state_stop();
  puVar2 = PTR_DAT_03023564;
  PTR_DAT_03023564[0x10] = 0;
  puVar2[0x11] = 0;
  *(undefined1 *)PTR_DAT_03023568 = 0;
  p_call_setup_sm_state->field_0x1 = 0;
  puVar3 = PTR_DAT_0302356c;
  *(undefined1 *)PTR_DAT_0302356c = 0;
  PTR_DAT_03023570[4] = 0;
  *(byte *)((int)puVar3 + 3) = *(byte *)((int)puVar3 + 3) & 0xfc;
  memset_bytes((int)puVar3 + 5,0,0x20);
  memset_bytes(puVar2 + 0x88,0,0x1b);
  memset_bytes(puVar2 + 0xa3,0,0x1b);
  iVar4 = DAT_03023574;
  memset_bytes(DAT_03023574,0,0x1b);
  memset_bytes(iVar4 + 0x1b,0,0x1b);
  dVar1 = SystemControl_Type_11000000.LAYER2_SLOTON;
  SystemControl_Type_11000000.LAYER2_SLOTON = dVar1 & 2;
  dVar1 = SystemControl_Type_11000000.LAYER2_TXRX_CTRL;
  SystemControl_Type_11000000.LAYER2_TXRX_CTRL = dVar1 | 0x800000;
  dVar1 = SystemControl_Type_11000000.LAYER2_TXRX_CTRL;
  SystemControl_Type_11000000.LAYER2_TXRX_CTRL = dVar1 | 0x400000;
  modem_set_mode_variant();
  noop_stub_0300c0ec();
  return;
}

