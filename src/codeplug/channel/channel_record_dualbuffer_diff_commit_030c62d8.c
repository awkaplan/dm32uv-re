/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_record_dualbuffer_diff_commit @ 030c62d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 374 bytes
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

void channel_record_dualbuffer_diff_commit(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  
  puVar2 = PTR_DAT_030c6450;
  channel_record_commit_step_with_fixedpoint_scale
            (PTR_DAT_030c6450 + 0xc4c,(int)(short)PTR_DAT_030c6450[0xb9b],
             PTR_DAT_030c6450 + (short)PTR_DAT_030c6450[0xc4b] + 0xbaa,0x50,0x800,0,
             (int)(short)PTR_DAT_030c6450[0xb9d],PTR_DAT_030c6450);
  channel_record_commit_step_with_fixedpoint_scale
            (puVar2 + 0xc4c,(int)(short)puVar2[0xb9b],puVar2 + (short)puVar2[0xc4b] + 0xbaa,0x50,
             0x800,1,(int)(short)puVar2[0xb9d],puVar2);
  puVar4 = puVar2 + 0xc4c;
  do {
    *puVar4 = *puVar4 ^ puVar4[0x48];
    puVar4 = puVar4 + 1;
  } while (puVar4 != puVar2 + 0xc7d);
  if ((*(char *)((int)puVar2 + 0x19d5) == '\0') || (*(char *)(PTR_DAT_030c6450 + 0xceb) == '\0')) {
    channel_list_string_render_field
              (_DAT_030c6454,_DAT_030c6454,(int)(short)puVar2[0xb9c],_DAT_030c6454 + -0x1b8);
  }
  puVar3 = PTR_DAT_030c6450;
  func_0x030de0b4((int)puVar2 + *(byte *)((int)puVar2 + 0x19d3) + 0x19b8,PTR_DAT_030c6450 + 0xc4c,
                  0x48);
  sVar1 = puVar2[0xb9a];
  *(char *)((int)puVar2 + 0x19d3) = *(char *)((int)puVar2 + 0x19d3) + '\t';
  puVar2[0xb9a] = sVar1 + 1;
  if (2 < (short)(sVar1 + 1)) {
    if (*(char *)((int)puVar3 + 0x19d5) == '\x01') {
      func_0x030de178();
      *(undefined1 *)((int)puVar3 + 0x19d3) = 0;
      puVar3[0xb9a] = 0;
    }
    else {
      FUN_030c6f18(0,puVar3 + 0xcdc,0x1b);
      *(undefined1 *)((int)puVar3 + 0x19d3) = 0;
      puVar3[0xb9a] = 0;
    }
    if (*(char *)(puVar2 + 0xcea) == '\x01') {
      if (*(char *)((int)PTR_DAT_030c6450 + 0x19d5) != '\x01') {
        func_0x030de178();
      }
    }
  }
  return;
}

