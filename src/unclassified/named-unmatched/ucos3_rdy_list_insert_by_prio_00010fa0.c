/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: ucos3_rdy_list_insert_by_prio @ 00010fa0 (IRAM address; the boot stub copies these bytes from program flash 0x030c0bc0)
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

void ucos3_rdy_list_insert_by_prio(int param_1)

{
  OS_PrioInsert(*(undefined1 *)(param_1 + 0x37));
  if (*(char *)(param_1 + 0x37) == *PTR_DAT_00011090) {
    timer_object_register_into_bucket_list(param_1);
  }
  else {
    hashtable_bucket_insert_tail(param_1);
  }
  return;
}

