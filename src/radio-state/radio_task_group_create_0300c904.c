/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_task_group_create @ 0300c904 (file base 0x03000000; code starts at 0x03001000)
 * Size: 880 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 radio_task_group_create(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_1c [4];
  
  iVar1 = radio_event_dispatch_by_name(_DAT_0300cc54,0);
  iVar2 = noop_stub_0300c434();
  if (iVar2 == iVar1) {
    iVar1 = radio_event_dispatch_by_name(_DAT_0300cc58,0);
    if (iVar2 == iVar1) {
      iVar1 = radio_event_dispatch_by_name(_DAT_0300cc5c,0);
      if (iVar2 == iVar1) {
        iVar1 = radio_event_dispatch_by_name(_DAT_0300cc60,0);
        if (iVar2 == iVar1) {
          iVar1 = OSSemCreate_shared_name_wrapper(_DAT_0300cc64,0);
          if (iVar2 == iVar1) {
            iVar1 = OSSemCreate_shared_name_wrapper(_DAT_0300cc68,0);
            if (iVar2 == iVar1) {
              iVar1 = OSSemCreate_shared_name_wrapper(_DAT_0300cc6c,0);
              if (iVar2 == iVar1) {
                iVar1 = OSSemCreate_shared_name_wrapper(_DAT_0300cc70,0);
                uVar3 = _DAT_0300cc74;
                if (iVar2 == iVar1) {
                  memset_bytes(_DAT_0300cc74,0,0x708);
                  OSTaskCreate(_DAT_0300cc78,_DAT_0300cc7c,_DAT_0300cc80,0,0x11,uVar3,0,0x1c2,0,0,0,
                               3,auStack_1c);
                  uVar3 = _DAT_0300cc84;
                  memset_bytes(_DAT_0300cc84,0,0x400);
                  OSTaskCreate(_DAT_0300cc88,_DAT_0300cc8c,_DAT_0300cc90,0,0xc,uVar3,0,0x100,0,0,0,3
                               ,auStack_1c);
                  uVar3 = _DAT_0300cc94;
                  memset_bytes(_DAT_0300cc94,0,0x400);
                  OSTaskCreate(_DAT_0300cc98,_DAT_0300cc9c,_DAT_0300cca0,0,0x12,uVar3,0,0x100,0,0,0,
                               3,auStack_1c);
                  uVar3 = _DAT_0300cca4;
                  memset_bytes(_DAT_0300cca4,0,0x400);
                  OSTaskCreate(_DAT_0300cca8,_DAT_0300ccac,_DAT_0300ccb0,0,0x17,uVar3,0,0x100,0,0,0,
                               3,auStack_1c);
                  uVar3 = _DAT_0300ccb4;
                  memset_bytes(_DAT_0300ccb4,0,0x600);
                  OSTaskCreate(_DAT_0300ccb8,_DAT_0300ccbc,_DAT_0300ccc0,0,0x18,uVar3,0,0x180,0,0,0,
                               3,auStack_1c);
                  uVar3 = _DAT_0300ccc4;
                  memset_bytes(_DAT_0300ccc4,0,0x400);
                  OSTaskCreate(_DAT_0300ccc8,_DAT_0300cccc,_DAT_0300ccd0,0,0x19,uVar3,0,0x100,0,0,0,
                               3,auStack_1c);
                  uVar3 = _DAT_0300ccd4;
                  memset_bytes(_DAT_0300ccd4,0,0x400);
                  OSTaskCreate(_DAT_0300ccd8,_DAT_0300ccdc,_DAT_0300cce0,0,0x1a,uVar3,0,0x100,0,0,0,
                               3,auStack_1c);
                  uVar3 = _DAT_0300cce4;
                  memset_bytes(_DAT_0300cce4,0,0x400);
                  OSTaskCreate(_DAT_0300cce8,_DAT_0300ccec,_DAT_0300ccf0,0,0x16,uVar3,0,0x100,0,0,0,
                               3,auStack_1c);
                  uVar3 = _DAT_0300ccf8;
                  if (PTR_DAT_0300ccf4[1] == '\x02') {
                    memset_bytes(_DAT_0300ccf8,0,0x400);
                    OSTaskCreate(_DAT_0300ccfc,_DAT_0300cd00,_DAT_0300cd04,0,0x21,uVar3,0,0x100,0,0,
                                 0,3,auStack_1c);
                  }
                  uVar3 = _DAT_0300cd08;
                  memset_bytes(_DAT_0300cd08,0,0x400);
                  OSTaskCreate(_DAT_0300cd0c,_DAT_0300cd10,_DAT_0300cd14,0,6,uVar3,0,0x100,0,0,0,3,
                               auStack_1c);
                  uVar3 = _DAT_0300cd18;
                  memset_bytes(_DAT_0300cd18,0,0x400);
                  OSTaskCreate(_DAT_0300cd1c,_DAT_0300cd20,_DAT_0300cd24,0,0x1b,uVar3,0,0x100,0,0,0,
                               3,auStack_1c);
                  uVar3 = _DAT_0300cd28;
                  memset_bytes(_DAT_0300cd28,0,0x400);
                  OSTaskCreate(_DAT_0300cd2c,_DAT_0300cd30,_DAT_0300cd34,0,0xd,uVar3,0,0x100,0,0,0,3
                               ,auStack_1c);
                  uVar3 = _DAT_0300cd38;
                  memset_bytes(_DAT_0300cd38,0,0x400);
                  OSTaskCreate(_DAT_0300cd3c,_DAT_0300cd40,_DAT_0300cd44,0,0xe,uVar3,0,0x100,0,0,0,3
                               ,auStack_1c);
                  uVar3 = 0;
                }
                else {
                  uVar3 = 1;
                }
              }
              else {
                uVar3 = 1;
              }
            }
            else {
              uVar3 = 1;
            }
          }
          else {
            uVar3 = 1;
          }
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

