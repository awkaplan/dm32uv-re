/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: idle_background_notify_counter @ 0305fcd4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 152 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void idle_background_notify_counter(void)

{
  int iVar1;
  
  if ((*PTR_DAT_0305fd5c & 0x20) == 0) {
    iVar1 = tx_is_inhibited();
    if ((((iVar1 == 0) && (iVar1 = read_byte_field_0305fca8(), iVar1 == 0)) &&
        (*(char *)PTR_DAT_0305fd6c == '\0')) &&
       (((PTR_DAT_0305fd74[3] & 2) == 0 && ((PTR_DAT_0305fd74[3] & 0x40) == 0)))) {
      if ((byte)PTR_DAT_0305fd78[0x21] < 10) {
        PTR_DAT_0305fd78[0x21] = PTR_DAT_0305fd78[0x21] + 1;
      }
      else {
        *(undefined1 *)(_LAB_0305fd8c + 0x21) = 0;
        ui_event_notify_alt(0xd);
      }
    }
  }
  else if ((PTR_DAT_0305fd74[3] & 2) != 0) {
    if ((byte)PTR_DAT_0305fd78[0x21] < 0xf) {
      PTR_DAT_0305fd78[0x21] = PTR_DAT_0305fd78[0x21] + 1;
    }
    else {
      PTR_DAT_0305fd78[0x21] = 0;
      ui_event_notify_alt(0xd);
    }
  }
  return;
}

