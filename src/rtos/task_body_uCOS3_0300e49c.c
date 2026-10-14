/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: task_body_uCOS3 @ 0300e49c (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void task_body_uCOS3(void)

{
  void *flaggrp;
  void *pvVar1;
  byte bVar2;
  undefined1 auStack_28 [4];
  
  flaggrp = p_ucos_flaggrp_0003a4f0;
  do {
    pvVar1 = flaggrp;
    OSFlagPend_wrapper_consume(flaggrp,0xc000,0,0,auStack_28);
    if (((uint)pvVar1 & 0x4000) != 0) {
      OSFlagPost_wrapper_clr(flaggrp,0x4000);
    }
    if (((uint)pvVar1 & 0x8000) != 0) {
      OSFlagPost_wrapper_clr(flaggrp,0x8000);
      fd6818b_reg_write(FD6818_PAGE0_REG_02H,0);
      fd6818_reg_read(FD6818_PAGE0_REG_02H);
      if ((p_radio_mode_state_0003e318[2].field_0x1 & 0x80) == 0) {
        bVar2 = p_vfo_display_state->field_0x16 & 0xe;
        if (bVar2 == 8) {
          uart_rx_frame_assemble_polarity_correct();
        }
        else if (((bVar2 == 2) || (bVar2 == 6)) || (bVar2 == 4)) {
          circular_buffer_append_3bit_status();
        }
      }
    }
  } while( true );
}

