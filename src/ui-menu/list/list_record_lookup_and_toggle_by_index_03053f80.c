/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_record_lookup_and_toggle_by_index @ 03053f80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 710 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_record_lookup_and_toggle_by_index(int param_1__w,int param_2__w,undefined4 param_3,char *param_4)

{
  byte param_1 = (byte)param_1__w;
  ushort param_2 = (ushort)param_2__w;
  short sVar1;
  ushort block_id;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  ushort uVar6;
  int iStack_34;
  byte bStack_2b;
  byte bStack_2a;
  undefined1 uStack_29;
  byte bStack_28;
  byte bStack_27;
  
  if (param_1 == 3) {
    param_3 = 8;
    param_4 = DAT_030540f0;
  }
  else if (param_1 < 4) {
    if (param_1 == 1) {
      param_3 = 7;
      param_4 = DAT_030540ec;
    }
  }
  else if (param_1 == 4) {
    param_3 = 10;
    param_4 = DAT_030540fc;
  }
  else if (param_1 == 5) {
    param_3 = 9;
    param_4 = DAT_030540f4;
  }
  if (*param_4 != '\0') {
    iVar2 = flash_block_id_resolve_locked(param_3);
    block_id = (ushort)iVar2;
    if (param_1 == 4) {
      sVar1 = ((param_2 & 0xff) - 1) * 0x81;
      flash_block_read(block_id,(uint)(ushort)(sVar1 + 0x10),&bStack_28,1);
      flash_block_read(block_id,(uint)(ushort)(sVar1 + 0x11),p_text_entry_buffer,(uint)bStack_28);
    }
    else {
      uVar3 = dmr_list_header_load(param_1);
      if (uVar3 != 0) {
        uVar6 = 0;
        do {
          flash_block_read(block_id,uVar3 + 0x2f & 0xffff,&bStack_2b,1);
          uVar4 = (uint)bStack_2b;
          if (uVar4 < 0xe) {
            flash_block_read(block_id,(uVar4 - 1) * 0x110 + 0x130 & 0xfff0,&bStack_28,2);
          }
          else {
            contact_char_index_to_display_code(uVar4,param_1,&uStack_29,&bStack_2a);
            iStack_34 = flash_block_id_resolve_locked(uStack_29);
            flash_block_read((ushort)iStack_34,(bStack_2a - 1) * 0x110 & 0xfff0,&bStack_28,2);
          }
          if (((bStack_28 & 1) != 0) && (uVar6 = uVar6 + 1 & 0xff, uVar6 == (param_2 & 0xff))) {
            if ((bStack_28 & 2) != 0) {
              bStack_28 = bStack_28 & 0xfd;
              if (bStack_2b < 0xe) {
                mutex_guarded_param_dispatch_1(iVar2 << 0xc | (bStack_2b - 1) * 0x110 + 0x130);
              }
              else {
                mutex_guarded_param_dispatch_1(iStack_34 << 0xc | (bStack_2a - 1) * 0x110);
              }
              cVar5 = *(char *)(_LAB_03054264 + 1) + -1;
              *(char *)(_LAB_03054264 + 1) = cVar5;
              if (cVar5 == '\0') {
                display_mode_state_icon_blit_0x6b();
              }
            }
            if (param_1 == 3) {
              _LAB_03054268[1] = _LAB_03054268[1] & 0xfc;
              if ((bStack_28 & 0xc) == 4) {
                _LAB_03054268[1] = _LAB_03054268[1] & 0xfc | 1;
              }
              else if ((bStack_28 & 0xc) == 8) {
                _LAB_03054268[1] = _LAB_03054268[1] & 0xfc | 2;
              }
            }
            else if (param_1 == 1) {
              if ((bStack_28 & 0xc) == 0) {
                *_LAB_03054268 = *_LAB_03054268 & 0x3f;
              }
              else {
                *_LAB_03054268 = *_LAB_03054268 & 0x3f | 0x40;
              }
            }
            if (uVar3 != 0) goto LAB_030541b2;
            break;
          }
          uVar3 = uVar3 - 1 & 0xff;
        } while (uVar3 != 0);
      }
      *_p_text_entry_buffer = 0;
LAB_030541b2:
      if (0x80 < bStack_27) {
        bStack_27 = 0x80;
      }
      if (bStack_2b < 0xe) {
        flash_block_read(block_id,(bStack_2b - 1) * 0x110 + 0x140 & 0xfff0,_p_text_entry_buffer,
                         (uint)bStack_27);
      }
      else {
        flash_block_read((ushort)iStack_34,(bStack_2a - 1) * 0x110 + 0x10 & 0xfff0,
                         _p_text_entry_buffer,(uint)bStack_27);
      }
      if (param_1 == 3) {
        *_DAT_03054270 = 0;
        if (bStack_2b < 0xe) {
          flash_block_read(block_id,(bStack_2b - 1) * 0x110 + 0x13d & 0xffff,_DAT_03054270,3);
        }
        else {
          flash_block_read((ushort)iStack_34,(bStack_2a - 1) * 0x110 + 0xd & 0xffff,_DAT_03054270,3)
          ;
        }
      }
    }
  }
  return;
}

