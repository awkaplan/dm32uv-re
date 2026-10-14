/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_task_main_loop @ 0301fe80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_setup_task_main_loop(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_28 [4];
  
  puVar2 = PTR_DAT_0301ff88;
  puVar1 = PTR_DAT_0301ff7c;
  do {
    do {
      *(undefined1 *)puVar2 = 0;
      clear_byte_field_dat03023b88_0x15();
      osflag_pend_consume_with_decisecond_timeout_alt(0x400,0,0,auStack_28);
      os_flag_post_clear_0300c8d4(0x400);
      *(undefined1 *)puVar2 = 1;
      iVar3 = call_setup_ack_retry_and_history_log_loop();
      *(char *)(puVar1 + 3) = (char)iVar3;
    } while (iVar3 != 1);
    ui_mode_group2_flag_set(2,0x10);
  } while( true );
}

