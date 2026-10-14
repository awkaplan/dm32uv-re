/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_boot_selftest_and_init @ 030c59ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
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

void modem_boot_selftest_and_init(undefined1 *param_1)

{
  int iStack_10;
  
  OSSemCreate_variant2(_DAT_030c5af4,_DAT_030c5af0,0,&iStack_10);
  if (iStack_10 != 0) {
    *param_1 = 1;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  OSSemCreate_variant2(_DAT_030c5af8,_DAT_030c5afc,0,&iStack_10);
  if (iStack_10 != 0) {
    *param_1 = 2;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  OSSemCreate_variant2(_DAT_030c5b00,_DAT_030c5b04,0,&iStack_10);
  if (iStack_10 != 0) {
    *param_1 = 3;
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_030c6e90();
  FUN_030c3de8();
  hr_c7000_modem_core_reinit_sequence();
  vframe_message_poll_and_dispatch_3x(param_1);
  FUN_030c3d84(param_1);
  vframe_message_poll_and_dispatch_3x(param_1);
  modem_codec_pool_and_state_init(param_1);
  FUN_030c66f0();
  return;
}

