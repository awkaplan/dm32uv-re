/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: startup_input_and_flash_state_init @ 0304af18 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void startup_input_and_flash_state_init(void)

{
  input_alter_task_create_init();
  func_0x0304a38c();
  apply_flags_from_flash_0x65_0x66();
  subsystem_buffer_reset_and_task_init_0x4b0();
  flash_record_table_reclaim_or_count_empty();
  ucos_sem_create_03033494();
  dmr_list_subsystem_init();
  timed_feature_config_load_from_flash();
  func_0x03060dd0();
  return;
}

