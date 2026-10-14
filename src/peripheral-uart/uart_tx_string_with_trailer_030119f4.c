/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: uart_tx_string_with_trailer @ 030119f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: peripheral-uart
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void uart_tx_string_with_trailer(char *param_1)

{
  char *dest;
  undefined4 *puVar1;
  undefined2 uVar2;
  int iVar3;
  char *pcVar4;
  
  dest = _DAT_03011b28;
  if ((*(byte *)PTR_DAT_03011b24 & 1) == 0) {
    memset_bytes(_DAT_03011b28,0,100);
    strcat(dest,param_1);
    iVar3 = strlen_ck803s(dest);
    puVar1 = PTR_LAB_03011b2c;
    pcVar4 = dest + iVar3;
    *pcVar4 = *(char *)PTR_LAB_03011b2c;
    pcVar4[1] = *(char *)((int)puVar1 + 1);
    pcVar4[2] = *(char *)((int)puVar1 + 2);
    uVar2 = strlen_ck803s(dest);
    uart_tx_chunked_mutex_send(dest,uVar2);
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

