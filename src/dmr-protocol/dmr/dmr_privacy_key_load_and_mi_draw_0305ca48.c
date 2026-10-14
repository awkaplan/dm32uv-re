/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_privacy_key_load_and_mi_draw @ 0305ca48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 192 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_privacy_key_load_and_mi_draw(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  ushort block_id;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 local_3c [11];
  undefined1 uStack_31;
  undefined1 auStack_30 [32];
  
  memset_bytes(DAT_0305cbd0,0,10);
  p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0xfc;
  if (((p_vfo_display_state->field_0xe == 0) || ((p_vfo_display_state->field_0xf & 0x40) == 0)) ||
     ((p_vfo_display_state->flags_0x8 & 0xf0) != 0x10)) {
    *(undefined1 *)PTR_DAT_0305cbdc = 0;
  }
  else {
    block_id = flash_block_id_resolve_locked(0x10);
    flash_block_read(block_id,(p_vfo_display_state->field_0xe - 1) * 0x2c + 0x300 & 0xfffc,local_3c,
                     0x2c);
    puVar1 = PTR_DAT_0305cbe0;
    PTR_DAT_0305cbe0[1] = local_3c[0];
    puVar4 = PTR_DAT_0305cbe4;
    PTR_DAT_0305cbe4[1] = local_3c[0];
    *(undefined1 *)PTR_DAT_0305cbdc = uStack_31;
    puVar3 = puVar1 + 2;
    memset_bytes(puVar3,0,0x20);
    memcpy_bytes_iram(puVar3,auStack_30,0x20);
    memcpy_bytes_iram(puVar4 + 3,puVar3,0x20);
    puVar4 = puVar1 + 0x22;
    do {
      uVar2 = lcg_rand_next();
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    } while (puVar4 != puVar1 + 0x28);
  }
  dmr_privacy_type_apply(*(undefined1 *)PTR_DAT_0305cbdc,(int)PTR_DAT_0305cbdc + 1,10);
  return;
}

