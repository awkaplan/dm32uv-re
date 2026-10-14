/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_rect_outline_mutex_guarded @ 03017cbc (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void draw_rect_outline_mutex_guarded
               (short param_1,short param_2,short param_3,short param_4,undefined2 param_5)

{
  void *mutex;
  
  mutex = p_ucos_mutex_00039344;
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  draw_line_bresenham(param_1,param_3,param_2,param_3 + 1,param_5);
  draw_line_bresenham(param_1,param_3,param_1 + 1,param_4,param_5);
  draw_line_bresenham(param_2,param_3,param_2 + 1,param_4,param_5);
  draw_line_bresenham(param_1,param_4,param_2,param_4 + 1,param_5);
  os_sem_post(mutex);
  return;
}

