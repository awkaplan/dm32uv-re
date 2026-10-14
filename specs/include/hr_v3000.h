/*
 * hr_v3000.h - the UART protocol of the Hongrui HR_V3000 vocoder (an STM32F303RC running DVSI's
 * AMBE++ as a software core): packet types, command codes, the ECMODE/DCMODE mode-word bits and
 * byte-exact frame layouts. HAND-MAINTAINED. For C code and for Ghidra (File > Parse C Source,
 * then apply the structs/enums to a vocoder driver's buffers and arguments; Kaitai has no
 * Ghidra importer, so this header is the Ghidra-side twin of specs/ksy/hr_v3000.ksy).
 *
 * READ FIRST - THE DM-32UV DOES NOT HAVE THIS CHIP. Stock DM32.00.01.048 contains no HR_V3000
 * driver, so there are no stock send/receive routines to type with this header. Checked
 * 2026-10-11 [FW, checked]:
 *   - no frame template (61 00 01 00 / 61 00 03 00 / 61 00 02 00 / 61 00 1b) in the app image,
 *     the 1 MB program-flash image or the IRAM image;
 *   - no `movi`/`cmpnei` of 0x61 that builds or matches a frame anywhere: capstone-csky linear
 *     sweeps of IRAM 0x00010000-0x0002f098 (0 hits) and flash 0x03001000-0x030d2000 (12 hits,
 *     all unrelated: XMODEM @0x0300468c, ASCII in codeplug defaults and display code, a
 *     settings clamp @0x0304abcc, byte tables);
 *   - the UARTs it does drive are not a vocoder link:
 *       UART0 @0x14030000  uart0_init @0x0301da48, 115200 (0xe1<<9 passed from
 *                          radio_boot_full_init_sequence @0x0305f326): the CPS/console UART,
 *                          no pin-mux write;
 *       UART1 @0x14040000  gps_uart1_init_9600 @0x0301d96c, 9600 baud (clock / 0x25800), IRQ 0x2a,
 *                          handler @0x0002ccc8 (IRAM); called only when option byte bit 2 is set
 *                          (0x0305f310-0x0305f31e); its only transmitter,
 *                          uart_tx_chunked_mutex_send @0x0301d9d4 (from FUN_030119f4), sends
 *                          ASCII + CR LF next to the CASIC GPS commands "$PCAS03,..",
 *                          "$PCAS00*01", "$PCAS05,2*1A", "$PCAS04,3*1A" @0x03081e10-0x03081e4c.
 *                          That is the GPS receiver (ATGM336H), which wants 9600; the HR_V3000
 *                          wants 115200.
 *   The DM-32 uses the HR_C7000's built-in vocoder [DS HR_C7000 v2.7 en, 7.1.1, p.473]: PCM in
 *   SRAM 0x18000000-0x1800009F / 0x180000A0-0x18000140, coded frames in modem RAM
 *   0x16000960-0x1600097A (27 bytes), irq28 encode / irq27 decode. This header is for boards
 *   that do populate an HR_V3000 (the HR_C7000 datasheet v2.7 en, 2.2.7 p.36, lists it as
 *   supported) and for hardware probing.
 *
 * CONFIDENCE TAGS:
 *   [DS]   HR_V3000 声码器使用说明文档 (vocoder user manual) v1.2, 2013-09-11, section and PDF page.
 *   [DVSI] DVSI AMBE-3000R Vocoder Chip User's Manual, as transcribed by the open-source tools
 *          serialDV (github.com/f4exb/serialDV, dvcontroller.h, GPL-3.0), tcd
 *          (github.com/nostar/tcd, DVSIPacket.h, GPL-3.0) and zumspotpy
 *          (github.com/spectriclabs/zumspotpy, ambeserver.py, Apache-2.0). Cross-check only;
 *          no code copied.
 *   [FW]   stock DM32.00.01.048 (load base 0x03000000). [INF] inferred, a hypothesis.
 *
 * WIRE FORMAT [DS 4.2.1 p.11-13]: 115200 8N1, no flow control.
 *     0x61 | len_hi len_lo | type | DATA[len]        len counts DATA only (n >= 1), big-endian.
 *   Same as DVSI's AMBE-3000 packet [DVSI]. Control (type 0): DATA[0] = command code,
 *   DATA[1..] = its parameters, multi-byte values high byte first. ONE command per packet (DVSI
 *   packs several). The vocoder ACKs every accepted command with `61 00 01 00 <code>` (DVSI
 *   answers ID + status byte instead); wait for the ACK before the next command. Coded voice
 *   (types 1 and 3) is the bare 27 coded bytes, no field tag (DVSI tags CHAND 0x01 + bit count).
 *
 * TYPES. No u8/u16 typedefs: dm32_patch_api.h and dm32_ui.h typedef those without a guard and
 * C99 forbids a repeat. Bytes are spelled `unsigned char`; every name is prefixed HRV_/hrv_.
 * Nothing here is per-unit data (a real chip's PRODID answer would be - never commit one).
 */
#ifndef HR_V3000_H
#define HR_V3000_H

/* C99-compatible compile-time check (no _Static_assert). */
#define HRV_STATIC_ASSERT(name, cond) typedef char hrv_static_assert_##name[(cond) ? 1 : -1]

#define HRV_UART_BAUD          115200u  /* [DS 4.2.1 p.11] 8N1, no flow control */
#define HRV_START_BYTE         0x61u    /* [DS 4.2.1 p.11] [DVSI same] */
#define HRV_HEADER_BYTES       4u       /* start + length(2) + type */
#define HRV_VOICE_FRAME_BYTES  27u      /* [DS 5.6.1 p.18] 216 coded bits ... */
#define HRV_VOICE_FRAME_MS     60u      /* ... every 60 ms = 3600 bit/s. [INF] 3 x 72-bit AMBE+2 frames */
#define HRV_WAKE_LATENCY_MS    5u       /* [DS 3 p.9 note 1] 4-5 ms from standby to ready */

/* ------------------------------------------------------------------------------------------
 * Packet type, frame byte 3 [DS 4.2.1 type table, p.11-12]. Other values reserved.
 * ------------------------------------------------------------------------------------------ */
typedef enum hrv_packet_type {
    HRV_TYPE_CCP  = 0x00,  /* control command / ACK / answer. [DVSI 0x00 control] */
    HRV_TYPE_DECP = 0x01,  /* coded voice into/out of the DECODER. [DVSI 0x01 channel data] */
    HRV_TYPE_ENCP = 0x03   /* coded voice out of/back into the ENCODER. Not DVSI (0x02 = PCM there) */
} hrv_packet_type;

/* ------------------------------------------------------------------------------------------
 * Control command codes, DATA[0] of a CCP packet [DS 4.2.1 p.12; A.1 p.22]. "len" = frame
 * Length of the command / of the vocoder's answer. "in" = vocoder-to-host only.
 * ------------------------------------------------------------------------------------------ */
typedef enum hrv_control_code {
    HRV_CC_ECMODE         = 0x05, /* len 3/1: encoder mode word, HRV_ECMODE_*. [DVSI PKT_ECMODE] */
    HRV_CC_DCMODE         = 0x06, /* len 3/1: decoder mode word, HRV_DCMODE_*. [DVSI PKT_DCMODE] */
    HRV_CC_PRODID         = 0x30, /* len 1/13: 96-bit chip ID [DS 5.9.2 p.21]. [DVSI PKT_PRODID] */
    HRV_CC_VERSTRING      = 0x31, /* len 1/>=7: "V1.2.0" etc. [DVSI PKT_VERSTRING] */
    HRV_CC_READY          = 0x39, /* in, len 1: init/wake done, host may talk. [DVSI PKT_READY] */
    HRV_CC_ENCODERSTART   = 0xa0, /* len 1/1 */
    HRV_CC_ENCODERSTOP    = 0xa1, /* len 1/1 */
    HRV_CC_DECODERSTART   = 0xa2, /* len 1/1 */
    HRV_CC_DECODERSTOP    = 0xa3, /* len 1/1 */
    HRV_CC_ENCRYPTON      = 0xa4, /* len 1/1: encoder output detours via the host [DS 5.7 p.19] */
    HRV_CC_ENCRYPTOFF     = 0xa5, /* len 1/1. The vocoder has no cipher; the host encrypts. */
    HRV_CC_DECRYPTON      = 0xa6, /* len 1/1: decoder input detours via the host */
    HRV_CC_DECRYPTOFF     = 0xa7, /* len 1/1 */
    HRV_CC_DECSRC         = 0xa8, /* len 2/1: u8 hrv_dec_source */
    HRV_CC_RECSRC         = 0xa9, /* len 2/1: u8 hrv_rec_source */
    HRV_CC_PLAYRAMRDY     = 0xaa, /* in, len 1: playback buffer takes one DECP frame (every 60 ms) */
    HRV_CC_SET_DBM0_LEVEL = 0xab, /* len 3/1: s16 AGC target, dBm0, default -22 [DS 5.4 p.16] */
    HRV_CC_MAX_DB_GAIN    = 0xac, /* len 3/1: s16 AGC max gain, dB, default 20 */
    HRV_CC_MIN_DB_GAIN    = 0xad, /* len 3/1: s16 AGC min gain, dB, default -10 */
    HRV_CC_ENC_TONE_INDEX = 0xae, /* len 3/1: u16 HRV_TONE_* */
    HRV_CC_ENC_TONE_LEVEL = 0xaf, /* len 3/1: s16 dBm0, default -20 [DS 5.3.1 p.15] */
    HRV_CC_DEC_TONE_INDEX = 0xb0, /* len 3/1: u16 HRV_TONE_* */
    HRV_CC_DEC_TONE_LEVEL = 0xb1, /* len 3/1: s16 dBm0 */
    HRV_CC_ERR_RATE       = 0xb2, /* len 1/3: u16 bit-error rate * 2^17 [DS 5.5 p.17] */
    HRV_CC_TTL_ERRS       = 0xb3, /* len 1/3: u16 bit errors in the last frame */
    HRV_CC_GPIO_SET       = 0xb4, /* len 3/1: u16 pin mask -> high. (A.1 says len 1; 5.8.2 wins) */
    HRV_CC_GPIO_RESET     = 0xb5  /* len 3/1: u16 pin mask -> low */
} hrv_control_code;

/* ------------------------------------------------------------------------------------------
 * Mode words, 16-bit, sent high byte first [DS 5, tables p.13-14]. Reserved bits must be 0.
 * Register view with full citations: specs/rdl/hr_v3000_modes.rdl.
 * ------------------------------------------------------------------------------------------ */
#define HRV_ECMODE_DTMF_SEND        (1u << 14) /* encode ENC_TONE_INDEX instead of speech. [DVSI TS_ENABLE] */
#define HRV_ECMODE_AGC_ON           (1u << 13) /* input AGC. DVSI has EC_ENABLE (echo canceller) here */
#define HRV_ECMODE_TONE_DET_ENABLE  (1u << 12) /* tone detection. [DVSI TD_ENABLE] */
#define HRV_ECMODE_DTX_ENABLE       (1u << 11) /* silence frames in gaps, default 1. [DVSI DTX_ENABLE] */
#define HRV_ECMODE_NS_ENABLE        (1u << 6)  /* noise suppression, default 1. [DVSI NS_ENABLE] */
#define HRV_ECMODE_RESERVED_MASK    0x87bfu
#define HRV_ECMODE_MANUAL_EXAMPLE   0x1840u    /* [DS 4.2.1 p.13] tone det + DTX + NS */

#define HRV_DCMODE_DTMF_SEND        (1u << 14) /* play DEC_TONE_INDEX instead of decoding. [DVSI TS_ENABLE] */
#define HRV_DCMODE_CNI_FRAME        (1u << 3)  /* continuous comfort noise, default 0. [DVSI CNI_FRAME] */
#define HRV_DCMODE_RESERVED_MASK    0xbff7u

typedef enum hrv_dec_source {           /* DECSRC parameter [DS 5.6.1 p.18] */
    HRV_DECSRC_BASEBAND        = 0,     /* host baseband chip over V_SPI (manual: HR_C5000), default */
    HRV_DECSRC_PLAYBACK_BUFFER = 1      /* host-filled playback buffer (DECP frames) */
} hrv_dec_source;

typedef enum hrv_rec_source {           /* RECSRC parameter [DS 5.6.1 p.18]; other values = off */
    HRV_RECSRC_OFF     = 0,
    HRV_RECSRC_ENCODER = 1,             /* encoder output copied to host as ENCP */
    HRV_RECSRC_DECODER = 2,             /* decoder input copied to host as DECP */
    HRV_RECSRC_BOTH    = 3
} hrv_rec_source;

/* Tone indices [DS A.2 p.23-24]. 5..122 = single tone at index * 31.25 Hz; 0-4, 123-127,
 * 164-254 invalid. */
#define HRV_TONE_SINGLE_MIN     5u
#define HRV_TONE_SINGLE_MAX     122u
#define HRV_TONE_SINGLE_HZ_X100(i) ((i) * 3125u)     /* frequency in 0.01 Hz */
#define HRV_TONE_DTMF_0         128u    /* 128..137 = DTMF '0'..'9' */
#define HRV_TONE_DTMF_A         138u    /* 138..141 = 'A'..'D' */
#define HRV_TONE_DTMF_STAR      142u
#define HRV_TONE_DTMF_HASH      143u
#define HRV_TONE_KNOX_0         144u    /* 144..153 = KNOX '0'..'9', 154..157 'A'..'D' */
#define HRV_TONE_KNOX_STAR      158u
#define HRV_TONE_KNOX_HASH      159u
#define HRV_TONE_CALL_PROGRESS  160u    /* 160..163: 440+350, 480+440, 620+480, 490+350 Hz */
#define HRV_TONE_NONE           255u

#define HRV_ERR_RATE_SCALE      131072u /* ERR_RATE / 2^17 = rate [DS 5.5.1 p.17] */

/* ------------------------------------------------------------------------------------------
 * Frame layouts. All members are bytes, so these have no padding on any ABI and need no
 * packing attribute; the asserts check it. Multi-byte values are big-endian on the wire, so
 * they are byte pairs here (a u16 member would read byte-swapped on the little-endian CK803S
 * and in Ghidra); use HRV_BE16 / HRV_PUT_BE16.
 * ------------------------------------------------------------------------------------------ */
typedef struct hrv_frame_header {
    unsigned char start;      /* HRV_START_BYTE */
    unsigned char len_be[2];  /* DATA length, big-endian, excludes these 4 bytes */
    unsigned char type;       /* hrv_packet_type */
} hrv_frame_header;
HRV_STATIC_ASSERT(header_is_4_bytes, sizeof(hrv_frame_header) == 4);

/* Command / ACK with no parameter: 61 00 01 00 <code>. */
typedef struct hrv_ctrl_frame {
    hrv_frame_header hdr;     /* len 1, type HRV_TYPE_CCP */
    unsigned char    code;    /* hrv_control_code */
} hrv_ctrl_frame;
HRV_STATIC_ASSERT(ctrl_is_5_bytes, sizeof(hrv_ctrl_frame) == 5);

/* Command with one byte (DECSRC, RECSRC): 61 00 02 00 <code> <v>. */
typedef struct hrv_ctrl_u8_frame {
    hrv_frame_header hdr;
    unsigned char    code;
    unsigned char    value;
} hrv_ctrl_u8_frame;
HRV_STATIC_ASSERT(ctrl_u8_is_6_bytes, sizeof(hrv_ctrl_u8_frame) == 6);

/* Command or answer with a 16-bit value (ECMODE, DCMODE, levels, tone indices, GPIO masks,
 * ERR_RATE / TTL_ERRS answers): 61 00 03 00 <code> <hi> <lo>. */
typedef struct hrv_ctrl_u16_frame {
    hrv_frame_header hdr;
    unsigned char    code;
    unsigned char    value_be[2];
} hrv_ctrl_u16_frame;
HRV_STATIC_ASSERT(ctrl_u16_is_7_bytes, sizeof(hrv_ctrl_u16_frame) == 7);

/* PRODID answer: 61 00 0d 00 30 ID[0-11]. */
typedef struct hrv_prodid_frame {
    hrv_frame_header hdr;
    unsigned char    code;
    unsigned char    id[12];
} hrv_prodid_frame;
HRV_STATIC_ASSERT(prodid_is_17_bytes, sizeof(hrv_prodid_frame) == 17);

/* DECP / ENCP coded voice: 61 00 1b 01|03 DATA[0-26]. */
typedef struct hrv_voice_frame {
    hrv_frame_header hdr;     /* len 27, type HRV_TYPE_DECP or HRV_TYPE_ENCP */
    unsigned char    bits[27];
} hrv_voice_frame;
HRV_STATIC_ASSERT(voice_is_31_bytes, sizeof(hrv_voice_frame) == 31);

#define HRV_BE16(p)          ((unsigned)(((p)[0] << 8) | (p)[1]))
#define HRV_PUT_BE16(p, v)   ((p)[0] = (unsigned char)((unsigned)(v) >> 8), \
                              (p)[1] = (unsigned char)(v))
#define HRV_FRAME_LEN(h)     HRV_BE16((h)->len_be)

#endif /* HR_V3000_H */
