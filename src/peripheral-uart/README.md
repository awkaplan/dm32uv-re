# peripheral-uart

17 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 10 |
| STRUCTURAL | 7 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x0002c0f8` | `serial_flash_sector_erase_then_poll_ready` | 102 | STRUCTURAL |
| `0x0002c160` | `serial_flash_write_chunk_with_retry` | 78 | STRUCTURAL |
| `0x0002ce78` | `uart_tx_poll_mutex_guarded` | 42 | CONFIRMED |
| `0x03001bc8` | `uart0_set_baud_divisor` | 56 | CONFIRMED |
| `0x03002c30` | `serial_command_phase_tracker_and_dispatch` | 152 | STRUCTURAL |
| `0x030118b0` | `serial_rx_ringbuffer_line_extract` | 124 | CONFIRMED |
| `0x030119f4` | `uart_tx_string_with_trailer` | 76 | STRUCTURAL |
| `0x0301d9d4` | `uart_tx_chunked_mutex_send` | 116 | CONFIRMED |
| `0x0301da48` | `uart0_init` | 96 | CONFIRMED |
| `0x030253a0` | `serial_frame_classify_and_extract_ids` | 372 | STRUCTURAL |
| `0x03025514` | `serial_9bit_frame_handler_with_crc_validate` | 1662 | CONFIRMED |
| `0x03028c5e` | `serial_9bit_frame_validate_entry` | 6 | STRUCTURAL |
| `0x0302a044` | `serial_protocol_vframe_command_loop` | 1042 | CONFIRMED |
| `0x0302a4dc` | `serial_protocol_vframe_command_loop_variant` | 1252 | CONFIRMED |
| `0x0302b2b8` | `serial_password_command_handler` | 262 | CONFIRMED |
| `0x03067978` | `uart_rx_frame_assemble_polarity_correct` | 362 | STRUCTURAL |
| `0x030c3f24` | `serial_clock_out_byte_to_companion_chip` | 282 | CONFIRMED |
