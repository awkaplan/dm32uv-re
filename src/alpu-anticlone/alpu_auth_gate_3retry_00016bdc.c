/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_auth_gate_3retry @ 00016bdc (IRAM address; the boot stub copies these bytes from program flash 0x030c67fc)
 * Size: 148 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: alpu-anticlone
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void alpu_auth_gate_3retry(undefined1 *param_1)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  
  puVar5 = auStack_28;
  do {
    uVar2 = alpu_nonce_byte_next();
    *puVar5 = uVar2;
    puVar5 = puVar5 + 1;
  } while (puVar5 != &stack0xffffffe0);
  iVar3 = alpu_handshake_step_sequence(auStack_28,auStack_30);
  iVar1 = iRam00016c70;
  *(char *)(iRam00016c70 + 0x24) = (char)iVar3;
  puVar5 = auStack_28;
  if (iVar3 != 0) {
    do {
      uVar2 = alpu_nonce_byte_next();
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
    } while (&stack0xffffffe0 != puVar5);
    iVar3 = alpu_handshake_step_sequence(auStack_28,auStack_30);
    *(char *)(iVar1 + 0x24) = (char)iVar3;
    puVar5 = auStack_28;
    if (iVar3 != 0) {
      do {
        uVar2 = alpu_nonce_byte_next();
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
      } while (&stack0xffffffe0 != puVar5);
      iVar3 = alpu_handshake_step_sequence(auStack_28,auStack_30);
      *(char *)(iVar1 + 0x24) = (char)iVar3;
      if (iVar3 != 0) {
        *param_1 = 0x10;
        modem_workmode_rfmode_reload();
        uVar4 = func_0x0306fea4();
        uVar4 = (uVar4 & 7) - 1;
        if (6 < uVar4) {
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
                    /* WARNING: Could not recover jumptable at 0x00016c6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(uint *)(iRam00016c74 + uVar4 * 4) & 0xfffffffe))();
        return;
      }
    }
  }
  return;
}

