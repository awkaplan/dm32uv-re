/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: slottimer_dmr_slot_state @ 0302945c (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void slottimer_dmr_slot_state(void)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  
  pbVar5 = p_dmr_call_config_state;
  puVar4 = PTR_DAT_030294c4;
  puVar3 = PTR_DAT_030294bc;
  do {
    while( true ) {
      do {
        *(undefined1 *)puVar4 = 0;
        mutex_pend_with_timeout_0300c8ec(0);
        *(undefined1 *)puVar4 = 1;
        cVar1 = *(char *)(puVar3 + 1);
        *(char *)(puVar3 + 1) = ~(cVar1 != '\0');
        cVar2 = *(char *)((int)puVar3 + 3);
      } while (cVar2 == '\0');
      if (cVar2 != '\x01') break;
      *(undefined1 *)((int)puVar3 + 3) = 2;
    }
    if (cVar2 == '\x02') {
      *(undefined1 *)((int)puVar3 + 3) = 3;
    }
    else {
      *(undefined1 *)((int)puVar3 + 3) = 0;
      *pbVar5 = ~(cVar1 != '\0');
      modem_set_layer2_mode(0);
    }
  } while( true );
}

