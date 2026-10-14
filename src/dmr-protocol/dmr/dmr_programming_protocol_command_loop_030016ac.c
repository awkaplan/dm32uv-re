/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_programming_protocol_command_loop @ 030016ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 262 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_programming_protocol_command_loop(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uStack_25;
  
  FUN_0300185c(6);
  uVar2 = _DAT_030017b8;
  puVar1 = PTR_LAB_030017b4;
  while( true ) {
    while( true ) {
      do {
        cVar3 = FUN_0001265c(puVar1,5,0x100000);
      } while (cVar3 == '\0');
      cVar3 = *puVar1;
      if (cVar3 == 'M') break;
      if (cVar3 == 'G') {
        if (0x20 < (byte)puVar1[4]) {
          return;
        }
        *puVar1 = 0x53;
        FUN_03001868(puVar1,(byte)puVar1[4] + 5);
        cVar3 = FUN_0001265c(puVar1,1,0x100000);
        if ((cVar3 != '\0') && (*puVar1 == '\x06')) {
          FUN_03001868(puVar1,1);
        }
      }
      else if (cVar3 == 'V') {
        puVar1[1] = 2;
        puVar1[2] = 0xc;
        FUN_03001868(puVar1,3);
        cVar3 = FUN_0001265c(puVar1,1,0x100000);
        if (cVar3 == '\0') {
          return;
        }
        if (*puVar1 != '\x06') {
          return;
        }
        FUN_03001868(puVar1,0xc);
      }
      else if (cVar3 == 'E') {
        uStack_25 = 6;
        FUN_03001868(&uStack_25,1);
        return;
      }
    }
    uVar4 = strlen_unaligned_path(uVar2);
    puVar1[1] = 1;
    puVar1[2] = uVar4;
    FUN_03001868(puVar1,3,30000);
    cVar3 = FUN_0001265c(puVar1,1,0x100000);
    if (cVar3 == '\0') {
      return;
    }
    if (*puVar1 != '\x06') break;
    FUN_0001232c(puVar1,uVar2,uVar4);
    FUN_03001868(puVar1,uVar4);
  }
  return;
}

