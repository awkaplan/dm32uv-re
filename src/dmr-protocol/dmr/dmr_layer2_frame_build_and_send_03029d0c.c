/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_layer2_frame_build_and_send @ 03029d0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool dmr_layer2_frame_build_and_send(int param_1)

{
  dword dVar1;
  int iVar2;
  
  iVar2 = history_slot_allocate();
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 2) = 0;
    *(undefined1 *)(iVar2 + 3) = 3;
    memset_bytes(iVar2 + 5,0,0x18);
    *(undefined1 *)(iVar2 + 5) = 0x9e;
    *(undefined1 *)(iVar2 + 6) = *(undefined1 *)(param_1 + 2);
    *(undefined1 *)(iVar2 + 7) = 2;
    *(undefined1 *)(iVar2 + 8) = 0;
    *(char *)(iVar2 + 9) = (char)*(undefined2 *)(param_1 + 6);
    *(char *)(iVar2 + 10) = (char)((uint)*(undefined4 *)(param_1 + 4) >> 8);
    *(char *)(iVar2 + 0xb) = (char)*(undefined4 *)(param_1 + 4);
    *(char *)(iVar2 + 0xc) = (char)*(undefined2 *)(param_1 + 10);
    *(char *)(iVar2 + 0xd) = (char)((uint)*(undefined4 *)(param_1 + 8) >> 8);
    *(char *)(iVar2 + 0xe) = (char)*(undefined4 *)(param_1 + 8);
    SystemControl_Type_11000000.LAYER2_SEND_TYPE = (uint)*(byte *)(iVar2 + 3) << 4;
    sram_16000000_block_write(0,iVar2 + 5,0x18);
    clear_byte_at_ptr(iVar2);
    dVar1 = SystemControl_Type_11000000.LAYER2_TXRX_CTRL;
    SystemControl_Type_11000000.LAYER2_TXRX_CTRL = dVar1 & 0xffffff3f;
    dVar1 = SystemControl_Type_11000000.LAYER2_TXRX_CTRL;
    SystemControl_Type_11000000.LAYER2_TXRX_CTRL = dVar1 | 0x80;
  }
  return iVar2 == 0;
}

