# peripheral-gpio

17 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 10 |
| STRUCTURAL | 7 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x0002c544` | `gpio_clear_output_bit` | 68 | CONFIRMED |
| `0x0002c588` | `gpio_read_input_bit` | 80 | CONFIRMED |
| `0x0002c5d8` | `gpio_interrupt_disable_bit` | 68 | CONFIRMED |
| `0x0002c61c` | `gpio_interrupt_enable_bit_with_polarity` | 188 | CONFIRMED |
| `0x03001124` | `gpio_drv_set_output` | 248 | CONFIRMED |
| `0x0300121c` | `gpio_pin_configure` | 916 | CONFIRMED |
| `0x030015b0` | `gpio_pin_read` | 80 | CONFIRMED |
| `0x03001600` | `board_gpio_init` | 138 | CONFIRMED |
| `0x03003c3c` | `gpio_set_output_bit_variant2` | 68 | STRUCTURAL |
| `0x03003c80` | `gpio_clear_output_bit_variant2` | 68 | STRUCTURAL |
| `0x0300c3cc` | `gpio_clear_bit0_wrapper` | 8 | CONFIRMED |
| `0x030135d8` | `gpio_portb_read_input_bits_17_to_20` | 12 | CONFIRMED |
| `0x0301d184` | `gpio_pin_set_output_level` | 240 | STRUCTURAL |
| `0x0301d4c8` | `gpio_interrupt_enable_bit` | 68 | STRUCTURAL |
| `0x0301d50c` | `board_gpio_defaults_and_encoder_irq_arm` | 208 | STRUCTURAL |
| `0x0301d830` | `gpio_clear_bit0` | 12 | STRUCTURAL |
| `0x03029420` | `gpio_clear_bit0_if_flag_clear` | 30 | STRUCTURAL |
