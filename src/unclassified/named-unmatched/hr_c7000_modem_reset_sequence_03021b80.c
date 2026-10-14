/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hr_c7000_modem_reset_sequence @ 03021b80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 212 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void hr_c7000_modem_reset_sequence(void)

{
  dword dVar1;
  undefined1 *puVar2;
  
  puVar2 = PTR_DAT_03021c58;
  PTR_DAT_03021c58[0xd2] = PTR_DAT_03021c58[0xd2] | 3;
  dVar1 = SystemControl_Type_11000000.SYS_SOFT_RSTN;
  SystemControl_Type_11000000.SYS_SOFT_RSTN = dVar1 & 0xfffffff7;
  dVar1 = SystemControl_Type_11000000.SYS_SOFT_RSTN;
  SystemControl_Type_11000000.SYS_SOFT_RSTN = dVar1 & 0xffffffef;
  OSTimeDly_ms_wrapper(2);
  puVar2[0xd2] = puVar2[0xd2] & 0xfe;
  OSTimeDly_ms_wrapper(100);
  puVar2[0xd2] = puVar2[0xd2] & 0xfd;
  puVar2[0xd3] = 0x40;
  puVar2[0xcb] = 0;
  puVar2[0xcc] = puVar2[0xcc] | 0x40;
  puVar2[0xc9] = 0xc0;
  puVar2[0xcf] = puVar2[0xcf] & 0xef;
  OSTimeDly_ms_wrapper(100);
  puVar2[0xcf] = puVar2[0xcf] & 0x7f;
  puVar2[200] = 0xc0;
  puVar2[0xcd] = puVar2[0xcd] & 0xef;
  dVar1 = SystemControl_Type_11000000.LINEOUT_CTRL;
  puVar2 = PTR_DAT_03021c58;
  while (PTR_DAT_03021c58 = puVar2, (int)dVar1 < 0) {
    OSTimeDly_ms_wrapper(10);
    dVar1 = SystemControl_Type_11000000.LINEOUT_CTRL;
    puVar2 = PTR_DAT_03021c58;
  }
  puVar2[0xcd] = puVar2[0xcd] & 0x7f;
  OSTimeDly_ms_wrapper(100);
  puVar2[0xdf] = 0xab;
  FUN_03021b60(1);
  return;
}

