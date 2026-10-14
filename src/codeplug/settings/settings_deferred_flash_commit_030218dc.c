/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_deferred_flash_commit @ 030218dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_deferred_flash_commit(void)

{
  undefined4 *puVar1;
  
  if ((*(byte *)PTR_DAT_030219f4 & 1) != 0) {
    FUN_000160b0();
    if ((*(byte *)PTR_DAT_030219fc & 0x10) != 0) {
      voice_record_direction_select(0);
      write_byte_field_030212e4(5);
      puVar1 = PTR_DAT_03021a00;
      if ((*(byte *)((int)PTR_DAT_03021a00 + 0x2b) & 4) != 0) {
        flash_write_split_across_page_boundary(PTR_DAT_03021a00[2],0x12,_DAT_03021a04,2);
        mutex_guarded_param_dispatch_3(puVar1[3],*(undefined2 *)((int)puVar1 + 2));
        *(byte *)((int)puVar1 + 0x2b) = *(byte *)((int)puVar1 + 0x2b) & 0xfb;
      }
    }
    *(byte *)PTR_DAT_030219f4 = *(byte *)PTR_DAT_030219f4 & 0xfe;
  }
  return;
}

