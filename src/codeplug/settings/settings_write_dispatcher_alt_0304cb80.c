/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_write_dispatcher_alt @ 0304cb80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 688 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_write_dispatcher_alt(char param_1,byte param_2)

{
  byte local_11;
  
  flash_field_read_cached(4,0x20,&local_11,1);
  param_2 = param_2 ^ 1;
  if (param_1 == '\0') {
    if (param_2 == 0) {
      local_11 = local_11 & 0xbf;
      p_dm32_settings_block04[0x42] = 0;
      goto LAB_0304cbc8;
    }
    local_11 = local_11 | 0x40;
    p_dm32_settings_block04[0x42] = 1;
LAB_0304cc48:
    if (param_1 != '\x03') {
      if (param_1 == '\x04') {
        if (param_2 == 0) {
          local_11 = local_11 & 0xfb;
          p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xf7;
          goto LAB_0304ce28;
        }
        local_11 = local_11 | 4;
        p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xf7 | 8;
      }
      else if (param_1 == '\x05') {
        if (param_2 == 0) {
          local_11 = local_11 & 0xfd;
          p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xef;
          goto LAB_0304ce28;
        }
        local_11 = local_11 | 2;
        p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xef | 0x10;
      }
      else {
        if (param_1 != '\a') {
          flash_field_write_cached(4,0x20,local_11);
          flash_field_read_cached(4,0x21,&local_11,1);
          if (param_1 == '\x06') {
            if (param_2 == 0) {
              local_11 = local_11 & 0x7f;
              p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xdf;
            }
            else {
              local_11 = local_11 | 0x80;
              p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xdf | 0x20;
            }
            goto LAB_0304cdf6;
          }
          goto LAB_0304cdb8;
        }
        if (param_2 == 0) {
          local_11 = local_11 & 0xfe;
          p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xbf;
          goto LAB_0304ce28;
        }
        local_11 = local_11 | 1;
        p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xbf | 0x40;
      }
      goto LAB_0304ce0c;
    }
    if (param_2 != 0) {
      local_11 = local_11 | 8;
      p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xfb | 4;
      goto LAB_0304ce0c;
    }
    local_11 = local_11 & 0xf7;
    p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xfb;
LAB_0304ce28:
    flash_field_write_cached(4,0x20,local_11);
    flash_field_read_cached(4,0x21,&local_11,1);
  }
  else {
LAB_0304cbc8:
    if (param_1 == '\x01') {
      if (param_2 == 0) {
        local_11 = local_11 & 0xdf;
        p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xfe;
        goto LAB_0304ce28;
      }
      local_11 = local_11 | 0x20;
      p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xfe | 1;
    }
    else {
      if (param_1 != '\x02') goto LAB_0304cc48;
      if (param_2 == 0) {
        local_11 = local_11 & 0xef;
        p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xfd;
        goto LAB_0304ce28;
      }
      local_11 = local_11 | 0x10;
      p_dm32_settings_block04[0x43] = p_dm32_settings_block04[0x43] & 0xfd | 2;
    }
LAB_0304ce0c:
    flash_field_write_cached(4,0x20,local_11);
    flash_field_read_cached(4,0x21,&local_11,1);
  }
LAB_0304cdb8:
  if (param_1 == '\t') {
    if (param_2 == 0) {
      local_11 = local_11 & 0xbf;
      p_dm32_settings_block04[0x44] = p_dm32_settings_block04[0x44] & 0xfe;
    }
    else {
      local_11 = local_11 | 0x40;
      p_dm32_settings_block04[0x44] = p_dm32_settings_block04[0x44] & 0xfe | 1;
    }
  }
LAB_0304cdf6:
  flash_field_write_cached(4,0x21,local_11);
  return;
}

