# rtos

172 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 109 |
| STRUCTURAL | 63 |
| RAW | 0 |

## Subdirectories

This subsystem is large enough to be split a second level. Grouping key: shared name prefix.

| Directory | Files |
|---|---|
| `timer/` | 35 |
| `cyclic/` | 10 |
| `mutex/` | 10 |
| `rtc/` | 10 |
| _(subsystem root)_ | 107 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x000105be` | `OSCtxSw` | 42 | CONFIRMED |
| `0x000105e6` | `OSIntCtxSw` | 30 | CONFIRMED |
| `0x00010894` | `OSIntEnter` | 26 | CONFIRMED |
| `0x000108b0` | `OSIntExit` | 130 | CONFIRMED |
| `0x00010934` | `OSSched` | 92 | CONFIRMED |
| `0x00010c60` | `queue_list_process_and_reset` | 42 | STRUCTURAL |
| `0x00010f4c` | `timer_object_register_into_bucket_list` | 84 | STRUCTURAL |
| `0x00010fc8` | `os_rdylist_move_head_to_tail` | 60 | CONFIRMED |
| `0x00011190` | `OSSchedLock` | 92 | CONFIRMED |
| `0x00011250` | `OSSchedUnlock` | 118 | CONFIRMED |
| `0x000114dc` | `sched_obj_state_reset_and_unlink` | 140 | STRUCTURAL |
| `0x00011a58` | `OSSemPend` | 402 | CONFIRMED |
| `0x00011dbc` | `OSSemCreate` | 152 | CONFIRMED |
| `0x00011e84` | `OSSemDel` | 306 | CONFIRMED |
| `0x000120dc` | `OSSemPost` | 135 | CONFIRMED |
| `0x00012190` | `OSTaskChangePrio` | 362 | CONFIRMED |
| `0x000126a0` | `OSTaskRegGetID` | 66 | CONFIRMED |
| `0x00012720` | `OSTaskSemPend` | 390 | CONFIRMED |
| `0x000129f4` | `OSTaskStkChk` | 88 | CONFIRMED |
| `0x00012dd8` | `OSTaskCreate` | 504 | CONFIRMED |
| `0x00013368` | `OSTaskResume` | 100 | CONFIRMED |
| `0x00013664` | `OSTaskSemPost` | 84 | CONFIRMED |
| `0x000137f4` | `OSTaskSuspend` | 72 | CONFIRMED |
| `0x00013a48` | `dll_node_remove` | 58 | STRUCTURAL |
| `0x00013c6c` | `OSTimeDly` | 242 | CONFIRMED |
| `0x00013d60` | `OSTimeDlyHMSM` | 460 | CONFIRMED |
| `0x00013fb6` | `OSTimeDlyResume_dly_arm` | 90 | CONFIRMED |
| `0x00014046` | `OSTimeDlyResume_dly_suspended_arm` | 86 | CONFIRMED |
| `0x00014128` | `OSTimeTick` | 48 | CONFIRMED |
| `0x03002464` | `OSIntExit_variant2` | 120 | CONFIRMED |
| `0x0300256c` | `lazy_device_descriptor_init_once` | 68 | CONFIRMED |
| `0x03002704` | `timer_wheel_bucket_drain_and_reset` | 42 | CONFIRMED |
| `0x03002978` | `timer_list_swap_or_rotate_head` | 60 | STRUCTURAL |
| `0x03003804` | `timer_entry_insert_hash_bucketed_list_0300` | 296 | CONFIRMED |
| `0x0300393c` | `timer_list_unlink_node` | 58 | STRUCTURAL |
| `0x03003ad8` | `timer_wheel_tick_task` | 40 | STRUCTURAL |
| `0x0300c464` | `OSFlagPend_wrapper_consume` | 48 | STRUCTURAL |
| `0x0300c494` | `OSFlagPost_wrapper_set` | 20 | STRUCTURAL |
| `0x0300c4a8` | `OSFlagPost_wrapper_clr` | 20 | STRUCTURAL |
| `0x0300c4bc` | `OSTimeDly_ms_wrapper` | 24 | CONFIRMED |
| `0x0300c4d4` | `OSSemCreate_shared_name_wrapper` | 22 | CONFIRMED |
| `0x0300c500` | `os_sem_pend_ms` | 30 | CONFIRMED |
| `0x0300c53c` | `os_sem_post` | 20 | CONFIRMED |
| `0x0300c5e4` | `timer_state_ensure_valid_or_recreate` | 134 | STRUCTURAL |
| `0x0300c66c` | `osmbox_post_candidate2_on_check` | 36 | STRUCTURAL |
| `0x0300c6a0` | `osmbox_post_candidate2_on_check_0300c768` | 10 | STRUCTURAL |
| `0x0300c6bc` | `osmbox_post_candidate2_on_check_0300c770` | 10 | STRUCTURAL |
| `0x0300c6d8` | `osmbox_post_candidate2_on_check_0300c778` | 10 | STRUCTURAL |
| `0x0300c6f4` | `osmbox_post_candidate2_on_check_0300c780` | 10 | STRUCTURAL |
| `0x0300c700` | `osflag_pend_consume_with_decisecond_timeout` | 34 | CONFIRMED |
| `0x0300c724` | `OSFlagPost_wrapper_set_fixed_grp` | 12 | STRUCTURAL |
| `0x0300c730` | `os_flag_post_clear_0300c784` | 12 | CONFIRMED |
| `0x0300c73c` | `osflag_pend_consume_with_decisecond_timeout_alt` | 34 | CONFIRMED |
| `0x0300c78c` | `OSFlagPost_wrapper_set_passthrough` | 12 | STRUCTURAL |
| `0x0300c798` | `os_flag_post_clear_0300c8d4` | 12 | CONFIRMED |
| `0x0300c7a4` | `osflag_pend_consume_generic` | 28 | CONFIRMED |
| `0x0300c7c0` | `OSFlagPost_wrapper_set_fixed_grp_variant_0300c7c0` | 12 | STRUCTURAL |
| `0x0300c7cc` | `os_flag_post_clear_0300c8d8` | 12 | CONFIRMED |
| `0x0300c820` | `mutex_pend_with_timeout_0300c8e0` | 12 | CONFIRMED |
| `0x0300c838` | `ossem_pend_txslot` | 12 | CONFIRMED |
| `0x0300c868` | `mutex_pend_with_timeout_0300c8ec` | 12 | CONFIRMED |
| `0x0300c874` | `osflag_post_clear_three_groups` | 34 | CONFIRMED |
| `0x0300cd6c` | `periodic_task_and_queue_create_0x180` | 66 | CONFIRMED |
| `0x0300e49c` | `task_body_uCOS3` | 146 | CONFIRMED |
| `0x0300f7ac` | `mutex_guarded_param_dispatch_1` | 48 | STRUCTURAL |
| `0x03010680` | `mutex_guarded_param_dispatch_2` | 52 | STRUCTURAL |
| `0x03010818` | `mutex_guarded_param_dispatch_3` | 46 | STRUCTURAL |
| `0x03010db8` | `mutex_guarded_call3_wrapper` | 36 | STRUCTURAL |
| `0x03010ddc` | `mutex_guarded_call_generic3arg` | 36 | CONFIRMED |
| `0x03013178` | `write_field_and_mbox_post` | 68 | STRUCTURAL |
| `0x030141e0` | `poll_condition_group` | 46 | STRUCTURAL |
| `0x03015b24` | `poll_condition_group_and_schedule_ui_tick` | 138 | STRUCTURAL |
| `0x0301b9dc` | `tick_counter_and_event_log` | 88 | STRUCTURAL |
| `0x0301c2d4` | `rtc_register_read` | 26 | CONFIRMED |
| `0x0301c2f0` | `rtc_decode_calendar_date` | 354 | CONFIRMED |
| `0x0301c454` | `rtc_reg_0x11_set_bit1` | 22 | STRUCTURAL |
| `0x0301c46c` | `rtc_reg11_clear_bit1` | 20 | STRUCTURAL |
| `0x0301c480` | `rtc_register_0x11_set_bit2` | 22 | CONFIRMED |
| `0x0301c498` | `rtc_date_validate_and_write` | 322 | CONFIRMED |
| `0x0301c5ec` | `rtc_reg17_pulse_low_25ms` | 26 | STRUCTURAL |
| `0x0301c608` | `rtc_validate_and_set_default_datetime` | 102 | CONFIRMED |
| `0x0301d740` | `timer_channel_enable_dispatch` | 14 | CONFIRMED |
| `0x0301d754` | `timer_ch0_enable` | 12 | CONFIRMED |
| `0x0301d760` | `timer_ch1_enable` | 12 | CONFIRMED |
| `0x0301d76c` | `timer_ch2_enable` | 12 | CONFIRMED |
| `0x0301d778` | `timer_ch3_enable` | 12 | CONFIRMED |
| `0x0301d784` | `timer_ch4_enable` | 10 | CONFIRMED |
| `0x0301d78e` | `timer_channel_enable_noop_stub` | 2 | CONFIRMED |
| `0x0301d790` | `timer_channel_readwrite_dispatch` | 14 | CONFIRMED |
| `0x0301d7a4` | `timer_ch0_write_period` | 8 | CONFIRMED |
| `0x0301d7ac` | `timer_ch1_write_period` | 8 | CONFIRMED |
| `0x0301d7b4` | `timer_ch2_write_period` | 8 | CONFIRMED |
| `0x0301d7bc` | `timer_ch3_write_period` | 8 | CONFIRMED |
| `0x0301d7c4` | `timer_ch4_write_period` | 6 | CONFIRMED |
| `0x0301d7ca` | `timer_readwrite_noop_stub1` | 2 | CONFIRMED |
| `0x0301d7e0` | `timer_ch0_read_status` | 8 | CONFIRMED |
| `0x0301d7e8` | `timer_ch1_read_status` | 8 | CONFIRMED |
| `0x0301d7f0` | `timer_ch2_read_status` | 8 | CONFIRMED |
| `0x0301d7f8` | `timer_ch3_read_status` | 8 | CONFIRMED |
| `0x0301d800` | `timer_ch4_read_status` | 8 | CONFIRMED |
| `0x0301d808` | `timer_readwrite_noop_stub2` | 2 | CONFIRMED |
| `0x0301d920` | `timer_ch1_disable` | 12 | CONFIRMED |
| `0x0301d958` | `timer_channel_enable_dispatch_arg5h` | 10 | STRUCTURAL |
| `0x03022e68` | `wait_for_status_byte_clear` | 42 | STRUCTURAL |
| `0x03023900` | `mutex_pend_forever_count_loop` | 20 | STRUCTURAL |
| `0x0302aa3c` | `rtc_chip_response_poll_and_date_apply` | 170 | CONFIRMED |
| `0x0303240c` | `task_codesw_entry` | 40 | CONFIRMED |
| `0x03035c38` | `reentrant_state_reset_sequence` | 282 | CONFIRMED |
| `0x030487a0` | `cyclic_value_step` | 40 | CONFIRMED |
| `0x03048918` | `cyclic_step_duration_display_linear` | 22 | STRUCTURAL |
| `0x030489f0` | `cyclic_step_duration_display_scaled` | 26 | STRUCTURAL |
| `0x03048a64` | `cyclic_step_0xc0_dir1_and_display` | 22 | STRUCTURAL |
| `0x03048b28` | `cyclic_step_0xff_and_refresh` | 20 | STRUCTURAL |
| `0x03048c3c` | `cyclic_step_duration_display_wrapping` | 22 | STRUCTURAL |
| `0x03048cfc` | `duration_seconds_cycle_0to49_from3_step0_and_menu_offset` | 22 | STRUCTURAL |
| `0x03048d12` | `cyclic_value_step_counter_settings_offset` | 26 | STRUCTURAL |
| `0x03048d2c` | `cyclic_ms_display_and_text_cursor_advance` | 22 | STRUCTURAL |
| `0x03048d7a` | `cyclic_step_0xc0_and_display` | 22 | STRUCTURAL |
| `0x03048dd8` | `duration_seconds_cycle_0to49_step0_and_menu_offset_alt` | 22 | STRUCTURAL |
| `0x03048dee` | `duration_seconds_cycle_0to39_from5_and_menu_offset_alt` | 22 | STRUCTURAL |
| `0x03048e04` | `duration_seconds_cycle_0to99_from5_and_menu_offset` | 22 | STRUCTURAL |
| `0x03048e1a` | `cyclic_step_0x14_and_seconds_display` | 22 | STRUCTURAL |
| `0x03048e30` | `byte_value_cycle_0to255_and_menu_offset` | 20 | STRUCTURAL |
| `0x03048ef4` | `rtc_date_decode_to_bcd_display_buffer` | 98 | CONFIRMED |
| `0x0305e318` | `event_flags_dispatch_bit8_group` | 420 | CONFIRMED |
| `0x0305e694` | `event_flags_dispatch_bit4_group` | 278 | CONFIRMED |
| `0x0305e9f8` | `event_flags1_group_dispatch` | 74 | CONFIRMED |
| `0x0305eb78` | `event_flags2_group_dispatch` | 74 | CONFIRMED |
| `0x0305ed30` | `event_flags9_dispatch_and_name_encode` | 198 | STRUCTURAL |
| `0x0305edfc` | `event_flags14_dispatch_hw_and_flaggrp` | 90 | STRUCTURAL |
| `0x03060e30` | `mutex_pend_no_timeout_03060f1c` | 12 | CONFIRMED |
| `0x030686a4` | `ucos3_message_broadcast_dispatcher` | 256 | CONFIRMED |
| `0x03068814` | `OSFlagPend` | 180 | CONFIRMED |
| `0x030688c8` | `os_flag_group_ready_bits_apply_or_error` | 20 | STRUCTURAL |
| `0x030688dc` | `os_flag_wait_and_dispatch` | 1138 | STRUCTURAL |
| `0x030690e4` | `OSFlagPost_internal` | 448 | CONFIRMED |
| `0x030692ac` | `OSFlagPost` | 128 | CONFIRMED |
| `0x03069334` | `OSMemGet` | 84 | CONFIRMED |
| `0x03069388` | `OSMemPut` | 96 | CONFIRMED |
| `0x03069404` | `os_queue_create_and_register` | 274 | CONFIRMED |
| `0x030695f0` | `critical_section_struct_init` | 16 | CONFIRMED |
| `0x03069738` | `scheduled_task_state_advance_with_queue_promotion` | 598 | STRUCTURAL |
| `0x030699d0` | `os_sched_op_dispatch_with_lock_timing` | 256 | CONFIRMED |
| `0x03069ae0` | `scheduled_task_advance_or_requeue` | 484 | STRUCTURAL |
| `0x03069d20` | `OSMutexCreate` | 160 | CONFIRMED |
| `0x0306a100` | `sched_lock_unlock_with_max_duration_tracking` | 184 | CONFIRMED |
| `0x0306a3ac` | `os_sched_op_dispatch_with_lock_timing_variant2` | 256 | CONFIRMED |
| `0x0306a500` | `critical_section_counted_init_dispatch` | 168 | STRUCTURAL |
| `0x0306a870` | `os_post_message_opt_validated` | 178 | CONFIRMED |
| `0x0306b078` | `OSTmrCreate` | 232 | CONFIRMED |
| `0x0306b3b4` | `timer_list_entry_unlink` | 82 | CONFIRMED |
| `0x0306b4a0` | `OSTmr_state_dispatch_callback` | 234 | CONFIRMED |
| `0x0306b65c` | `timer_object_cancel_and_unlink` | 180 | STRUCTURAL |
| `0x0306bc60` | `scheduler_locked_padded_block_alloc` | 202 | STRUCTURAL |
| `0x0306cea4` | `timer_ch0_periodic_start_store_mhz` | 36 | STRUCTURAL |
| `0x0306cef4` | `timer_ch0_configure_periodic` | 26 | STRUCTURAL |
| `0x0306e344` | `mutex_guarded_call_wrapper` | 46 | STRUCTURAL |
| `0x030c0624` | `OSStart` | 68 | CONFIRMED |
| `0x030c0880` | `pend_list_drain_and_clear` | 42 | STRUCTURAL |
| `0x030c0be8` | `queued_event_list_swap_or_rotate_head` | 60 | STRUCTURAL |
| `0x030c0db0` | `OSSchedLock_variant2` | 92 | CONFIRMED |
| `0x030c0e70` | `OSSchedUnlock_variant2` | 118 | CONFIRMED |
| `0x030c182c` | `os_sched_op_dispatch_with_lock_timing_variant3` | 256 | CONFIRMED |
| `0x030c19dc` | `OSSemCreate_variant2` | 152 | CONFIRMED |
| `0x030c25d0` | `OSTaskSemSet` | 66 | CONFIRMED |
| `0x030c2614` | `OSTaskStkChk_variant2` | 178 | CONFIRMED |
| `0x030c26c8` | `OSTaskTimeQuantaSet` | 82 | CONFIRMED |
| `0x030c29f8` | `OSTaskCreate_variant2` | 504 | CONFIRMED |
| `0x030c3508` | `timer_entry_insert_hash_bucketed_list_030c` | 296 | CONFIRMED |
| `0x030c3668` | `queued_event_list_unlink` | 58 | STRUCTURAL |
| `0x030c3854` | `timer_expiry_task` | 40 | STRUCTURAL |
| `0x030c3b58` | `OSTimeDlyResume` | 110 | CONFIRMED |
