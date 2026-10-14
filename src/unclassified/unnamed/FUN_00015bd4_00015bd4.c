/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00015bd4 @ 00015bd4 (IRAM address; the boot stub copies these bytes from program flash 0x030c57f4)
 * Size: 256 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00015bd4(char param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined1 auStack_28 [16];
  
  pcVar3 = param_2 + 0x28;
  func_0x0002f06c(pcVar3,param_2 + 2,0x20);
  cVar1 = *param_2;
  if (cVar1 == '\x01') {
    func_0x0002f06c(param_2 + 0x2d,param_2 + 0x22,4);
    func_0x00014698(param_2 + 0x238,pcVar3,9);
    if (param_1 == '\x01') {
      func_0x000147ac(param_2 + 0x238,param_2 + 0x338,0x7e);
      uVar2 = func_0x00014860(*param_2,param_2 + 0x22);
      func_0x00015b70(uVar2,param_2 + 0x3b8);
    }
  }
  else if (cVar1 == '\x02') {
    func_0x0001d4b8(param_2 + 0x138,pcVar3);
    if (param_1 == '\x01') {
      func_0x0001d3e0(param_2 + 0x22,auStack_28,1);
      func_0x0001d4c4(auStack_28,param_2 + 0x138,param_2 + 0x338);
      uVar2 = func_0x00014860(*param_2,param_2 + 0x22);
      func_0x00015b70(uVar2,param_2 + 0x3b8);
    }
  }
  else {
    if (cVar1 == '\x04') {
      func_0x0001cfac(pcVar3,param_2 + 0x48,4,10);
    }
    else if (cVar1 == '\x05') {
      func_0x0001cfac(pcVar3,param_2 + 0x48,8,0xe);
    }
    if (param_1 == '\x01') {
      func_0x0001d3e0(param_2 + 0x22,auStack_28,3);
      func_0x0001d46c(*param_2,auStack_28,param_2 + 0x48,param_2 + 0x338);
      uVar2 = func_0x00014860(*param_2,param_2 + 0x22);
      func_0x00015b70(uVar2,param_2 + 0x3b8);
      return;
    }
  }
  return;
}

