/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: adc_stop_and_reset @ 0301caec (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-adc
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void adc_stop_and_reset(void)

{
  dword dVar1;
  
  OSSemCreate_shared_name_wrapper(p_ucos_mutex_0003a474,1);
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX2;
  SystemControl_Type_11000000.IO_DIPLEX2 = dVar1 & 0xffefffff;
  dVar1 = SystemControl_Type_11000000.IO_DIPLEX2;
  SystemControl_Type_11000000.IO_DIPLEX2 = dVar1 & 0xffdfffff;
  ADC_140D0000.ADC_CTRL = 0;
  ADC_140D0000.ADC_CTRL = 8;
  ADC_140D0000.ADC_CTRL_STOP = 2;
  while ((dVar1 = ADC_140D0000.ADC_CTRL_STATE, (dVar1 & 1) != 0 ||
         (dVar1 = ADC_140D0000.ADC_CTRL_STATE, (dVar1 & 0x3e) != 0))) {
    ADC_140D0000.ADC_CTRL_STOP = 2;
  }
  ADC_140D0000.ADC_CTRL = 0;
  ADC_140D0000.ADC_PD_SEOC_TIME = 0xa20;
  ADC_140D0000.ADC_P2S_EN = 0;
  ADC_140D0000.ADC_INTR = 0;
  ADC_140D0000.ADC_CH_VLD = 0;
  return;
}

