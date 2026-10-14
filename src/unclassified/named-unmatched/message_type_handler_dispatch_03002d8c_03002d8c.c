/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: message_type_handler_dispatch_03002d8c @ 03002d8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void message_type_handler_dispatch_03002d8c(void)

{
  uint uVar1;
  uint *puVar2;
  undefined1 auStack_8 [4];
  
  puVar2 = (uint *)*PTR_DAT_03002e0c;
  uVar1 = *puVar2;
  if (uVar1 == _DAT_03002e10) {
    func_0x05ff38ac(puVar2[2],puVar2[5],(short)puVar2[6],puVar2[7],auStack_8);
  }
  else if (_DAT_03002e10 < uVar1) {
    if (uVar1 == _DAT_03002e18) {
      OS_TaskSemPost_variant2(puVar2[2],(short)puVar2[6],puVar2[7],auStack_8);
    }
    else if (uVar1 == _DAT_03002e1c) {
      activity_timer_message_dispatch_complete(_DAT_03002e24 + (uint)*_DAT_03002e20 * 0xc);
      OS_TaskSemPost_variant2(_DAT_03002e28,0,*(undefined4 *)(*PTR_DAT_03002e0c + 0x1c),auStack_8);
    }
  }
  else if (uVar1 == _DAT_03002e14) {
    radio_list_command_dispatch_with_iteration(puVar2[2],(short)puVar2[6],puVar2[7],auStack_8);
  }
  return;
}

