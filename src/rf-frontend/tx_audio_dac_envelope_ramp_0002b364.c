/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: tx_audio_dac_envelope_ramp @ 0002b364 (IRAM address; the boot stub copies these bytes from program flash 0x030daf84)
 * Size: 202 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_audio_dac_envelope_ramp(int param_1,int param_2,undefined1 param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  func_0x0300c500(uRam0002b430,0);
  if (param_1 == 0) {
    dac_channel2_write_from_byte(param_3);
  }
  else if (param_2 == 0) {
    func_0x0306f494(param_3);
    func_0x0306efb8();
    puVar2 = puRam0002b438;
    puVar3 = puRam0002b438 + 0x14;
    do {
      func_0x0306f320(*puVar3);
      func_0x0306ed10();
      func_0x0306ec8c();
      uVar1 = func_0x0306e374();
      dac_channel2_write_from_byte(uVar1);
      puVar3 = puVar3 + -1;
    } while (puVar3 != puVar2);
    dac_channel2_write_from_byte(0);
  }
  else {
    func_0x0306f494(param_3);
    func_0x0306efb8();
    puVar3 = puRam0002b438 + 0x28;
    puVar2 = puRam0002b438;
    do {
      func_0x0306f320(*puVar2);
      func_0x0306ed10();
      func_0x0306ec8c();
      uVar1 = func_0x0306e374();
      dac_channel2_write_from_byte(uVar1);
      puVar2 = puVar2 + 1;
    } while (puVar2 != puVar3);
    dac_channel2_write_from_byte(param_3);
  }
  func_0x0300c53c(uRam0002b430);
  return;
}

