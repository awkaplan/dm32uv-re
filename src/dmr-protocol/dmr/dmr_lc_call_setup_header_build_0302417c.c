/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_lc_call_setup_header_build @ 0302417c (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_lc_call_setup_header_build(byte *out_buf,uint target_dmr_id)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_030241b0;
  *out_buf = *(byte *)PTR_DAT_030241b0 | 0x20;
  out_buf[1] = 0x10;
  out_buf[2] = *(byte *)((int)puVar1 + 1);
  memcpy_bytes_iram(out_buf + 3,(int)puVar1 + 0x22,4);
  out_buf[7] = (byte)(target_dmr_id >> 0x10);
  out_buf[8] = (byte)(target_dmr_id >> 8);
  out_buf[9] = (byte)target_dmr_id;
  out_buf[10] = 8;
  out_buf[0xb] = 0x53;
  return;
}

