# alpu-anticlone

19 functions.

| Confidence | Count |
|---|---|
| CONFIRMED | 17 |
| STRUCTURAL | 2 |
| RAW | 0 |

| Address | Function | Size | Confidence |
|---|---|---|---|
| `0x00014304` | `i2c_send_byte_wait_ack` | 282 | CONFIRMED |
| `0x00014424` | `i2c_write_block_0x7a` | 216 | CONFIRMED |
| `0x000144fc` | `i2c_read_block_0x7a` | 404 | CONFIRMED |
| `0x00015d8c` | `alpu_boot_sem_create_and_auth_init` | 120 | STRUCTURAL |
| `0x00016b60` | `alpu_nonce_byte_next` | 110 | STRUCTURAL |
| `0x00016bdc` | `alpu_auth_gate_3retry` | 148 | CONFIRMED |
| `0x0001e8bc` | `alpu_handshake_challenge_read_32byte` | 568 | CONFIRMED |
| `0x0001eafc` | `alpu_cipher_invert_and_fold_halfblock` | 252 | CONFIRMED |
| `0x0001ebf8` | `alpu_cipher_xor_mix_and_swap_halves` | 318 | CONFIRMED |
| `0x0001ed38` | `alpu_cipher_byte_rotate_right` | 228 | CONFIRMED |
| `0x0001ee1c` | `alpu_cipher_block_rotate_left` | 226 | CONFIRMED |
| `0x0001ef00` | `alpu_cipher_byte_permute` | 294 | CONFIRMED |
| `0x0001f028` | `alpu_block_cipher` | 1394 | CONFIRMED |
| `0x0001f5b0` | `alpu_challenge_response_auth` | 486 | CONFIRMED |
| `0x0001f798` | `alpu_handshake_response_write_16byte` | 450 | CONFIRMED |
| `0x0001f96c` | `alpu_handshake_step_sequence` | 1238 | CONFIRMED |
| `0x0002ced4` | `alpu_i2c_shift_out_byte` | 128 | CONFIRMED |
| `0x0002d184` | `alpu_i2c_shift_in_byte` | 122 | CONFIRMED |
| `0x0306fea4` | `lcg_rand_next` | 20 | CONFIRMED |
