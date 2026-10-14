/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_signaling_param_struct_defaults_init @ 030c6c10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 486 bytes
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

void channel_signaling_param_struct_defaults_init(int param_1,short param_2,short param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  
  if (param_3 != 0) {
    u16_buffer_fill_memset(param_1,0,0xb70);
    u16_buffer_fill_memset(param_1 + 0x1170,0xfffffff1,7);
    *(undefined2 *)(param_1 + 0x630) = 0x2aab;
    *(undefined2 *)(param_1 + 0x634) = 0x147b;
    *(undefined2 *)(param_1 + 0x632) = 0x147b;
    iVar2 = 0;
    *(undefined2 *)(param_1 + 0x63a) = 0x1000;
    *(undefined2 *)(param_1 + 0x644) = 0x7fff;
    *(undefined2 *)(param_1 + 0x63c) = 0x1000;
    *(undefined2 *)(param_1 + 0x646) = 0x7fff;
    *(undefined2 *)(param_1 + 0x63e) = 0x1000;
    *(undefined2 *)(param_1 + 0x648) = 0x7fff;
    *(undefined2 *)(param_1 + 0x640) = 0x1000;
    *(undefined2 *)(param_1 + 0x64a) = 0x7fff;
    *(undefined2 *)(param_1 + 0x642) = 0x1000;
    *(undefined2 *)(param_1 + 0x64c) = 0x7fff;
    puVar3 = (undefined2 *)(param_1 + 0x6ee);
    do {
      u16_buffer_fill_memset(param_1 + 0x69e + iVar2,1,8);
      *puVar3 = 0xffe2;
      u16_buffer_fill_memset(param_1 + 0x64e + iVar2,3,8);
      iVar2 = iVar2 + 0x10;
      puVar3 = puVar3 + 1;
    } while (iVar2 != 0x50);
    iVar2 = 0;
    puVar3 = (undefined2 *)(param_1 + 0x70a);
    do {
      *puVar3 = 0xffe2;
      u16_buffer_fill_memset(param_1 + 0x710 + iVar2,0x7fff,8);
      iVar2 = iVar2 + 0x10;
      puVar3 = puVar3 + 1;
    } while (iVar2 != 0x30);
    *(short *)(param_1 + 0x98a) = (short)_DAT_030c6df8;
    *(short *)(param_1 + 0x98c) = (short)_DAT_030c6dfc;
    *(short *)(param_1 + 0x98e) = (short)_DAT_030c6e00;
    *(short *)(param_1 + 0x990) = (short)_DAT_030c6e04;
    *(short *)(param_1 + 0x992) = (short)_DAT_030c6e08;
    *(short *)(param_1 + 0x994) = (short)_DAT_030c6e0c;
    u16_buffer_fill_memset(param_1 + 0x996,_DAT_030c6e10,10);
    u16_buffer_fill_memset(param_1 + 0x9aa,5,0x10);
    u16_buffer_fill_memset(param_1 + 0x9ca,0x7fff,0x10);
    u16_buffer_fill_memset(param_1 + 0x9ea,5,0x10);
    u16_buffer_fill_memset(param_1 + 0xa0a,300,0x10);
    *(short *)(param_1 + 0x980) = (short)_DAT_030c6e14;
    *(short *)(param_1 + 0x988) = (short)_DAT_030c6e18;
    *(undefined4 *)(param_1 + 0x978) = 0xfa000;
    *(short *)(param_1 + 0xa72) = (short)_DAT_030c6e1c;
    *(undefined2 *)(param_1 + 0xa74) = 20000;
    *(undefined2 *)(param_1 + 0xa76) = 0xfff0;
    *(undefined2 *)(param_1 + 0x986) = 300;
    u16_buffer_fill_memset(param_1 + 0xa78,0,0x10);
    u16_buffer_fill_memset(param_1 + 0xa98,0xffffffe2,0x10);
    *(undefined2 *)(param_1 + 0x122e) = 0x2000;
    *(undefined2 *)(param_1 + 0xab8) = 0;
    *(undefined2 *)(param_1 + 0xaba) = 0;
    *(undefined2 *)(param_1 + 0x984) = 0;
    *(undefined2 *)(param_1 + 0x986) = 300;
    channel_tx_rx_offset_set(param_1,0x20,0xfffffff6);
    uVar1 = (undefined2)_DAT_030c6e20;
    *(undefined2 *)(param_1 + 0x137e) = uVar1;
    *(undefined2 *)(param_1 + 0x1380) = uVar1;
    *(undefined2 *)(param_1 + 0x1382) = uVar1;
    *(undefined2 *)(param_1 + 0x1384) = uVar1;
    *(undefined2 *)(param_1 + 0x1386) = uVar1;
    *(undefined2 *)(param_1 + 5000) = uVar1;
    *(undefined2 *)(param_1 + 0x1370) = 0;
    channel_signaling_block_16a2_defaults(param_1,0xffffffea,0x14,0xfffffff6);
  }
  signaling_subblock_defaults_init((int)param_2,param_1 + 0x138a,param_1 + 0xabc);
  return;
}

