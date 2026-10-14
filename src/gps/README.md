# gps

20 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 10 |
| STRUCTURAL | 10 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x03011450` | `nmea_latlon_pack_deg_1e5` | 130 | CONFIRMED |
| `0x030114f4` | `gps_coordinate_seconds_to_hms_string_format` | 146 | CONFIRMED |
| `0x030116cc` | `gps_power_set` | 122 | STRUCTURAL |
| `0x0301192c` | `nmea_sentence_checksum_from_ring_buffer` | 112 | CONFIRMED |
| `0x03011aa4` | `gps_coordinate_table_entry_parse` | 124 | CONFIRMED |
| `0x03011b40` | `gps_datetime_format` | 466 | STRUCTURAL |
| `0x0301265c` | `gps_nmea_datetime_to_rtc_sync` | 248 | CONFIRMED |
| `0x03012758` | `gps_nmea_rmc_gga_sentence_parser` | 868 | CONFIRMED |
| `0x03015824` | `gps_refresh_gated_by_tx_state` | 154 | STRUCTURAL |
| `0x0301d96c` | `gps_uart1_init_9600` | 102 | CONFIRMED |
| `0x030390f0` | `gps_lock_status_or_band_select_screen` | 170 | STRUCTURAL |
| `0x03062138` | `gps_time_compact_format` | 322 | CONFIRMED |
| `0x03062290` | `gps_nmea_gprmc_parser` | 594 | CONFIRMED |
| `0x03062510` | `gps_display_refresh_and_notify` | 172 | STRUCTURAL |
| `0x030625bc` | `gps_display_periodic_refresh_tick` | 112 | STRUCTURAL |
| `0x03062d2c` | `gps_log_record_append_compact` | 342 | STRUCTURAL |
| `0x03062fe4` | `gps_coordinate_normalize_pair` | 168 | STRUCTURAL |
| `0x030630b4` | `gps_coordinate_distance_soft_float` | 222 | STRUCTURAL |
| `0x0306319c` | `gps_coordinate_pair_distance_calc` | 1234 | STRUCTURAL |
| `0x030636e0` | `gps_position_display_screen` | 1246 | CONFIRMED |
