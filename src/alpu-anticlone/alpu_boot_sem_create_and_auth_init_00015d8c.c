/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: alpu_boot_sem_create_and_auth_init @ 00015d8c (IRAM address; the boot stub copies these bytes from program flash 0x030c59ac)
 * Size: 120 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: alpu-anticlone
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void alpu_boot_sem_create_and_auth_init(undefined1 *param_1)

{
  int iStack_10;
  
  OSSemCreate(uRam00015ed4,uRam00015ed0,0,&iStack_10);
  if (iStack_10 != 0) {
    *param_1 = 1;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  OSSemCreate(uRam00015ed8,uRam00015edc,0,&iStack_10);
  if (iStack_10 != 0) {
    *param_1 = 2;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  OSSemCreate(uRam00015ee0,uRam00015ee4,0,&iStack_10);
  if (iStack_10 != 0) {
    *param_1 = 3;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  func_0x00017270();
  func_0x000141c8();
  func_0x000169d8();
  alpu_auth_gate_3retry(param_1);
  func_0x00014164(param_1);
  alpu_auth_gate_3retry(param_1);
  func_0x000162a8(param_1);
  modem_workmode_rfmode_reload();
  return;
}

