/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: os_flag_group_ready_bits_apply_or_error @ 030688c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 20 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x03068d1e) */
/* WARNING: Removing unreachable block (ram,0x03068922) */
/* WARNING: Removing unreachable block (ram,0x03068c34) */
/* WARNING: Removing unreachable block (ram,0x03068928) */
/* WARNING: Removing unreachable block (ram,0x03068ac2) */
/* WARNING: Removing unreachable block (ram,0x03068ac8) */
/* WARNING: Removing unreachable block (ram,0x03068acc) */
/* WARNING: Removing unreachable block (ram,0x03068ad8) */
/* WARNING: Removing unreachable block (ram,0x03068ade) */
/* WARNING: Removing unreachable block (ram,0x03068af0) */
/* WARNING: Removing unreachable block (ram,0x03068af6) */
/* WARNING: Removing unreachable block (ram,0x03068b14) */
/* WARNING: Removing unreachable block (ram,0x03068b1c) */
/* WARNING: Removing unreachable block (ram,0x03068b32) */
/* WARNING: Removing unreachable block (ram,0x03068b6c) */
/* WARNING: Removing unreachable block (ram,0x03068b70) */
/* WARNING: Removing unreachable block (ram,0x03068998) */
/* WARNING: Removing unreachable block (ram,0x030689a0) */
/* WARNING: Removing unreachable block (ram,0x030689b6) */
/* WARNING: Removing unreachable block (ram,0x030689f0) */
/* WARNING: Removing unreachable block (ram,0x030689f4) */
/* WARNING: Removing unreachable block (ram,0x03068938) */
/* WARNING: Removing unreachable block (ram,0x03068942) */
/* WARNING: Removing unreachable block (ram,0x03068948) */
/* WARNING: Removing unreachable block (ram,0x0306894c) */
/* WARNING: Removing unreachable block (ram,0x03068958) */
/* WARNING: Removing unreachable block (ram,0x0306895e) */
/* WARNING: Removing unreachable block (ram,0x0306897c) */
/* WARNING: Removing unreachable block (ram,0x03068982) */
/* WARNING: Removing unreachable block (ram,0x03068a52) */
/* WARNING: Removing unreachable block (ram,0x03068a5a) */
/* WARNING: Removing unreachable block (ram,0x03068a6e) */
/* WARNING: Removing unreachable block (ram,0x03068aa8) */
/* WARNING: Removing unreachable block (ram,0x03068aac) */
/* WARNING: Removing unreachable block (ram,0x03068b7c) */
/* WARNING: Removing unreachable block (ram,0x03068b86) */
/* WARNING: Removing unreachable block (ram,0x03068b8c) */
/* WARNING: Removing unreachable block (ram,0x03068b90) */
/* WARNING: Removing unreachable block (ram,0x03068b9c) */
/* WARNING: Removing unreachable block (ram,0x03068ba2) */
/* WARNING: Removing unreachable block (ram,0x03068bb4) */
/* WARNING: Removing unreachable block (ram,0x03068bba) */
/* WARNING: Removing unreachable block (ram,0x03068bce) */
/* WARNING: Removing unreachable block (ram,0x03068bd6) */
/* WARNING: Removing unreachable block (ram,0x03068bea) */
/* WARNING: Removing unreachable block (ram,0x03068c24) */
/* WARNING: Removing unreachable block (ram,0x03068c28) */
/* WARNING: Removing unreachable block (ram,0x03068c4a) */
/* WARNING: Removing unreachable block (ram,0x03068c9c) */
/* WARNING: Removing unreachable block (ram,0x03068ca0) */
/* WARNING: Removing unreachable block (ram,0x03068ca6) */
/* WARNING: Removing unreachable block (ram,0x03068c64) */
/* WARNING: Removing unreachable block (ram,0x03068c68) */
/* WARNING: Removing unreachable block (ram,0x03068cdc) */
/* WARNING: Removing unreachable block (ram,0x03068ce0) */
/* WARNING: Removing unreachable block (ram,0x03068ce6) */
/* WARNING: Removing unreachable block (ram,0x03068c6c) */
/* WARNING: Removing unreachable block (ram,0x03068cfc) */
/* WARNING: Removing unreachable block (ram,0x03068c70) */
/* WARNING: Removing unreachable block (ram,0x03068cc0) */
/* WARNING: Removing unreachable block (ram,0x03068cc6) */
/* WARNING: Removing unreachable block (ram,0x03068c72) */
/* WARNING: Removing unreachable block (ram,0x03068c76) */
/* WARNING: Removing unreachable block (ram,0x03068c7c) */
/* WARNING: Removing unreachable block (ram,0x03068c90) */
/* WARNING: Removing unreachable block (ram,0x03068d18) */
/* WARNING: Removing unreachable block (ram,0x03068d2a) */
/* WARNING: Removing unreachable block (ram,0x03068d30) */
/* WARNING: Removing unreachable block (ram,0x03068d40) */
/* WARNING: Removing unreachable block (ram,0x03068d28) */
/* WARNING: Removing unreachable block (ram,0x03068d56) */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint os_flag_group_ready_bits_apply_or_error(void)

{
  undefined4 sr;
  int unaff_r4;
  uint uVar1;
  int *unaff_r6;
  uint unaff_r7;
  undefined4 *unaff_r9;
  int *unaff_r11;
  int iStack00000008;
  
  if (unaff_r4 == 0x8108) {
    if (*unaff_r6 == DAT_03068978) {
      iStack00000008 = 1;
      if (unaff_r11 != (int *)0x0) {
        *unaff_r11 = 0;
      }
      sr = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      uVar1 = unaff_r7 & unaff_r6[8];
      if (uVar1 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *unaff_r9 = 0x61b0;
      }
      else {
        if (iStack00000008 == 1) {
          unaff_r6[8] = unaff_r6[8] & ~uVar1;
        }
        *(uint *)(*PTR_OSTCBCurPtr_03068b10 + 0x84) = uVar1;
        if (unaff_r11 != (int *)0x0) {
          *unaff_r11 = unaff_r6[9];
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *unaff_r9 = 0;
      }
    }
    else {
      *unaff_r9 = 0x5dc4;
      uVar1 = 0;
    }
  }
  else {
    *unaff_r9 = 0x5e25;
    uVar1 = 0;
  }
  return uVar1;
}

