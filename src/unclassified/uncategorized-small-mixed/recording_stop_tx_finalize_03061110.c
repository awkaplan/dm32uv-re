/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: recording_stop_tx_finalize @ 03061110 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void recording_stop_tx_finalize(void)

{
  undefined4 *puVar1;
  
  if (((*(byte *)PTR_DAT_0306125c & 0x10) != 0) && (PTR_DAT_03061260[1] == '\x02')) {
    voice_record_direction_select(0);
    write_byte_field_030212e4(5);
    puVar1 = PTR_DAT_03061264;
    if ((*(byte *)((int)PTR_DAT_03061264 + 0x2b) & 4) != 0) {
      flash_write_split_across_page_boundary(PTR_DAT_03061264[2],0x12,DAT_03061268,2);
      mutex_guarded_param_dispatch_3(puVar1[3],*(undefined2 *)((int)puVar1 + 2));
      *(byte *)((int)puVar1 + 0x2b) = *(byte *)((int)puVar1 + 0x2b) & 0xfb;
    }
  }
  return;
}

