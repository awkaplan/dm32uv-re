/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_string_wrapped @ 03019d58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 326 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_string_wrapped(int param_1__w,int param_2__w,int param_3)

{
  ushort param_1 = (ushort)param_1__w;
  ushort param_2 = (ushort)param_2__w;
  byte bVar1;
  byte bVar2;
  short sVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  byte local_6c;
  byte bStack_6b;
  
  memset_ck803s(&local_6c,0,0x48);
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  puVar4 = PTR_DAT_03019eb4;
  pbVar5 = (byte *)(param_3 + (uint)*DAT_03019eb0);
LAB_03019e8e:
  do {
    bVar2 = *pbVar5;
    if (bVar2 == 0) {
LAB_03019e94:
      os_sem_post(p_ucos_mutex_00039344);
      return;
    }
    if ((0x80 < bVar2) && (bVar1 = pbVar5[1], 0x80 < bVar1)) {
      if (0x108 < param_1) goto LAB_03019e94;
      if (0xd7 < param_2) {
        param_1 = param_1 + 0x18;
        if (0x108 < param_1) goto LAB_03019e94;
        param_2 = 5;
      }
      local_6c = bVar2;
      bStack_6b = bVar1;
      if (bVar2 < 0xa6) {
        gb2312_glyph_index_lookup1(&local_6c);
      }
      else {
        if (0xf < bVar2) {
          local_6c = bVar2 - 0xf;
        }
        gb2312_glyph_index_lookup2(&local_6c);
      }
      display_draw_glyph_gb2312(param_1,param_2,&local_6c,0xffff,0);
      pbVar5 = pbVar5 + 2;
      param_2 = param_2 + 0x18;
      *(short *)puVar4 = *(short *)puVar4 + 2;
      goto LAB_03019e8e;
    }
    if ((byte)(bVar2 - 0x20) < 0x60) {
      if (0x108 < param_1) goto LAB_03019e94;
      if (0xe3 < param_2) {
        param_1 = param_1 + 0x18;
        if (0x108 < param_1) goto LAB_03019e94;
        param_2 = 5;
      }
      display_draw_glyph_ascii(param_2,param_1,bVar2,0x18,0xffff,0);
      pbVar5 = pbVar5 + 1;
      param_2 = param_2 + 0xc;
      *(short *)puVar4 = *(short *)puVar4 + 1;
    }
    else if (bVar2 == 10) {
      if (0x107 < param_1) {
        *(undefined2 *)PTR_DAT_03019eb4 = *(undefined2 *)PTR_DAT_03019eb8;
        goto LAB_03019e94;
      }
      param_1 = param_1 + 0x18;
      pbVar5 = pbVar5 + 1;
      sVar3 = *(short *)puVar4;
      *(short *)puVar4 = sVar3 + 1;
      *(short *)PTR_DAT_03019eb8 = sVar3 + 1;
      param_2 = 5;
    }
    else {
      if (0xe3 < param_2) {
        if (0x127 < param_1) goto LAB_03019e94;
        param_1 = param_1 + 0x18;
        param_2 = 5;
      }
      display_fill_glyph_cell(param_1,param_2,0);
      pbVar5 = pbVar5 + 1;
      param_2 = param_2 + 0xc;
      *(short *)puVar4 = *(short *)puVar4 + 1;
    }
  } while( true );
}

