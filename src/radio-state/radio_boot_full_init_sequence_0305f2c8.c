/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_boot_full_init_sequence @ 0305f2c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 474 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_boot_full_init_sequence(void)

{
  undefined4 *puVar1;
  undefined1 auStack_8 [4];
  
  OSTimeDly_ms_wrapper(500);
  radio_event_dispatch_by_name(_DAT_0305f4a4,0);
  board_gpio_defaults_and_encoder_irq_arm();
  hw_timer_counter_to_time_components();
  i2c2_master_init_400khz();
  hr_c7000_modem_core_clock_and_reset_init();
  dac_boot_init_and_sem_create();
  adc_stop_and_reset();
  sysctrl_diplex0_bit17_clear_init();
  spi_m0_init_flash_cs_high();
  boot_drive_pin_0x35_low();
  irq_boot_register_handlers_3b_to_41();
  FUN_0002bf80();
  hw_reg_snapshot_shift12_then_flash_scan();
  hw_port_state_poll_into_ram_mirror();
  if ((*(byte *)PTR_DAT_0305f4a8 & 4) != 0) {
    gps_uart1_init_9600();
  }
  uart0_init(0x1c200);
  OSTimeDly_ms_wrapper(300);
  radio_config_tables_init_with_guard();
  subsystem_buffer_reset_and_task_init_0x600();
  if ((*(byte *)PTR_DAT_0305f4a8 & 0x10) != 0) {
    spi_flash_config_block_magic_scan();
    spi_flash_dual_log_reset_with_marker_scan();
  }
  startup_input_and_flash_state_init();
  lcd_controller_power_on_init_sequence();
  menu_power_on_display_and_keypad_poll_loop();
  FUN_0300d48c();
  FUN_03021b24(0x10,0xf);
  alpu_boot_sem_create_and_auth_init(auStack_8);
  rtc_validate_and_set_default_datetime();
  hr_c7000_modem_core_register_init();
  FUN_0301df04(0);
  hr_c7000_modem_reset_sequence();
  subsystem_buffer_reset_and_task_init_0x400();
  rf_config_load_from_flash_block2();
  rf_chip_init_and_spawn_worker_tasks();
  rx_voice_start_begin_record();
  OSTimeDly_ms_wrapper(100);
  rx_voice_end_stop_rx_record();
  radio_task_group_create();
  ucos3_task_create_prio5_stk0x80();
  periodic_task_and_queue_create_0x180();
  settings_block4_apply_runtime_params();
  dialog_flags_restore_from_flash_0xf00();
  ucos3_task_create_prio38_stk0x180();
  ucos3_task_create_prio11_stk0xc8();
  ucos3_task_create_prio32_stk0x100();
  ucos3_task_create_prio34_stk0x100();
  ucos3_tmr_dlyhnd_create_oneshot_10tick();
  clear_state_byte_pair_03035a00();
  startup_channel01_frequency_load_and_validate();
  scan_list_timer_create_and_flash_load();
  FUN_03054980();
  rda5807m_init();
  OSTimeDly_ms_wrapper(100);
  rda5807m_power_down();
  adc_read_channel_dispatch(2);
  busy_wait_delay_n_units(0x32);
  adc_read_channel_dispatch(2);
  keypad_battery_poll_burst_5x20ms();
  flash_block_value_display_or_fallback(1);
  volume_setting_load_clamp_apply();
  roam_zone_record_init();
  if ((*(byte *)PTR_DAT_0305f4ac & 2) == 0) {
    if ((*(byte *)((int)PTR_DAT_0305f4ac + 3) & 0x20) == 0) {
      ui_event_0xf_if_status_flag40();
      OSTimeDlyHMSM(0,0,1,0,0,auStack_8);
    }
    channel_change_apply_with_zone_and_flash_validate();
  }
  puVar1 = PTR_DAT_0305f4ac;
  *(byte *)((int)PTR_DAT_0305f4ac + 5) = *(byte *)((int)PTR_DAT_0305f4ac + 5) & 0xfd | 2;
  *(byte *)((int)puVar1 + 2) = *(byte *)((int)puVar1 + 2) & 0xf7;
  if ((*(byte *)PTR_DAT_0305f4a8 & 4) == 0) {
    gpio_set_output_bit(0x2c);
  }
  else {
    gpio_clear_output_bit(0x2c);
    peripheral_gpio_and_buffer_init();
  }
  subsystem_sem_create_and_buffer_init_0xa00();
  OSTimeDly_ms_wrapper(200);
  settings_flag_bits_sync_to_dat_03064328();
  OSTimeDly_ms_wrapper(10);
  settings_block_cache_load_from_flash();
  timer_channel_enable_dispatch_arg5h();
  *(undefined1 *)PTR_DAT_0305f4b0 = 0;
  *(byte *)PTR_DAT_0305f4ac = *(byte *)PTR_DAT_0305f4ac & 0xef | 0x10;
  return;
}

