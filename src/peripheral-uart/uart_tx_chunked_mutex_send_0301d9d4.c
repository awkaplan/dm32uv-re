/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: uart_tx_chunked_mutex_send @ 0301d9d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-uart
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void uart_tx_chunked_mutex_send(int param_1,int param_2__w)

{
  ushort param_2 = (ushort)param_2__w;
  dword dVar1;
  void *mutex;
  undefined4 uVar2;
  undefined2 *puVar3;
  
  puVar3 = PTR_DAT_0301dab8;
  uVar2 = _DAT_0301dab4;
  mutex = _DAT_0301daac;
  while( true ) {
    os_sem_pend_ms(mutex,0);
    if (param_2 < 0x65) {
      memcpy_bytes_iram(_DAT_0301dab4,param_1,param_2);
      puVar3 = PTR_DAT_0301dab8;
      PTR_DAT_0301dab8[1] = 0;
      puVar3[2] = param_2;
      dVar1 = UART_Type_14040000.IER_DLH;
      UART_Type_14040000.IER_DLH = dVar1 | 0x82;
      return;
    }
    memcpy_bytes_iram(uVar2,param_1,100);
    puVar3[1] = 0;
    puVar3[2] = 100;
    param_2 = param_2 - 100;
    dVar1 = UART_Type_14040000.IER_DLH;
    UART_Type_14040000.IER_DLH = dVar1 | 0x82;
    if (param_2 == 0) break;
    param_1 = param_1 + 100;
  }
  return;
}

