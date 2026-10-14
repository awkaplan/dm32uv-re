/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: voice_recorder_task @ 030212f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 636 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void voice_recorder_task(void)

{
  char cVar1;
  short sVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined1 uStack_5b;
  undefined1 uStack_5a;
  undefined1 uStack_57;
  byte bStack_54;
  char cStack_53;
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  char cStack_49;
  char cStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 auStack_40 [28];
  
  iVar7 = DAT_030214b8;
  iVar6 = DAT_030214b4;
  iVar5 = DAT_030214b0;
  iVar4 = DAT_030214ac;
  puVar3 = PTR_DAT_030214a8;
LAB_03021306:
  do {
    while( true ) {
      cVar1 = puVar3[1];
      if (((byte)(cVar1 - 1U) < 2) && ((*(byte *)(iVar4 + 0x11) & 0x10) == 0)) break;
      OSTimeDly_ms_wrapper(0x3c);
    }
    if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        func_0x0002e37c(0,auStack_40,0x1b,0x46);
        goto LAB_0302133e;
      }
      break;
    }
    label_table_segment_copy(0,auStack_40,0x1b,0x46);
LAB_0302133e:
  } while (1 < (byte)(puVar3[1] - 1));
  if ((*(byte *)(iVar5 + 0x2b) & 4) == 0) {
    uVar8 = flash_state_and_tag_dispatcher(0);
    *(undefined4 *)(iVar5 + 8) = uVar8;
    flash_mutex_guarded_op();
    channel_bitmap_bit_clear(*(undefined4 *)(iVar5 + 8));
    spi_flash_log_append_2byte(*(undefined4 *)(iVar5 + 8));
    uVar8 = flash_state_and_tag_dispatcher(0);
    *(undefined4 *)(iVar5 + 0xc) = uVar8;
    flash_mutex_guarded_op();
    channel_bitmap_bit_clear(*(undefined4 *)(iVar5 + 0xc));
    *(undefined1 *)(iVar5 + 0x2a) = 0;
    mutex_guarded_param_dispatch_2(*(undefined2 *)(iVar5 + 8),*(undefined2 *)(iVar5 + 0xc),0);
    *(undefined1 *)(iVar5 + 0x2a) = 1;
    *(byte *)(iVar5 + 0x2b) = *(byte *)(iVar5 + 0x2b) & 0xfb | 4;
    *(undefined2 *)(iVar5 + 2) = 0;
    if ((*(byte *)(iVar4 + 0x11) & 0x10) != 0) goto LAB_03021536;
    if (((*(byte *)PTR_call_active_flag_030214bc & 4) == 0) && (puVar3[1] != '\x01')) {
      bStack_54 = 1;
    }
    else {
      bStack_54 = 0;
    }
    if ((PTR_DAT_030214c0[8] & 0xf0) == 0x10) {
      bStack_54 = bStack_54 | 0x10;
    }
    if (PTR_DAT_030214c4[9] == '\x02') {
      cStack_53 = PTR_DAT_030214c4[0x14];
    }
    else {
      cStack_53 = PTR_DAT_030214c4[0x1c];
    }
    cStack_53 = cStack_53 << 4;
    if (puVar3[1] == '\x01') {
      uVar8 = PTR_DAT_030214c8[2];
      uStack_52 = (undefined1)uVar8;
      uStack_51 = (undefined1)((uint)uVar8 >> 8);
      uStack_50 = (undefined1)((uint)uVar8 >> 0x10);
      uVar9 = PTR_DAT_030214c8[1];
      uStack_4f = (undefined1)uVar9;
      uStack_4e = (undefined1)(uVar9 >> 8);
      uStack_4d = (undefined1)(uVar9 >> 0x10);
    }
    else {
      uVar8 = *(undefined4 *)(iVar7 + 0x14);
      uStack_52 = (undefined1)uVar8;
      uStack_51 = (undefined1)((uint)uVar8 >> 8);
      uStack_50 = (undefined1)((uint)uVar8 >> 0x10);
      uVar9 = *(uint *)(iVar7 + 0x10);
      uStack_4f = (undefined1)uVar9;
      uStack_4e = (undefined1)(uVar9 >> 8);
      uStack_4d = (undefined1)(uVar9 >> 0x10);
    }
    uVar9 = uVar9 >> 8;
    uStack_4c = *(undefined1 *)(iVar6 + 0x29);
    uStack_4b = *(undefined1 *)(iVar6 + 0x26);
    uStack_4a = 0;
    uVar8 = rtc_decode_calendar_date();
    uStack_5b = (undefined1)((uint)uVar8 >> 8);
    uStack_5a = (undefined1)((uint)uVar8 >> 0x10);
    uStack_57 = (undefined1)(uVar9 >> 8);
    cStack_48 = (char)(uVar9 / 0x640000);
    cStack_49 = (char)(uVar9 >> 0x10) + cStack_48 * -100;
    uStack_47 = uStack_57;
    uStack_46 = (undefined1)uVar9;
    uStack_45 = (undefined1)uVar8;
    uStack_44 = uStack_5b;
    uStack_43 = uStack_5a;
    flash_write_split_across_page_boundary(*(undefined4 *)(iVar5 + 8),0,&bStack_54,0x12,uVar8,uVar9)
    ;
  }
  else {
    flash_write_split_across_page_boundary
              (*(undefined4 *)(iVar5 + 0xc),*(undefined2 *)(iVar5 + 2),auStack_40,0x1b);
    sVar2 = *(short *)(iVar5 + 2);
    *(short *)(iVar5 + 2) = sVar2 + 0x1b;
    if (0xfd4 < (ushort)(sVar2 + 0x1bU)) {
      mutex_guarded_param_dispatch_3(*(undefined4 *)(iVar5 + 0xc));
      uVar8 = flash_state_and_tag_dispatcher(0);
      *(undefined4 *)(iVar5 + 0xc) = uVar8;
      if ((*(byte *)(iVar5 + 0x2b) & 4) == 0) goto LAB_03021306;
      flash_mutex_guarded_op();
      channel_bitmap_bit_clear(*(undefined4 *)(iVar5 + 0xc));
      mutex_guarded_param_dispatch_2
                (*(undefined2 *)(iVar5 + 8),*(undefined2 *)(iVar5 + 0xc),
                 *(undefined1 *)(iVar5 + 0x2a));
      *(char *)(iVar5 + 0x2a) = *(char *)(iVar5 + 0x2a) + '\x01';
      *(undefined2 *)(iVar5 + 2) = 0;
    }
  }
  if ((*(byte *)(iVar4 + 0x11) & 0x10) == 0) goto LAB_03021306;
LAB_03021536:
  if ((*(byte *)(iVar5 + 0x2b) & 4) != 0) {
    if (puVar3[1] == '\x02') {
      voice_record_direction_select(0);
      write_byte_field_030212e4(5);
    }
    else if (puVar3[1] == '\x01') {
      voice_record_direction_select(0);
      write_byte_field_030212e4(5);
    }
    flash_write_split_across_page_boundary(*(undefined4 *)(iVar5 + 8),0x12,_LAB_03021594,2);
    mutex_guarded_param_dispatch_3(*(undefined4 *)(iVar5 + 0xc),*(undefined2 *)(iVar5 + 2));
    *(byte *)(iVar5 + 0x2b) = *(byte *)(iVar5 + 0x2b) & 0xfb;
  }
  goto LAB_03021306;
}

