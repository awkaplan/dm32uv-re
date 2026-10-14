/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_timer_apply_random_jitter @ 03024238 (file base 0x03000000; code starts at 0x03001000)
 * Size: 128 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_timer_apply_random_jitter(uint param_1)

{
  int iVar1;
  
  if (*PTR_DAT_0302432c == '\x03') {
    iVar1 = lcg_rand_next();
    PTR_DAT_03024338[1] =
         PTR_DAT_03024338[1] & 0xf800 |
         (short)((uint)((iVar1 % 0x36) * 0x3c) / 500) + (PTR_DAT_03024338[1] & 0x7ff) & 0x7ff;
    guarded_timer_config_apply_wrapper();
    PTR_DAT_0302432c[3] = 1;
  }
  else if ((param_1 & 0xff) < 0x13) {
    iVar1 = lcg_rand_next();
    PTR_DAT_03024338[1] =
         PTR_DAT_03024338[1] & 0xf800 |
         (short)((iVar1 % 0x438 + (param_1 & 0xff) * 0x78) / 500) + (PTR_DAT_03024338[1] & 0x7ff) &
         0x7ff;
    guarded_timer_config_apply_wrapper();
    PTR_DAT_0302432c[3] = 1;
  }
  return;
}

