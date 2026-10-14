/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_ptt_event_task_loop @ 03023044 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dtmf_ptt_event_task_loop(void)

{
  void *flaggrp;
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined1 auStack_20 [4];
  
  puVar2 = PTR_DAT_030230b8;
  puVar1 = PTR_DAT_030230b4;
  flaggrp = DAT_030230b0;
  do {
    while( true ) {
      while( true ) {
        OSFlagPend_wrapper_consume(flaggrp,0x40,0,0,auStack_20);
        OSFlagPost_wrapper_clr(flaggrp,0x40);
        if (*puVar1 != '(') break;
        dtmf_sequence_playback_start();
      }
      if (*puVar1 != ')') break;
      tx_gate_companded_audio_burst_send(*(undefined1 *)puVar2);
    }
    tone_ptt_preamble_seq0();
  } while( true );
}

