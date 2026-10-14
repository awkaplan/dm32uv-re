/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: upgrade_mode_enter_and_reset_task @ 0301b83c (file base 0x03000000; code starts at 0x03001000)
 * Size: 280 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void upgrade_mode_enter_and_reset_task(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  void *flaggrp;
  int iVar7;
  undefined1 auStack_28 [4];
  
  iVar7 = iram_call_0002c588_arg0x10();
  puVar1 = PTR_DAT_0301b9c0;
  puVar2 = PTR_DAT_0301b9bc;
  iVar3 = DAT_0301b9b8;
  puVar4 = PTR_PTR_0301b9b4;
  puVar5 = PTR_DAT_0301b9b0;
  pbVar6 = PTR_DAT_0301b9ac;
  flaggrp = DAT_0301b9a8;
  if (iVar7 != 0) {
    gpio_clear_output_bit(0x11);
    puVar1 = PTR_DAT_0301b9c0;
    puVar2 = PTR_DAT_0301b9bc;
    iVar3 = DAT_0301b9b8;
    puVar4 = PTR_PTR_0301b9b4;
    puVar5 = PTR_DAT_0301b9b0;
    pbVar6 = PTR_DAT_0301b9ac;
    flaggrp = DAT_0301b9a8;
  }
  do {
    OSFlagPend_wrapper_consume(flaggrp,0x40000,0,0,auStack_28);
    OSFlagPost_wrapper_clr(flaggrp,0x40000);
    event_queue_reset();
    recording_stop_rx_finalize();
    recording_stop_tx_finalize();
    fd6818b_driver_state_reset();
    config_table_init_entries_0300e924();
    antenna_switch_select_gpio_24_22(0);
    gpio_set_output_bit(0x2c);
    tx_abort_on_condition();
    settings_read_dispatch_0x31_then_hook();
    display_fill_fullscreen_rect_color(0);
    if ((pbVar6[1] & 4) == 0) {
      display_draw_number_centered
                (0x90,0xffff,0,
                 **(uint **)(PTR_PTR_0301b9c8 + (*(byte *)(iVar3 + 0x30) >> 6 & 1) * 8));
    }
    else {
      display_draw_dialog_panel();
      dialog_show_icon_and_two_numbers
                (0x30,0x30,puVar5,*(undefined4 *)puVar4[(*(byte *)(iVar3 + 0x30) >> 6 & 1) * 2],
                 DAT_0301b9c4);
    }
    busy_wait_delay_n_units(1000);
    audio_pa_enable_gate(0);
    gpio_clear_output_bit(0x11);
    iram_call_0002bb18_arg0();
    clock_uart_reconfigure();
    *(undefined1 *)puVar2 = 0;
    *(undefined2 *)puVar1 = 0;
    do {
      while ((*pbVar6 & 0x10) == 0) {
        battery_monitor_adc_tick();
        busy_wait_delay_n_units(100);
      }
      iVar7 = iram_call_0002c588_arg0x10();
    } while ((iVar7 != 0) || ((pbVar6[4] & 0x10) != 0));
    flash_quad_enable_and_system_reset();
  } while( true );
}

