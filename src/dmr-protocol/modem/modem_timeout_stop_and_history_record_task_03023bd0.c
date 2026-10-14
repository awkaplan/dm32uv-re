/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: modem_timeout_stop_and_history_record_task @ 03023bd0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 198 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void modem_timeout_stop_and_history_record_task(void)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  
  iVar2 = DAT_03023cec;
  puVar1 = PTR_DAT_03023ce0;
  do {
    do {
      while( true ) {
        while (puVar1[0x72] != '\0') {
          OSTimeDly_ms_wrapper(0x1e0);
          iVar5 = *(int *)(puVar1 + 0x78);
          *(uint *)(puVar1 + 0x78) = iVar5 + 0x1e0U;
          if (0xbf4 < iVar5 + 0x1e0U) {
            puVar1[0x72] = 0;
            *(undefined4 *)(puVar1 + 0x78) = 0;
            modem_stop();
          }
        }
        uVar3 = (uint)(byte)(puVar1[0x71] + 1) -
                ((uint)(byte)(puVar1[0x71] + 1) / (uint)(byte)puVar1[0x70]) *
                (uint)(byte)puVar1[0x70];
        uVar4 = uVar3 & 0xff;
        puVar1[0x71] = (char)uVar3;
        noop_stub_0300c3a8(*(undefined4 *)(puVar1 + uVar4 * 0xc + 8),
                           *(undefined4 *)(puVar1 + uVar4 * 0xc + 4));
        modem_stop();
        if (puVar1[(byte)puVar1[0x71] + 0x48] == '\0') break;
        OSTimeDly_ms_wrapper(0xa14);
      }
      puVar1[(byte)puVar1[0x71] + 0x48] = 1;
    } while (*(char *)(iVar2 + 0x19) == '\0');
    bVar6 = 0;
    do {
      history_record_build_type3(0xffffff,*(undefined4 *)(iVar2 + 0x24));
      modem_mode_select(2,2);
      OSTimeDly_ms_wrapper(*(undefined2 *)(iVar2 + 0x1c));
      if (puVar1[0x72] == '\x01') break;
      bVar6 = bVar6 + 1;
    } while (bVar6 < *(byte *)(iVar2 + 0x19));
  } while( true );
}

