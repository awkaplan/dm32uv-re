/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_read_dispatcher @ 0304c318 (file base 0x03000000; code starts at 0x03001000)
 * Size: 726 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte settings_read_dispatcher(char param_1)

{
  byte bVar1;
  
  if (param_1 == '\x04') {
    bVar1 = p_dm32_settings_block04->field_0x38;
  }
  else if (param_1 == '\x03') {
    bVar1 = p_dm32_settings_block04->standby_text_colour;
  }
  else if (param_1 == '\x06') {
    bVar1 = p_dm32_settings_block04->field_0x29;
  }
  else if (param_1 == '\a') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x30 >> 6 & 1;
  }
  else if (param_1 == '\b') {
    bVar1 = p_dm32_settings_block04->field_0x32 >> 2 & 1;
  }
  else if (param_1 == '\t') {
    bVar1 = p_dm32_settings_block04->field_0x32 >> 3 & 1;
  }
  else if (param_1 == '\n') {
    bVar1 = p_dm32_settings_block04->field_0x32 >> 4 & 1;
  }
  else if (param_1 == '\x05') {
    bVar1 = p_dm32_settings_block04->field_0x3d;
  }
  else if (param_1 == '\x0e') {
    bVar1 = p_dm32_settings_block04->field_0x3e;
  }
  else if (param_1 == '\x0f') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x30 >> 1 & 1;
  }
  else if (param_1 == '.') {
    bVar1 = p_dm32_settings_block04->field_0x57;
  }
  else if (param_1 == '\x10') {
    bVar1 = p_dm32_settings_block04->field_0x41;
  }
  else if (param_1 == '\x1b') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x44 >> 1 & 1;
  }
  else if (param_1 == '\x11') {
    bVar1 = p_dm32_settings_block04->field_0x42;
  }
  else if (param_1 == '\x12') {
    bVar1 = p_dm32_settings_block04->field_0x43 & 1;
  }
  else if (param_1 == '\x13') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x43 >> 1 & 1;
  }
  else if (param_1 == '\x14') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x43 >> 2 & 1;
  }
  else if (param_1 == '\x15') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x43 >> 3 & 1;
  }
  else if (param_1 == '\x16') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x43 >> 4 & 1;
  }
  else if (param_1 == '\x17') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x43 >> 5 & 1;
  }
  else if (param_1 == '\x18') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x43 >> 6 & 1;
  }
  else if (param_1 == '\x19') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x43 >> 7;
  }
  else if (param_1 == '\x1a') {
    bVar1 = p_dm32_settings_block04->field_0x44 & 1;
  }
  else if (param_1 == '\x1e') {
    bVar1 = p_dm32_settings_block04->field_0x47;
  }
  else if (param_1 == '\x1f') {
    bVar1 = p_dm32_settings_block04->field_0x48;
  }
  else if (param_1 == ' ') {
    bVar1 = p_dm32_settings_block04->field_0x49;
  }
  else if (param_1 == '!') {
    bVar1 = p_dm32_settings_block04->field_0x4a;
  }
  else if (param_1 == '\"') {
    bVar1 = p_dm32_settings_block04->field_0x4b;
  }
  else if (param_1 == '#') {
    bVar1 = p_dm32_settings_block04->field_0x4c;
  }
  else if (param_1 == '$') {
    bVar1 = p_dm32_settings_block04->field_0x4d;
  }
  else if (param_1 == '%') {
    bVar1 = p_dm32_settings_block04->field_0x4e;
  }
  else if (param_1 == '&') {
    bVar1 = p_dm32_settings_block04->field_0x4f;
  }
  else if (param_1 == '\'') {
    bVar1 = p_dm32_settings_block04->field_0x50;
  }
  else if (param_1 == '(') {
    bVar1 = p_dm32_settings_block04->field_0x51;
  }
  else if (param_1 == ')') {
    bVar1 = p_dm32_settings_block04->field_0x52;
  }
  else if (param_1 == '*') {
    bVar1 = (byte)p_dm32_settings_block04->field_0x44 >> 2 & 3;
  }
  else if (param_1 == '1') {
    bVar1 = p_dm32_settings_block04->field_0x55;
  }
  else if (param_1 == '-') {
    bVar1 = p_dm32_settings_block04->zone_a_colour;
  }
  else if (param_1 == '0') {
    bVar1 = p_dm32_settings_block04->field_0x32 & 3;
  }
  else if (param_1 == 'A') {
    bVar1 = p_dm32_settings_block04->callsign_colour;
  }
  else if (param_1 == 'G') {
    bVar1 = p_dm32_settings_block04->field_0x70;
  }
  else if (param_1 == 'L') {
    bVar1 = p_dm32_settings_block04->field_0x76;
  }
  else if (param_1 == 'H') {
    bVar1 = p_dm32_settings_block04->field_0x71;
  }
  else if (param_1 == 'M') {
    bVar1 = p_dm32_settings_block04->field_0x77;
  }
  else if (param_1 == 'I') {
    bVar1 = p_dm32_settings_block04->field_0x72;
  }
  else if (param_1 == 'N') {
    bVar1 = p_dm32_settings_block04->field_0x78;
  }
  else if (param_1 == 'J') {
    bVar1 = p_dm32_settings_block04->field_0x73;
  }
  else if (param_1 == 'O') {
    bVar1 = p_dm32_settings_block04->field_0x79;
  }
  else if (param_1 == 'K') {
    bVar1 = p_dm32_settings_block04->field_0x75;
  }
  else if (param_1 == 'P') {
    bVar1 = p_dm32_settings_block04->field_0x7b;
  }
  else {
    bVar1 = 0;
  }
  return bVar1;
}

