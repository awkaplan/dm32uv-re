/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_signaling_scroll_and_display_update @ 03030240 (file base 0x03000000; code starts at 0x03001000)
 * Size: 234 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tone_signaling_scroll_and_display_update(void)

{
  byte *pbVar1;
  byte bVar2;
  
  pbVar1 = _DAT_03030348;
  if ((_DAT_03030348[4] & 1) != 0) {
    _DAT_03030348[4] = _DAT_03030348[4] & 0xfe;
    if ((*pbVar1 & 0x20) != 0) {
      if ((_DAT_03030348[4] & 2) == 0) {
        if ((*(byte *)(_DAT_0303034c + 0x5d) & 1) == 0) {
          if (*_DAT_03030350 < 2) {
            *_DAT_03030350 = 0x32;
          }
          else {
            *_DAT_03030350 = *_DAT_03030350 - 1;
          }
        }
        else {
          bVar2 = *_DAT_03030350;
          *_DAT_03030350 = bVar2 + 1;
          if (0x32 < (byte)(bVar2 + 1)) {
            *_DAT_03030350 = 1;
          }
        }
        ctcss_tone_freq_display(_DAT_03030354);
      }
      else {
        if ((*(byte *)(_DAT_0303034c + 0x5d) & 1) == 0) {
          if (*_DAT_03030350 < 2) {
            *_DAT_03030350 = 0x69;
            _DAT_03030348[4] = _DAT_03030348[4] & 0xfb | (_DAT_03030348[4] >> 2 & 1 ^ 1) << 2;
          }
          else {
            *_DAT_03030350 = *_DAT_03030350 - 1;
          }
        }
        else {
          bVar2 = *_DAT_03030350;
          *_DAT_03030350 = bVar2 + 1;
          if (0x69 < (byte)(bVar2 + 1)) {
            *_DAT_03030350 = 1;
            _DAT_03030348[4] = _DAT_03030348[4] & 0xfb | (_DAT_03030348[4] >> 2 & 1 ^ 1) << 2;
          }
        }
        dcs_code_display_normal_invert(_DAT_03030354);
      }
      bVar2 = tone_signaling_type_classify(*(undefined2 *)(_DAT_03030358 + 0x11));
      *(byte *)(_DAT_0303035c + 0x35) = *(byte *)(_DAT_0303035c + 0x35) & 0xf3 | (bVar2 & 3) << 2;
      rf_channel_mode_select_and_apply();
    }
  }
  return;
}

