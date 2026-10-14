/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: countdown_timer_tick_standby_trigger @ 03054700 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void countdown_timer_tick_standby_trigger(void)

{
  short sVar1;
  int iVar2;
  
  if ((((p_dm32_settings_block04[0x5a] & 0xf) != 0) &&
      (iVar2 = get_current_mode_state1(), iVar2 == 0)) && (sVar1 = PTR_DAT_03054744[6], sVar1 != 0))
  {
    PTR_DAT_03054744[6] = sVar1 + -1;
    if (sVar1 == 1) {
      iram_call_0002bb18_arg0();
      noop_stub_03060b74();
      PTR_DAT_03054754[2] = PTR_DAT_03054754[2] & 0xef | 0x10;
    }
  }
  return;
}

