/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_name_copy_under_sem_select @ 03011a40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
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

void channel_name_copy_under_sem_select(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  
  os_sem_pend_ms(_DAT_03011b30,0);
  memset_bytes(_DAT_03011b28,0,100);
  if ((*(byte *)PTR_DAT_03011b24 & 0x40) != 0) {
    PTR_DAT_03011b34[0x10] = PTR_DAT_03011b34[0x10] & 0xbf | 0x40;
    iVar2 = _DAT_03011b38;
    uVar3 = strlen_ck803s(_DAT_03011b38);
    uVar1 = _DAT_03011b28;
    memcpy_bytes_iram(_DAT_03011b28,iVar2,uVar3);
    channel_select_input_gate(4,*(undefined4 *)(iVar2 + -9),uVar1,uVar3,0);
  }
  os_sem_post(_DAT_03011b30);
  return;
}

