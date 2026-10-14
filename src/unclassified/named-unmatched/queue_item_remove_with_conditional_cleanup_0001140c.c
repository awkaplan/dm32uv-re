/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: queue_item_remove_with_conditional_cleanup @ 0001140c (IRAM address; the boot stub copies these bytes from program flash 0x030c102c)
 * Size: 28 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void queue_item_remove_with_conditional_cleanup(int param_1)

{
  dll_node_remove();
  if ((*(byte *)(param_1 + 0x36) & 4) == 0) {
    ucos3_rdy_list_insert_by_prio(param_1);
  }
  return;
}

