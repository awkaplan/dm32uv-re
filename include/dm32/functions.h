/* GENERATED FILE - do not edit by hand.
 *
 * Prototypes for every decompiled function, with the address it lives at and the
 * confidence of its identification. READ THE CONFIDENCE MARKER: a prototype is only as
 * good as the analysis behind it.
 *
 *   CONFIRMED  - cross-validated against an independent source.
 *   STRUCTURAL - inferred from code shape and call context; plausible, unverified.
 *   RAW        - unmodified decompiler output. Argument count and types are GUESSES;
 *                a `void` return in particular often just means the decompiler could
 *                not prove a value was returned.
 */
#ifndef DM32_FUNCTIONS_H
#define DM32_FUNCTIONS_H

#include "types.h"
#include "structs.h"


/* ---- CONFIRMED (1510 functions) ---- */

uint cpu_sr_save_and_disable_irq_iram(void);  /* 0x0001018c 16B */
void cpu_sr_restore_irq_iram(undefined4 sr);  /* 0x0001019c 6B */
void OS_SchedLockTimeMeasStart(void);  /* 0x0001023c 36B */
void OS_SchedLockTimeMeasStop(void);  /* 0x00010260 56B */
uint msb_bit_position_via_byte_table();  /* 0x000103e0 74B */
void OSCtxSw(void);  /* 0x000105be 42B */
void OSIntCtxSw(void);  /* 0x000105e6 30B */
void irq_vector_entry_wrapper(void);  /* 0x0001064a 4B */
void OS_IdleTask(void);  /* 0x00010868 44B */
void OSIntEnter(void);  /* 0x00010894 26B */
void OSIntExit(void);  /* 0x000108b0 130B */
void OSSched(void);  /* 0x00010934 92B */
void ucos3_pend_list_init(undefined4 *param_1);  /* 0x00010b88 10B */
void fixed_capacity_keyed_record_update(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5);  /* 0x00010d04 64B */
void hashtable_bucket_insert_tail(int param_1);  /* 0x00010eec 96B */
void os_rdylist_move_head_to_tail(int *param_1);  /* 0x00010fc8 60B */
void OS_RdyListRemove();  /* 0x000110bc 138B */
void OS_SchedLockTimeMeasStart_variant4(void);  /* 0x0001117c 20B */
void OSSchedLock(undefined4 *param_1);  /* 0x00011190 92B */
void OS_SchedLockTimeMeasStop_variant4(void);  /* 0x000111ec 46B */
void OSSchedUnlock(undefined4 *param_1);  /* 0x00011250 118B */
void ucos3_task_timeout_requeue(int *param_1);  /* 0x000112c8 158B */
void OS_Pend(int param_1,int param_2,undefined1 param_3,undefined4 param_4);  /* 0x000113bc 78B */
void queue_item_remove_with_conditional_cleanup();  /* 0x0001140c 28B */
void work_item_advance_or_complete_and_unlink(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5);  /* 0x00011428 180B */
void ucos3_message_queue_post_with_overflow_check();  /* 0x00011604 158B */
char OS_PrioGetHighest(void);  /* 0x000119ec 38B */
void OS_PrioInsert();  /* 0x00011a14 30B */
int OSSemPend(int *param_1,undefined4 param_2,short param_3,int *param_4,undefined4 *param_5);  /* 0x00011a58 402B */
void OSSemCreate();  /* 0x00011dbc 152B */
short OSSemDel(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x00011e84 306B */
int OS_SemPost(int param_1,ushort param_2,undefined4 param_3,undefined4 *param_4);  /* 0x00011fe8 228B */
undefined4 OSSemPost(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x000120dc 135B */
void OSTaskChangePrio();  /* 0x00012190 362B */
bool OSTaskRegGetID();  /* 0x000126a0 66B */
int OSTaskSemPend();  /* 0x00012720 390B */
void OSTaskStkChk(int *param_1,int *param_2,int *param_3,undefined4 *param_4);  /* 0x000129f4 88B */
void radio_command_jumptable_dispatch_iram(undefined *param_1,undefined4 *param_2);  /* 0x00012c3c 218B */
void OSTaskCreate();  /* 0x00012dd8 504B */
void OSTaskResume();  /* 0x00013368 100B */
int OS_TaskSemPost(int param_1,short param_2,undefined4 param_3,undefined4 *param_4);  /* 0x000133f4 610B */
undefined4 OSTaskSemPost(undefined4 param_1,short param_2,undefined4 *param_3);  /* 0x00013664 84B */
void active_command_subcommand_dispatcher();  /* 0x000136c8 102B */
void OSTaskSuspend(undefined *param_1,undefined4 *param_2);  /* 0x000137f4 72B */
void OSTimeDly(int param_1,ushort param_2,int *param_3);  /* 0x00013c6c 242B */
void OSTimeDlyHMSM(uint param_1,uint param_2,uint param_3,uint param_4,ushort param_5,int *param_6);  /* 0x00013d60 460B */
void OSTimeDlyResume_dly_arm(void);  /* 0x00013fb6 90B */
void OSTimeDlyResume_dly_suspended_arm(void);  /* 0x00014046 86B */
void OSTimeTick(void);  /* 0x00014128 48B */
byte i2c_bitbang_read_byte_with_ack(char param_1);  /* 0x0001420c 248B */
bool i2c_send_byte_wait_ack(uint param_1);  /* 0x00014304 282B */
undefined4 i2c_write_block_0x7a();  /* 0x00014424 216B */
undefined4 i2c_read_block_0x7a();  /* 0x000144fc 404B */
void modem_workmode_rfmode_reload(void);  /* 0x00016ad0 82B */
void alpu_auth_gate_3retry(undefined1 *param_1);  /* 0x00016bdc 148B */
char alpu_handshake_challenge_read_32byte(void);  /* 0x0001e8bc 568B */
void alpu_cipher_invert_and_fold_halfblock(int param_1);  /* 0x0001eafc 252B */
void alpu_cipher_xor_mix_and_swap_halves(int param_1,int param_2);  /* 0x0001ebf8 318B */
void alpu_cipher_byte_rotate_right(int param_1);  /* 0x0001ed38 228B */
void alpu_cipher_block_rotate_left(undefined1 *param_1);  /* 0x0001ee1c 226B */
void alpu_cipher_byte_permute(undefined1 *param_1);  /* 0x0001ef00 294B */
void alpu_block_cipher(int param_1,int param_2,int param_3,byte param_4,int param_5,char param_6);  /* 0x0001f028 1394B */
char alpu_challenge_response_auth(void);  /* 0x0001f5b0 486B */
char alpu_handshake_response_write_16byte(void);  /* 0x0001f798 450B */
char alpu_handshake_step_sequence(int param_1,int param_2);  /* 0x0001f96c 1238B */
void memcpy_bytes_iram();  /* 0x0002b338 22B */
void memset_bytes();  /* 0x0002b350 18B */
void rf_tx_enable_sequence(void);  /* 0x0002b440 94B */
void rf_tx_disable_sequence(void);  /* 0x0002b4a0 92B */
void fd6818b_reg47_tx_bypass_or_rx_afout(void);  /* 0x0002b51c 50B */
void fd6818b_reg47_afout_clear_mode(void);  /* 0x0002b550 22B */
void fd6818_set_frequency(undefined2 param_1,undefined2 param_2);  /* 0x0002b56c 22B */
void fd6818b_reg47_write_byte_or_6042(short param_1);  /* 0x0002b584 18B */
void fd6818b_reg50_write_bb18(void);  /* 0x0002b598 14B */
void fd6818b_reg50_write_3b18(void);  /* 0x0002b5a8 14B */
void fd6818b_init_seq_filter_ctcss_chipmode(void);  /* 0x0002b5b8 42B */
void fd6818b_filter_select_then_chipmode_normal(void);  /* 0x0002b5e4 58B */
void fd6818b_reg48_cic_mode_write(ushort param_1);  /* 0x0002b624 16B */
void fd6818b_retune_and_reinit_sequence(uint param_1);  /* 0x0002b674 42B */
void spi_flash_cmd1_send(w25q128jv_cmd opcode);  /* 0x0002b814 38B */
void spi_flash_wait_wip(void);  /* 0x0002b83c 92B */
void spi_flash_shadow_addr_set();  /* 0x0002b898 14B */
void spi_flash_page_program_raw(undefined4 param_1,undefined2 param_2);  /* 0x0002b8a8 86B */
void spi_flash_program_pagesplit();  /* 0x0002b900 88B */
void spi_flash_read_data_raw(undefined4 param_1,short param_2);  /* 0x0002b958 66B */
void spi_flash_read_seq();  /* 0x0002b99c 24B */
void spi_flash_read_mutex_guarded(undefined4 param_1,undefined4 param_2,undefined2 param_3);  /* 0x0002ba10 76B */
void spi_flash_write_chunk_pagesplit();  /* 0x0002ba5c 80B */
undefined4 spi_flash_write_multi_sector(uint param_1,int param_2,uint param_3);  /* 0x0002baac 102B */
uint spi_controller_single_byte_xfer(int param_1,uint param_2);  /* 0x0002bf90 50B */
void spi_controller_byte_xfer_rdwr(uint param_1,uint param_2,int param_3,uint param_4,int param_5,ushort param_6);  /* 0x0002bfc4 100B */
void spi_controller_byte_xfer(uint param_1,uint param_2,int param_3,ushort param_4);  /* 0x0002c09c 64B */
void lcd_write_command(lcd_cmd cmd);  /* 0x0002c1cc 10B */
void lcd_write_data(uint param_1);  /* 0x0002c1d8 10B */
void lcd_write_pixel(uint param_1);  /* 0x0002c1e4 18B */
void fd6818b_shift_out_8bit(char param_1);  /* 0x0002c1f8 78B */
void fd6818b_shift_out_16bit(short param_1);  /* 0x0002c248 80B */
ushort fd6818b_shift_in_16bit(void);  /* 0x0002c298 90B */
void fd6818b_reg_write(fd6818_page0 reg,undefined2 value);  /* 0x0002c2f4 70B */
undefined4 fd6818_reg_read(fd6818_page0 reg);  /* 0x0002c33c 72B */
void dac_channel_write_12bit(char param_1,uint param_2);  /* 0x0002c388 42B */
void dac_channel2_write_from_byte(uint param_1);  /* 0x0002c3b4 14B */
void isr_time_slot_inter_rx(void);  /* 0x0002c3c4 16B */
void isr_time_slot_inter_tx(void);  /* 0x0002c42c 38B */
void gpio_set_output_bit(uint param_1);  /* 0x0002c500 68B */
void gpio_clear_output_bit(uint param_1);  /* 0x0002c544 68B */
bool gpio_read_input_bit(uint param_1);  /* 0x0002c588 80B */
void gpio_interrupt_disable_bit(uint param_1);  /* 0x0002c5d8 68B */
void gpio_interrupt_enable_bit_with_polarity(uint param_1,int param_2);  /* 0x0002c61c 188B */
void pa_band_select_vhf_uhf_gpio(int param_1);  /* 0x0002c838 62B */
void timer5_ui_tick_isr(void);  /* 0x0002cab8 216B */
undefined4 uart_tx_poll_mutex_guarded(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4);  /* 0x0002ce78 42B */
undefined4 i2c2_master_read_reg_locked(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4);  /* 0x0002cea8 42B */
bool alpu_i2c_shift_out_byte(byte param_1);  /* 0x0002ced4 128B */
bool fd6818b_bitbang_write_byte_pin8(byte param_1);  /* 0x0002d040 128B */
byte alpu_i2c_shift_in_byte(char param_1);  /* 0x0002d184 122B */
byte fd6818b_bitbang_read_byte_pin8(char param_1);  /* 0x0002d230 122B */
void txslot_tx_slot_service_task(void);  /* 0x0002d604 140B */
undefined4 busy_wait_delay_loop_counted();  /* 0x0002df14 42B */
void busy_wait_delay_loop_short(short param_1);  /* 0x0002df70 14B */
void scaled_busy_wait_delay(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4);  /* 0x0002e06c 106B */
undefined4 identity_return_arg();  /* 0x0002e0f4 98B */
int strlen_unaligned_path(char *param_1);  /* 0x030010e4 28B */
void gpio_drv_set_output(uint param_1,int param_2);  /* 0x03001124 248B */
void gpio_pin_configure(uint param_1,int param_2,int param_3);  /* 0x0300121c 916B */
bool gpio_pin_read(uint param_1);  /* 0x030015b0 80B */
void board_gpio_init(void);  /* 0x03001600 138B */
void dmr_programming_protocol_command_loop(void);  /* 0x030016ac 262B */
ushort crc16_xmodem(byte *param_1,short param_2);  /* 0x03001810 74B */
void refcounted_critical_section_object_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4);  /* 0x03001878 134B */
undefined4 ucos_flag_group_post(int param_1,uint param_2,short param_3,undefined4 param_4,undefined4 *param_5);  /* 0x03001964 440B */
undefined4 noop_stub_03001b24();  /* 0x03001b24 16B */
void mmio_dummy_read_1400000c(void);  /* 0x03001bb0 8B */
void uart0_set_baud_divisor();  /* 0x03001bc8 56B */
void sram_state_word_bit_clear(int param_1,int param_2);  /* 0x03001c50 86B */
uint cpu_sr_save_and_disable_irq(void);  /* 0x030020d4 1B */
void OS_SchedLockTimeMeasStart_variant2(void);  /* 0x0300213c 36B */
void OS_SchedLockTimeMeasStop_variant2(void);  /* 0x0300216c 56B */
void OS_IdleTask_variant2(void);  /* 0x03002418 36B */
void OSIntExit_variant2(void);  /* 0x03002464 120B */
void lazy_device_descriptor_init_once(undefined4 *param_1);  /* 0x0300256c 68B */
void timer_wheel_bucket_drain_and_reset(int param_1);  /* 0x03002704 42B */
void list_node_unlink_and_free_slot(int param_1);  /* 0x030029b4 138B */
void ucos_crit_section_nest_exit_with_lock_time_track_variant2(void);  /* 0x03002aa0 46B */
void message_queue_enqueue_7arg(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4, undefined4 param_5,undefined2 param_6,undefined4 param_7,undefined4 *param_8);  /* 0x03002cc8 158B */
void radio_list_pool_init_and_transact(undefined4 *param_1);  /* 0x03002eac 206B */
int ucos_sem_pend_wait_variant(undefined4 param_1,short param_2,undefined4 *param_3,undefined4 *param_4);  /* 0x03003134 314B */
void protocol_request_struct_build_and_dispatch(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, char param_5,undefined4 *param_6,int param_7,uint param_8,undefined2 param_9, int param_10,undefined4 param_11,ushort param_12,undefined4 *param_13);  /* 0x030032ec 398B */
int OS_TaskSemPost_variant2(int param_1,short param_2,undefined4 param_3,undefined4 *param_4);  /* 0x030034c4 610B */
void timer_entry_insert_hash_bucketed_list_0300(int param_1,uint param_2,short param_3,undefined4 *param_4);  /* 0x03003804 296B */
void OS_TickListUpdate(void);  /* 0x03003978 332B */
int flash_sector_erase_range_4kb(uint param_1,uint param_2);  /* 0x03003e9c 132B */
void uint_to_trimmed_decimal_ascii(int param_1,uint param_2);  /* 0x030040fc 66B */
undefined4 parse_numeric_string_hex_or_decimal_with_suffix(byte *param_1,int *param_2);  /* 0x03004140 300B */
void libc_memcpy_bytes();  /* 0x03004274 22B */
void libc_memset_bytes(undefined1 *param_1,undefined1 param_2,int param_3);  /* 0x0300428c 18B */
void hr_c7000_modem_core_reset_and_poll_ready(void);  /* 0x030043c8 170B */
void noop_stub_0300c0ec(void);  /* 0x0300c0ec 2B */
void crc9_bitserial();  /* 0x0300c154 102B */
void crc32_mpeg2_bitserial();  /* 0x0300c224 92B */
uint internet_checksum16(byte *param_1,int param_2);  /* 0x0300c280 58B */
void audio_ctrl_fm_play_set();  /* 0x0300c2dc 38B */
void noop_stub_0300c3a8();  /* 0x0300c3a8 2B */
void gpio_clear_bit0_wrapper(void);  /* 0x0300c3cc 8B */
void set_flag_byte_03064328_call();  /* 0x0300c3d4 8B */
undefined4 noop_stub_0300c42c(void);  /* 0x0300c42c 6B */
undefined4 noop_stub_0300c434(void);  /* 0x0300c434 4B */
undefined4 radio_event_dispatch_by_name();  /* 0x0300c438 22B */
void OSTimeDly_ms_wrapper(int param_1);  /* 0x0300c4bc 24B */
undefined4 OSSemCreate_shared_name_wrapper();  /* 0x0300c4d4 22B */
undefined4 ucos_sem_del_always(undefined4 param_1);  /* 0x0300c4ec 20B */
int os_sem_pend_ms(void *mutex,int timeout_ms);  /* 0x0300c500 30B */
int os_sem_post(void *mutex);  /* 0x0300c53c 20B */
void guarded_timer_config_apply();  /* 0x0300c550 134B */
void protocol_timer_ensure_valid_or_recreate_wrapper(undefined4 param_1);  /* 0x0300c6e4 14B */
void osflag_pend_consume_with_decisecond_timeout(uint param_1,int param_2,int param_3,void *param_4);  /* 0x0300c700 34B */
void os_flag_post_clear_0300c784(uint flags);  /* 0x0300c730 12B */
void osflag_pend_consume_with_decisecond_timeout_alt(uint param_1,int param_2,int param_3,void *param_4);  /* 0x0300c73c 34B */
void os_flag_post_clear_0300c8d4(uint flags);  /* 0x0300c798 12B */
void osflag_pend_consume_generic(uint param_1,int param_2,uint param_3,void *param_4);  /* 0x0300c7a4 28B */
void os_flag_post_clear_0300c8d8(uint param_1);  /* 0x0300c7cc 12B */
void mutex_pend_with_timeout_0300c8e0(int param_1);  /* 0x0300c820 12B */
void ossem_pend_txslot(int param_1);  /* 0x0300c838 12B */
void mutex_pend_with_timeout_0300c8ec(int param_1);  /* 0x0300c868 12B */
void osflag_post_clear_three_groups(void);  /* 0x0300c874 34B */
void periodic_task_and_queue_create_0x180(void);  /* 0x0300cd6c 66B */
undefined1 get_event_flags_byte0(void);  /* 0x0300cdf4 8B */
undefined1 get_event_flags_byte1(void);  /* 0x0300cdfc 8B */
undefined1 get_event_flags_byte2(void);  /* 0x0300ce04 8B */
undefined1 get_event_flags_byte3(void);  /* 0x0300ce0c 8B */
undefined1 get_event_flags_byte4(void);  /* 0x0300ce14 8B */
undefined1 get_event_flags_byte5(void);  /* 0x0300ce1c 8B */
undefined1 get_event_flags_byte6(void);  /* 0x0300ce24 8B */
undefined1 get_event_flags_byte7(void);  /* 0x0300ce2c 8B */
undefined1 get_event_flags_byte8(void);  /* 0x0300ce34 8B */
undefined1 get_event_flags_byte9(void);  /* 0x0300ce3c 8B */
undefined1 get_event_flags_byte10(void);  /* 0x0300ce52 8B */
undefined1 get_event_flags_byte11(void);  /* 0x0300ce5a 8B */
undefined1 get_event_flags_byte12(void);  /* 0x0300ce62 8B */
undefined1 get_event_flags_byte13(void);  /* 0x0300ce6a 8B */
undefined1 get_event_flags_byte14(void);  /* 0x0300ce72 8B */
undefined4 get_event_flags_noop_stub(void);  /* 0x0300ce7a 4B */
void update_event_flags_byte_dispatch(uint index,uint value);  /* 0x0300ce80 16B */
void update_event_flags_byte0(undefined4 param_1,byte param_2);  /* 0x0300ce9c 16B */
void update_event_flags_byte1(undefined4 param_1,byte param_2);  /* 0x0300ceac 16B */
void update_event_flags_byte2(undefined4 param_1,byte param_2);  /* 0x0300cebc 16B */
void update_event_flags_byte3(undefined4 param_1,byte param_2);  /* 0x0300cecc 16B */
void update_event_flags_byte4(undefined4 param_1,byte param_2);  /* 0x0300cedc 16B */
void update_event_flags_byte5(undefined4 param_1,byte param_2);  /* 0x0300ceec 16B */
void update_event_flags_byte6(undefined4 param_1,byte param_2);  /* 0x0300cefc 16B */
void update_event_flags_byte7(undefined4 param_1,byte param_2);  /* 0x0300cf0c 16B */
void update_event_flags_byte8(undefined4 param_1,byte param_2);  /* 0x0300cf1c 16B */
void update_event_flags_byte9(undefined4 param_1,byte param_2);  /* 0x0300cf2c 16B */
void update_event_flags_byte10(undefined4 param_1,byte param_2);  /* 0x0300cf3c 16B */
void update_event_flags_byte11(undefined4 param_1,byte param_2);  /* 0x0300cf4c 16B */
void update_event_flags_byte12(undefined4 param_1,byte param_2);  /* 0x0300cf5c 16B */
void update_event_flags_byte13(undefined4 param_1,byte param_2);  /* 0x0300cf6c 16B */
void update_event_flags_byte14(undefined4 param_1,byte param_2);  /* 0x0300cf7c 14B */
void update_event_flags_noop_stub(void);  /* 0x0300cf8a 2B */
void ui_mode_group_flag_set_and_post(byte param_1,byte param_2);  /* 0x0300d028 58B */
void set_field_bits_and_post_ui_mode_group_0x10(byte param_1);  /* 0x0300d08c 22B */
void ui_mode_dispatch(uint param_1);  /* 0x0300d0a4 26B */
void ui_mode_noop_stub(void);  /* 0x0300d27a 8B */
void call_setup_debounce_and_ui_state_driver(void);  /* 0x0300d284 326B */
void copy_bytes_from_offset_table();  /* 0x0300d41c 40B */
void rf_config_load_from_flash_block2(void);  /* 0x0300d568 642B */
byte value_at_or_above_low_bound_check();  /* 0x0300d810 22B */
void frequency_band_range_check_and_status_set(uint param_1,uint param_2);  /* 0x0300d84c 458B */
byte value_in_range_multi_band_check(uint param_1);  /* 0x0300da48 62B */
void channel_freq_pair_store(uint param_1,uint param_2);  /* 0x0300da88 146B */
void dmr_rf_tx_task(void);  /* 0x0300dc94 80B */
uint freq_bitpack_crc12_encode(uint param_1);  /* 0x0300de10 80B */
void fd6818b_reg_write_wrapper(void);  /* 0x0300de60 20B */
void hw_register_0x78_write_from_byte_pair();  /* 0x0300de78 20B */
void vfo_step_field_write(uint param_1);  /* 0x0300de8c 124B */
void channel_freq_split_and_crc_finalize(uint param_1);  /* 0x0300dfd8 264B */
void bcd_unpack_u16_on_stack(undefined2 param_1);  /* 0x0300e0f8 18B */
void ctcss_dcs_tone_apply(char param_1,undefined2 param_2);  /* 0x0300e10c 188B */
void radio_init_sequence(void);  /* 0x0300e40c 144B */
void task_body_uCOS3(void);  /* 0x0300e49c 146B */
void fd6818b_pa_power_level_select(char param_1);  /* 0x0300e68c 88B */
void fd6818_tx_deviation_bandwidth_mode_set(char mode);  /* 0x0300e794 70B */
void fd6818b_write_tone_divider_reg07(undefined2 param_1);  /* 0x0300e7e0 12B */
void config_table_entry_dispatch(uint param_1);  /* 0x0300e89c 16B */
void fd6818b_default_register_init(void);  /* 0x0300ecb8 290B */
uint hw_status_bit_select_by_config_field(void);  /* 0x0300ee10 92B */
bool hw_status_bit_check_by_radio_mode(void);  /* 0x0300ee6c 44B */
undefined4 fd6818b_status_register_poll_with_reinit(void);  /* 0x0300eea4 160B */
bool fd6818_pa_status_fault_check(void);  /* 0x0300ef44 140B */
void fd6818b_dtmf_coefficient_table_load(void);  /* 0x0300f068 162B */
void write_flag_and_notify_ui_event0x29(undefined1 param_1);  /* 0x0300f258 14B */
void tx_teardown_config_reset(void);  /* 0x0300f268 58B */
void spi_flash_pending_update_scan_and_invalidate(void);  /* 0x0300f3d0 278B */
int flash_block_id_resolve_locked(byte param_1);  /* 0x0300f594 32B */
ushort flash_page_find_first_free(char param_1);  /* 0x0300f624 102B */
void flash_block_read(ushort block_id,uint offset,void *dest,uint len);  /* 0x0300f71c 98B */
void flash_field_read_cached();  /* 0x0300f780 44B */
void flash_block_write();  /* 0x0300f878 420B */
void flash_field_write_cached();  /* 0x0300fa28 302B */
void flash_page_read_modify_write(byte param_1,uint param_2,undefined1 *param_3,uint param_4,ushort param_5, undefined1 *param_6,ushort param_7);  /* 0x0300fb58 574B */
void flash_record_commit_3field(byte param_1,uint param_2,undefined1 *param_3,uint param_4,ushort param_5, undefined1 *param_6,ushort param_7,ushort param_8,undefined1 *param_9,ushort param_10);  /* 0x0300fda4 756B */
void flash_record_commit_4field(byte param_1,uint param_2,undefined1 *param_3,uint param_4,ushort param_5, undefined1 *param_6,ushort param_7,ushort param_8,undefined1 *param_9,ushort param_10 ,ushort param_11,undefined1 *param_12,ushort param_13);  /* 0x030100a8 1018B */
void channel_bitmap_bit_clear(int param_1);  /* 0x03010558 92B */
void spi_flash_log_append_2byte(undefined4 param_1);  /* 0x030105d0 174B */
void spi_flash_dual_log_reset_with_marker_scan(void);  /* 0x030106b4 330B */
void flash_write_split_across_page_boundary();  /* 0x03010848 94B */
undefined2 recording_index_lookup(uint param_1);  /* 0x030108a8 90B */
void channel_list_compact_and_delete_entry(ushort param_1);  /* 0x03010978 440B */
void mutex_guarded_call_generic3arg();  /* 0x03010ddc 36B */
undefined * font_glyph_ptr_lookup(byte *param_1);  /* 0x03010e6c 28B */
uint flash_table_binary_search_exact_match(int param_1,uint param_2,uint param_3,byte param_4);  /* 0x03010ff4 86B */
int name_tag_encoded_length_table_lookup(uint param_1);  /* 0x0301104c 108B */
void comma_delimited_field_extractor(int param_1,undefined1 *param_2,int param_3,int param_4);  /* 0x030113c8 88B */
char string_find_nth_comma_index(char *param_1,char param_2);  /* 0x03011420 48B */
int nmea_latlon_pack_deg_1e5();  /* 0x03011450 130B */
void gps_coordinate_seconds_to_hms_string_format();  /* 0x030114f4 146B */
void peripheral_gpio_and_buffer_init(void);  /* 0x03011588 128B */
void circular_line_buffer_char_append(void);  /* 0x03011748 194B */
uint nth_comma_field_offset_lookup(uint param_1);  /* 0x0301185c 82B */
void serial_rx_ringbuffer_line_extract(void);  /* 0x030118b0 124B */
byte nmea_sentence_checksum_from_ring_buffer(int param_1);  /* 0x0301192c 112B */
byte star_delimited_two_hex_digit_decode(int param_1);  /* 0x030119ac 72B */
void gps_coordinate_table_entry_parse(uint param_1,char *param_2,char *param_3);  /* 0x03011aa4 124B */
void gps_nmea_datetime_to_rtc_sync(void);  /* 0x0301265c 248B */
void gps_nmea_rmc_gga_sentence_parser(void);  /* 0x03012758 868B */
void device_telemetry_report_build(void);  /* 0x03012b0c 496B */
void main_ptt_and_channel_event_loop(void);  /* 0x03012d10 260B */
void keypad_scan_begin_mux_rows_drive_low(void);  /* 0x03012e14 68B */
void radio_config_tables_init_with_guard(void);  /* 0x03012e84 196B */
byte bitwise_not_of_boolean_result(void);  /* 0x03012f48 14B */
void keypad_debounce_and_commit_event(void);  /* 0x03012f58 190B */
void keymsgq_command_dispatch_and_store(void);  /* 0x03013144 50B */
void ui_background_periodic_subtask_dispatcher(void);  /* 0x030131e4 482B */
uint gpio_portb_read_input_bits_17_to_20(void);  /* 0x030135d8 12B */
void gpioc_reg0_set_bits(uint param_1);  /* 0x030135e4 46B */
uint scan_entry_get_mode_bits(byte param_1);  /* 0x03014198 56B */
void keypad_back_key_press_handler(void);  /* 0x03014a00 84B */
undefined4 ui_dialog_tick_scheduler(int param_1);  /* 0x03014ae4 512B */
void write_field2_and_mbox_post();  /* 0x03014da4 12B */
void tx_teardown_reset_if_flags_5_6_set();  /* 0x03014e28 36B */
void keypress_counter_persist_and_dialog_tick(void);  /* 0x03014f34 250B */
void ui_key_and_menu_event_dispatch_loop(void);  /* 0x030152cc 294B */
void alarm_banner_draw();  /* 0x03015428 118B */
void vfo_ab_display_redraw_dispatch();  /* 0x030154a0 336B */
void scan_entry_initiate_and_show_range(void);  /* 0x03015714 232B */
void record_switch_toggle(void);  /* 0x03015bb0 230B */
void vfo_channel_step_on_key_event(void);  /* 0x03015d0c 184B */
void vfo_save_to_memory_channel(void);  /* 0x03015e5c 444B */
void vfo_save_to_memory_or_clear_channel(void);  /* 0x03016030 436B */
void scan_group14_resume_or_stop_status_update(void);  /* 0x03016280 170B */
void tx_call_abort_to_idle(void);  /* 0x03016534 164B */
void scan_entry_status_update_tone_aware(void);  /* 0x030165f4 224B */
void scan_group11_call_log_record_or_notify(void);  /* 0x030166d4 170B */
void dmr_scan_entry_toggle_and_reload(void);  /* 0x030167a8 278B */
void scan_list_flash_load_and_build(void);  /* 0x03016944 942B */
void keypad_tmrkey_event_post_and_close(undefined1 param_1);  /* 0x03016d48 28B */
void noop_stub_03016ea0(void);  /* 0x03016ea0 2B */
undefined4 zone_up_down_toggle_handler(char param_1);  /* 0x030171f0 186B */
void ui_event_notify_dispatch_by_code(char param_1);  /* 0x03017548 126B */
void channel_record_commit(void);  /* 0x0301765c 564B */
void lcd_set_orientation(char normal_orientation);  /* 0x030178ec 30B */
void lcd_ram_write_begin(void);  /* 0x0301790c 10B */
void lcd_set_column_range(undefined1 param_1,undefined1 param_2);  /* 0x03017950 38B */
void display_plot_pixel(undefined2 param_1,undefined2 param_2,undefined2 param_3);  /* 0x030179a4 24B */
void display_plot_glyph_2color();  /* 0x030179bc 148B */
void display_draw_circle_bresenham(uint param_1,uint param_2,uint param_3,undefined2 param_4);  /* 0x03017b00 226B */
void display_set_x_window(ushort x_start,ushort x_end);  /* 0x03017be8 38B */
void display_set_y_window(ushort y_start,ushort y_end);  /* 0x03017c10 38B */
void display_set_window(ushort param_1,ushort param_2,ushort param_3,ushort param_4);  /* 0x03017c38 24B */
void display_fill_rect(short x0,short y0,short x1,short y1,ushort color);  /* 0x03017c50 106B */
void draw_rect_outline_mutex_guarded(short param_1,short param_2,short param_3,short param_4,undefined2 param_5);  /* 0x03017cbc 104B */
void display_fill_fullscreen_rect_color(ushort param_1);  /* 0x03017d24 26B */
void lcd_controller_power_on_init_sequence(void);  /* 0x03017d4c 506B */
void display_fill_screen(ushort color);  /* 0x03017f54 72B */
void lcd_blit_image_from_spi_flash(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5);  /* 0x0301802c 240B */
void display_bitfield_serialize_16byte(short param_1,short param_2,int param_3,undefined2 param_4,undefined2 param_5);  /* 0x030181d0 166B */
void dual_6x8_glyph_bitmap_blit(short param_1,uint param_2,byte *param_3,undefined2 param_4);  /* 0x030182d4 172B */
void lcd_draw_dualcolor_bitmap_40x8(short param_1,short param_2,int param_3,undefined2 param_4,undefined2 param_5);  /* 0x03018380 250B */
void display_fill_glyph_cell(short param_1,short param_2,undefined2 param_3);  /* 0x0301851c 62B */
void display_draw_string_mixed_ascii_gb2312(undefined2 param_1,ushort param_2,byte *param_3,undefined2 param_4);  /* 0x030187f8 196B */
void display_draw_glyph_row_mutex(short param_1,ushort param_2,byte *param_3,undefined2 param_4,undefined2 param_5);  /* 0x030188bc 208B */
void display_draw_string_gb2312(short x,ushort y,byte *text,ushort fg,ushort bg);  /* 0x03018998 254B */
undefined4 display_draw_number_centered_dispatch();  /* 0x03018a98 100B */
int display_draw_number_centered();  /* 0x03018b5c 90B */
void display_draw_frequency();  /* 0x03018c14 194B */
void display_blit_bitmap_1bpp();  /* 0x03018de0 132B */
void standby_screen_refresh(void);  /* 0x03018e64 106B */
void vfo_standby_row_render(char param_1);  /* 0x03018ed0 1248B */
void display_draw_status_bar(void);  /* 0x03019434 338B */
void standby_screen_refresh_with_statusbar(void);  /* 0x030195cc 12B */
void dual_plane_bitmap_icon_render(uint param_1,short param_2,uint param_3,int param_4,undefined2 param_5);  /* 0x03019680 216B */
void display_blit_packed_bitmap_row();  /* 0x03019770 210B */
void display_blit_bitmap_1bpp_rows();  /* 0x03019904 274B */
void lcd_draw_monochrome_bitmap_icon();  /* 0x03019a24 258B */
void display_clear_channel_row_background();  /* 0x03019b60 70B */
void display_draw_gb2312_label_top_by_config_bit(ushort param_1);  /* 0x03019c9c 44B */
void display_draw_gb2312_label_bottom_by_config_bit(ushort param_1);  /* 0x03019d00 44B */
void display_draw_gb2312_label_top_alt(ushort param_1);  /* 0x03019d2c 44B */
void display_draw_string_wrapped();  /* 0x03019d58 326B */
void menu_list_row_draw_with_icon(uint param_1,byte *param_2,char param_3,char param_4);  /* 0x03019ebc 264B */
void display_draw_string_wrapped2(ushort param_1,ushort param_2,byte *param_3,undefined2 param_4,undefined2 param_5);  /* 0x03019ff4 234B */
void display_draw_string_mutex_variant(undefined2 param_1,ushort param_2,byte *param_3,undefined2 param_4, undefined2 param_5);  /* 0x0301a10c 200B */
void display_draw_string_ascii_mixed(short param_1,ushort param_2,byte *param_3,ushort param_4,undefined2 param_5, undefined2 param_6);  /* 0x0301a1d4 218B */
void display_draw_two_tone_progress_bar(short param_1,short param_2,uint param_3,uint param_4);  /* 0x0301a390 68B */
void noop_stub_0301a490(void);  /* 0x0301a490 2B */
void display_clear_status_row_at_y_by_flag(char param_1);  /* 0x0301a494 54B */
void display_refresh_tone_mode_icon(void);  /* 0x0301a4cc 230B */
void noop_stub_0301a5d0();  /* 0x0301a5d0 2B */
void noop_stub_0301a5d8();  /* 0x0301a5d8 2B */
void display_text_encode_with_width_fit_check(byte *param_1);  /* 0x0301a5dc 190B */
void display_draw_string_centered_mixed(char param_1,byte *param_2,undefined4 param_3,undefined2 param_4);  /* 0x0301a6b4 282B */
void vfo_frequency_panel_render(void);  /* 0x0301a7d0 742B */
void status_field_glyph_or_ascii_render();  /* 0x0301aafc 88B */
void duration_seconds_decimal_display();  /* 0x0301ac08 68B */
void settings_duration_seconds_display();  /* 0x0301ac4c 80B */
void numeric_value_display_centered();  /* 0x0301ac9c 100B */
void ptt_id_status_screen_render();  /* 0x0301ad00 480B */
char frequency_to_step_index_resolve(uint param_1,char param_2,char param_3);  /* 0x0301af74 134B */
undefined1 freq_calibration_interpolate_single(uint param_1);  /* 0x0301b130 214B */
void display_update_datetime();  /* 0x0301b6a8 334B */
void battery_percentage_display_update(void);  /* 0x0301ba34 104B */
void dialog_type_icon_draw_with_color(void);  /* 0x0301ba9c 120B */
void display_toggle_box_or_bitmap_by_flag();  /* 0x0301bcf0 62B */
void call_setup_timeout_countdown(void);  /* 0x0301bd7c 192B */
void vfo_field_write_bit4_at_0x15(int param_1);  /* 0x0301be6c 278B */
byte rtc_register_read(byte reg);  /* 0x0301c2d4 26B */
uint rtc_decode_calendar_date(void);  /* 0x0301c2f0 354B */
void rtc_register_0x11_set_bit2(void);  /* 0x0301c480 22B */
undefined4 rtc_date_validate_and_write();  /* 0x0301c498 322B */
void rtc_validate_and_set_default_datetime(void);  /* 0x0301c608 102B */
int datetime_to_unix_timestamp(uint param_1,uint param_2);  /* 0x0301c670 254B */
undefined4 unix_time_to_date_components(uint param_1);  /* 0x0301c7f0 298B */
undefined4 table_entry_write_word0(uint param_1,undefined4 param_2);  /* 0x0301c92c 14B */
undefined4 table_entry_write_field_0x14(uint param_1,undefined4 param_2);  /* 0x0301c93c 16B */
undefined4 spi_m0_init_flash_cs_high(void);  /* 0x0301c94c 68B */
uint spi_drv_txrx(int param_1,uint param_2);  /* 0x0301c998 50B */
void spi_m3_select_and_read_block();  /* 0x0301c9cc 60B */
void lcd_bus_pads_restore_after_keypad_scan(void);  /* 0x0301cad0 18B */
void adc_stop_and_reset(void);  /* 0x0301caec 88B */
undefined4 adc_read_channel_dispatch(uint param_1);  /* 0x0301cb44 90B */
uint adc_read_ch0_low10(void);  /* 0x0301cba8 12B */
uint adc_read_ch0_high9(void);  /* 0x0301cbb4 12B */
uint adc_read_ch1_low10(void);  /* 0x0301cbc0 12B */
uint adc_read_ch1_high9(void);  /* 0x0301cbcc 12B */
uint adc_read_ch2_low10(void);  /* 0x0301cbd8 12B */
uint adc_read_ch2_high9(void);  /* 0x0301cbe4 12B */
uint adc_read_ch3_low10(void);  /* 0x0301cbf0 12B */
uint adc_read_ch3_high9(void);  /* 0x0301cbfc 22B */
void mask_in_place_and(undefined4 param_1,undefined4 param_2,uint param_3,uint *param_4);  /* 0x0301d274 8B */
void hr_c7000_modem_core_clock_and_reset_init(void);  /* 0x0301d5f8 176B */
void timer_channel_enable_dispatch(uint param_1);  /* 0x0301d740 14B */
void timer_ch0_enable(void);  /* 0x0301d754 12B */
void timer_ch1_enable(void);  /* 0x0301d760 12B */
void timer_ch2_enable(void);  /* 0x0301d76c 12B */
void timer_ch3_enable(void);  /* 0x0301d778 12B */
void timer_ch4_enable(void);  /* 0x0301d784 10B */
void timer_channel_enable_noop_stub(void);  /* 0x0301d78e 2B */
void timer_channel_readwrite_dispatch();  /* 0x0301d790 14B */
void timer_ch0_write_period(undefined4 param_1,dword param_2);  /* 0x0301d7a4 8B */
void timer_ch1_write_period(undefined4 param_1,dword param_2);  /* 0x0301d7ac 8B */
void timer_ch2_write_period(undefined4 param_1,dword param_2);  /* 0x0301d7b4 8B */
void timer_ch3_write_period(undefined4 param_1,dword param_2);  /* 0x0301d7bc 8B */
void timer_ch4_write_period(undefined4 param_1,dword param_2);  /* 0x0301d7c4 6B */
void timer_readwrite_noop_stub1(void);  /* 0x0301d7ca 2B */
dword timer_ch0_read_status(void);  /* 0x0301d7e0 8B */
dword timer_ch1_read_status(void);  /* 0x0301d7e8 8B */
dword timer_ch2_read_status(void);  /* 0x0301d7f0 8B */
dword timer_ch3_read_status(void);  /* 0x0301d7f8 8B */
dword timer_ch4_read_status(void);  /* 0x0301d800 8B */
void timer_readwrite_noop_stub2(void);  /* 0x0301d808 2B */
undefined4 hw_timer_counter_to_time_components(void);  /* 0x0301d860 122B */
void timer_ch1_disable(void);  /* 0x0301d920 12B */
void tx_forbid_flag_clear(void);  /* 0x0301d92c 34B */
void tx_forbid_flag_clear_call(void);  /* 0x0301d950 8B */
undefined4 gps_uart1_init_9600(void);  /* 0x0301d96c 102B */
void uart_tx_chunked_mutex_send();  /* 0x0301d9d4 116B */
undefined4 uart0_init(uint param_1);  /* 0x0301da48 96B */
void i2c2_master_init_400khz(void);  /* 0x0301dacc 114B */
undefined4 i2c2_master_write_reg(uint param_1,uint param_2,int param_3,uint param_4);  /* 0x0301db40 204B */
void i2c2_master_read_reg(uint param_1,uint param_2,int param_3,uint param_4);  /* 0x0301dc1c 238B */
undefined4 bitbang_serial_command_read_pins56(byte param_1,undefined1 param_2,int param_3,int param_4);  /* 0x0301dd0c 250B */
undefined4 bitbang_serial_command_read_pins78(byte param_1,undefined1 param_2,int param_3,int param_4);  /* 0x0301de08 250B */
int call_setup_step_permitted(char mode_a,char mode_b,byte *out_flag);  /* 0x0301df0c 168B */
int call_setup_state_machine_step(char param_1,char param_2,byte *param_3);  /* 0x0301e034 1230B */
void call_setup_sm_reset_and_status_clear(void);  /* 0x0301e528 74B */
void audio_ctrl_ring_play_set(int param_1);  /* 0x0301e598 36B */
void status_byte_bit5_set_clear(undefined4 param_1,char param_2);  /* 0x0301e600 38B */
void call_setup_sm_aux_field24_store();  /* 0x0301e840 6B */
void call_setup_sm_aux_field_0x2c_store(uint param_1,undefined4 param_2);  /* 0x0301e858 12B */
void mmio_11000384_low_byte_write(byte param_1);  /* 0x0301e864 26B */
void call_setup_sm_arm(byte mode,byte param);  /* 0x0301e8dc 26B */
void call_setup_sm_reset(void);  /* 0x0301e8f8 22B */
void dmr_call_setup_state_machine_task(void);  /* 0x0301e9cc 216B */
void protocol_control_char_dispatch_dialog_history(char param_1);  /* 0x0301eb90 176B */
void field_mode_write_and_dispatch_to_0301f170();  /* 0x0301ec58 98B */
bool call_state_not_idle_check(void);  /* 0x0301eda8 48B */
void contact_name_field_encode_to_display_buffer(byte param_1,byte param_2,int param_3);  /* 0x0301ede4 274B */
void dmr_privacy_alg_select_from_cps_type(int param_1);  /* 0x0301f074 168B */
void dmr_privacy_type_apply();  /* 0x0301f11c 34B */
undefined1 call_setup_ack_retry_and_history_log_loop(void);  /* 0x0301f1c0 3148B */
void dmr_call_setup_teardown_event_loop(void);  /* 0x03020044 1600B */
void memcpy_from_const_0302076c();  /* 0x03020750 12B */
void rxvoice_task_entry(void);  /* 0x03020778 702B */
void rxcsbk_build_reply_task(void);  /* 0x03020a8c 842B */
uint set_status_bit_dispatch_alt_caller(uint param_1,undefined4 param_2);  /* 0x03020e70 188B */
int call_setup_state_machine_step_with_timeout(void);  /* 0x03020f70 226B */
undefined1 call_setup_or_teardown_handler(char param_1,uint param_2,undefined4 param_3,char param_4);  /* 0x0302108c 492B */
void voice_recorder_task(void);  /* 0x030212f4 636B */
void set_status_bit_dispatch(uint index,uint value);  /* 0x03021598 16B */
void set_status_bit0(undefined4 param_1,byte param_2);  /* 0x030215ac 12B */
void set_status_bit1(undefined4 param_1,byte param_2);  /* 0x030215b8 12B */
void set_status_bit2(undefined4 param_1,byte param_2);  /* 0x030215c4 12B */
void set_status_bit3(undefined4 param_1,byte param_2);  /* 0x030215d0 12B */
void set_status_bit4(undefined4 param_1,byte param_2);  /* 0x030215dc 12B */
void set_status_bit5(undefined4 param_1,byte param_2);  /* 0x030215e8 10B */
void set_status_bit_noop_stub(void);  /* 0x030215f2 2B */
void mmio_11000108_high_word_write_from_byte(uint param_1);  /* 0x0302180c 32B */
void mmio_11000114_low_word_duplicate_write();  /* 0x03021830 26B */
void noop_stub_0302184c();  /* 0x0302184c 2B */
void rx_voice_start_begin_record(void);  /* 0x03021948 172B */
void rx_voice_end_stop_rx_record(void);  /* 0x03021a14 92B */
void tx_voice_start_begin_record(void);  /* 0x03021a70 154B */
void hr_c7000_modem_reset_sequence(void);  /* 0x03021b80 212B */
void ui_event_notify(byte event_id);  /* 0x03021ca4 40B */
void tone_mixer_3osc_additive();  /* 0x03021e68 506B */
void flash_audio_clip_playback_pcm(uint param_1,int param_2,int param_3);  /* 0x030222f0 244B */
void flash_audio_clip_sequence_playback(uint param_1);  /* 0x03022400 164B */
void tone_ptt_preamble_seq0();  /* 0x030224a4 268B */
void tone_ptt_preamble_seq1(void);  /* 0x030225d4 32B */
void tone_ptt_preamble_seq3(void);  /* 0x03022636 64B */
void tone_ptt_preamble_seq5(void);  /* 0x030226de 114B */
void tone_ptt_preamble_seq8(void);  /* 0x030227ba 28B */
void tone_ptt_preamble_seq9(void);  /* 0x030227d6 30B */
void tone_ptt_preamble_seq11(void);  /* 0x03022810 28B */
void tone_ptt_preamble_seq13(void);  /* 0x0302284a 28B */
void tone_ptt_preamble_seq16(void);  /* 0x030228a0 32B */
void tone_ptt_preamble_seq17(void);  /* 0x030228c0 70B */
void tone_ptt_preamble_seq18(void);  /* 0x03022906 72B */
void tone_ptt_preamble_seq19(void);  /* 0x03022954 72B */
void tone_ptt_preamble_seq24(void);  /* 0x03022a84 100B */
void tone_ptt_preamble_seq28(void);  /* 0x03022b8a 104B */
void tone_ptt_preamble_seq32(void);  /* 0x03022c86 78B */
void tone_ptt_preamble_seq34(void);  /* 0x03022cde 92B */
void pcm_sample_mix_and_process_loop(uint param_1,uint param_2,uint param_3);  /* 0x03022e98 254B */
void tx_gate_companded_audio_burst_send(undefined1 param_1);  /* 0x03022fac 150B */
int float_to_decimal_string_formatter(int param_1,float param_2,byte param_3,uint param_4);  /* 0x03023128 190B */
void modem_layer2_regs_clear(void);  /* 0x0302323c 22B */
void modem_set_layer2_mode(char param_1);  /* 0x03023254 150B */
void modem_set_mode_variant(void);  /* 0x030232ec 56B */
void modem_mode_select(byte param_1,byte param_2);  /* 0x03023324 192B */
void dmr_call_config_reset_and_flag(void);  /* 0x030233f8 48B */
void hr_c7000_modem_core_register_init(void);  /* 0x03023608 498B */
void mode_gated_field_copy_or_invert(char param_1);  /* 0x0302384c 102B */
byte dmr_call_setup_block_d_byte5_read(void);  /* 0x030238b4 6B */
void call_setup_set_pending_flag(void);  /* 0x03023af4 8B */
void clear_byte_field_dat03023b88_0x15(void);  /* 0x03023afc 8B */
byte bitwise_not_of_nonzero_check(void);  /* 0x03023b04 10B */
void control_reg_conditional_set_with_status_xor(void);  /* 0x03023b1c 78B */
bool call_setup_target_present_check(void);  /* 0x03023b90 48B */
void call_setup_sm_field0x72_and_0x78_clear(void);  /* 0x03023bc0 14B */
void modem_timeout_stop_and_history_record_task(void);  /* 0x03023bd0 198B */
char call_index_get_1based(void);  /* 0x03023c98 12B */
undefined4 call_abort_by_index(byte param_1);  /* 0x03023ca4 58B */
char bit_pattern_match_count_with_position_gate(byte param_1,char param_2);  /* 0x03023d30 46B */
char count_table_entries_sharing_bit(byte param_1);  /* 0x03023d60 28B */
undefined4 char_in_allowlist_table_check(char param_1);  /* 0x03023d7c 58B */
void clear_byte_field_dat0302432c_plus3(void);  /* 0x03024228 14B */
void scan_timer_apply_random_jitter();  /* 0x03024238 128B */
void protocol_frame_field_pack_and_send_0x12(uint param_1,ushort param_2,uint param_3);  /* 0x0302454c 148B */
void protocol_frame_field_copy_and_send(void);  /* 0x0302470c 124B */
void history_record_push(void);  /* 0x03024828 210B */
void protocol_state_write_and_apply_sequence(undefined4 param_1,ushort param_2,char param_3);  /* 0x03024928 74B */
void config_struct_field_write_dispatch(void);  /* 0x03024f10 252B */
void config_struct_bitfield_unpack_and_reset(void);  /* 0x03025030 122B */
void config_struct_bitfield_unpack_and_reset_variant5(void);  /* 0x030250aa 106B */
void config_struct_bitfield_unpack_and_reset_variant2(void);  /* 0x03025114 138B */
void config_struct_bitfield_unpack_and_reset_variant4(void);  /* 0x0302519e 122B */
void config_struct_bitfield_unpack_and_reset_variant3(void);  /* 0x03025224 140B */
void config_struct_bitfield_unpack_and_reset_variant6(void);  /* 0x030252b0 156B */
void config_struct_reset_only_no_unpack(void);  /* 0x0302534c 70B */
void serial_9bit_frame_handler_with_crc_validate();  /* 0x03025514 1662B */
void protocol_packet_field_pack_8byte(char *param_1,char param_2);  /* 0x03025bbc 148B */
void protocol_packet_build_with_checksum(char *param_1,char param_2);  /* 0x03025c54 490B */
undefined4 dmr_message_split_into_history_slots(int param_1);  /* 0x03026158 1108B */
undefined4 history_message_fragment_and_link(int param_1,char param_2);  /* 0x03026694 710B */
undefined4 dmr_history_bitmask_record_builder(undefined1 param_1,char param_2,byte *param_3,byte param_4);  /* 0x030269f0 170B */
undefined4 call_teardown_packet_build_and_history_push(undefined1 param_1,char param_2,undefined4 param_3,undefined1 param_4,undefined2 param_5, short param_6,undefined4 param_7,undefined4 param_8,char param_9);  /* 0x03026aa8 410B */
undefined4 dmr_text_packet_builder_and_log(undefined1 param_1,char param_2,undefined4 param_3,undefined1 param_4,undefined4 param_5, short param_6,undefined2 param_7,undefined2 param_8,undefined4 param_9,undefined4 param_10 ,char param_11);  /* 0x03026c4c 694B */
void call_setup_packet_build_and_history_push(undefined1 param_1,char param_2,undefined4 param_3,undefined1 param_4, undefined2 param_5,short param_6,undefined4 param_7,undefined4 param_8,char param_9);  /* 0x03026f0c 456B */
bool dmr_call_config_state_not_idle(void);  /* 0x03027368 12B */
bool dmr_call_config_state_field2_not_one(void);  /* 0x030273b4 20B */
bool call_setup_state_advance_gate(void);  /* 0x030273c8 36B */
undefined4 noop_stub_030273ec(void);  /* 0x030273ec 4B */
undefined4 noop_stub_030273f0(void);  /* 0x030273f0 4B */
void dmr_incoming_call_setup_conflict_resolve(void);  /* 0x0302741c 478B */
void deferred_task_dispatch_on_timer_match(void);  /* 0x030276bc 98B */
void dmr_call_setup_event_dispatch(void);  /* 0x03027c30 548B */
void dmr_call_setup_message_dispatch_by_type(void);  /* 0x03027f16 286B */
void call_setup_frame_ack_dispatch_wrapper(void);  /* 0x03028096 8B */
void noop_stub_0302814e(void);  /* 0x0302814e 4B */
void dmr_call_setup_message_handler(void);  /* 0x03028154 170B */
void modem_control_state_stop(void);  /* 0x030293ac 26B */
void clear_byte_at_ptr();  /* 0x03029554 6B */
undefined4 dmr_call_history_slot_register(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4, undefined4 param_5);  /* 0x03029620 138B */
undefined4 dmr_call_history_slot_register_short(undefined4 param_1);  /* 0x030296ac 92B */
bool call_event_record_append_to_history(char param_1,char param_2,char param_3,undefined4 param_4,uint param_5, undefined4 param_6);  /* 0x03029708 282B */
undefined4 history_slot_allocate_and_init(char param_1,undefined4 param_2);  /* 0x03029838 212B */
void history_record_push_type3(void *record);  /* 0x0302990c 70B */
void tx_queue_walk_and_send_per_slot(uint param_1);  /* 0x03029c30 82B */
void history_push_call_and_type3(undefined4 param_1,undefined4 param_2);  /* 0x03029d9c 52B */
void noop_stub_03029ed8(void);  /* 0x03029ed8 4B */
void clear_two_state_bytes_03029fc8(void);  /* 0x03029f30 12B */
void clear_counter_block_0302a19c(void);  /* 0x0302a014 28B */
void store_u32_le(undefined4 param_1,undefined1 *param_2);  /* 0x0302a030 18B */
void serial_protocol_vframe_command_loop(void);  /* 0x0302a044 1042B */
undefined4 serial_protocol_vframe_command_loop_variant(void);  /* 0x0302a4dc 1252B */
void rtc_chip_response_poll_and_date_apply(void);  /* 0x0302aa3c 170B */
void cps_serial_field_rw_dispatcher(void);  /* 0x0302aaec 122B */
void cps_serial_field_rw_reentry0(void);  /* 0x0302ab84 36B */
void cps_serial_field_rw_reentry1(void);  /* 0x0302aba8 36B */
void cps_serial_field_rw_reentry2(void);  /* 0x0302abcc 38B */
void cps_serial_field_rw_reentry3(void);  /* 0x0302abf2 36B */
void cps_serial_field_rw_reentry4(void);  /* 0x0302ac16 38B */
void cps_serial_field_rw_reentry5(void);  /* 0x0302ac3c 38B */
void cps_serial_field_rw_reentry6(void);  /* 0x0302ac62 38B */
void cps_serial_field_rw_reentry7(void);  /* 0x0302ac88 38B */
void cps_serial_field_rw_reentry8(void);  /* 0x0302acae 36B */
void cps_serial_field_rw_reentry9(void);  /* 0x0302acd2 36B */
void cps_serial_field_rw_dispatcher_variant(void);  /* 0x0302ae0e 1136B */
void serial_password_command_handler(void);  /* 0x0302b2b8 262B */
void cps_serial_handshake_command_dispatcher(void);  /* 0x0302b3d4 736B */
void call_duration_accumulator_tick(void);  /* 0x0302b8b0 110B */
void display_wrapped_text_paginator(int param_1,ushort param_2,ushort param_3);  /* 0x0302b920 204B */
void talker_alias_info_screen(void);  /* 0x0302ba20 1708B */
void ptt_active_icon_draw_dual_slot(void);  /* 0x0302c17c 216B */
void talker_alias_screen_refresh_by_call_state(void);  /* 0x0302c27c 106B */
void status_datetime_dialog_pending_check(void);  /* 0x0302c3a8 34B */
void talker_alias_display_debounce_tick(void);  /* 0x0302c3cc 80B */
void incoming_call_display_screen(void);  /* 0x0302c41c 218B */
byte ptt_ui_state_machine_update(void);  /* 0x0302c5c8 752B */
void contact_field_name_display_dispatch(void);  /* 0x0302c8fc 58B */
void message_notification_dialog_draw(void);  /* 0x0302c9e4 80B */
void noop_stub_0302cd46(void);  /* 0x0302cd46 4B */
void contact_name_field_refresh_dispatch(void);  /* 0x0302ce90 64B */
void tx_release_debounce_timer(void);  /* 0x0302cf84 144B */
void vfo_status_screen(void);  /* 0x0302d01c 338B */
void status_row_redraw_with_selftoggle_noop(void);  /* 0x0302d530 126B */
void talker_alias_refresh_gate_by_dialog_flags(void);  /* 0x0302d5b0 52B */
void dialog_timeout_tick_and_notify(void);  /* 0x0302d6c0 62B */
void dialog_display_refresh_and_flag_clear(void);  /* 0x0302d700 70B */
void post_dialog_close_screen_dispatch(void);  /* 0x0302d748 84B */
void caller_info_dialog_show_and_clear_flags(void);  /* 0x0302d848 58B */
void dialog_request_tick(void);  /* 0x0302d884 438B */
void dialog_panel_update_tick(void);  /* 0x0302da7c 384B */
void call_log_writer_task_loop(void);  /* 0x0302df64 394B */
void bcd_frequency_bound_clamp(char param_1,uint param_2,byte *param_3);  /* 0x0302e12c 100B */
undefined1 scan_list_entry_byte_read(ushort param_1);  /* 0x0302e1c8 40B */
void channel_lock_flag_bit_set_in_block11(ushort param_1,uint param_2);  /* 0x0302e714 230B */
void flash_field_find_nth_matching_value_wrapper(undefined2 param_1);  /* 0x0302e7fc 14B */
void channel_lock_icon_update(undefined1 param_1,undefined2 param_2);  /* 0x0302e80c 80B */
short vfo_freq_display_index_from_offset(undefined4 param_1,short param_2);  /* 0x0302e85c 14B */
void scrollable_list_menu_render_8row(ushort param_1,ushort param_2,ushort param_3);  /* 0x0302e86c 298B */
void channel_list_screen_with_add(uint param_1,uint param_2,uint param_3);  /* 0x0302ea10 542B */
void vfo_freq_list_cursor_advance(undefined1 *param_1,undefined1 *param_2);  /* 0x0302ec58 34B */
bool tx_is_inhibited(void);  /* 0x0302ed50 154B */
undefined4 vfo_frequency_digit_cursor_step_back(void);  /* 0x0302f344 120B */
void dtmf_inject_digits_2_0(void);  /* 0x0302f3d4 46B */
void channel_field_write_6bit_at_9(byte param_1);  /* 0x0302f5e8 218B */
byte bcd_frequency_in_range_check(char param_1,undefined4 param_2);  /* 0x0302f6c4 44B */
undefined4 bcd_frequency_pair_validate_and_store();  /* 0x0302f6f0 190B */
void startup_channel01_frequency_load_and_validate(void);  /* 0x0302f7cc 234B */
void display_draw_hex_digits_6_with_separator(int param_1);  /* 0x0302f8b8 140B */
undefined4 flash_record_11byte_exists_check_bank1(undefined4 param_1);  /* 0x0302f968 82B */
void dialog_header_number_draw_variant(void);  /* 0x0302f9bc 94B */
void tx_abort_and_radio_state_reset(void);  /* 0x0302fa70 272B */
void radio_idle_state_reset(char param_1);  /* 0x0302fbbc 138B */
void dialog_header_status_bit4_toggle_and_draw(void);  /* 0x0302fc48 26B */
void rf_frequency_adjust_and_display_refresh(void);  /* 0x0302fcd0 360B */
void channel_squelch_tone_scan_and_apply();  /* 0x0302fe94 378B */
void ctcss_or_dcs_code_display(uint param_1);  /* 0x03030044 162B */
void ctcss_tone_freq_display(undefined1 *param_1);  /* 0x0303011c 94B */
void dcs_code_display_normal_invert(undefined1 *param_1);  /* 0x0303017c 150B */
void tone_signaling_scroll_and_display_update(void);  /* 0x03030240 234B */
void ui_event_notify_alt(byte param_1);  /* 0x030305ac 88B */
void display_draw_tone_mode_icon(char param_1,char param_2,undefined2 param_3);  /* 0x03030604 232B */
void display_draw_channel_frequency(char param_1,undefined4 param_2);  /* 0x03030714 114B */
void counter_value_bcd_encode_and_save(uint param_1);  /* 0x03030788 140B */
void channel_field_bcd_write_to_flash_block(uint param_1,int param_2);  /* 0x03030814 176B */
void channel_frequency_read_decode();  /* 0x030308d8 46B */
void channel_freq_bcd_decode_by_slot(int param_1,int param_2);  /* 0x03030908 60B */
void bcd_pack_and_write_flash_block_0x41();  /* 0x03030944 110B */
void channel_list_index_resolve_then_channel_frequency_read_decode(undefined1 param_1,undefined1 param_2);  /* 0x030309b4 16B */
void channel_data_block_write_by_list_select(undefined1 param_1,int param_2,undefined4 param_3);  /* 0x03030e8c 60B */
void vfo_record_offset_select2(char param_1);  /* 0x03030ec8 90B */
void vfo_field_write_bit7_at_0x9(char param_1);  /* 0x03030fbc 72B */
void vfo_record_offset_select1(byte param_1);  /* 0x03031004 78B */
void vfo_field_write_1bit_at_10(byte param_1);  /* 0x0303105c 72B */
void vfo_field_write_3bit_at_0x16(char param_1,byte param_2);  /* 0x030310a4 150B */
void vfo_field_write_2bit_at_0x19(byte param_1);  /* 0x0303113c 72B */
void ctcss_dcs_list_row_render(uint param_1,uint param_2,uint param_3);  /* 0x03031204 214B */
void channel_field_write_and_notify();  /* 0x030312fc 154B */
void vfo_frequency_write();  /* 0x03031398 136B */
void ctcss_dcs_list_cursor_next(undefined1 *param_1,undefined1 *param_2);  /* 0x03031450 48B */
undefined4 channel_name_exists(undefined4 param_1);  /* 0x030314b4 74B */
int channel_apply_frequency_offset();  /* 0x03031500 58B */
void vfo_screen_redraw(void);  /* 0x030317f0 896B */
void channel_display_screen(void);  /* 0x03031bb8 1068B */
void channel_switch_and_screen_refresh(void);  /* 0x03032024 900B */
void task_codesw_entry(void);  /* 0x0303240c 40B */
void deferred_callback_pair_run_and_clear(void);  /* 0x030331fc 54B */
void status_queue_push_and_signal();  /* 0x03033234 72B */
void talkgroup_index_decode_paged(uint param_1,ushort *param_2,undefined1 *param_3);  /* 0x03033310 50B */
void record_read_by_index(undefined2 param_1,void *param_2);  /* 0x03033344 58B */
void flash_config_record_read_16byte(uint param_1,int param_2);  /* 0x030336b4 100B */
void flash_talker_record_read(uint param_1,undefined4 param_2);  /* 0x03033718 96B */
undefined4 flash_read_4byte_mutex_guarded(void);  /* 0x03033778 28B */
void range_count_two_level_counter_increment(int *param_1,int *param_2);  /* 0x03033890 66B */
void fixed_field_copy_and_format_dispatch();  /* 0x03033918 24B */
void load_const_string16_03033b18(undefined4 param_1,undefined4 param_2);  /* 0x03033940 16B */
void number_to_string_format_2args_wrapper(void);  /* 0x03033950 24B */
void load_const_string8_03033b24(undefined4 param_1,undefined4 param_2);  /* 0x03033968 16B */
void load_const_string16_03033b28(undefined4 param_1,undefined4 param_2);  /* 0x03033978 16B */
void load_const_string16_03033b2c(undefined4 param_1,undefined4 param_2);  /* 0x03033988 16B */
void load_const_string16_03033b30(undefined4 param_1,undefined4 param_2);  /* 0x03033998 16B */
void load_const_string16_03033b34(undefined4 param_1,undefined4 param_2);  /* 0x030339a8 18B */
void channel_number_and_name_screen_draw();  /* 0x0303400c 82B */
void tx_contact_select_screen();  /* 0x03034060 570B */
void contact_text_list_screen(byte param_1,uint param_2,uint param_3,ushort param_4);  /* 0x030342cc 766B */
void tx_contact_index_rewrite_both_blocks();  /* 0x03034624 406B */
undefined4 quick_contact_slot_bitmask_mark();  /* 0x03034834 414B */
undefined4 talkgroup_lookup_by_name(undefined4 param_1,undefined2 *param_2,uint param_3);  /* 0x03034ae8 244B */
bool contact_name_lookup_or_format(undefined4 param_1,undefined4 param_2,void *param_3,undefined1 param_4);  /* 0x03034d58 154B */
void tx_contact_select_index_advance(undefined1 param_1,short *param_2,ushort *param_3);  /* 0x03034e98 88B */
void contact_select_screen_adjust(undefined1 param_1,ushort *param_2,short *param_3);  /* 0x03034ef0 90B */
void contact_list_cursor_advance(undefined1 param_1,short *param_2,ushort *param_3);  /* 0x03034f54 90B */
void contact_list_screen_adjust(undefined1 param_1,short *param_2,short *param_3);  /* 0x03034fb0 94B */
void list_row_text_buffer_clear(void);  /* 0x03035010 12B */
void list_row_text_set_or_default(char param_1,undefined4 param_2);  /* 0x0303502c 38B */
undefined4 contact_edit_save_flow2();  /* 0x030350c4 800B */
undefined4 scanned_channel_save_as_contact_flow(void);  /* 0x030353fc 440B */
void talkgroup_binary_search_dispatch_by_radio_mode_flag(undefined4 param_1);  /* 0x03035880 56B */
void clear_state_byte_pair_03035a00(void);  /* 0x030358bc 10B */
void status_field_multi_step_state_machine(void);  /* 0x030358c8 310B */
void menu_mode_transition_and_field_redraw(char param_1);  /* 0x03035a20 290B */
void reentrant_state_reset_sequence(void);  /* 0x03035c38 282B */
void call_setup_state_dispatch(void);  /* 0x0303611c 166B */
void channel_vfo_commit_with_password_and_flash_write(void);  /* 0x0303659c 838B */
void text_entry_blank_placeholder_row_draw_alt(void);  /* 0x0303695c 64B */
void ring_buffer_multi_table_append_and_flush(void);  /* 0x0303699c 116B */
void menu_numeric_setting_commit_with_range_check(void);  /* 0x03036d1c 634B */
void menu_option_screen_dispatch_and_index_rebuild(void);  /* 0x03037110 518B */
void field_edit_multikey_input_dispatch(char param_1);  /* 0x03037718 1502B */
void diagnostic_screen_render_and_flash_log(void);  /* 0x03037dd4 228B */
void rssi_sql_meter_tick_decrement(void);  /* 0x03037ee8 170B */
void rssi_sql_meter_tick_increment(void);  /* 0x03037f94 174B */
void display_draw_number_centered_wrapper_030386c6(void);  /* 0x030386c6 34B */
void display_draw_number1_white_ptr_label(void);  /* 0x03038e20 4B */
void display_draw_number1_white_fixed_label(void);  /* 0x03038e24 20B */
void lcd_rect_bitmap_blit(uint param_1,uint param_2,uint param_3,uint param_4,int param_5);  /* 0x03038ee0 164B */
void display_blit_image();  /* 0x03039034 150B */
void signal_level_bargraph_render(uint param_1,uint param_2);  /* 0x030391d8 250B */
void signal_level_bargraph_mode_select(void);  /* 0x03039398 80B */
void tx_gate_call_record_on_newline_marker(void);  /* 0x030396b0 30B */
void menu_screen_load_contact_list(void);  /* 0x0303975c 64B */
void menu_screen_load_static(void);  /* 0x0303979c 48B */
void channel_number_indicator_update(int param_1,undefined2 param_2);  /* 0x03039c7c 180B */
void vfo_label_draw(int param_1);  /* 0x03039d30 130B */
void menu_icon_with_index_label_draw();  /* 0x03039db4 108B */
void dialog_history_menu_step_and_refresh(void);  /* 0x03039e3c 40B */
void display_blit_bitmap_by_palette_variant();  /* 0x0303a470 70B */
void dialog_show_icon_and_number_from_ptr(void);  /* 0x0303a4dc 70B */
void dialog_show_icon_and_number(char param_1,uint param_2);  /* 0x0303a524 86B */
void menu_key_action_dispatch_by_screen_state(void);  /* 0x0303a57c 430B */
void menu_text_entry_and_softkey_event_dispatch(void);  /* 0x0303a770 830B */
void asterisk_key_dispatch(void);  /* 0x0303af68 428B */
void display_draw_digit_string_indicators(byte *param_1);  /* 0x0303b150 240B */
void display_draw_decimal_string_2color(byte *param_1);  /* 0x0303b240 258B */
void text_entry_blank_placeholder_row_draw(void);  /* 0x0303b354 64B */
void menu_field_value_screen_render_and_key_dispatch(void);  /* 0x0303b720 232B */
void scan_mode_display_refresh(void);  /* 0x0303bc5e 80B */
void main_menu_open_contact_text_list(void);  /* 0x0303bcae 58B */
void main_menu_open_tx_contact_select(void);  /* 0x0303bce8 60B */
void set_screen_mode_0x12(void);  /* 0x0303bed6 10B */
void ctcss_dcs_list_dialog_screen(void);  /* 0x0303c17a 90B */
void tone_signaling_screen_render_and_apply(void);  /* 0x0303c20c 138B */
void channel_list_screen_render_with_roaming(void);  /* 0x0303c4ba 74B */
void recording_list_dialog_screen(void);  /* 0x0303c504 36B */
void aprs_waypoint_list_dialog_screen(void);  /* 0x0303c58a 36B */
void main_menu_reset_and_display(void);  /* 0x0303c868 222B */
void main_menu_screen_render_entry(void);  /* 0x0303cbc4 414B */
void main_menu_render_and_field_edit_dispatch(void);  /* 0x0303cdf0 254B */
void menu_screen_render_entry_variant(void);  /* 0x0303d8c8 334B */
void main_menu_entry_screen_setup(void);  /* 0x0303ddb0 302B */
undefined4 sidekey_press_debounce_dispatch(void);  /* 0x0303f1a0 352B */
void ui_event_code_dispatch_main(void);  /* 0x0303fa04 396B */
void dialog_history_apply_entry_with_tx_gate(void);  /* 0x0303fbb8 72B */
void dialog_history_apply_entry_variant_e(void);  /* 0x0303fc00 72B */
void menu_key_confirm_dispatch(void);  /* 0x0303fc48 418B */
void dialog_history_action_dispatch_with_tx_gate(void);  /* 0x03040052 220B */
void keypad_event_dispatch_idle_or_menu(void);  /* 0x03040282 982B */
void flash_block_value_display_or_fallback();  /* 0x03040a8c 142B */
void tx_gate_call_record_toggle_a(void);  /* 0x03040b1c 36B */
void list_row_scroll_decrement_a_call(void);  /* 0x03040ba8 12B */
void menu_item_cycle_prev_call(void);  /* 0x03040c1e 12B */
void key_shortcut_call_03056614(void);  /* 0x03040c4e 16B */
void key_shortcut_call_03056ba8(void);  /* 0x03040c6e 16B */
void key_shortcut_call_0302e9e8(void);  /* 0x03040c9e 16B */
void key_shortcut_call_03055e68(void);  /* 0x03040cae 16B */
void key_shortcut_call_0302ec90(void);  /* 0x03040cbe 16B */
void key_shortcut_call_03055dfc(void);  /* 0x03040cce 16B */
void key_shortcut_call_03056718(void);  /* 0x03040cde 16B */
void key_shortcut_call_03061500(void);  /* 0x03040cfe 16B */
void key_shortcut_call_0305cc2c(void);  /* 0x03040d0e 16B */
void key_shortcut_call_03062d04(void);  /* 0x03040d1e 16B */
void key_shortcut_call_list_cursor_and_03062ed8(void);  /* 0x03040d2e 30B */
void key_shortcut_call_030584ac(void);  /* 0x03040d86 14B */
void tx_gate_call_record_toggle_b(void);  /* 0x03040f9c 36B */
void key_shortcut_dispatch_table_list_screens(void);  /* 0x03040fc0 50B */
void list_row_scroll_increment_b_call(void);  /* 0x03041018 12B */
void menu_item_cycle_next(void);  /* 0x0304108e 12B */
void number_list_display_update_fwd(void);  /* 0x0304109a 24B */
void channel_list_cursor_increment(void);  /* 0x0304116e 16B */
void key_shortcut_channel_list_advance_dispatch(void);  /* 0x0304119e 30B */
void table_entry_select_and_index_list_build_variant13_03041470(void);  /* 0x03041470 228B */
void radio_id_detail_screen(void);  /* 0x03041700 352B */
void contact_list_window_clamp_to_8(void);  /* 0x030418a0 206B */
void menu_option_list_select_and_init(void);  /* 0x030419b8 96B */
void table_entry_select_and_index_list_build_variant17(void);  /* 0x03041aa4 60B */
void table_entry_select_and_index_list_build_variant12_03041ae0(void);  /* 0x03041ae0 24B */
void table_entry_select_and_index_list_build_variant9(void);  /* 0x03041b24 66B */
void menu_option_list_init_from_table_with_index_list_and_flag4(void);  /* 0x03041ba8 32B */
void table_entry_select_and_index_list_build_variant10_03041d74(void);  /* 0x03041d74 68B */
void settings_edit_field_init_or_commit_dispatch(void);  /* 0x03041db8 90B */
void menu_option_accept_reject_with_history_pop(void);  /* 0x03041e50 60B */
void menu_bool_option_init_03041fd8(void);  /* 0x03041fd8 104B */
void vfo_display_option_count_clamp(void);  /* 0x03042040 80B */
void load_tag_string_0x52_and_set_len4(void);  /* 0x03042090 30B */
void load_tag_string_0x53_and_set_len4(void);  /* 0x030420ae 30B */
void table_entry_select_and_index_list_build_variant19(void);  /* 0x030420cc 82B */
void menu_ctcss_dcs_scope_option_init(void);  /* 0x030421f2 82B */
void noop_stub_03042244(void);  /* 0x03042244 4B */
void zone_list_select_or_init_dispatch(void);  /* 0x03042248 230B */
void table_entry_select_and_index_list_build_variant10(void);  /* 0x03042384 24B */
void table_entry_select_and_index_list_build_variant18(void);  /* 0x030424d4 66B */
void menu_dtmf_timing_option_init(void);  /* 0x03042544 66B */
void table_entry_select_and_index_list_build(void);  /* 0x03042586 66B */
void contact_menu_accept_reject_with_dispatch_variant(void);  /* 0x03042830 140B */
void contact_menu_option_or_history_dispatch(void);  /* 0x030428bc 288B */
void contact_name_entry_dialog_init(void);  /* 0x03042a30 62B */
void contact_menu_accept_reject_with_dispatch(void);  /* 0x03042a70 86B */
void contact_menu_option_or_history_dispatch_wrapper(void);  /* 0x03042b34 6B */
void contact_name_entry_dialog_init_wrapper(void);  /* 0x03042b3a 6B */
void contact_menu_accept_reject_with_dispatch_wrapper_03042b40(void);  /* 0x03042b40 6B */
void contact_menu_accept_reject_with_dispatch_wrapper_03042b46(void);  /* 0x03042b46 6B */
void table_entry_select_and_index_list_build_variant15(void);  /* 0x03042b4c 164B */
void table_entry_select_and_index_list_build_variant11_03042bf0(void);  /* 0x03042bf0 24B */
void table_entry_select_and_index_list_build_variant2(void);  /* 0x03042cc0 66B */
void list_record_toggle_or_dialog_countdown(void);  /* 0x03042d02 192B */
void table_select_or_dialog_show_by_mode(void);  /* 0x03042ec2 124B */
void menu_confirm_delete_dialog_option_init_03042f84(void);  /* 0x03042f84 290B */
void settings_code_read_and_status_dispatch();  /* 0x030430a8 80B */
void settings4_field_0x4c_option_count_init(void);  /* 0x03043140 12B */
void settings_setting_0x4d_clamped_to_8(void);  /* 0x03043158 12B */
void settings_setting_0x4a_clamped_to_8(void);  /* 0x03043194 12B */
void contact_group_range_select_and_clamp(void);  /* 0x0304332c 182B */
void menu_recording_entry_actions_option_init(void);  /* 0x030433e4 82B */
void dmr_channel_load_from_flash_or_dialog(void);  /* 0x03043438 396B */
void menu_contact_pick_method_option_init_03043624(void);  /* 0x03043624 72B */
void contact_list_select_and_history_dispatch(void);  /* 0x03043774 30B */
void menu_option_list_init_from_fixed_table_and_history_draw(void);  /* 0x030437d8 34B */
void menu_contact_edit_fields_option_init_030437fa(void);  /* 0x030437fa 70B */
void menu_contact_edit_fields_option_init_03043840(void);  /* 0x03043840 122B */
void menu_option_list_init_from_table_by_settings_0x30_bit6(void);  /* 0x030438ba 44B */
void menu_contact_view_or_apply_option_init_030439cc(void);  /* 0x030439cc 286B */
void menu_selector_byte_dispatch_3way(void);  /* 0x03043b38 42B */
void table_entry_select_and_index_list_build_variant11(void);  /* 0x03043c38 80B */
void shutdown_state_screen_dispatch(void);  /* 0x03043ce8 44B */
void shutdown_state_screen_dispatch_wrapper(void);  /* 0x03043dee 6B */
void index_table_read_decrement_wrapper(void);  /* 0x03043df4 6B */
void list_record_toggle_dialog_init(void);  /* 0x03043e3e 100B */
void menu_screen_option_selector_three_way_dispatch(void);  /* 0x03044188 44B */
void settings_struct_byte_read_and_status_dispatch();  /* 0x030441b4 86B */
void menu_bool_option_init_03044308(void);  /* 0x03044308 94B */
void menu_capability_dispatch_arg9(void);  /* 0x03044366 10B */
void menu_capability_dispatch_arg0(void);  /* 0x03044370 10B */
void menu_capability_dispatch_arg1(void);  /* 0x0304437a 10B */
void menu_capability_dispatch_arg2(void);  /* 0x03044384 10B */
void menu_capability_dispatch_arg3(void);  /* 0x0304438e 10B */
void menu_capability_dispatch_arg4(void);  /* 0x03044398 10B */
void menu_capability_dispatch_arg5(void);  /* 0x030443a2 10B */
void menu_capability_dispatch_arg7(void);  /* 0x030443ac 10B */
void menu_capability_dispatch_arg6(void);  /* 0x030443b6 10B */
void menu_backlight_brightness_option_init(void);  /* 0x0304450c 86B */
void menu_backlight_timeout_option_init(void);  /* 0x03044562 86B */
void table_entry_select_and_index_list_build_variant4(void);  /* 0x030445b8 94B */
void settings_struct_byte_read_and_status_wrapper(void);  /* 0x03044616 8B */
void menu_vfo_display_mode_option_init(void);  /* 0x03044682 94B */
void menu_ui_language_option_init(void);  /* 0x0304471c 112B */
void menu_direction_normal_reverse_option_init(void);  /* 0x0304478c 100B */
void table_entry_select_with_settings_check_variant2(void);  /* 0x030447f0 112B */
void menu_auto_poweroff_timeout_option_init(void);  /* 0x0304493c 94B */
void list_descriptor_init_and_setting3_store_0x36(void);  /* 0x0304499a 42B */
void table_entry_select_and_index_list_build_variant12(void);  /* 0x030449ec 60B */
void menu_bool_option_init_03044a50(void);  /* 0x03044a50 142B */
void table_entry_select_and_index_list_build_variant5(void);  /* 0x03044b70 84B */
void menu_battery_save_ratio_option_init(void);  /* 0x03044c1e 106B */
void table_entry_select_and_index_list_build_variant20(void);  /* 0x03044cc0 106B */
void menu_bool_option_init_03044d2a(void);  /* 0x03044d2a 88B */
void menu_bool_option_init_03044d82(void);  /* 0x03044d82 88B */
void table_entry_select_and_index_list_build_variant13(void);  /* 0x03044e20 94B */
void table_entry_select_and_index_list_build_with_settings_check(void);  /* 0x03044f6a 110B */
void menu_bool_option_init_03044fd8(void);  /* 0x03044fd8 108B */
void noop_stub_03045082(void);  /* 0x03045082 2B */
void menu_ctcss_dcs_type_option_init(void);  /* 0x030450c0 188B */
void menu_list_apply_edit_actions_option_init(void);  /* 0x0304517c 156B */
void menu_bool_option_init_030452ac(void);  /* 0x030452ac 208B */
void radio_id_list_screen(void);  /* 0x0304537c 154B */
void noop_stub_03045478(void);  /* 0x03045478 2B */
void menu_field_mode_dispatch_context_or_contact_edit(void);  /* 0x0304547c 34B */
void menu_screen_dispatch_contact_or_static_gated_by_index_0x2(void);  /* 0x03045630 46B */
void menu_contact_view_or_apply_option_init_03045858(void);  /* 0x03045858 408B */
void menu_scan_priority_actions_option_init(void);  /* 0x03045a94 100B */
void menu_screen_option_list_init_by_type(void);  /* 0x03045af8 306B */
void menu_contact_pick_method_option_init_03045cd8(void);  /* 0x03045cd8 82B */
void table_entry_select_and_index_list_build_variant3(void);  /* 0x03045d2c 68B */
void menu_message_compose_actions_option_init(void);  /* 0x03045e3c 82B */
void menu_item_render_and_select_multibranch(void);  /* 0x03045fd8 786B */
void table_entry_select_and_index_list_build_variant21(void);  /* 0x0304664c 80B */
void menu_name_field_list_option_init(void);  /* 0x0304669c 198B */
void table_entry_select_and_index_list_build_conditional(void);  /* 0x030467bc 74B */
void radio_shutdown_confirm_screen_call(void);  /* 0x03046808 8B */
void menu_confirm_delete_dialog_option_init_03046810(void);  /* 0x03046810 306B */
void menu_screen_dispatch_contact_or_static_by_field7_flag(void);  /* 0x0304699c 34B */
void menu_confirm_delete_dialog_option_init_030469c0(void);  /* 0x030469c0 156B */
void menu_screen_dispatch_contact_or_static_by_two_empty_checks(void);  /* 0x03046a5c 42B */
void table_entry_select_two_mode_dispatch(void);  /* 0x03046a88 132B */
void menu_remove_group_action_option_init(void);  /* 0x03046b7c 382B */
void menu_search_contact_manual_dial_option_init(void);  /* 0x03046d5c 164B */
void menu_contact_pick_method_option_init_03046e00(void);  /* 0x03046e00 96B */
void menu_message_entry_actions_option_init(void);  /* 0x03046e98 122B */
void menu_contact_pick_submode_dispatch(void);  /* 0x03046f14 86B */
void menu_screen_dispatch_by_field_0x8(void);  /* 0x03046f88 44B */
void menu_contact_pick_method_option_init_03046fe8(void);  /* 0x03046fe8 146B */
void table_entry_select_and_index_list_build_toplevel_dispatch(void);  /* 0x03047324 28B */
void channel_frequency_display_setup(void);  /* 0x03047374 160B */
void menu_tx_power_level_option_init(void);  /* 0x03047414 136B */
void menu_ctcss_dcs_direction_option_init(void);  /* 0x0304749c 70B */
void contact_group_range_select_and_clamp_wrapper(void);  /* 0x030474e2 8B */
void table_entry_select_index_list_build_with_state_reset(void);  /* 0x030476cc 100B */
void menu_bool_option_init_03047780(void);  /* 0x03047780 116B */
void channel_name_dialog_init(void);  /* 0x030477f4 138B */
void menu_channel_mode_option_init(void);  /* 0x030478da 86B */
void menu_channel_bandwidth_option_init(void);  /* 0x03047988 96B */
void menu_encryption_option_init(void);  /* 0x030479e8 66B */
void menu_signalling_system_option_init(void);  /* 0x03047a2a 94B */
void table_entry_select_and_index_list_build_variant14(void);  /* 0x03047a88 96B */
void tone_signaling_menu_option_0x1f_dispatch(void);  /* 0x03047ae8 146B */
void menu_repeater_shift_direction_option_init(void);  /* 0x03047bbc 94B */
void channel_freq_load_and_format_digits(void);  /* 0x03047c1a 124B */
void menu_bool_option_init_03047c96(void);  /* 0x03047c96 98B */
void record_or_screen_init_toplevel_dispatch(void);  /* 0x03047d44 26B */
void menu_option_handler_dispatch_wrapper(void);  /* 0x03047d6c 8B */
void table_entry_select_and_index_list_build_wrapper(void);  /* 0x03047d74 8B */
void menu_radio_identity_field_list_init(void);  /* 0x03047d7c 128B */
void block_record_template_load_id_by_index_dispatch(void);  /* 0x03047dfc 24B */
void menu_bool_option_init_03047ee4(void);  /* 0x03047ee4 98B */
void menu_prompt_reply_mode_option_init(void);  /* 0x03047f46 84B */
void block_record_template_load_by_menu_index_dispatch(void);  /* 0x03047f9a 24B */
void table_entry_select_and_index_list_build_variant6_twin(void);  /* 0x03048022 98B */
void table_entry_select_and_index_list_build_variant6(void);  /* 0x030480cc 96B */
void menu_option_list_init_from_table_with_fixed_0x68_and_state(void);  /* 0x03048188 36B */
void table_entry_select_scan_preset_with_flag_init(void);  /* 0x0304823c 88B */
void table_entry_select_and_index_list_build_variant7(void);  /* 0x03048334 96B */
void table_entry_select_and_index_list_build_variant8(void);  /* 0x03048394 86B */
void table_entry_select_and_index_list_build_variant16(void);  /* 0x030483ea 88B */
void band_range_select_screen(void);  /* 0x0304857c 480B */
byte cyclic_value_step(byte param_1,byte param_2,byte param_3,char param_4);  /* 0x030487a0 40B */
void time_hms_display(void);  /* 0x030487c8 90B */
void date_ymd_display(void);  /* 0x03048824 90B */
void time_display_refresh_and_char_picker_offset_dec(void);  /* 0x030488d0 6B */
void date_display_refresh_and_char_picker_offset_dec(void);  /* 0x030488d6 6B */
void settings_duration_seconds_cycle_var_f0_rev(void);  /* 0x0304892e 26B */
void text_entry_char_group_index_retreat_and_cursor_x_set(void);  /* 0x03048b3c 130B */
void time_display_refresh_and_char_picker_offset_inc(void);  /* 0x03048bf4 6B */
void date_display_refresh_and_char_picker_offset_inc(void);  /* 0x03048bfa 6B */
void settings_duration_seconds_cycle_var_f0_fwd(void);  /* 0x03048c52 26B */
void text_entry_char_group_index_advance_and_cursor_x_set(void);  /* 0x03048e44 128B */
void rtc_date_decode_to_bcd_display_buffer(void);  /* 0x03048ef4 98B */
void date_pack_bcd_and_display(undefined4 param_1,uint param_2);  /* 0x03048f56 112B */
void display_draw_number_centered_wrapper_0304904c(void);  /* 0x0304904c 52B */
void display_draw_number_centered_then_display_draw_hex_digits_6_with_separator(void);  /* 0x03049080 52B */
void display_draw_number_centered_then_display_clear_and_draw_scaled_number_ms_030491b4(void);  /* 0x030491b4 40B */
void display_draw_number_centered_then_settings_duration_seconds_display_call_030491dc(void);  /* 0x030491dc 40B */
void display_draw_number_centered_then_display_clear_and_draw_number_with_label_arg(void);  /* 0x03049204 40B */
void table_value_display_draw_and_refresh(void);  /* 0x0304922c 54B */
void display_draw_number_centered_then_display_clear_and_draw_scaled_number_ms_03049262(void);  /* 0x03049262 40B */
void display_draw_number_centered_then_settings_duration_seconds_display_call_030492b8(void);  /* 0x030492b8 40B */
void display_draw_number_centered_then_seconds_decimal_from_int_format(void);  /* 0x030492e0 54B */
void noop_stub_0304933c(void);  /* 0x0304933c 4B */
bool scan_feature_enabled(char param_1);  /* 0x03049358 160B */
void vfo_load_side_config(void);  /* 0x0304a200 188B */
void settings_bitfield_remap_0x2d(void);  /* 0x0304a2cc 96B */
void settings_set_menu_hold_interval(ushort param_1);  /* 0x0304a32c 94B */
undefined4 settings_write_dispatcher();  /* 0x0304b088 4602B */
byte settings_read_dispatcher(char param_1);  /* 0x0304c318 726B */
void menu_screen_load_and_setting_read(char param_1,char param_2);  /* 0x0304c928 546B */
void flash_block4_write_field_0x332_and_cache();  /* 0x0304ce50 30B */
void menu_confirm_apply_handler1(void);  /* 0x0304cf5c 896B */
void status_mode_byte_pair_select_and_write(void);  /* 0x0304d54c 64B */
void menu_wrapper_character_dispatch(void);  /* 0x0304d6c0 344B */
void menu_wrapper_ui_update_notify(void);  /* 0x0304df96 90B */
void menu_wrapper_conditional_notify(void);  /* 0x0304dff0 64B */
void dmr_control_message_dispatch_and_channel_commit(void);  /* 0x0304e044 156B */
void menu_wrapper_settings_notify_status(void);  /* 0x0304e12a 36B */
void menu_wrapper_settings_notify(void);  /* 0x0304e14e 26B */
void status_mode_write_0x23_1_variant_a(void);  /* 0x0304e232 10B */
void menu_wrapper_notify_alt8_a(void);  /* 0x0304e23c 24B */
void status_mode_write_0x23_1_variant_b(void);  /* 0x0304e254 10B */
void menu_wrapper_vfo_2bit_write(void);  /* 0x0304e2ae 24B */
void menu_wrapper_vfo_record_offset_write(void);  /* 0x0304e2e0 24B */
void menu_wrapper_vfo_bit_write(void);  /* 0x0304e3fe 24B */
void status_mode_or_settings_menu_command_dispatch(void);  /* 0x0304e560 24B */
void status_mode_write_0x23_1_variant_c(void);  /* 0x0304e5a0 10B */
void menu_command_dispatch_with_dmr_fallback_wrapper(void);  /* 0x0304e5aa 6B */
void settings_block6_offset0x100_field_write_dispatch(void);  /* 0x0304e5b0 22B */
void settings_block6_offset0x100_write_field3(void);  /* 0x0304e5de 10B */
void settings_block6_offset0x100_write_field0xc(void);  /* 0x0304e5f2 10B */
void settings_block6_offset0xa20_field_write_dispatch(void);  /* 0x0304e644 22B */
void settings_block6_offset0xa20_write_field4(void);  /* 0x0304e678 10B */
void call_list_field_write_dispatch_b(void);  /* 0x0304e6e4 22B */
void call_list_index_write_then_dialog_show_icon_and_number_0304e722(void);  /* 0x0304e722 10B */
void call_list_index_write_then_dialog_show_icon_and_number_0304e72c(void);  /* 0x0304e72c 10B */
void call_list_index_write_then_dialog_show_icon_and_number_0304e74a(void);  /* 0x0304e74a 10B */
void menu_wrapper_call_list_write_a(void);  /* 0x0304e754 48B */
void call_list_field_write_dispatch(void);  /* 0x0304e784 22B */
void call_list_index_write2_then_dialog_show_icon_and_number_0304e7b8(void);  /* 0x0304e7b8 10B */
void menu_wrapper_call_list_write_b(void);  /* 0x0304e7c2 14B */
void menu_wrapper_call_list_write_c(void);  /* 0x0304e7d0 20B */
void call_list_index_write2_then_dialog_show_icon_and_number_0304e7f8(void);  /* 0x0304e7f8 10B */
void call_list_index_write2_then_dialog_show_icon_and_number_0304e802(void);  /* 0x0304e802 38B */
void menu_command_dispatch_with_flash_block65_write(void);  /* 0x0304e83c 402B */
void flash_block65_field_toggle_with_dialog(void);  /* 0x0304ea10 230B */
void dmr_menu_field_edit_key_dispatch(void);  /* 0x0304eb28 32B */
void contact_list_delete_entry_and_compact_wrapper(void);  /* 0x0304ecd4 16B */
void status_dialog_request_by_code_dispatch_b(void);  /* 0x0304ece4 218B */
void contact_history_pop_or_scan_action_dispatch(void);  /* 0x0304f070 164B */
void status_mode_write_or_history_pop_pair(void);  /* 0x0304f17c 56B */
void quick_contact_slot_mark_and_pop(void);  /* 0x0304f1f6 44B */
void scan_status_field_tick_or_hold(void);  /* 0x0304f222 42B */
void menu_wrapper_callsign_colour(void);  /* 0x0304fd00 20B */
void menu_wrapper_standby_text_colour(void);  /* 0x0304fd14 20B */
void menu_wrapper_zone_a_colour(void);  /* 0x0304fd50 20B */
void menu_exit_time_option_apply(void);  /* 0x0304fe20 32B */
void menu_wrapper_bare_redraw(void);  /* 0x0304fe5e 10B */
void menu_wrapper_vfo_step(void);  /* 0x03050070 10B */
void noop_stub_030500ac(void);  /* 0x030500ac 4B */
void menu_confirm_apply_handler2(void);  /* 0x030500b0 732B */
void settings_menu_confirm_dispatch(void);  /* 0x03050414 34B */
void scanlist_membership_remove_or_prompt(void);  /* 0x03050b30 106B */
void channel_select_finalize_or_history_pop(void);  /* 0x03050d3c 110B */
void menu_confirm_apply_dispatcher();  /* 0x03050de8 1962B */
void roam_zone_countdown_step_from_menu_index(void);  /* 0x0305168c 16B */
void status_dialog_request_by_code_dispatch(void);  /* 0x0305169c 130B */
void screen_mode_static_table_dispatch(void);  /* 0x0305279c 86B */
void menu_list_screen_render(void);  /* 0x03052840 332B */
void call_log_entry_render_with_header(void);  /* 0x030529c4 108B */
void call_log_entry_render_basic(void);  /* 0x03052a30 68B */
void list_cursor_advance_with_wrap(void);  /* 0x03052ad0 84B */
void jumptable_dispatch_masked_index_align(uint param_1);  /* 0x03052b44 16B */
void active_screen_option_list_reindex_and_clear(void);  /* 0x03052b54 58B */
void call_record_line_advance_or_close_tx(void);  /* 0x03052c04 116B */
undefined4 dmr_list_header_load(char param_1);  /* 0x03052d48 58B */
void bitarray_set_or_clear_bit(uint param_1,int param_2,char param_3);  /* 0x03052dc4 72B */
void contact_char_index_to_display_code(byte param_1,char param_2,char *param_3,byte *param_4);  /* 0x03052e2c 92B */
void dmr_contact_list_menu_row_render_group3(void);  /* 0x03052e88 738B */
void dmr_contact_list_menu_row_render_group1(void);  /* 0x03053180 856B */
void dmr_contact_list_menu_row_render_group2(void);  /* 0x03053508 856B */
char dmr_contact_list1_active_count(void);  /* 0x030538b0 176B */
void dmr_list_headers_load_and_validate(void);  /* 0x03053998 332B */
void quick_text_message_read(uint param_1);  /* 0x03053b0c 30B */
undefined4 quick_text_insert_and_rewrap(undefined1 param_1);  /* 0x03053b2c 184B */
undefined4 contact_edit_save_flow1();  /* 0x03053be4 494B */
void flash_list_entry_remove_and_compact(uint param_1,char param_2);  /* 0x03053e0c 204B */
void erase_stored_field_category_by_code(char param_1);  /* 0x03053eec 148B */
int channel_number_decode_from_menu_index();  /* 0x03054274 262B */
void buffer_prepend_3byte_le(undefined4 param_1,undefined1 *param_2,int param_3);  /* 0x0305437c 40B */
void wlt_cmd_string_build(undefined1 param_1);  /* 0x030543b4 30B */
void menu_exit_timer_tick(void);  /* 0x030544ac 482B */
void ui_periodic_maintenance_task_loop(void);  /* 0x0305476c 462B */
void crystal_osc_and_timer5_init(void);  /* 0x03054a6c 266B */
void rf_transceiver_mode_init(char param_1);  /* 0x03054bb8 154B */
void fd6818b_partial_display_mode_reconfigure(void);  /* 0x03054c54 84B */
void rf_mode_state_clear_and_reinit_if_mode2(void);  /* 0x03054da0 32B */
void fd6818b_compander_calibration_write(undefined1 param_1);  /* 0x03054e30 14B */
void display_lookup_channel_icon_and_bank(byte *param_1);  /* 0x03054f44 564B */
void set_flag_bits_and_post_os_flag_0x8000(uint param_1);  /* 0x03055644 22B */
void dialog_set_pending_render_flag();  /* 0x03055678 82B */
void call_display_countdown_and_ui_event_trigger(void);  /* 0x030556cc 258B */
void volume_setting_load_clamp_apply(void);  /* 0x030557e8 102B */
void channel_num_to_block_offset(ushort param_1,short *param_2,short *param_3);  /* 0x03055924 110B */
void channel_offset_from_num(undefined2 param_1,undefined4 param_2,short *param_3);  /* 0x03055994 28B */
char flash_field_scan_until_invalid_or_32(ushort param_1);  /* 0x030559f8 76B */
undefined4 flash_field_contains_value(ushort param_1,int param_2);  /* 0x03055a44 94B */
void scan_list_screen_with_add(uint param_1,uint param_2,uint param_3);  /* 0x03055aa4 382B */
void flash_block_read_modify_write_96b(uint param_1,uint param_2);  /* 0x03055c4c 116B */
void group_member_list_screen(uint param_1,uint param_2,uint param_3,uint param_4);  /* 0x03055d24 214B */
void list_cursor_increment_then_group_member_list_screen(undefined1 *param_1,undefined1 *param_2);  /* 0x03055e24 38B */
void scan_list_cursor_next_if_present(undefined1 *param_1,undefined1 *param_2);  /* 0x03055e90 40B */
void dmr_user_register_next_free_bitmap_slot();  /* 0x03055eb8 98B */
void channel_config_load_from_flash_and_apply(uint param_1);  /* 0x03055f1c 108B */
void rf_mode_transition_on_freq_delta(uint *param_1);  /* 0x03055f88 212B */
undefined2 flash_indexed_u12_field_read(ushort param_1);  /* 0x03056068 66B */
void dmr_id_log_write(ushort param_1,uint param_2);  /* 0x030560e8 190B */
void flash_bcd_frequency_pair_decode(undefined2 param_1,undefined1 *param_2);  /* 0x030561e0 106B */
void vfo_tx_contact_field_read_wrapper(undefined1 param_1);  /* 0x03056258 10B */
void vfo_record_offset_select3(void *dest,void *src);  /* 0x030562d8 74B */
void zone_list_screen(uint param_1,uint param_2,uint param_3);  /* 0x03056464 350B */
void zone_list_cursor_increment(undefined1 *param_1,undefined1 *param_2);  /* 0x030565c4 40B */
void zone_list_cursor_decrement(undefined1 *param_1,undefined1 *param_2);  /* 0x03056614 40B */
void list_cursor_increment_then_draw_channel_records_from_flash(undefined1 *param_1,undefined1 *param_2);  /* 0x03056734 28B */
ushort channel_free_slot_count_until_nth();  /* 0x03056750 158B */
void channel_list_render_rows_free_slot();  /* 0x03056804 122B */
void contact_list_delete_entry_and_compact(char param_1,uint param_2);  /* 0x03056900 190B */
undefined4 zone_name_exists_check(undefined4 param_1);  /* 0x030569d4 90B */
undefined4 flash_record_11byte_exists_check_bank2(undefined4 param_1);  /* 0x03056a30 82B */
ushort flash_field_find_nth_matching_value();  /* 0x03056a84 168B */
void channel_list_render_rows_flash_matching_value(uint param_1,uint param_2,uint param_3);  /* 0x03056b2c 122B */
void vfo_field_write_bit4_at_0xd(char param_1);  /* 0x03056c54 234B */
void vfo_field_write_nibble_high(uint param_1);  /* 0x03056d40 208B */
void vfo_field_write_bit5_at_0xd(char param_1);  /* 0x03056e24 234B */
void * channel_freq_record_build_from_flash(void *param_1,int param_2);  /* 0x030570dc 138B */
void channel_frequencies_read_and_decode(short param_1,undefined1 *param_2);  /* 0x03057168 256B */
undefined1 flash_field_read_cached_block0x67_off0(void);  /* 0x03057278 26B */
void flash_block0x67_write_byte_off0();  /* 0x03057294 24B */
int flash_field_block67_signed_threshold_check();  /* 0x030572ac 52B */
void channel_change_apply_dispatcher(short param_1,char param_2);  /* 0x030573e8 3184B */
void channel_change_apply_with_zone_and_flash_validate(void);  /* 0x03058180 308B */
void radio_id_entry_write(uint param_1,undefined4 param_2);  /* 0x030582c8 26B */
void radio_id_entry_read_and_terminate(uint param_1,int param_2);  /* 0x030582e4 26B */
void flash_block0x67_write_indexed_12byte(uint param_1,undefined4 param_2);  /* 0x03058300 20B */
undefined4 locked_radio_id_lookup_by_string(undefined4 param_1,ushort param_2);  /* 0x03058314 74B */
void list_row_decrement_and_redraw(undefined1 *param_1,undefined1 *param_2);  /* 0x030584ac 34B */
void list_row_increment_and_redraw(undefined1 *param_1,undefined1 *param_2);  /* 0x030584d0 34B */
void flash_record_erase_and_clear_cache(uint param_1);  /* 0x030585dc 68B */
void flash_history_record_append_with_date();  /* 0x0305878c 622B */
void flash_record_table_reclaim_or_count_empty(void);  /* 0x03058a0c 106B */
void contact_name_lookup_by_offset_walk(uint param_1,char param_2,undefined4 param_3);  /* 0x03058a90 134B */
undefined4 flash_record_read_nth_entry(uint param_1,char param_2);  /* 0x03058ca4 108B */
void flash_record_read_with_block_skip(uint param_1,char param_2,void *param_3);  /* 0x03058d10 102B */
void datetime_display_gb2312(char param_1,undefined1 param_2);  /* 0x03058d78 190B */
void text_entry_backspace_and_channel_insert(void);  /* 0x03058fa4 252B */
void input_alter_task_create_init(void);  /* 0x030590a0 86B */
void display_format_id_with_separators(void);  /* 0x03059188 758B */
void display_draw_char_glyph_dispatch(void);  /* 0x030594b8 30B */
void display_draw_ascii_digit_glyph_advance(void);  /* 0x030594e4 8B */
void display_draw_glyph_row_advance_0x41(void);  /* 0x030594ec 8B */
void display_draw_glyph_row_advance_0x42(void);  /* 0x030594f4 8B */
void display_draw_glyph_row_advance_0x43(void);  /* 0x030594fc 8B */
void display_draw_glyph_row_advance_0x44(void);  /* 0x03059504 8B */
void display_draw_glyph_row_advance_asterisk(void);  /* 0x0305950c 8B */
void display_draw_glyph_row_advance_0x23(void);  /* 0x03059514 58B */
void channel_type_apply_tone_idx0xb(void);  /* 0x030595d4 4B */
void text_input_append_byte_and_scroll(byte param_1);  /* 0x03059748 230B */
void scan_monitor_display_refresh(void);  /* 0x03059b4c 94B */
void scan_mode_state_transition_handler(void);  /* 0x03059bac 110B */
void scan_monitor_mode_cycle_advance(void);  /* 0x03059c1c 198B */
undefined4 text_entry_char_picker_render(void);  /* 0x03059dfc 578B */
void scan_list_multikey_digit_dispatch(char param_1);  /* 0x0305a468 114B */
void display_draw_single_char_or_gb2312_glyph(char *param_1);  /* 0x0305a4dc 272B */
void text_entry_input_loop_blocking(void);  /* 0x0305a6e0 438B */
int text_entry_char_picker_render_fixed(void);  /* 0x0305a8d8 444B */
void text_entry_cursor_advance_line_wrap(void);  /* 0x0305ac24 240B */
void text_entry_char_append_and_scroll(void);  /* 0x0305ad3c 392B */
void scan_list_row_or_text_entry_render(void);  /* 0x0305aee8 90B */
void scan_list_or_text_entry_index_advance_and_render(void);  /* 0x0305af44 36B */
void scan_list_selection_advance_and_render(void);  /* 0x0305af68 118B */
void ui_countdown_decrement_wrap(void);  /* 0x0305afe0 60B */
void text_entry_char_step_up_and_render(void);  /* 0x0305b120 68B */
int text_entry_columns_used_for_length();  /* 0x0305b164 34B */
void text_entry_scroll_and_display_refresh(void);  /* 0x0305b19c 332B */
void text_entry_cursor_advance_wide_or_narrow(void);  /* 0x0305b368 244B */
void text_entry_backspace_delete_char(void);  /* 0x0305b50c 564B */
void dmr_scan_list_row_up_or_exit(void);  /* 0x0305b798 74B */
void gb2312_text_wrap_calculate(byte *param_1);  /* 0x0305b984 122B */
void text_entry_field_init_and_wrap_calc(void);  /* 0x0305ba00 72B */
void mmio_11000074_bits78_set_from_status_nibble(void);  /* 0x0305ba70 44B */
void status_byte_bit5_set_clear_wrapper(undefined1 param_1,undefined1 param_2);  /* 0x0305ba9c 12B */
void ptt_press_handler(void);  /* 0x0305bfb8 2214B */
void channel_select_input_gate(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4, undefined1 param_5);  /* 0x0305ca0c 48B */
void dmr_privacy_key_load_and_mi_draw(void);  /* 0x0305ca48 192B */
char flash_block_count_records_until_null(void);  /* 0x0305cb08 60B */
void list_cursor_increment_then_list_screen_none_placeholder(undefined1 *param_1,undefined1 *param_2);  /* 0x0305cc50 34B */
void audio_ctrl_bit0_tx_voice_source_set(char param_1);  /* 0x0305ce5c 38B */
void channel_select_type_noop_stub(void);  /* 0x0305cfb6 4B */
void dialog_history_show_if_present(void);  /* 0x0305cfbc 20B */
void contact_edit_save_via_temp_buffer(void);  /* 0x0305cfd0 58B */
void gb2312_string_reencode(char param_1,int param_2,uint param_3,undefined1 *param_4);  /* 0x0305d020 960B */
uint text_to_encoded_message_with_len_prefix_and_mode_branch(undefined4 param_1,char *param_2,uint param_3,undefined1 *param_4);  /* 0x0305d3e8 264B */
void apply_flags_from_flash_0x65_0x66(void);  /* 0x0305d544 444B */
void clear_field_bit3_and_set_dialog_bit(void);  /* 0x0305d93c 28B */
void ui_notify_0x22_on_bit3_set_and_bit1_clear(void);  /* 0x0305d984 38B */
void dialog_commit_channel_selection(void);  /* 0x0305d9bc 264B */
void dialog_ucos_flag_signal_and_wait(void);  /* 0x0305db28 58B */
byte keypad_dispatch_not_inhibited(void);  /* 0x0305dbe4 16B */
void dialog_flags_dismiss_if_state_0x20(void);  /* 0x0305dd4c 62B */
void protocol_control_char_dispatch_backspace_wrapper(void);  /* 0x0305df4c 10B */
void call_setup_control_char_and_reset();  /* 0x0305df58 122B */
void call_teardown_on_event_flag(void);  /* 0x0305e220 110B */
void tx_led_tone_off_on_event_flag(void);  /* 0x0305e2c8 50B */
void event_flags_dispatch_bit8_group(void);  /* 0x0305e318 420B */
void event_flags_dispatch_bit4_group(void);  /* 0x0305e694 278B */
void ui_key_event_dispatcher(void);  /* 0x0305e7c8 502B */
void event_flags1_group_dispatch(void);  /* 0x0305e9f8 74B */
void event_flags2_group_dispatch(void);  /* 0x0305eb78 74B */
void numeric_dialog_field_apply_or_gps_update(void);  /* 0x0305ebc4 322B */
void ui_event_flag_dispatch_loop(void);  /* 0x0305ee70 188B */
void hw_port_state_poll_into_ram_mirror(void);  /* 0x0305ef44 468B */
void menu_power_on_display_and_keypad_poll_loop(void);  /* 0x0305f128 386B */
void radio_boot_full_init_sequence(void);  /* 0x0305f2c8 474B */
uint decimal_to_bcd_pack(uint param_1);  /* 0x0305f4b4 40B */
void u32_to_bcd4_encode(uint param_1,int param_2);  /* 0x0305f4f0 50B */
byte nibble_to_hex_ascii_uppercase(byte param_1);  /* 0x0305f524 28B */
char count_clear_bits_low23(uint param_1);  /* 0x0305f540 32B */
int bcd_frequency_decode();  /* 0x0305f560 56B */
int bcd_buffer_to_int(int param_1,uint param_2);  /* 0x0305f598 54B */
void bcd_unpack_int_default_width(undefined4 param_1);  /* 0x0305f614 10B */
void int_to_bcd_bytes(int param_1,uint param_2,uint param_3);  /* 0x0305f6e0 56B */
void channel_change_detect_reset_and_redisplay(void);  /* 0x0305f838 136B */
undefined4 strcmp_byte_ordinal(byte *param_1,byte *param_2);  /* 0x0305f8cc 80B */
byte hex_digit_to_value(char param_1);  /* 0x0305f990 54B */
void soft_double_conditional_add_or_sub();  /* 0x0305f9f4 60B */
void channel_switch_teardown_and_apply();  /* 0x0305fa38 410B */
void tx_timeout_cleanup(void);  /* 0x0305fc24 114B */
void noop_stub_0305fca4(void);  /* 0x0305fca4 2B */
void idle_background_notify_counter(void);  /* 0x0305fcd4 152B */
void signal_meter_bargraph_draw(char param_1,char param_2,ushort param_3);  /* 0x0305fd90 420B */
void menu_highlight_position_update();  /* 0x0305ff44 158B */
void tx_supervisory_tick(void);  /* 0x030602b0 882B */
void idle_timeout_counter_tick(void);  /* 0x0306069c 98B */
void tx_state_transition_and_supervisory_tick(void);  /* 0x03060700 82B */
void tx_state_main_task_loop(void);  /* 0x03060754 252B */
void radio_id_entry_read_by_stored_index(int param_1);  /* 0x030608c4 30B */
void radio_id_display_field_prep_dispatch(void);  /* 0x030608e4 48B */
void call_status_indicator_byte_compute(void);  /* 0x03060a4c 214B */
void noop_stub_03060b70(void);  /* 0x03060b70 2B */
void noop_stub_03060b74(void);  /* 0x03060b74 2B */
void tx_led_or_tone_service_tick_dispatch(void);  /* 0x03060b78 18B */
void tx_led_tone_blink_toggle_variant_b(void);  /* 0x03060b94 76B */
void tx_led_or_tone_on_and_conditional_off(void);  /* 0x03060be0 10B */
void tx_led_or_tone_off_and_conditional(void);  /* 0x03060bea 10B */
void tx_led_tone_blink_toggle_variant_c(void);  /* 0x03060bf4 80B */
void tx_led_tone_blink_toggle_variant_a(void);  /* 0x03060c44 120B */
void tx_led_or_tone_blink_heartbeat(void);  /* 0x03060cbc 70B */
void tx_led_or_tone_toggle_off_on(void);  /* 0x03060d02 8B */
void noop_stub_03060d0a(void);  /* 0x03060d0a 2B */
void compand_table_nibble_split_lookup();  /* 0x03060d80 40B */
void dtmf_code_flash_read(char param_1,uint param_2,uint param_3,void *param_4);  /* 0x03060de4 76B */
void mutex_pend_no_timeout_03060f1c(void);  /* 0x03060e30 12B */
void operating_mode_set_and_notify(byte param_1);  /* 0x03060e48 54B */
void noop_stub_03060e80(void);  /* 0x03060e80 2B */
void dtmf_sequence_playback_start(void);  /* 0x03060e84 300B */
void dtmf_digit_sequence_play_from_idxf_a(void);  /* 0x03060fec 4B */
void dtmf_digit_sequence_play_from_idxe(void);  /* 0x03060ff0 4B */
void dtmf_digit_sequence_play_from_idxf_b(void);  /* 0x03060ff4 4B */
void dtmf_digit_sequence_play_reentry1(char param_1);  /* 0x03060ff8 14B */
void dtmf_digit_sequence_play_from_idxc(void);  /* 0x03061006 86B */
void dtmf_digit_sequence_playback_cleanup(void);  /* 0x0306105c 138B */
void dtmf_digit_sequence_play_from_idxd_a(void);  /* 0x030610e6 4B */
void dtmf_digit_sequence_play_from_idxd_b(void);  /* 0x030610ea 4B */
void recording_stop_rx_finalize(void);  /* 0x0306116c 104B */
void flash_pagesplit_write_with_split_markers(void);  /* 0x030611d4 134B */
void spi_flash_config_block_magic_scan(void);  /* 0x03061280 282B */
void recording_list_screen(int param_1,uint param_2,uint param_3);  /* 0x0306139c 298B */
void channel_list_cursor_decrement(uint *param_1,int *param_2);  /* 0x03061500 72B */
void recording_list_cursor_advance(int *param_1,int *param_2);  /* 0x03061548 66B */
void recording_playback_to_speaker();  /* 0x0306158c 584B */
void flash_field4_byte_update_with_shadow_copy(byte param_1);  /* 0x03061a40 72B */
void channel_bitmap_flash_rebuild(void);  /* 0x03061b0c 470B */
void analog_digital_channel_tracking_sync(void);  /* 0x03061cfc 364B */
void settings_block_cache_load_from_flash(void);  /* 0x03061e8c 244B */
void gps_time_compact_format(char param_1,uint param_2,byte param_3,undefined1 param_4,byte param_5,byte param_6, undefined1 param_7,undefined4 param_8);  /* 0x03062138 322B */
void gps_nmea_gprmc_parser(char param_1,undefined4 param_2);  /* 0x03062290 594B */
undefined2 aprs_log_count_read(void);  /* 0x0306265c 34B */
undefined4 aprs_log_record_id_read(uint param_1);  /* 0x03062680 46B */
void aprs_log_record_read(uint param_1,void *param_2);  /* 0x030626b0 34B */
void aprs_log_record_detail_screen(undefined2 param_1);  /* 0x030626d4 1254B */
void aprs_info_list_screen(uint param_1,uint param_2,uint param_3);  /* 0x03062c14 200B */
void aprs_waypoint_list_conditional_show(undefined2 *param_1,undefined2 *param_2);  /* 0x03062cdc 38B */
void aprs_log_clear(void);  /* 0x03062e90 70B */
void channel_list_screen_render(uint param_1,uint param_2);  /* 0x03062ed8 240B */
void soft_double_multiply_then_soft_double_divide();  /* 0x03063094 24B */
void gps_position_display_screen(void);  /* 0x030636e0 1246B */
void display_fill_rect_then_display_draw_number_centered(undefined1 value);  /* 0x03063cc4 48B */
undefined4 dtmf_compand_config_apply(undefined1 param_1);  /* 0x03063cf4 338B */
void boot_mode_select_persist_and_reset(void);  /* 0x0306406c 124B */
void circular_buffer_append_3bit_status();  /* 0x030640e8 140B */
void vfo_apply_active_side_config(void);  /* 0x030641f4 140B */
void vfo_exit_dual_watch_and_refresh(void);  /* 0x03064280 64B */
void mode_transition_cleanup(void);  /* 0x030644d8 64B */
void vfo_sync_active_side_on_ptt(void);  /* 0x03064518 62B */
void timed_feature_config_load_from_flash(void);  /* 0x03064cb4 94B */
void key_event_state_clear_preserve_bit0(void);  /* 0x03064d14 32B */
undefined1 flash_stored_setting_load_and_dispatch(uint param_1);  /* 0x03064f54 52B */
undefined4 status2_mailbox_post_reason0(void);  /* 0x030652d8 24B */
undefined4 status2_mailbox_post_reason4(void);  /* 0x030652f0 24B */
undefined4 status2_mailbox_post_reason5(void);  /* 0x03065308 24B */
undefined4 status2_mailbox_post_reason6(void);  /* 0x03065320 24B */
undefined4 status2_mailbox_post_reason7(void);  /* 0x03065338 24B */
void tx_disable_gate_check_wrapper(void);  /* 0x03065350 8B */
undefined4 status2_mailbox_post_reason8(void);  /* 0x03065358 24B */
undefined4 status2_mailbox_post_reason9(void);  /* 0x03065370 24B */
undefined4 status2_mailbox_post_reason10(void);  /* 0x03065388 24B */
undefined4 list_screen_event_noop_stub(void);  /* 0x03065414 4B */
undefined4 noop_stub_03065428(void);  /* 0x03065428 6B */
void peripheral_reset_gpio_pulse_sequence_variant_030654d8(void);  /* 0x030654d8 60B */
void rda5807m_init(void);  /* 0x0306565c 56B */
void rda5807m_power_down(void);  /* 0x030657c0 52B */
void rda5807m_seek_up(uint param_1);  /* 0x03065860 140B */
byte value_in_range_check(ushort param_1);  /* 0x030658ec 24B */
void flash_block4_write_offset0x700_u16(undefined4 param_1);  /* 0x03065904 18B */
void bcd_pack_and_write_flash_block4_0x702(uint param_1);  /* 0x03065918 70B */
void settings_value_step_by_ten_clamped_write(char param_1);  /* 0x0306597c 74B */
void seek_banner_draw(char param_1);  /* 0x030659c8 72B */
void battery_value_display_format(char param_1);  /* 0x03065a10 374B */
void channel_scan_dwell_timer_tick(void);  /* 0x03066058 94B */
void list_cursor_decrement_variant2(undefined1 *param_1,undefined1 *param_2);  /* 0x03066274 40B */
void list_cursor_increment_variant2(undefined1 *param_1,undefined1 *param_2);  /* 0x0306629c 40B */
undefined4 flash_block65_string_lookup_exists(undefined4 param_1);  /* 0x030662c4 82B */
void flash_field_write_and_readback_channel_data(undefined1 param_1);  /* 0x03066334 80B */
void channel_and_roaming_record_read(ushort param_1,undefined4 param_2);  /* 0x03066384 62B */
void channel_scrolling_list_render_with_roaming(uint param_1,uint param_2,uint param_3);  /* 0x030663c4 214B */
void list_cursor_decrement_then_channel_scrolling_list_render_with_roaming(undefined1 *param_1,undefined1 *param_2);  /* 0x0306649c 28B */
void list_cursor_increment_then_channel_scrolling_list_render_with_roaming(undefined1 *param_1,undefined1 *param_2);  /* 0x030664d0 28B */
ushort flash_field_channel_table_lookup(uint param_1,ushort param_2);  /* 0x030664ec 124B */
void channel_roaming_list_render_rows();  /* 0x03066568 138B */
void roam_zone_countdown_decrement_with_limit(uint param_1,uint param_2);  /* 0x030665f4 146B */
void list_cursor_prev_and_redraw(undefined1 *param_1,undefined1 *param_2);  /* 0x0306669c 26B */
void list_cursor_next_and_redraw(undefined1 *param_1,undefined1 *param_2);  /* 0x030666b8 26B */
void roam_zone_slot_byte_write_with_wear_count(uint param_1,undefined1 param_2);  /* 0x030666d4 78B */
void modem_c7000_param_table_defaults_init(void);  /* 0x0306674c 88B */
undefined4 scan_byte_stream_match_returns_0_nomatch_0xff(char param_1);  /* 0x03066834 84B */
void block3_tonecall_record_assemble(void);  /* 0x03066e4c 86B */
undefined4 flash_record_frequency_calibration_apply(uint param_1);  /* 0x03066f98 396B */
void seconds_decimal_from_int_format();  /* 0x03067494 40B */
void numeric_value_display_centered_percent_d_wrapper();  /* 0x030674bc 12B */
void memset_bytes_wrapper(void);  /* 0x030674d4 14B */
void byte_bitplane_differential_xor_invert(int param_1,uint param_2);  /* 0x030674e4 82B */
uint byte_bit_reverse(uint param_1);  /* 0x030675f4 66B */
ushort crc16_ccitt(int param_1,uint param_2);  /* 0x03067664 116B */
undefined4 fsk_diff_decode_dmr_sync_frame();  /* 0x03067858 286B */
void display_clear_and_draw_scaled_number_ms_label(undefined1 value);  /* 0x03067f18 46B */
void display_clear_and_draw_number_with_label_arg(undefined1 value);  /* 0x03067f48 42B */
void settings_duration_seconds_display_call(undefined1 param_1);  /* 0x03067f74 10B */
ushort bdc_table_count_read(void);  /* 0x03067f80 52B */
undefined4 bdc_table_lookup_by_id(undefined2 param_1,undefined2 *param_2);  /* 0x03067fb4 106B */
void bdc_table_read_by_index(uint param_1,void *param_2);  /* 0x0306803c 36B */
uint flash_block6_callsign_lookup_or_hex_fallback(char *param_1,undefined1 *param_2);  /* 0x03068060 260B */
undefined1 factory_service_command_dispatch(char param_1,undefined1 param_2);  /* 0x030682bc 195B */
void local_beep_frontend_init_and_burst(void);  /* 0x03068450 162B */
short ucos3_message_broadcast_dispatcher(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x030686a4 256B */
uint OSFlagPend(int *param_1,uint param_2,undefined4 param_3,uint param_4,int *param_5,undefined4 *param_6);  /* 0x03068814 180B */
void queue_list_init_and_register();  /* 0x03068db4 152B */
short timed_task_state_transition_with_sched_lock_timing(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x03068e7c 498B */
undefined4 OSFlagPost_internal(int param_1,uint param_2,short param_3,undefined4 param_4,undefined4 *param_5);  /* 0x030690e4 448B */
undefined4 OSFlagPost(int *param_1,undefined4 param_2,uint param_3,undefined4 *param_4);  /* 0x030692ac 128B */
undefined4 * OSMemGet(int param_1,undefined4 *param_2);  /* 0x03069334 84B */
void OSMemPut(int param_1,undefined4 *param_2,undefined4 *param_3);  /* 0x03069388 96B */
void os_queue_create_and_register(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,ushort param_4, ushort param_5,undefined4 *param_6);  /* 0x03069404 274B */
void critical_section_struct_init(undefined4 *param_1,undefined2 param_2);  /* 0x030695f0 16B */
int queue_node_dequeue_and_free(undefined4 *param_1,undefined2 *param_2,int *param_3,undefined4 *param_4);  /* 0x03069600 112B */
void queue_node_alloc_and_enqueue();  /* 0x03069670 184B */
short os_sched_op_dispatch_with_lock_timing(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x030699d0 256B */
void OSMutexCreate(undefined4 *param_1,undefined4 param_2,undefined4 *param_3);  /* 0x03069d20 160B */
undefined4 sched_lock_unlock_with_max_duration_tracking(int *param_1,undefined4 *param_2);  /* 0x0306a100 184B */
short os_sched_op_dispatch_with_lock_timing_variant2(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x0306a3ac 256B */
void instance_list_prepend_with_vtable(int param_1);  /* 0x0306a4e0 30B */
short radio_list_item_remove_by_handle(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x0306a5f8 306B */
void reentrant_dispatch_single_or_list(int param_1,undefined4 param_2,undefined2 param_3,ushort param_4,undefined4 param_5, undefined4 *param_6);  /* 0x0306a750 288B */
void os_post_message_opt_validated(int *param_1,undefined4 param_2,undefined2 param_3,ushort param_4, undefined4 *param_5);  /* 0x0306a870 178B */
int dmr_command_subop_dispatch_with_crit_section(int *param_1,undefined4 *param_2);  /* 0x0306af04 188B */
byte guarded_state_validate_dispatch(int *param_1,undefined4 *param_2);  /* 0x0306afc0 100B */
void linked_list_prepend_struct(int param_1);  /* 0x0306b05c 26B */
void OSTmrCreate();  /* 0x0306b078 232B */
void timer_list_entry_unlink(int param_1);  /* 0x0306b3b4 82B */
undefined4 OSTmr_state_dispatch_callback(int *param_1,short param_2,undefined4 param_3,undefined4 *param_4);  /* 0x0306b4a0 234B */
bool isalnum_impl(char param_1);  /* 0x0306b73c 46B */
bool isxdigit_impl(char param_1);  /* 0x0306b7ac 46B */
byte isspace_impl(char param_1);  /* 0x0306b7f0 50B */
void memset_with_word_alignment(undefined1 *param_1,undefined1 param_2,uint param_3);  /* 0x0306ba88 116B */
void memmove_overlap_safe(void *param_1,void *param_2,uint param_3);  /* 0x0306bb08 182B */
int queue_list_remaining_capacity_scaled(int *param_1,uint param_2,undefined4 *param_3);  /* 0x0306bd2c 166B */
void result_struct_init_or_null_delegate(undefined4 *param_1,undefined4 *param_2);  /* 0x0306bdf0 74B */
undefined4 locked_queue_pop_dequeue(int *param_1,uint param_2,undefined4 *param_3);  /* 0x0306c244 188B */
void queue_list_insert_unique(int *param_1,int param_2,undefined4 *param_3);  /* 0x0306c3b4 272B */
int queue_list_find_index_from_tail(int *param_1,int param_2,undefined4 *param_3);  /* 0x0306c4c8 286B */
uint strtoul_ascii_to_uint_radix(char *param_1,undefined4 *param_2,uint param_3,int param_4,undefined1 *param_5);  /* 0x0306c5ec 410B */
int integer_to_radix_string_format(uint param_1,uint param_2,uint param_3,int param_4,char param_5,char param_6, char param_7,int param_8);  /* 0x0306c788 454B */
uint strnlen_impl(char *param_1,uint param_2);  /* 0x0306c954 50B */
char * strncpy_nul_terminated(char *param_1,char *param_2,uint param_3);  /* 0x0306c994 98B */
ushort strncmp_impl(byte *param_1,byte *param_2,uint param_3);  /* 0x0306ca7c 190B */
uint strncmp_ck803s_null_safe(char *param_1,undefined1 *param_2,uint param_3);  /* 0x0306cb4c 236B */
char * strnchr_bounded(char *param_1,uint param_2,char param_3);  /* 0x0306cc48 86B */
char * reverse_char_search_bounded(char *param_1,int param_2,char param_3);  /* 0x0306ccb0 70B */
undefined4 CPU_TS_TmrRd(void);  /* 0x0306ced4 18B */
void mmio_dummy_read_1400000c_dup();  /* 0x0306cf10 8B */
void irq_controller_unmask_and_register_handler(int param_1,int param_2);  /* 0x0306cf70 86B */
void soft_double_cos();  /* 0x0306d4f0 180B */
void noop_stub_0306d5a8();  /* 0x0306d5a8 8B */
void soft_double_sin();  /* 0x0306d65c 180B */
uint soft_double_x_plus_x_squared();  /* 0x0306d714 474B */
int soft_double_rem_pio2();  /* 0x0306d9a0 880B */
int soft_double_to_int();  /* 0x0306e374 54B */
uint * softfloat32_addsub_core(uint *param_1,uint *param_2,uint *param_3);  /* 0x0306e3b0 318B */
float softfloat32_add(float a,float b);  /* 0x0306e4f0 50B */
float softfloat32_sub(float a,float b);  /* 0x0306e524 58B */
float softfloat32_mul(float a,float b);  /* 0x0306e564 272B */
undefined4 softfloat32_compare_gt(undefined4 param_1,undefined4 param_2);  /* 0x0306e764 62B */
undefined4 softfloat32_compare(undefined4 param_1,undefined4 param_2);  /* 0x0306e7a4 64B */
undefined4 int32_to_float32_special_case_only(int param_1);  /* 0x0306e7e4 58B */
void float32_unpack_then_softdouble_pack_round_wrapper();  /* 0x0306e898 44B */
uint * soft_double_addsub_core(uint *param_1,uint *param_2,uint *param_3);  /* 0x0306e940 844B */
void soft_double_add();  /* 0x0306ec8c 60B */
void soft_double_sub();  /* 0x0306ecc8 68B */
void soft_double_multiply();  /* 0x0306ed10 668B */
void soft_double_divide();  /* 0x0306efb8 366B */
undefined4 soft_double_compare_packed_dup_0306f1b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);  /* 0x0306f1b0 72B */
undefined4 softdouble_compare_le();  /* 0x0306f1f8 74B */
undefined4 softdouble_compare_ne(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);  /* 0x0306f244 74B */
undefined4 soft_double_compare_packed();  /* 0x0306f290 72B */
undefined4 softdouble_compare_gt(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);  /* 0x0306f2d8 72B */
undefined4 soft_double_from_int();  /* 0x0306f320 62B */
uint softdouble_to_int32();  /* 0x0306f3a4 132B */
int umul32_to_64();  /* 0x0306f5a4 108B */
uint float32_pack_round();  /* 0x0306f610 220B */
void float32_unpack(uint *param_1,uint *param_2);  /* 0x0306f6ec 162B */
int softfloat_compare_core(uint *param_1,uint *param_2);  /* 0x0306f790 140B */
int soft_double_compare(uint *param_1,uint *param_2);  /* 0x0306fc04 162B */
void strtol_signed_wrapper(undefined4 param_1);  /* 0x0306fd34 12B */
void * malloc_best_fit(int size);  /* 0x0306fd40 138B */
void heap_free_with_adjacent_coalesce();  /* 0x0306fddc 112B */
uint lcg_rand_next(void);  /* 0x0306fea4 20B */
undefined4 strtod_ascii_to_double();  /* 0x0306ff18 548B */
int buffer_compare_memcmp_style(uint *param_1,uint *param_2,int param_3);  /* 0x03070270 264B */
void memcpy_ck803s(void *dest,void *src,int n);  /* 0x030703bc 126B */
void memset_ck803s(uint *param_1,uint param_2,int param_3);  /* 0x0307043c 158B */
char * strcat(char *dest,char *src);  /* 0x030704dc 26B */
char * strchr(char *s,int c);  /* 0x030704f8 18B */
void strcpy_ck803s();  /* 0x0307050c 34B */
int strlen_ck803s();  /* 0x030705d8 28B */
int isalpha(int c);  /* 0x0307063c 18B */
int isdigit(int c);  /* 0x03070650 8B */
int isspace(int c);  /* 0x03070658 18B */
int isupper(int c);  /* 0x0307066c 8B */
undefined4 noop_stub_03070678();  /* 0x03070678 4B */
undefined4 noop_stub_0307067c();  /* 0x0307067c 4B */
int vfprintf_core();  /* 0x03070724 150B */
void * memmove(void *dest,void *src,int n);  /* 0x0307175c 184B */
uint udivdi3_64by32(uint param_1,uint param_2,uint param_3,uint param_4);  /* 0x03071bf0 960B */
undefined4 soft_double_compare_packed_dup_03071fb4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);  /* 0x03071fb4 72B */
void gb2312_ui_string_table_channel_errors(void);  /* 0x030bf73c 1B */
void ascii_ui_string_table_response_prompt(void);  /* 0x030bfa78 6B */
uint cpu_sr_save_and_disable_irq_variant2(void);  /* 0x030bfdac 1B */
void cpu_sr_restore_irq_variant2(undefined4 sr);  /* 0x030bfdbc 1B */
int saturating_sub_from_global(uint param_1);  /* 0x030bfdc4 16B */
void OS_SchedLockTimeMeasStart_variant3(void);  /* 0x030bfe5c 36B */
void OS_SchedLockTimeMeasStop_variant3(void);  /* 0x030bfe80 56B */
uint count_leading_zeros_u32();  /* 0x030c0000 74B */
int count_trailing_zeros_u32(uint param_1);  /* 0x030c013c 26B */
int u32_count_trailing_zeros(uint param_1);  /* 0x030c0190 26B */
void store_u32_via_ptr(undefined4 *param_1,undefined4 param_2);  /* 0x030c03d8 6B */
void OS_IdleTask_variant3(void);  /* 0x030c0488 44B */
void ucos3_int_exit(void);  /* 0x030c04d0 130B */
void OS_Sched(void);  /* 0x030c0554 92B */
void OSStart(undefined4 *param_1);  /* 0x030c0624 68B */
void linked_list_slot_free_and_unlink(int param_1);  /* 0x030c0cdc 138B */
void ucos_lock_release_cleanup_and_notify(void);  /* 0x030c0d68 50B */
void conditional_cached_value_refresh(void);  /* 0x030c0d9c 20B */
void OSSchedLock_variant2(undefined4 *param_1);  /* 0x030c0db0 92B */
void ucos_crit_section_nest_exit_with_lock_time_track(void);  /* 0x030c0e0c 46B */
void OSSchedUnlock_variant2(undefined4 *param_1);  /* 0x030c0e70 118B */
void OS_TaskBlock(int param_1,int param_2);  /* 0x030c0f88 58B */
void OS_Pend_variant2(int param_1,int param_2,undefined1 param_3,undefined4 param_4);  /* 0x030c0fdc 78B */
void message_phase_advance_dual_path();  /* 0x030c10fc 140B */
void bounded_queue_append_with_dropcount();  /* 0x030c1224 158B */
void radio_list_pool_init_and_transact_variant(undefined4 *param_1);  /* 0x030c14ec 206B */
char OS_PrioGetHighest_variant2(void);  /* 0x030c160c 38B */
short os_sched_op_dispatch_with_lock_timing_variant3(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x030c182c 256B */
void OSSemCreate_variant2(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4);  /* 0x030c19dc 152B */
short radio_list_item_remove_by_handle_variant(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x030c1aa4 306B */
int OS_SemPost_variant2(int param_1,ushort param_2,undefined4 param_3,undefined4 *param_4);  /* 0x030c1c08 228B */
undefined4 reentrant_lock_section_guard_variant2(int param_1,undefined4 *param_2);  /* 0x030c1f2c 182B */
undefined4 ucos_sem_pend_wait(undefined4 param_1,short param_2,undefined2 *param_3,int *param_4,int *param_5);  /* 0x030c1fe4 424B */
undefined4 dmr_message_dispatch_with_reentrancy_guard(int param_1,short param_2,undefined4 *param_3);  /* 0x030c21a0 214B */
undefined4 OSTaskSemSet(int param_1,undefined4 param_2,undefined4 *param_3);  /* 0x030c25d0 66B */
void OSTaskStkChk_variant2(int *param_1,int *param_2,int *param_3,undefined4 *param_4);  /* 0x030c2614 178B */
void OSTaskTimeQuantaSet(int param_1,int param_2,undefined4 *param_3);  /* 0x030c26c8 82B */
void radio_list_command_dispatch_jumptable(int param_1,undefined4 *param_2);  /* 0x030c285c 218B */
void OSTaskCreate_variant2(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,byte param_5, undefined4 *param_6,uint param_7,uint param_8,undefined2 param_9,int param_10, undefined4 param_11,ushort param_12,undefined4 *param_13);  /* 0x030c29f8 504B */
void OS_TaskQPost(int param_1,undefined4 param_2,undefined2 param_3,short param_4,undefined4 param_5,undefined4 *param_6);  /* 0x030c2c10 454B */
void command_jump_table_dispatch(int param_1,undefined4 *param_2);  /* 0x030c2e6c 58B */
int OS_TaskSemPost_variant3(int param_1,short param_2,undefined4 param_3,undefined4 *param_4);  /* 0x030c3014 610B */
void radio_command_jumptable_dispatch_flash();  /* 0x030c32e8 102B */
void timer_entry_insert_hash_bucketed_list_030c(int param_1,uint param_2,short param_3,undefined4 *param_4);  /* 0x030c3508 296B */
void OSTimeDlyResume(int param_1,undefined4 *param_2);  /* 0x030c3b58 110B */
bool serial_clock_out_byte_to_companion_chip(uint param_1);  /* 0x030c3f24 282B */
void rc4_key_scheduling_init();  /* 0x030c42b8 86B */
void rc4_keystream_xor_cipher(int param_1,int param_2,uint param_3);  /* 0x030c435c 112B */
void rc4_keystream_generate_to_buffer();  /* 0x030c43cc 106B */
uint dmr_privacy_mi_advance(char param_1,byte *param_2);  /* 0x030c4480 164B */
uint hamming23_syndrome_error_correct(uint param_1,uint param_2);  /* 0x030c4e50 486B */
void codeplug_bitfield_unpack_3byte(uint *param_1,int param_2,byte param_3);  /* 0x030c518c 444B */
void dmr_privacy_rx_keystream_setup(char param_1,char *param_2);  /* 0x030c5348 202B */
void dmr_privacy_keystream_apply(char *param_1,int param_2,uint param_3);  /* 0x030c5538 298B */
void dmr_privacy_keystream_apply_rx_variant(char *param_1,int param_2,uint param_3);  /* 0x030c5664 298B */
void dmr_privacy_tx_keystream_setup(char param_1,char *param_2);  /* 0x030c57f4 256B */
undefined4 packed_field_checksum_validate_and_copy(uint *param_1,undefined4 param_2);  /* 0x030c58f4 174B */
undefined4 decisecond_round_up_dispatch(undefined4 param_1,int param_2);  /* 0x030c5da8 30B */
void hr_c7000_modem_core_reinit_sequence(void);  /* 0x030c65f8 246B */
uint rng_seed_from_fm_voice_bytes(void);  /* 0x030c6780 110B */
ushort channel_record_commit_step_with_fixedpoint_scale(undefined4 param_1,short param_2,undefined4 param_3,short param_4,ushort param_5, ushort param_6,short param_7,int param_8);  /* 0x030c6b5c 132B */
short channel_audio_gain_clamp(short param_1,int param_2,short param_3);  /* 0x030c70f8 76B */
void display_status_buffer_reset_or_score_calc(int param_1,short param_2);  /* 0x030c84f4 102B */
int signed_divide_saturating_halved();  /* 0x030c88bc 100B */
int signed_divide_saturating();  /* 0x030c8994 98B */
ushort freq_range_validate_and_select(ushort param_1,int param_2,ushort param_3,int param_4,undefined2 *param_5);  /* 0x030c89f8 106B */
ushort range_clamp_or_saturating_negate(ushort param_1,int param_2,ushort param_3,int param_4,undefined2 *param_5);  /* 0x030c8a7c 126B */
uint fixed_point_table_interp_16bit(int param_1);  /* 0x030c8c1e 2B */
void array_copy_u16();  /* 0x030c909c 24B */
void u16_buffer_fill_memset(undefined2 *param_1,undefined2 param_2,int param_3);  /* 0x030c90b4 16B */
ushort pack_u16_array_low_bits_to_bitfield(int param_1,short param_2);  /* 0x030c90c4 50B */
int unpack_bits_lsb_first_to_u16_array(int param_1,int param_2,short param_3);  /* 0x030c90f8 48B */
int unpack_bits_lsb_first_to_u16_array_signed();  /* 0x030c9128 54B */
void find_k_smallest_by_absolute_value(uint *param_1,int param_2,ushort param_3,short param_4,short param_5);  /* 0x030c9160 460B */
int short_sample_vs_twolevel_pattern_sse_metric(int param_1,int param_2,short param_3,short param_4);  /* 0x030c932c 76B */
void call_config_state_duplicate(undefined2 *param_1,undefined2 *param_2);  /* 0x030c98dc 68B */
undefined2 classify_id_into_range_bucket();  /* 0x030ca054 66B */
short argmax_index_int16_array(short *param_1,short param_2);  /* 0x030ca880 58B */
short argmax_index_int32_array(int *param_1,short param_2);  /* 0x030ca8bc 48B */
uint gf256_multiply_aes(uint param_1,uint param_2);  /* 0x030cc9dc 120B */
void xor_fold_16byte_key_block(int param_1,undefined4 *param_2);  /* 0x030cca54 84B */
int aes_subword_sbox_substitute(uint param_1);  /* 0x030ccaa8 58B */
void aes_shift_rows(void);  /* 0x030ccb88 32B */
void aes_key_schedule_expand();  /* 0x030ccbcc 196B */
void aes_block_encrypt();  /* 0x030ccc9c 378B */
void block_cipher_decrypt_16byte_variant_a(undefined1 *param_1,undefined1 *param_2,int param_3,uint param_4);  /* 0x030cce18 470B */
void dmr_privacy_mi_expand_lfsr(byte *param_1,byte *param_2,byte param_3);  /* 0x030cd000 140B */
void dmr_privacy_aes_ofb_keystream_128();  /* 0x030cd08c 74B */
void dmr_privacy_alg2_key_setup_stub();  /* 0x030cd0d8 2B */
void dmr_privacy_alg2_block_op_stub();  /* 0x030cd0dc 2B */
void dmr_privacy_alg2_block_encrypt_stub();  /* 0x030cd0e4 2B */

/* ---- STRUCTURAL (1813 functions) ---- */

void assert_null_ptr_spin(void);  /* 0x000101b4 2B */
void irq_lock_release_global_value(void);  /* 0x00010224 22B */
void call_and_return_wrapper(void);  /* 0x0001042c 8B */
void list_node_unlink_a(undefined4 *param_1,int *param_2);  /* 0x00010c24 60B */
void queue_list_process_and_reset(int param_1);  /* 0x00010c60 42B */
void timer_object_register_into_bucket_list(int param_1);  /* 0x00010f4c 84B */
void ucos3_rdy_list_insert_by_prio();  /* 0x00010fa0 40B */
void irq_disable_save_and_release_reinit(void);  /* 0x00011148 50B */
void sched_obj_state_reset_and_unlink();  /* 0x000114dc 140B */
void msg_node_retire_by_state();  /* 0x0001156c 150B */
void command_dispatcher(void);  /* 0x000116a4 318B */
undefined4 ucos3_sched_unlock_and_resched();  /* 0x00012614 72B */
void ucos_event_flag_ready_bits_dispatch(int param_1,undefined4 param_2,undefined2 param_3,short param_4,undefined4 param_5, undefined4 *param_6);  /* 0x00012ff0 454B */
void radio_command_dispatcher(int param_1,undefined4 *param_2);  /* 0x0001324c 58B */
void dll_node_remove();  /* 0x00013a48 58B */
void ucos3_schedlock_exit_resched_13fa4(void);  /* 0x00013fa4 18B */
void ucos3_schedlock_exit_resched_14010(void);  /* 0x00014010 18B */
void ucos3_schedlock_exit_resched_14022(void);  /* 0x00014022 18B */
void ucos3_schedlock_exit_resched_14034(void);  /* 0x00014034 18B */
void ucos3_schedlock_exit_resched_1409c(void);  /* 0x0001409c 18B */
void ucos3_schedlock_exit_resched_140ae(void);  /* 0x000140ae 24B */
void alpu_boot_sem_create_and_auth_init(undefined1 *param_1);  /* 0x00015d8c 120B */
void voice_record_direction_select(char param_1);  /* 0x00015fa4 92B */
void indexed_ramp_field_store_a(undefined4 param_1,uint param_2);  /* 0x00016040 34B */
void indexed_ramp_field_store_b(undefined4 param_1,uint param_2);  /* 0x00016064 34B */
undefined4 label_table_segment_copy(uint param_1,undefined4 param_2,uint param_3,int param_4);  /* 0x0001620c 100B */
void pass_through_wrapper(undefined1 param_1);  /* 0x00016b54 10B */
uint alpu_nonce_byte_next(void);  /* 0x00016b60 110B */
int bytes_to_u32_be(void);  /* 0x00017298 24B */
void tx_audio_dac_envelope_ramp(int param_1,int param_2,undefined1 param_3);  /* 0x0002b364 202B */
void fd6818b_reg50_tx_audio_unmute_set(void);  /* 0x0002b50c 8B */
void fd6818b_reg50_tx_audio_mute_set(void);  /* 0x0002b514 8B */
void fd6818b_driver_state_reset(void);  /* 0x0002b634 64B */
void rf_retune_and_apply_channel_mode(uint param_1);  /* 0x0002b6a0 318B */
void spi_flash_cmd_sector_erase_raw(void);  /* 0x0002b9b4 70B */
void spi_flash_sector_erase();  /* 0x0002b9fc 16B */
void serial_flash_sector_erase_then_poll_ready(void);  /* 0x0002c0f8 102B */
void serial_flash_write_chunk_with_retry(int param_1,undefined4 param_2,undefined4 param_3);  /* 0x0002c160 78B */
void antenna_switch_select_gpio_24_22(int param_1);  /* 0x0002c878 62B */
void stage_hook_dispatch(uint param_1);  /* 0x0002cbd0 16B */
void dmr_ber_frame_compare_and_report(void);  /* 0x0002d358 276B */
byte vfo_active_side_mode_nibble(void);  /* 0x0002deb8 89B */
void busy_wait_delay_loop_4arg();  /* 0x0002df80 236B */
void busy_wait_delay_n_units(uint param_1);  /* 0x0002e0d8 28B */
void ring_half_block_enqueue_post(void);  /* 0x0002e1d4 98B */
void ring_half_block_dequeue_fallback_post(void);  /* 0x0002e238 190B */
void mmio_110003b0_bit4_set(void);  /* 0x0002e35c 16B */
void mmio_110003b0_bit5_set(void);  /* 0x0002e36c 16B */
undefined4 label_table_segment_copy_alt(uint param_1,undefined4 param_2,uint param_3,int param_4);  /* 0x0002e37c 100B */
void display_scroll_task_loop(void);  /* 0x0002f000 986B */
undefined4 refcounted_cs_object_init_wrapper(undefined4 param_1,undefined4 param_2);  /* 0x03001690 22B */
void boot_main_gpio_gate(void);  /* 0x030017bc 68B */
void state_machine_field_init_with_mode_normalize(int param_1,undefined4 param_2,undefined4 param_3);  /* 0x03001920 68B */
undefined4 get_state_field_03001b34(void);  /* 0x03001b34 6B */
void state_field_update_and_store_scaled_micro(undefined4 param_1,undefined4 param_2);  /* 0x03001b54 30B */
undefined4 irq_locked_read_u32_iram(void);  /* 0x03001b78 18B */
void unexpected_isr_handler(void);  /* 0x03001c04 10B */
void sram_state_table_reset_clear_bit_0x21(void);  /* 0x03001cc4 34B */
uint msb_bit_position_via_byte_table_variant2();  /* 0x030021b8 74B */
void ucos3_highrdy_commit_variant2(void);  /* 0x03002216 42B */
void ucos3_int_highrdy_commit_variant2(void);  /* 0x0300223e 30B */
void word_buffer_clear_set_end_a(void);  /* 0x03002328 44B */
void bounded_queue_lock_release_pair_variant(void);  /* 0x030024fc 82B */
void radio_bringup_protocol_request_0x0b();  /* 0x030025c8 58B */
void owner_slot_array_init_a(int param_1,undefined4 *param_2,short param_3);  /* 0x03002620 46B */
void pend_list_insert_by_prio_a(undefined4 *param_1,int *param_2);  /* 0x0300265c 108B */
void list_node_unlink_b(undefined4 *param_1,int *param_2);  /* 0x030026c8 60B */
void slot_table_find_and_store_a(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5);  /* 0x03002730 64B */
void slot_list_table_clear_8(void);  /* 0x03002770 24B */
void radio_device_state_reset_and_bringup_variant(int *param_1);  /* 0x0300278c 188B */
void slot_list_push_front_a(int param_1);  /* 0x03002888 96B */
void slot_list_push_back_a(int param_1);  /* 0x030028f0 84B */
void timer_list_swap_or_rotate_head(int *param_1);  /* 0x03002978 60B */
void queued_task_event_dispatch_with_counter(void);  /* 0x03002a4c 40B */
void ucos_timer_live_count_decrement_hook(void);  /* 0x03002a84 20B */
void activity_timer_message_dispatch_complete(int *param_1);  /* 0x03002ae0 158B */
void channel_timeout_arm_and_unlink(int param_1,int param_2);  /* 0x03002b90 58B */
void channel_object_link_or_clear_init(int param_1,int param_2,undefined1 param_3,undefined4 param_4);  /* 0x03002bcc 68B */
void feature_activate_if_not_already_set(int param_1);  /* 0x03002c14 28B */
void serial_command_phase_tracker_and_dispatch(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5);  /* 0x03002c30 152B */
void message_type_handler_dispatch_03002d8c(void);  /* 0x03002d8c 128B */
void message_queue_consumer_task(void);  /* 0x03002e2c 114B */
char table_index_derive_from_element_count(void);  /* 0x03002fc8 38B */
int radio_list_command_dispatch_with_iteration(int param_1,ushort param_2,undefined4 param_3,undefined4 *param_4);  /* 0x0300304c 228B */
void radio_list_item_add_forever(void);  /* 0x0300349c 30B */
void clear_slot_table_records(void);  /* 0x0300373c 36B */
void protocol_request_validate_and_dispatch(undefined4 *param_1);  /* 0x03003768 114B */
void timer_list_unlink_node();  /* 0x0300393c 58B */
void timer_wheel_tick_task(void);  /* 0x03003ad8 40B */
void radio_list_item_add_guarded(int param_1,ushort param_2,int *param_3);  /* 0x03003b04 242B */
void message_queue_post_zero_record(void);  /* 0x03003c04 44B */
void gpio_set_output_bit_variant2(uint param_1);  /* 0x03003c3c 68B */
void gpio_clear_output_bit_variant2(uint param_1);  /* 0x03003c80 68B */
void flash_controller_descriptor_init_once(void);  /* 0x03003dd0 122B */
undefined4 modem_wait_ready_then_proceed();  /* 0x03003e4c 66B */
int flash_region_write_chunked(uint param_1,uint param_2,int param_3);  /* 0x03003f60 200B */
undefined4 flash_controller_init_entry(void);  /* 0x03004030 10B */
undefined4 flash_erase_firmware_region_locked(void);  /* 0x03004040 58B */
bool ymodem_flash_block_program(int *param_1,undefined4 param_2,int param_3);  /* 0x0300407c 82B */
void busy_wait_ms_alt(uint param_1);  /* 0x030042e4 28B */
void busy_wait_count_delay(uint param_1);  /* 0x03004300 198B */
void hr_c7000_bringup_sequence(void);  /* 0x03004474 80B */
void xmodem_receive_entry(void);  /* 0x03004550 10B */
uint xmodem_ymodem_block_receive_loop(undefined4 param_1);  /* 0x03004618 578B */
void pack_name_and_decimal_suffix_record(undefined1 *param_1,char *param_2,undefined4 *param_3);  /* 0x0300487c 150B */
void cpu_sr_restore_irq_inlined_fragment();  /* 0x0300c000 120B */
void modem_fm_bandwidth_write_0x5f();  /* 0x0300c2cc 14B */
void modem_fm_ptt_set(char param_1);  /* 0x0300c304 34B */
void call_setup_sm_init(void);  /* 0x0300c328 128B */
byte read_byte_field_0300c3ac(void);  /* 0x0300c3ac 6B */
void write_byte_field_0300c3b4(byte param_1);  /* 0x0300c3b4 6B */
void write_byte_field_0300c3bc(byte param_1);  /* 0x0300c3bc 6B */
void protocol_frame_periodic_timer_state_machine_thunk(void);  /* 0x0300c40c 8B */
void dmr_call_history_slot_append_batch_thunk(void);  /* 0x0300c414 8B */
void clear_byte_field_dat0302432c_plus3_thunk(void);  /* 0x0300c41c 8B */
void radio_state_reinit_and_120s_timer_start_thunk(void);  /* 0x0300c424 8B */
undefined4 timed_task_state_advance(undefined4 param_1);  /* 0x0300c450 20B */
void OSFlagPend_wrapper_consume(void *flaggrp,uint flags,int consume,uint timeout,void *out_err);  /* 0x0300c464 48B */
int OSFlagPost_wrapper_set(void *flaggrp,uint flags);  /* 0x0300c494 20B */
int OSFlagPost_wrapper_clr(void *flaggrp,uint flags);  /* 0x0300c4a8 20B */
undefined4 ucos_pend_gate_no_timeout_opt0x8000();  /* 0x0300c520 26B */
void timer_state_ensure_valid_or_recreate();  /* 0x0300c5e4 134B */
void osmbox_post_candidate2_on_check();  /* 0x0300c66c 36B */
void guarded_timer_config_apply_wrapper_a(undefined4 param_1);  /* 0x0300c690 14B */
void osmbox_post_candidate2_on_check_0300c768(void);  /* 0x0300c6a0 10B */
void guarded_timer_config_apply_wrapper_b(uint config);  /* 0x0300c6ac 14B */
void osmbox_post_candidate2_on_check_0300c770(void);  /* 0x0300c6bc 10B */
void guarded_timer_config_apply_wrapper();  /* 0x0300c6c8 14B */
void osmbox_post_candidate2_on_check_0300c778(void);  /* 0x0300c6d8 10B */
void osmbox_post_candidate2_on_check_0300c780();  /* 0x0300c6f4 10B */
void OSFlagPost_wrapper_set_fixed_grp(uint param_1);  /* 0x0300c724 12B */
void OSFlagPost_wrapper_set_passthrough();  /* 0x0300c78c 12B */
void OSFlagPost_wrapper_set_fixed_grp_variant_0300c7c0(uint param_1);  /* 0x0300c7c0 12B */
void ucos3_flag_pend_ms(uint param_1,int param_2,int param_3,void *param_4);  /* 0x0300c7d8 34B */
void ucos3_flaggrp_set_bits(uint param_1);  /* 0x0300c7fc 12B */
void ucos3_flaggrp_clr_bits(uint param_1);  /* 0x0300c808 12B */
void ucos_mutex_0003644c_pend(void);  /* 0x0300c814 10B */
void ucos_mutex_00035f50_pend(void);  /* 0x0300c82c 10B */
void ucos_sem_00037820_pend(void);  /* 0x0300c844 10B */
void ui_mode_noop_stub_variant_0300c85c(void);  /* 0x0300c85c 10B */
void ucos3_task_create_prio25_stk0x100(void);  /* 0x0300c898 60B */
undefined4 radio_task_group_create(void);  /* 0x0300c904 880B */
void ui_mode_group_flag_post(byte param_1);  /* 0x0300cdb0 24B */
byte get_event_flags_byte_dispatch(uint index);  /* 0x0300cdc8 14B */
byte get_event_flags_packed_nibbles(void);  /* 0x0300ce44 14B */
void ui_mode_group1_flag_set(byte param_1,byte param_2);  /* 0x0300cf8c 76B */
void ui_mode_group2_flag_set(byte param_1,byte param_2);  /* 0x0300cfd8 76B */
void ui_group_flag_set_and_notify(byte param_1,byte param_2);  /* 0x0300d064 40B */
void ui_mode_reset(void);  /* 0x0300d0cc 30B */
void ui_mode_set1(void);  /* 0x0300d0ea 38B */
void ui_mode_set2(void);  /* 0x0300d110 38B */
void ui_mode_set4(void);  /* 0x0300d136 16B */
void ui_mode_toggle_5_or_reset(void);  /* 0x0300d146 64B */
void ui_mode_dispatch_caller_0x20(void);  /* 0x0300d186 8B */
void ui_mode_set8_group2(void);  /* 0x0300d18e 16B */
void ui_mode_reset_group2_conditional(void);  /* 0x0300d19e 156B */
void ui_mode_set6_group4(void);  /* 0x0300d25c 16B */
void ui_mode_reset_group4(void);  /* 0x0300d26c 14B */
void sram_16000000_block_write(int param_1,undefined1 *param_2,short param_3);  /* 0x0300d3ec 48B */
void iram_memcpy_at_fixed_offset(int param_1,undefined4 param_2,undefined2 param_3);  /* 0x0300d47c 14B */
void rf_chip_init_and_spawn_worker_tasks(void);  /* 0x0300d4b0 152B */
void unresolved_callee_pair_wrapper(void);  /* 0x0300d828 14B */
void config_table_entry_0x30_init_sequence(void);  /* 0x0300d838 20B */
void freq_calibration_apply_all(void);  /* 0x0300db48 310B */
void rf_tx_flag_wait_then_unkey_loop(void);  /* 0x0300dce4 56B */
void rf_mode_config_entry_0x51_apply(char param_1);  /* 0x0300dd1c 120B */
void vfo_display_config_apply(void);  /* 0x0300dd94 88B */
void channel_change_apply_squelch(void);  /* 0x0300df08 62B */
void int_to_double_divide_convert(undefined2 param_1);  /* 0x0300df5c 32B */
void config_entry_0x71_0x72_and_gain_apply();  /* 0x0300df7c 36B */
void tx_power_mode_apply_from_flags();  /* 0x0300dfa0 56B */
void rf_channel_mode_select_and_apply(void);  /* 0x0300e218 134B */
void ptt_preamble_end_ui_audio_setup_1(void);  /* 0x0300e2c0 160B */
void tx_abort_reset(void);  /* 0x0300e360 84B */
undefined2 tone_signaling_type_classify(ushort param_1);  /* 0x0300e3b4 50B */
void hw_status_debounce_and_alarm_poll(void);  /* 0x0300e530 266B */
void config_table_entry_0x7d_indexed(uint param_1);  /* 0x0300e668 34B */
void fd6818b_mode_register_table_apply(char param_1);  /* 0x0300e6e4 174B */
void param_set_bit_0x2000(ushort param_1);  /* 0x0300e7ec 14B */
void fd6818b_write_cdcss_code_reg08(ushort param_1,undefined2 param_2);  /* 0x0300e7fc 24B */
void config_table_entry_0x51_clear(void);  /* 0x0300e814 12B */
void fd6818_reg31_clear_bit1(void);  /* 0x0300e824 24B */
void fd6818_reg31_set_bit3(void);  /* 0x0300e83c 22B */
void fd6818_reg31_clear_bit3(void);  /* 0x0300e854 24B */
void rf_setup_fd6818_regs_47_7e(void);  /* 0x0300e86c 24B */
void config_table_init_entries_0300e884(void);  /* 0x0300e884 24B */
void config_table_entry_0300e8b0(void);  /* 0x0300e8b0 12B */
void config_table_entry_0300e8bc(void);  /* 0x0300e8bc 12B */
void config_table_entry_0300e8c8(void);  /* 0x0300e8c8 12B */
void config_table_entry_0300e8d4(void);  /* 0x0300e8d4 12B */
void config_table_entry_0300e8e0(void);  /* 0x0300e8e0 12B */
void config_table_init_group1(void);  /* 0x0300e8ec 42B */
void config_table_entry_0x30(void);  /* 0x0300e918 12B */
void config_table_init_entries_0300e924(void);  /* 0x0300e924 22B */
void fd6818b_reg_write_arg37h_1d0fh(void);  /* 0x0300e93c 14B */
void rf_band_mode_clear_regs(char param_1,char param_2,uint param_3);  /* 0x0300e94c 28B */
void fd6818b_preset_write_0xf50b(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e96c 8B */
void fd6818b_preset_write_0xdf22(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e974 8B */
void fd6818b_preset_write_0xd42d(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e97c 8B */
void fd6818b_preset_write_0xcc35(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e984 8B */
void fd6818b_preset_write_0xfa02(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e98c 8B */
void fd6818b_preset_write_0x9009(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e9a4 10B */
void fd6818b_preset_write_0x8f46(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e9ae 10B */
void fd6818b_preset_write_0x8ed8(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e9b8 10B */
void fd6818b_preset_write_0x8d8f(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e9c2 10B */
void fd6818b_preset_write_0x91c1(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e9cc 10B */
void fd6818b_preset_write_0x920b(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e9d6 10B */
void fd6818b_preset_write_0x935a(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e9e0 10B */
void fd6818b_preset_write_0xe61c(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e9f0 8B */
void fd6818b_preset_write_0x8f90(int param_1,undefined4 param_2,undefined4 param_3,int param_4);  /* 0x0300e9f8 80B */
void indexed_callback_dispatch_lt6(uint param_1);  /* 0x0300ea48 16B */
void rf_fd6818b_page0_cfg_r41_81c1_a(void);  /* 0x0300ea5c 52B */
void rf_fd6818b_page0_cfg_r41_81c2(void);  /* 0x0300ea90 52B */
void rf_fd6818b_page0_cfg_r41_81c1_b(void);  /* 0x0300eac4 52B */
void rf_fd6818b_page0_preset_3b_3c(void);  /* 0x0300eaf8 22B */
void rf_fd6818b_page0_cfg_r41_81c5(void);  /* 0x0300eb0e 50B */
uint reg_0xc_bit1_read(void);  /* 0x0300eb44 14B */
uint hw_status_bit10_read(void);  /* 0x0300eb54 14B */
uint hw_status_bit14_read(void);  /* 0x0300eb74 14B */
uint fd6818_page0_reg0c_bit2_get(void);  /* 0x0300eb84 14B */
uint fd6818_reg64h_read_masked(void);  /* 0x0300eb94 28B */
uint reg_0x67_lower9_read(void);  /* 0x0300ebb0 14B */
uint fd6818_page0_reg65_low7_get(void);  /* 0x0300ebc0 14B */
undefined1 fd6818_page0_reg63_get(void);  /* 0x0300ebd0 12B */
void fd6818b_reg33_indexed_bit_set_and_dispatch(uint param_1,undefined4 param_2,byte param_3);  /* 0x0300ebdc 50B */
void fd6818_p0_r35_set_bits11_8(void);  /* 0x0300ec14 24B */
void fd6818_p0_r35_set_bits7_4(void);  /* 0x0300ec2c 24B */
void fd6818_page0_reg35_nibble_update(void);  /* 0x0300ec44 22B */
void fd6818_p0_r34_set_bits15_12(void);  /* 0x0300ec5a 24B */
void fd6818_p0_r34_set_bits11_8(void);  /* 0x0300ec72 24B */
void fd6818_p0_r34_set_bits7_4(void);  /* 0x0300ec8a 24B */
void fd6818_page0_reg34_nibble_update(void);  /* 0x0300eca2 22B */
bool fd6818_set_reg33_bit_test_reg0a(uint param_1);  /* 0x0300eddc 50B */
void rf_fd6818b_page0_init(ushort param_1);  /* 0x0300efd0 80B */
void config_table_init_entries_0300f03c(void);  /* 0x0300f03c 20B */
void config_table_init_entries_0300f050(void);  /* 0x0300f050 20B */
void config_table_init_entries_0x21_0x24(void);  /* 0x0300f10c 24B */
void config_table_entry_0x24(void);  /* 0x0300f124 12B */
void config_table_init_group1_variant_0300f130(void);  /* 0x0300f130 42B */
void config_table_entry_0300f15c(void);  /* 0x0300f15c 14B */
void config_table_init_group1_variant_0300f16c(void);  /* 0x0300f16c 44B */
void config_table_init_entries_and_param_2b(void);  /* 0x0300f198 26B */
void tx_bandwidth_deviation_mode_set(char param_1,char param_2);  /* 0x0300f1b4 150B */
undefined4 vfo_display_state_nibble_bits_check(void);  /* 0x0300f2a4 40B */
void config_table_init_entries_0300f2cc(void);  /* 0x0300f2cc 24B */
void config_table_entry_0300f2e4(void);  /* 0x0300f2e4 12B */
void flash_page_tag_write(undefined2 param_1,undefined1 param_2);  /* 0x0300f2fc 26B */
void flash_page_invalidate_range(void);  /* 0x0300f318 52B */
void flash_page_invalidate_range_locked(void);  /* 0x0300f34c 24B */
int flash_block_id_resolve(byte block_id);  /* 0x0300f364 108B */
void hw_reg_snapshot_shift12_then_flash_scan(void);  /* 0x0300f4fc 46B */
uint flash_page_tag_search(char param_1,char param_2);  /* 0x0300f52c 104B */
uint flash_block_id_resolve_helper1(void);  /* 0x0300f5b4 110B */
uint flash_block_id_resolve_helper2(char param_1);  /* 0x0300f6c0 62B */
void flash_mutex_guarded_op();  /* 0x0300f700 28B */
void mutex_guarded_param_dispatch_1();  /* 0x0300f7ac 48B */
undefined4 flash_program_linear_addr_locked(uint param_1,int param_2,uint param_3);  /* 0x0300f7dc 96B */
void flash_read_mutex_guarded();  /* 0x0300f848 42B */
uint flash_tagged_record_bitlength_scan(void);  /* 0x030104b0 168B */
void mutex_guarded_param_dispatch_2(undefined2 param_1,undefined2 param_2,short param_3);  /* 0x03010680 52B */
void mutex_guarded_param_dispatch_3();  /* 0x03010818 46B */
undefined2 flash_page_indexed_2byte_read(undefined2 param_1,uint param_2);  /* 0x03010904 50B */
ushort flash_page_trailing_count_read();  /* 0x03010938 50B */
void flash_dual_range_invalidate(void);  /* 0x03010b40 148B */
uint flash_state_and_tag_dispatcher(char param_1);  /* 0x03010bd4 258B */
short recording_count_scan(void);  /* 0x03010cf8 190B */
void mutex_guarded_call3_wrapper(undefined4 param_1,undefined4 param_2,undefined2 param_3);  /* 0x03010db8 36B */
undefined * table_index_ptr_0x6c_byte(uint param_1);  /* 0x03010e0c 12B */
undefined * table_index_ptr_0xe_byte(uint param_1);  /* 0x03010e18 12B */
int gb2312_glyph_index_lookup2(byte *gb_code);  /* 0x03010e24 36B */
int gb2312_glyph_index_lookup1(byte *gb_code);  /* 0x03010e48 36B */
undefined4 gb2312_glyph_flash_offset_read();  /* 0x03010ec4 126B */
void bit_matrix_column_transpose_pack(byte *param_1,int param_2,uint param_3);  /* 0x03010f44 136B */
uint dbyte_code_range_table_lookup(uint param_1,uint param_2);  /* 0x030110b8 768B */
void format_computed_ratio_as_string();  /* 0x030114d4 32B */
void channel_record_load_from_block4(uint param_1);  /* 0x0301163c 142B */
void gps_power_set(char param_1);  /* 0x030116cc 122B */
void line_buffer_pump_loop(void);  /* 0x03011824 56B */
void uart_tx_string_with_trailer(char *param_1);  /* 0x030119f4 76B */
void channel_name_copy_under_sem_select(void);  /* 0x03011a40 98B */
void gps_datetime_format(char param_1,char *param_2,byte *param_3,undefined4 param_4);  /* 0x03011b40 466B */
void radio_telemetry_format_dispatch(char param_1,char *param_2);  /* 0x03011d24 688B */
void list_display_with_strlen_format(void);  /* 0x03011ff0 200B */
void menu_list_scroll_retreat_and_redraw(void);  /* 0x030120d8 668B */
void menu_list_scroll_advance_and_redraw(void);  /* 0x03012390 662B */
byte keypad_read_pin_0x32_active_low(void);  /* 0x0301305c 14B */
void keypad_debounced_input_poll_a(void);  /* 0x0301306c 98B */
byte keypad_read_pin_0x31_active_low(void);  /* 0x030130d0 14B */
void keypad_debounced_input_poll_b(void);  /* 0x030130e0 100B */
void write_field_and_mbox_post(uint field,uint value);  /* 0x03013178 68B */
void tx_gate_write_call_record();  /* 0x030134c4 124B */
void event_record_guarded_by_state_flags(void);  /* 0x03013568 112B */
undefined1 keypad_scan_and_map_pressed_key(void);  /* 0x03013660 226B */
void keypad_poll_and_dispatch_key_event(void);  /* 0x03013744 540B */
void keypad_event_maybe_forward_to_dialog(void);  /* 0x030139c0 122B */
void main_ui_background_task_loop(void);  /* 0x03013a3c 1184B */
undefined4 keypad_key_allowed_by_bitmask_a(char param_1);  /* 0x03014060 48B */
undefined4 keypad_key_allowed_check_bel_or_hash(char param_1);  /* 0x030140a8 34B */
byte keypad_key_allowed_check_hash_or_enq_mode_dependent(char param_1);  /* 0x030140cc 94B */
undefined4 keypad_key_allowed_by_bitmask_mode_dependent(char param_1);  /* 0x0301412c 108B */
int poll_condition_group(uint group);  /* 0x030141e0 46B */
void scan_entry_get_mode_bits_fwd_thunk(undefined1 param_1);  /* 0x03014210 10B */
void call_inactive_post_event_0x17(void);  /* 0x0301422c 24B */
void conditional_mbox_post_0x12(void);  /* 0x0301425c 24B */
void write_field_and_mbox_post_arg2h_2h(void);  /* 0x03014274 12B */
void write_field_and_mbox_post_arg2h_1h(void);  /* 0x03014280 12B */
void menu_history_step_or_mbox_post(void);  /* 0x0301428c 72B */
void tx_inactive_mbox_post_0x13(void);  /* 0x030142d4 56B */
void tx_inactive_mbox_post_0x12(void);  /* 0x0301430c 56B */
void tx_state_poll_and_teardown(void);  /* 0x03014360 68B */
void tx_teardown_guard_a(void);  /* 0x030143a4 36B */
void tx_teardown_guard_b(void);  /* 0x030143c8 36B */
void tx_teardown_guard_c(void);  /* 0x030143ec 36B */
void tx_teardown_guard_d(void);  /* 0x03014410 36B */
void keypad_tmrkey_gated_dispatch_a(void);  /* 0x03014434 122B */
void keypad_tmrkey_gated_dispatch_b(void);  /* 0x030144d0 122B */
void tx_teardown_check_and_tmrkey_dispatch(void);  /* 0x0301454c 54B */
void keypad_gate_dispatch_mask01(void);  /* 0x03014584 110B */
void keypad_gate_dispatch_mask04(void);  /* 0x03014610 114B */
void keypad_gate_dispatch_mask02(void);  /* 0x03014684 114B */
void keypad_key_event_post_0x16(void);  /* 0x03014748 118B */
void keypad_key_event_post_0x15(void);  /* 0x030147c0 118B */
void dialog_idle_gate_post_key_0x1f(void);  /* 0x03014838 128B */
void dialog_idle_gate_post_key_0x1d(void);  /* 0x030148d8 146B */
void keypad_key_event_post_0x1e(void);  /* 0x0301496c 118B */
void keypad_tmrkey_expiry_dispatch(void);  /* 0x03014a54 74B */
void dialog_history_advance_or_tx_gate(void);  /* 0x03014aa0 68B */
void call_setup_mode_flag_dispatch(void);  /* 0x03014d34 110B */
void write_field2_and_mbox_post_arg11h_eh(void);  /* 0x03014db0 12B */
void write_field2_and_mbox_post_arg10h_dh(void);  /* 0x03014dbc 12B */
void write_field2_and_mbox_post_argfh_ch(void);  /* 0x03014dc8 12B */
void write_field2_and_mbox_post_argeh_bh(void);  /* 0x03014dd4 12B */
void write_field2_and_mbox_post_argdh_ah(void);  /* 0x03014de0 12B */
void write_field2_and_mbox_post_argch_9h(void);  /* 0x03014dec 12B */
void write_field2_and_mbox_post_argbh_8h(void);  /* 0x03014df8 12B */
void write_field2_and_mbox_post_argah_7h(void);  /* 0x03014e04 12B */
void write_field2_and_mbox_post_arg9h_6h(void);  /* 0x03014e10 12B */
void write_field2_and_mbox_post_arg8h_5h(void);  /* 0x03014e1c 12B */
void tx_teardown_reset_if_flags_5_6_set_arg11h(void);  /* 0x03014e4c 10B */
void tx_teardown_reset_if_flags_5_6_set_arg10h(void);  /* 0x03014e68 10B */
void tx_teardown_reset_if_flags_5_6_set_argfh(void);  /* 0x03014e74 10B */
void tx_teardown_reset_if_flags_5_6_set_argeh(void);  /* 0x03014e80 10B */
void tx_teardown_reset_if_flags_5_6_set_argdh(void);  /* 0x03014e8c 10B */
void tx_teardown_reset_if_flags_5_6_set_argch(void);  /* 0x03014e98 10B */
void tx_teardown_reset_if_flags_5_6_set_argbh(void);  /* 0x03014ea4 10B */
void tx_teardown_reset_if_flags_5_6_set_argah(void);  /* 0x03014eb0 10B */
void tx_teardown_reset_if_flags_5_6_set_arg9h(void);  /* 0x03014ebc 10B */
void tx_teardown_reset_if_flags_5_6_set_arg8h(void);  /* 0x03014ec8 10B */
void request_display_refresh(byte param_1);  /* 0x03014ed4 20B */
void display_pending_refresh_check(void);  /* 0x03014ee8 76B */
void vfo_freq_display_refresh(void);  /* 0x03015050 602B */
void ui_event_notify_code21_entry_a(void);  /* 0x03015610 10B */
void ui_event_notify_code21_entry_b(void);  /* 0x0301561c 10B */
void ui_event_notify_code21_entry_c(void);  /* 0x03015628 10B */
void ui_event_notify_code21_entry_d(void);  /* 0x03015634 10B */
void ui_event_notify_code21_entry_e(void);  /* 0x03015640 10B */
void ui_event_0x21_conditional_notify(void);  /* 0x0301564c 44B */
void dialog_history_step_or_exit_to_idle(void);  /* 0x03015678 124B */
void codeplug_defaults_or_field_post(void);  /* 0x030156f4 32B */
void gps_refresh_gated_by_tx_state(void);  /* 0x03015824 154B */
void screen_subtype_enter_on_flash_flag(void);  /* 0x030158c0 140B */
void ui_key_commit_gate_mode0b(void);  /* 0x03015988 128B */
void ui_key_commit_gate_mode0b_variant2(void);  /* 0x03015a08 108B */
void vfo_key_cursor_back(void);  /* 0x03015a74 66B */
void poll_and_conditional_mode_transition(void);  /* 0x03015ad8 74B */
void poll_condition_group_and_schedule_ui_tick(void);  /* 0x03015b24 138B */
void tx_abort_check_and_report(void);  /* 0x03015cc8 66B */
void scan_mode9_poll_toggle_vfo_bit4(void);  /* 0x03015de0 124B */
void vfo_scan_add_toggle_on_poll_change(void);  /* 0x030161fc 132B */
void settings_slot4_tristate_cycle(void);  /* 0x03016350 130B */
void tx_timeout_tick_and_status_refresh(void);  /* 0x030163d4 72B */
void fm_radio_seek_up_gated_handler(void);  /* 0x0301641c 132B */
void fm_radio_power_toggle(void);  /* 0x030164b8 124B */
void dialog_pending_commit_and_post(void);  /* 0x030168c0 102B */
void scan_list_timer_create_and_flash_load(void);  /* 0x03016d20 40B */
void keypad_tmrkey_state_dispatch(void);  /* 0x03016d64 254B */
undefined1 get_state_field_03016e98(void);  /* 0x03016e98 6B */
void ui_key_commit_gate_mode1e(void);  /* 0x03016ea4 108B */
void call_setup_control_char_and_reset_arg1h(void);  /* 0x03016f10 10B */
void forward_to_FUN_0305dd94(undefined1 param_1);  /* 0x03016f1c 10B */
void call_setup_reset_or_forward(void);  /* 0x03016f28 30B */
void scan_list_activation_commit(char param_1);  /* 0x03016f4c 182B */
void scan_list_activation_commit_arg1h(void);  /* 0x03017028 10B */
void scan_list_activation_commit_arg0h(void);  /* 0x03017034 10B */
undefined4 tx_disable_mode_gate_check(char param_1);  /* 0x03017040 156B */
void tx_settings_field_gate_and_validate(undefined1 param_1);  /* 0x030170ec 146B */
void tx_settings_field_gate_and_validate_arg4h(void);  /* 0x030171a8 10B */
void tx_settings_field_gate_and_validate_arg3h(void);  /* 0x030171b4 10B */
void tx_settings_field_gate_and_validate_arg2h(void);  /* 0x030171c0 10B */
void tx_settings_field_gate_and_validate_arg1h(void);  /* 0x030171cc 10B */
void tx_settings_field_gate_and_validate_arg0h(void);  /* 0x030171d8 10B */
void zone_up_down_toggle_handler_arg1h(void);  /* 0x030172ac 10B */
void zone_up_down_toggle_handler_arg0h(void);  /* 0x030172b8 10B */
void zone_up_down_toggle_handler_arg2h(void);  /* 0x030172c4 10B */
void channel_scroll_with_wraparound(char param_1);  /* 0x030172e0 246B */
void channel_step_forward_or_notify_0x21(void);  /* 0x030173d8 32B */
void channel_step_back_or_notify_0x21(void);  /* 0x03017414 32B */
void refresh_display_or_call_03015ad8(int param_1);  /* 0x0301743c 20B */
void refresh_display_or_call_03015b24(int param_1);  /* 0x03017450 20B */
void ui_notify_event_0x2d_gated(void);  /* 0x03017464 42B */
void dtmf_key_poll_tick(void);  /* 0x03017494 158B */
void radio_mode_ui_tick(void);  /* 0x030175c8 142B */
void lcd_write_command_arg28h(void);  /* 0x03017918 10B */
void lcd_write_command_arg29h(void);  /* 0x03017924 10B */
void lcd_sleep_in_and_wait(void);  /* 0x03017930 16B */
void lcd_sleep_out_and_wait(void);  /* 0x03017940 16B */
void display_set_cursor_pos(uint param_1,ushort param_2);  /* 0x03017978 44B */
void draw_line_bresenham(uint param_1,uint param_2,uint param_3,uint param_4,undefined2 param_5);  /* 0x03017a50 174B */
void display_clear_fullscreen(void);  /* 0x03017d40 10B */
void display_blit_rect_from_buffer(uint param_1,uint param_2,uint param_3,uint param_4,int param_5);  /* 0x03017f9c 142B */
void blit_bitmap_8x8_two_blocks(short param_1,short param_2,int param_3,undefined2 param_4);  /* 0x03018128 166B */
void display_blit_glyph_6x8(short param_1,short param_2,int param_3,undefined2 param_4,undefined2 param_5);  /* 0x03018278 92B */
void display_blit_mono_bitmap_rows(short param_1,uint param_2,uint param_3,ushort param_4,ushort *param_5, undefined2 param_6,undefined2 param_7);  /* 0x0301847c 158B */
void blit_bitmap_8x16_two_blocks(short param_1,short param_2,int param_3,undefined2 param_4);  /* 0x0301855c 166B */
void display_blit_bitmap_16x16_1bpp(short param_1,short param_2,int param_3,undefined2 param_4,undefined2 param_5);  /* 0x03018604 168B */
void display_draw_glyph_gb2312(short param_1,short param_2,byte *param_3,undefined2 param_4,undefined2 param_5);  /* 0x030186ac 158B */
void display_draw_glyph_ascii(ushort param_1,uint param_2,int param_3,uint param_4,undefined2 param_5, undefined2 param_6);  /* 0x0301874c 170B */
undefined4 display_draw_formatted_right_aligned(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4, undefined4 param_5);  /* 0x03018b08 84B */
undefined4 display_draw_formatted_number_centered(short param_1,ushort param_2,ushort param_3,undefined4 param_4,undefined4 param_5);  /* 0x03018bbc 88B */
void display_draw_list_row(uint param_1,byte *param_2,char param_3);  /* 0x03018cd8 116B */
void blit_bitmap_with_mutex();  /* 0x03018d4c 124B */
void display_update_tone_signaling_icon(char param_1);  /* 0x030195d8 166B */
void display_blit_packed_bitmap_row_constch_ch_fwd(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4, undefined2 param_5);  /* 0x03019844 34B */
void format_and_plot_number_with_decimals(undefined4 param_1,short param_2,short param_3,undefined2 param_4,undefined2 param_5 ,uint param_6);  /* 0x03019868 154B */
void display_clear_status_row(short param_1,ushort param_2);  /* 0x03019b28 50B */
void display_fill_main_panel(void);  /* 0x03019ba8 62B */
void display_draw_dialog_panel(void);  /* 0x03019be8 26B */
void display_clear_body_and_underline(void);  /* 0x03019c04 44B */
void clear_screen_color0(void);  /* 0x03019c30 10B */
void dialog_header_draw_two_lines(void);  /* 0x03019c3c 94B */
void display_draw_string_from_table(ushort param_1);  /* 0x03019cc8 44B */
undefined4 format_number_and_draw_display();  /* 0x03019fc4 46B */
void draw_string_mixed_charset(short param_1,ushort param_2,byte *param_3,ushort param_4,undefined2 param_5, undefined2 param_6);  /* 0x0301a2b4 194B */
void display_draw_dialog_panel_variant_0301a378(void);  /* 0x0301a378 24B */
void display_status_corner_clear_when_idle(void);  /* 0x0301a3d4 44B */
void conditional_tone_dispatch_by_mode(void);  /* 0x0301a400 142B */
void vfo_active_side_icon_draw(char param_1);  /* 0x0301ab54 82B */
void dialog_show_icon_and_two_numbers();  /* 0x0301aba8 74B */
void bandwidth_deviation_threshold_store(undefined4 param_1,undefined4 *param_2);  /* 0x0301af44 4B */
int linear_interpolate_freq_calibration(int param_1,int param_2,uint param_3,int param_4,uint param_5);  /* 0x0301b000 118B */
undefined1 frequency_range_clamp_and_dispatch(uint param_1);  /* 0x0301b078 184B */
char channel_step_frequency_bound_check(uint param_1,uint param_2,int param_3);  /* 0x0301b214 518B */
undefined1 freq_calibration_interpolate_selected(uint param_1,char param_2);  /* 0x0301b424 308B */
undefined1 freq_cal_interp_mode_select(undefined4 param_1);  /* 0x0301b5a4 78B */
undefined1 calibration_table_interp_block2(undefined4 param_1);  /* 0x0301b5f4 102B */
undefined1 flash_field_read_signed_select(undefined4 param_1,ushort param_2);  /* 0x0301b65c 68B */
void radio_boot_gpio_preinit(void);  /* 0x0301b818 22B */
void iram_call_0002c588_arg0x10(void);  /* 0x0301b830 10B */
void upgrade_mode_enter_and_reset_task(void);  /* 0x0301b83c 280B */
void ucos3_task_create_prio5_stk0x80(void);  /* 0x0301b954 60B */
void ui_flag_post_0x40000_if_check(void);  /* 0x0301b990 22B */
void tick_counter_and_event_log(void);  /* 0x0301b9dc 88B */
void rssi_meter_level_update_and_fault_reset(uint param_1);  /* 0x0301bb44 334B */
void battery_monitor_adc_tick(void);  /* 0x0301bcb0 64B */
void map_index_to_16bit_value(byte param_1);  /* 0x0301bd30 76B */
void fd6818_reg7e_set_flag_bit15(uint param_1);  /* 0x0301bf94 56B */
void zero_fields_by_index_pair(uint param_1);  /* 0x0301bfdc 26B */
void rf_agc_step_adaptive_control_loop(uint param_1);  /* 0x0301bff8 374B */
undefined4 sysctrl_diplex0_bit17_clear_init(void);  /* 0x0301c1a4 24B */
void config_param_cap_and_dispatch();  /* 0x0301c294 34B */
void device_reg_write_selector_0xe0(undefined1 param_1,undefined1 param_2);  /* 0x0301c2b8 26B */
void rtc_reg_0x11_set_bit1(void);  /* 0x0301c454 22B */
void rtc_reg11_clear_bit1(void);  /* 0x0301c46c 20B */
void rtc_reg17_pulse_low_25ms(void);  /* 0x0301c5ec 26B */
uint day_of_week_calculate(undefined4 param_1,uint param_2);  /* 0x0301c780 112B */
undefined4 spi_m3_efuse_init_and_read8();  /* 0x0301ca08 60B */
void flash_cache_sector_modify_and_writeback(int param_1,int param_2,uint param_3);  /* 0x0301ca44 132B */
void modem_sem_create_and_gpio_0x18_high(void);  /* 0x0301cc18 20B */
void dac_boot_init_and_sem_create(void);  /* 0x0301cc30 52B */
void ui_inactivity_timeout_tick(void);  /* 0x0301cc68 1088B */
void irq_boot_register_handlers_3b_to_41(void);  /* 0x0301d128 60B */
void gpio_pin_set_output_level(uint param_1,int param_2);  /* 0x0301d184 240B */
void gpio_interrupt_enable_bit(uint param_1);  /* 0x0301d4c8 68B */
void board_gpio_defaults_and_encoder_irq_arm(void);  /* 0x0301d50c 208B */
void boot_drive_pin_0x35_low(void);  /* 0x0301d6c0 12B */
void audio_pa_enable_gate();  /* 0x0301d6cc 96B */
void gpio_clear_bit0(void);  /* 0x0301d830 12B */
void set_flag_byte_03064328_variant_0301d858();  /* 0x0301d858 6B */
void mmio_14000000_timer_config(int param_1);  /* 0x0301d900 32B */
void timer_channel_enable_dispatch_arg5h(void);  /* 0x0301d958 10B */
undefined4 call_setup_step_ready_gate(char param_1,char param_2,undefined1 *param_3);  /* 0x0301dfb4 120B */
void mmio_11000074_bits_7_8_set_clear(int param_1);  /* 0x0301e578 32B */
void mmio_11000088_bool_set(int param_1);  /* 0x0301e5bc 28B */
void modem_buffer_indexed_byte_write_0301e5d8(byte param_1);  /* 0x0301e5d8 34B */
void modem_rf_mode_transition_apply(char param_1,char param_2,char param_3);  /* 0x0301e628 462B */
void set_call_setup_field_0xac(undefined4 param_1);  /* 0x0301e848 8B */
void write_single_byte_0301ea5c(byte param_1);  /* 0x0301e8d4 8B */
void call_setup_full_reset_with_clock(void);  /* 0x0301e910 26B */
void radio_reset_sequence_with_clock_reset(void);  /* 0x0301e92c 26B */
byte get_field_0301ea64_0x14(void);  /* 0x0301e948 6B */
void radio_mode_dispatcher_char();  /* 0x0301e950 122B */
void dialog_request_enqueue(uint request_id,void *arg);  /* 0x0301eb70 32B */
undefined4 dialog_state_get_field_0301ecbc(void);  /* 0x0301ecbc 6B */
void dialog_state_set_bit_0301ecc4(byte param_1);  /* 0x0301ecc4 12B */
void dialog_state_set_bit_0301ecd0();  /* 0x0301ecd0 12B */
void dialog_state_set_bit_0301ecdc(byte param_1);  /* 0x0301ecdc 12B */
void sysctl_0x384_bit8_toggle_with_companion_byte();  /* 0x0301ece8 58B */
byte read_field_0x18_bit4(void);  /* 0x0301ed24 10B */
void dialog_state_set_bit_0301ed30(byte param_1);  /* 0x0301ed30 12B */
void dialog_state_set_bit_0301ed3c(byte param_1);  /* 0x0301ed3c 12B */
void write_field_0x18_bit7(char param_1);  /* 0x0301ed48 12B */
void write_byte_field_0301ed54(byte param_1);  /* 0x0301ed54 6B */
void modem_set_digital_mode_enable(byte param_1);  /* 0x0301ed68 46B */
void write_two_bit_flags_0301eef8(byte param_1,byte param_2);  /* 0x0301ed98 16B */
byte read_bytes_0xe_0xf_or(void);  /* 0x0301edd8 12B */
void encode_name_tag_field(int param_1);  /* 0x0301ef14 264B */
void dialog_clear_flag_bit2_at_1_variant_0301f01c(void);  /* 0x0301f01c 18B */
void stack_buffer_triple_call_helper(void);  /* 0x0301f040 36B */
void dmr_privacy_custom_key_delta_encode(void);  /* 0x0301f064 14B */
void config_struct_write_with_flag_post(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4);  /* 0x0301f170 40B */
void state_reset_clear_flag_0x400(void);  /* 0x0301f198 24B */
void call_setup_task_main_loop(void);  /* 0x0301fe80 78B */
undefined4 call_setup_connect_with_retry(void);  /* 0x0301fed0 332B */
bool table_range_copy_checked_600(int param_1,undefined4 param_2,int param_3);  /* 0x030206ec 30B */
undefined2 mmio_read_16bit_offset_14(void);  /* 0x0302070c 6B */
undefined4 dialog_state_get_field_03020724(void);  /* 0x03020724 6B */
void dmr_config_callback_variant_dispatcher();  /* 0x0302072c 28B */
undefined1 get_state_field_03020748(void);  /* 0x03020748 6B */
undefined4 dialog_state_get_field_03020df8(void);  /* 0x03020df8 6B */
undefined4 radio_mode_classify_from_status_bytes(void);  /* 0x03020e00 40B */
undefined4 dialog_state_get_field_03020e28(void);  /* 0x03020e28 6B */
undefined1 read_byte_field_03020e30(void);  /* 0x03020e30 6B */
void history_mode_entry_init(void);  /* 0x03020e40 46B */
bool stored_config_fields_differ(char param_1,int param_2,int param_3);  /* 0x03021064 38B */
undefined4 dialog_state_get_field_0302128c(void);  /* 0x0302128c 6B */
undefined4 config_status_from_bytes_1_2(void);  /* 0x03021294 40B */
void set_single_bit_field_0x3(byte param_1);  /* 0x030212c8 12B */
void write_byte_field_030212dc();  /* 0x030212dc 6B */
void write_byte_field_030212e4(undefined1 param_1);  /* 0x030212e4 6B */
void dialog_state_set_substate(byte param_1);  /* 0x030215f4 60B */
void dialog_state_set_flag_0xc();  /* 0x03021630 6B */
undefined4 dialog_state_get_field_0x8(void);  /* 0x03021638 6B */
void dialog_state_set_2bit_at_1();  /* 0x03021640 14B */
void dialog_state_set_bit3_at_1(byte param_1);  /* 0x03021650 14B */
undefined4 dialog_state_get_field_0x10(void);  /* 0x03021660 6B */
void radio_mode_transition_sequencer(byte param_1);  /* 0x03021670 298B */
void radio_mode_reset_to_idle(void);  /* 0x030217b8 30B */
void set_global_upper_16bits(int param_1);  /* 0x030217f0 26B */
void tx_voice_end_stop_tx_record(void);  /* 0x03021850 64B */
void voice_record_arm(void);  /* 0x03021890 74B */
void settings_deferred_flash_commit(void);  /* 0x030218dc 106B */
void subsystem_buffer_reset_and_task_init_0x400(void);  /* 0x03021c5c 70B */
void ui_event_0xf_if_status_flag40(void);  /* 0x03021ccc 26B */
void write_event_record_and_notify(undefined1 param_1,undefined1 param_2);  /* 0x03021ce8 40B */
void tone_synth_mix4_stream();  /* 0x03021d10 300B */
void tone_synth_mix3_stream();  /* 0x03022074 370B */
void tone_synth_silence_stream(ushort param_1);  /* 0x030221f0 50B */
void audio_tone_stream_decode_loop(void);  /* 0x03022224 196B */
void tone_ptt_preamble_seq2(void);  /* 0x030225f4 66B */
void tone_ptt_preamble_seq4(void);  /* 0x03022676 104B */
void tone_ptt_preamble_seq37(void);  /* 0x03022750 42B */
void tone_ptt_preamble_seq6(void);  /* 0x0302277a 32B */
void tone_ptt_preamble_seq7(void);  /* 0x0302279a 32B */
void tone_ptt_preamble_seq10(void);  /* 0x030227f4 28B */
void tone_ptt_preamble_seq12(void);  /* 0x0302282c 30B */
void tone_ptt_preamble_seq14(void);  /* 0x03022866 28B */
void tone_ptt_preamble_seq15(void);  /* 0x03022882 30B */
void tone_ptt_preamble_seq20(void);  /* 0x0302299c 34B */
void tone_ptt_preamble_seq21(void);  /* 0x030229be 26B */
void tone_ptt_preamble_seq22(void);  /* 0x030229d8 100B */
void tone_ptt_preamble_seq23(void);  /* 0x03022a3c 72B */
void tone_ptt_preamble_seq25(void);  /* 0x03022ae8 6B */
void tone_ptt_preamble_seq26(void);  /* 0x03022aee 70B */
void tone_ptt_preamble_seq27(void);  /* 0x03022b34 86B */
void tone_ptt_preamble_seq29(void);  /* 0x03022bf2 30B */
void tone_ptt_preamble_seq30(void);  /* 0x03022c10 72B */
void tone_ptt_preamble_seq31(void);  /* 0x03022c58 46B */
void tone_ptt_preamble_seq33(void);  /* 0x03022cd4 10B */
void tone_ptt_preamble_seq35(void);  /* 0x03022d3a 90B */
void tone_ptt_preamble_seq36(void);  /* 0x03022d94 162B */
void wait_for_status_byte_clear();  /* 0x03022e68 42B */
void dtmf_ptt_event_task_loop(void);  /* 0x03023044 80B */
void tone_or_volume_step_lookup();  /* 0x030230bc 68B */
void display_draw_formatted_number_semicolon_eol(ushort param_1,ushort param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5);  /* 0x030231ee 78B */
void modem_stop(void);  /* 0x03023428 168B */
void dmr_call_state_timeout_check(void);  /* 0x030234d0 130B */
void modem_queue_drain_and_stop(void);  /* 0x0302357c 140B */
bool data_buffer_offset_2_nonzero_check(void);  /* 0x03023840 12B */
void mutex_pend_forever_count_loop(void);  /* 0x03023900 20B */
void dmr_rx_deferred_frame_dispatch(void);  /* 0x03023a68 112B */
byte call_setup_sm_aux_field0xb_is_zero(void);  /* 0x03023b10 10B */
void modem_tx_enable(void);  /* 0x03023b6c 26B */
bool call_setup_sm_field0x72_not_one(void);  /* 0x03023cf0 14B */
char bitmask_nth_set_bit_table_index(byte param_1,char param_2);  /* 0x03023d00 46B */
undefined4 bitmask_table_index_lookup(int param_1,byte param_2,byte *param_3);  /* 0x03023db8 382B */
void call_setup_frame_ack_state_machine(int param_1);  /* 0x03023f4c 466B */
void delta_encode_adjacent_xor();  /* 0x03024138 54B */
void dmr_lc_call_setup_header_build(byte *out_buf,uint target_dmr_id);  /* 0x0302417c 52B */
void dmr_call_config_state_reset_and_arm_timer(void);  /* 0x030241b4 116B */
void dmr_call_history_slot_append_batch(void);  /* 0x030242b8 358B */
void radio_state_reinit_and_120s_timer_start(void);  /* 0x03024434 108B */
void dmr_burst_assemble_and_dispatch(byte param_1,uint param_2);  /* 0x030244ac 158B */
void dmr_burst_freq_field_pack_and_timer_arm(int param_1);  /* 0x030245e0 190B */
void dmr_rx_burst_timer_setup_and_start(void);  /* 0x030246a8 98B */
void protocol_frame_periodic_timer_state_machine(void);  /* 0x03024788 150B */
void dmr_rx_control_state_update_from_status(void);  /* 0x030248fc 44B */
undefined1 circular_gap_classify_u16(uint param_1,uint param_2,uint param_3);  /* 0x03024974 38B */
void dmr_rx_burst_dispatch(int param_1);  /* 0x0302499c 1342B */
uint serial_frame_classify_and_extract_ids(int param_1);  /* 0x030253a0 372B */
undefined4 history_record_push_typed();  /* 0x03025e40 80B */
undefined4 history_record_build_typed_dispatch(char param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5, undefined4 param_6,byte param_7);  /* 0x030265ac 230B */
undefined4 history_slot_alloc_with_data(char *param_1);  /* 0x03026960 144B */
void history_log_type3_packet_builder(undefined1 param_1,char param_2,undefined4 param_3,undefined1 param_4, undefined4 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8, undefined4 param_9,undefined4 param_10,char param_11);  /* 0x030270e4 488B */
bool dmr_call_config_field0x9_not_one(void);  /* 0x03027374 12B */
bool call_active_and_mode_not_2(void);  /* 0x03027380 34B */
uint rx_type_info_read_and_copy(undefined4 param_1);  /* 0x03027400 26B */
void dmr_call_setup_accept_and_signal(void);  /* 0x03027618 72B */
void dmr_call_config_reset(void);  /* 0x03027688 52B */
bool call_setup_target_id_decode_and_check(byte param_1,byte *param_2,uint *param_3,uint *param_4);  /* 0x03027720 1244B */
void call_setup_queue_entry_append_and_dialog_advance(void);  /* 0x03027e80 68B */
void dmr_call_config_slot_store_and_flag_post_0x2000000(void);  /* 0x03027ec4 36B */
void dmr_call_config_slot_store_and_dialog_substate4(void);  /* 0x03027ee8 46B */
void call_setup_queue_entry_append_flag_signal(void);  /* 0x03028044 32B */
void dmr_call_config_slot_store_and_flag_post_0x1000000(void);  /* 0x03028064 50B */
void dmr_state_dependent_table_write(void);  /* 0x0302809e 36B */
void dmr_call_setup_frame_unpack_and_dispatch(void);  /* 0x03028214 290B */
void dmr_call_setup_response_process_and_signal(void);  /* 0x03028338 864B */
void dmr_call_state_machine_step(void);  /* 0x030286d8 1250B */
void dmr_call_setup_accept_entry(void);  /* 0x03028c40 6B */
void dmr_call_setup_response_entry(void);  /* 0x03028c46 6B */
void dmr_call_setup_frame_dispatch_entry(void);  /* 0x03028c4c 6B */
void dmr_call_setup_event_dispatch_entry(void);  /* 0x03028c52 6B */
void config_struct_field_write_entry(void);  /* 0x03028c58 6B */
void serial_9bit_frame_validate_entry(void);  /* 0x03028c5e 6B */
void dmr_call_config_reset_entry(void);  /* 0x03028c64 6B */
void dmr_embedded_lc_superframe_process(void);  /* 0x03028c78 1716B */
void gpio_clear_bit0_if_flag_clear(void);  /* 0x03029420 30B */
void flag_byte_clear_and_gpio_reset(void);  /* 0x03029440 28B */
void slottimer_dmr_slot_state(void);  /* 0x0302945c 88B */
undefined4 * history_slot_allocate(void);  /* 0x030294f8 90B */
void history_slot_link_append();  /* 0x0302955c 176B */
undefined4 history_event_record_build_type0xb8(void);  /* 0x0302996c 40B */
undefined4 history_event_record_build_type0x84(void);  /* 0x03029994 44B */
undefined4 history_event_record_build_type0x85(void);  /* 0x030299c0 48B */
undefined4 history_event_record_build_type0xa0(void);  /* 0x030299f0 44B */
undefined4 history_event_record_build_type0xa6(void);  /* 0x03029a1c 50B */
undefined4 history_event_record_build_type0xbd(void);  /* 0x03029a4e 60B */
undefined4 history_event_record_build_type0xa7(void);  /* 0x03029a8a 44B */
undefined4 history_event_record_build_type0x9f(void);  /* 0x03029ab6 44B */
undefined4 dmr_frame_pack_and_history_record(undefined4 param_1,undefined4 param_2,byte param_3);  /* 0x03029ae2 124B */
undefined4 history_event_record_build_type0x9d(void);  /* 0x03029b5e 42B */
undefined4 history_record_conditional_push_by_type(void);  /* 0x03029b88 68B */
undefined4 history_record_push_type3_repeated(undefined1 param_1,undefined4 param_2,undefined4 param_3,char param_4,char param_5, char param_6);  /* 0x03029bd0 92B */
void history_record_build_type3();  /* 0x03029cd0 24B */
bool dmr_layer2_frame_build_and_send(int param_1);  /* 0x03029d0c 128B */
void history_event_record_build_dispatch(undefined4 param_1,undefined4 param_2);  /* 0x03029dd0 70B */
void history_event_record_build_type0x1f_b(void);  /* 0x03029e24 26B */
void history_event_record_build_type0x1d_b(void);  /* 0x03029e3e 28B */
void history_event_record_build_type0x24_a(void);  /* 0x03029e5a 28B */
void history_event_record_build_type0x24_b(void);  /* 0x03029e76 28B */
void history_event_record_build_type0x24_c(void);  /* 0x03029e92 26B */
void history_event_record_build_type0x27(void);  /* 0x03029eac 44B */
byte max_linked_list_length_of_two(void);  /* 0x03029ee0 64B */
undefined1 table_scaled_clamped_accumulator_step(uint param_1);  /* 0x03029f3c 140B */
void ucos3_task_create_prio11_stk0xc8(void);  /* 0x03029fd8 60B */
uint rx_audio_queue_dequeue_n(uint param_1,uint param_2,int param_3,int *param_4);  /* 0x0302b6fc 278B */
void subsystem_buffer_reset_and_task_init_0x4b0(void);  /* 0x0302b858 70B */
void call_duration_post_flag_0x1000(void);  /* 0x0302b8a0 14B */
void draw_dialog_with_status_and_datetime(void);  /* 0x0302c2e8 158B */
void handle_incoming_call_display(void);  /* 0x0302c510 104B */
void tx_ptt_ui_field_set_on_call_match_gate(void);  /* 0x0302c578 80B */
void dialog_show_icon_and_two_numbers_gb2312(void);  /* 0x0302c948 38B */
void dialog_show_icon_and_two_numbers_gb2312_v2(void);  /* 0x0302c96e 38B */
void build_string_and_show_dialog_icon_two_numbers(void);  /* 0x0302c994 80B */
void build_string_and_show_dialog_icon_two_numbers_v2(void);  /* 0x0302ca34 150B */
void call_dialog_field_progress_and_timeout(void);  /* 0x0302cd4c 292B */
void contact_field_dialog_state_advance(void);  /* 0x0302ced0 180B */
void channel_dialog_commit_flags_update(void);  /* 0x0302d194 48B */
void tx_dialog_state_machine_tick(void);  /* 0x0302d1c4 412B */
void refresh_display_based_on_dialog_flags(void);  /* 0x0302d36c 414B */
void dialog_periodic_tick_state_dispatcher(void);  /* 0x0302d5e4 186B */
void tx_caller_dialog_screen(void);  /* 0x0302d79c 138B */
void dialog_close_and_tx_release(void);  /* 0x0302dc38 724B */
byte read_byte_field_0302e118(void);  /* 0x0302e118 6B */
byte read_byte_field_0302e120(void);  /* 0x0302e120 6B */
void vfo_zone_display_refresh(void);  /* 0x0302e190 54B */
void zone_record_read();  /* 0x0302e1f0 880B */
void scanlist_channel_membership_remove(uint param_1,uint param_2);  /* 0x0302e598 376B */
void vfo_scroll_list_cursor_advance(undefined1 *param_1,undefined1 *param_2);  /* 0x0302e9c0 40B */
void list_cursor_decrement_call1(undefined1 *param_1,undefined1 *param_2);  /* 0x0302e9e8 40B */
void list_cursor_decrement_call2(undefined1 *param_1,undefined1 *param_2);  /* 0x0302ec90 34B */
void dtmf_digit_input_handler();  /* 0x0302ecec 64B */
byte get_current_mode_state1(void);  /* 0x0302ed2c 6B */
void ui_mode_periodic_state_tick(void);  /* 0x0302ee14 1240B */
void dtmf_digit2_input_and_clear_flag();  /* 0x0302f3bc 22B */
bool vfo_freq_display_field0x5c_in_range(void);  /* 0x0302f41c 70B */
byte zone_change_key_handler(int param_1);  /* 0x0302f464 356B */
void draw_dialog_header_and_centered_number(void);  /* 0x0302fa1c 82B */
void subsystem_buffer_reset_and_task_init_0x600(void);  /* 0x03030360 70B */
void commit_channel_record_dual_vfo();  /* 0x030303bc 412B */
void rx_forbid_flag_conditional_clear(void);  /* 0x0303056c 62B */
void read_channel_field_from_flash(undefined1 param_1,int param_2,int param_3);  /* 0x030309c4 64B */
void vfo_standby_frequency_panel_render(char param_1);  /* 0x03030a04 1072B */
void vfo_field_write_2bit_at_8_direct_commit(char param_1);  /* 0x03030f24 150B */
undefined2 uint16_classify_by_sign_and_high_nibble(ushort param_1);  /* 0x03031184 48B */
byte search_table_u16_for_value(char param_1,short param_2);  /* 0x030311b4 80B */
void list_cursor_decrement_conditional(undefined1 *param_1,undefined1 *param_2);  /* 0x03031420 48B */
void ctcss_dcs_row_render_wrapper(undefined1 param_1);  /* 0x03031494 30B */
void * channel_record_load_by_index();  /* 0x0303153c 330B */
void * vfo_record_read();  /* 0x0303169c 340B */
void codeplug_factory_defaults_write(void);  /* 0x03032434 2512B */
void set_flag_bits_and_post_os_flag_0x8000_arg4h(void);  /* 0x030331c4 10B */
void ucos3_tmr_dlyhnd_create_oneshot_10tick(void);  /* 0x030331d0 44B */
void ucos_dlytmr_set_interval_and_delete(int param_1);  /* 0x0303327c 56B */
void ucos_sem_create_03033494(void);  /* 0x030332cc 12B */
ushort get_block0xb_u16_field0(void);  /* 0x030332d8 56B */
void history_record_lookup_by_type(char param_1,ushort param_2,void *param_3);  /* 0x03033380 274B */
void index_1based_to_slot_and_bit(uint param_1,short *param_2,undefined1 *param_3);  /* 0x03033498 46B */
void history_record_detail_screen_draw(undefined2 param_1);  /* 0x030334c8 208B */
uint flash_binary_search_le_record(uint param_1,int param_2);  /* 0x03033598 254B */
void range_count_status_display();  /* 0x03033794 232B */
void tx_status_display_adjust(uint *param_1,int *param_2);  /* 0x030338d4 66B */
void list_string_format_and_draw(void);  /* 0x030339bc 200B */
void menu_list_row_advance_and_render(void);  /* 0x03033a84 656B */
void menu_list_row_advance_and_render_variant2(void);  /* 0x03033d68 650B */
short flash_block_u16_scan_find_index(ushort param_1,ushort param_2);  /* 0x030347d4 94B */
short flash_block_u16_scan_find_index_030349e4(ushort param_1,ushort param_2);  /* 0x030349e4 94B */
undefined4 flash_bitmap_find_free_slot(short *param_1);  /* 0x03034a44 162B */
undefined4 talkgroup_binary_search_by_id_and_flag(uint param_1,undefined2 *param_2,uint param_3,char param_4);  /* 0x03034be4 372B */
undefined2 flash_block11_indexed_u16_read(short param_1);  /* 0x03034df4 36B */
short contact_count_range_calc();  /* 0x03034e18 126B */
void set_flag_byte_03064328_variant_0303501c(undefined1 param_1);  /* 0x0303501c 6B */
undefined1 get_state_field_03035024(void);  /* 0x03035024 6B */
void string_copy_by_param_select();  /* 0x03035054 28B */
void dmr_contact_record_copy(undefined1 *param_1,undefined1 *param_2,undefined1 param_3);  /* 0x03035070 66B */
undefined4 contact_edit_validate_and_save();  /* 0x030355ec 578B */
undefined1 read_byte_field_03035a18(void);  /* 0x03035a18 6B */
void status_message_save_on_confirm(void);  /* 0x03035b44 56B */
void settings_clear_pair_on_read_0xf(void);  /* 0x03035ba0 22B */
void clear_field_flag_if_setting0xf_and_empty(void);  /* 0x03035bb8 28B */
void menu_ok_action_dispatch_mode0x30(void);  /* 0x03035bf0 72B */
void menu_confirm_apply_handler3(void);  /* 0x03035d88 236B */
void subsystem_buffer_reset_and_task_init_0xa00(void);  /* 0x03035e74 62B */
void subsystem_sem_create_and_buffer_init_0xa00(void);  /* 0x03035eb4 16B */
void write_status_mode_byte_pair();  /* 0x03035ec4 16B */
void write_status_mode_byte_pair_screen_code7ch(void);  /* 0x03035f1c 12B */
void write_status_mode_byte_pair_screen_code7bh(void);  /* 0x03035f28 12B */
void write_status_mode_byte_pair_screen_code7ah(void);  /* 0x03035f34 12B */
void write_status_mode_byte_pair_screen_code79h(void);  /* 0x03035f40 12B */
void text_entry_key_letter_d(void);  /* 0x03035f4c 62B */
void text_entry_key_letter_c(void);  /* 0x03035f8c 62B */
void write_status_mode_byte_pair_screen_code75h(void);  /* 0x03035fcc 12B */
void write_status_mode_byte_pair_screen_code74h(void);  /* 0x03035fd8 12B */
void text_entry_key_letter_b(void);  /* 0x03035fe4 62B */
void keypad_key_a_handler(void);  /* 0x03036024 62B */
void tx_gate_write_call_record_screen_code6fh(void);  /* 0x03036064 18B */
void tx_gate_write_call_record_screen_code6eh(void);  /* 0x03036078 18B */
void write_status_mode_byte_pair_arg69h_0h(void);  /* 0x0303608c 12B */
void tx_gate_write_call_record_screen_code6ch(void);  /* 0x030360a0 18B */
void tx_gate_write_call_record_screen_code6bh(void);  /* 0x030360b4 18B */
void write_status_mode_byte_pair_arg54h_0h(void);  /* 0x030360c8 12B */
void write_status_mode_byte_pair_screen_code55h(void);  /* 0x030360d4 22B */
void write_status_mode_byte_pair_screen_code67h(void);  /* 0x030360ec 22B */
void write_status_mode_byte_pair_screen_code66h(void);  /* 0x03036104 22B */
void write_status_mode_byte_pair_screen_code61h(void);  /* 0x030361c4 22B */
void write_status_mode_byte_pair_screen_code60h(void);  /* 0x030361dc 22B */
void write_status_mode_byte_pair_screen_code5fh(void);  /* 0x030361f4 22B */
void write_status_mode_byte_pair_screen_code52h(void);  /* 0x03036260 12B */
void write_status_mode_byte_pair_screen_code51h(void);  /* 0x0303626c 12B */
void write_status_mode_byte_pair_screen_code50h(void);  /* 0x03036278 12B */
void write_status_mode_byte_pair_screen_code4fh(void);  /* 0x03036284 12B */
void write_status_mode_byte_pair_screen_code4bh(void);  /* 0x03036290 12B */
void write_status_mode_byte_pair_screen_code4ah(void);  /* 0x0303629c 12B */
void menu_history_key_dispatch_or_status(void);  /* 0x030362a8 42B */
void write_status_mode_byte_pair_screen_code44h(void);  /* 0x030362d4 22B */
void write_status_mode_byte_pair_screen_code43h(void);  /* 0x030362ec 22B */
void menu_channel_entry_apply_or_status(void);  /* 0x03036304 42B */
void write_status_mode_byte_pair_screen_code3dh(void);  /* 0x03036330 22B */
void write_status_mode_byte_pair_screen_code3ch(void);  /* 0x03036348 22B */
void menu_state_code_dispatch(void);  /* 0x03036378 72B */
void write_status_mode_byte_pair_screen_code36h(void);  /* 0x030363c0 22B */
void write_status_mode_byte_pair_screen_code35h(void);  /* 0x030363d8 22B */
void write_status_mode_byte_pair_screen_code2fh(void);  /* 0x030363f0 22B */
void write_status_mode_byte_pair_screen_code2eh(void);  /* 0x03036408 22B */
void menu_state_action_dispatch_by_index(void);  /* 0x03036420 112B */
void write_status_mode_byte_pair_screen_code28h(void);  /* 0x03036490 22B */
void write_status_mode_byte_pair_screen_code27h(void);  /* 0x030364b8 22B */
void write_status_mode_byte_pair_screen_code21h(void);  /* 0x030364d0 22B */
void write_status_mode_byte_pair_screen_code20h(void);  /* 0x030364e8 22B */
void write_status_mode_byte_pair_screen_code1ah(void);  /* 0x03036500 22B */
void write_status_mode_byte_pair_screen_code19h(void);  /* 0x03036518 22B */
void write_status_mode_byte_pair_screen_code13h(void);  /* 0x03036530 22B */
void write_status_mode_byte_pair_screen_code12h(void);  /* 0x03036548 22B */
void write_status_mode_byte_pair_argeh_1h(void);  /* 0x03036560 12B */
void write_status_mode_byte_pair_screen_code0ch(void);  /* 0x0303656c 22B */
void write_status_mode_byte_pair_screen_code0bh(void);  /* 0x03036584 22B */
void dialog_history_status_clear_a(void);  /* 0x0303692c 22B */
void dialog_history_status_clear_b(void);  /* 0x03036944 22B */
void dialog_history_flush_and_reset(void);  /* 0x03036a48 40B */
void menu_screen_advance_step_with_scan(void);  /* 0x03036a70 342B */
void history_queue_pop(void);  /* 0x03036c00 166B */
void history_queue_pop_clear_bit0(void);  /* 0x03037008 22B */
void dialog_history_pop_and_state_dispatch(void);  /* 0x03037020 80B */
void tx_stop_and_reset_to_idle(void);  /* 0x03037070 88B */
void history_pop_clear_pending_flags(void);  /* 0x030370c8 72B */
void tx_history_pop_release_a(void);  /* 0x03037378 84B */
void tx_history_pop_release_b(void);  /* 0x030373cc 84B */
void text_entry_pop_and_commit_on_bksp(void);  /* 0x03037420 20B */
void history_queue_pop_thunk(void);  /* 0x03037434 8B */
void history_pop_or_status_flag2(void);  /* 0x0303743c 42B */
void text_entry_enter_backspace_dispatch(void);  /* 0x03037470 322B */
void text_entry_enter_bksp_or_pop_a(void);  /* 0x030375e8 26B */
void text_entry_enter_bksp_or_pop_b(void);  /* 0x03037604 26B */
void text_entry_key_dispatch_or_clear_flags(void);  /* 0x03037620 58B */
void text_entry_enter_bksp_or_pop_c(void);  /* 0x0303767c 26B */
void text_entry_enter_bksp_or_pop_d(void);  /* 0x03037698 26B */
void ui_key_text_entry_or_history_dispatch(void);  /* 0x030376b4 98B */
void diag_rssi_sql_numeric_draw();  /* 0x03037d78 92B */
void screen_enter_apply_channel_and_rf_mode(void);  /* 0x03038058 1148B */
void menu_field_value_display_dispatch(void);  /* 0x03038528 74B */
void display_draw_number1_from_selected_ptr_table(void);  /* 0x0303858c 22B */
void draw_number_centered_menu_field_0x1(void);  /* 0x030385a2 34B */
void menu_field_value_display_dispatch_variant(void);  /* 0x030385c4 28B */
void draw_number_centered_menu_field_0x2(void);  /* 0x030385fa 34B */
void draw_number_centered_menu_variant(void);  /* 0x0303861c 34B */
void draw_number_centered_ptr_0303879c(void);  /* 0x0303863e 34B */
void draw_number_centered_ptr_030387a0(void);  /* 0x03038660 34B */
void draw_number_centered_ptr_030387a4(void);  /* 0x03038682 34B */
void draw_number_centered_ptr_030387a8(void);  /* 0x030386a4 34B */
void draw_number_centered_ptr_030387b0(void);  /* 0x030386e8 34B */
void draw_number_centered_fixed_field(void);  /* 0x0303870a 22B */
void menu_value_ptr_select_multilevel_and_display_variant(void);  /* 0x03038720 500B */
void menu_value_ptr_select_multilevel_and_display(void);  /* 0x03038994 464B */
void draw_number_centered_menu_dispatcher(void);  /* 0x03038b9e 320B */
void menu_index_value_select_and_draw_centered(void);  /* 0x03038d24 190B */
void draw_number_centered_conditional_state(void);  /* 0x03038de2 62B */
void display_blit_bitmap_1bpp_clipped();  /* 0x03038f84 156B */
void display_clear_and_draw_fixed_region(void);  /* 0x030390cc 34B */
void gps_lock_status_or_band_select_screen(char param_1);  /* 0x030390f0 170B */
void check_mode_nibble_eq1_then_write_field_0x2f(void);  /* 0x030391bc 24B */
void key_event_filter_dispatch1(void);  /* 0x030392d4 138B */
void list_cursor_decrement(byte *param_1,char *param_2,byte param_3);  /* 0x030393e8 50B */
void menu_cursor_decrement_with_wrap();  /* 0x0303941c 50B */
void list_cursor_increment(char *param_1,byte *param_2,uint param_3);  /* 0x03039450 44B */
void circular_index_advance_with_capped_depth_counter();  /* 0x0303947c 44B */
void input_state_arm_if_not_busy(void);  /* 0x030394a8 32B */
void input_state_clear_mode_then_arm(void);  /* 0x030394fc 26B */
void ui_call_guard_input_dispatch_a(void);  /* 0x03039518 160B */
void input_state_arm_if_not_busy_variant2(void);  /* 0x030395b8 32B */
void input_state_clear_mode_then_arm_variant2(void);  /* 0x030395d8 26B */
void ui_call_guard_input_dispatch_b(void);  /* 0x030395f4 146B */
void history_list_row_lookup(short param_1);  /* 0x030396d0 138B */
void character_input_event_dispatcher(char param_1);  /* 0x03039810 186B */
void channel_info_screen_refresh(void);  /* 0x030398cc 158B */
void vfo_ab_swap(void);  /* 0x03039988 180B */
void tx_gate_press_standby_action_dispatch(void);  /* 0x03039a3c 510B */
void menu_icon_draw_dispatch(uint param_1,uint param_2);  /* 0x03039e64 250B */
void list_row_scroll_decrement_b(void);  /* 0x03039f60 592B */
void list_row_scroll_decrement_a(void);  /* 0x0303a200 594B */
void zone_confirm_menu_handler(void);  /* 0x0303ab50 914B */
void dialog_show_number_or_alt(void);  /* 0x0303b394 710B */
void main_menu_screen_dispatch(void);  /* 0x0303b6c4 70B */
void menu_option_list_screen_driver(void);  /* 0x0303b808 58B */
void menu_item_dialog_screen_jump(void);  /* 0x0303b842 54B */
void menu_item_plain_dialog_screen(void);  /* 0x0303b878 46B */
void vfo_offset_select_and_string_display(void);  /* 0x0303b8d8 46B */
void vfo_status_screen_number_and_id_redraw(void);  /* 0x0303b906 794B */
void range_count_status_dialog_screen(undefined4 param_1,undefined4 param_2,int param_3);  /* 0x0303bd24 72B */
void numeric_value_adjust_dialog_screen(void);  /* 0x0303bd6c 144B */
void frequency_step_number_screen_refresh(void);  /* 0x0303be4a 88B */
void number_list_dialog_screen(void);  /* 0x0303bea2 52B */
void mode_display_icon_draw_dispatch(void);  /* 0x0303bee0 120B */
void scan_monitor_number_draw_handler(void);  /* 0x0303bf58 268B */
void zone_list_screen_render_input_dispatch(void);  /* 0x0303c0c0 104B */
void menu_screen_render_number_and_list_row(void);  /* 0x0303c128 82B */
void scrollable_list_screen_render_and_dispatch(void);  /* 0x0303c296 102B */
void channel_list_add_dialog_screen(void);  /* 0x0303c2fc 80B */
void list_row_dialog_screen_draw(void);  /* 0x0303c34c 48B */
void screen_setup_number_dialog_header(void);  /* 0x0303c37c 100B */
void screen_number_dialog_with_variant(void);  /* 0x0303c420 80B */
void screen_number_conditional_draw(void);  /* 0x0303c470 74B */
void screen_dual_number_with_table(void);  /* 0x0303c528 98B */
void channel_list_dialog_screen_draw(void);  /* 0x0303c5f8 70B */
void call_gps_id_detail_screen_dispatch(void);  /* 0x0303c63e 146B */
void dialog_record_number_table_display(void);  /* 0x0303c6d0 94B */
void dialog_dual_number_display(void);  /* 0x0303c72e 64B */
void menu_history_countdown_or_refresh(void);  /* 0x0303c76e 82B */
void key_event_character_filter(void);  /* 0x0303c7fc 98B */
void menu_screen_restore_state_and_dispatch(void);  /* 0x0303c97c 126B */
void main_menu_reset_and_enter(void);  /* 0x0303c9fc 60B */
void menu_contact_pick_entry_dispatch(void);  /* 0x0303ca38 50B */
void menu_screen_refresh_dispatch(void);  /* 0x0303ca6c 30B */
void menu_screen_flush_dispatch_a(void);  /* 0x0303ca8c 28B */
void menu_name_field_screen_setup(void);  /* 0x0303cae0 6B */
void menu_table_entry_conditional_screen_setup(void);  /* 0x0303cae6 6B */
void menu_confirm_delete_or_two_mode_screen_setup(void);  /* 0x0303caec 6B */
void radio_shutdown_confirm_screen_setup(void);  /* 0x0303caf2 6B */
void menu_remove_group_init_then_main_menu(void);  /* 0x0303caf8 4B */
void menu_screen_flush_dispatch_b(void);  /* 0x0303cb04 28B */
void menu_contact_view_apply_screen_setup(void);  /* 0x0303cb2c 6B */
void menu_scan_priority_actions_screen_setup(void);  /* 0x0303cb32 6B */
void menu_screen_submode_dispatch_screen_setup(void);  /* 0x0303cb38 6B */
void menu_message_compose_actions_screen_setup(void);  /* 0x0303cb3e 6B */
void menu_field_render_multibranch_screen_setup(void);  /* 0x0303cb44 6B */
void table_entry_build_variant21_then_main_menu(void);  /* 0x0303cb4a 4B */
void menu_screen_dispatch_after_history_flush(void);  /* 0x0303cb54 36B */
void menu_selector_3way_screen_setup(void);  /* 0x0303cb88 6B */
void scan_list_entry_or_name_edit_screen_setup(void);  /* 0x0303cb8e 6B */
void table_entry_select_index_list_variant11_screen_setup(void);  /* 0x0303cb94 6B */
void contact_edit_action_then_main_menu(void);  /* 0x0303cb9a 6B */
void menu_option_three_way_then_main_menu(void);  /* 0x0303cba0 6B */
void menu_field_mode_then_main_menu(void);  /* 0x0303cba6 6B */
void menu_dual_state2_flag_then_main_menu(void);  /* 0x0303cbac 6B */
void menu_state_dispatch_then_main_menu(void);  /* 0x0303cbb2 6B */
void menu_gated_contact_or_static_screen_setup(void);  /* 0x0303cbb8 10B */
undefined4 menu_screen_entry_generic2(void);  /* 0x0303df18 374B */
undefined4 menu_screen_entry_generic1(void);  /* 0x0303e0b8 768B */
undefined4 menu_screen_entry_generic_0303e424(char param_1);  /* 0x0303e424 550B */
undefined4 menu_screen_entry_generic3(char param_1);  /* 0x0303e66c 550B */
undefined4 menu_screen_entry_generic4(void);  /* 0x0303e8e4 548B */
undefined4 menu_screen_entry_generic5(void);  /* 0x0303eb34 374B */
undefined4 menu_screen_entry_generic6(char param_1);  /* 0x0303ecd4 664B */
undefined4 menu_navigation_dispatcher_0303efd4(void);  /* 0x0303efd4 396B */
undefined4 menu_navigation_dispatcher(void);  /* 0x0303f338 396B */
undefined4 menu_navigation_dispatcher_0303f4ec(void);  /* 0x0303f4ec 396B */
undefined4 menu_screen_entry_generic7(void);  /* 0x0303f6a4 396B */
void screen_subtype_set_2_post_0x18(void);  /* 0x0303f864 24B */
void menu_screen_entry_generic8(void);  /* 0x0303f87c 334B */
void dialog_history_release_dispatch_with_call_gate(void);  /* 0x0303fe08 542B */
void dialog_key_release_history_dispatch(void);  /* 0x03040154 230B */
void history_dialog_cancel_and_release_mutex(void);  /* 0x0304023a 8B */
void asterisk_key_and_history_dispatch(void);  /* 0x03040242 42B */
void vfo_ab_swap_key_and_history_dispatch(void);  /* 0x0304026c 22B */
void history_dialog_cancel_and_release_mutex_variant(void);  /* 0x030406da 62B */
void ui_event_loop_entry_with_dialog(void);  /* 0x03040a80 12B */
void key_shortcut_dispatch_table(void);  /* 0x03040b68 20B */
void call_record_list_key_handler(void);  /* 0x03040b7c 12B */
void contact_select_screen_adjust_call(void);  /* 0x03040bb4 20B */
void contact_list_screen_adjust_call(void);  /* 0x03040bc8 20B */
void key_shortcut_call_030338d4(void);  /* 0x03040bdc 16B */
void key_shortcut_call_03033a84(void);  /* 0x03040bec 12B */
void key_shortcut_call_030120d8(void);  /* 0x03040bf8 12B */
void key_shortcut_no_tx_gate_call_03052b90(void);  /* 0x03040c04 6B */
void key_shortcut_call_03052a84_03052a74(void);  /* 0x03040c0a 20B */
void key_shortcut_call_03052a84_03058b18(void);  /* 0x03040c2a 24B */
void key_shortcut_call_0305b480(void);  /* 0x03040c42 12B */
void key_shortcut_call_03066274(void);  /* 0x03040c5e 16B */
void key_shortcut_call_0306669c(void);  /* 0x03040c7e 16B */
void key_shortcut_call_03031420(void);  /* 0x03040c8e 16B */
void key_shortcut_call_0306649c(void);  /* 0x03040cee 16B */
void key_shortcut_special_case(void);  /* 0x03040d74 18B */
void key_shortcut_noop_stub(void);  /* 0x03040d94 24B */
void key_shortcut_dispatch_table_screen_code41h(void);  /* 0x03040dac 8B */
void key_shortcut_dispatch_table_screen_code3ah(void);  /* 0x03040db4 8B */
void key_shortcut_dispatch_table_screen_code33h(void);  /* 0x03040dbc 8B */
void key_shortcut_and_event_record_dispatch_a(void);  /* 0x03040dc4 358B */
void key_shortcut_dispatch_table_screen_code25h(void);  /* 0x03040f48 8B */
void key_shortcut_dispatch_table_screen_code1eh(void);  /* 0x03040f50 8B */
void key_shortcut_dispatch_gate_main(void);  /* 0x03040f58 52B */
void key_shortcut_dispatch_table_screen_code10h(void);  /* 0x03040f8c 8B */
void key_shortcut_dispatch_table_screen_code09h(void);  /* 0x03040f94 8B */
void list_cursor_increment_call1(void);  /* 0x03041024 12B */
void contact_select_screen_adjust_fwd(void);  /* 0x03041030 20B */
void contact_list_screen_adjust_fwd(void);  /* 0x03041044 20B */
void list_cursor_increment_call2(void);  /* 0x03041058 16B */
void list_cursor_increment_call3(void);  /* 0x03041068 12B */
void call_record_display_update_fwd(void);  /* 0x03041074 6B */
void jump_table_dispatch_forward(void);  /* 0x0304107a 20B */
void list_cursor_increment_call4(void);  /* 0x030410b2 12B */
void list_cursor_increment_call5(void);  /* 0x030410be 16B */
void list_cursor_increment_call6(void);  /* 0x030410ce 16B */
void control_action_char_dispatch_fwd(void);  /* 0x030410de 16B */
void list_cursor_increment_call7(void);  /* 0x030410ee 16B */
void list_cursor_increment_call8(void);  /* 0x030410fe 16B */
void list_cursor_increment_call9(void);  /* 0x0304110e 16B */
void list_cursor_increment_call10(void);  /* 0x0304111e 16B */
void list_cursor_increment_call11(void);  /* 0x0304112e 16B */
void list_cursor_increment_call12(void);  /* 0x0304113e 16B */
void list_cursor_increment_call13(void);  /* 0x0304114e 16B */
void list_cursor_increment_call14(void);  /* 0x0304115e 16B */
void list_cursor_increment_call15(void);  /* 0x0304117e 16B */
void radio_param_conditional_update_fwd(void);  /* 0x0304118e 16B */
void key_shortcut_special_case_fwd(void);  /* 0x030411e4 18B */
void list_row_decrement_and_redraw_fwd(void);  /* 0x030411f6 14B */
void key_shortcut_noop_stub_fwd(void);  /* 0x03041204 24B */
void key_shortcut_dispatch_table_list_screens_screen_code42h(void);  /* 0x0304121c 8B */
void key_shortcut_dispatch_table_list_screens_screen_code3bh(void);  /* 0x03041224 8B */
void key_shortcut_dispatch_table_list_screens_screen_code34h(void);  /* 0x0304122c 8B */
void key_shortcut_and_event_record_dispatch_b(void);  /* 0x03041234 358B */
void key_shortcut_dispatch_table_list_screens_screen_code26h(void);  /* 0x030413b8 8B */
void key_shortcut_dispatch_table_list_screens_screen_code1fh(void);  /* 0x030413c0 8B */
void key_shortcut_dispatch_gate_list(void);  /* 0x030413c8 54B */
void key_shortcut_dispatch_table_list_screens_screen_code11h(void);  /* 0x03041400 8B */
void key_shortcut_dispatch_table_list_screens_screen_code0ah(void);  /* 0x03041408 8B */
void tx_pending_mbox_post_clear(void);  /* 0x0304142c 68B */
void menu_row_highlight_draw(void);  /* 0x03041598 170B */
void display_list_with_icons_renderer(void);  /* 0x03041644 186B */
void field_pair_init_with_optional_string_copy(void);  /* 0x03041970 70B */
void table_entry_select_and_index_list_build_variant_03041a68(void);  /* 0x03041a68 60B */
void menu_option_list_init_and_dialog_or_alt_action(void);  /* 0x03041b66 66B */
void state_field_table_index_copy(void);  /* 0x03041bc8 66B */
void pointer_array_index_copy(void);  /* 0x03041c0a 66B */
void dialog_icon_or_sequential_list_show(void);  /* 0x03041c4c 76B */
void menu_list_screen_render_or_single_icon(void);  /* 0x03041cdc 76B */
void menu_list_screen_render_or_single_icon_var2(void);  /* 0x03041d28 76B */
void menu_screen_entry_with_history_pop_var_2c(void);  /* 0x03041e8c 60B */
void menu_screen_entry_with_history_pop_var_2e(void);  /* 0x03041ec8 60B */
void menu_screen_entry_with_history_pop_var_30(void);  /* 0x03041f04 60B */
void menu_screen_entry_with_history_pop_var_2f(void);  /* 0x03041f40 60B */
void menu_screen_type0x2f_flag_init_submode1(void);  /* 0x0304211e 62B */
void menu_screen_type0x2f_flag_init_submode3(void);  /* 0x030421b0 66B */
void menu_screen_entry_with_history_pop_var_14(void);  /* 0x030423a8 78B */
void menu_screen_entry_with_history_pop_var_06(void);  /* 0x030423f6 78B */
void menu_screen_entry_with_history_pop_var_08(void);  /* 0x03042444 78B */
void flags_bit67_lookup_table_read(void);  /* 0x03042492 66B */
void mode_index_zone_setup(void);  /* 0x030425c8 74B */
void channel_name_edit_or_option_list_dispatch(void);  /* 0x03042614 300B */
void screen_option_template_load_id_generic(void);  /* 0x030427b4 124B */
void contact_menu_submenu_action_dispatch(void);  /* 0x03042afc 38B */
void menu_option_list_select_or_show_icon(void);  /* 0x03042c48 120B */
void menu_option_list_init_or_show_icon_ptt_gated(void);  /* 0x03042e20 162B */
void dmr_setting_0x47_read_store(void);  /* 0x03043134 12B */
void menu_field_init_setting_0x48_clamp8(void);  /* 0x0304314c 12B */
void dmr_setting_0x4b_read_store(void);  /* 0x03043164 12B */
void menu_field_init_setting_0x50_clamp8(void);  /* 0x03043170 12B */
void menu_field_init_setting_0x49_clamp8(void);  /* 0x0304317c 12B */
void dmr_setting_0x4e_read_store(void);  /* 0x03043188 12B */
void dmr_setting_0x4f_read_store(void);  /* 0x030431a0 44B */
void menu_option_handler_dispatch(void);  /* 0x030431cc 288B */
void menu_option_list_init_and_state_reset(void);  /* 0x030436c0 44B */
void text_entry_dialog_init_two_field(void);  /* 0x030436ec 136B */
void list_descriptor_copy_and_conditional_dialog_init(void);  /* 0x030438e6 48B */
void menu_screen_entry_with_history_pop_var_01(void);  /* 0x03043916 80B */
void contact_dispatch_by_count_range(void);  /* 0x030439ac 30B */
void scan_list_entry_or_name_edit_dialog_init(void);  /* 0x03043b64 210B */
void index_table_read_decrement(void);  /* 0x03043d14 72B */
void contact_edit_field_action_dispatch(void);  /* 0x03043d5c 24B */
void list_entry_toggle_and_related_lookup_gated(void);  /* 0x03043da0 78B */
void list_entry_toggle_and_related_display_refresh(void);  /* 0x03043dfa 68B */
void active_screen_load_options(void);  /* 0x03043ea4 68B */
void menu_screen_state_dispatch_three_way(void);  /* 0x03043f3c 184B */
void menu_screen_option_list_selector(void);  /* 0x03043ff4 178B */
void menu_screen_option_list_selector_variant2(void);  /* 0x030440d4 178B */
void menu_entry_init_from_settings_0x62_clamp8(void);  /* 0x03044244 12B */
void menu_entry_init_from_settings_0x63_clamp8(void);  /* 0x03044250 12B */
void menu_entry_init_from_settings_0x64_clamp8(void);  /* 0x0304425c 12B */
void menu_entry_init_from_settings_0x65_clamp8(void);  /* 0x03044268 12B */
void menu_entry_init_from_settings_0x66_clamp8(void);  /* 0x03044274 12B */
void menu_entry_init_from_settings_0x67_clamp8(void);  /* 0x03044280 44B */
void menu_context_mode_dispatch(void);  /* 0x030442ac 52B */
void config_mode_selector_apply(void);  /* 0x030443c0 88B */
void config_flags_extract_apply(void);  /* 0x0304461e 100B */
void menu_exit_time_option_load(void);  /* 0x03044860 40B */
void pointer_array_index_load_apply(void);  /* 0x03044888 70B */
void zone_record_template_load_id0x5d(void);  /* 0x030449c4 40B */
void zone_record_template_load_id0x5e(void);  /* 0x03044a28 40B */
void menu_option_list_init_0x22_from_settings_block(void);  /* 0x03044b1e 82B */
void list_descriptor_init_from_vfo_field_0x19(void);  /* 0x03044bc4 90B */
void menu_option_list_init_from_table_and_settings_0x6d(void);  /* 0x03044dda 70B */
void menu_option_list_init_from_table_and_vfo_field0xc(void);  /* 0x03044ec4 80B */
void config_init_with_index_list(void);  /* 0x03044f14 86B */
void contact_edit_field_select_dispatch(void);  /* 0x03045084 30B */
void dialog_setup_with_string_measure(void);  /* 0x03045218 60B */
void menu_screen_dual_index_state2_check_and_flag(void);  /* 0x030454a0 42B */
void menu_screen_state_dispatcher(void);  /* 0x030454cc 260B */
void text_entry_dialog_init_field_pair(void);  /* 0x03045668 166B */
void text_entry_dialog_init_field_pair_variant2(void);  /* 0x03045710 238B */
void menu_option_list_init_with_dualwatch_index_range(void);  /* 0x03045a4c 70B */
void table_entry_select_and_index_list_build_variant_03045c94(void);  /* 0x03045c94 68B */
void menu_screen_state_dispatch_by_submode(void);  /* 0x03045d70 140B */
void vfo_display_step_index_compute(void);  /* 0x03045e90 262B */
void menu_field_render_multibranch_dispatch(void);  /* 0x0304637c 598B */
void menu_confirm_delete_or_two_mode_dispatch(void);  /* 0x03046b40 60B */
void shutdown_confirm_gate_check(void);  /* 0x03046f6c 22B */
void vfo_record_offset_select4(void);  /* 0x0304707c 518B */
undefined4 format_and_write_status_field2();  /* 0x030472d0 82B */
void menu_option_list_init_from_table_and_vfo_state(void);  /* 0x030474ea 84B */
void dispatcher_setting_index_reader(void);  /* 0x03047598 118B */
void flash_field_0x67_clamp_and_list_init(void);  /* 0x0304760e 88B */
void frequency_branch_dialog_init(void);  /* 0x03047666 102B */
void flash_field_bitcount_index_list_init(void);  /* 0x0304787e 92B */
void block_record_template_load_id0x66_03047e4c(void);  /* 0x03047e4c 38B */
void block_record_template_load_id0x66_03047e72(void);  /* 0x03047e72 38B */
void menu_option_list_init_from_table_with_default_100_and_state(void);  /* 0x03047e98 38B */
void block_record_template_load_id0x67(void);  /* 0x03047ebe 38B */
void block_record_template_load_id0x60_03047ffc(void);  /* 0x03047ffc 38B */
void block_record_template_load_id0x62_03048084(void);  /* 0x03048084 36B */
void block_record_template_load_id0x61(void);  /* 0x030480a8 36B */
void block_record_template_load_dispatch_0x69(void);  /* 0x0304812c 22B */
void block_record_template_load_id0x69_030481ac(void);  /* 0x030481ac 36B */
void block_record_template_load_id0x69_030481d0(void);  /* 0x030481d0 36B */
void block_record_template_load_id0x6a(void);  /* 0x030481f4 36B */
void block_record_template_load_id0x6b(void);  /* 0x03048218 36B */
void block_record_template_load_id0x6c_03048294(void);  /* 0x03048294 36B */
void block_record_template_load_dispatch_0x60(void);  /* 0x030482b8 22B */
void block_record_template_load_id0x60_03048310(void);  /* 0x03048310 36B */
void block_record_template_load_id0x62_03048442(void);  /* 0x03048442 36B */
void block_record_template_load_id0x6c_03048466(void);  /* 0x03048466 36B */
undefined4 format_and_write_status_field();  /* 0x030484c8 98B */
void text_field_copy_and_status_write(undefined1 param_1,int param_2,undefined4 param_3);  /* 0x0304852c 78B */
void menu_item_dispatch_cycle_sub_prev(void);  /* 0x030488b0 22B */
void standby_timeout_step_and_char_picker_offset(void);  /* 0x030488dc 60B */
void cyclic_step_duration_display_linear(void);  /* 0x03048918 22B */
void frequency_step_cycle_and_field_select_a(void);  /* 0x03048948 52B */
void settings_field_0x3c_advance_wrap60_and_menu_offset(void);  /* 0x0304897c 68B */
void duration_seconds_cycle_x5_scale_and_menu_offset(void);  /* 0x030489c0 26B */
void duration_seconds_cycle_0to49_from3_and_menu_offset(void);  /* 0x030489da 22B */
void cyclic_step_duration_display_scaled(void);  /* 0x030489f0 26B */
void menu_ms_setting_cycle_wrap_and_char_pos_update(void);  /* 0x03048a0a 22B */
void standby_timeout_step_wrap51_and_char_picker_offset(void);  /* 0x03048a20 46B */
void text_entry_char_group_cycle_var_60_1(void);  /* 0x03048a4e 22B */
void cyclic_step_0xc0_dir1_and_display(void);  /* 0x03048a64 22B */
void menu_ms_setting_cycle_wrap_and_char_pos_update_variant2(void);  /* 0x03048a8c 22B */
void duration_seconds_advance_wrap75_and_menu_offset(void);  /* 0x03048aa2 46B */
void duration_seconds_cycle_0to49_and_menu_offset(void);  /* 0x03048ad0 22B */
void duration_seconds_cycle_0to39_from5_and_menu_offset(void);  /* 0x03048ae6 22B */
void backlight_or_squelch_step_0to100_and_seconds_display(void);  /* 0x03048afc 22B */
void duration_seconds_cycle_0to19_and_menu_offset(void);  /* 0x03048b12 22B */
void cyclic_step_0xff_and_refresh(void);  /* 0x03048b28 20B */
void menu_item_dispatch_cycle_sub_next(void);  /* 0x03048bd4 22B */
void standby_timeout_step_down_wrap97_display(void);  /* 0x03048c00 60B */
void cyclic_step_duration_display_wrapping(void);  /* 0x03048c3c 22B */
void frequency_step_cycle_and_field_select_b(void);  /* 0x03048c6c 52B */
void menu_entry_number_render_and_char_group_cycle(void);  /* 0x03048ca0 66B */
void duration_seconds_cycle_x5_scale_from1_step0_and_menu_offset(void);  /* 0x03048ce2 26B */
void duration_seconds_cycle_0to49_from3_step0_and_menu_offset(void);  /* 0x03048cfc 22B */
void cyclic_value_step_counter_settings_offset(void);  /* 0x03048d12 26B */
void cyclic_ms_display_and_text_cursor_advance(void);  /* 0x03048d2c 22B */
void duration_seconds_decrement_min0_and_menu_offset(void);  /* 0x03048d42 34B */
void menu_setting_cycle_linear_and_char_pos_update(void);  /* 0x03048d64 22B */
void cyclic_step_0xc0_and_display(void);  /* 0x03048d7a 22B */
void menu_ms_setting_cycle_linear_and_char_pos_update(void);  /* 0x03048da0 22B */
void duration_seconds_decrement_min0_and_menu_offset_alt(void);  /* 0x03048db6 34B */
void duration_seconds_cycle_0to49_step0_and_menu_offset_alt(void);  /* 0x03048dd8 22B */
void duration_seconds_cycle_0to39_from5_and_menu_offset_alt(void);  /* 0x03048dee 22B */
void duration_seconds_cycle_0to99_from5_and_menu_offset(void);  /* 0x03048e04 22B */
void cyclic_step_0x14_and_seconds_display(void);  /* 0x03048e1a 22B */
void byte_value_cycle_0to255_and_menu_offset(void);  /* 0x03048e30 20B */
void menu_item_dispatch_plain(void);  /* 0x03048ec4 24B */
void display_number_centered_100_0_color_7e0_with_duration(void);  /* 0x03048fc6 50B */
void display_number_centered_100_0_color_7e0_offset_8(void);  /* 0x03048ff8 40B */
void display_number_centered_100_0_color_7e0_offset_16_duration_x30(void);  /* 0x03049020 44B */
void settings_dual_value_display_and_field_0x57_to_0x3c_sync(void);  /* 0x030490ec 60B */
void settings_field_0x5c_display_and_x5_duration(void);  /* 0x03049128 50B */
void duration_field_display_from_settings_0x5f(void);  /* 0x0304915a 46B */
void display_number_centered_100_0_color_7e0_offset_64_duration_x5(void);  /* 0x03049188 44B */
void settings_value_display_centered_with_state_call(void);  /* 0x03049316 38B */
void menu_option_list_dispatch(uint index,void *list,void *ctx);  /* 0x030493f8 196B */
void menu_option_gen_idx8(void);  /* 0x030494cc 26B */
void menu_option_gen_idx4(void);  /* 0x030494e6 100B */
void menu_option_gen_idx0(void);  /* 0x0304954a 28B */
void menu_option_gen_idx18(void);  /* 0x03049566 16B */
void menu_option_gen_idx10(void);  /* 0x03049576 128B */
void menu_option_gen_idx32(void);  /* 0x030495f6 94B */
void menu_option_gen_idx33(void);  /* 0x03049654 78B */
void menu_option_gen_idx14(void);  /* 0x030496a2 196B */
void menu_option_gen_idx1(void);  /* 0x03049766 128B */
void menu_option_gen_idx12(void);  /* 0x030497fc 56B */
void menu_option_gen_idx5(void);  /* 0x03049834 88B */
void menu_option_gen_idx13(void);  /* 0x0304988c 164B */
void menu_option_gen_idx6(void);  /* 0x03049930 502B */
void menu_option_gen_idx20(void);  /* 0x03049b30 24B */
void menu_option_gen_idx19(void);  /* 0x03049b48 140B */
void menu_option_gen_idx22(void);  /* 0x03049bd4 44B */
void menu_option_gen_idx21(void);  /* 0x03049c00 176B */
void menu_option_gen_idx15(void);  /* 0x03049cb0 28B */
void menu_option_gen_idx16(void);  /* 0x03049ccc 16B */
void menu_option_gen_idx23(void);  /* 0x03049cdc 242B */
void menu_option_gen_idx24(void);  /* 0x03049dd8 88B */
void menu_option_gen_idx25(void);  /* 0x03049e30 84B */
void menu_option_gen_idx34(void);  /* 0x03049e84 22B */
void menu_option_gen_idx31(void);  /* 0x03049e9a 114B */
void menu_option_gen_idx35(void);  /* 0x03049f0c 44B */
void menu_option_gen_idx36(void);  /* 0x03049f38 24B */
void menu_option_gen_idx37(void);  /* 0x03049f50 154B */
void menu_option_gen_idx38(void);  /* 0x03049ff4 64B */
void menu_option_gen_idx42(void);  /* 0x0304a034 24B */
void menu_option_gen_idx43(void);  /* 0x0304a04c 22B */
void menu_option_gen_idx44(void);  /* 0x0304a062 24B */
void menu_option_gen_idx45(void);  /* 0x0304a07a 22B */
void menu_option_gen_idx46(void);  /* 0x0304a090 22B */
void menu_option_gen_idx47(void);  /* 0x0304a0a6 22B */
void menu_option_gen_idx48(void);  /* 0x0304a0bc 22B */
void menu_option_gen_idx40(void);  /* 0x0304a0d2 22B */
void menu_option_gen_idx41(void);  /* 0x0304a0e8 22B */
void menu_option_gen_idx50(void);  /* 0x0304a0fe 20B */
void menu_option_gen_noop_stub(void);  /* 0x0304a112 4B */
void build_sequential_index_list(ushort count,ushort *out_count,byte *out_list);  /* 0x0304a118 24B */
void contact_record_copy_with_limit(int param_1);  /* 0x0304a130 206B */
void startup_input_and_flash_state_init(void);  /* 0x0304af18 40B */
void settings_block4_apply_runtime_params(void);  /* 0x0304af40 316B */
void display_mode_state_icon_blit_0x6b(void);  /* 0x0304c5fc 142B */
void channel_type_mode_settings_write(undefined4 param_1,undefined4 param_2,byte param_3,uint param_4);  /* 0x0304c68c 164B */
void menu_capability_dispatch(uint param_1);  /* 0x0304c750 72B */
void menu_capability_entry_init_bit1(void);  /* 0x0304c7b4 32B */
void menu_capability_field0x42_zero_check(void);  /* 0x0304c7d4 26B */
void menu_capability_entry_init_bit0(void);  /* 0x0304c7ee 30B */
void menu_capability_entry_init_bit2(void);  /* 0x0304c80c 32B */
void menu_capability_entry_init_bit3(void);  /* 0x0304c82c 32B */
void menu_capability_entry_init_bit4(void);  /* 0x0304c84c 32B */
void menu_capability_entry_init_bit5(void);  /* 0x0304c86c 32B */
void menu_capability_entry_init_bit6(void);  /* 0x0304c88c 32B */
void menu_capability_entry_init_bit7(void);  /* 0x0304c8ac 32B */
void menu_capability_field0x43_bit7_check(void);  /* 0x0304c8cc 32B */
void menu_capability_field0x44_bit0_check(void);  /* 0x0304c8f4 50B */
void settings_write_dispatcher_alt(char param_1,byte param_2);  /* 0x0304cb80 688B */
void call_setup_aux_field24_set(undefined4 param_1);  /* 0x0304ce44 12B */
void toggle_0x331_write(char param_1);  /* 0x0304ce70 92B */
void aprs_related_toggle_0x302_write(char param_1);  /* 0x0304cecc 92B */
void status_mode_reset_and_post_0x62_on_bit1(void);  /* 0x0304cf30 44B */
void menu_confirm_apply_zone_handler(void);  /* 0x0304d34c 422B */
void backlight_setting_toggle_handler(void);  /* 0x0304d590 250B */
void dtmf_zone_entry_activate(void);  /* 0x0304d84c 84B */
void dmr_id_log_or_zone_name_confirm_dispatch(void);  /* 0x0304d8a0 312B */
void input_message_dispatcher(void);  /* 0x0304da34 402B */
void menu_item_apply_and_show_or_prompt(void);  /* 0x0304dc24 102B */
void menu_command_dispatch_with_dmr_fallback(void);  /* 0x0304dc8c 28B */
void parse_bcd_numeric_input_dual_range_validation(void);  /* 0x0304dcc4 486B */
void menu_wrapper_conditional_settings_write(void);  /* 0x0304dedc 72B */
void contact_index_log_and_display(void);  /* 0x0304df24 114B */
void copy_field_and_write_status_mode_0x23_1(void);  /* 0x0304e030 20B */
void text_entry_confirm_and_write_setting(void);  /* 0x0304e168 164B */
void menu_wrapper_pointer_state_display(void);  /* 0x0304e20c 38B */
void menu_wrapper_notify_alt_a(void);  /* 0x0304e294 26B */
void menu_wrapper_notify_alt_b(void);  /* 0x0304e2c6 26B */
void history_entry_numeric_display_and_pop(void);  /* 0x0304e2f8 262B */
void settings_save_confirm_dialog(void);  /* 0x0304e416 164B */
void block6_offset0x100_write(void);  /* 0x0304e5d4 10B */
void settings_block6_write_and_show_dialog(void);  /* 0x0304e5e8 10B */
void menu_wrapper_flash_block_write(void);  /* 0x0304e5fc 20B */
void menu_wrapper_conditional_storage_update(void);  /* 0x0304e610 52B */
void menu_wrapper_conditional_display_storage(void);  /* 0x0304e682 20B */
void block6_offset0xa20_write_a(void);  /* 0x0304e696 10B */
void block6_offset0xa20_write_b(void);  /* 0x0304e6a0 10B */
void menu_wrapper_config_bit_flash_write(void);  /* 0x0304e6aa 58B */
void config_copy_full_byte_write_list_index_display_icon(void);  /* 0x0304e718 10B */
void config_copy_offset_3_write_list_index_display_icon(void);  /* 0x0304e736 10B */
void config_copy_offset_4_write_list_index_display_icon(void);  /* 0x0304e740 10B */
void menu_update_highlight_and_icon(void);  /* 0x0304e7e4 20B */
void status_mode_write_from_indexed_field_a(void);  /* 0x0304e828 20B */
void state_dispatcher_menu_char_0x01_0x02(void);  /* 0x0304eb48 308B */
void menu_option_activate_dialog_code8(void);  /* 0x0304edf0 46B */
void menu_option_activate_dialog_code4(void);  /* 0x0304ee1e 46B */
void menu_option_activate_dialog_code5(void);  /* 0x0304ee4c 154B */
void menu_option_activate_dialog_code6(void);  /* 0x0304eee6 46B */
void menu_option_activate_dialog_code7(void);  /* 0x0304ef14 46B */
void dtmf_or_wlt_channel_select_dispatch(void);  /* 0x0304ef42 182B */
void status_mode_write_from_indexed_field_b(void);  /* 0x0304f168 20B */
void contact_edit_mode_0x02_save_or_pop(void);  /* 0x0304f1b4 66B */
void status_dialog_show_or_request_by_code(void);  /* 0x0304f24c 80B */
void menu_confirm_apply_scan_handler(void);  /* 0x0304f384 390B */
void channel_entry_command_byte_router(void);  /* 0x0304f548 176B */
void text_entry_commit_name(void);  /* 0x0304f630 94B */
void contact_edit_mode_dispatcher_0x00_0x01(void);  /* 0x0304f690 88B */
void menu_refresh_mode_dispatch(void);  /* 0x0304f6e8 92B */
void contact_slot_remove_and_resave_confirm(void);  /* 0x0304f744 150B */
void menu_item_status_refresh_dispatch(void);  /* 0x0304f820 596B */
void settings_menu_wrapper_dispatch(void);  /* 0x0304fab4 56B */
void menu_wrapper_opcode0x10(void);  /* 0x0304fb2c 12B */
void menu_wrapper_alt_opcode9(void);  /* 0x0304fb38 12B */
void menu_wrapper_alt_opcode0(void);  /* 0x0304fb44 12B */
void menu_wrapper_alt_opcode1(void);  /* 0x0304fb50 12B */
void menu_wrapper_alt_opcode2(void);  /* 0x0304fb5c 12B */
void menu_wrapper_alt_opcode3(void);  /* 0x0304fb68 12B */
void menu_wrapper_alt_opcode4(void);  /* 0x0304fb74 12B */
void menu_wrapper_alt_opcode5(void);  /* 0x0304fb80 12B */
void menu_wrapper_alt_opcode7(void);  /* 0x0304fb8c 12B */
void menu_wrapper_alt_opcode6(void);  /* 0x0304fb98 12B */
void menu_wrapper_opcode0x2a(void);  /* 0x0304fba4 22B */
void menu_wrapper_opcode0x47(void);  /* 0x0304fbf8 12B */
void menu_wrapper_opcode0x4c(void);  /* 0x0304fc04 12B */
void menu_wrapper_opcode0x48(void);  /* 0x0304fc10 12B */
void menu_wrapper_opcode0x4d(void);  /* 0x0304fc1c 12B */
void menu_wrapper_opcode0x4b(void);  /* 0x0304fc28 12B */
void menu_wrapper_opcode0x50(void);  /* 0x0304fc34 12B */
void menu_wrapper_opcode0x49(void);  /* 0x0304fc40 12B */
void menu_wrapper_opcode0x4e(void);  /* 0x0304fc4c 12B */
void menu_wrapper_opcode0x4a(void);  /* 0x0304fc58 12B */
void menu_wrapper_opcode0x4f(void);  /* 0x0304fc64 22B */
void menu_wrapper_opcode0x31(void);  /* 0x0304fcb8 16B */
void menu_wrapper_opcode0x2d(void);  /* 0x0304fcc8 44B */
void menu_wrapper_opcode0x41(void);  /* 0x0304fcf4 12B */
void menu_wrapper_field0x38(void);  /* 0x0304fd28 20B */
void menu_wrapper_field0x39(void);  /* 0x0304fd3c 20B */
void menu_wrapper_field0x3b(void);  /* 0x0304fd64 20B */
void menu_wrapper_opcode0x43(void);  /* 0x0304fd78 12B */
void menu_wrapper_field0x80_readback(void);  /* 0x0304fd84 60B */
void menu_wrapper_opcode7_conditional(void);  /* 0x0304fdc0 56B */
void menu_wrapper_call_0301_78ec(void);  /* 0x0304fdf8 28B */
void menu_wrapper_opcode8(void);  /* 0x0304fe14 12B */
void menu_wrapper_status_mode_0x2a(void);  /* 0x0304fe54 10B */
void menu_wrapper_opcode0x5f(void);  /* 0x0304fe8c 18B */
void menu_wrapper_opcode3(void);  /* 0x0304fe9e 18B */
void menu_wrapper_field0xa1(void);  /* 0x0304feb0 24B */
void menu_wrapper_status_mode_0x2a_b(void);  /* 0x0304fec8 10B */
void menu_wrapper_field0xa3(void);  /* 0x0304fed2 20B */
void menu_wrapper_ui_event_0x11(void);  /* 0x0304fee6 48B */
void menu_wrapper_opcode0x55(void);  /* 0x0304ff16 12B */
void menu_wrapper_opcode0x54(void);  /* 0x0304ff22 12B */
void menu_wrapper_opcode0x42(void);  /* 0x0304ff2e 12B */
void menu_wrapper_opcode0x5a(void);  /* 0x0304ff3a 12B */
void menu_wrapper_conditional_complex(void);  /* 0x0304ff46 60B */
void menu_wrapper_field0x700(void);  /* 0x0304ff82 28B */
void menu_wrapper_field0xa4_toggle(void);  /* 0x0304ff9e 66B */
void menu_wrapper_field0xa5_toggle_a(void);  /* 0x0304ffe0 66B */
void menu_wrapper_field0xa5_toggle_b(void);  /* 0x03050034 60B */
void menu_wrapper_opcode0x45(void);  /* 0x0305007a 12B */
void menu_wrapper_opcode9_boolinvert(void);  /* 0x03050086 16B */
void menu_wrapper_opcode10_boolinvert(void);  /* 0x03050096 14B */
void menu_wrapper_noop_stub_a(void);  /* 0x030500a4 8B */
void status_mode_write_from_indexed_field_c(void);  /* 0x03050438 22B */
void channel_command_dispatch_select_or_save_name(void);  /* 0x03050450 264B */
void menu_char_dispatcher_null_and_0x01(void);  /* 0x030505a4 134B */
void field_entry_confirm_multicontext_dispatch(void);  /* 0x0305063c 488B */
void status_field_dispatch_variant_6(void);  /* 0x030508c0 46B */
void status_field_dispatch_variant_7(void);  /* 0x030508ee 46B */
void status_field_dispatch_variant_3(void);  /* 0x0305091c 154B */
void status_field_dispatch_variant_1(void);  /* 0x030509b6 46B */
void status_field_dispatch_variant_2(void);  /* 0x030509e4 46B */
void dialog_icon_or_commit_on_flag_0x40(void);  /* 0x03050a12 120B */
void channel_contact_commit_or_delete_dispatch(void);  /* 0x03050b9c 338B */
void status_field_dispatch_variant_5(void);  /* 0x03051764 46B */
void status_mode_screen_select_and_write_var2(void);  /* 0x03051792 46B */
void status_field2_dispatch_with_table_select(void);  /* 0x030517c0 154B */
void status_mode_screen_select_and_write_var1(void);  /* 0x0305185a 46B */
void status_field_dispatch_variant_4(void);  /* 0x03051888 46B */
void dialog_or_channel_select_on_flag_0x40(void);  /* 0x030518b6 118B */
void scan_list_flash_field_bit_update(void);  /* 0x030519a0 478B */
void menu_screen_state_mode_dispatch(void);  /* 0x03051bac 586B */
void quick_text_insert_and_commit(void);  /* 0x03051e60 68B */
void menu_confirm_apply_manual_freq_entry(void);  /* 0x03051ea4 842B */
void menu_confirm_apply_channel_number_entry(void);  /* 0x0305225c 572B */
void history_or_channel_selection_key_dispatch(void);  /* 0x03052518 462B */
void history_entry_stage(void);  /* 0x03052744 32B */
void history_entry_verify_post_or_flag(void);  /* 0x03052764 56B */
void history_entry_cancel_pending(void);  /* 0x030527f4 32B */
void draw_wrapped_string_then_dialog_header(void);  /* 0x0305298c 20B */
void jump_table_dispatch_by_param(uint param_1);  /* 0x03052a74 14B */
void channel_freq_adjust_shortcut(void);  /* 0x03052a84 74B */
void call_record_display_update(void);  /* 0x03052b90 114B */
void radio_shutdown_confirm_screen(void);  /* 0x03052c98 106B */
char zero_bit_count_13byte_prefix(int param_1);  /* 0x03052d04 68B */
char byte_field_first_set_bit_position(int param_1);  /* 0x03052d84 62B */
byte dmr_list_count_block10_clamped(void);  /* 0x03053960 54B */
void dmr_list_subsystem_init(void);  /* 0x03053afc 16B */
void list_record_lookup_and_toggle_by_index();  /* 0x03053f80 710B */
undefined1 radio_mode_state_field_lookup_if_key_matches(int param_1);  /* 0x030543d4 116B */
void ucos3_task_create_prio38_stk0x180(void);  /* 0x0305446c 62B */
void ui_tick_prescaler_post(void);  /* 0x030546dc 36B */
void countdown_timer_tick_standby_trigger(void);  /* 0x03054700 66B */
void clock_uart_reconfigure(void);  /* 0x0305499c 208B */
void rf_mode_debounce_state_machine(void);  /* 0x03054ca8 188B */
void event_queue_reset(void);  /* 0x03054d80 32B */
void diag_screen_adc_reading_draw(void);  /* 0x03054ddc 24B */
void hw_register_0x78_write_from_byte_pair_fwd_thunk(undefined1 param_1);  /* 0x03054df4 10B */
void fd6818b_reg_write_51h_or8000h(ushort param_1);  /* 0x03054e00 22B */
void fd6818b_reg_write_51h_or9000h(ushort param_1);  /* 0x03054e18 22B */
void set_global_upper_16bits_fwd_thunk(undefined2 param_1);  /* 0x03054e40 10B */
void noop_stub_0302184c_fwd_thunk(undefined1 param_1);  /* 0x03054e4c 10B */
void mmio_11000114_low_word_duplicate_write_fwd_thunk(undefined1 param_1);  /* 0x03054e58 10B */
void mmio_11000108_high_word_write_from_byte_fwd_thunk(undefined1 param_1);  /* 0x03054e64 10B */
void dac_channel2_write_wrapper(undefined1 param_1);  /* 0x03054e70 10B */
void adc_diag_avg_ch2_display(void);  /* 0x03054e7c 64B */
void adc_diag_avg_ch1_display(void);  /* 0x03054ebc 82B */
void keypad_battery_poll_burst_5x20ms(void);  /* 0x03054f10 50B */
void audio_compander_calibration_apply(uint param_1);  /* 0x030551b0 516B */
void init_flag_and_mmio_bits7_8(void);  /* 0x030553d4 22B */
void channel_change_tx_led_reset(void);  /* 0x030553ec 222B */
void byte_code_range_dispatch_to_fnptr_table(void);  /* 0x030554cc 134B */
void ui_deferred_event_task_loop(void);  /* 0x03055574 144B */
void ucos3_task_create_prio34_stk0x100(void);  /* 0x03055604 62B */
void modem_buffer_char_remap_write_03055850(uint param_1);  /* 0x03055850 48B */
void ptt_preamble_tone_period_lookup(uint param_1);  /* 0x03055880 72B */
void channel_offset_minus_0x10(uint param_1,short *param_2,short *param_3);  /* 0x030558e8 58B */
char count_set_bits_in_flash_field(void);  /* 0x030559b0 72B */
void recent_value_list_append_to_flash(ushort param_1,undefined4 param_2);  /* 0x03055cc0 98B */
void list_cursor_decrement_call3(undefined1 *param_1,undefined1 *param_2);  /* 0x03055dfc 38B */
void list_cursor_decrement_call4(undefined1 *param_1,undefined1 *param_2);  /* 0x03055e68 40B */
undefined2 vfo_tx_contact_field_read(char param_1);  /* 0x030560ac 58B */
void channel_record_read_full(undefined2 param_1,undefined4 param_2);  /* 0x030561b4 44B */
void vfo_channel_apply_delegate();  /* 0x0305624c 10B */
ushort channel_list_index_resolve(undefined1 param_1,ushort param_2);  /* 0x03056264 114B */
void vfo_scan_add_toggle(uint param_1);  /* 0x03056324 262B */
undefined1 get_zone_count(void);  /* 0x03056444 30B */
void draw_channel_records_from_flash(ushort param_1,ushort param_2,char param_3);  /* 0x0305663c 218B */
void list_cursor_decrement_call5(undefined1 *param_1,undefined1 *param_2);  /* 0x03056718 28B */
void dmr_id_log_append(char param_1,uint param_2);  /* 0x03056880 126B */
void control_action_char_dispatch(undefined2 *param_1,undefined2 *param_2);  /* 0x03056ba8 70B */
void menu_field_render_dispatch_by_type(undefined2 *param_1,undefined2 *param_2);  /* 0x03056c0c 70B */
void vfo_field_write_nibble_low_at_0xd(byte param_1);  /* 0x03056f10 224B */
void vfo_field_write_6bit_at_0xf();  /* 0x03056ff8 226B */
void vfo_field_write_byte_at_0x1b();  /* 0x030572e0 246B */
void channel_load_synchronized(undefined2 param_1,undefined1 param_2);  /* 0x0305813c 66B */
void list_row_draw_variant1(uint param_1,uint param_2,uint param_3);  /* 0x03058360 330B */
uint fixed21_slot_table_remove_last_used();  /* 0x0305851c 104B */
undefined4 fixed21_slot_table_insert_after_last_used(undefined4 param_1,uint param_2);  /* 0x03058584 88B */
void flash_block_config_load_validate_writeback(uint param_1,char param_2);  /* 0x03058620 346B */
undefined4 number_list_display_update(uint param_1);  /* 0x03058b18 340B */
void list_item_select_screen(undefined1 param_1,undefined1 param_2);  /* 0x03058e44 212B */
ushort flash_chain_walk_to_slot(uint param_1,char param_2);  /* 0x03058f18 86B */
void text_entry_commit_and_clear_mode_flags(void);  /* 0x0305913c 74B */
void dtmf_quicktext_scroll_display_dispatch(void);  /* 0x03059550 106B */
void channel_type_apply_tone_idx0xc(void);  /* 0x030595d8 4B */
void channel_type_apply_tone_idx0xd(void);  /* 0x030595dc 4B */
void channel_type_apply_tone_idx0xe(void);  /* 0x030595e0 4B */
void channel_type_apply_tone_idx0xf(void);  /* 0x030595e4 4B */
void channel_type_apply_tone_idx_param(undefined4 param_1,undefined4 param_2,char param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);  /* 0x030595e8 8B */
void channel_type_apply_tone_idx10(void);  /* 0x030595f0 2B */
void channel_type_apply_tone_idx_default(void);  /* 0x030595f2 190B */
void init_field_pair_0x20_5(void);  /* 0x030596b0 32B */
void write_byte_field_030596d0(uint value);  /* 0x030596d0 6B */
void text_entry_status_glyph_set_by_settings_flags_a();  /* 0x030596d8 54B */
void text_entry_status_glyph_set_by_settings_flags_b();  /* 0x03059710 56B */
void dialog_request_init(ushort param_1);  /* 0x03059860 116B */
void scan_channel_icon_draw(byte param_1);  /* 0x030598d4 112B */
undefined4 ascii_digits_to_uint(void);  /* 0x030599a0 378B */
char name_table_prefix_match_count(void);  /* 0x03059d1c 222B */
undefined4 * scan_list_row_render();  /* 0x0305a06c 150B */
uint text_entry_columns_remaining(uint param_1);  /* 0x0305a12c 86B */
void scan_list_scroll_update();  /* 0x0305a184 294B */
void scan_list_name_edit_input_handler();  /* 0x0305a2d8 322B */
void text_entry_char_insert_and_render(void);  /* 0x0305a620 190B */
void scan_state_tick(void);  /* 0x0305aab8 134B */
void draw_wrapped_text_conditional(void);  /* 0x0305ab40 156B */
void text_entry_char_row_step_wrap(void);  /* 0x0305b04c 60B */
void scan_label_entry_state_dispatch(void);  /* 0x0305b088 152B */
void text_entry_state_dispatch(void);  /* 0x0305b308 96B */
void radio_state_render_update(void);  /* 0x0305b480 140B */
void scan_list_row_init_and_render(void);  /* 0x0305b7e4 24B */
uint channel_frequency_step_clamp(uint param_1,int param_2);  /* 0x0305b7fc 222B */
void channel_freq_step_adjust_a(void);  /* 0x0305b91c 50B */
void channel_freq_step_adjust_b(void);  /* 0x0305b950 50B */
void call_teardown_and_history_dispatch(void);  /* 0x0305baa8 66B */
void radio_mode_entry_reinit_and_display(void);  /* 0x0305baec 806B */
void tx_key_from_vfo_mode_guard(char param_1,void *param_2,char param_3);  /* 0x0305be64 306B */
void sysctl_bit8_toggle_with_mode_flag(char param_1);  /* 0x0305c974 48B */
void channel_select_commit_and_notify();  /* 0x0305c9a4 104B */
void list_screen_none_placeholder(char param_1,byte param_2,byte param_3);  /* 0x0305cb44 194B */
void list_cursor_decrement_call6(undefined1 *param_1,undefined1 *param_2);  /* 0x0305cc2c 34B */
void vfo_field_write_byte_at_0xe(byte param_1);  /* 0x0305cc74 174B */
undefined4 vfo_field_write_bit6_at_0xf(char param_1);  /* 0x0305cd24 294B */
void channel_select_type_dispatch();  /* 0x0305ce84 180B */
void channel_select_type0(void);  /* 0x0305cf60 18B */
void channel_select_type1(void);  /* 0x0305cf72 14B */
void channel_select_type0_alt(void);  /* 0x0305cf80 18B */
void channel_select_type2(void);  /* 0x0305cf92 14B */
void channel_select_type_default(void);  /* 0x0305cfa0 22B */
uint record_build_value_plus_csv_field(undefined4 param_1,char *param_2,undefined4 param_3,undefined1 *param_4);  /* 0x0305d4f0 80B */
void dialog_flags_load_from_param_or_flash(undefined4 param_1,undefined4 param_2,uint param_3);  /* 0x0305d710 514B */
void dialog_clear_flag_bit2_at_1_variant_0305d91c(void);  /* 0x0305d91c 18B */
void dialog_state_set_bit3_wrapper();  /* 0x0305d930 10B */
void dialog_flags_clear_for_channel_sync(void);  /* 0x0305d958 44B */
void dialog_clear_flag_bit2_at_1(void);  /* 0x0305d9ac 14B */
void dialog_enter_mode2(void);  /* 0x0305dad8 22B */
void dialog_leave_locked_state(void);  /* 0x0305daf0 56B */
void dialog_idle_ready_state_trigger(void);  /* 0x0305db64 34B */
void clear_bit1_set_bit2_and_dialog_state(void);  /* 0x0305db88 20B */
void dialog_clear_flag_bit1_then_set_state(void);  /* 0x0305db9c 20B */
void dialog_flags_restore_from_flash_0xf00(void);  /* 0x0305dbb0 52B */
byte read_byte_field_0305dbf4(void);  /* 0x0305dbf4 8B */
void settings_write_0xf00_wrapper(undefined1 param_1);  /* 0x0305dbfc 54B */
void ptt_release_handler(void);  /* 0x0305dc40 84B */
void dialog_history_advance_or_dispatch(void);  /* 0x0305dc94 184B */
void channel_forward_navigation_commit(byte param_1);  /* 0x0305dd94 344B */
void dialog_close_reset(void);  /* 0x0305df04 68B */
void dialog_tick_idle_check(void);  /* 0x0305dfd4 60B */
byte dialog_flags_low2bits_read(void);  /* 0x0305e010 10B */
void dialog_tick_event_dispatcher(void);  /* 0x0305e02c 474B */
void event10_flag_dispatch_and_ptt_ui_state(void);  /* 0x0305e290 54B */
void tx_dialog_event_state_dispatcher(void);  /* 0x0305e4e8 400B */
void tx_forbid_event_flag5_handler(void);  /* 0x0305e9cc 44B */
void tx_event_flag_dispatcher(void);  /* 0x0305ea44 284B */
void event_flags9_dispatch_and_name_encode(void);  /* 0x0305ed30 198B */
void event_flags14_dispatch_hw_and_flaggrp(void);  /* 0x0305edfc 90B */
void flash_quad_enable_and_system_reset(void);  /* 0x0305ef30 20B */
short bcd_nibbles_unpack_to_int_variable_width(ushort *param_1,char param_2);  /* 0x0305f5ec 40B */
void int_to_bcd_bytes_const4h_fwd(undefined4 param_1,undefined4 param_2);  /* 0x0305f718 10B */
void data_block_checksum4(byte *param_1,byte *param_2);  /* 0x0305f724 180B */
void struct_init_const_wrapper();  /* 0x0305f7d8 8B */
void byte_table_derive_from_const_seed(byte *param_1);  /* 0x0305f7e0 86B */
void ptt_preamble_end_ui_audio_setup_2(void);  /* 0x0305fbf8 42B */
void pending_request_set_code(undefined1 param_1);  /* 0x0305fc98 12B */
undefined1 read_byte_field_0305fca8(void);  /* 0x0305fca8 6B */
void channel_switch_display_reset(void);  /* 0x0305fcb0 34B */
void rssi_rolling_average_meter_update(void);  /* 0x0305ffe4 122B */
byte vfo_display_debounce_and_hw_flag_clear(void);  /* 0x03060060 468B */
void flag_post_every_third_tick(void);  /* 0x03060884 50B */
void settings_write_0x50_wrapper(undefined4 param_1,undefined1 param_2);  /* 0x03060914 20B */
void packed_flags_0x67_write(void);  /* 0x03060928 120B */
void ucos3_task_create_prio32_stk0x100(void);  /* 0x030609ac 62B */
void tx_led_or_tone_off_conditional_variant_030609ec(void);  /* 0x030609ec 26B */
void tx_led_or_tone_off(void);  /* 0x03060a08 10B */
void tx_led_or_tone_off_conditional(void);  /* 0x03060a14 26B */
void tx_led_or_tone_on(void);  /* 0x03060a30 10B */
void ui_background_flag_post_0x4000(void);  /* 0x03060a3c 14B */
void settings_read_dispatch_0x31_then_hook(void);  /* 0x03060b54 14B */
void iram_call_0002bb18_arg0(void);  /* 0x03060b64 10B */
void tx_led_tone_task_loop(void);  /* 0x03060d14 94B */
void compand_table_nibble_split_lookup_variant_03060da8(uint param_1,undefined2 *param_2,undefined2 *param_3);  /* 0x03060da8 40B */
void ui_mode_noop_stub_variant_03060e3c(void);  /* 0x03060e3c 10B */
void recording_stop_tx_finalize(void);  /* 0x03061110 90B */
void call_record_detail_render(void);  /* 0x030617f0 538B */
void settings_toggle_and_notify_0x45(char param_1);  /* 0x03061a88 108B */
void vfo_field_write_2bit_at_0xc(uint param_1);  /* 0x03061f80 214B */
void vfo_field_write_2bit_at_8_v2(byte param_1);  /* 0x03062064 212B */
void gps_display_refresh_and_notify(void);  /* 0x03062510 172B */
void gps_display_periodic_refresh_tick(void);  /* 0x030625bc 112B */
void radio_param_conditional_update(undefined2 *param_1,undefined2 *param_2);  /* 0x03062d04 38B */
void gps_log_record_append_compact(undefined4 param_1,undefined2 param_2);  /* 0x03062d2c 342B */
void gps_coordinate_normalize_pair(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 *param_5,undefined4 *param_6);  /* 0x03062fe4 168B */
void gps_coordinate_distance_soft_float(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);  /* 0x030630b4 222B */
undefined4 gps_coordinate_pair_distance_calc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8, undefined2 *param_9);  /* 0x0306319c 1234B */
void flash_block6_read_off0x100_len13(void);  /* 0x03063cac 22B */
undefined4 flash_block6_pattern_match_mode_entry(void);  /* 0x03063e58 496B */
void settings_flag_bits_sync_to_dat_03064328(void);  /* 0x0306419c 60B */
undefined1 get_current_mode_state2(void);  /* 0x030641e4 6B */
void set_flag_byte_03064328(uint value);  /* 0x030641ec 6B */
void key_hold_debounce_state_dispatcher(void);  /* 0x030642c0 468B */
void flash_block3_tonecall_cache_load(void);  /* 0x03064564 34B */
void call_list_index_write2(void);  /* 0x03064588 34B */
void fd6818b_channel_table_register_program(uint param_1);  /* 0x030645ac 64B */
void fd6818b_channel_table_program_idx5(void);  /* 0x030645ec 12B */
void flash_pending_action_scan_and_apply(void);  /* 0x030645f8 524B */
void dtmf_tone_playback_from_i2c_code(uint param_1);  /* 0x03064950 354B */
undefined4 dtmf_tone_playback_from_i2c_stored_code(uint param_1);  /* 0x03064acc 466B */
void call_timeout_and_tx_state_tick(void);  /* 0x03064d34 452B */
void settings_block4_5byte_array_read(uint param_1,void *param_2);  /* 0x03064f24 48B */
bool protocol_command_byte_dispatch(uint param_1,char param_2);  /* 0x03064f88 420B */
void settings_block4_array_entry_read(uint param_1,void *param_2);  /* 0x03065150 32B */
uint list_screen_event_dispatch(uint param_1,uint param_2);  /* 0x03065170 142B */
undefined4 list_screen_event_clear_flag_and_notify(void);  /* 0x0306520c 24B */
bool list_screen_event_open_dialog(void);  /* 0x03065224 60B */
undefined4 list_screen_event_enqueue_dialog_type4(void);  /* 0x03065260 14B */
undefined4 list_screen_event_enqueue_dialog_type8(void);  /* 0x0306526e 14B */
undefined4 list_screen_event_enqueue_dialog_type5(void);  /* 0x0306527c 14B */
undefined4 list_screen_event_enqueue_dialog_type7(void);  /* 0x0306528a 14B */
undefined4 list_screen_event_enqueue_dialog_type6(void);  /* 0x03065298 14B */
undefined4 alert_code_post_0xb(void);  /* 0x030653a0 24B */
undefined4 alert_code_post_0xc(void);  /* 0x030653b8 24B */
undefined4 alert_code_post_0xd(void);  /* 0x030653d0 24B */
undefined4 alert_code_post_0xe(void);  /* 0x030653e8 24B */
void iram_delay_call_arg2(void);  /* 0x03065438 10B */
void rda5807m_i2c_start(void);  /* 0x03065444 64B */
void rda5807m_i2c_stop(void);  /* 0x03065484 82B */
void rda5807m_bitbang_ack_pulse(void);  /* 0x03065514 50B */
void rda5807m_i2c_send_byte(char param_1);  /* 0x03065548 82B */
void peripheral_reset_step_bit0x20(void);  /* 0x0306559c 14B */
byte rda5807m_i2c_recv_byte(void);  /* 0x030655ac 122B */
void rda5807m_i2c_read_addr_phase(void);  /* 0x03065628 14B */
void rda5807m_read_reg_0a(undefined1 *param_1);  /* 0x03065638 34B */
void rda5807m_set_volume(byte param_1);  /* 0x03065694 88B */
void rda5807m_tune(uint param_1);  /* 0x030656ec 158B */
void rda5807m_fm_on(void);  /* 0x0306578c 50B */
void rda5807m_fm_off(void);  /* 0x0306580c 24B */
void tx_abort_on_condition(void);  /* 0x03065824 58B */
void rda5807m_seek_complete_poll(void);  /* 0x03065bb8 140B */
void roam_zone_record_init(void);  /* 0x03065c58 432B */
undefined1 read_byte_field_03065e34(void);  /* 0x03065e34 6B */
void channel_scan_step_and_lock(void);  /* 0x03065e3c 500B */
bool is_memory_channel_not_vfo(void);  /* 0x030660b8 68B */
void list_row_draw_variant2(uint param_1,uint param_2,uint param_3);  /* 0x030660fc 336B */
void table_entry_write_field_0x14_arg1h_10h(void);  /* 0x03066734 12B */
void table_entry_write_field_0x14_arg1h_2h(void);  /* 0x03066740 12B */
undefined4 poll_flag_until_ff_or_timeout(void);  /* 0x030667a4 66B */
void spi_sdcard_read_status_register(void);  /* 0x030667e8 40B */
bool spi_sdcard_select_and_wait_ready(void);  /* 0x03066810 34B */
bool spi_sdcard_sync_byte_probe(undefined4 param_1,undefined2 param_2);  /* 0x03066888 78B */
undefined4 spi_sdcard_block_write_512_with_response_check(undefined4 param_1,char param_2);  /* 0x030668e0 134B */
char spi_sdcard_send_command(byte param_1,undefined4 param_2,undefined1 param_3);  /* 0x03066968 140B */
bool sdcard_read_cid(undefined4 param_1);  /* 0x030669f4 42B */
bool sdcard_read_csd(undefined4 param_1);  /* 0x03066a20 42B */
int sdcard_spi_probe_and_init(void);  /* 0x03066ae0 452B */
int sdcard_data_block_read();  /* 0x03066ca8 124B */
int spi_sdcard_block_write_dispatch(int param_1,int param_2,char param_3);  /* 0x03066d24 148B */
undefined4 sdcard_block_trailer_word_read(void);  /* 0x03066db8 44B */
void sdcard_store_u32_in_block_67999(undefined4 param_1);  /* 0x03066df4 78B */
void call_list_index_write(void);  /* 0x03066ea4 86B */
undefined1 cos_scaled_piecewise_to_int();  /* 0x03066f00 118B */
void zero_4entry_16byte_table_and_related_fields(void);  /* 0x03067124 30B */
void flash_block3_unpack_cfg_0x36_0x41(void);  /* 0x0306715c 200B */
void fd6818b_load_coeff_table_regs(void);  /* 0x03067224 106B */
void favorite_channel_scan_confirm_and_switch(void);  /* 0x03067290 480B */
void flash_block6_keyed_field_load(void);  /* 0x03067538 42B */
void fd6818b_page0_enable_config(char param_1);  /* 0x03067564 144B */
short u16_byte_swap_via_lookup(uint param_1);  /* 0x03067638 26B */
void block7_syndrome_threshold_bit_correct(int param_1);  /* 0x030676d8 206B */
byte block_bit_transpose_crc_verify(undefined1 *param_1);  /* 0x030677a8 176B */
void uart_rx_frame_assemble_polarity_correct();  /* 0x03067978 362B */
byte * block7_parity_bit_interleave_encode(byte *param_1);  /* 0x03067b18 200B */
int tone_gen_command_frame_build_and_send(int param_1,undefined1 param_2,undefined1 param_3,uint param_4);  /* 0x03067be0 84B */
int frame_build_two_block_crc_encoded(int param_1,undefined1 param_2,undefined1 param_3,uint param_4,undefined2 param_5, undefined2 param_6);  /* 0x03067c34 148B */
void tone_gen_config_apply(uint param_1);  /* 0x03067cc8 574B */
void backup_or_restore_slot_from_scratch();  /* 0x03068164 22B */
void radio_mode_enter_and_refresh(char param_1);  /* 0x0306817c 102B */
void call_hold_led_debounce_dual_timer_tick(void);  /* 0x03068224 132B */
void local_beep_tone_burst(void);  /* 0x03068380 188B */
void dialog_show_and_clear_bits(void);  /* 0x030684f4 68B */
void call_teardown_tx_release_sequence(void);  /* 0x03068538 292B */
void radio_boot_task_entry(void);  /* 0x03068688 20B */
undefined4 ucos3_curtcb_field84_read(undefined4 *param_1);  /* 0x030687a4 58B */
void update_and_apply_settings();  /* 0x030687f0 34B */
uint os_flag_group_ready_bits_apply_or_error(void);  /* 0x030688c8 20B */
uint os_flag_wait_and_dispatch(void);  /* 0x030688dc 1138B */
void list_register_push_front_a(int param_1);  /* 0x03068d94 30B */
void dlist_unlink_timed(int param_1);  /* 0x03068e4c 48B */
void queue_state_update_and_process(int param_1,undefined4 param_2,undefined4 param_3);  /* 0x0306909c 70B */
void registry_list_push_front_a(int param_1);  /* 0x030693e8 26B */
void scheduled_task_state_advance_with_queue_promotion(int *param_1,undefined4 param_2,short param_3,int *param_4,undefined4 *param_5);  /* 0x03069738 598B */
void ucos3_sched_lock_time_stop_irq_restore(undefined4 param_1,undefined4 param_2,int param_3);  /* 0x030699a8 32B */
void scheduled_task_advance_or_requeue(int *param_1,short param_2,undefined4 *param_3);  /* 0x03069ae0 484B */
void list_register_push_front_b(int param_1);  /* 0x03069d00 30B */
void dlist_unlink_msgq(int param_1);  /* 0x03069dec 48B */
short ucos_msg_queue_post_or_pend_variant(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x03069e1c 684B */
undefined4 guarded_request_command_dispatch(int *param_1,undefined4 param_2,short param_3,undefined2 *param_4,undefined4 *param_5, int *param_6);  /* 0x0306a1b8 482B */
void radio_list_item_reinit_pend_list(undefined4 *param_1);  /* 0x0306a4b8 38B */
void critical_section_counted_init_dispatch();  /* 0x0306a500 168B */
void dlist_unlink_radio(int param_1);  /* 0x0306a5c8 48B */
void radio_state_and_linked_list_node_fields_zero_reset(undefined4 *param_1);  /* 0x0306a93c 238B */
void cpu_and_channel_load_statistics_task(void);  /* 0x0306aa2c 742B */
void subsystem_handshake_init_with_timeout_ratio(int *param_1);  /* 0x0306ad94 174B */
void ucos3_task_create_checked(undefined4 *param_1);  /* 0x0306ae44 122B */
void struct_init_typetag_and_funcptr(undefined4 *param_1);  /* 0x0306b024 36B */
void dlist_node_unlink_with_head_update(int param_1);  /* 0x0306b160 48B */
void rate_counter_init_and_task_create_dispatch(undefined4 *param_1);  /* 0x0306b1a4 200B */
void sorted_bucket_deadline_list_insert(int param_1,short param_2);  /* 0x0306b26c 228B */
void array_clear_first_field_stride8(void);  /* 0x0306b398 28B */
void soft_timer_wheel_task(void);  /* 0x0306b408 152B */
undefined4 ucos_tmr_del(int *param_1,undefined4 *param_2);  /* 0x0306b5a8 170B */
undefined4 timer_object_cancel_and_unlink(int *param_1,undefined4 *param_2);  /* 0x0306b65c 180B */
uint padded_block_total_size_with_overflow_guard();  /* 0x0306b960 162B */
void memset_with_word_alignment_const0h_fwd(undefined4 param_1,undefined4 param_2);  /* 0x0306bafc 12B */
int scheduler_locked_padded_block_alloc(uint param_1,int param_2,uint *param_3,undefined4 *param_4);  /* 0x0306bc60 202B */
void queue_capacity_query_discard_result(undefined4 param_1,undefined4 param_2);  /* 0x0306bde0 16B */
void flash_block_alloc_with_overflow_guard(undefined4 *param_1,uint param_2,int param_3,uint param_4,int param_5,int param_6, uint *param_7,int *param_8);  /* 0x0306be3c 868B */
void saturating_sub_or_full_and_stamp_0x27d8(void);  /* 0x0306c12c 48B */
int queue_count_get(int *param_1,undefined4 *param_2);  /* 0x0306c1ec 86B */
undefined4 queue_entry_peek_reverse(int *param_1,int param_2,undefined4 *param_3);  /* 0x0306c308 158B */
void strlen_unbounded(undefined4 param_1);  /* 0x0306c988 12B */
void strcpy_unbounded(undefined4 param_1,undefined4 param_2);  /* 0x0306c9f8 12B */
undefined2 strcmp_unbounded(undefined4 param_1,undefined4 param_2);  /* 0x0306cb3c 14B */
undefined2 strcmp_null_safe_unbounded(undefined4 param_1,undefined4 param_2);  /* 0x0306cc38 14B */
void strchr_unbounded(undefined4 param_1,undefined1 param_2);  /* 0x0306cca0 14B */
void reverse_char_search_bounded_constffffffffh_fwd(undefined4 param_1,undefined1 param_2);  /* 0x0306ccf8 14B */
int bounded_range_search_first_match(int param_1,int param_2,int param_3);  /* 0x0306cd54 136B */
void bounded_range_search_first_match_constffffffffh_fwd(undefined4 param_1,undefined4 param_2);  /* 0x0306cddc 12B */
void integer_to_radix_string_format_const0h_fwd(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4, undefined1 param_5,undefined1 param_6,undefined4 param_7);  /* 0x0306cde8 42B */
void integer_to_radix_string_signed(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4, undefined1 param_5,undefined1 param_6,undefined4 param_7);  /* 0x0306ce14 58B */
void strtoul_ascii_to_uint_radix_const0h_0h_fwd(undefined4 param_1,undefined4 param_2,undefined1 param_3);  /* 0x0306ce50 18B */
uint strtol_ascii_saturating(undefined4 param_1,undefined4 param_2,undefined1 param_3);  /* 0x0306ce64 56B */
void timer_ch0_periodic_start_store_mhz(void);  /* 0x0306cea4 36B */
void timer_ch0_configure_periodic(undefined4 param_1,uint param_2);  /* 0x0306cef4 26B */
void timer0_rtos_tick_isr(void);  /* 0x0306cf20 14B */
void irq_table_fill_and_enable_irq_0x21(void);  /* 0x0306cfe4 34B */
int soft_double_divide_or_reciprocal_series();  /* 0x0306d014 954B */
uint soft_double_to_int_round_trunc_variant();  /* 0x0306d448 166B */
uint soft_double_to_int_round_ceil_variant();  /* 0x0306d5b0 170B */
undefined4 soft_double_modulo_or_remainder();  /* 0x0306d8f0 170B */
void soft_double_poly_horner(int param_1,int param_2,undefined4 param_3,undefined4 param_4);  /* 0x0306dd70 64B */
undefined4 softdouble_piecewise_poly_eval(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5);  /* 0x0306ddb0 356B */
void soft_double_rational_poly_eval_with_denorm_branch(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4);  /* 0x0306df30 362B */
uint softdouble_divide_guarded();  /* 0x0306e0c0 638B */
int mutex_guarded_call_wrapper();  /* 0x0306e344 46B */
void decimal_string_pair_to_fixed(undefined4 param_1,undefined4 param_2);  /* 0x0306e678 232B */
uint atoi_clamped();  /* 0x0306e838 96B */
void float32_pack_const_two(int param_1);  /* 0x0306e8c4 30B */
void add_64(undefined4 param_1,undefined4 param_2,uint param_3,int param_4);  /* 0x0306f0fc 108B */
void softdouble_pack_round_wrapper(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5);  /* 0x0306f428 40B */
void softdouble_extract_exponent_mantissa();  /* 0x0306f450 66B */
void soft_double_pack_constant_two();  /* 0x0306f494 44B */
void float32_pack_round_from_4args(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);  /* 0x0306f81c 22B */
uint soft_double_pack_and_round();  /* 0x0306f834 744B */
void soft_double_unpack(uint *param_1,uint *param_2);  /* 0x0306fb30 198B */
uint shift_right_64(uint param_1,uint param_2,uint param_3);  /* 0x0306fca8 40B */
int shift_left_64(int param_1,undefined4 param_2,uint param_3);  /* 0x0306fcd0 40B */
void number_to_string_format_2args();  /* 0x0306fcf8 26B */
void number_to_string_format(undefined4 param_1,undefined4 param_2,undefined4 param_3);  /* 0x0306fd14 18B */
void strtod(undefined4 param_1);  /* 0x0306fd28 10B */
void heap_calloc_zeroed(int param_1,int param_2);  /* 0x0306fe54 28B */
void * malloc_copy_source_range_checked(void *param_1,int param_2);  /* 0x0306fe70 42B */
undefined4 pow10_decimal_exponent();  /* 0x0306fecc 66B */
undefined4 * strtol_signed(byte *param_1,undefined4 *param_2,int param_3);  /* 0x0307014c 288B */
int strncmp_ck803s(byte *param_1,byte *param_2,int param_3);  /* 0x03070618 36B */
uint strbuf_append_bounded(void *param_1,uint param_2,int *param_3);  /* 0x03070684 62B */
void snprintf_numeric_to_buffer(int param_1,uint param_2,undefined4 param_3,undefined4 param_4);  /* 0x030706c4 92B */
int abs_int(int v);  /* 0x03071068 6B */
uint strtol_buffered(byte *param_1,undefined4 *param_2,int param_3);  /* 0x03071070 244B */
undefined4 lookup_table_get_or_default(uint param_1);  /* 0x03071168 18B */
char * double_to_decimal_string();  /* 0x03071184 1046B */
undefined4 three_way_compare();  /* 0x030715c4 32B */
byte coord_pair_matches_stored(int param_1,int param_2);  /* 0x030715e4 48B */
uint int64_to_decimal_string(byte *param_1,int param_2,int param_3,int param_4,int param_5,char param_6);  /* 0x03071618 192B */
uint uint_to_hex_string(char *param_1,int param_2,uint param_3,uint param_4,int param_5);  /* 0x030716d8 132B */
uint fixed_16_16_divide(uint param_1,uint param_2,uint param_3,uint param_4);  /* 0x03071814 980B */
void stub_trap_halt_baddata(void);  /* 0x030bf698 16B */
void irq_snapshot_sat_sub_a(void);  /* 0x030bfe10 22B */
undefined4 irq_take_and_clear_u32_global(void);  /* 0x030bfe28 26B */
void irq_snapshot_sat_sub_b(void);  /* 0x030bfe44 22B */
void ucos3_name_set_checked(int param_1,undefined4 *param_2);  /* 0x030bfeb8 80B */
void ucos3_name_get_16(int param_1,undefined4 *param_2);  /* 0x030bff2c 60B */
void ucos3_sched_locked_op16(void);  /* 0x030bff68 32B */
void thin_wrapper_to_030c0000();  /* 0x030c004c 8B */
int lowest_set_bit_from_top_u8(byte param_1);  /* 0x030c0158 28B */
int lowest_set_bit_from_top_u16(ushort param_1);  /* 0x030c0174 28B */
void ucos3_highrdy_commit(void);  /* 0x030c01de 42B */
void ucos3_int_highrdy_commit(void);  /* 0x030c0206 30B */
void word_buffer_clear_set_end_b(void);  /* 0x030c02fc 44B */
void flag_value_pair_set_default(char param_1,int param_2,undefined4 *param_3);  /* 0x030c05d8 76B */
void radio_bringup_mem_partition_0x3f();  /* 0x030c0674 58B */
void queued_slot_tag_match_a(int param_1,int param_2,undefined4 param_3);  /* 0x030c06b0 52B */
void owner_slot_array_init_b(int param_1,undefined4 *param_2,short param_3);  /* 0x030c06e4 46B */
void pend_list_insert_by_prio_b(undefined4 *param_1,int *param_2);  /* 0x030c07d8 108B */
void list_node_unlink_c(undefined4 *param_1,int *param_2);  /* 0x030c0844 60B */
void pend_list_drain_and_clear(int param_1);  /* 0x030c0880 42B */
void queued_slot_tag_match_b(int param_1,int param_2,undefined4 param_3);  /* 0x030c08f0 52B */
void slot_table_find_and_store_b(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5);  /* 0x030c0924 64B */
void slot_list_table_clear_64(void);  /* 0x030c0964 24B */
void radio_device_state_reset_and_bringup(int *param_1);  /* 0x030c097c 298B */
void slot_list_push_front_b(int param_1);  /* 0x030c0b0c 96B */
void slot_list_push_back_b(int param_1);  /* 0x030c0b6c 84B */
void queued_event_list_swap_or_rotate_head(int *param_1);  /* 0x030c0be8 60B */
void activity_timer_handle_dispatch_complete(int *param_1);  /* 0x030c0ee8 158B */
void queued_timer_event_dispatch_if_not_flagged(int param_1);  /* 0x030c102c 28B */
void queued_event_dispatch_immediate_or_deferred(int param_1,int param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5);  /* 0x030c1048 180B */
void queued_event_dispatch_immediate_or_deferred_simple(int param_1,int param_2,undefined4 param_3);  /* 0x030c118c 150B */
void settings_block_command_dispatch(void);  /* 0x030c12c4 318B */
void command_queue_worker_loop(void);  /* 0x030c145c 142B */
int timed_task_teardown_with_status_report(int *param_1,undefined4 param_2,short param_3,int *param_4,undefined4 *param_5);  /* 0x030c1678 420B */
void obj_slot_claim_checked(int *param_1,int param_2,undefined4 *param_3);  /* 0x030c192c 104B */
void list_register_push_front_c(int param_1);  /* 0x030c19bc 30B */
void dlist_unlink_radio_variant(int param_1);  /* 0x030c1a74 48B */
undefined4 identifier_matched_command_dispatch_030c1cfc(int *param_1,ushort param_2,undefined4 *param_3);  /* 0x030c1cfc 136B */
void channel_frequency_or_dmr_mode_configure(int param_1,byte param_2,undefined4 *param_3);  /* 0x030c1d8c 398B */
undefined4 ucos3_tcb_word_0x7c_get(int param_1,char param_2,undefined4 *param_3);  /* 0x030c2284 60B */
bool critical_flag_try_claim(undefined4 *param_1);  /* 0x030c22c0 66B */
void ucos3_tcb_word_0x7c_set(int param_1,char param_2,undefined4 param_3,undefined4 *param_4);  /* 0x030c2304 58B */
int timed_task_advance_with_timestamp_delta_tracking(undefined4 param_1,short param_2,undefined4 *param_3,undefined4 *param_4);  /* 0x030c2340 390B */
undefined4 typed_message_validate_and_dispatch_030c24d8(int param_1,short param_2,undefined4 *param_3);  /* 0x030c24d8 234B */
void registry_list_push_front_b(int param_1);  /* 0x030c2728 34B */
void event_post_checked_isr_aware(undefined4 param_1,undefined4 param_2,undefined2 param_3,ushort param_4, undefined4 *param_5);  /* 0x030c2dec 112B */
void command_send_task_or_isr_queue(int param_1,undefined4 *param_2);  /* 0x030c2f88 100B */
undefined4 ucos_event_post_or_queue_isr_aware(undefined4 param_1,short param_2,undefined4 *param_3);  /* 0x030c3284 84B */
void radio_command_submit_isr_aware(int param_1,undefined4 *param_2);  /* 0x030c3414 72B */
void clear_slot_table_records_variant2(void);  /* 0x030c3470 36B */
void mem_partition_config_validate_and_register(undefined4 *param_1);  /* 0x030c3494 114B */
void queued_event_list_unlink();  /* 0x030c3668 58B */
void expired_timer_queue_entries_process(void);  /* 0x030c36c0 376B */
void timer_expiry_task(void);  /* 0x030c3854 40B */
void command_dispatch_with_guard_flags_variant_030c388c(int param_1,ushort param_2,int *param_3);  /* 0x030c388c 242B */
void dmr_channel_frequency_validate_and_commit(uint param_1,uint param_2,uint param_3,uint param_4,ushort param_5,int *param_6);  /* 0x030c3980 460B */
undefined4 ucos3_cs_shared_word_read(undefined4 *param_1);  /* 0x030c3cf8 36B */
void ucos3_cs_shared_word_write(undefined4 param_1,undefined4 *param_2);  /* 0x030c3d1c 36B */
void bounded_queue_enqueue_fetched_value(void);  /* 0x030c3d48 48B */
byte bitbang_serial_byte_read_with_strobe(char param_1);  /* 0x030c3e2c 248B */
undefined4 bitbang_bus_scan_buffer_for_match(undefined1 param_1,undefined1 param_2,int param_3,uint param_4);  /* 0x030c4044 216B */
undefined4 companion_chip_serial_command_sequence(byte param_1,undefined1 param_2,int param_3,int param_4);  /* 0x030c411c 404B */
void dmr_type_s_scramble_permute_block(byte *param_1);  /* 0x030c458c 2234B */
void ccitt_crc4_stream_update();  /* 0x030c5038 94B */
void tri_word_bitfield_pack_into_byte_buffer(uint *param_1,int param_2,byte param_3);  /* 0x030c5098 242B */
void dmr_27byte_block_keyed_scramble(int param_1,int param_2,uint param_3);  /* 0x030c5414 140B */
void dmr_27byte_block_keyed_descramble(int param_1,int param_2,uint param_3);  /* 0x030c54a0 150B */
void dmr_privacy_mi_embedded_encode(uint param_1,uint *param_2);  /* 0x030c5790 100B */
void modem_boot_selftest_and_init(undefined1 *param_1);  /* 0x030c59ac 120B */
void channel_offset_pair_set_first(short param_1);  /* 0x030c5a34 26B */
void channel_offset_pair_set_second(short param_1);  /* 0x030c5a50 26B */
void channel_offset_pair_alt_set_first(short param_1);  /* 0x030c5a6c 26B */
void channel_offset_pair_alt_set_second(short param_1);  /* 0x030c5a88 26B */
void channel_record_triple_decode_to_table_thunk();  /* 0x030c5c50 8B */
void dmr_27byte_block_transform_three_chunks_thunk();  /* 0x030c5c58 8B */
void indexed_ramp_field_store_c(undefined4 param_1,uint param_2);  /* 0x030c5c60 34B */
void indexed_ramp_field_store_d(undefined4 param_1,uint param_2);  /* 0x030c5c84 34B */
undefined4 grid_draw_checked_timed_a(uint param_1,undefined4 param_2,uint param_3,int param_4);  /* 0x030c5dc8 100B */
undefined4 grid_draw_checked_timed_b(uint param_1,undefined4 param_2,uint param_3,int param_4);  /* 0x030c5e2c 100B */
undefined4 identifier_matched_dispatch_mode0(undefined4 param_1);  /* 0x030c5eb4 20B */
void modem_codec_pool_and_state_init(undefined1 *param_1);  /* 0x030c5ec8 712B */
void channel_record_dualbuffer_diff_commit(void);  /* 0x030c62d8 374B */
void dmr_27byte_block_transform_three_chunks();  /* 0x030c6458 88B */
void channel_record_triple_decode_to_table();  /* 0x030c64b0 306B */
void vframe_message_poll_and_dispatch_3x();  /* 0x030c67fc 148B */
undefined2 channel_buffer_prepare_or_passthrough(undefined4 param_1,short param_2,undefined4 param_3,short param_4,short param_5, short param_6,int param_7);  /* 0x030c68fc 132B */
undefined4 codec_level_id_store_and_scale(int param_1,short param_2,short param_3);  /* 0x030c6980 46B */
void dmr_state_init_with_lcg_fill(int param_1,short param_2);  /* 0x030c69b0 116B */
void tone_squelch_detection_frame_dispatch(int param_1,undefined4 param_2,int param_3,ushort param_4,short param_5);  /* 0x030c6a24 308B */
undefined4 channel_tx_rx_offset_set(int param_1,short param_2,short param_3);  /* 0x030c6be0 48B */
void channel_signaling_param_struct_defaults_init(int param_1,short param_2,short param_3);  /* 0x030c6c10 486B */
void tone_squelch_candidate_select_and_lock(int param_1,undefined4 param_2,short param_3,uint param_4,short param_5, short param_6);  /* 0x030c6f4c 258B */
uint ones_complement_checksum_32word(int param_1,uint param_2);  /* 0x030c7254 58B */
bool dmr_channel_params_equal(short param_1,short param_2,short param_3,int param_4,short param_5,short param_6, short param_7,short param_8,short param_9,short param_10);  /* 0x030c7318 184B */
void tone_code_best_of4_score_argmax(int *param_1,short *param_2,int param_3,short *param_4);  /* 0x030c73d0 64B */
short tone_squelch_code_match_search(undefined2 *param_1,int param_2,short param_3,short param_4,int param_5, short param_6);  /* 0x030c7410 1642B */
uint best_match_index_search_by_cost_metric();  /* 0x030c7d24 224B */
uint lookup_table_sequence_processor(undefined4 param_1,short param_2,short param_3);  /* 0x030c7e5c 118B */
ushort vocoder_frame_params_decode(int param_1,short param_2,undefined4 param_3,short param_4,ushort param_5, int *param_6);  /* 0x030c7edc 644B */
undefined4 channel_record_copy_0x34(int param_1,int param_2);  /* 0x030c84c4 46B */
undefined2 channel_list_string_render_field();  /* 0x030c855c 176B */
void fixed_point_signed_divide_16bit(uint param_1,undefined4 param_2,short param_3,undefined4 param_4,undefined2 *param_5);  /* 0x030c8b14 136B */
bool fixed_point_exp_aligned_less_than(int param_1,int param_2,int param_3,int param_4);  /* 0x030c8bb8 50B */
uint table_lookup_linear_interpolate_9bit_index(int param_1);  /* 0x030c8c20 54B */
int cubic_polynomial_fixedpoint_interpolator(uint param_1,short *param_2);  /* 0x030c8de0 186B */
uint fixedpoint_polynomial_coefficient_evaluate(int param_1,short param_2,short param_3);  /* 0x030c8ea0 224B */
undefined4 dmr_message_checksum_verify_and_status_resolve(undefined4 param_1,short param_2,ushort param_3,short param_4,short *param_5, undefined4 param_6,int param_7);  /* 0x030c9378 500B */
ushort dmr_signaling_param_block_build_and_dispatch(undefined4 param_1,short param_2,ushort param_3,undefined2 param_4,int param_5, ushort param_6);  /* 0x030c956c 538B */
short fixed_point_windowed_correlation_or_convolution(int param_1,undefined4 param_2,int param_3,short param_4,ushort param_5, short param_6,int param_7,short param_8,short param_9);  /* 0x030c978c 334B */
void dmr_filter_block_init_defaults(undefined2 *param_1);  /* 0x030c9920 54B */
void display_buffer_command_dispatch(short *param_1);  /* 0x030c9958 128B */
void channel_buffer_frame_process(short *param_1,undefined4 param_2,short param_3,short param_4,int param_5);  /* 0x030c99d8 992B */
void clamped_table_entry_update();  /* 0x030c9f24 302B */
undefined4 calibration_fingerprint_compare_and_reset(short *param_1,short *param_2,short param_3);  /* 0x030ca0e8 240B */
undefined4 channel_tone_or_offset_buffer_build(undefined2 *param_1,short param_2,ushort param_3,uint param_4,short param_5);  /* 0x030ca1e0 910B */
undefined4 level_scale_by_category_with_offset(short *param_1,short param_2,ushort param_3);  /* 0x030ca578 142B */
void channel_window_slot_rotate();  /* 0x030ca608 196B */
void int16_array_sum_saturating_div(short *param_1,short param_2);  /* 0x030ca738 32B */
void tone_squelch_delay_line_shift();  /* 0x030cb390 152B */
undefined4 log_domain_sample_decode_with_energy_clamp(int param_1,int param_2);  /* 0x030cc8e8 242B */
void rotate_uint32_bytes(int param_1,int param_2);  /* 0x030ccae4 56B */
void aes_inv_shift_rows(void);  /* 0x030ccba8 36B */
void check_stack_value_halt_if_positive(void);  /* 0x030cd33c 42B */
void fixed_point_freq_scale_and_accumulate_into_buffer(int param_1,int param_2,short param_3,short param_4,ushort *param_5,short param_6);  /* 0x030cd610 880B */
void channel_signaling_block_16a2_defaults(int param_1,short param_2,short param_3,short param_4);  /* 0x030ce47c 96B */
char companion_auth_challenge_response_verify(int param_1,int param_2);  /* 0x030cf58c 1238B */
undefined4 signaling_subblock_defaults_init(short param_1,undefined4 param_2,undefined2 *param_3);  /* 0x030cfc68 106B */
void tone_squelch_detection_frame_process(int param_1,int param_2,short param_3,undefined4 param_4,short param_5,int param_6, short param_7,short *param_8,undefined4 param_9);  /* 0x030d01d8 2178B */
void tone_squelch_state_history_update();  /* 0x030d13ec 1402B */
void lcg_conditional_reflect_u16_array(short *param_1,short param_2,short param_3,short param_4);  /* 0x030d1c00 68B */

/* ---- RAW (238 functions) ---- */

void FUN_000101e8(undefined4 param_1);  /* 0x000101e8 6B */
void FUN_000101f4(void);  /* 0x000101f4 1B */
void FUN_000105b4(void);  /* 0x000105b4 4B */
void FUN_000105b8(void);  /* 0x000105b8 38B */
void FUN_00010708();  /* 0x00010708 14B */
void FUN_00010738(void);  /* 0x00010738 14B */
void FUN_000107bc();  /* 0x000107bc 2B */
void FUN_00010b3c();  /* 0x00010b3c 12B */
void FUN_00010b58();  /* 0x00010b58 90B */
void FUN_00010b6c(int param_1,int param_2);  /* 0x00010b6c 26B */
void FUN_00010c98();  /* 0x00010c98 52B */
void FUN_00010ccc(void);  /* 0x00010ccc 4B */
void FUN_00011a34(uint param_1);  /* 0x00011a34 30B */
void FUN_00011cf4();  /* 0x00011cf4 24B */
void FUN_00011d38();  /* 0x00011d38 10B */
undefined4 FUN_0001232c();  /* 0x0001232c 149B */
undefined4 FUN_0001265c();  /* 0x0001265c 6B */
undefined4 FUN_00012688();  /* 0x00012688 24B */
void FUN_00012a4c();  /* 0x00012a4c 10B */
void FUN_00012a58();  /* 0x00012a58 78B */
void FUN_00013a84(void);  /* 0x00013a84 28B */
void FUN_000141c0();  /* 0x000141c0 8B */
void FUN_00015bd4(char param_1,char *param_2);  /* 0x00015bd4 256B */
void FUN_00015ea0(void);  /* 0x00015ea0 14B */
void FUN_00015eb0(void);  /* 0x00015eb0 14B */
void FUN_00015ef0(void);  /* 0x00015ef0 14B */
void FUN_00015f00(void);  /* 0x00015f00 24B */
void FUN_00015f30(ushort param_1,char param_2);  /* 0x00015f30 76B */
void FUN_00016000(undefined1 param_1);  /* 0x00016000 12B */
void FUN_0001600c(char param_1);  /* 0x0001600c 34B */
void FUN_00016088(void);  /* 0x00016088 38B */
void FUN_000160b0(void);  /* 0x000160b0 14B */
void FUN_000160c0(void);  /* 0x000160c0 38B */
void FUN_00016104(void);  /* 0x00016104 28B */
void FUN_00016164(undefined1 param_1);  /* 0x00016164 6B */
void FUN_00016174(undefined1 param_1);  /* 0x00016174 6B */
undefined4 FUN_000161a8(uint param_1,undefined4 param_2,uint param_3,int param_4);  /* 0x000161a8 100B */
int FUN_000172b0(void);  /* 0x000172b0 24B */
void FUN_0002b300(undefined4 param_1,undefined4 param_2,undefined1 param_3);  /* 0x0002b300 10B */
void FUN_0002b30c(undefined4 param_1,undefined4 param_2,undefined1 param_3);  /* 0x0002b30c 10B */
void FUN_0002b318();  /* 0x0002b318 8B */
void FUN_0002b320();  /* 0x0002b320 10B */
void FUN_0002b32c();  /* 0x0002b32c 10B */
void FUN_0002bb18(undefined4 param_1);  /* 0x0002bb18 16B */
int FUN_0002bde8(uint param_1,uint param_2);  /* 0x0002bde8 132B */
undefined4 FUN_0002be78(uint param_1,uint param_2,int param_3);  /* 0x0002be78 62B */
int FUN_0002beb8(uint param_1,uint param_2,int param_3);  /* 0x0002beb8 200B */
undefined4 FUN_0002bf80(void);  /* 0x0002bf80 10B */
void FUN_0002c0e0(int param_1,undefined4 param_2,undefined4 param_3);  /* 0x0002c0e0 24B */
void FUN_0002d46c(void);  /* 0x0002d46c 50B */
void FUN_0002d6a4(void);  /* 0x0002d6a4 165B */
undefined4 FUN_0002dea4(undefined4 param_1);  /* 0x0002dea4 16B */
byte FUN_0002df40(void);  /* 0x0002df40 36B */
void FUN_0002e1c0(undefined4 *param_1);  /* 0x0002e1c0 12B */
void FUN_0002e1cc(undefined4 param_1);  /* 0x0002e1cc 6B */
undefined4 FUN_0300185c(undefined1 param_1);  /* 0x0300185c 12B */
void FUN_03001868();  /* 0x03001868 10B */
undefined4 FUN_03001c14(uint param_1,int param_2);  /* 0x03001c14 56B */
void FUN_03001ca8(void);  /* 0x03001ca8 26B */
int FUN_030020ec(uint param_1);  /* 0x030020ec 4B */
void FUN_03002100(void);  /* 0x03002100 22B */
undefined4 FUN_0300211c(void);  /* 0x0300211c 26B */
void FUN_03002208(void);  /* 0x03002208 8B */
void FUN_03002210(void);  /* 0x03002210 38B */
void FUN_03002324(void);  /* 0x03002324 2B */
void FUN_03002360();  /* 0x03002360 2B */
void FUN_03002364();  /* 0x03002364 2B */
void FUN_03002368();  /* 0x03002368 118B */
void FUN_030023e4(void);  /* 0x030023e4 38B */
void FUN_03002414(void);  /* 0x03002414 2B */
void FUN_0300294c(int param_1);  /* 0x0300294c 40B */
void FUN_03002fbc(void);  /* 0x03002fbc 8B */
void FUN_03002ff4(uint param_1);  /* 0x03002ff4 30B */
void FUN_03003018(uint param_1);  /* 0x03003018 30B */
void FUN_0300303c(undefined4 *param_1);  /* 0x0300303c 12B */
void FUN_0300327c(undefined4 *param_1);  /* 0x0300327c 16B */
void FUN_03003294(undefined4 *param_1);  /* 0x03003294 82B */
void FUN_03003cc4(uint param_1);  /* 0x03003cc4 64B */
undefined4 FUN_03003d30(int param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4);  /* 0x03003d30 42B */
undefined4 FUN_03003d5c(uint param_1,int param_2,int param_3,undefined1 *param_4);  /* 0x03003d5c 116B */
void FUN_030040d8(void);  /* 0x030040d8 28B */
bool FUN_030042a0(undefined1 *param_1);  /* 0x030042a0 30B */
undefined1 FUN_030042c0(void);  /* 0x030042c0 34B */
void FUN_0300455c(void);  /* 0x0300455c 30B */
undefined4 FUN_03004580(undefined4 param_1,int param_2);  /* 0x03004580 34B */
undefined4 FUN_030045a4();  /* 0x030045a4 44B */
void FUN_0300460c();  /* 0x0300460c 10B */
void FUN_0300491c(undefined1 *param_1,undefined1 *param_2,byte param_3,uint param_4);  /* 0x0300491c 120B */
void FUN_0300c0e4();  /* 0x0300c0e4 2B */
void FUN_0300c0e8(void);  /* 0x0300c0e8 2B */
void FUN_0300c0f0(uint param_1,uint param_2,int param_3,uint param_4);  /* 0x0300c0f0 98B */
void FUN_0300c1bc(uint param_1,uint param_2,int param_3,uint param_4);  /* 0x0300c1bc 104B */
undefined4 FUN_0300c2c4(void);  /* 0x0300c2c4 4B */
undefined4 FUN_0300c2c8(void);  /* 0x0300c2c8 4B */
undefined4 FUN_0300d48c(void);  /* 0x0300d48c 4B */
uint FUN_0300e1c8();  /* 0x0300e1c8 38B */
int FUN_0300e1f0(uint param_1);  /* 0x0300e1f0 24B */
void FUN_0300e208(uint param_1);  /* 0x0300e208 16B */
void FUN_0300eb40(void);  /* 0x0300eb40 2B */
void FUN_03013400(void);  /* 0x03013400 146B */
void FUN_03014244(void);  /* 0x03014244 22B */
void FUN_030146f8(void);  /* 0x030146f8 52B */
void FUN_0301b558(uint param_1,undefined1 *param_2,uint *param_3);  /* 0x0301b558 66B */
void FUN_0301bfcc(void);  /* 0x0301bfcc 16B */
void FUN_0301d27c(uint param_1,int param_2,int param_3);  /* 0x0301d27c 508B */
byte FUN_0301d72c(void);  /* 0x0301d72c 10B */
void FUN_0301df04();  /* 0x0301df04 8B */
void FUN_0301e5fc();  /* 0x0301e5fc 2B */
void FUN_0301f158();  /* 0x0301f158 24B */
void FUN_0302179c(int param_1);  /* 0x0302179c 28B */
void FUN_03021b24(undefined1 param_1,undefined1 param_2);  /* 0x03021b24 40B */
void FUN_03021b60(char param_1);  /* 0x03021b60 30B */
int FUN_03023110(int param_1,int param_2);  /* 0x03023110 24B */
void FUN_03023914(void);  /* 0x03023914 14B */
void FUN_03023a58(void);  /* 0x03023a58 12B */
bool FUN_03023ae8(void);  /* 0x03023ae8 12B */
void FUN_03024f00(void);  /* 0x03024f00 14B */
bool FUN_030273f4(void);  /* 0x030273f4 12B */
void FUN_03028c76(void);  /* 0x03028c76 2B */
void FUN_030294cc(void);  /* 0x030294cc 42B */
void FUN_03029ce8(void);  /* 0x03029ce8 34B */
void FUN_0302fc64(void);  /* 0x0302fc64 108B */
void FUN_030300e8(void);  /* 0x030300e8 52B */
void FUN_03036224(void);  /* 0x03036224 60B */
void FUN_03036ca8(void);  /* 0x03036ca8 116B */
void FUN_0303cafc(void);  /* 0x0303cafc 6B */
void FUN_0303cb4e(void);  /* 0x0303cb4e 6B */
void FUN_03054980(void);  /* 0x03054980 28B */
void FUN_0305f620(int param_1,uint param_2);  /* 0x0305f620 94B */
void FUN_0305f680(int param_1,uint param_2);  /* 0x0305f680 96B */
void FUN_0305f9c8(int param_1,int param_2,uint param_3);  /* 0x0305f9c8 44B */
void FUN_03060280(void);  /* 0x03060280 48B */
undefined4 FUN_03066a4c(void);  /* 0x03066a4c 140B */
void FUN_03068d6c(undefined4 *param_1);  /* 0x03068d6c 22B */
void FUN_03069544(undefined4 *param_1);  /* 0x03069544 110B */
void FUN_030695b4(undefined4 *param_1);  /* 0x030695b4 58B */
void FUN_03069cdc(undefined4 *param_1);  /* 0x03069cdc 34B */
bool FUN_0306b76c(char param_1);  /* 0x0306b76c 14B */
bool FUN_0306b78c(char param_1);  /* 0x0306b78c 14B */
bool FUN_0306b824(char param_1);  /* 0x0306b824 14B */
char FUN_0306b8c8(char param_1);  /* 0x0306b8c8 18B */
char FUN_0306b8dc(char param_1);  /* 0x0306b8dc 18B */
byte FUN_0306b8f0(undefined1 param_1,undefined1 param_2);  /* 0x0306b8f0 24B */
byte FUN_0306b908(int param_1,uint param_2);  /* 0x0306b908 86B */
int FUN_0306ba04(int param_1,uint param_2,uint param_3);  /* 0x0306ba04 78B */
char * FUN_0306ca04(char *param_1,char *param_2,uint param_3);  /* 0x0306ca04 106B */
void FUN_0306ca70(undefined4 param_1,undefined4 param_2);  /* 0x0306ca70 12B */
char * FUN_0306cd08(char *param_1,char param_2,char param_3,int param_4);  /* 0x0306cd08 58B */
void FUN_0306cd44(undefined4 param_1,undefined1 param_2,undefined1 param_3);  /* 0x0306cd44 16B */
undefined4 FUN_0306ce9c(void);  /* 0x0306ce9c 6B */
void FUN_0306cec8(void);  /* 0x0306cec8 10B */
undefined4 FUN_0306cf38(uint param_1,int param_2);  /* 0x0306cf38 56B */
void FUN_0306cfc8(void);  /* 0x0306cfc8 26B */
void FUN_030bfdd4(void);  /* 0x030bfdd4 2B */
void FUN_030bfdd8(void);  /* 0x030bfdd8 8B */
void FUN_030bfde4(undefined4 *param_1);  /* 0x030bfde4 36B */
void FUN_030bff88(void);  /* 0x030bff88 76B */
undefined1 FUN_030bffd4(uint param_1);  /* 0x030bffd4 12B */
uint FUN_030bffe0(uint param_1);  /* 0x030bffe0 32B */
uint FUN_030c0054(uint param_1,uint param_2);  /* 0x030c0054 190B */
int FUN_030c01ac(uint param_1,uint param_2);  /* 0x030c01ac 38B */
void FUN_030c01d8(void);  /* 0x030c01d8 38B */
void FUN_030c02ec(void);  /* 0x030c02ec 14B */
void FUN_030c0328(void);  /* 0x030c0328 14B */
void FUN_030c0338();  /* 0x030c0338 14B */
void FUN_030c0348(void);  /* 0x030c0348 14B */
void FUN_030c0358();  /* 0x030c0358 14B */
void FUN_030c0368();  /* 0x030c0368 110B */
void FUN_030c03e0(void);  /* 0x030c03e0 4B */
void FUN_030c0474(void);  /* 0x030c0474 14B */
void FUN_030c0754(int param_1,int param_2);  /* 0x030c0754 56B */
void FUN_030c078c(int param_1,int param_2);  /* 0x030c078c 26B */
void FUN_030c07a8(undefined4 *param_1);  /* 0x030c07a8 10B */
void FUN_030c08b8(int param_1,undefined1 param_2);  /* 0x030c08b8 56B */
void FUN_030c0bc0(int param_1);  /* 0x030c0bc0 40B */
void FUN_030c0c24(undefined4 *param_1);  /* 0x030c0c24 152B */
void FUN_030c1600(void);  /* 0x030c1600 10B */
void FUN_030c1634(uint param_1);  /* 0x030c1634 30B */
void FUN_030c1654(uint param_1);  /* 0x030c1654 30B */
void FUN_030c19a4(undefined4 *param_1);  /* 0x030c19a4 24B */
void FUN_030c1bf8(undefined4 *param_1);  /* 0x030c1bf8 14B */
void FUN_030c2790(undefined4 *param_1);  /* 0x030c2790 18B */
void FUN_030c27a4(undefined4 *param_1);  /* 0x030c27a4 182B */
void FUN_030c2ffc(void);  /* 0x030c2ffc 24B */
void FUN_030c3d84();  /* 0x030c3d84 26B */
void FUN_030c3dac(uint param_1);  /* 0x030c3dac 50B */
void FUN_030c3de8(void);  /* 0x030c3de8 62B */
void FUN_030c4310(int param_1,int param_2,uint param_3);  /* 0x030c4310 76B */
void FUN_030c4438(int param_1,int param_2,uint param_3);  /* 0x030c4438 70B */
uint FUN_030c4524(byte *param_1);  /* 0x030c4524 104B */
void FUN_030c5ba4(undefined4 param_1);  /* 0x030c5ba4 32B */
undefined1 FUN_030c5d8c(void);  /* 0x030c5d8c 6B */
void FUN_030c61e0(void);  /* 0x030c61e0 86B */
void FUN_030c6238(void);  /* 0x030c6238 128B */
void FUN_030c66f0(void);  /* 0x030c66f0 82B */
void FUN_030c6774(undefined1 param_1);  /* 0x030c6774 10B */
void FUN_030c68c4(int param_1,int param_2);  /* 0x030c68c4 56B */
uint FUN_030c6e24(uint param_1);  /* 0x030c6e24 56B */
undefined4 FUN_030c6e5c(int param_1,ushort param_2);  /* 0x030c6e5c 50B */
void FUN_030c6e90(void);  /* 0x030c6e90 40B */
int FUN_030c6eb8(void);  /* 0x030c6eb8 24B */
int FUN_030c6ed0(void);  /* 0x030c6ed0 24B */
void FUN_030c6f18(int param_1,undefined1 *param_2,short param_3);  /* 0x030c6f18 44B */
short FUN_030c7050(undefined2 *param_1,undefined2 *param_2,int param_3,short param_4,short param_5,short param_6);  /* 0x030c7050 166B */
void FUN_030c7144();  /* 0x030c7144 86B */
undefined4 FUN_030c7290();  /* 0x030c7290 108B */
bool FUN_030c7ce0(short *param_1,undefined2 *param_2,int param_3);  /* 0x030c7ce0 68B */
void FUN_030c7e04(undefined4 param_1,int param_2,short param_3);  /* 0x030c7e04 26B */
ushort FUN_030c7ed4(undefined4 param_1,short param_2,undefined4 param_3,short param_4);  /* 0x030c7ed4 4B */
ushort FUN_030c7ed8(undefined4 param_1,short param_2,undefined4 param_3,short param_4);  /* 0x030c7ed8 4B */
ushort FUN_030c81c8(void);  /* 0x030c81c8 1B */
void FUN_030c8610();  /* 0x030c8610 14B */
void FUN_030c864c();  /* 0x030c864c 74B */
void FUN_030c87ec(undefined4 param_1,undefined4 param_2,ushort *param_3,short param_4);  /* 0x030c87ec 88B */
void FUN_030c8c5c(void);  /* 0x030c8c5c 4B */
void FUN_030c8ce0();  /* 0x030c8ce0 4B */
void FUN_030c8f84();  /* 0x030c8f84 8B */
uint FUN_030c9000(int param_1,short param_2,short param_3);  /* 0x030c9000 46B */
short FUN_030ca098(uint param_1,ushort param_2,short param_3);  /* 0x030ca098 74B */
void FUN_030ca758(int *param_1,uint *param_2,int param_3);  /* 0x030ca758 32B */
void FUN_030ca778();  /* 0x030ca778 80B */
void FUN_030ca7fc();  /* 0x030ca7fc 6B */
void FUN_030ca8ec();  /* 0x030ca8ec 6B */
void FUN_030ca9c0(undefined4 param_1,int param_2,short param_3,undefined2 *param_4);  /* 0x030ca9c0 100B */
void FUN_030caa34(int param_1,short param_2,int *param_3,short param_4,ushort param_5);  /* 0x030caa34 140B */
void FUN_030caaec(undefined4 param_1,int param_2,short param_3,undefined2 *param_4);  /* 0x030caaec 126B */
void FUN_030cab7c(int param_1,int param_2,short param_3,short param_4,short param_5);  /* 0x030cab7c 80B */
void FUN_030cac00();  /* 0x030cac00 1380B */
undefined4 FUN_030cc8c4(int param_1,short param_2);  /* 0x030cc8c4 36B */
void FUN_030ccb1c(void);  /* 0x030ccb1c 46B */
void FUN_030ccb4c(void);  /* 0x030ccb4c 60B */
undefined4 FUN_030cd0e8(undefined2 *param_1,short *param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6,short param_7,short param_8,short param_9,short param_10);  /* 0x030cd0e8 326B */
void FUN_030cda30();  /* 0x030cda30 1636B */
uint fixedpoint_level_gain_select(int param_1,int param_2,short *param_3);  /* 0x030ce380 252B */
undefined2 FUN_030cfbc0(int param_1);  /* 0x030cfbc0 4B */
void FUN_030cfe48();  /* 0x030cfe48 274B */
uint dmr_block_decode_tag6_dispatch(short *param_1,undefined4 param_2,short *param_3,uint param_4,int param_5, undefined4 param_6,short param_7,undefined4 param_8,int param_9,short *param_10, undefined4 param_11,undefined4 param_12,short param_13);  /* 0x030cff5c 392B */
void FUN_030d1ce0(int param_1);  /* 0x030d1ce0 20B */

#endif /* DM32_FUNCTIONS_H */
