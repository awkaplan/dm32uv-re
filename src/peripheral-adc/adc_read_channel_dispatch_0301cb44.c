/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: adc_read_channel_dispatch @ 0301cb44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-adc
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 adc_read_channel_dispatch(uint param_1)

{
  dword dVar1;
  undefined4 uVar2;
  
  os_sem_pend_ms(p_ucos_mutex_0003a474,0);
  while ((dVar1 = ADC_140D0000.ADC_CTRL_STATE, (dVar1 & 1) != 0 ||
         (dVar1 = ADC_140D0000.ADC_CTRL_STATE, (dVar1 & 0x3e) != 0))) {
    ADC_140D0000.ADC_CTRL_STOP = 2;
  }
  ADC_140D0000.ADC_CH_VLD = 1 << (param_1 & 0x3f);
  ADC_140D0000.ADC_START = 1;
  do {
    do {
      dVar1 = ADC_140D0000.ADC_CTRL_STATE;
    } while ((dVar1 & 1) != 0);
    dVar1 = ADC_140D0000.ADC_CTRL_STATE;
  } while ((dVar1 & 0x3e) != 0);
  if ((param_1 & 0xff) < 8) {
                    /* WARNING: Could not recover jumptable at 0x0301cb9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)(PTR_PTR_0301cba4[param_1 & 0xff] & 0xfffffffe))();
    return uVar2;
  }
  os_sem_post(p_ucos_mutex_0003a474);
  return 0;
}

