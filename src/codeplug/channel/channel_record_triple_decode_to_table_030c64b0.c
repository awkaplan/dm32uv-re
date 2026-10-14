/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_record_triple_decode_to_table @ 030c64b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 306 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_record_triple_decode_to_table(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  undefined1 auStack_b4 [144];
  
  puVar3 = PTR_DAT_030c65ec;
  PTR_DAT_030c65ec[0x8aa] = PTR_DAT_030c65ec[0x8a9];
  func_0x030de010(auStack_b4,param_1,0x48);
  puVar4 = PTR_DAT_030c65f0;
  puVar6 = puVar3 + 0x7e8;
  bVar2 = *(byte *)PTR_DAT_030c65f0;
  uVar5 = vocoder_frame_params_decode
                    (auStack_b4,(int)(short)puVar3[0x8b4],auStack_b4,1,(int)(short)puVar3[0x8aa],
                     puVar6);
  bVar1 = *(byte *)puVar4;
  puVar3[(uint)bVar2 * 3 + 0x8ab] = uVar5;
  channel_record_copy_0x34(puVar3 + (uint)bVar1 * 0x4e + 0x80c,puVar6);
  func_0x030de0b4(param_1,auStack_b4,0x31);
  func_0x030de010(auStack_b4,param_1 + 9,0x48);
  bVar2 = *(byte *)puVar4;
  uVar5 = vocoder_frame_params_decode
                    (auStack_b4,(int)(short)puVar3[0x8b4],auStack_b4,1,(int)(short)puVar3[0x8aa],
                     puVar6);
  bVar1 = *(byte *)puVar4;
  puVar3[(uint)bVar2 * 3 + 0x8ac] = uVar5;
  channel_record_copy_0x34(puVar3 + (uint)bVar1 * 0x4e + 0x826,puVar6);
  func_0x030de0b4(param_1 + 9,auStack_b4,0x31);
  func_0x030de010(auStack_b4,param_1 + 0x12,0x48);
  bVar2 = *(byte *)puVar4;
  uVar5 = vocoder_frame_params_decode
                    (auStack_b4,(int)(short)puVar3[0x8b4],auStack_b4,1,(int)(short)puVar3[0x8aa],
                     puVar6);
  bVar1 = *(byte *)puVar4;
  puVar3[(uint)bVar2 * 3 + 0x8ad] = uVar5;
  channel_record_copy_0x34(puVar3 + (uint)bVar1 * 0x4e + 0x840,puVar6);
  func_0x030de0b4(param_1 + 0x12,auStack_b4,0x31);
  return;
}

