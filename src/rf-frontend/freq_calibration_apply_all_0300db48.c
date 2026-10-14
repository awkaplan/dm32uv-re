/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: freq_calibration_apply_all @ 0300db48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 310 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void freq_calibration_apply_all(void)

{
  vfo_display_state *pvVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  
  pvVar1 = p_vfo_display_state;
  uVar3 = freq_calibration_interpolate_selected
                    (*(undefined4 *)&p_vfo_display_state->field_0x4_0,
                     p_vfo_display_state->flags_0x8 >> 1 & 3);
  puVar2 = PTR_DAT_0300dc84;
  PTR_DAT_0300dc84[0x28] = uVar3;
  uVar4 = channel_step_frequency_bound_check
                    (*(undefined4 *)pvVar1,pvVar1->field_0xc >> 4,pvVar1->flags_0x9 >> 7);
  PTR_DAT_0300dc88[1] = uVar4;
  uVar3 = freq_calibration_interpolate_single(*(undefined4 *)&pvVar1->field_0x4_0);
  puVar2[0x29] = uVar3;
  mmio_11000114_low_word_duplicate_write();
  noop_stub_0302184c(puVar2[0x29]);
  uVar3 = frequency_range_clamp_and_dispatch(*(undefined4 *)&pvVar1->field_0x4_0);
  puVar2[0x38] = uVar3;
  if ((pvVar1->flags_0x8 & 0xf0) == 0) {
    if ((pvVar1->flags_0x9 & 0x80) == 0) {
      soft_double_from_int(PTR_DAT_0300dc84[0x29]);
      soft_double_multiply();
      uVar5 = soft_double_to_int();
    }
    else {
      soft_double_from_int(puVar2[0x29]);
      soft_double_multiply();
      uVar5 = soft_double_to_int();
    }
    if (0xff < uVar5) {
      uVar5 = 0xff;
    }
    mmio_11000114_low_word_duplicate_write(uVar5 & 0xff);
    noop_stub_0302184c(uVar5 & 0xff);
    uVar3 = flash_field_read_signed_select
                      (*(undefined4 *)&p_vfo_display_state->field_0x4_0,
                       *(undefined2 *)&p_vfo_display_state->field_0x13_0);
    PTR_DAT_0300dc84[0x2d] = uVar3;
  }
  PTR_DAT_0300dc84[0x32] = PTR_DAT_0300dc84[0x32] & 0xfe;
  return;
}

