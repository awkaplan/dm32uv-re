/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vframe_message_poll_and_dispatch_3x @ 030c67fc (file base 0x03000000; code starts at 0x03001000)
 * Size: 148 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vframe_message_poll_and_dispatch_3x(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  
  puVar4 = auStack_28;
  do {
    uVar1 = rng_seed_from_fm_voice_bytes();
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  } while (puVar4 != &stack0xffffffe0);
  iVar2 = companion_auth_challenge_response_verify(auStack_28,auStack_30);
  puVar4 = PTR_DAT_030c6890;
  PTR_DAT_030c6890[0x24] = (char)iVar2;
  puVar5 = auStack_28;
  if (iVar2 != 0) {
    do {
      uVar1 = rng_seed_from_fm_voice_bytes();
      *puVar5 = uVar1;
      puVar5 = puVar5 + 1;
    } while (&stack0xffffffe0 != puVar5);
    iVar2 = companion_auth_challenge_response_verify(auStack_28,auStack_30);
    puVar4[0x24] = (char)iVar2;
    puVar5 = auStack_28;
    if (iVar2 != 0) {
      do {
        uVar1 = rng_seed_from_fm_voice_bytes();
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
      } while (&stack0xffffffe0 != puVar5);
      iVar2 = companion_auth_challenge_response_verify(auStack_28,auStack_30);
      puVar4[0x24] = (char)iVar2;
      if (iVar2 != 0) {
        *param_1 = 0x10;
        FUN_030c66f0();
        uVar3 = func_0x0611fac4();
        uVar3 = (uVar3 & 7) - 1;
        if (6 < uVar3) {
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
                    /* WARNING: Could not recover jumptable at 0x030c688c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(PTR_DAT_030c6894[uVar3] & 0xfffffffe))();
        return;
      }
    }
  }
  return;
}

