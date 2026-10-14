/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_char_index_to_display_code @ 03052e2c (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_char_index_to_display_code(byte param_1,char param_2,char *param_3,byte *param_4)

{
  char cVar1;
  uint uVar2;
  char cVar3;
  
  uVar2 = (uint)param_1;
  if (param_2 == '\x03') {
    if (uVar2 < 0xe) {
      cVar3 = '\b';
      goto LAB_03052e82;
    }
    cVar3 = 'O';
  }
  else if (param_2 == '\x05') {
    if (uVar2 < 0xe) {
      cVar3 = '\t';
      goto LAB_03052e82;
    }
    cVar3 = 'U';
  }
  else {
    if (param_2 != '\x01') {
      return;
    }
    if (uVar2 < 0xe) {
      cVar3 = '\a';
LAB_03052e82:
      *param_3 = cVar3;
      *param_4 = param_1;
      return;
    }
    cVar3 = 'I';
  }
  cVar1 = (char)((int)(uVar2 - 0xe) / 0xf);
  *param_3 = cVar3 + cVar1;
  *param_4 = (char)(uVar2 - 0xe) + cVar1 * -0xf + 1;
  return;
}

