/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rx_voice_start_begin_record @ 03021948 (file base 0x03000000; code starts at 0x03001000)
 * Size: 172 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: audio
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rx_voice_start_begin_record(void)

{
  dword dVar1;
  int iVar2;
  
  if ((*(byte *)PTR_DAT_030219f4 & 2) == 0) {
    dVar1 = SystemControl_Type_11000000.AUDIO_BUFFER_CLR;
    SystemControl_Type_11000000.AUDIO_BUFFER_CLR = dVar1 | 2;
    dVar1 = SystemControl_Type_11000000.AUDIO_BUFFER_CLR;
    SystemControl_Type_11000000.AUDIO_BUFFER_CLR = dVar1 | 1;
    if (((((*(byte *)PTR_DAT_030219fc & 0x10) != 0) && ((*(byte *)PTR_DAT_03021a08 & 0x10) != 0)) &&
        ((PTR_DAT_03021a0c[3] & 1) != 0)) &&
       ((PTR_DAT_03021a0c[2] == '\0' || (PTR_DAT_03021a0c[2] == '\x02')))) {
      PTR_DAT_03021a00[5] = 0;
      voice_record_direction_select(2);
      write_byte_field_030212e4(1);
    }
    iVar2 = call_setup_sm_aux_field0xb_is_zero();
    if (iVar2 == 0) {
      FUN_00015f30(4,1);
      FUN_00016000(1);
      FUN_0001600c(0);
      PTR_DAT_030219f8[0x1f] = 1;
    }
    if (*(char *)PTR_DAT_03021a10 == '\x01') {
      OSTimeDly_ms_wrapper(300);
    }
    FUN_000160c0();
    *(byte *)PTR_DAT_030219f4 = *(byte *)PTR_DAT_030219f4 | 2;
  }
  return;
}

