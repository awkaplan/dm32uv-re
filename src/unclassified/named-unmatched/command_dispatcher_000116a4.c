/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: command_dispatcher @ 000116a4 (IRAM address; the boot stub copies these bytes from program flash 0x030c12c4)
 * Size: 318 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void command_dispatcher(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined1 auStack_8 [4];
  
  puVar4 = *(uint **)PTR_DAT_00011808;
  uVar2 = *puVar4;
  if (uVar2 == uRam0001180c) {
    ucos_event_flag_ready_bits_dispatch
              (puVar4[2],puVar4[3],(short)puVar4[4],(short)puVar4[6],puVar4[7],auStack_8);
  }
  else if (uRam0001180c < uVar2) {
    if (uVar2 == uRam0001181c) {
      radio_command_dispatcher(puVar4[2],auStack_8);
    }
    else if (uRam0001181c < uVar2) {
      if (uVar2 == uRam00011824) {
        active_command_subcommand_dispatcher(puVar4[2],auStack_8);
      }
      else if (uVar2 == uRam00011828) {
        func_0x0306a750(puVar4[2],puVar4[3],(short)puVar4[4],(short)puVar4[6],puVar4[7],auStack_8);
      }
    }
    else if (uVar2 == uRam00011820) {
      ucos3_task_timeout_requeue(PTR_OSRdyList_000117f4 + (uint)(byte)*PTR_DAT_00011800 * 0xc);
      OS_TaskSemPost(PTR_DAT_0001182c,0,*(undefined4 *)(*(int *)PTR_DAT_00011808 + 0x1c),auStack_8);
      iVar3 = *(int *)PTR_DAT_00011830;
      *(int *)PTR_DAT_00011830 = iVar3 + -1;
      if (iVar3 + -1 == 0) {
        *(undefined4 *)PTR_DAT_00011830 = *(undefined4 *)PTR_OSPrioCur_00011834;
        uVar1 = func_0x0306ced4();
        OS_TaskSemPost(PTR_DAT_00011838,0,uVar1,auStack_8);
      }
    }
  }
  else if (uVar2 == uRam00011810) {
    func_0x030690e4(puVar4[2],puVar4[5],(short)puVar4[6],puVar4[7],auStack_8);
  }
  else if (uVar2 == uRam00011814) {
    OS_TaskSemPost(puVar4[2],(short)puVar4[6],puVar4[7],auStack_8);
  }
  else if (uVar2 == uRam00011818) {
    OS_SemPost(puVar4[2],(short)puVar4[6],puVar4[7],auStack_8);
  }
  return;
}

