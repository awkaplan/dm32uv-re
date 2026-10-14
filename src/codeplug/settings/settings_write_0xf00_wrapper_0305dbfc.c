/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_write_0xf00_wrapper @ 0305dbfc (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_write_0xf00_wrapper(undefined1 param_1)

{
  undefined1 local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  
  local_c = param_1;
  uStack_b = settings_read_dispatcher(6);
  uStack_a = (undefined1)*(undefined2 *)&p_vfo_freq_display_state->field_0x54_0;
  uStack_9 = (undefined1)((ushort)*(undefined2 *)&p_vfo_freq_display_state->field_0x54_0 >> 8);
  flash_block_write(4,0xf00,&local_c,4);
  return;
}

