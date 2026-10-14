/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rda5807m_read_reg_0a @ 03065638 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rda5807m_read_reg_0a(undefined1 *param_1)

{
  undefined1 uVar1;
  
  rda5807m_i2c_read_addr_phase();
  uVar1 = rda5807m_i2c_recv_byte();
  *param_1 = uVar1;
  rda5807m_bitbang_ack_pulse();
  uVar1 = rda5807m_i2c_recv_byte();
  param_1[1] = uVar1;
  peripheral_reset_gpio_pulse_sequence_variant_030654d8();
  rda5807m_i2c_stop();
  return;
}

