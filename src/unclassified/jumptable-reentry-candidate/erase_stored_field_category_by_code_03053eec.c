/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: erase_stored_field_category_by_code @ 03053eec (file base 0x03000000; code starts at 0x03001000)
 * Size: 148 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void erase_stored_field_category_by_code(char param_1)

{
  char *unaff_r6;
  undefined4 unaff_r7;
  undefined1 auStack_8c [100];
  undefined1 auStack_28 [16];
  
  os_sem_pend_ms(p_ucos_mutex_0003ea50,0);
  if (param_1 == '\x03') {
    unaff_r7 = 8;
    unaff_r6 = DAT_030540f0;
  }
  else if (param_1 == '\x05') {
    unaff_r7 = 9;
    unaff_r6 = DAT_030540f4;
  }
  else if (param_1 == '\x01') {
    unaff_r7 = 7;
    unaff_r6 = DAT_030540ec;
  }
  if (*unaff_r6 == '\0') {
    os_sem_post(p_ucos_mutex_0003ea50);
  }
  else {
    memset_bytes(auStack_28,0xff,0xd);
    memset_bytes(auStack_8c,0xff,100);
    flash_page_read_modify_write(unaff_r7,0,auStack_28,0xd,0x30,auStack_8c,100);
    if ((param_1 == '\x01') && (PTR_DAT_030540f8[1] != '\0')) {
      PTR_DAT_030540f8[1] = 0;
      display_mode_state_icon_blit_0x6b();
    }
    *unaff_r6 = '\0';
    os_sem_post(p_ucos_mutex_0003ea50);
  }
  return;
}

