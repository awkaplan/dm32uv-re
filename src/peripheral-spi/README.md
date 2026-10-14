# peripheral-spi

15 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 8 |
| STRUCTURAL | 7 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x0002bf90` | `spi_controller_single_byte_xfer` | 50 | CONFIRMED |
| `0x0300f3d0` | `spi_flash_pending_update_scan_and_invalidate` | 278 | CONFIRMED |
| `0x030105d0` | `spi_flash_log_append_2byte` | 174 | CONFIRMED |
| `0x030106b4` | `spi_flash_dual_log_reset_with_marker_scan` | 330 | CONFIRMED |
| `0x0301c94c` | `spi_m0_init_flash_cs_high` | 68 | CONFIRMED |
| `0x0301c998` | `spi_drv_txrx` | 50 | CONFIRMED |
| `0x0301c9cc` | `spi_m3_select_and_read_block` | 60 | CONFIRMED |
| `0x0301ca08` | `spi_m3_efuse_init_and_read8` | 60 | STRUCTURAL |
| `0x03061280` | `spi_flash_config_block_magic_scan` | 282 | CONFIRMED |
| `0x030667e8` | `spi_sdcard_read_status_register` | 40 | STRUCTURAL |
| `0x03066810` | `spi_sdcard_select_and_wait_ready` | 34 | STRUCTURAL |
| `0x03066888` | `spi_sdcard_sync_byte_probe` | 78 | STRUCTURAL |
| `0x030668e0` | `spi_sdcard_block_write_512_with_response_check` | 134 | STRUCTURAL |
| `0x03066968` | `spi_sdcard_send_command` | 140 | STRUCTURAL |
| `0x03066d24` | `spi_sdcard_block_write_dispatch` | 148 | STRUCTURAL |
