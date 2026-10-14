/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_event_flag_dispatch_loop @ 0305ee70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 188 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_event_flag_dispatch_loop(void)

{
  void *flaggrp;
  byte bVar1;
  undefined1 auStack_28 [4];
  
  flaggrp = DAT_0305ef2c;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          OSFlagPend_wrapper_consume(flaggrp,1,0,0,auStack_28);
          OSFlagPost_wrapper_clr(flaggrp,1);
          bVar1 = get_event_flags_byte_dispatch(0);
          if ((bVar1 & 1) == 0) break;
          event_flags1_group_dispatch();
          update_event_flags_byte_dispatch(0,1);
        }
        if ((bVar1 & 2) == 0) break;
        event_flags2_group_dispatch();
        update_event_flags_byte_dispatch(0,2);
      }
      if ((bVar1 & 4) == 0) break;
      event_flags9_dispatch_and_name_encode();
      update_event_flags_byte_dispatch(0,4);
    }
    if ((bVar1 & 8) == 0) {
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x20) != 0) {
          ui_key_event_dispatcher();
          update_event_flags_byte_dispatch(0,0x20);
        }
      }
      else {
        event_flags14_dispatch_hw_and_flaggrp();
        update_event_flags_byte_dispatch(0,0x10);
      }
    }
    else {
      event10_flag_dispatch_and_ptt_ui_state();
      update_event_flags_byte_dispatch(0,8);
    }
  } while( true );
}

