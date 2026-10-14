/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_field_multi_step_state_machine @ 030358c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 310 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void status_field_multi_step_state_machine(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bVar4;
  
  if ((((PTR_DAT_03035a04[8] & 1) == 0) && (*(char *)PTR_DAT_03035a08 == '\0')) &&
     ((PTR_DAT_03035a0c[0x2b] & 8) == 0)) {
    iVar3 = settings_read_dispatcher(0xf);
    if ((iVar3 == 1) && (iVar3 = read_byte_field_0302e118(), iVar3 == 0)) {
      cVar1 = *(char *)((int)PTR_DAT_03035a00 + 1);
      if (cVar1 == '\0') {
        cVar1 = *(char *)PTR_DAT_03035a00;
        *(byte *)PTR_DAT_03035a00 = cVar1 + 1U;
        puVar2 = PTR_DAT_03035a00;
        if ((byte)p_dm32_settings_block04[0x57] < (byte)(cVar1 + 1U)) {
          *(undefined1 *)((int)PTR_DAT_03035a00 + 1) = 1;
          if ((*(byte *)((int)puVar2 + 3) & 1) != 0) {
            *(byte *)((int)PTR_DAT_03035a00 + 3) = *(byte *)((int)PTR_DAT_03035a00 + 3) & 0xfe;
          }
          event_queue_reset();
          format_and_write_status_field
                    (0,10,**(undefined4 **)
                            (PTR_PTR_03035a14 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))
          ;
        }
      }
      else {
        if (cVar1 == '\x02') {
          bVar4 = 2;
        }
        else {
          if (cVar1 != '\x04') {
            if (cVar1 != '\x03') {
              return;
            }
            cVar1 = *(char *)PTR_DAT_03035a00;
            *(byte *)PTR_DAT_03035a00 = cVar1 + 1U;
            puVar2 = PTR_DAT_03035a00;
            if ((byte)(cVar1 + 1U) < 2) {
              return;
            }
            *(undefined1 *)((int)PTR_DAT_03035a00 + 1) = 0;
            *(undefined1 *)puVar2 = 0;
            return;
          }
          bVar4 = 1;
        }
        cVar1 = *(char *)PTR_DAT_03035a00;
        *(byte *)PTR_DAT_03035a00 = cVar1 + 1U;
        if (bVar4 < (byte)(cVar1 + 1U)) {
          *(undefined1 *)((int)PTR_DAT_03035a00 + 1) = 1;
        }
      }
    }
    else {
      cVar1 = *(char *)((int)PTR_DAT_03035a00 + 1);
      if (cVar1 == '\x03') {
        cVar1 = *(char *)PTR_DAT_03035a00;
        *(byte *)PTR_DAT_03035a00 = cVar1 + 1U;
        puVar2 = PTR_DAT_03035a00;
        if (1 < (byte)(cVar1 + 1U)) {
          *(undefined1 *)((int)PTR_DAT_03035a00 + 1) = 0;
          *(undefined1 *)puVar2 = 0;
        }
      }
      else if (cVar1 == '\x02') {
        cVar1 = *(char *)PTR_DAT_03035a00;
        *(byte *)PTR_DAT_03035a00 = cVar1 + 1U;
        puVar2 = PTR_DAT_03035a00;
        if (2 < (byte)(cVar1 + 1U)) {
          *(undefined1 *)((int)PTR_DAT_03035a00 + 1) = 1;
          *(undefined1 *)puVar2 = 0;
        }
      }
      else if ((cVar1 == '\x04') &&
              (cVar1 = *(char *)PTR_DAT_03035a00, *(byte *)PTR_DAT_03035a00 = cVar1 + 1U,
              puVar2 = PTR_DAT_03035a00, 2 < (byte)(cVar1 + 1U))) {
        *(undefined1 *)((int)PTR_DAT_03035a00 + 1) = 1;
        *(undefined1 *)puVar2 = 0;
      }
    }
  }
  return;
}

