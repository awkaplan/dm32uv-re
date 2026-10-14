/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_block_command_dispatch @ 030c12c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 318 bytes
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

void settings_block_command_dispatch(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined1 auStack_8 [4];
  
  puVar4 = (uint *)*PTR_DAT_030c1428;
  uVar2 = *puVar4;
  if (uVar2 == _DAT_030c142c) {
    OS_TaskQPost(puVar4[2],puVar4[3],(short)puVar4[4],(short)puVar4[6],puVar4[7],auStack_8);
  }
  else if (_DAT_030c142c < uVar2) {
    if (uVar2 == _DAT_030c143c) {
      command_jump_table_dispatch(puVar4[2],auStack_8);
    }
    else if (_DAT_030c143c < uVar2) {
      if (uVar2 == _DAT_030c1444) {
        radio_command_jumptable_dispatch_flash(puVar4[2],auStack_8);
      }
      else if (uVar2 == _DAT_030c1448) {
        func_0x0611a370(puVar4[2],puVar4[3],(short)puVar4[4],(short)puVar4[6],puVar4[7],auStack_8);
      }
    }
    else if (uVar2 == _DAT_030c1440) {
      activity_timer_handle_dispatch_complete
                (PTR_OSRdyList_030c1414 + (uint)*(byte *)PTR_DAT_030c1420 * 6);
      OS_TaskSemPost_variant3(_DAT_030c144c,0,*(undefined4 *)(*PTR_DAT_030c1428 + 0x1c),auStack_8);
      iVar3 = *PTR_DAT_030c1450;
      *PTR_DAT_030c1450 = iVar3 + -1;
      if (iVar3 + -1 == 0) {
        *PTR_DAT_030c1450 = *PTR_OSPrioCur_030c1454;
        uVar1 = func_0x0611caf4();
        OS_TaskSemPost_variant3(_DAT_030c1458,0,uVar1,auStack_8);
      }
    }
  }
  else if (uVar2 == _DAT_030c1430) {
    func_0x06118d04(puVar4[2],puVar4[5],(short)puVar4[6],puVar4[7],auStack_8);
  }
  else if (uVar2 == _DAT_030c1434) {
    OS_TaskSemPost_variant3(puVar4[2],(short)puVar4[6],puVar4[7],auStack_8);
  }
  else if (uVar2 == _DAT_030c1438) {
    OS_SemPost_variant2(puVar4[2],(short)puVar4[6],puVar4[7],auStack_8);
  }
  return;
}

