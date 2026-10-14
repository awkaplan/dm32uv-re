/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_bandwidth_deviation_mode_set @ 0300f1b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_bandwidth_deviation_mode_set(char param_1,char param_2)

{
  undefined1 *puVar1;
  char cVar2;
  
  cVar2 = value_at_or_above_low_bound_check(*(undefined4 *)p_vfo_display_state);
  if (cVar2 == '\0') {
    config_table_entry_0300f15c();
    if (param_1 == '\0') {
      if (PTR_DAT_0300f254[2] != '\x02') {
        config_table_init_entries_and_param_2b();
        PTR_DAT_0300f254[2] = 2;
      }
    }
    else if (PTR_DAT_0300f254[2] != '\x01') {
      config_table_init_group1_variant_0300f16c();
      PTR_DAT_0300f254[2] = 1;
    }
    if (param_2 == '\0') {
      if (PTR_DAT_0300f254[1] != '\x02') {
        fd6818_tx_deviation_bandwidth_mode_set('\0');
        PTR_DAT_0300f254[1] = 2;
      }
    }
    else if (PTR_DAT_0300f254[1] != '\x01') {
      fd6818_tx_deviation_bandwidth_mode_set('\x02');
      PTR_DAT_0300f254[1] = 1;
    }
  }
  else {
    config_table_init_group1_variant_0300f130();
    puVar1 = PTR_DAT_0300f254;
    PTR_DAT_0300f254[1] = 0;
    puVar1[2] = 0;
  }
  return;
}

