# peripheral-mmio

16 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 6 |
| STRUCTURAL | 10 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x0002e35c` | `mmio_110003b0_bit4_set` | 16 | STRUCTURAL |
| `0x0002e36c` | `mmio_110003b0_bit5_set` | 16 | STRUCTURAL |
| `0x03001bb0` | `mmio_dummy_read_1400000c` | 8 | CONFIRMED |
| `0x0300eb44` | `reg_0xc_bit1_read` | 14 | STRUCTURAL |
| `0x0300ebb0` | `reg_0x67_lower9_read` | 14 | STRUCTURAL |
| `0x0301d900` | `mmio_14000000_timer_config` | 32 | STRUCTURAL |
| `0x0301e578` | `mmio_11000074_bits_7_8_set_clear` | 32 | STRUCTURAL |
| `0x0301e5bc` | `mmio_11000088_bool_set` | 28 | STRUCTURAL |
| `0x0301e864` | `mmio_11000384_low_byte_write` | 26 | CONFIRMED |
| `0x0302070c` | `mmio_read_16bit_offset_14` | 6 | STRUCTURAL |
| `0x0302180c` | `mmio_11000108_high_word_write_from_byte` | 32 | CONFIRMED |
| `0x03021830` | `mmio_11000114_low_word_duplicate_write` | 26 | CONFIRMED |
| `0x03054e58` | `mmio_11000114_low_word_duplicate_write_fwd_thunk` | 10 | STRUCTURAL |
| `0x03054e64` | `mmio_11000108_high_word_write_from_byte_fwd_thunk` | 10 | STRUCTURAL |
| `0x0305ba70` | `mmio_11000074_bits78_set_from_status_nibble` | 44 | CONFIRMED |
| `0x0306cf10` | `mmio_dummy_read_1400000c_dup` | 8 | CONFIRMED |
