/*
 * Source binary: DM32.00.01.048.bin (whole image, load base 0x03000000)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Generated output - DO NOT EDIT BY HAND; regenerate instead.
 * Confidence: STRUCTURAL (bytes exact; each pool's owning function is inferred by adjacency)
 */

/* Inline lrw constant pools. On CK803S the compiler parks `lrw` constants in the middle of the
 * function that loads them, so these regions sit BETWEEN fragments of a single function body and
 * are not shared tables. They are emitted because they resolve what a function actually loads:
 * mostly IRAM global addresses (0x0001xxxx-0x0005xxxx) and flash string/data pointers.
 * 371 pools, 15268 bytes.
 */
#include <stdint.h>

/* 030021a4-030021b8 20 bytes  pool of OS_SchedLockTimeMeasStop_variant2 @0300216c */
const uint32_t dm32_pool_030021a4[5] = {
    0x00017060,  /* IRAM */
    0x00017064,  /* IRAM */
    0x0001705c,  /* IRAM */
    0x00017068,  /* IRAM */
    0x00017054,  /* IRAM */
};

/* 030024dc-030024fc 32 bytes  pool of OSIntExit_variant2 @03002464 */
const uint32_t dm32_pool_030024dc[8] = {
    0x00016d4d,  /* IRAM */
    0x00016e44,  /* IRAM */
    0x00016d4c,  /* IRAM */
    0x00016db4,  /* IRAM */
    0x00016d50,  /* IRAM */
    0x00016e38,  /* IRAM */
    0x00016e30,  /* IRAM */
    0x00016e40,  /* IRAM */
};

/* 030025b0-030025c8 24 bytes  pool of lazy_device_descriptor_init_once @0300256c */
const uint32_t dm32_pool_030025b0[6] = {
    0x00016d4d,  /* IRAM */
    0x00016db4,  /* IRAM */
    0x00016db5,  /* IRAM */
    0x00016d50,  /* IRAM */
    0x00016e38,  /* IRAM */
    0x00016e30,  /* IRAM */
};

/* 03002848-03002888 64 bytes  pool of radio_device_state_reset_and_bringup_variant @0300278c */
const uint32_t dm32_pool_03002848[16] = {
    0x00016e44,  /* IRAM */
    0x00016d4d,  /* IRAM */
    0x00016d4c,  /* IRAM */
    0x00016e30,  /* IRAM */
    0x00016e38,  /* IRAM */
    0x00016db5,  /* IRAM */
    0x00016db4,  /* IRAM */
    0x00016e36,  /* IRAM */
    0x00016e2c,  /* IRAM */
    0x00016f44,  /* IRAM */
    0x00016e3c,  /* IRAM */
    0x00016f4c,  /* IRAM */
    0x03001ef0,  /* flash data */
    0x00016f30,  /* IRAM */
    0x03001ec0,  /* flash data */
    0x03001ebc,  /* flash data */
};

/* 03002a74-03002a84 16 bytes  pool of queued_task_event_dispatch_with_counter @03002a4c */
const uint32_t dm32_pool_03002a74[4] = {
    0x00016db4,  /* IRAM */
    0x00016e38,  /* IRAM */
    0x00016ebc,  /* IRAM */
    0x00016e40,  /* IRAM */
};

/* 0300392c-0300393c 16 bytes  pool of timer_entry_insert_hash_bucketed_list_0300 @03003804 */
const uint32_t dm32_pool_0300392c[4] = {
    0x00016f34,  /* IRAM */
    0x03001f08,  /* flash data */
    0x00016684,  /* IRAM */
    0x00016688,  /* IRAM */
};

/* 03003ac4-03003ad8 20 bytes  pool of OS_TickListUpdate @03003978 */
const uint32_t dm32_pool_03003ac4[5] = {
    0x00016d4c,  /* IRAM */
    0x00016f34,  /* IRAM */
    0x03001f08,  /* flash data */
    0x00016684,  /* IRAM */
    0x00016f4e,  /* IRAM */
};

/* 0300c8d4-0300c904 48 bytes  pool of ucos3_task_create_prio25_stk0x100 @0300c898 */
const uint32_t dm32_pool_0300c8d4[12] = {
    0x00038314,  /* IRAM */
    0x00036f30,  /* IRAM */
    0x00035f28,  /* IRAM */
    0x0003644c,  /* IRAM */
    0x00035f50,  /* IRAM */
    0x00037820,  /* IRAM */
    0x00035f00,  /* IRAM */
    0x00036570,  /* IRAM */
    0x000346a4,  /* IRAM */
    0x00037020,  /* IRAM */
    0x03076778,  /* flash data */
    0x0301fe80,  /* flash code */
};

/* 0300d548-0300d568 32 bytes  pool of rf_chip_init_and_spawn_worker_tasks @0300d4b0 */
const uint32_t dm32_pool_0300d548[8] = {
    0x00038590,  /* IRAM */
    0x0002f6a8,  /* IRAM */
    0x000384c8,  /* IRAM */
    0x03076984,  /* flash data */
    0x03060754,  /* flash code */
    0x000385c0,  /* IRAM */
    0x03076994,  /* flash data */
    0x0300dc94,  /* flash code */
};

/* 0300ddec-0300de10 36 bytes  pool of dmr_rf_tx_task @0300dc94 */
const uint32_t dm32_pool_0300ddec[9] = {
    0x00038590,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x00038464,  /* IRAM */
    0x0003fd90,  /* IRAM */
    0x0003e1c0,  /* IRAM */
    0x00038470,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 0300e0e0-0300e0f8 24 bytes  pool of int_to_double_divide_convert @0300df5c */
const uint32_t dm32_pool_0300e0e0[6] = {
    0x03076944,  /* flash data */
    0x000385b8,  /* IRAM */
    0x0003fde4,  /* IRAM */
    0x000384c0,  /* IRAM */
    0x00038470,  /* IRAM */
    0x000384b4,  /* IRAM */
};

/* 0300f020-0300f03c 28 bytes  pool of fd6818b_status_register_poll_with_reinit @0300eea4 */
const uint32_t dm32_pool_0300f020[7] = {
    0x0003fdb8,  /* IRAM */
    0x00038690,  /* IRAM */
    0x00038694,  /* IRAM */
    0x0002feb1,  /* IRAM */
    0x00038692,  /* IRAM */
    0x0003868a,  /* IRAM */
    0x0003868e,  /* IRAM */
};

/* 0300f678-0300f6ac 52 bytes  pool of flash_page_find_first_free @0300f624 */
const uint32_t dm32_pool_0300f678[13] = {
    0x030adb0c,  /* flash data */
    0x000386a3,  /* IRAM */
    0x030adb10,  /* flash data */
    0x000386a2,  /* IRAM */
    0x030adb30,  /* flash data */
    0x00038698,  /* IRAM */
    0x000386a0,  /* IRAM */
    0x0003ffc8,  /* IRAM */
    0x0003ffd0,  /* IRAM */
    0x0003ffbc,  /* IRAM */
    0x0003ffd4,  /* IRAM */
    0x0003944c,  /* IRAM */
    0x030adb14,  /* flash data */
};

/* 030105b4-030105d0 28 bytes  pool of flash_record_commit_4field @030100a8 */
const uint32_t dm32_pool_030105b4[7] = {
    0x0003944c,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x0003ff80,  /* IRAM */
    0x00039474,  /* IRAM */
    0x0003ffc4,  /* IRAM */
    0x00039475,  /* IRAM */
};

/* 03010b30-03010b40 16 bytes  pool of channel_list_compact_and_delete_entry @03010978 */
const uint32_t dm32_pool_03010b30[4] = {
    0x0003944c,  /* IRAM */
    0x0003ffc4,  /* IRAM */
    0x00039474,  /* IRAM */
    0x0003869c,  /* IRAM */
};

/* 03011608-0301163c 52 bytes  pool of peripheral_gpio_and_buffer_init @03011588 */
const uint32_t dm32_pool_03011608[13] = {
    0x03081ddc,  /* flash data */
    0x03081de4,  /* flash data */
    0x03081dec,  /* flash data */
    0x03081df4,  /* flash data */
    0x03081e60,  /* flash data */
    0x03081e64,  /* flash data */
    0x00038c6c,  /* IRAM */
    0x0002ff80,  /* IRAM */
    0x00038d48,  /* IRAM */
    0x0002ff88,  /* IRAM */
    0x00038ba4,  /* IRAM */
    0x03081e74,  /* flash data */
    0x03011824,  /* flash code */
};

/* 03011998-030119a8 16 bytes  pool of serial_rx_ringbuffer_line_extract @030118b0 */
const uint32_t dm32_pool_03011998[4] = {
    0x0003fd90,  /* IRAM */
    0x00038c6c,  /* IRAM */
    0x0002ff80,  /* IRAM */
    0x000386a4,  /* IRAM */
};

/* 03011b20-03011b40 32 bytes  pool of gps_coordinate_table_entry_parse @03011aa4 */
const uint32_t dm32_pool_03011b20[8] = {
    0x0002ff80,  /* IRAM */
    0x00038c6c,  /* IRAM */
    0x00038aa4,  /* IRAM */
    0x03081e0c,  /* flash data */
    0x00038d48,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00038c79,  /* IRAM */
    0x030b8b28,  /* flash data */
};

/* 03011ed4-03011ef0 28 bytes  pool of radio_telemetry_format_dispatch @03011d24 */
const uint32_t dm32_pool_03011ed4[7] = {
    0x00038c6c,  /* IRAM */
    0x00038c79,  /* IRAM */
    0x03081dfc,  /* flash data */
    0x03081e5c,  /* flash data */
    0x03081ec4,  /* flash data */
    0x03081ecc,  /* flash data */
    0x03081e9c,  /* flash data */
};

/* 030120b4-030120d4 32 bytes  pool of radio_telemetry_format_dispatch @03011d24 */
const uint32_t dm32_pool_030120b4[8] = {
    0x00038c6c,  /* IRAM */
    0x00038c79,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e8f4,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x03081f78,  /* flash data */
};

/* 03012640-0301265c 28 bytes  pool of menu_list_scroll_advance_and_redraw @03012390 */
const uint32_t dm32_pool_03012640[7] = {
    0x0003e5cc,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x03081f77,  /* flash data */
    0x03081f78,  /* flash data */
    0x0003e5fb,  /* IRAM */
};

/* 03012924-0301294c 40 bytes  pool of gps_nmea_rmc_gga_sentence_parser @03012758 */
const uint32_t dm32_pool_03012924[10] = {
    0x0002ff80,  /* IRAM */
    0x00038c6c,  /* IRAM */
    0x00038d48,  /* IRAM */
    0x000386a4,  /* IRAM */
    0x03081ed0,  /* flash data */
    0x03081ed8,  /* flash data */
    0x03081ee0,  /* flash data */
    0x00038c79,  /* IRAM */
    0x00038d28,  /* IRAM */
    0x03081e04,  /* flash data */
};

/* 03012ab8-03012ae0 40 bytes  pool of gps_nmea_rmc_gga_sentence_parser @03012758 */
const uint32_t dm32_pool_03012ab8[10] = {
    0x00038c6c,  /* IRAM */
    0x0002ff80,  /* IRAM */
    0x000386a4,  /* IRAM */
    0x00038c79,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x03081ee8,  /* flash data */
    0x03081ef0,  /* flash data */
    0x03081ef8,  /* flash data */
    0x00038d48,  /* IRAM */
};

/* 03012cfc-03012d10 20 bytes  pool of gps_nmea_rmc_gga_sentence_parser @03012758 */
const uint32_t dm32_pool_03012cfc[5] = {
    0x00038c6c,  /* IRAM */
    0x000386a4,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x030b8ab0,  /* flash data */
    0x0003e9b4,  /* IRAM */
};

/* 03012e58-03012e84 44 bytes  pool of main_ptt_and_channel_event_loop @03012d10 */
const uint32_t dm32_pool_03012e58[11] = {
    0x0003a4f0,  /* IRAM */
    0x00030388,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003ffdc,  /* IRAM */
    0x00040238,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003ecc0,  /* IRAM */
};

/* 030131bc-030131e4 40 bytes  pool of write_field_and_mbox_post @03013178 */
const uint32_t dm32_pool_030131bc[10] = {
    0x00038e24,  /* IRAM */
    0x000392cc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x18000834,
    0x000392c8,  /* IRAM */
    0x00038fc0,  /* IRAM */
    0x00030388,  /* IRAM */
    0x00038d70,  /* IRAM */
    0x00038fc1,  /* IRAM */
    0x00038e29,  /* IRAM */
};

/* 03013540-03013568 40 bytes  pool of tx_gate_write_call_record @030134c4 */
const uint32_t dm32_pool_03013540[10] = {
    0x0003e1dc,  /* IRAM */
    0x0003e1c0,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x00038e20,  /* IRAM */
    0x00030388,  /* IRAM */
    0x18000800,
    0x0003fdb8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00038e2c,  /* IRAM */
    0x0003e9b4,  /* IRAM */
};

/* 03013828-03013854 44 bytes  pool of keypad_poll_and_dispatch_key_event @03013744 */
const uint32_t dm32_pool_03013828[11] = {
    0x00038e28,  /* IRAM */
    0x03081f1c,  /* flash data */
    0x00039344,  /* IRAM */
    0x18000800,
    0x00030388,  /* IRAM */
    0x000392c4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003ff84,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x000392cd,  /* IRAM */
};

/* 03013bcc-03013c0c 64 bytes  pool of main_ui_background_task_loop @03013a3c */
const uint32_t dm32_pool_03013bcc[16] = {
    0x0003fdb8,  /* IRAM */
    0x00038e20,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ff84,  /* IRAM */
    0x0003fd90,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e135,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x000400c0,  /* IRAM */
    0x000400a8,  /* IRAM */
    0x00038688,  /* IRAM */
    0x000320af,  /* IRAM */
    0x18000a90,
    0x0003e13a,  /* IRAM */
};

/* 03013dd8-03013e0c 52 bytes  pool of main_ui_background_task_loop @03013a3c */
const uint32_t dm32_pool_03013dd8[13] = {
    0x0003e134,  /* IRAM */
    0x03081f48,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x030ba200,  /* flash data */
    0x0003e1ac,  /* IRAM */
    0x0003e13b,  /* IRAM */
    0x0003fdcc,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003e1bc,  /* IRAM */
    0x0003ee34,  /* IRAM */
    0x0309fd34,  /* flash data */
    0x030ba638,  /* flash data */
};

/* 03014090-030140a8 24 bytes  pool of keypad_key_allowed_by_bitmask_a @03014060 */
const uint32_t dm32_pool_03014090[6] = {
    0x0003fd2c,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003bd50,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x44e00031,
};

/* 030141d0-030141e0 16 bytes  pool of keypad_key_allowed_by_bitmask_mode_dependent @0301412c */
const uint32_t dm32_pool_030141d0[4] = {
    0x0003e1dc,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x02380617,
    0x0003e144,  /* IRAM */
};

/* 03014344-03014360 28 bytes  pool of conditional_mbox_post_0x12 @0301425c */
const uint32_t dm32_pool_03014344[7] = {
    0x0003fdc8,  /* IRAM */
    0x000392cd,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x000320af,  /* IRAM */
    0x18000a90,
    0x0003e5d8,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 030144a8-030144c8 32 bytes  pool of tx_state_poll_and_teardown @03014360 */
const uint32_t dm32_pool_030144a8[8] = {
    0x00030798,  /* IRAM */
    0x000392cd,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x0003ff38,  /* IRAM */
    0x000392d4,  /* IRAM */
    0x000392d0,  /* IRAM */
};

/* 0301472c-03014748 28 bytes  pool of FUN_030146f8 @030146f8 */
const uint32_t dm32_pool_0301472c[7] = {
    0x0003fdb8,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x000392d4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x000392d0,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x000320ae,  /* IRAM */
};

/* 03014898-030148b8 32 bytes  pool of dialog_idle_gate_post_key_0x1f @03014838 */
const uint32_t dm32_pool_03014898[8] = {
    0x0003fdb8,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x000392d4,  /* IRAM */
    0x000392d0,  /* IRAM */
    0x0003ff38,  /* IRAM */
    0x0003fdc8,  /* IRAM */
};

/* 030151ec-0301520c 32 bytes  pool of vfo_freq_display_refresh @03015050 */
const uint32_t dm32_pool_030151ec[8] = {
    0x0003e144,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x00040120,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 03015394-030153c8 52 bytes  pool of ui_key_and_menu_event_dispatch_loop @030152cc */
const uint32_t dm32_pool_03015394[13] = {
    0x00040238,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003ffdc,  /* IRAM */
    0x0003ba20,  /* IRAM */
    0x0003a4f0,  /* IRAM */
    0x0003fd90,  /* IRAM */
    0x00030798,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x000392d8,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x03016280,  /* flash code */
};

/* 03015560-03015570 16 bytes  pool of vfo_ab_display_redraw_dispatch @030154a0 */
const uint32_t dm32_pool_03015560[4] = {
    0x03016280,  /* flash code */
    0x0003e9b4,  /* IRAM */
    0x03081f50,  /* flash data */
    0x0003e318,  /* IRAM */
};

/* 03015600-03015610 16 bytes  pool of vfo_ab_display_redraw_dispatch @030154a0 */
const uint32_t dm32_pool_03015600[4] = {
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x03081f58,  /* flash data */
    0x0003e144,  /* IRAM */
};

/* 0301579c-030157c4 40 bytes  pool of ui_event_0x21_conditional_notify @0301564c */
const uint32_t dm32_pool_0301579c[10] = {
    0x0003fdb8,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdc0,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba220,  /* flash data */
};

/* 03015c64-03015c94 48 bytes  pool of record_switch_toggle @03015bb0 */
const uint32_t dm32_pool_03015c64[12] = {
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030bbc28,  /* flash data */
    0x0003fdc8,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003fdc0,  /* IRAM */
    0x0003ff84,  /* IRAM */
    0x0003bd38,  /* IRAM */
    0x0003e120,  /* IRAM */
    0x000334c0,  /* IRAM */
    0x030b8388,  /* flash data */
};

/* 03015dc4-03015de0 28 bytes  pool of vfo_channel_step_on_key_event @03015d0c */
const uint32_t dm32_pool_03015dc4[7] = {
    0x000334c0,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8388,  /* flash data */
    0x0003e318,  /* IRAM */
    0x0003943f,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x000320af,  /* IRAM */
};

/* 03016498-030164b0 24 bytes  pool of tx_timeout_tick_and_status_refresh @030163d4 */
const uint32_t dm32_pool_03016498[6] = {
    0x0003e318,  /* IRAM */
    0x0003e45f,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x00040104,  /* IRAM */
};

/* 030165d8-030165f4 28 bytes  pool of fm_radio_seek_up_gated_handler @0301641c */
const uint32_t dm32_pool_030165d8[7] = {
    0x00040114,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e1bc,  /* IRAM */
    0x0003e1dc,  /* IRAM */
};

/* 03016774-0301679c 40 bytes  pool of scan_entry_status_update_tone_aware @030165f4 */
const uint32_t dm32_pool_03016774[10] = {
    0x0003e318,  /* IRAM */
    0x0003e45f,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030bbc30,  /* flash data */
    0x18000a90,
    0x0003fdb8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e5d8,  /* IRAM */
};

/* 03016914-03016930 28 bytes  pool of dialog_pending_commit_and_post @030168c0 */
const uint32_t dm32_pool_03016914[7] = {
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x000392d8,  /* IRAM */
};

/* 03016afc-03016b18 28 bytes  pool of scan_list_flash_load_and_build @03016944 */
const uint32_t dm32_pool_03016afc[7] = {
    0x000392d8,  /* IRAM */
    0x03015678,  /* flash code */
    0x000392d4,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x000392d0,  /* IRAM */
    0x1800090c,
};

/* 030173f8-03017414 28 bytes  pool of channel_step_forward_or_notify_0x21 @030173d8 */
const uint32_t dm32_pool_030173f8[7] = {
    0x0003fdc0,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ff84,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003fdc8,  /* IRAM */
};

/* 030177b8-030177f4 60 bytes  pool of channel_record_commit @0301765c */
const uint32_t dm32_pool_030177b8[15] = {
    0x0003e0c0,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e1bc,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030bb900,  /* flash data */
    0x030ba1b0,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003ee98,  /* IRAM */
    0x0003ed04,  /* IRAM */
    0x030b9e40,  /* flash data */
};

/* 030178cc-030178ec 32 bytes  pool of channel_record_commit @0301765c */
const uint32_t dm32_pool_030178cc[8] = {
    0x0003e9b4,  /* IRAM */
    0x030ba180,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003e318,  /* IRAM */
    0x0003ed04,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x000400d8,  /* IRAM */
};

/* 03018dc8-03018de0 24 bytes  pool of display_draw_list_row @03018cd8 */
const uint32_t dm32_pool_03018dc8[6] = {
    0x03081f80,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x030b0790,  /* flash data */
    0x03081f70,  /* flash data */
    0x18000a90,
    0x00039344,  /* IRAM */
};

/* 0301904c-03019074 40 bytes  pool of vfo_standby_row_render @03018ed0 */
const uint32_t dm32_pool_0301904c[10] = {
    0x00039344,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b7d58,  /* flash data */
    0x030b0790,  /* flash data */
    0x03082450,  /* flash data */
    0x0003e358,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e21c,  /* IRAM */
    0x030a8cfc,  /* flash data */
    0x030a8fa8,  /* flash data */
};

/* 030191f8-03019220 40 bytes  pool of vfo_standby_row_render @03018ed0 */
const uint32_t dm32_pool_030191f8[10] = {
    0x03082ed8,  /* flash data */
    0x0003e144,  /* IRAM */
    0x030ba718,  /* flash data */
    0x030ba758,  /* flash data */
    0x030ba738,  /* flash data */
    0x03082f40,  /* flash data */
    0x03082f7c,  /* flash data */
    0x030a7e40,  /* flash data */
    0x0003e318,  /* IRAM */
    0x03082318,  /* flash data */
};

/* 03019380-030193b4 52 bytes  pool of vfo_standby_row_render @03018ed0 */
const uint32_t dm32_pool_03019380[13] = {
    0x0003e318,  /* IRAM */
    0x030822f8,  /* flash data */
    0x03082358,  /* flash data */
    0x03082338,  /* flash data */
    0x00040120,  /* IRAM */
    0x0003fdc0,  /* IRAM */
    0x030a9464,  /* flash data */
    0x030a91dc,  /* flash data */
    0x0309facc,  /* flash data */
    0x0003ff84,  /* IRAM */
    0x030a6b00,  /* flash data */
    0x03082ec0,  /* flash data */
    0x030821b8,  /* flash data */
};

/* 03019758-03019770 24 bytes  pool of dual_plane_bitmap_icon_render @03019680 */
const uint32_t dm32_pool_03019758[6] = {
    0x000400d8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x03082f40,  /* flash data */
    0x03082f7c,  /* flash data */
    0x00039344,  /* IRAM */
};

/* 0301a520-0301a538 24 bytes  pool of display_refresh_tone_mode_icon @0301a4cc */
const uint32_t dm32_pool_0301a520[6] = {
    0x000320af,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
};

/* 0301bb14-0301bb44 48 bytes  pool of tick_counter_and_event_log @0301b9dc */
const uint32_t dm32_pool_0301bb14[12] = {
    0x0003e318,  /* IRAM */
    0x00039441,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9ed0,  /* flash data */
    0x00038470,  /* IRAM */
    0x03081ff8,  /* flash data */
    0x0003943f,  /* IRAM */
    0x03082004,  /* flash data */
    0x03082044,  /* flash data */
    0x03082104,  /* flash data */
    0x030820c4,  /* flash data */
    0x03082084,  /* flash data */
};

/* 0301c5c4-0301c5d4 16 bytes  pool of rtc_date_validate_and_write @0301c498 */
const uint32_t dm32_pool_0301c5c4[4] = {
    0x030ad9cc,  /* flash data */
    0x030ad9e4,  /* flash data */
    0x030ad9e7,  /* flash data */
    0x030ad9b8,  /* flash data */
};

/* 0301cdbc-0301cdec 48 bytes  pool of ui_inactivity_timeout_tick @0301cc68 */
const uint32_t dm32_pool_0301cdbc[12] = {
    0x0003fdc8,  /* IRAM */
    0x00040238,  /* IRAM */
    0x000309c8,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x000320af,  /* IRAM */
};

/* 0301cf4c-0301cf6c 32 bytes  pool of ui_inactivity_timeout_tick @0301cc68 */
const uint32_t dm32_pool_0301cf4c[8] = {
    0x000320af,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x000309c8,  /* IRAM */
    0x00040104,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003a4ec,  /* IRAM */
};

/* 0301d164-0301d184 32 bytes  pool of irq_boot_register_handlers_3b_to_41 @0301d128 */
const uint32_t dm32_pool_0301d164[8] = {
    0x000309c8,  /* IRAM */
    0x0002c4a4,  /* IRAM */
    0x0002c49c,  /* IRAM */
    0x0002c454,  /* IRAM */
    0x0002c3c4,  /* IRAM */
    0x0002c42c,  /* IRAM */
    0x0002c400,  /* IRAM */
    0x0002c3d4,  /* IRAM */
};

/* 0301d5dc-0301d5f8 28 bytes  pool of gpio_interrupt_enable_bit @0301d4c8 */
const uint32_t dm32_pool_0301d5dc[7] = {
    0x0003a4f0,  /* IRAM */
    0x0003fdc0,  /* IRAM */
    0x0003a648,  /* IRAM */
    0x0003a61c,  /* IRAM */
    0x0002c4cc,  /* IRAM */
    0x0002c6d8,  /* IRAM */
    0x0002c4e4,  /* IRAM */
};

/* 0301d6a8-0301d6c0 24 bytes  pool of hr_c7000_modem_core_clock_and_reset_init @0301d5f8 */
const uint32_t dm32_pool_0301d6a8[6] = {
    0x0003a5e0,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x000309e4,  /* IRAM */
    0x0003a518,  /* IRAM */
    0x030ada34,  /* flash data */
    0x0300e49c,  /* flash code */
};

/* 0301daa8-0301dacc 36 bytes  pool of uart_tx_chunked_mutex_send @0301d9d4 */
const uint32_t dm32_pool_0301daa8[9] = {
    0x0003a60c,  /* IRAM */
    0x0003b97c,  /* IRAM */
    0x0002ccc8,  /* IRAM */
    0x0003a650,  /* IRAM */
    0x00030de6,  /* IRAM */
    0x0003a64c,  /* IRAM */
    0x0003b9a6,  /* IRAM */
    0x0003b8bc,  /* IRAM */
    0x0002cc64,  /* IRAM */
};

/* 0301dc0c-0301dc1c 16 bytes  pool of i2c2_master_write_reg @0301db40 */
const uint32_t dm32_pool_0301dc0c[4] = {
    0x0003b9d0,  /* IRAM */
    0x0003b9a8,  /* IRAM */
    0x0003b9f8,  /* IRAM */
    0x0003a60c,  /* IRAM */
};

/* 0301ec08-0301ec20 24 bytes  pool of dialog_request_enqueue @0301eb70 */
const uint32_t dm32_pool_0301ec08[6] = {
    0x00033cac,  /* IRAM */
    0x0003ba9c,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003ba38,  /* IRAM */
    0x0003ba20,  /* IRAM */
    0x0003bd3c,  /* IRAM */
};

/* 0301f2f4-0301f308 20 bytes  pool of call_setup_ack_retry_and_history_log_loop @0301f1c0 */
const uint32_t dm32_pool_0301f2f4[5] = {
    0x0003bd14,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x00030df0,  /* IRAM */
    0x0003c2b6,  /* IRAM */
    0x0003c25c,  /* IRAM */
};

/* 0301f4c8-0301f4d8 16 bytes  pool of call_setup_ack_retry_and_history_log_loop @0301f1c0 */
const uint32_t dm32_pool_0301f4c8[4] = {
    0x0003c25c,  /* IRAM */
    0x0003bd14,  /* IRAM */
    0x0003c2b6,  /* IRAM */
    0x00033cac,  /* IRAM */
};

/* 0301f6c0-0301f6d0 16 bytes  pool of call_setup_ack_retry_and_history_log_loop @0301f1c0 */
const uint32_t dm32_pool_0301f6c0[4] = {
    0x0003bd14,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003ba38,  /* IRAM */
    0x0003c2b6,  /* IRAM */
};

/* 0301f8e4-0301f8f4 16 bytes  pool of call_setup_ack_retry_and_history_log_loop @0301f1c0 */
const uint32_t dm32_pool_0301f8e4[4] = {
    0x0003ba38,  /* IRAM */
    0x0003c25c,  /* IRAM */
    0x0003bd14,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 0301fb40-0301fb5c 28 bytes  pool of call_setup_ack_retry_and_history_log_loop @0301f1c0 */
const uint32_t dm32_pool_0301fb40[7] = {
    0x0003bd14,  /* IRAM */
    0x0003ba38,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003c25c,  /* IRAM */
    0x0003c2b6,  /* IRAM */
    0x0003fd20,  /* IRAM */
};

/* 0301ff7c-0301ff9c 32 bytes  pool of call_setup_connect_with_retry @0301fed0 */
const uint32_t dm32_pool_0301ff7c[8] = {
    0x0003bd14,  /* IRAM */
    0x0003ba38,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x00030df0,  /* IRAM */
    0x0003ba20,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x00040120,  /* IRAM */
    0x00040119,  /* IRAM */
};

/* 0302075c-03020778 28 bytes  pool of memcpy_from_const_0302076c @03020750 */
const uint32_t dm32_pool_0302075c[7] = {
    0x0003baa4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003c2d8,  /* IRAM */
    0x0003c2b6,  /* IRAM */
    0x0003c2bb,  /* IRAM */
    0x00a3ea83,
    0x783c8300,
};

/* 030209fc-03020a2c 48 bytes  pool of rxvoice_task_entry @03020778 */
const uint32_t dm32_pool_030209fc[12] = {
    0x00030df3,  /* IRAM */
    0x0003ba38,  /* IRAM */
    0x0003c5f8,  /* IRAM */
    0x0003be8c,  /* IRAM */
    0x0003bd2c,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x00040114,  /* IRAM */
    0x0003bd3c,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003ba20,  /* IRAM */
    0x0003f700,  /* IRAM */
};

/* 03021040-03021050 16 bytes  pool of set_status_bit_dispatch_alt_caller @03020e70 */
const uint32_t dm32_pool_03021040[4] = {
    0x0003bd3c,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003ba38,  /* IRAM */
    0x0003ba20,  /* IRAM */
};

/* 030214a8-030214cc 36 bytes  pool of voice_recorder_task @030212f4 */
const uint32_t dm32_pool_030214a8[9] = {
    0x0003bd38,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ff84,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003ba20,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003bd2c,  /* IRAM */
};

/* 030219f4-03021a14 32 bytes  pool of rx_voice_start_begin_record @03021948 */
const uint32_t dm32_pool_030219f4[8] = {
    0x0003bd50,  /* IRAM */
    0x00030e1c,  /* IRAM */
    0x0003fdc0,  /* IRAM */
    0x0003ff84,  /* IRAM */
    0x0003e120,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003bd38,  /* IRAM */
    0x00033824,  /* IRAM */
};

/* 030223e4-03022400 28 bytes  pool of flash_audio_clip_playback_pcm @030222f0 */
const uint32_t dm32_pool_030223e4[7] = {
    0x16000980,
    0x0003fd2c,  /* IRAM */
    0x160009c0,
    0x030aebfc,  /* flash data */
    0x00038698,  /* IRAM */
    0x030adb30,  /* flash data */
    0x030af1d8,  /* flash data */
};

/* 03023094-030230bc 40 bytes  pool of dtmf_ptt_event_task_loop @03023044 */
const uint32_t dm32_pool_03023094[10] = {
    0x18000800,
    0x00030790,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030af1c0,  /* flash data */
    0x030af1c4,  /* flash data */
    0x030af1c8,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x0003fd90,  /* IRAM */
    0x0003be48,  /* IRAM */
    0x0003868c,  /* IRAM */
};

/* 03023100-03023110 16 bytes  pool of tone_or_volume_step_lookup @030230bc */
const uint32_t dm32_pool_03023100[4] = {
    0x0003e1dc,  /* IRAM */
    0x0003ecfd,  /* IRAM */
    0x0003ecfc,  /* IRAM */
    0x16000900,
};

/* 03023ad8-03023ae8 16 bytes  pool of dmr_rx_deferred_frame_dispatch @03023a68 */
const uint32_t dm32_pool_03023ad8[4] = {
    0x0003be84,  /* IRAM */
    0x0003ebf0,  /* IRAM */
    0x0003fde0,  /* IRAM */
    0x0000783c,
};

/* 03023e58-03023e6c 20 bytes  pool of bitmask_table_index_lookup @03023db8 */
const uint32_t dm32_pool_03023e58[5] = {
    0x00033d60,  /* IRAM */
    0x030af498,  /* flash data */
    0x00033daf,  /* IRAM */
    0x030af497,  /* flash data */
    0x030af48f,  /* flash data */
};

/* 0302500c-03025030 36 bytes  pool of config_struct_field_write_dispatch @03024f10 */
const uint32_t dm32_pool_0302500c[9] = {
    0x0003c25c,  /* IRAM */
    0x0003bee4,  /* IRAM */
    0x0003beb0,  /* IRAM */
    0x0003c5f8,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003be8c,  /* IRAM */
    0x0003c2ae,  /* IRAM */
    0x0003c638,  /* IRAM */
    0x030af4a0,  /* flash data */
};

/* 030274d4-030274f0 28 bytes  pool of dmr_incoming_call_setup_conflict_resolve @0302741c */
const uint32_t dm32_pool_030274d4[7] = {
    0x0003be8c,  /* IRAM */
    0x00033d60,  /* IRAM */
    0x0003c608,  /* IRAM */
    0x0003c5f8,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003beb0,  /* IRAM */
    0x0003c604,  /* IRAM */
};

/* 03027660-03027688 40 bytes  pool of dmr_call_setup_accept_and_signal @03027618 */
const uint32_t dm32_pool_03027660[10] = {
    0x0003be8c,  /* IRAM */
    0x0003c604,  /* IRAM */
    0x00033d60,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003beb0,  /* IRAM */
    0x0003c5f8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003c668,  /* IRAM */
    0x0000783c,
    0x0000783c,
};

/* 03028034-03028044 16 bytes  pool of call_setup_queue_entry_append_and_dialog_advance @03027e80 */
const uint32_t dm32_pool_03028034[4] = {
    0x0003be8c,  /* IRAM */
    0x0003c5f8,  /* IRAM */
    0x0003c6b8,  /* IRAM */
    0x0003bd3c,  /* IRAM */
};

/* 030283f0-03028414 36 bytes  pool of dmr_call_setup_response_process_and_signal @03028338 */
const uint32_t dm32_pool_030283f0[9] = {
    0x0003beb0,  /* IRAM */
    0x0003c5f8,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003ba38,  /* IRAM */
    0x0003be8c,  /* IRAM */
    0x0003c608,  /* IRAM */
    0x0003c604,  /* IRAM */
    0x0003ba20,  /* IRAM */
    0x0003c620,  /* IRAM */
};

/* 0302877c-03028794 24 bytes  pool of dmr_call_state_machine_step @030286d8 */
const uint32_t dm32_pool_0302877c[6] = {
    0x0003c5f8,  /* IRAM */
    0x0003be8c,  /* IRAM */
    0x0003beb0,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ba38,  /* IRAM */
    0x00033cac,  /* IRAM */
};

/* 030288d8-030288e8 16 bytes  pool of dmr_call_state_machine_step @030286d8 */
const uint32_t dm32_pool_030288d8[4] = {
    0x0003be8c,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003c5f8,  /* IRAM */
    0x00033d60,  /* IRAM */
};

/* 03028aa4-03028ad4 48 bytes  pool of dmr_call_state_machine_step @030286d8 */
const uint32_t dm32_pool_03028aa4[12] = {
    0x00033d60,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x0003be8c,  /* IRAM */
    0x0003c5f4,  /* IRAM */
    0x0003c788,  /* IRAM */
    0x0003c60c,  /* IRAM */
    0x0003c5f8,  /* IRAM */
    0x0003c604,  /* IRAM */
    0x0003f700,  /* IRAM */
    0x0003c680,  /* IRAM */
    0x0003fabc,  /* IRAM */
    0x0003c608,  /* IRAM */
};

/* 03029124-03029140 28 bytes  pool of dmr_embedded_lc_superframe_process @03028c78 */
const uint32_t dm32_pool_03029124[7] = {
    0x0003c5f8,  /* IRAM */
    0x0003be8c,  /* IRAM */
    0x0003ba54,  /* IRAM */
    0x00033cac,  /* IRAM */
    0x00033d60,  /* IRAM */
    0x0003c78c,  /* IRAM */
    0x0003c604,  /* IRAM */
};

/* 030292b4-030292cc 24 bytes  pool of dmr_embedded_lc_superframe_process @03028c78 */
const uint32_t dm32_pool_030292b4[6] = {
    0x00033cac,  /* IRAM */
    0x00033d60,  /* IRAM */
    0x0003be8c,  /* IRAM */
    0x0003c5f8,  /* IRAM */
    0x0003c78c,  /* IRAM */
    0x0003c604,  /* IRAM */
};

/* 030294b4-030294cc 24 bytes  pool of flag_byte_clear_and_gpio_reset @03029440 */
const uint32_t dm32_pool_030294b4[6] = {
    0x83001064,
    0x0000783c,
    0x0003c6cc,  /* IRAM */
    0x03029420,  /* flash code */
    0x0003129c,  /* IRAM */
    0x0003be8c,  /* IRAM */
};

/* 0302960c-03029620 20 bytes  pool of history_slot_link_append @0302955c */
const uint32_t dm32_pool_0302960c[5] = {
    0x0003c7f4,  /* IRAM */
    0x0003c6d4,  /* IRAM */
    0x0003c818,  /* IRAM */
    0x0003be8c,  /* IRAM */
    0x00033cac,  /* IRAM */
};

/* 0302981c-03029830 20 bytes  pool of dmr_call_history_slot_register_short @030296ac */
const uint32_t dm32_pool_0302981c[5] = {
    0x0003be8c,  /* IRAM */
    0x0003c700,  /* IRAM */
    0x0003c748,  /* IRAM */
    0x0003c6d4,  /* IRAM */
    0x00033cac,  /* IRAM */
};

/* 03029d8c-03029d9c 16 bytes  pool of dmr_layer2_frame_build_and_send @03029d0c */
const uint32_t dm32_pool_03029d8c[4] = {
    0x0003c6d4,  /* IRAM */
    0x0003c7a8,  /* IRAM */
    0x0003be8c,  /* IRAM */
    0x00033cac,  /* IRAM */
};

/* 03029f20-03029f30 16 bytes  pool of max_linked_list_length_of_two @03029ee0 */
const uint32_t dm32_pool_03029f20[4] = {
    0x00033cac,  /* IRAM */
    0x00038430,  /* IRAM */
    0x0003ba38,  /* IRAM */
    0x0003c6d4,  /* IRAM */
};

/* 03029fc8-03029fd8 16 bytes  pool of clear_two_state_bytes_03029fc8 @03029f30 */
const uint32_t dm32_pool_03029fc8[4] = {
    0x0003cefd,  /* IRAM */
    0x0003cefc,  /* IRAM */
    0x030af704,  /* flash data */
    0x030af724,  /* flash data */
};

/* 0302a18c-0302a1c8 60 bytes  pool of serial_protocol_vframe_command_loop @0302a044 */
const uint32_t dm32_pool_0302a18c[15] = {
    0x000312a0,  /* IRAM */
    0x0003df08,  /* IRAM */
    0x030af8f8,  /* flash data */
    0x0302b3d4,  /* flash code */
    0x0003a64c,  /* IRAM */
    0x0003b9a6,  /* IRAM */
    0x00030de6,  /* IRAM */
    0x00030dee,  /* IRAM */
    0x00030dec,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x18000a84,
    0x0003cf00,  /* IRAM */
    0x0003cf03,  /* IRAM */
    0x0003cf06,  /* IRAM */
    0x0003cf05,  /* IRAM */
};

/* 0302a3b4-0302a3fc 72 bytes  pool of serial_protocol_vframe_command_loop @0302a044 */
const uint32_t dm32_pool_0302a3b4[18] = {
    0x0003cf06,  /* IRAM */
    0x030adaa0,  /* flash data */
    0x030adab0,  /* flash data */
    0x0003cf03,  /* IRAM */
    0x030adabc,  /* flash data */
    0x030adaec,  /* flash data */
    0x030adb30,  /* flash data */
    0x030adb34,  /* flash data */
    0x030adb18,  /* flash data */
    0x030adb1c,  /* flash data */
    0x030adb28,  /* flash data */
    0x030adb2c,  /* flash data */
    0x030adb20,  /* flash data */
    0x030adb24,  /* flash data */
    0x030adb48,  /* flash data */
    0x030adb4c,  /* flash data */
    0x030adb0c,  /* flash data */
    0x030adb10,  /* flash data */
};

/* 0302a5cc-0302a5ec 32 bytes  pool of serial_protocol_vframe_command_loop_variant @0302a4dc */
const uint32_t dm32_pool_0302a5cc[8] = {
    0x030adadc,  /* flash data */
    0x030adb50,  /* flash data */
    0x030adb40,  /* flash data */
    0x030adb44,  /* flash data */
    0x0003cf00,  /* IRAM */
    0x18000a84,
    0x0003cf03,  /* IRAM */
    0x0003cf06,  /* IRAM */
};

/* 0302b150-0302b174 36 bytes  pool of cps_serial_field_rw_dispatcher_variant @0302ae0e */
const uint32_t dm32_pool_0302b150[9] = {
    0x0003e8fe,  /* IRAM */
    0x0003e8f6,  /* IRAM */
    0x00032ab4,  /* IRAM */
    0x00038470,  /* IRAM */
    0x0003e210,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e5d4,  /* IRAM */
    0x18000ab8,
    0x0003be4c,  /* IRAM */
};

/* 0302b32c-0302b340 20 bytes  pool of cps_serial_field_rw_dispatcher_variant @0302ae0e */
const uint32_t dm32_pool_0302b32c[5] = {
    0x0003e8f6,  /* IRAM */
    0x00032ab4,  /* IRAM */
    0x18000ab8,
    0x0003e8fe,  /* IRAM */
    0x18000a84,
};

/* 0302b520-0302b54c 44 bytes  pool of cps_serial_handshake_command_dispatcher @0302b3d4 */
const uint32_t dm32_pool_0302b520[11] = {
    0x18000a84,
    0x0003ebf0,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030af904,  /* flash data */
    0x030af90c,  /* flash data */
    0x030af91c,  /* flash data */
    0x0003e38c,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x000400ec,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x030af914,  /* flash data */
};

/* 0302b6e0-0302b6fc 28 bytes  pool of cps_serial_handshake_command_dispatcher @0302b3d4 */
const uint32_t dm32_pool_0302b6e0[7] = {
    0x030af924,  /* flash data */
    0x0003fdb8,  /* IRAM */
    0x030af92c,  /* flash data */
    0x030af934,  /* flash data */
    0x030af93c,  /* flash data */
    0x030af944,  /* flash data */
    0x030af94c,  /* flash data */
};

/* 0302b9d8-0302ba0c 52 bytes  pool of display_wrapped_text_paginator @0302b920 */
const uint32_t dm32_pool_0302b9d8[13] = {
    0x0003e098,  /* IRAM */
    0x000315c8,  /* IRAM */
    0x0003dfd0,  /* IRAM */
    0x030af97c,  /* flash data */
    0x0302df64,  /* flash code */
    0x0003fd90,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b0790,  /* flash data */
};

/* 0302c068-0302c09c 52 bytes  pool of talker_alias_info_screen @0302ba20 */
const uint32_t dm32_pool_0302c068[13] = {
    0x0003fdc8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x030946e0,  /* flash data */
    0x030934e0,  /* flash data */
    0x03090c98,  /* flash data */
    0x03092c98,  /* flash data */
    0x0003e318,  /* IRAM */
    0x0003e0ee,  /* IRAM */
    0x0003e460,  /* IRAM */
    0x030afae8,  /* flash data */
    0x030af9b8,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x030b0790,  /* flash data */
};

/* 0302c228-0302c250 40 bytes  pool of talker_alias_info_screen @0302ba20 */
const uint32_t dm32_pool_0302c228[10] = {
    0x0003e0c0,  /* IRAM */
    0x030afae8,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x030ba278,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x030af9a8,  /* flash data */
    0x030958e0,  /* flash data */
    0x0003fdc8,  /* IRAM */
    0x030930bc,  /* flash data */
    0x03092c98,  /* flash data */
};

/* 0302c804-0302c818 20 bytes  pool of ptt_ui_state_machine_update @0302c5c8 */
const uint32_t dm32_pool_0302c804[5] = {
    0x0003e0c0,  /* IRAM */
    0x0003f004,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 0302ce70-0302ce90 32 bytes  pool of call_dialog_field_progress_and_timeout @0302cd4c */
const uint32_t dm32_pool_0302ce70[8] = {
    0x030a5ea0,  /* flash data */
    0x030a5240,  /* flash data */
    0x030a3980,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x030b96b0,  /* flash data */
    0x0003fd2c,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003fdc8,  /* IRAM */
};

/* 0302d4cc-0302d4f0 36 bytes  pool of refresh_display_based_on_dialog_flags @0302d36c */
const uint32_t dm32_pool_0302d4cc[9] = {
    0x0003fd2c,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9850,  /* flash data */
    0x030b9838,  /* flash data */
    0x030b9808,  /* flash data */
    0x030b9868,  /* flash data */
    0x030b9404,  /* flash data */
    0x03099780,  /* flash data */
};

/* 0302d678-0302d698 32 bytes  pool of talker_alias_refresh_gate_by_dialog_flags @0302d5b0 */
const uint32_t dm32_pool_0302d678[8] = {
    0x0003e9b4,  /* IRAM */
    0x030ba5c0,  /* flash data */
    0x0003fdc8,  /* IRAM */
    0x000315c8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003fd38,  /* IRAM */
    0x0003e0ee,  /* IRAM */
};

/* 0302d9cc-0302da0c 64 bytes  pool of dialog_request_tick @0302d884 */
const uint32_t dm32_pool_0302d9cc[16] = {
    0x0003e0c0,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003f004,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00038c6c,  /* IRAM */
    0x00040078,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b97c0,  /* flash data */
    0x030b1458,  /* flash data */
    0x0308c630,  /* flash data */
    0x030b97d8,  /* flash data */
    0x0308b6d0,  /* flash data */
    0x0003bd14,  /* IRAM */
    0x030b8ed8,  /* flash data */
    0x030bb938,  /* flash data */
    0x030a0a0c,  /* flash data */
};

/* 0302df1c-0302df3c 32 bytes  pool of dialog_close_and_tx_release @0302dc38 */
const uint32_t dm32_pool_0302df1c[8] = {
    0x0003ff84,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00040238,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003ee34,  /* IRAM */
    0x0003e098,  /* IRAM */
};

/* 0302e3b4-0302e3cc 24 bytes  pool of scan_list_entry_byte_read @0302e1c8 */
const uint32_t dm32_pool_0302e3b4[6] = {
    0x0003e144,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e145,  /* IRAM */
    0x0003e14a,  /* IRAM */
    0x0003e17a,  /* IRAM */
};

/* 0302e918-0302e940 40 bytes  pool of scrollable_list_menu_render_8row @0302e86c */
const uint32_t dm32_pool_0302e918[10] = {
    0x0003e144,  /* IRAM */
    0x0003e900,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9e40,  /* flash data */
    0x030ba180,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x030af9e4,  /* flash data */
    0x03081f48,  /* flash data */
    0x03081f78,  /* flash data */
    0x03082408,  /* flash data */
};

/* 0302ef68-0302ef84 28 bytes  pool of tx_is_inhibited @0302ed50 */
const uint32_t dm32_pool_0302ef68[7] = {
    0x0003fdb8,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003207c,  /* IRAM */
};

/* 0302f59c-0302f5bc 32 bytes  pool of zone_change_key_handler @0302f464 */
const uint32_t dm32_pool_0302f59c[8] = {
    0x0003e1dc,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00040120,  /* IRAM */
    0x0003e358,  /* IRAM */
    0x0003e21c,  /* IRAM */
    0x0003e38c,  /* IRAM */
};

/* 0302f944-0302f968 36 bytes  pool of display_draw_hex_digits_6_with_separator @0302f8b8 */
const uint32_t dm32_pool_0302f944[9] = {
    0x0003e13c,  /* IRAM */
    0x0003e1a8,  /* IRAM */
    0x0003e12c,  /* IRAM */
    0x0003e1b4,  /* IRAM */
    0x0003e128,  /* IRAM */
    0x00038470,  /* IRAM */
    0x0003e1b0,  /* IRAM */
    0x0003e140,  /* IRAM */
    0x0003e144,  /* IRAM */
};

/* 0302fb60-0302fb9c 60 bytes  pool of tx_abort_and_radio_state_reset @0302fa70 */
const uint32_t dm32_pool_0302fb60[15] = {
    0x0003e144,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x030a972c,  /* flash data */
    0x030a9704,  /* flash data */
    0x03082fb8,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x030ba1f0,  /* flash data */
    0x0003e318,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e13a,  /* IRAM */
    0x0003e1ac,  /* IRAM */
    0x0003e13b,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
};

/* 0302fdf8-0302fe44 76 bytes  pool of FUN_0302fc64 @0302fc64 */
const uint32_t dm32_pool_0302fdf8[19] = {
    0x0003e13a,  /* IRAM */
    0x0003e1a4,  /* IRAM */
    0x0003e136,  /* IRAM */
    0x0003e138,  /* IRAM */
    0x0003e13b,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e130,  /* IRAM */
    0x00038690,  /* IRAM */
    0x00038694,  /* IRAM */
    0x01312cff,
    0x030afa34,  /* flash data */
    0x030afa3c,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x0003846c,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
};

/* 0302fe84-0302fe94 16 bytes  pool of rf_frequency_adjust_and_display_refresh @0302fcd0 */
const uint32_t dm32_pool_0302fe84[4] = {
    0x0003fdb8,  /* IRAM */
    0x0003e1ac,  /* IRAM */
    0x0003e134,  /* IRAM */
    0x0003e1a4,  /* IRAM */
};

/* 030301e8-03030214 44 bytes  pool of dcs_code_display_normal_invert @0303017c */
const uint32_t dm32_pool_030301e8[11] = {
    0x0003e1b8,  /* IRAM */
    0x030afa44,  /* flash data */
    0x030afa4c,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x030ba200,  /* flash data */
    0x0003fdb8,  /* IRAM */
    0x0003e13b,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x030b7a28,  /* flash data */
    0x030b7a8c,  /* flash data */
    0x030afa54,  /* flash data */
};

/* 03030344-03030360 28 bytes  pool of tone_signaling_scroll_and_display_update @03030240 */
const uint32_t dm32_pool_03030344[7] = {
    0x030afa5c,  /* flash data */
    0x0003fdb8,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e1ed,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x00038470,  /* IRAM */
};

/* 03030558-0303056c 20 bytes  pool of commit_channel_record_dual_vfo @030303bc */
const uint32_t dm32_pool_03030558[5] = {
    0x0003e1dc,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e358,  /* IRAM */
    0x0003e21c,  /* IRAM */
    0x0003e9b4,  /* IRAM */
};

/* 030306ec-03030714 40 bytes  pool of ui_event_notify_alt @030305ac */
const uint32_t dm32_pool_030306ec[10] = {
    0x0003e318,  /* IRAM */
    0x0003fd90,  /* IRAM */
    0x0003e330,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x03082168,  /* flash data */
    0x03082208,  /* flash data */
    0x03082258,  /* flash data */
    0x030822a8,  /* flash data */
    0x030821b8,  /* flash data */
};

/* 030308c4-030308d8 20 bytes  pool of counter_value_bcd_encode_and_save @03030788 */
const uint32_t dm32_pool_030308c4[5] = {
    0x0003e9b4,  /* IRAM */
    0x030b0790,  /* flash data */
    0x0003e318,  /* IRAM */
    0x0003e330,  /* IRAM */
    0x0003fdb8,  /* IRAM */
};

/* 03030cdc-03030cfc 32 bytes  pool of vfo_standby_frequency_panel_render @03030a04 */
const uint32_t dm32_pool_03030cdc[8] = {
    0x0003e9b4,  /* IRAM */
    0x030b0790,  /* flash data */
    0x0003e358,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x030afa64,  /* flash data */
    0x0003e21c,  /* IRAM */
    0x03081f58,  /* flash data */
    0x00040120,  /* IRAM */
};

/* 03031480-03031494 20 bytes  pool of vfo_frequency_write @03031398 */
const uint32_t dm32_pool_03031480[5] = {
    0x0003e330,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e6cb,  /* IRAM */
};

/* 030318b0-030318d4 36 bytes  pool of vfo_record_read @0303169c */
const uint32_t dm32_pool_030318b0[9] = {
    0x0003e9b4,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x00040238,  /* IRAM */
    0x00040120,  /* IRAM */
    0x0003e358,  /* IRAM */
    0x0003e21c,  /* IRAM */
    0x0003fdb8,  /* IRAM */
};

/* 03032814-03032834 32 bytes  pool of codeplug_factory_defaults_write @03032434 */
const uint32_t dm32_pool_03032814[8] = {
    0x030afaec,  /* flash data */
    0x030afab0,  /* flash data */
    0x0003d0c0,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030afae0,  /* flash data */
    0x0003cf00,  /* IRAM */
    0x0003cf02,  /* IRAM */
    0x030afaf4,  /* flash data */
};

/* 03032a0c-03032a54 72 bytes  pool of codeplug_factory_defaults_write @03032434 */
const uint32_t dm32_pool_03032a0c[18] = {
    0x0003cf02,  /* IRAM */
    0x030afafc,  /* flash data */
    0x0003cf00,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003cf1a,  /* IRAM */
    0x030afb08,  /* flash data */
    0x030afb14,  /* flash data */
    0x0003cf32,  /* IRAM */
    0x030afb1c,  /* flash data */
    0x030afb24,  /* flash data */
    0x0003cf11,  /* IRAM */
    0x030afb30,  /* flash data */
    0x030afb6c,  /* flash data */
    0x0003cf10,  /* IRAM */
    0x030afb38,  /* flash data */
    0x030afb44,  /* flash data */
    0x0003cfa1,  /* IRAM */
    0x030afb50,  /* flash data */
};

/* 030332b4-030332cc 24 bytes  pool of status_queue_push_and_signal @03033234 */
const uint32_t dm32_pool_030332b4[6] = {
    0x00032080,  /* IRAM */
    0x030331c4,  /* flash code */
    0x0003e3c4,  /* IRAM */
    0x030afc54,  /* flash data */
    0x0003e400,  /* IRAM */
    0x0003e3f8,  /* IRAM */
};

/* 03033858-0303386c 20 bytes  pool of flash_config_record_read_16byte @030336b4 */
const uint32_t dm32_pool_03033858[5] = {
    0x030adb40,  /* flash data */
    0x18000a14,
    0x18000a08,
    0x0003e9b4,  /* IRAM */
    0x030afc78,  /* flash data */
};

/* 03033930-03033940 16 bytes  pool of fixed_field_copy_and_format_dispatch @03033918 */
const uint32_t dm32_pool_03033930[4] = {
    0x0003e9b4,  /* IRAM */
    0x030ba048,  /* flash data */
    0x0003e968,  /* IRAM */
    0x030afc5c,  /* flash data */
};

/* 03033b18-03033b54 60 bytes  pool of list_string_format_and_draw @030339bc */
const uint32_t dm32_pool_03033b18[15] = {
    0x0003e460,  /* IRAM */
    0x0003e470,  /* IRAM */
    0x030afae8,  /* flash data */
    0x0003e474,  /* IRAM */
    0x0003e47c,  /* IRAM */
    0x0003e48c,  /* IRAM */
    0x0003e49c,  /* IRAM */
    0x0003e4ac,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e8f4,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x03081f78,  /* flash data */
    0x03081f77,  /* flash data */
};

/* 03033d50-03033d68 24 bytes  pool of menu_list_row_advance_and_render @03033a84 */
const uint32_t dm32_pool_03033d50[6] = {
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x03081f77,  /* flash data */
    0x03081f78,  /* flash data */
};

/* 03033f24-03033f3c 24 bytes  pool of menu_list_row_advance_and_render_variant2 @03033d68 */
const uint32_t dm32_pool_03033f24[6] = {
    0x0003e5f8,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x03081f77,  /* flash data */
    0x03081f78,  /* flash data */
};

/* 03034750-03034768 24 bytes  pool of tx_contact_index_rewrite_both_blocks @03034624 */
const uint32_t dm32_pool_03034750[6] = {
    0x0003e9b4,  /* IRAM */
    0x030afcbc,  /* flash data */
    0x030afccc,  /* flash data */
    0x030b9c08,  /* flash data */
    0x030ba048,  /* flash data */
    0x0003944c,  /* IRAM */
};

/* 030354b4-030354ec 56 bytes  pool of scanned_channel_save_as_contact_flow @030353fc */
const uint32_t dm32_pool_030354b4[14] = {
    0x0003e318,  /* IRAM */
    0x00039474,  /* IRAM */
    0x0003869c,  /* IRAM */
    0x0003944c,  /* IRAM */
    0x0003e40c,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9f30,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x0309bb80,  /* flash data */
    0x030b9e28,  /* flash data */
    0x0003e434,  /* IRAM */
    0x030b9fb8,  /* flash data */
};

/* 03035670-0303569c 44 bytes  pool of scanned_channel_save_as_contact_flow @030353fc */
const uint32_t dm32_pool_03035670[11] = {
    0x0309bb80,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x030b9fd0,  /* flash data */
    0x030ba030,  /* flash data */
    0x0003e318,  /* IRAM */
    0x0309df80,  /* flash data */
    0x030b9b00,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x0003e434,  /* IRAM */
    0x030b9fb8,  /* flash data */
    0x030b1458,  /* flash data */
};

/* 0303584c-03035870 36 bytes  pool of contact_edit_validate_and_save @030355ec */
const uint32_t dm32_pool_0303584c[9] = {
    0x0003e9b4,  /* IRAM */
    0x030ba030,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309bb80,  /* flash data */
    0x0003e318,  /* IRAM */
    0x030ba1b0,  /* flash data */
    0x0309df80,  /* flash data */
    0x000320a8,  /* IRAM */
    0x030b9f30,  /* flash data */
};

/* 03035b7c-03035ba0 36 bytes  pool of status_message_save_on_confirm @03035b44 */
const uint32_t dm32_pool_03035b7c[9] = {
    0x0003e4bc,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9d40,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x030b9d80,  /* flash data */
    0x030b9dc8,  /* flash data */
};

/* 03035ed4-03035f1c 72 bytes  pool of subsystem_sem_create_and_buffer_init_0xa00 @03035eb4 */
const uint32_t dm32_pool_03035ed4[18] = {
    0x0003fdc8,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003ff3c,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x000334ec,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9750,  /* flash data */
    0x030b1458,  /* flash data */
    0x030877d0,  /* flash data */
    0x03081e9c,  /* flash data */
    0x0003e318,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x000320b4,  /* IRAM */
    0x0003e4fc,  /* IRAM */
    0x030b07a8,  /* flash data */
    0x03040a80,  /* flash code */
    0x0003e4c0,  /* IRAM */
};

/* 03036698-030366b4 28 bytes  pool of channel_vfo_commit_with_password_and_flash_write @0303659c */
const uint32_t dm32_pool_03036698[7] = {
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003eeac,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x030b0190,  /* flash data */
    0x0003e3b4,  /* IRAM */
};

/* 03036854-03036880 44 bytes  pool of channel_vfo_commit_with_password_and_flash_write @0303659c */
const uint32_t dm32_pool_03036854[11] = {
    0x0003e9b4,  /* IRAM */
    0x030ba1e0,  /* flash data */
    0x0003fdc8,  /* IRAM */
    0x0003ee84,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x00040114,  /* IRAM */
    0x00040104,  /* IRAM */
    0x030b07b4,  /* flash data */
    0x030b07bc,  /* flash data */
    0x0003e144,  /* IRAM */
    0x0003e1dc,  /* IRAM */
};

/* 03036a10-03036a48 56 bytes  pool of text_entry_blank_placeholder_row_draw_alt @0303695c */
const uint32_t dm32_pool_03036a10[14] = {
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e358,  /* IRAM */
    0x0003e21c,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5e0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x18000b07,
};

/* 03036db0-03036dfc 76 bytes  pool of FUN_03036ca8 @03036ca8 */
const uint32_t dm32_pool_03036db0[19] = {
    0x00039340,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003f335,  /* IRAM */
    0x0003f334,  /* IRAM */
    0x18000b07,
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x00040120,  /* IRAM */
    0x0003ee34,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003ee84,  /* IRAM */
    0x00040104,  /* IRAM */
};

/* 030372c0-03037320 96 bytes  pool of dialog_history_pop_and_state_dispatch @03037020 */
const uint32_t dm32_pool_030372c0[24] = {
    0x00040120,  /* IRAM */
    0x0003ee34,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003f004,  /* IRAM */
    0x0003fd20,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x030b01a4,  /* flash data */
    0x0003e5c4,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x00040238,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x030b8030,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e5fa,  /* IRAM */
    0x030bb784,  /* flash data */
    0x0003e5cd,  /* IRAM */
    0x18000a9c,
    0x0003ea4b,  /* IRAM */
    0x00042a3a,  /* IRAM */
};

/* 03037cb4-03037ce4 48 bytes  pool of field_edit_multikey_input_dispatch @03037718 */
const uint32_t dm32_pool_03037cb4[12] = {
    0x000320ac,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x18000b04,
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003ee84,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x18000ab4,
    0x18000b07,
    0x18000b05,
    0x0003fdc8,  /* IRAM */
    0x0003ffdc,  /* IRAM */
};

/* 03037e94-03037ec4 48 bytes  pool of field_edit_multikey_input_dispatch @03037718 */
const uint32_t dm32_pool_03037e94[12] = {
    0x0003ee84,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x030b07c4,  /* flash data */
    0x030b07cc,  /* flash data */
    0x030b07d4,  /* flash data */
    0x0003fdb8,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e8f6,  /* IRAM */
    0x0003e8fe,  /* IRAM */
};

/* 03038438-0303845c 36 bytes  pool of screen_enter_apply_channel_and_rf_mode @03038058 */
const uint32_t dm32_pool_03038438[9] = {
    0x0003e1dc,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e8fe,  /* IRAM */
    0x0003e8f6,  /* IRAM */
    0x00038470,  /* IRAM */
    0x0003e210,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x18000ab8,
    0x0003e318,  /* IRAM */
};

/* 03038784-030387c8 68 bytes  pool of menu_field_value_display_dispatch_variant @030385c4 */
const uint32_t dm32_pool_03038784[17] = {
    0x030b1458,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x030b8128,  /* flash data */
    0x030b80b8,  /* flash data */
    0x030b8030,  /* flash data */
    0x030b8060,  /* flash data */
    0x030b7e88,  /* flash data */
    0x030b8348,  /* flash data */
    0x030bb960,  /* flash data */
    0x030b7e28,  /* flash data */
    0x030b7db8,  /* flash data */
    0x0003e63f,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x030b8488,  /* flash data */
    0x030b89a0,  /* flash data */
};

/* 03038958-03038994 60 bytes  pool of menu_value_ptr_select_multilevel_and_display_variant @03038720 */
const uint32_t dm32_pool_03038958[15] = {
    0x0003e9b4,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x030bbad8,  /* flash data */
    0x030bba10,  /* flash data */
    0x030bbb48,  /* flash data */
    0x030bbb88,  /* flash data */
    0x0003e662,  /* IRAM */
    0x030b7ea8,  /* flash data */
    0x0003e434,  /* IRAM */
    0x030b1458,  /* flash data */
    0x030ba538,  /* flash data */
    0x030b7db8,  /* flash data */
    0x030bb960,  /* flash data */
    0x030b9728,  /* flash data */
};

/* 03039018-0303902c 20 bytes  pool of lcd_rect_bitmap_blit @03038ee0 */
const uint32_t dm32_pool_03039018[5] = {
    0x030b1458,  /* flash data */
    0x0003e434,  /* IRAM */
    0x0003e970,  /* IRAM */
    0x00039344,  /* IRAM */
    0x03081f77,  /* flash data */
};

/* 030394c8-030394fc 52 bytes  pool of list_cursor_increment @03039450 */
const uint32_t dm32_pool_030394c8[13] = {
    0x18000a90,
    0x0003e8f2,  /* IRAM */
    0x0003e964,  /* IRAM */
    0x0003e5dc,  /* IRAM */
    0x0003e968,  /* IRAM */
    0x0003ffd8,  /* IRAM */
    0x0003ffc0,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x000309c8,  /* IRAM */
    0x000309c9,  /* IRAM */
    0x000309ca,  /* IRAM */
};

/* 03039660-03039688 40 bytes  pool of ui_call_guard_input_dispatch_b @030395f4 */
const uint32_t dm32_pool_03039660[10] = {
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003ffdc,  /* IRAM */
    0x0003ee84,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x000309c9,  /* IRAM */
    0x000309c8,  /* IRAM */
    0x000309ca,  /* IRAM */
};

/* 030397cc-03039810 68 bytes  pool of menu_screen_load_contact_list @0303975c */
const uint32_t dm32_pool_030397cc[17] = {
    0x0003e3b4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x18000a90,
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x030b9200,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e964,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003e8fa,  /* IRAM */
    0x030b9648,  /* flash data */
    0x0003e318,  /* IRAM */
};

/* 03039c60-03039c7c 28 bytes  pool of tx_gate_press_standby_action_dispatch @03039a3c */
const uint32_t dm32_pool_03039c60[7] = {
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
};

/* 03039e20-03039e3c 28 bytes  pool of menu_icon_with_index_label_draw @03039db4 */
const uint32_t dm32_pool_03039e20[7] = {
    0x0003e9b4,  /* IRAM */
    0x030b0790,  /* flash data */
    0x030b07f8,  /* flash data */
    0x030b0800,  /* flash data */
    0x030b0808,  /* flash data */
    0x03081f78,  /* flash data */
    0x030a38fc,  /* flash data */
};

/* 0303a334-0303a350 28 bytes  pool of list_row_scroll_decrement_b @03039f60 */
const uint32_t dm32_pool_0303a334[7] = {
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e5fb,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5f8,  /* IRAM */
};

/* 0303a674-0303a6b8 68 bytes  pool of menu_key_action_dispatch_by_screen_state @0303a57c */
const uint32_t dm32_pool_0303a674[17] = {
    0x0309cd80,  /* flash data */
    0x0003e9b4,  /* IRAM */
    0x030b941c,  /* flash data */
    0x0309bb80,  /* flash data */
    0x0309a980,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003fdb8,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d4,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e63f,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003ffd8,  /* IRAM */
};

/* 0303a830-0303a874 68 bytes  pool of menu_text_entry_and_softkey_event_dispatch @0303a770 */
const uint32_t dm32_pool_0303a830[17] = {
    0x0003e9b4,  /* IRAM */
    0x030ba138,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003ffd8,  /* IRAM */
    0x030ba150,  /* flash data */
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e63f,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003ee6c,  /* IRAM */
    0x030b9f60,  /* flash data */
    0x0003e318,  /* IRAM */
};

/* 0303aa10-0303aa6c 92 bytes  pool of menu_text_entry_and_softkey_event_dispatch @0303a770 */
const uint32_t dm32_pool_0303aa10[23] = {
    0x0003e445,  /* IRAM */
    0x0003ee84,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003f335,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x18000a90,
    0x18000b02,
    0x0003ee72,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee94,  /* IRAM */
    0x18000b07,
    0x0003e8f8,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba138,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x030ba150,  /* flash data */
    0x0003e5cc,  /* IRAM */
    0x030b8398,  /* flash data */
};

/* 0303add4-0303adf0 28 bytes  pool of zone_confirm_menu_handler @0303ab50 */
const uint32_t dm32_pool_0303add4[7] = {
    0x000320ac,  /* IRAM */
    0x0003e5d4,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e63f,  /* IRAM */
    0x0003e5df,  /* IRAM */
};

/* 0303af30-0303af68 56 bytes  pool of zone_confirm_menu_handler @0303ab50 */
const uint32_t dm32_pool_0303af30[14] = {
    0x0003ed06,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x00040120,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba220,  /* flash data */
    0x0004011e,  /* IRAM */
    0x030bb960,  /* flash data */
    0x0003e5f8,  /* IRAM */
    0x0003e968,  /* IRAM */
    0x030b7fa0,  /* flash data */
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x18000a90,
};

/* 0303b0cc-0303b108 60 bytes  pool of asterisk_key_dispatch @0303af68 */
const uint32_t dm32_pool_0303b0cc[15] = {
    0x0003fdb8,  /* IRAM */
    0x0003e3b4,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9a70,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003fdc8,  /* IRAM */
    0x18000a90,
    0x0003ee84,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x18000b04,
    0x000320ac,  /* IRAM */
    0x000400fc,  /* IRAM */
};

/* 0303b698-0303b6c4 44 bytes  pool of dialog_show_number_or_alt @0303b394 */
const uint32_t dm32_pool_0303b698[11] = {
    0x0003e9b4,  /* IRAM */
    0x0003e358,  /* IRAM */
    0x0003e21c,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x030ba1c8,  /* flash data */
};

/* 0303bc10-0303bc30 32 bytes  pool of vfo_status_screen_number_and_id_redraw @0303b906 */
const uint32_t dm32_pool_0303bc10[8] = {
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba508,  /* flash data */
    0x030b7e88,  /* flash data */
    0x030ba280,  /* flash data */
    0x030b7f60,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x0003e63f,  /* IRAM */
};

/* 0303bfb8-0303c014 92 bytes  pool of numeric_value_adjust_dialog_screen @0303bd6c */
const uint32_t dm32_pool_0303bfb8[23] = {
    0x0003ed04,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ed02,  /* IRAM */
    0x0003e964,  /* IRAM */
    0x0003e8fa,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030bb8d8,  /* flash data */
    0x00040120,  /* IRAM */
    0x0004011a,  /* IRAM */
    0x00040118,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e8f8,  /* IRAM */
    0x0003e8f4,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x18000a90,
    0x0003e904,  /* IRAM */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x030ba518,  /* flash data */
    0x030ba538,  /* flash data */
};

/* 0303c1d4-0303c20c 56 bytes  pool of scan_monitor_number_draw_handler @0303bf58 */
const uint32_t dm32_pool_0303c1d4[14] = {
    0x0003e9b4,  /* IRAM */
    0x030b89a0,  /* flash data */
    0x030ba528,  /* flash data */
    0x030ba538,  /* flash data */
    0x18000b05,
    0x030b7db8,  /* flash data */
    0x0003e5f8,  /* IRAM */
    0x0003e8f4,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x030bb960,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e1dc,  /* IRAM */
};

/* 0303c3c0-0303c400 64 bytes  pool of tone_signaling_screen_render_and_apply @0303c20c */
const uint32_t dm32_pool_0303c3c0[16] = {
    0x0003e9b4,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x030b80b8,  /* flash data */
    0x03082fb8,  /* flash data */
    0x0003fdb8,  /* IRAM */
    0x0003e1ed,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x00038470,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e8f4,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003ed05,  /* IRAM */
    0x030b89a0,  /* flash data */
};

/* 0303c79c-0303c7d8 60 bytes  pool of channel_list_dialog_screen_draw @0303c5f8 */
const uint32_t dm32_pool_0303c79c[15] = {
    0x0003e9b4,  /* IRAM */
    0x030ba924,  /* flash data */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e8f9,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x030b88e0,  /* flash data */
    0x0003e8f4,  /* IRAM */
    0x000400f4,  /* IRAM */
    0x030b9f90,  /* flash data */
    0x030b9fa8,  /* flash data */
    0x0003e5cd,  /* IRAM */
    0x000320ac,  /* IRAM */
};

/* 0303caa8-0303cae0 56 bytes  pool of menu_screen_flush_dispatch_a @0303ca8c */
const uint32_t dm32_pool_0303caa8[14] = {
    0x000320ac,  /* IRAM */
    0x0003e5d8,  /* IRAM */
    0x0003ee85,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x18000b78,
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e318,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e63f,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x030afe94,  /* flash data */
};

/* 0303cb78-0303cb88 16 bytes  pool of menu_contact_view_apply_screen_setup @0303cb2c */
const uint32_t dm32_pool_0303cb78[4] = {
    0x000320ac,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e63f,  /* IRAM */
    0x030afecc,  /* flash data */
};

/* 0303cd3c-0303cd7c 64 bytes  pool of main_menu_screen_render_entry @0303cbc4 */
const uint32_t dm32_pool_0303cd3c[16] = {
    0x0003fdb8,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b7cb8,  /* flash data */
    0x0003e318,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x030b7ca8,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x0003e5d0,  /* IRAM */
    0x18000a90,
    0x030b7c2c,  /* flash data */
    0x030b7c1c,  /* flash data */
    0x0003e685,  /* IRAM */
    0x030b7c4c,  /* flash data */
};

/* 0303dd80-0303ddb0 48 bytes  pool of menu_screen_render_entry_variant @0303d8c8 */
const uint32_t dm32_pool_0303dd80[12] = {
    0x000320ac,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8060,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x030b8128,  /* flash data */
    0x030b8348,  /* flash data */
    0x030bb960,  /* flash data */
    0x030b7e28,  /* flash data */
    0x030ba924,  /* flash data */
};

/* 0303e070-0303e098 40 bytes  pool of menu_screen_entry_generic2 @0303df18 */
const uint32_t dm32_pool_0303e070[10] = {
    0x0004250d,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5e0,  /* IRAM */
    0x0003e61e,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
};

/* 0303e218-0303e244 44 bytes  pool of menu_screen_entry_generic1 @0303e0b8 */
const uint32_t dm32_pool_0303e218[11] = {
    0x000320ac,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5e0,  /* IRAM */
    0x0003e61e,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x0003e641,  /* IRAM */
};

/* 0303e3e4-0303e424 64 bytes  pool of menu_screen_entry_generic1 @0303e0b8 */
const uint32_t dm32_pool_0303e3e4[16] = {
    0x0003e4e8,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0003e5e0,  /* IRAM */
    0x0003e664,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x0003e687,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8150,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320ac,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
};

/* 0303e89c-0303e8c4 40 bytes  pool of menu_screen_entry_generic3 @0303e66c */
const uint32_t dm32_pool_0303e89c[10] = {
    0x0003e4e8,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0003e5e0,  /* IRAM */
    0x0003e641,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
};

/* 0303ea44-0303ea70 44 bytes  pool of menu_screen_entry_generic3 @0303e66c */
const uint32_t dm32_pool_0303ea44[11] = {
    0x000320ac,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5e0,  /* IRAM */
    0x0003e61e,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x0003e641,  /* IRAM */
};

/* 0303ec08-0303ec30 40 bytes  pool of menu_screen_entry_generic4 @0303e8e4 */
const uint32_t dm32_pool_0303ec08[10] = {
    0x000320ac,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5e0,  /* IRAM */
    0x0003e61e,  /* IRAM */
};

/* 0303f498-0303f4c0 40 bytes  pool of menu_navigation_dispatcher @0303f338 */
const uint32_t dm32_pool_0303f498[10] = {
    0x0003e4e8,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x0003e5e0,  /* IRAM */
    0x0003e61e,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
};

/* 0303f814-0303f848 52 bytes  pool of menu_screen_entry_generic7 @0303f6a4 */
const uint32_t dm32_pool_0303f814[13] = {
    0x000320ac,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5e0,  /* IRAM */
    0x0003e61e,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x0003e641,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b7e88,  /* flash data */
};

/* 0303fb90-0303fbb8 40 bytes  pool of ui_event_code_dispatch_main @0303fa04 */
const uint32_t dm32_pool_0303fb90[10] = {
    0x0003fdc8,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x0003ff38,  /* IRAM */
    0x18000a90,
    0x0003e0c0,  /* IRAM */
    0x0003e4c0,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x030aff9c,  /* flash data */
};

/* 0303ff54-0303ff80 44 bytes  pool of menu_key_confirm_dispatch @0303fc48 */
const uint32_t dm32_pool_0303ff54[11] = {
    0x0003fd2c,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e5d8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x18000a90,
};

/* 030402c4-030402ec 40 bytes  pool of dialog_key_release_history_dispatch @03040154 */
const uint32_t dm32_pool_030402c4[10] = {
    0x0003fd2c,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00040238,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x000400fc,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x18000a90,
    0x0003ee84,  /* IRAM */
};

/* 03040618-03040640 40 bytes  pool of keypad_event_dispatch_idle_or_menu @03040282 */
const uint32_t dm32_pool_03040618[10] = {
    0x0003e1bc,  /* IRAM */
    0x000392cd,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x18000a90,
    0x0003e9b4,  /* IRAM */
    0x030ba508,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x0003e63f,  /* IRAM */
};

/* 03040b40-03040b68 40 bytes  pool of tx_gate_call_record_toggle_a @03040b1c */
const uint32_t dm32_pool_03040b40[10] = {
    0x0003e318,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e45f,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x030b01a4,  /* flash data */
    0x0003e5c4,  /* IRAM */
    0x0003e4c0,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e5cc,  /* IRAM */
};

/* 03040d4c-03040d74 40 bytes  pool of list_row_scroll_decrement_a_call @03040ba8 */
const uint32_t dm32_pool_03040d4c[10] = {
    0x0003e8fa,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003e5c8,  /* IRAM */
    0x0003e5dc,  /* IRAM */
    0x0003ea4b,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003ffcc,  /* IRAM */
    0x0003ffd8,  /* IRAM */
};

/* 03040edc-03040ef8 28 bytes  pool of key_shortcut_special_case @03040d74 */
const uint32_t dm32_pool_03040edc[7] = {
    0x0003e8f9,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
};

/* 030411bc-030411e4 40 bytes  pool of list_row_scroll_increment_b_call @03041018 */
const uint32_t dm32_pool_030411bc[10] = {
    0x0003e8fa,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003e5c8,  /* IRAM */
    0x0003e5dc,  /* IRAM */
    0x0003ea4b,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003ffcc,  /* IRAM */
    0x0003ffd8,  /* IRAM */
};

/* 0304134c-03041368 28 bytes  pool of key_shortcut_special_case_fwd @030411e4 */
const uint32_t dm32_pool_0304134c[7] = {
    0x0003e8f9,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
};

/* 03041410-0304142c 28 bytes  pool of key_shortcut_dispatch_table_list_screens_screen_code11h @03041400 */
const uint32_t dm32_pool_03041410[7] = {
    0x0003e5cc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x18000a90,
    0x0003e144,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003e5df,  /* IRAM */
};

/* 03041554-03041598 68 bytes  pool of tx_pending_mbox_post_clear @0304142c */
const uint32_t dm32_pool_03041554[17] = {
    0x000320af,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e4bc,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8298,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x0003fe04,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x030b7ee0,  /* flash data */
};

/* 03041860-030418a0 64 bytes  pool of radio_id_detail_screen @03041700 */
const uint32_t dm32_pool_03041860[16] = {
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e8f4,  /* IRAM */
    0x03081f78,  /* flash data */
    0x03082378,  /* flash data */
    0x030823c0,  /* flash data */
    0x0003e5f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x030afae8,  /* flash data */
    0x0003ee6c,  /* IRAM */
    0x000400c4,  /* IRAM */
    0x03081f9c,  /* flash data */
    0x00040224,  /* IRAM */
    0x000400dc,  /* IRAM */
};

/* 03041af8-03041b24 44 bytes  pool of table_entry_select_and_index_list_build_variant_03041a68 @03041a68 */
const uint32_t dm32_pool_03041af8[11] = {
    0x0003ee72,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b7f60,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x030b7ea8,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x030b0818,  /* flash data */
};

/* 03041c98-03041cdc 68 bytes  pool of table_entry_select_and_index_list_build_variant9 @03041b24 */
const uint32_t dm32_pool_03041c98[17] = {
    0x0003e9b4,  /* IRAM */
    0x030bb784,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b81c8,  /* flash data */
    0x0003e318,  /* IRAM */
    0x0003ea4b,  /* IRAM */
    0x18000a94,
    0x030bb7a4,  /* flash data */
    0x030bb7c4,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x030b150c,  /* flash data */
    0x030ba0a8,  /* flash data */
    0x18000b88,
};

/* 03041f7c-03041fd8 92 bytes  pool of menu_option_accept_reject_with_history_pop @03041e50 */
const uint32_t dm32_pool_03041f7c[23] = {
    0xb8203100,
    0x32f06c07,
    0xe3fe331b,
    0x1071ae65,
    0x10718342,
    0x83425a6c,
    0x09573a07,
    0xd043106f,
    0x780c0883,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b7cb8,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x0003e5d0,  /* IRAM */
    0x18000a90,
    0x030b7c2c,  /* flash data */
    0x030b7c4c,  /* flash data */
    0x030b7c8c,  /* flash data */
    0x030b7c78,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x030b084c,  /* flash data */
};

/* 0304215c-030421b0 84 bytes  pool of menu_bool_option_init_03041fd8 @03041fd8 */
const uint32_t dm32_pool_0304215c[21] = {
    0x0003e9b4,  /* IRAM */
    0x030b8298,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003ee84,  /* IRAM */
    0x0003e1b0,  /* IRAM */
    0x0003e91e,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003e140,  /* IRAM */
    0x030b80e0,  /* flash data */
    0x0003e128,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e13b,  /* IRAM */
};

/* 03042740-030427b4 116 bytes  pool of channel_name_edit_or_option_list_dispatch @03042614 */
const uint32_t dm32_pool_03042740[29] = {
    0x0003e9b4,  /* IRAM */
    0x030bbb48,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030bbb88,  /* flash data */
    0x030b8d90,  /* flash data */
    0x00032ab6,  /* IRAM */
    0x0003e900,  /* IRAM */
    0x0003ed06,  /* IRAM */
    0x0003ed04,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003e8fa,  /* IRAM */
    0x18000b70,
    0x030b9274,  /* flash data */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ee68,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 03042c08-03042c48 64 bytes  pool of contact_menu_option_or_history_dispatch_wrapper @03042b34 */
const uint32_t dm32_pool_03042c08[16] = {
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b7ec8,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x030b7f00,  /* flash data */
    0x0003fe04,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x030b089c,  /* flash data */
};

/* 030430f8-03043134 60 bytes  pool of settings_code_read_and_status_dispatch @030430a8 */
const uint32_t dm32_pool_030430f8[15] = {
    0x0003e4e8,  /* IRAM */
    0x0003ed0c,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8f00,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b8f10,  /* flash data */
    0x030b8f20,  /* flash data */
    0x030b932c,  /* flash data */
    0x030ba4d8,  /* flash data */
    0x030b08b0,  /* flash data */
};

/* 030432ec-0304332c 64 bytes  pool of dmr_setting_0x47_read_store @03043134 */
const uint32_t dm32_pool_030432ec[16] = {
    0x0003e5cc,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8518,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b85b0,  /* flash data */
    0x030b8650,  /* flash data */
    0x030b8708,  /* flash data */
};

/* 0304366c-030436c0 84 bytes  pool of menu_contact_pick_method_option_init_03043624 @03043624 */
const uint32_t dm32_pool_0304366c[21] = {
    0x0003e9b4,  /* IRAM */
    0x030ba258,  /* flash data */
    0x000320b0,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x030b8de8,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x030b8298,  /* flash data */
    0x0003e5f8,  /* IRAM */
    0x00040120,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x030b9484,  /* flash data */
    0x0003e91e,  /* IRAM */
    0x030b94a4,  /* flash data */
};

/* 03043c88-03043ce8 96 bytes  pool of table_entry_select_and_index_list_build_variant11 @03043c38 */
const uint32_t dm32_pool_03043c88[24] = {
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x18000a90,
    0x0003e900,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x030b9274,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x000320b0,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ee68,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b96d0,  /* flash data */
};

/* 03043d74-03043da0 44 bytes  pool of shutdown_state_screen_dispatch @03043ce8 */
const uint32_t dm32_pool_03043d74[11] = {
    0x0003e4e8,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b954c,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x030b08f0,  /* flash data */
};

/* 03043ee8-03043f3c 84 bytes  pool of active_screen_load_options @03043ea4 */
const uint32_t dm32_pool_03043ee8[21] = {
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x030b8ca4,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003ea4b,  /* IRAM */
    0x0003ea4c,  /* IRAM */
    0x0003eafc,  /* IRAM */
    0x030b9244,  /* flash data */
    0x0003e5f8,  /* IRAM */
    0x030b8ce4,  /* flash data */
    0x000320b0,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b954c,  /* flash data */
};

/* 030442e0-03044308 40 bytes  pool of menu_entry_init_from_settings_0x62_clamp8 @03044244 */
const uint32_t dm32_pool_030442e0[10] = {
    0x0003e9b4,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x030b091c,  /* flash data */
};

/* 030446e0-0304471c 60 bytes  pool of menu_backlight_brightness_option_init @0304450c */
const uint32_t dm32_pool_030446e0[15] = {
    0x0003e9b4,  /* IRAM */
    0x030b93d4,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x030b9cf0,  /* flash data */
    0x030b9ed0,  /* flash data */
    0x000320b0,  /* IRAM */
    0x030bb80c,  /* flash data */
    0x030b8780,  /* flash data */
};

/* 03044abc-03044afc 64 bytes  pool of menu_auto_poweroff_timeout_option_init @0304493c */
const uint32_t dm32_pool_03044abc[16] = {
    0x0003e9b4,  /* IRAM */
    0x030b87e0,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x030b9484,  /* flash data */
    0x0003e91e,  /* IRAM */
    0x030b82b8,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x030b8298,  /* flash data */
};

/* 03044c88-03044cc0 56 bytes  pool of menu_bool_option_init_03044a50 @03044a50 */
const uint32_t dm32_pool_03044c88[14] = {
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8850,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x030ba710,  /* flash data */
    0x000320b0,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x030bb874,  /* flash data */
};

/* 03045254-030452ac 88 bytes  pool of menu_ctcss_dcs_type_option_init @030450c0 */
const uint32_t dm32_pool_03045254[22] = {
    0x0003e9b4,  /* IRAM */
    0x030b8180,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x00032ab6,  /* IRAM */
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003ed09,  /* IRAM */
    0x0003ed07,  /* IRAM */
    0x030b8d90,  /* flash data */
    0x030ba258,  /* flash data */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x030b8de8,  /* flash data */
};

/* 03045410-03045464 84 bytes  pool of menu_bool_option_init_030452ac @030452ac */
const uint32_t dm32_pool_03045410[21] = {
    0x0003e4e8,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8298,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003f6fc,  /* IRAM */
    0x000320b0,  /* IRAM */
    0x0003ed08,  /* IRAM */
    0x0003ed05,  /* IRAM */
    0x0003eff4,  /* IRAM */
    0x0003e434,  /* IRAM */
    0x030b1008,  /* flash data */
    0x030bbc10,  /* flash data */
};

/* 030455d0-03045630 96 bytes  pool of menu_screen_state_dispatcher @030454cc */
const uint32_t dm32_pool_030455d0[24] = {
    0x0003e5cc,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x18000a90,
    0x0003e8f9,  /* IRAM */
    0x00040139,  /* IRAM */
    0x0004011a,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x000320b0,  /* IRAM */
    0x18000b70,
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x030b9274,  /* flash data */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ee68,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 030457dc-03045834 88 bytes  pool of text_entry_dialog_init_field_pair_variant2 @03045710 */
const uint32_t dm32_pool_030457dc[22] = {
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x0003e6cb,  /* IRAM */
    0x000320b0,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x030b929c,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003ee84,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee94,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x030b92a4,  /* flash data */
    0x0003efec,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x030b92c4,  /* flash data */
    0x0003e96c,  /* IRAM */
};

/* 030459f0-03045a4c 92 bytes  pool of menu_contact_view_or_apply_option_init_03045858 @03045858 */
const uint32_t dm32_pool_030459f0[23] = {
    0x0003e318,  /* IRAM */
    0x030b92cc,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e45f,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b92fc,  /* flash data */
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e6cb,  /* IRAM */
    0x030b7ff0,  /* flash data */
    0x030b8ed8,  /* flash data */
    0x030b7f80,  /* flash data */
    0x0003f334,  /* IRAM */
    0x0003e5dc,  /* IRAM */
    0x0003e460,  /* IRAM */
    0x0003e434,  /* IRAM */
    0x0000783c,
};

/* 03045be4-03045c48 100 bytes  pool of menu_scan_priority_actions_option_init @03045a94 */
const uint32_t dm32_pool_03045be4[25] = {
    0x000320b0,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003e8fa,  /* IRAM */
    0x18000b70,
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e318,  /* IRAM */
    0x0003e964,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8db0,  /* flash data */
    0x00032ab6,  /* IRAM */
    0x0003e6cb,  /* IRAM */
    0x030b948c,  /* flash data */
    0x030b94a4,  /* flash data */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x0003ee94,  /* IRAM */
};

/* 0304616c-030461bc 80 bytes  pool of menu_item_render_and_select_multibranch @03045fd8 */
const uint32_t dm32_pool_0304616c[20] = {
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e6cb,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b91a0,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x030b9484,  /* flash data */
    0x0003e91e,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x030ba5f8,  /* flash data */
    0x030b8fc0,  /* flash data */
    0x030b8298,  /* flash data */
};

/* 0304675c-030467b4 88 bytes  pool of menu_field_render_multibranch_dispatch @0304637c */
const uint32_t dm32_pool_0304675c[22] = {
    0x18000b80,
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x00038470,  /* IRAM */
    0x02625a00,
    0x0003ee8b,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b96d0,  /* flash data */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6ee,  /* IRAM */
    0x030b7ff0,  /* flash data */
    0x030b8ed8,  /* flash data */
};

/* 03046b0c-03046b40 52 bytes  pool of table_entry_select_two_mode_dispatch @03046a88 */
const uint32_t dm32_pool_03046b0c[13] = {
    0x0003e4e8,  /* IRAM */
    0x0003e711,  /* IRAM */
    0x0003e6ee,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b94a4,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b8f34,  /* flash data */
    0x030b94e4,  /* flash data */
    0x0003e6cb,  /* IRAM */
};

/* 03046cbc-03046d1c 96 bytes  pool of menu_confirm_delete_or_two_mode_dispatch @03046b40 */
const uint32_t dm32_pool_03046cbc[24] = {
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003ed00,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba258,  /* flash data */
    0x18000b60,
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e964,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003e8fa,  /* IRAM */
    0x000320b0,  /* IRAM */
    0x030ba168,  /* flash data */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x18000b80,
    0x0003e318,  /* IRAM */
    0x0003ee8b,  /* IRAM */
    0x02625a00,
    0x0003edf6,  /* IRAM */
    0x0003ee72,  /* IRAM */
};

/* 03046e60-03046e98 56 bytes  pool of menu_search_contact_manual_dial_option_init @03046d5c */
const uint32_t dm32_pool_03046e60[14] = {
    0x0003e4e8,  /* IRAM */
    0x0003e63f,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e6ee,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b95b4,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b9620,  /* flash data */
    0x0003e6cb,  /* IRAM */
    0x030b9524,  /* flash data */
};

/* 03046fb4-03046fe8 52 bytes  pool of menu_screen_dispatch_by_field_0x8 @03046f88 */
const uint32_t dm32_pool_03046fb4[13] = {
    0x0003e4e8,  /* IRAM */
    0x0003e6ee,  /* IRAM */
    0x0003e711,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b954c,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e734,  /* IRAM */
    0x0000783c,
};

/* 03047194-030471e0 76 bytes  pool of vfo_record_offset_select4 @0304707c */
const uint32_t dm32_pool_03047194[19] = {
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6ee,  /* IRAM */
    0x0003e711,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9524,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e63f,  /* IRAM */
    0x0003e1c0,  /* IRAM */
    0x03089bd0,  /* flash data */
    0x0308a4d0,  /* flash data */
    0x0308add0,  /* flash data */
    0x0003ee6c,  /* IRAM */
    0x030afae8,  /* flash data */
    0x0003e685,  /* IRAM */
};

/* 03047340-03047374 52 bytes  pool of table_entry_select_and_index_list_build_toplevel_dispatch @03047324 */
const uint32_t dm32_pool_03047340[13] = {
    0x0003e904,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x030b88e0,  /* flash data */
    0x030b8a28,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e970,  /* IRAM */
    0x000320af,  /* IRAM */
    0x18000a90,
    0x0304142c,  /* flash code */
    0x0003e685,  /* IRAM */
    0x030b0a18,  /* flash data */
};

/* 03047730-03047780 80 bytes  pool of dispatcher_setting_index_reader @03047598 */
const uint32_t dm32_pool_03047730[20] = {
    0x0003e9b4,  /* IRAM */
    0x030b8f88,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e91e,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003ed05,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x030bb900,  /* flash data */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x030b8de8,  /* flash data */
    0x030bb844,  /* flash data */
};

/* 03047930-03047988 88 bytes  pool of menu_bool_option_init_03047780 @03047780 */
const uint32_t dm32_pool_03047930[22] = {
    0x0003e9b4,  /* IRAM */
    0x030b8298,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x030b9274,  /* flash data */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ee68,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ed07,  /* IRAM */
    0x030bb844,  /* flash data */
};

/* 03047cf8-03047d44 76 bytes  pool of tone_signaling_menu_option_0x1f_dispatch @03047ae8 */
const uint32_t dm32_pool_03047cf8[19] = {
    0x0003e9b4,  /* IRAM */
    0x030b89f0,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x030b88c0,  /* flash data */
    0x000320b0,  /* IRAM */
    0x18000b80,
    0x0003e318,  /* IRAM */
    0x0003ee8a,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x030bba60,  /* flash data */
};

/* 03047e14-03047e4c 56 bytes  pool of menu_option_handler_dispatch_wrapper @03047d6c */
const uint32_t dm32_pool_03047e14[14] = {
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e8f8,  /* IRAM */
    0x030b81b8,  /* flash data */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e8f9,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003ee6c,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b8f40,  /* flash data */
    0x030adaa0,  /* flash data */
    0x030b0a8c,  /* flash data */
};

/* 03048d90-03048da0 16 bytes  pool of time_display_refresh_and_char_picker_offset_inc @03048bf4 */
const uint32_t dm32_pool_03048d90[4] = {
    0x0003e9b4,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x030b106c,  /* flash data */
    0x03081f94,  /* flash data */
};

/* 03048edc-03048ef4 24 bytes  pool of menu_ms_setting_cycle_linear_and_char_pos_update @03048da0 */
const uint32_t dm32_pool_03048edc[6] = {
    0x0003e5cc,  /* IRAM */
    0x0003e91e,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x030b0e54,  /* flash data */
};

/* 030490b4-030490ec 56 bytes  pool of rtc_date_decode_to_bcd_display_buffer @03048ef4 */
const uint32_t dm32_pool_030490b4[14] = {
    0x0003ee84,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b8708,  /* flash data */
    0x0003e5cc,  /* IRAM */
    0x030ba924,  /* flash data */
    0x030bb980,  /* flash data */
    0x030b106c,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x030b80b8,  /* flash data */
};

/* 03049340-03049358 24 bytes  pool of display_draw_number_centered_then_settings_duration_seconds_display_call_030492b8 @030492b8 */
const uint32_t dm32_pool_03049340[6] = {
    0x0003e9b4,  /* IRAM */
    0x030bbad8,  /* flash data */
    0x0003e5cc,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x030bbb48,  /* flash data */
};

/* 030494bc-030494cc 16 bytes  pool of scan_feature_enabled @03049358 */
const uint32_t dm32_pool_030494bc[4] = {
    0x0003e144,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b1074,  /* flash data */
};

/* 0304a2bc-0304a2cc 16 bytes  pool of vfo_load_side_config @0304a200 */
const uint32_t dm32_pool_0304a2bc[4] = {
    0x0003e9b4,  /* IRAM */
    0x0003e9b5,  /* IRAM */
    0x0003e9c8,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 0304bd48-0304bd5c 20 bytes  pool of settings_write_dispatcher @0304b088 */
const uint32_t dm32_pool_0304bd48[5] = {
    0x000392d4,  /* IRAM */
    0x000392d0,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x1800090c,
    0x000392d8,  /* IRAM */
};

/* 0304bf2c-0304bf48 28 bytes  pool of settings_write_dispatcher @0304b088 */
const uint32_t dm32_pool_0304bf2c[7] = {
    0x000392d0,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x1800090c,
    0x000392d8,  /* IRAM */
    0x000392d4,  /* IRAM */
    0x0003930c,  /* IRAM */
    0x18000b05,
};

/* 0304c2b0-0304c2c0 16 bytes  pool of settings_write_dispatcher @0304b088 */
const uint32_t dm32_pool_0304c2b0[4] = {
    0x0003e9b4,  /* IRAM */
    0x0003e1b0,  /* IRAM */
    0x0003e140,  /* IRAM */
    0x0003e128,  /* IRAM */
};

/* 0304c798-0304c7b4 28 bytes  pool of menu_capability_dispatch @0304c750 */
const uint32_t dm32_pool_0304c798[7] = {
    0x0003e9b4,  /* IRAM */
    0x030b8298,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x030b1140,  /* flash data */
};

/* 0304caa8-0304cadc 52 bytes  pool of menu_screen_load_and_setting_read @0304c928 */
const uint32_t dm32_pool_0304caa8[13] = {
    0x0003e5cc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x0003e91f,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x030b9160,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320b0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x030b9078,  /* flash data */
};

/* 0304cc6c-0304cc7c 16 bytes  pool of settings_write_dispatcher_alt @0304cb80 */
const uint32_t dm32_pool_0304cc6c[4] = {
    0x0003e5cc,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e9b4,  /* IRAM */
};

/* 0304d430-0304d488 88 bytes  pool of menu_confirm_apply_handler1 @0304cf5c */
const uint32_t dm32_pool_0304d430[22] = {
    0x0003e5cc,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b941c,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x18000a90,
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x00032ab4,  /* IRAM */
    0x0003e5d4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00032ab5,  /* IRAM */
    0x0003ed06,  /* IRAM */
    0x18000b02,
    0x0003ee34,  /* IRAM */
    0x18000b07,
    0x0003ee98,  /* IRAM */
    0x030b9fb8,  /* flash data */
    0x030bb8f0,  /* flash data */
    0x030ba180,  /* flash data */
};

/* 0304db74-0304dbd0 92 bytes  pool of input_message_dispatcher @0304da34 */
const uint32_t dm32_pool_0304db74[23] = {
    0x0003e9c8,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ed06,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x18000a90,
    0x18000b02,
    0x18000b07,
    0x0003ee72,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee94,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9ae8,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003e685,  /* IRAM */
    0x030b9b48,  /* flash data */
};

/* 0304dca8-0304dcc4 28 bytes  pool of menu_command_dispatch_with_dmr_fallback @0304dc8c */
const uint32_t dm32_pool_0304dca8[7] = {
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9b48,  /* flash data */
    0x0003e662,  /* IRAM */
    0x030b9988,  /* flash data */
    0x030b116c,  /* flash data */
};

/* 0304e578-0304e5a0 40 bytes  pool of status_mode_or_settings_menu_command_dispatch @0304e560 */
const uint32_t dm32_pool_0304e578[10] = {
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003ee34,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9434,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309bb80,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x030b11c4,  /* flash data */
};

/* 0304e94c-0304e98c 64 bytes  pool of call_list_index_write2_then_dialog_show_icon_and_number_0304e7b8 @0304e7b8 */
const uint32_t dm32_pool_0304e94c[16] = {
    0x0003e5cc,  /* IRAM */
    0x000400dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b941c,  /* flash data */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x00040139,  /* IRAM */
    0x18000a90,
    0x18000b02,
    0x0003ee34,  /* IRAM */
    0x18000b07,
    0x0003ee98,  /* IRAM */
    0x030b9fb8,  /* flash data */
    0x030bb8f8,  /* flash data */
    0x00040120,  /* IRAM */
    0x030ba180,  /* flash data */
};

/* 0304ec7c-0304ecd4 88 bytes  pool of dmr_menu_field_edit_key_dispatch @0304eb28 */
const uint32_t dm32_pool_0304ec7c[22] = {
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x0003e900,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e8fc,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba5d0,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x18000a90,
    0x18000b02,
    0x0003ee34,  /* IRAM */
    0x18000b07,
    0x0003ee98,  /* IRAM */
    0x030b9fb8,  /* flash data */
    0x030bb8f8,  /* flash data */
    0x0003e970,  /* IRAM */
};

/* 0304ef84-0304efc8 68 bytes  pool of menu_option_activate_dialog_code8 @0304edf0 */
const uint32_t dm32_pool_0304ef84[17] = {
    0x0003e9b4,  /* IRAM */
    0x030ba2d0,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x030ba2e8,  /* flash data */
    0x0003fd2c,  /* IRAM */
    0x030ba340,  /* flash data */
    0x030ba320,  /* flash data */
    0x030ba300,  /* flash data */
    0x030ba358,  /* flash data */
    0x030ba370,  /* flash data */
    0x00038c6c,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003eff0,  /* IRAM */
};

/* 0304f114-0304f168 84 bytes  pool of dtmf_or_wlt_channel_select_dispatch @0304ef42 */
const uint32_t dm32_pool_0304f114[21] = {
    0x0003e9b4,  /* IRAM */
    0x030b8b40,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x030ba220,  /* flash data */
    0x0003eff0,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b8ed8,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x18000b02,
    0x0003e434,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003e445,  /* IRAM */
    0x0003ee84,  /* IRAM */
    0x030b1258,  /* flash data */
};

/* 0304f484-0304f4c0 60 bytes  pool of menu_confirm_apply_scan_handler @0304f384 */
const uint32_t dm32_pool_0304f484[15] = {
    0x0003fe04,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x18000a90,
    0x18000b02,
    0x0003ee34,  /* IRAM */
    0x18000b07,
    0x0003e434,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba5c0,  /* flash data */
    0x0003e318,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
};

/* 0304f5f8-0304f630 56 bytes  pool of channel_entry_command_byte_router @0304f548 */
const uint32_t dm32_pool_0304f5f8[14] = {
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003fe04,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003ee6c,  /* IRAM */
    0x0003eff0,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003ee98,  /* IRAM */
};

/* 0304faec-0304fb2c 64 bytes  pool of settings_menu_wrapper_dispatch @0304fab4 */
const uint32_t dm32_pool_0304faec[16] = {
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x18000b02,
    0x18000b07,
    0x0003ee72,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee94,  /* IRAM */
    0x030b150c,  /* flash data */
    0x0003e908,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b99a0,  /* flash data */
    0x0003e685,  /* IRAM */
    0x030b1270,  /* flash data */
};

/* 0304fe40-0304fe54 20 bytes  pool of menu_wrapper_opcode0x31 @0304fcb8 */
const uint32_t dm32_pool_0304fe40[5] = {
    0x0003e5cc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b93ec,  /* flash data */
    0x030b9780,  /* flash data */
    0x0003e38c,  /* IRAM */
};

/* 03050390-030503e0 80 bytes  pool of menu_confirm_apply_handler2 @030500b0 */
const uint32_t dm32_pool_03050390[20] = {
    0x0003ed09,  /* IRAM */
    0x0003ed07,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x18000a90,
    0x18000b02,
    0x0003ee34,  /* IRAM */
    0x18000b07,
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9fb8,  /* flash data */
    0x030bb8f0,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x030b941c,  /* flash data */
    0x030b7f40,  /* flash data */
    0x0309bb80,  /* flash data */
};

/* 03050558-030505a4 76 bytes  pool of channel_command_dispatch_select_or_save_name @03050450 */
const uint32_t dm32_pool_03050558[19] = {
    0x0003e5cc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b941c,  /* flash data */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x00040139,  /* IRAM */
    0x030ba180,  /* flash data */
    0x18000a90,
    0x18000b02,
    0x0003e318,  /* IRAM */
    0x0003ee34,  /* IRAM */
    0x18000b07,
    0x0003ee98,  /* IRAM */
    0x030b9fb8,  /* flash data */
    0x030bb8f8,  /* flash data */
    0x0003e434,  /* IRAM */
};

/* 0305071c-03050774 88 bytes  pool of field_entry_confirm_multicontext_dispatch @0305063c */
const uint32_t dm32_pool_0305071c[22] = {
    0x0003e4e8,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003ee6c,  /* IRAM */
    0x0003eff0,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e63f,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6cb,  /* IRAM */
    0x18000b02,
    0x18000b07,
    0x030b9fb8,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309bb80,  /* flash data */
    0x0003e434,  /* IRAM */
    0x0003e445,  /* IRAM */
    0x0003ee84,  /* IRAM */
};

/* 0305087c-030508c0 68 bytes  pool of field_entry_confirm_multicontext_dispatch @0305063c */
const uint32_t dm32_pool_0305087c[17] = {
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9ae8,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003e8f2,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e685,  /* IRAM */
    0x0003e6cb,  /* IRAM */
    0x0003eff0,  /* IRAM */
    0x0003e470,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x030b1360,  /* flash data */
};

/* 03050a58-03050a9c 68 bytes  pool of status_field_dispatch_variant_6 @030508c0 */
const uint32_t dm32_pool_03050a58[17] = {
    0x0003e9b4,  /* IRAM */
    0x030ba2d0,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x030ba2e8,  /* flash data */
    0x0003fd2c,  /* IRAM */
    0x030ba340,  /* flash data */
    0x030ba320,  /* flash data */
    0x030ba300,  /* flash data */
    0x030ba358,  /* flash data */
    0x030ba370,  /* flash data */
    0x00038c6c,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003eff0,  /* IRAM */
};

/* 03050c0c-03050c58 76 bytes  pool of channel_contact_commit_or_delete_dispatch @03050b9c */
const uint32_t dm32_pool_03050c0c[19] = {
    0x0003e9b4,  /* IRAM */
    0x030b8b40,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x030ba220,  /* flash data */
    0x0003eff0,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e900,  /* IRAM */
    0x030ba150,  /* flash data */
    0x0003e8f2,  /* IRAM */
    0x0003f330,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e1c0,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 03051394-030513d8 68 bytes  pool of menu_confirm_apply_dispatcher @03050de8 */
const uint32_t dm32_pool_03051394[17] = {
    0x0003e9b4,  /* IRAM */
    0x030b9434,  /* flash data */
    0x0003e318,  /* IRAM */
    0x18000b02,
    0x18000b07,
    0x0003ee98,  /* IRAM */
    0x0309bb80,  /* flash data */
    0x030b9fb8,  /* flash data */
    0x0003ed05,  /* IRAM */
    0x0003e434,  /* IRAM */
    0x030bb8f8,  /* flash data */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e6cb,  /* IRAM */
    0x18000a90,
    0x0003ee34,  /* IRAM */
};

/* 030515dc-03051628 76 bytes  pool of menu_confirm_apply_dispatcher @03050de8 */
const uint32_t dm32_pool_030515dc[19] = {
    0x0003ed09,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003e970,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003ee84,  /* IRAM */
    0x00989680,
    0x0003e4e8,  /* IRAM */
    0x0003e6a8,  /* IRAM */
    0x00038470,  /* IRAM */
    0x0003ee34,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba1b0,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003e318,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x030ba180,  /* flash data */
};

/* 030518fc-03051940 68 bytes  pool of status_field_dispatch_variant_5 @03051764 */
const uint32_t dm32_pool_030518fc[17] = {
    0x0003e9b4,  /* IRAM */
    0x030ba2d0,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x030ba2e8,  /* flash data */
    0x0003fd2c,  /* IRAM */
    0x030ba340,  /* flash data */
    0x030ba320,  /* flash data */
    0x030ba300,  /* flash data */
    0x030ba358,  /* flash data */
    0x030ba370,  /* flash data */
    0x00038c6c,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003eff0,  /* IRAM */
};

/* 03051ae4-03051b10 44 bytes  pool of dialog_or_channel_select_on_flag_0x40 @030518b6 */
const uint32_t dm32_pool_03051ae4[11] = {
    0x0003e9b4,  /* IRAM */
    0x030b8b40,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x030ba220,  /* flash data */
    0x0003eff0,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003e900,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e144,  /* IRAM */
};

/* 03051e24-03051e60 60 bytes  pool of menu_screen_state_mode_dispatch @03051bac */
const uint32_t dm32_pool_03051e24[15] = {
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x18000b02,
    0x0003e4e8,  /* IRAM */
    0x0003e6cb,  /* IRAM */
    0x0003e6ee,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003ee6c,  /* IRAM */
    0x0003eff0,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003e908,  /* IRAM */
    0x030b9b48,  /* flash data */
};

/* 03052314-03052364 80 bytes  pool of menu_confirm_apply_manual_freq_entry @03051ea4 */
const uint32_t dm32_pool_03052314[20] = {
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba180,  /* flash data */
    0x0003ee34,  /* IRAM */
    0x030b9434,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x18000a90,
    0x0003ee6c,  /* IRAM */
    0x0003eff0,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6ee,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003ea4c,  /* IRAM */
};

/* 030524e8-03052518 48 bytes  pool of menu_confirm_apply_channel_number_entry @0305225c */
const uint32_t dm32_pool_030524e8[12] = {
    0x0003e4e8,  /* IRAM */
    0x0003e711,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5f8,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9ae8,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
    0x0003e6ee,  /* IRAM */
};

/* 03052694-030526dc 72 bytes  pool of history_or_channel_selection_key_dispatch @03052518 */
const uint32_t dm32_pool_03052694[18] = {
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x0003e6cb,  /* IRAM */
    0x0003e734,  /* IRAM */
    0x0003e8f2,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e5df,  /* IRAM */
    0x0003ee6c,  /* IRAM */
    0x0003eff0,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003e6ee,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x030b9ae8,  /* flash data */
    0x030b1458,  /* flash data */
    0x0309df80,  /* flash data */
};

/* 03052814-03052840 44 bytes  pool of history_entry_cancel_pending @030527f4 */
const uint32_t dm32_pool_03052814[11] = {
    0x0003ea30,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x000320ac,  /* IRAM */
    0x0003ea33,  /* IRAM */
    0x000320af,  /* IRAM */
    0x030b01a4,  /* flash data */
    0x0003e5c4,  /* IRAM */
    0x000320b0,  /* IRAM */
    0x0000783c,
    0x0000783c,
};

/* 030529a0-030529c4 36 bytes  pool of menu_list_screen_render @03052840 */
const uint32_t dm32_pool_030529a0[9] = {
    0x0003e8f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e8f4,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b13c0,  /* flash data */
    0x030b13d0,  /* flash data */
    0x030b9bf0,  /* flash data */
    0x0003ee98,  /* IRAM */
};

/* 03052b24-03052b44 32 bytes  pool of list_cursor_advance_with_wrap @03052ad0 */
const uint32_t dm32_pool_03052b24[8] = {
    0x0003e1dc,  /* IRAM */
    0x0003e1c0,  /* IRAM */
    0x0003ee6c,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x030b1390,  /* flash data */
    0x0003e5d5,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e8f8,  /* IRAM */
};

/* 03052c78-03052c98 32 bytes  pool of call_record_line_advance_or_close_tx @03052c04 */
const uint32_t dm32_pool_03052c78[8] = {
    0x030b1390,  /* flash data */
    0x0003936c,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x00032ab7,  /* IRAM */
    0x00039342,  /* IRAM */
    0x0003936e,  /* IRAM */
    0x0003ea48,  /* IRAM */
    0x0003ea4b,  /* IRAM */
};

/* 03052e0c-03052e2c 32 bytes  pool of bitarray_set_or_clear_bit @03052dc4 */
const uint32_t dm32_pool_03052e0c[8] = {
    0x18000a94,
    0x0003e8f8,  /* IRAM */
    0x0003e904,  /* IRAM */
    0x18000a90,
    0x0003e5f8,  /* IRAM */
    0x0003ea4b,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9c38,  /* flash data */
};

/* 0305304c-03053060 20 bytes  pool of contact_char_index_to_display_code @03052e2c */
const uint32_t dm32_pool_0305304c[5] = {
    0x0003e8f8,  /* IRAM */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e8f4,  /* IRAM */
    0x0003ee98,  /* IRAM */
};

/* 03053278-0305329c 36 bytes  pool of dmr_contact_list_menu_row_render_group1 @03053180 */
const uint32_t dm32_pool_03053278[9] = {
    0x0003ee98,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9bc0,  /* flash data */
    0x0003e5cc,  /* IRAM */
    0x030b13e4,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x030b13f4,  /* flash data */
    0x0003e5d5,  /* IRAM */
    0x0003e8f4,  /* IRAM */
};

/* 03053620-0305364c 44 bytes  pool of dmr_contact_list_menu_row_render_group1 @03053180 */
const uint32_t dm32_pool_03053620[11] = {
    0x0003ee98,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9ba8,  /* flash data */
    0x0003e5cc,  /* IRAM */
    0x030b1404,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x030b1414,  /* flash data */
    0x30303030,
    0x0003e1dc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e8f4,  /* IRAM */
};

/* 03053ae4-03053afc 24 bytes  pool of dmr_list_headers_load_and_validate @03053998 */
const uint32_t dm32_pool_03053ae4[6] = {
    0x0003e5cc,  /* IRAM */
    0x030b1434,  /* flash data */
    0x0003e8f8,  /* IRAM */
    0x00032ab7,  /* IRAM */
    0x18000a94,
    0x0003fdb8,  /* IRAM */
};

/* 03054264-03054274 16 bytes  pool of list_record_lookup_and_toggle_by_index @03053f80 */
const uint32_t dm32_pool_03054264[4] = {
    0x00032ab7,  /* IRAM */
    0x0003e1c0,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003f330,  /* IRAM */
};

/* 030545dc-03054628 76 bytes  pool of menu_exit_timer_tick @030544ac */
const uint32_t dm32_pool_030545dc[19] = {
    0x00032abc,  /* IRAM */
    0x0003eb00,  /* IRAM */
    0x030b145c,  /* flash data */
    0x0305476c,  /* flash code */
    0x0003e3b4,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003ff84,  /* IRAM */
    0x18000a90,
    0x0003fd2c,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x00040106,  /* IRAM */
    0x000320ae,  /* IRAM */
    0x0003fdc0,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x18000b02,
    0x0003ee34,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 03054fb0-03054fcc 28 bytes  pool of display_lookup_channel_icon_and_bank @03054f44 */
const uint32_t dm32_pool_03054fb0[7] = {
    0x00038470,  /* IRAM */
    0x0003e8fe,  /* IRAM */
    0x0003e8f6,  /* IRAM */
    0x00032ab5,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x00032ab4,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 0305536c-0305538c 32 bytes  pool of audio_compander_calibration_apply @030551b0 */
const uint32_t dm32_pool_0305536c[8] = {
    0x18000ab8,
    0x00032ab5,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00032ab4,  /* IRAM */
    0x030b146c,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x0003e8fe,  /* IRAM */
    0x00038470,  /* IRAM */
};

/* 03055518-03055530 24 bytes  pool of byte_code_range_dispatch_to_fnptr_table @030554cc */
const uint32_t dm32_pool_03055518[6] = {
    0x0003e1dc,  /* IRAM */
    0x0003ebf6,  /* IRAM */
    0x0003ebf4,  /* IRAM */
    0x00032ab5,  /* IRAM */
    0x18000ab8,
    0x0003e8f6,  /* IRAM */
};

/* 030558c8-030558e8 32 bytes  pool of modem_buffer_char_remap_write_03055850 @03055850 */
const uint32_t dm32_pool_030558c8[8] = {
    0x0003ecfd,  /* IRAM */
    0x0003ecfc,  /* IRAM */
    0x0003ecfe,  /* IRAM */
    0x030af1e0,  /* flash data */
    0x16000900,
    0x0003e1dc,  /* IRAM */
    0x030af1f8,  /* flash data */
    0x030af210,  /* flash data */
};

/* 030565ec-03056614 40 bytes  pool of zone_list_cursor_increment @030565c4 */
const uint32_t dm32_pool_030565ec[10] = {
    0x0003e9b4,  /* IRAM */
    0x03081f78,  /* flash data */
    0x0003e434,  /* IRAM */
    0x00032ab6,  /* IRAM */
    0x030b14b0,  /* flash data */
    0x030b14bc,  /* flash data */
    0x030a80a0,  /* flash data */
    0x030a7e60,  /* flash data */
    0x030b79a8,  /* flash data */
    0x030b14c8,  /* flash data */
};

/* 03056df4-03056e08 20 bytes  pool of vfo_field_write_nibble_high @03056d40 */
const uint32_t dm32_pool_03056df4[5] = {
    0x0003e4e8,  /* IRAM */
    0x0003e63f,  /* IRAM */
    0x0003e8fc,  /* IRAM */
    0x0003ed02,  /* IRAM */
    0x0003e1dc,  /* IRAM */
};

/* 030571ec-030571fc 16 bytes  pool of channel_frequencies_read_and_decode @03057168 */
const uint32_t dm32_pool_030571ec[4] = {
    0x0003e330,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e144,  /* IRAM */
};

/* 030579c0-030579e0 32 bytes  pool of channel_change_apply_dispatcher @030573e8 */
const uint32_t dm32_pool_030579c0[8] = {
    0x000400d8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e358,  /* IRAM */
    0x0003e21c,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x030b9d98,  /* flash data */
};

/* 03057d78-03057d8c 20 bytes  pool of channel_change_apply_dispatcher @030573e8 */
const uint32_t dm32_pool_03057d78[5] = {
    0x0003e9b4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e1bc,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 03058110-0305813c 44 bytes  pool of channel_change_apply_dispatcher @030573e8 */
const uint32_t dm32_pool_03058110[11] = {
    0x0003e9b4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x18000b00,
    0x0003ecfe,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003eff8,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003fd70,  /* IRAM */
};

/* 030582b4-030582c8 20 bytes  pool of channel_change_apply_with_zone_and_flash_validate @03058180 */
const uint32_t dm32_pool_030582b4[5] = {
    0x0003fd90,  /* IRAM */
    0x0003e32a,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e3b4,  /* IRAM */
};

/* 03058c6c-03058ca4 56 bytes  pool of number_list_display_update @03058b18 */
const uint32_t dm32_pool_03058c6c[14] = {
    0x0003e1dc,  /* IRAM */
    0x030b1508,  /* flash data */
    0x0003e5cc,  /* IRAM */
    0x0003e5d5,  /* IRAM */
    0x0003e8f4,  /* IRAM */
    0x0003ed0c,  /* IRAM */
    0x18000a4c,
    0x18000a40,
    0x0003e9b4,  /* IRAM */
    0x0003e4e8,  /* IRAM */
    0x0003e662,  /* IRAM */
    0x030b8278,  /* flash data */
    0x030afcb4,  /* flash data */
    0x030ba0a8,  /* flash data */
};

/* 030592cc-030592ec 32 bytes  pool of display_format_id_with_separators @03059188 */
const uint32_t dm32_pool_030592cc[8] = {
    0x0003ee94,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003ee84,  /* IRAM */
};

/* 030597a8-030597d8 48 bytes  pool of text_entry_status_glyph_set_by_settings_flags_b @03059710 */
const uint32_t dm32_pool_030597a8[12] = {
    0x0003e9b4,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee94,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x18000b02,
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x030ba78c,  /* flash data */
    0x0003ff3c,  /* IRAM */
};

/* 03059944-030599a0 92 bytes  pool of dialog_request_init @03059860 */
const uint32_t dm32_pool_03059944[23] = {
    0x0003ee84,  /* IRAM */
    0x0003edf6,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x030ba788,  /* flash data */
    0x0003ee98,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003ee68,  /* IRAM */
    0x18000ab4,
    0x0003e9b4,  /* IRAM */
    0x18000b02,
    0x0003ee28,  /* IRAM */
    0x0003edf4,  /* IRAM */
    0x0003ee80,  /* IRAM */
    0x0003ed2a,  /* IRAM */
    0x0003ee74,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x030afae8,  /* flash data */
    0x030ba8d4,  /* flash data */
    0x00033500,  /* IRAM */
};

/* 03059f08-03059f34 44 bytes  pool of text_entry_char_picker_render @03059dfc */
const uint32_t dm32_pool_03059f08[11] = {
    0x0003ee30,  /* IRAM */
    0x0003ed24,  /* IRAM */
    0x0003edf4,  /* IRAM */
    0x0003ee2c,  /* IRAM */
    0x0003ee78,  /* IRAM */
    0x0003ee79,  /* IRAM */
    0x0003ee74,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x030ba78c,  /* flash data */
    0x0003ee80,  /* IRAM */
};

/* 0305a5ec-0305a620 52 bytes  pool of display_draw_single_char_or_gb2312_glyph @0305a4dc */
const uint32_t dm32_pool_0305a5ec[13] = {
    0x18000b02,
    0x0003ee90,  /* IRAM */
    0x0003edf5,  /* IRAM */
    0x0003edf8,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x18000ab4,
    0x00033500,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ee97,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x030ba788,  /* flash data */
};

/* 0305ab90-0305abd8 72 bytes  pool of draw_wrapped_text_conditional @0305ab40 */
const uint32_t dm32_pool_0305ab90[18] = {
    0x0003ed2b,  /* IRAM */
    0x0003ee79,  /* IRAM */
    0x0003ee30,  /* IRAM */
    0x0003ed24,  /* IRAM */
    0x0003edf4,  /* IRAM */
    0x0003ee2c,  /* IRAM */
    0x0003ee80,  /* IRAM */
    0x0003ee78,  /* IRAM */
    0x18000b02,
    0x0003ed2a,  /* IRAM */
    0x0003ee74,  /* IRAM */
    0x0003ee90,  /* IRAM */
    0x0003ee70,  /* IRAM */
    0x030b5300,  /* flash data */
    0x18000a90,
    0x0003efec,  /* IRAM */
    0x0003ee97,  /* IRAM */
    0x0003ee72,  /* IRAM */
};

/* 0305ad14-0305ad3c 40 bytes  pool of draw_wrapped_text_conditional @0305ab40 */
const uint32_t dm32_pool_0305ad14[10] = {
    0x0003ee72,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee99,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x18000b02,
    0x030ba78c,  /* flash data */
    0x0003efec,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003ee68,  /* IRAM */
    0x030ba788,  /* flash data */
};

/* 0305b01c-0305b04c 48 bytes  pool of ui_countdown_decrement_wrap @0305afe0 */
const uint32_t dm32_pool_0305b01c[12] = {
    0x0003ed28,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x18000b02,
    0x030b52e0,  /* flash data */
    0x030b5300,  /* flash data */
    0x0003ee70,  /* IRAM */
    0x0003ed2a,  /* IRAM */
    0x0003ed2b,  /* IRAM */
    0x0003ee80,  /* IRAM */
    0x0003ee74,  /* IRAM */
};

/* 0305b2e8-0305b308 32 bytes  pool of text_entry_scroll_and_display_refresh @0305b19c */
const uint32_t dm32_pool_0305b2e8[8] = {
    0x0003ee72,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x030ba78c,  /* flash data */
    0x0003efec,  /* IRAM */
    0x0003ee7b,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee68,  /* IRAM */
    0x030ba788,  /* flash data */
};

/* 0305b45c-0305b480 36 bytes  pool of text_entry_state_dispatch @0305b308 */
const uint32_t dm32_pool_0305b45c[9] = {
    0x18000b02,
    0x0003ed2a,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x030ba78c,  /* flash data */
    0x0003efec,  /* IRAM */
    0x0003ee97,  /* IRAM */
    0x0003ee68,  /* IRAM */
    0x030ba788,  /* flash data */
};

/* 0305b5f0-0305b61c 44 bytes  pool of radio_state_render_update @0305b480 */
const uint32_t dm32_pool_0305b5f0[11] = {
    0x18000b02,
    0x0003ee80,  /* IRAM */
    0x0003ee74,  /* IRAM */
    0x0003ed2a,  /* IRAM */
    0x0003ed2b,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x030ba78c,  /* flash data */
    0x0003ee97,  /* IRAM */
    0x0003ee68,  /* IRAM */
};

/* 0305b76c-0305b798 44 bytes  pool of text_entry_backspace_delete_char @0305b50c */
const uint32_t dm32_pool_0305b76c[11] = {
    0x0003ee68,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x18000b02,
    0x0003ee94,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x00033500,  /* IRAM */
    0x030ba788,  /* flash data */
};

/* 0305ba48-0305ba70 40 bytes  pool of text_entry_field_init_and_wrap_calc @0305ba00 */
const uint32_t dm32_pool_0305ba48[10] = {
    0x0003e1dc,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x0003ed28,  /* IRAM */
    0x0003ee68,  /* IRAM */
    0x18000b02,
    0x0003ee98,  /* IRAM */
    0x0003ee29,  /* IRAM */
    0x0003efec,  /* IRAM */
    0x0003ee82,  /* IRAM */
    0x0003ee94,  /* IRAM */
};

/* 0305bbe8-0305bc10 40 bytes  pool of radio_mode_entry_reinit_and_display @0305baec */
const uint32_t dm32_pool_0305bbe8[10] = {
    0x0003e1dc,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x000400d4,  /* IRAM */
    0x0003e1bc,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00040120,  /* IRAM */
};

/* 0305bdd4-0305bdfc 40 bytes  pool of radio_mode_entry_reinit_and_display @0305baec */
const uint32_t dm32_pool_0305bdd4[10] = {
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x030b7338,  /* flash data */
    0x0003ed28,  /* IRAM */
    0x0003ee72,  /* IRAM */
    0x030ba78c,  /* flash data */
    0x0003ee34,  /* IRAM */
};

/* 0305bf6c-0305bf8c 32 bytes  pool of tx_key_from_vfo_mode_guard @0305be64 */
const uint32_t dm32_pool_0305bf6c[8] = {
    0x0003e1dc,  /* IRAM */
    0x00040238,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x000334ec,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e1bc,  /* IRAM */
};

/* 0305c0f4-0305c120 44 bytes  pool of ptt_press_handler @0305bfb8 */
const uint32_t dm32_pool_0305c0f4[11] = {
    0x0002feac,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba208,  /* flash data */
    0x030ba210,  /* flash data */
    0x0003fdc8,  /* IRAM */
    0x0003e144,  /* IRAM */
    0x0003e1e0,  /* IRAM */
    0x0003e1bc,  /* IRAM */
};

/* 0305c278-0305c2a0 40 bytes  pool of ptt_press_handler @0305bfb8 */
const uint32_t dm32_pool_0305c278[10] = {
    0x0003e144,  /* IRAM */
    0x0003e1bc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x00038470,  /* IRAM */
    0x000334c0,  /* IRAM */
    0x030b7340,  /* flash data */
};

/* 0305c954-0305c970 28 bytes  pool of ptt_press_handler @0305bfb8 */
const uint32_t dm32_pool_0305c954[7] = {
    0x0003e0c0,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b9ee8,  /* flash data */
    0x030b9e58,  /* flash data */
};

/* 0305cf38-0305cf60 40 bytes  pool of channel_select_type_dispatch @0305ce84 */
const uint32_t dm32_pool_0305cf38[10] = {
    0x0003e0c0,  /* IRAM */
    0x000334c0,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b97d8,  /* flash data */
    0x0003e1dc,  /* IRAM */
    0x030ba220,  /* flash data */
    0x0003e318,  /* IRAM */
    0x00040078,  /* IRAM */
    0x0003f006,  /* IRAM */
    0x030b734c,  /* flash data */
};

/* 0305d6ec-0305d6fc 16 bytes  pool of apply_flags_from_flash_0x65_0x66 @0305d544 */
const uint32_t dm32_pool_0305d6ec[4] = {
    0x0003fd58,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
};

/* 0305dab4-0305dac8 20 bytes  pool of dialog_commit_channel_selection @0305d9bc */
const uint32_t dm32_pool_0305dab4[5] = {
    0x0003fd2c,  /* IRAM */
    0x0003bd50,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e0ee,  /* IRAM */
    0x0003e0c0,  /* IRAM */
};

/* 0305deec-0305df04 24 bytes  pool of channel_forward_navigation_commit @0305dd94 */
const uint32_t dm32_pool_0305deec[6] = {
    0x0003e144,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003ff38,  /* IRAM */
};

/* 0305e478-0305e4a4 44 bytes  pool of event_flags_dispatch_bit8_group @0305e318 */
const uint32_t dm32_pool_0305e478[11] = {
    0x0003fdc8,  /* IRAM */
    0x0003ffdc,  /* IRAM */
    0x0003fd2c,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x00040120,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030bb9a0,  /* flash data */
    0x030ba238,  /* flash data */
    0x0003f004,  /* IRAM */
    0x0003e0c0,  /* IRAM */
};

/* 0305e648-0305e664 28 bytes  pool of event_flags_dispatch_bit8_group @0305e318 */
const uint32_t dm32_pool_0305e648[7] = {
    0x0003fdc8,  /* IRAM */
    0x00040120,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030bb9a8,  /* flash data */
    0x0003fd2c,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003fd70,  /* IRAM */
};

/* 0305f118-0305f128 16 bytes  pool of flash_quad_enable_and_system_reset @0305ef30 */
const uint32_t dm32_pool_0305f118[4] = {
    0x0003fdc1,  /* IRAM */
    0x0003fdc0,  /* IRAM */
    0x0003fdc4,  /* IRAM */
    0x0003fdc5,  /* IRAM */
};

/* 0305fbbc-0305fbe0 36 bytes  pool of channel_switch_teardown_and_apply @0305fa38 */
const uint32_t dm32_pool_0305fbbc[9] = {
    0x0003e318,  /* IRAM */
    0x00040254,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x00040238,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
};

/* 0305fd5c-0305fd7c 32 bytes  pool of idle_background_notify_counter @0305fcd4 */
const uint32_t dm32_pool_0305fd5c[8] = {
    0x0003fdb8,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003fdcc,  /* IRAM */
    0x0003e1bc,  /* IRAM */
    0x0003e38c,  /* IRAM */
};

/* 0305ff34-0305ff44 16 bytes  pool of signal_meter_bargraph_draw @0305fd90 */
const uint32_t dm32_pool_0305ff34[4] = {
    0x0003fdb8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x000320af,  /* IRAM */
    0x000400d8,  /* IRAM */
};

/* 03060300-0306032c 44 bytes  pool of FUN_03060280 @03060280 */
const uint32_t dm32_pool_03060300[11] = {
    0x0003fddc,  /* IRAM */
    0x0003fde4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x00038470,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003382f,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003e134,  /* IRAM */
    0x0003e144,  /* IRAM */
};

/* 03060850-03060884 52 bytes  pool of tx_state_main_task_loop @03060754 */
const uint32_t dm32_pool_03060850[13] = {
    0x0003fdb8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
    0x0003fde4,  /* IRAM */
    0x00040106,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e1bc,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003fd90,  /* IRAM */
    0x0003ebf0,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003ff84,  /* IRAM */
    0x0003e38c,  /* IRAM */
};

/* 03061490-030614c8 56 bytes  pool of recording_list_screen @0306139c */
const uint32_t dm32_pool_03061490[14] = {
    0x030adb48,  /* flash data */
    0x0003ffc8,  /* IRAM */
    0x0003ffd0,  /* IRAM */
    0x0003ffbc,  /* IRAM */
    0x0003ffd4,  /* IRAM */
    0x030adb4c,  /* flash data */
    0x0003ff80,  /* IRAM */
    0x0003ffb8,  /* IRAM */
    0x0003ffc4,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030b7488,  /* flash data */
    0x030b7494,  /* flash data */
    0x030b74a4,  /* flash data */
    0x03096f60,  /* flash data */
};

/* 03061af4-03061b0c 24 bytes  pool of call_record_detail_render @030617f0 */
const uint32_t dm32_pool_03061af4[6] = {
    0x0308a4d0,  /* flash data */
    0x0308add0,  /* flash data */
    0x030b74dc,  /* flash data */
    0x030b74f4,  /* flash data */
    0x030b1044,  /* flash data */
    0x0003ff84,  /* IRAM */
};

/* 03061e54-03061e74 32 bytes  pool of analog_digital_channel_tracking_sync @03061cfc */
const uint32_t dm32_pool_03061e54[8] = {
    0x0003e38c,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003ffdc,  /* IRAM */
    0x000400ec,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x030b7508,  /* flash data */
    0x0003fd2c,  /* IRAM */
};

/* 0306262c-0306265c 48 bytes  pool of gps_nmea_gprmc_parser @03062290 */
const uint32_t dm32_pool_0306262c[12] = {
    0x00038c79,  /* IRAM */
    0x0003ffe0,  /* IRAM */
    0x03081ed0,  /* flash data */
    0x00038d48,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x00040078,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00038c6c,  /* IRAM */
};

/* 03062fc8-03062fe4 28 bytes  pool of channel_list_screen_render @03062ed8 */
const uint32_t dm32_pool_03062fc8[7] = {
    0x0003944c,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030af9e8,  /* flash data */
    0x030b772c,  /* flash data */
    0x030b773c,  /* flash data */
    0x030b7744,  /* flash data */
};

/* 030633b4-030633cc 24 bytes  pool of gps_coordinate_pair_distance_calc @0306319c */
const uint32_t dm32_pool_030633b4[6] = {
    0x030b7584,  /* flash data */
    0x030b758c,  /* flash data */
    0x00033c38,  /* IRAM */
    0x030b7594,  /* flash data */
    0x030b759c,  /* flash data */
    0x030b75a4,  /* flash data */
};

/* 0306364c-030636a0 84 bytes  pool of gps_coordinate_pair_distance_calc @0306319c */
const uint32_t dm32_pool_0306364c[21] = {
    0x030b759c,  /* flash data */
    0x00033c38,  /* IRAM */
    0x030b75ac,  /* flash data */
    0x030b75b4,  /* flash data */
    0x030b758c,  /* flash data */
    0x030b75bc,  /* flash data */
    0x030b75c4,  /* flash data */
    0x030b75cc,  /* flash data */
    0x030b75d4,  /* flash data */
    0x030b75dc,  /* flash data */
    0x030b75e4,  /* flash data */
    0x030b75ec,  /* flash data */
    0x030b75f4,  /* flash data */
    0x030b75fc,  /* flash data */
    0x030b7604,  /* flash data */
    0x030b760c,  /* flash data */
    0x030b7614,  /* flash data */
    0x030b761c,  /* flash data */
    0x030b7624,  /* flash data */
    0x030b762c,  /* flash data */
    0x030b7634,  /* flash data */
};

/* 03063ad0-03063af4 36 bytes  pool of gps_position_display_screen @030636e0 */
const uint32_t dm32_pool_03063ad0[9] = {
    0x030b770c,  /* flash data */
    0x030a1bc0,  /* flash data */
    0x00038c6c,  /* IRAM */
    0x00038c79,  /* IRAM */
    0x0004009c,  /* IRAM */
    0x00040078,  /* IRAM */
    0x030b763c,  /* flash data */
    0x030b76f0,  /* flash data */
    0x030b7714,  /* flash data */
};

/* 03063ff4-03064018 36 bytes  pool of flash_block6_pattern_match_mode_entry @03063e58 */
const uint32_t dm32_pool_03063ff4[9] = {
    0x00040238,  /* IRAM */
    0x000400c0,  /* IRAM */
    0x000400a8,  /* IRAM */
    0x000400a9,  /* IRAM */
    0x000400c4,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x000400ac,  /* IRAM */
    0x00040240,  /* IRAM */
    0x0003e318,  /* IRAM */
};

/* 03064174-0306419c 40 bytes  pool of flash_block6_pattern_match_mode_entry @03063e58 */
const uint32_t dm32_pool_03064174[10] = {
    0x00040238,  /* IRAM */
    0x000400c4,  /* IRAM */
    0x00040254,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x00040190,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e38c,  /* IRAM */
    0x000400c0,  /* IRAM */
    0x000400a8,  /* IRAM */
};

/* 03064838-03064858 32 bytes  pool of flash_pending_action_scan_and_apply @030645f8 */
const uint32_t dm32_pool_03064838[8] = {
    0x000400d8,  /* IRAM */
    0x00040240,  /* IRAM */
    0x00040238,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x000400a8,  /* IRAM */
    0x000400c0,  /* IRAM */
    0x00040254,  /* IRAM */
    0x000400dc,  /* IRAM */
};

/* 030657f4-0306580c 24 bytes  pool of rda5807m_power_down @030657c0 */
const uint32_t dm32_pool_030657f4[6] = {
    0x030b790c,  /* flash data */
    0x00040108,  /* IRAM */
    0x0003b9d0,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x00040114,  /* IRAM */
    0x00040104,  /* IRAM */
};

/* 03065c44-03065c58 20 bytes  pool of battery_value_display_format @03065a10 */
const uint32_t dm32_pool_03065c44[5] = {
    0x0003b9d0,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x00040114,  /* IRAM */
    0x00040104,  /* IRAM */
    0x0003e9b4,  /* IRAM */
};

/* 03066180-030661a8 40 bytes  pool of is_memory_channel_not_vfo @030660b8 */
const uint32_t dm32_pool_03066180[10] = {
    0x00040120,  /* IRAM */
    0x0004011c,  /* IRAM */
    0x0004011e,  /* IRAM */
    0x000320af,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x0003e1dc,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x03081f78,  /* flash data */
    0x0003e434,  /* IRAM */
    0x00032ab6,  /* IRAM */
};

/* 030664b8-030664d0 24 bytes  pool of list_cursor_decrement_then_channel_scrolling_list_render_with_roaming @0306649c */
const uint32_t dm32_pool_030664b8[6] = {
    0x00040120,  /* IRAM */
    0x00040138,  /* IRAM */
    0x0003fdb8,  /* IRAM */
    0x0003ee98,  /* IRAM */
    0x0004011a,  /* IRAM */
    0x00040139,  /* IRAM */
};

/* 0306666c-03066680 20 bytes  pool of roam_zone_countdown_decrement_with_limit @030665f4 */
const uint32_t dm32_pool_0306666c[5] = {
    0x0004011a,  /* IRAM */
    0x00040139,  /* IRAM */
    0x00040120,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x030ba150,  /* flash data */
};

/* 03066de4-03066df4 16 bytes  pool of sdcard_spi_probe_and_init @03066ae0 */
const uint32_t dm32_pool_03066de4[4] = {
    0x00033c40,  /* IRAM */
    0x0004013c,  /* IRAM */
    0x0003944c,  /* IRAM */
    0x0003cf00,  /* IRAM */
};

/* 0306747c-03067494 24 bytes  pool of favorite_channel_scan_confirm_and_switch @03067290 */
const uint32_t dm32_pool_0306747c[6] = {
    0x00040190,  /* IRAM */
    0x00040238,  /* IRAM */
    0x00040254,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00038688,  /* IRAM */
};

/* 03067e50-03067e60 16 bytes  pool of block7_parity_bit_interleave_encode @03067b18 */
const uint32_t dm32_pool_03067e50[4] = {
    0x030bfc08,  /* flash data */
    0x00040224,  /* IRAM */
    0x0003e9b4,  /* IRAM */
    0x0003e1dc,  /* IRAM */
};

/* 030682a8-030682bc 20 bytes  pool of call_hold_led_debounce_dual_timer_tick @03068224 */
const uint32_t dm32_pool_030682a8[5] = {
    0x00040254,  /* IRAM */
    0x0003e318,  /* IRAM */
    0x00040238,  /* IRAM */
    0x000400d8,  /* IRAM */
    0x0003fdc8,  /* IRAM */
};

/* 0306843c-03068450 20 bytes  pool of factory_service_command_dispatch @030682bc */
const uint32_t dm32_pool_0306843c[5] = {
    0x0003e318,  /* IRAM */
    0x0003e1c0,  /* IRAM */
    0x00038e20,  /* IRAM */
    0x0003fdc8,  /* IRAM */
    0x0003e0c0,  /* IRAM */
};

/* 03068ec4-03068ee4 32 bytes  pool of queue_list_init_and_register @03068db4 */
const uint32_t dm32_pool_03068ec4[8] = {
    0x454e4f4e,
    0x03076688,  /* flash data */
    0x00042b10,  /* IRAM */
    0x000426be,  /* IRAM */
    0x030bf624,  /* flash data */
    0x000426d8,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x47414c46,
};

/* 030698a8-030698b8 16 bytes  pool of scheduled_task_state_advance_with_queue_promotion @03069738 */
const uint32_t dm32_pool_030698a8[4] = {
    0x000426d8,  /* IRAM */
    0x5854554d,
    0x00042500,  /* IRAM */
    0x0004250d,  /* IRAM */
};

/* 03069a20-03069a30 16 bytes  pool of ucos3_sched_lock_time_stop_irq_restore @030699a8 */
const uint32_t dm32_pool_03069a20[4] = {
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x00042500,  /* IRAM */
    0x000426d8,  /* IRAM */
};

/* 03069dc0-03069dec 44 bytes  pool of OSMutexCreate @03069d20 */
const uint32_t dm32_pool_03069dc0[11] = {
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x00042500,  /* IRAM */
    0x00042cc0,  /* IRAM */
    0x454e4f4e,
    0x03076690,  /* flash data */
    0x030bf624,  /* flash data */
    0x000426cc,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x5854554d,
    0x00042a38,  /* IRAM */
};

/* 03069f54-03069f6c 24 bytes  pool of dlist_unlink_msgq @03069dec */
const uint32_t dm32_pool_03069f54[6] = {
    0x000426cc,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x5854554d,
    0x0004250d,  /* IRAM */
    0x00042a38,  /* IRAM */
    0x00042a3a,  /* IRAM */
};

/* 0306a5a8-0306a5c8 32 bytes  pool of critical_section_counted_init_dispatch @0306a500 */
const uint32_t dm32_pool_0306a5a8[8] = {
    0x55455551,
    0x0004250d,  /* IRAM */
    0x454e4f4e,
    0x03076698,  /* flash data */
    0x030bf624,  /* flash data */
    0x00042708,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x000426f8,  /* IRAM */
};

/* 0306ad6c-0306ad94 40 bytes  pool of cpu_and_channel_load_statistics_task @0306aa2c */
const uint32_t dm32_pool_0306ad6c[10] = {
    0x000426e8,  /* IRAM */
    0x00042a24,  /* IRAM */
    0x000426fc,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x00061a7f,
    0x003d08ff,
    0x026259ff,
    0x17d783ff,
    0x0004250c,  /* IRAM */
    0x00042cb4,  /* IRAM */
};

/* 0306b048-0306b05c 20 bytes  pool of dmr_command_subop_dispatch_with_crit_section @0306af04 */
const uint32_t dm32_pool_0306b048[5] = {
    0x000426d8,  /* IRAM */
    0x20524d54,
    0x0004270c,  /* IRAM */
    0x454e4f4e,
    0x030766b0,  /* flash data */
};

/* 0306b190-0306b1a4 20 bytes  pool of OSTmrCreate @0306b078 */
const uint32_t dm32_pool_0306b190[5] = {
    0x000426d4,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x20524d54,
    0x000426ee,  /* IRAM */
};

/* 0306b308-0306b350 72 bytes  pool of rate_counter_init_and_task_create_dispatch @0306b1a4 */
const uint32_t dm32_pool_0306b308[18] = {
    0x000426d4,  /* IRAM */
    0x03076668,  /* flash data */
    0x03076644,  /* flash data */
    0x00042508,  /* IRAM */
    0x00042a28,  /* IRAM */
    0x0004270c,  /* IRAM */
    0x00042704,  /* IRAM */
    0x0307667c,  /* flash data */
    0x000411b4,  /* IRAM */
    0x0307666c,  /* flash data */
    0x03076674,  /* flash data */
    0x03076640,  /* flash data */
    0x03076664,  /* flash data */
    0x03076670,  /* flash data */
    0x000425ec,  /* IRAM */
    0x030766b8,  /* flash data */
    0x0306b408,  /* flash code */
    0x000411b0,  /* IRAM */
};

/* 0306b4cc-0306b4e8 28 bytes  pool of soft_timer_wheel_task @0306b408 */
const uint32_t dm32_pool_0306b4cc[7] = {
    0x000411b0,  /* IRAM */
    0x000411b4,  /* IRAM */
    0x0307667c,  /* flash data */
    0x000411b6,  /* IRAM */
    0x0004270c,  /* IRAM */
    0x00042704,  /* IRAM */
    0x000426d8,  /* IRAM */
};

/* 030bff08-030bff2c 36 bytes  pool of OS_SchedLockTimeMeasStart_variant3 @030bfe5c */
const uint32_t dm32_pool_030bff08[9] = {
    0x00045640,  /* IRAM */
    0x0004561c,  /* IRAM */
    0x00045638,  /* IRAM */
    0x0004563c,  /* IRAM */
    0x00045618,  /* IRAM */
    0x00045624,  /* IRAM */
    0x00045614,  /* IRAM */
    0x00045620,  /* IRAM */
    0x00045628,  /* IRAM */
};

/* 030c00d4-030c00fc 40 bytes  pool of thin_wrapper_to_030c0000 @030c004c */
const uint32_t dm32_pool_030c00d4[10] = {
    0x00045628,  /* IRAM */
    0x0004561c,  /* IRAM */
    0x00045618,  /* IRAM */
    0x00045624,  /* IRAM */
    0x00045614,  /* IRAM */
    0x00045620,  /* IRAM */
    0x00045638,  /* IRAM */
    0x0004563c,  /* IRAM */
    0x00045640,  /* IRAM */
    0x030763fc,  /* flash data */
};

/* 030c05b0-030c05d8 40 bytes  pool of OS_Sched @030c0554 */
const uint32_t dm32_pool_030c05b0[10] = {
    0x00042514,  /* IRAM */
    0x000425e8,  /* IRAM */
    0x00042710,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x00042ca8,  /* IRAM */
    0x0004271c,  /* IRAM */
    0x00042cac,  /* IRAM */
    0x00042500,  /* IRAM */
    0x000426f4,  /* IRAM */
};

/* 030c17e4-030c17f4 16 bytes  pool of timed_task_teardown_with_status_report @030c1678 */
const uint32_t dm32_pool_030c17e4[4] = {
    0x000426d8,  /* IRAM */
    0x414d4553,
    0x0004250d,  /* IRAM */
    0x00042500,  /* IRAM */
};

/* 030c1b04-030c1b24 32 bytes  pool of OSSemCreate_variant2 @030c19dc */
const uint32_t dm32_pool_030c1b04[8] = {
    0x454e4f4e,
    0x03076540,  /* flash data */
    0x030bf624,  /* flash data */
    0x00042a20,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x414d4553,
    0x000426bc,  /* IRAM */
};

/* 030c23c4-030c23d4 16 bytes  pool of timed_task_advance_with_timestamp_delta_tracking @030c2340 */
const uint32_t dm32_pool_030c23c4[4] = {
    0x0004250d,  /* IRAM */
    0x00042500,  /* IRAM */
    0x000426ec,  /* IRAM */
    0x000426d8,  /* IRAM */
};

/* 030c2b04-030c2b24 32 bytes  pool of OSTaskCreate_variant2 @030c29f8 */
const uint32_t dm32_pool_030c2b04[8] = {
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x000425e4,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x03076640,  /* flash data */
    0x00042a44,  /* IRAM */
    0x00042b14,  /* IRAM */
    0x000425e0,  /* IRAM */
};

/* 030c2ccc-030c2ce0 20 bytes  pool of OSTaskCreate_variant2 @030c29f8 */
const uint32_t dm32_pool_030c2ccc[5] = {
    0x0004250d,  /* IRAM */
    0x000425e4,  /* IRAM */
    0x00042710,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x00042500,  /* IRAM */
};

/* 030c2e5c-030c2e6c 16 bytes  pool of event_post_checked_isr_aware @030c2dec */
const uint32_t dm32_pool_030c2e5c[4] = {
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x47534d54,
};

/* 030c2fec-030c2ffc 16 bytes  pool of command_send_task_or_isr_queue @030c2f88 */
const uint32_t dm32_pool_030c2fec[4] = {
    0x0004250d,  /* IRAM */
    0x00042500,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x53455254,
};

/* 030c32d8-030c32e8 16 bytes  pool of ucos_event_post_or_queue_isr_aware @030c3284 */
const uint32_t dm32_pool_030c32d8[4] = {
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x47495354,
};

/* 030c345c-030c3470 20 bytes  pool of radio_command_jumptable_dispatch_flash @030c32e8 */
const uint32_t dm32_pool_030c345c[5] = {
    0x0004250d,  /* IRAM */
    0x00042b14,  /* IRAM */
    0x00042a44,  /* IRAM */
    0x000426d8,  /* IRAM */
    0x53555354,
};

/* 030c387c-030c388c 16 bytes  pool of timer_expiry_task @030c3854 */
const uint32_t dm32_pool_030c387c[4] = {
    0x00042714,  /* IRAM */
    0x0004250d,  /* IRAM */
    0x00042a3a,  /* IRAM */
    0x00042710,  /* IRAM */
};

/* 030c5e90-030c5eb4 36 bytes  pool of grid_draw_checked_timed_a @030c5dc8 */
const uint32_t dm32_pool_030c5e90[9] = {
    0x18000bd0,
    0x00049b39,  /* IRAM */
    0x0004a73c,  /* IRAM */
    0x0004a757,  /* IRAM */
    0x00045698,  /* IRAM */
    0x00048124,  /* IRAM */
    0x00048128,  /* IRAM */
    0x00048143,  /* IRAM */
    0x00045648,  /* IRAM */
};

/* 030c62b8-030c62d8 32 bytes  pool of FUN_030c6238 @030c6238 */
const uint32_t dm32_pool_030c62b8[8] = {
    0x00048160,  /* IRAM */
    0x00046b5c,  /* IRAM */
    0x00049b38,  /* IRAM */
    0x000456c0,  /* IRAM */
    0x00049b39,  /* IRAM */
    0x0004a73c,  /* IRAM */
    0x00048128,  /* IRAM */
    0x00048124,  /* IRAM */
};

