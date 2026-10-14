/*
 * HR_C7000 (Baofeng DM-32UV) peripheral register header. A reverse-engineering derivative, NOT a
 * Dahua/Baofeng artifact.
 *
 * Same register map as HR_C7000-DM32.svd (published alongside it), in CMSIS device-header style:
 * one struct per peripheral, _Pos/_Msk macros per field, <NAME>_BASE and a <NAME> pointer macro
 * per instance. The .svd carries the full per-register citations (datasheet section and page,
 * firmware addresses); comments here are abbreviated.
 *
 * Usable two ways: compiled into host or target C (C99 or later), or imported into a decompiler's
 * type manager through its C-header parser. Every struct member's offset is checked against the
 * register model with offsetof/sizeof static asserts when the map is built.
 *
 * Scope: a register is named where a source gives its offset. Registers whose bit layout is not
 * transcribed are plain words without _Pos/_Msk. Gaps are RESERVED arrays, which do not assert
 * that the silicon there is unimplemented.
 *
 * Bit positions are _Pos/_Msk macros rather than C bitfields on purpose: bitfield order and
 * packing are implementation-defined.
 *
 * Core: the HR_C7000 CPU is a XuanTie/T-Head CK803S (C-SKY V2), not an ARM Cortex-M. Nothing here
 * is CMSIS-Core (no NVIC/SCB/SysTick); only the device-header style is borrowed. The interrupt
 * controller is PIC (0x17000000). PIC "source" vs CPU "vector": vector = source + 32.
 *
 * Runtime MMIO only. Unrelated to the per-unit calibration data in the radio's external flash.
 */
#ifndef HR_C7000_DM32_H
#define HR_C7000_DM32_H

/* Self-contained typedefs so the header parses even where no stdint.h is on the include path.
 * Define DM32_UINT32_T_DEFINED (and include <stdint.h>) first to use the system types instead. */
#ifndef DM32_UINT32_T_DEFINED
#define DM32_UINT32_T_DEFINED
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
#endif

#define __IO volatile          /* read-write */
#define __I  volatile const    /* read-only  */
#define __O  volatile          /* write-only (no 'const', writes are the point) */

/* ===================================================================================
 * SystemControl @ 0x11000000: baseband/modem system control + clock manager, 64 KB window.
 * HAND-MAINTAINED (the .svd description lists the datasheet registers not yet described here).
 * DS = HR_C7000 v2.7 English guide, section and PDF page. FW = stock DM32.00.01.048 address.
 * =================================================================================== */
typedef struct {
  __IO uint32_t SYS_SOFT_RSTN;         /* 0x00 per-module soft reset, self-clearing (DS §4.1.4.1 p.70) */
  __IO uint32_t CLK_MGR_REG0x04;       /* 0x04 PLL/clock-switch control (DS §4.2.5.1 p.78) */
  __IO uint32_t CLK_MGR_REG0x08;       /* 0x08 APLL config; divider fields only (DS §4.2.5.2 p.79) */
  __IO uint32_t CLK_MGR_REG0x0c;       /* 0x0c apll_frac[23:0] (DS §4.2.5.3 p.81) */
  __IO uint32_t CLK_MGR_REG0x10;       /* 0x10 BPLL config; divider fields only (DS §4.2.5.4 p.81) */
  __IO uint32_t CLK_MGR_REG0x14;       /* 0x14 bpll_frac[23:0] (DS §4.2.5.5 p.82) */
  __IO uint32_t CLK_MGR_REG0x18;       /* 0x18 clock divider numerators (DS §4.2.5.6 p.83) */
  __IO uint32_t CLK_MGR_REG0x1c;       /* 0x1c 32k/192k fractional dividers; bits not transcribed */
  __IO uint32_t CLK_MGR_REG0x20;       /* 0x20 codec MCLK + 8k/512k dividers; bits not transcribed */
  __IO uint32_t CLK_MGR_REG0x24;       /* 0x24 DAC/ADC/SDIO dividers, bus ratios; bits not transcribed */
  __IO uint32_t CLK_MGR_REG0x28;       /* 0x28 SDIO/USB dividers; bits not transcribed */
  __IO uint32_t CLK_MGR_REG0x2c;       /* 0x2c clock-gate enables; bits not transcribed */
  __IO uint32_t LCSFC_BAUDR;           /* 0x30 LCSFC SPI clock divider (DS §4.4.4.1 p.93) */
  __IO uint32_t IO_DIPLEX0;            /* 0x34 pad mux bank 0: JTAG/I2C/UART/PWM (DS §4.4.4.4 p.93) */
  __IO uint32_t IO_DIPLEX1;            /* 0x38 pad mux bank 1: SPI0/1, TDMA/BS lines, PTB2-6 (DS §4.4.4.5 p.97) */
  __IO uint32_t IO_DIPLEX2;            /* 0x3c pad mux bank 2: CLK_OUT/LCD/ADC/DAC (DS §4.4.4.6 p.101) */
  __IO uint32_t RESERVED_0x40;         /* 0x40 = DS IOMGR_REN_REG0, pull-ups (DS §4.4.4.7 p.105); FW @0x0301d5f8 */
  __IO uint32_t RESERVED_44[1];        /* 0x44-0x47 */
  __IO uint32_t RESERVED_0x48;         /* 0x48 = DS IOMGR_REN_REG2, PTB pull-ups (DS §4.4.4.9 p.113) */
  __IO uint32_t RESERVED_4C[4];        /* 0x4c-0x5b */
  __IO uint32_t QUAD_ENABLE;           /* 0x5c LCSFC quad-mode enable (DS §4.4.4.3 p.93) */
  __IO uint32_t RESERVED_60[4];        /* 0x60-0x6f */
  __IO uint32_t DAC_CONTROL;           /* 0x70 baseband DAC control (DS §4.6.5.1 p.146) */
  __IO uint32_t ADC_CONTROL;           /* 0x74 baseband ADC control (DS §4.6.5.2 p.146) */
  __IO uint32_t RESERVED_78[2];        /* 0x78-0x7f */
  __IO uint32_t AUDIO_CONTROL;         /* 0x80 audio path routing (DS §4.6.5.3 p.148) */
  __IO uint32_t AUDIO_BUFFER_CLR;      /* 0x84 vocoder buffer clear (DS §4.6.5.4 p.150) */
  __IO uint32_t LINEOUT_CTRL;          /* 0x88 line-out enables (DS §4.6.5.5 p.150) */
  __IO uint32_t CODEC_I2C_MUX;         /* 0x8c codec control interface (DS §4.6.5.6 p.150) */
  __IO uint32_t RESERVED_90[28];       /* 0x90-0xff */
  __IO uint32_t WORK_MODE;             /* 0x100 baseband working mode (DS §4.6.5.7 p.151) */
  __IO uint32_t RF_MODE;               /* 0x104 RF interface mode (DS §4.6.5.8 p.152) */
  __IO uint32_t SIG_CENTER;            /* 0x108 TX/RX IQ DC-bias setting (DS §9.2.2.3 p.496) */
  __IO uint32_t TX_IF_FREQ;            /* 0x10c TX IF frequency word (DS §9.2.2.4 p.497) */
  __IO uint32_t RF_CONTROL;            /* 0x110 RF TX/RX interrupt advance (DS §9.2.2.5 p.498) */
  __IO uint32_t RF_MOD_BIAS_CTRL;      /* 0x114 TX signal amplitude adjustment (DS §9.2.2.6 p.498) */
  __IO uint32_t DEV_LIMITER;           /* 0x118 TX frequency-deviation threshold (DS §9.2.2.7 p.498) */
  __IO uint32_t RSSI_BIAS_VALUE;       /* 0x11c Signal-energy detection value and ADC DC-bias detection (DS §9.2.2.8 p.498) */
  __IO uint32_t THRESHOLD_VALUE;       /* 0x120 Sync-detection threshold (DS §9.2.2.9 p.499) */
  __IO uint32_t RESERVED_124[1];       /* 0x124-0x127 */
  __IO uint32_t PHASE_OUT;             /* 0x128 Phase-input amplitude detection in AF receive mode (DS §9.2.2.10 p.500) */
  __IO uint32_t SEND_DATA_SYNC_H;      /* 0x12c TX data sync pattern, high half (DS §9.2.2.11 p.500) */
  __IO uint32_t SEND_DATA_SYNC_L;      /* 0x130 TX data sync pattern, low half (see SEND_DATA_SYNC_H) (DS §9.2.2.12 p.500) */
  __IO uint32_t SEND_RC_SYNC_H;        /* 0x134 TX RC (reverse channel) sync pattern, high half (DS §9.2.2.13 p.502) */
  __IO uint32_t SEND_RC_SYNC_L;        /* 0x138 TX RC sync pattern, low half (DS §9.2.2.14 p.502) */
  __IO uint32_t RECV_MS_SYNC_H;        /* 0x13c RX MS data sync pattern, high half (DS §9.2.2.15 p.502) */
  __IO uint32_t RECV_MS_SYNC_L;        /* 0x140 RX MS data sync pattern, low half (DS §9.2.2.16 p.502) */
  __IO uint32_t RECV_BS_SYNC_H;        /* 0x144 RX BS data sync pattern, high half (DS §9.2.2.17 p.503) */
  __IO uint32_t RECV_BS_SYNC_L;        /* 0x148 RX BS data sync pattern, low half (DS §9.2.2.18 p.504) */
  __IO uint32_t RECV_TDMA1_SYNC_H;     /* 0x14c RX TDMA1 data sync pattern, high half (DS §9.2.2.19 p.504) */
  __IO uint32_t RECV_TDMA1_SYNC_L;     /* 0x150 RX TDMA1 data sync pattern, low half (DS §9.2.2.20 p.504) */
  __IO uint32_t RECV_TDMA2_SYNC_H;     /* 0x154 RX TDMA2 data sync pattern, high half (DS §9.2.2.21 p.505) */
  __IO uint32_t RECV_TDMA2_SYNC_L;     /* 0x158 RX TDMA2 data sync pattern, low half (DS §9.2.2.22 p.506) */
  __IO uint32_t RECV_RC_SYNC_H;        /* 0x15c RX RC data sync pattern, high half (DS §9.2.2.23 p.506) */
  __IO uint32_t RECV_RC_SYNC_L;        /* 0x160 RX RC data sync pattern, low half (DS §9.2.2.24 p.506) */
  __IO uint32_t RESERVED_164[1];       /* 0x164-0x167 */
  __IO uint32_t REG_0x168;             /* 0x168 not in DS; FW writes 0x14/0x98 (@0x03023760, 0x030237ba, 0x0302172c) */
  __IO uint32_t RESERVED_16C[17];      /* 0x16c-0x1af */
  __IO uint32_t RX_IF_FREQ;            /* 0x1b0 RX IF frequency word (DS §9.2.2.43 p.515) */
  __IO uint32_t RF_RECV_DELAY;         /* 0x1b4 RX channel delay offset (DS §9.2.2.44 p.515) */
  __IO uint32_t MODEM_AK_CLK_CALB;     /* 0x1b8 AK2401 clock adjustment control (DS §9.2.2.45 p.515) */
  __IO uint32_t AK2401_ADC_STATE;      /* 0x1bc AK2401 ADC receive status (DS §9.2.2.46 p.516) */
  __IO uint32_t RESERVED_1C0[100];     /* 0x1c0-0x34f */
  __IO uint32_t PI_CRC_MASK;           /* 0x350 PI frame CRC16 mask and initial value (DS §10.2.2.2 p.529) */
  __IO uint32_t RS_H_MASK;             /* 0x354 RS(12,9) code mask for the voice LC header (DS §10.2.2.3 p.529) */
  __IO uint32_t RS_H_INIT;             /* 0x358 RS code initial value for the voice LC header (DS §10.2.2.4 p.530) */
  __IO uint32_t RS_T_MASK;             /* 0x35c RS code mask for the terminator (DS §10.2.2.5 p.531) */
  __IO uint32_t RS_T_INIT;             /* 0x360 RS code initial value for the terminator (DS §10.2.2.6 p.531) */
  __IO uint32_t CSBK_CRC_MASK;         /* 0x364 CSBK CRC16 mask and initial value (DS §10.2.2.7 p.531) */
  __IO uint32_t MBCH_CRC_MASK;         /* 0x368 MBC header CRC16 mask and initial value (DS §10.2.2.8 p.531) */
  __IO uint32_t DATAH_CRC_MASK;        /* 0x36c Data header CRC16 mask and initial value (DS §10.2.2.9 p.531) */
  __IO uint32_t REG_0x370;             /* 0x370 not in DS; FW register_init writes 0xf0 (@0x030236d2) */
  __IO uint32_t REG_0x374;             /* 0x374 not in DS; FW register_init writes 0x1ff (@0x030236da) */
  __IO uint32_t REG_0x378;             /* 0x378 not in DS; FW register_init writes 0x10f (@0x030236e2) */
  __IO uint32_t REG_0x37c;             /* 0x37c not in DS; FW register_init writes 0 (@0x030236e6) */
  __IO uint32_t CRC8_INIT;             /* 0x380 Short LC CRC8 initial value (DS §10.2.2.10 p.533) */
  __IO uint32_t LOCAL_CC;              /* 0x384 Local colour code for TX and RX, voice-frame EMB PI setting (DS §10.2.2.11 p.533) */
  __IO uint32_t VOICE_EMB_CTRL;        /* 0x388 Voice frame F EMB fill settings (DS §10.2.2.12 p.533) */
  __IO uint32_t SCRAMBLE_REG;          /* 0x38c Basic voice-scrambling key (DS §10.2.2.13 p.534) */
  __IO uint32_t RX_TYPE_INFO;          /* 0x390 Received frame information (DS §10.2.2.14 p.535) */
  __IO uint32_t RX_INFO;               /* 0x394 Received RC frame information (DS §10.2.2.15 p.537) */
  __IO uint32_t SYS_INTERP_LIST;       /* 0x398 layer-2 interrupt vector list (DS §4.6.5.9 p.156) */
  __IO uint32_t SYS_INTERP_MASK;       /* 0x39c Mask for SYS_INTERP_LIST (DS §4.6.5.10 p.156) */
  __IO uint32_t SYS_INTERP_CLEAR;      /* 0x3a0 Clear for SYS_INTERP_LIST (write 1 to clear) (DS §4.6.5.11 p.160) */
  __IO uint32_t LAYER3_INTERP_LIST;    /* 0x3a4 layer-3 interrupt vector list (DS §4.6.5.12 p.160) */
  __IO uint32_t LAYER3_INTERP_MASK;    /* 0x3a8 Mask for LAYER3_INTERP_LIST (DS §4.6.5.13 p.162) */
  __IO uint32_t LAYER3_INTERP_CLEAR;   /* 0x3ac Clear for LAYER3_INTERP_LIST (DS §4.6.5.14 p.165) */
  __IO uint32_t INTERP_CLEAR;          /* 0x3b0 30 ms/RF/PCM interrupt clear (DS §4.6.5.15 p.166) */
  __IO uint32_t INTERP_CLEAR_AUX;      /* 0x3b4 not in DS; FW writes 0x1800 (cps_serial_field_rw_* family) */
  __IO uint32_t RESERVED_3B8[18];      /* 0x3b8-0x3ff */
  __IO uint32_t LAYER2_CONTROL;        /* 0x400 L2 mode control (DS §9.2.2.48 p.517, §10.2.2.16 p.537) */
  __IO uint32_t LAYER2_SLOTON;         /* 0x404 L2 timeslot switch (DS §10.2.2.17 p.539) */
  __IO uint32_t LAYER2_TXRX_CTRL;      /* 0x408 L2 TX/RX control (DS §9.2.2.49 p.517, §10.2.2.18 p.541) */
  __IO uint32_t LAYER2_SLOT_CNT;       /* 0x40c L2 slot count initial value (DS §10.2.2.19 p.543) */
  __IO uint32_t RESERVED_410[1];       /* 0x410-0x413 */
  __IO uint32_t LAYER2_SLOT_UPDATE;    /* 0x414 L2 slot update (DS §10.2.2.21 p.544) */
  __IO uint32_t LAYER2_SEND_TYPE;      /* 0x418 L2 TX frame type (DS §10.2.2.22 p.545) */
  __I  uint32_t LAYER2_STATUS;         /* 0x41c L2 slot status, RO (DS §10.2.2.23 p.549) */
  __IO uint32_t RESERVED_420[1];       /* 0x420-0x423 */
  __IO uint32_t LAYER2_SLOT_PRE;       /* 0x424 L2 interrupt pre-position (DS §10.2.2.24 p.549) */
  __IO uint32_t RESERVED_428[54];      /* 0x428-0x4ff */
  __IO uint32_t FM_BANDWIDTH;          /* 0x500 FM bandwidth and filter settings (DS §11.2.2.2 p.592) */
  __IO uint32_t FM_DEV_COEF;           /* 0x504 FM deviation coefficient (DS §11.2.2.3 p.594) */
  __IO uint32_t RESERVED_508[1];       /* 0x508-0x50b */
  __IO uint32_t SUBVOICE_COEF;         /* 0x50c Sub-audio (CTCSS/CDCSS) coefficient (DS §11.2.2.5 p.594) */
  __IO uint32_t FM_MOD;                /* 0x510 FM modulation control (DS §11.2.2.6 p.595) */
  __IO uint32_t RESERVED_514[1];       /* 0x514-0x517 */
  __IO uint32_t CTCSS_ADDR;            /* 0x518 CTCSS tone selection (DS §11.2.2.7 p.596) */
  __IO uint32_t RESERVED_51C[2];       /* 0x51c-0x523 */
  __IO uint32_t SELCALL_TONE;          /* 0x524 Selective-call tone (DS §11.2.2.10 p.598) */
  __IO uint32_t TONE_SEND_CTRL;        /* 0x528 Tone transmit control (DS §11.2.2.11 p.598) */
  __IO uint32_t RESERVED_52C[9];       /* 0x52c-0x54f */
  __IO uint32_t FM_TONE1;              /* 0x550 FM tone generator 1 (DS §11.2.2.21 p.602) */
  __IO uint32_t FM_TONE2;              /* 0x554 FM tone generator 2 (DS §11.2.2.22 p.604) */
  __IO uint32_t FM_TONE3;              /* 0x558 FM tone generator 3 (DS §11.2.2.23 p.604) */
  __IO uint32_t FM_TONE4;              /* 0x55c FM tone generator 4 (DS §11.2.2.24 p.604) */
  __IO uint32_t FM_PTT;                /* 0x560 FM PTT control (DS §11.2.2.25 p.604) */
  __IO uint32_t RESERVED_564[1];       /* 0x564-0x567 */
  __IO uint32_t FM_DECODE_FLAG2;       /* 0x568 FM decode flags 2 (DS §11.2.2.27 p.605) */
} SystemControl_Type;   /* 0x56c bytes; the rest of the 64 KB window is not described here */

/* Field positions (SystemControl registers with a transcribed layout). */
#define SYSCTL_SYS_SOFT_RSTN_protocol_soft_rstn_Pos  (0U)
#define SYSCTL_SYS_SOFT_RSTN_protocol_soft_rstn_Msk  (0x1U << 0U)
#define SYSCTL_SYS_SOFT_RSTN_phy_soft_rstn_Pos  (1U)
#define SYSCTL_SYS_SOFT_RSTN_phy_soft_rstn_Msk  (0x1U << 1U)
#define SYSCTL_SYS_SOFT_RSTN_fm_soft_rstn_Pos  (2U)
#define SYSCTL_SYS_SOFT_RSTN_fm_soft_rstn_Msk  (0x1U << 2U)
#define SYSCTL_SYS_SOFT_RSTN_audio_soft_rstn_Pos  (3U)
#define SYSCTL_SYS_SOFT_RSTN_audio_soft_rstn_Msk  (0x1U << 3U)
#define SYSCTL_SYS_SOFT_RSTN_codec_soft_rstn_Pos  (4U)
#define SYSCTL_SYS_SOFT_RSTN_codec_soft_rstn_Msk  (0x1U << 4U)
#define SYSCTL_SYS_SOFT_RSTN_adc_soft_rstn_Pos  (5U)
#define SYSCTL_SYS_SOFT_RSTN_adc_soft_rstn_Msk  (0x1U << 5U)
#define SYSCTL_SYS_SOFT_RSTN_adc_ctrl_soft_rstn_Pos  (6U)
#define SYSCTL_SYS_SOFT_RSTN_adc_ctrl_soft_rstn_Msk  (0x1U << 6U)
#define SYSCTL_SYS_SOFT_RSTN_sys_soft_rstn_Pos  (7U)
#define SYSCTL_SYS_SOFT_RSTN_sys_soft_rstn_Msk  (0x1U << 7U)
#define SYSCTL_SYS_SOFT_RSTN_cpu_soft_rstn_Pos  (8U)
#define SYSCTL_SYS_SOFT_RSTN_cpu_soft_rstn_Msk  (0x1U << 8U)
#define SYSCTL_CLK_MGR_REG0x04_aclk_re_cfg_reg_Pos  (0U)
#define SYSCTL_CLK_MGR_REG0x04_aclk_re_cfg_reg_Msk  (0x1U << 0U)
#define SYSCTL_CLK_MGR_REG0x04_bclk_re_cfg_reg_Pos  (1U)
#define SYSCTL_CLK_MGR_REG0x04_bclk_re_cfg_reg_Msk  (0x1U << 1U)
#define SYSCTL_CLK_MGR_REG0x04_aclk_work_sel_Pos  (2U)
#define SYSCTL_CLK_MGR_REG0x04_aclk_work_sel_Msk  (0x1U << 2U)
#define SYSCTL_CLK_MGR_REG0x04_bclk_work_sel_Pos  (3U)
#define SYSCTL_CLK_MGR_REG0x04_bclk_work_sel_Msk  (0x1U << 3U)
#define SYSCTL_CLK_MGR_REG0x04_clk_rdy_Pos  (30U)
#define SYSCTL_CLK_MGR_REG0x04_clk_rdy_Msk  (0x1U << 30U)
#define SYSCTL_CLK_MGR_REG0x04_pll_ld_Pos  (31U)
#define SYSCTL_CLK_MGR_REG0x04_pll_ld_Msk  (0x1U << 31U)
#define SYSCTL_CLK_MGR_REG0x08_postdiv2_Pos  (0U)
#define SYSCTL_CLK_MGR_REG0x08_postdiv2_Msk  (0x7U << 0U)
#define SYSCTL_CLK_MGR_REG0x08_postdiv1_Pos  (3U)
#define SYSCTL_CLK_MGR_REG0x08_postdiv1_Msk  (0x7U << 3U)
#define SYSCTL_CLK_MGR_REG0x08_fbdiv_Pos  (6U)
#define SYSCTL_CLK_MGR_REG0x08_fbdiv_Msk  (0xFFFU << 6U)
#define SYSCTL_CLK_MGR_REG0x08_refdiv_Pos  (18U)
#define SYSCTL_CLK_MGR_REG0x08_refdiv_Msk  (0x3FU << 18U)
#define SYSCTL_CLK_MGR_REG0x0c_apll_frac_Pos  (0U)
#define SYSCTL_CLK_MGR_REG0x0c_apll_frac_Msk  (0xFFFFFFU << 0U)
#define SYSCTL_CLK_MGR_REG0x10_postdiv2_Pos  (0U)
#define SYSCTL_CLK_MGR_REG0x10_postdiv2_Msk  (0x7U << 0U)
#define SYSCTL_CLK_MGR_REG0x10_postdiv1_Pos  (3U)
#define SYSCTL_CLK_MGR_REG0x10_postdiv1_Msk  (0x7U << 3U)
#define SYSCTL_CLK_MGR_REG0x10_fbdiv_Pos  (6U)
#define SYSCTL_CLK_MGR_REG0x10_fbdiv_Msk  (0xFFFU << 6U)
#define SYSCTL_CLK_MGR_REG0x10_refdiv_Pos  (18U)
#define SYSCTL_CLK_MGR_REG0x10_refdiv_Msk  (0x3FU << 18U)
#define SYSCTL_CLK_MGR_REG0x14_bpll_frac_Pos  (0U)
#define SYSCTL_CLK_MGR_REG0x14_bpll_frac_Msk  (0xFFFFFFU << 0U)
#define SYSCTL_CLK_MGR_REG0x18_modem_clk_div_num_Pos  (0U)
#define SYSCTL_CLK_MGR_REG0x18_modem_clk_div_num_Msk  (0xFFU << 0U)
#define SYSCTL_CLK_MGR_REG0x18_aclk_out_div_num_Pos  (8U)
#define SYSCTL_CLK_MGR_REG0x18_aclk_out_div_num_Msk  (0xFFU << 8U)
#define SYSCTL_CLK_MGR_REG0x18_bclk_out_div_num_Pos  (16U)
#define SYSCTL_CLK_MGR_REG0x18_bclk_out_div_num_Msk  (0xFFU << 16U)
#define SYSCTL_CLK_MGR_REG0x18_dac_clk_div_num_Pos  (24U)
#define SYSCTL_CLK_MGR_REG0x18_dac_clk_div_num_Msk  (0xFFU << 24U)
#define SYSCTL_IO_DIPLEX0_jtg_tms_sel_Pos  (0U)
#define SYSCTL_IO_DIPLEX0_jtg_tms_sel_Msk  (0x1U << 0U)
#define SYSCTL_IO_DIPLEX0_jtg_tck_sel_Pos  (1U)
#define SYSCTL_IO_DIPLEX0_jtg_tck_sel_Msk  (0x1U << 1U)
#define SYSCTL_IO_DIPLEX0_jtg_tdi_sel_Pos  (2U)
#define SYSCTL_IO_DIPLEX0_jtg_tdi_sel_Msk  (0x1U << 2U)
#define SYSCTL_IO_DIPLEX0_jtg_tdo_sel_Pos  (3U)
#define SYSCTL_IO_DIPLEX0_jtg_tdo_sel_Msk  (0x1U << 3U)
#define SYSCTL_IO_DIPLEX0_jtg_rstn_sel_Pos  (4U)
#define SYSCTL_IO_DIPLEX0_jtg_rstn_sel_Msk  (0x1U << 4U)
#define SYSCTL_IO_DIPLEX0_i2c0_scl_sel_Pos  (5U)
#define SYSCTL_IO_DIPLEX0_i2c0_scl_sel_Msk  (0x1U << 5U)
#define SYSCTL_IO_DIPLEX0_i2c0_sda_sel_Pos  (6U)
#define SYSCTL_IO_DIPLEX0_i2c0_sda_sel_Msk  (0x1U << 6U)
#define SYSCTL_IO_DIPLEX0_i2c1_scl_sel_Pos  (7U)
#define SYSCTL_IO_DIPLEX0_i2c1_scl_sel_Msk  (0x1U << 7U)
#define SYSCTL_IO_DIPLEX0_i2c1_sda_sel_Pos  (8U)
#define SYSCTL_IO_DIPLEX0_i2c1_sda_sel_Msk  (0x1U << 8U)
#define SYSCTL_IO_DIPLEX0_uart1_rxd_sel_Pos  (9U)
#define SYSCTL_IO_DIPLEX0_uart1_rxd_sel_Msk  (0x1U << 9U)
#define SYSCTL_IO_DIPLEX0_uart1_txd_sel_Pos  (10U)
#define SYSCTL_IO_DIPLEX0_uart1_txd_sel_Msk  (0x1U << 10U)
#define SYSCTL_IO_DIPLEX0_uart2_rxd_sel_Pos  (11U)
#define SYSCTL_IO_DIPLEX0_uart2_rxd_sel_Msk  (0x1U << 11U)
#define SYSCTL_IO_DIPLEX0_uart2_txd_sel_Pos  (12U)
#define SYSCTL_IO_DIPLEX0_uart2_txd_sel_Msk  (0x1U << 12U)
#define SYSCTL_IO_DIPLEX0_uart3_rxd_sel_Pos  (13U)
#define SYSCTL_IO_DIPLEX0_uart3_rxd_sel_Msk  (0x3U << 13U)
#define SYSCTL_IO_DIPLEX0_uart3_txd_sel_Pos  (15U)
#define SYSCTL_IO_DIPLEX0_uart3_txd_sel_Msk  (0x3U << 15U)
#define SYSCTL_IO_DIPLEX0_pwm0_sel_Pos  (17U)
#define SYSCTL_IO_DIPLEX0_pwm0_sel_Msk  (0x1U << 17U)
#define SYSCTL_IO_DIPLEX0_pwm1_sel_Pos  (18U)
#define SYSCTL_IO_DIPLEX0_pwm1_sel_Msk  (0x1U << 18U)
#define SYSCTL_IO_DIPLEX0_pwm2_sel_Pos  (19U)
#define SYSCTL_IO_DIPLEX0_pwm2_sel_Msk  (0x1U << 19U)
#define SYSCTL_IO_DIPLEX0_ptb7_sel_Pos  (31U)
#define SYSCTL_IO_DIPLEX0_ptb7_sel_Msk  (0x1U << 31U)
#define SYSCTL_IO_DIPLEX1_spi0_csn0_sel_Pos  (0U)
#define SYSCTL_IO_DIPLEX1_spi0_csn0_sel_Msk  (0x3U << 0U)
#define SYSCTL_IO_DIPLEX1_spi0_csn1_sel_Pos  (2U)
#define SYSCTL_IO_DIPLEX1_spi0_csn1_sel_Msk  (0x1U << 2U)
#define SYSCTL_IO_DIPLEX1_spi0_sclk_sel_Pos  (3U)
#define SYSCTL_IO_DIPLEX1_spi0_sclk_sel_Msk  (0x3U << 3U)
#define SYSCTL_IO_DIPLEX1_spi0_mosi_sel_Pos  (5U)
#define SYSCTL_IO_DIPLEX1_spi0_mosi_sel_Msk  (0x3U << 5U)
#define SYSCTL_IO_DIPLEX1_spi0_miso_sel_Pos  (7U)
#define SYSCTL_IO_DIPLEX1_spi0_miso_sel_Msk  (0x3U << 7U)
#define SYSCTL_IO_DIPLEX1_spi1_csn0_sel_Pos  (9U)
#define SYSCTL_IO_DIPLEX1_spi1_csn0_sel_Msk  (0x3U << 9U)
#define SYSCTL_IO_DIPLEX1_spi1_csn1_sel_Pos  (11U)
#define SYSCTL_IO_DIPLEX1_spi1_csn1_sel_Msk  (0x3U << 11U)
#define SYSCTL_IO_DIPLEX1_spi1_sclk_sel_Pos  (13U)
#define SYSCTL_IO_DIPLEX1_spi1_sclk_sel_Msk  (0x3U << 13U)
#define SYSCTL_IO_DIPLEX1_spi1_mosi_sel_Pos  (15U)
#define SYSCTL_IO_DIPLEX1_spi1_mosi_sel_Msk  (0x3U << 15U)
#define SYSCTL_IO_DIPLEX1_spi1_miso_sel_Pos  (17U)
#define SYSCTL_IO_DIPLEX1_spi1_miso_sel_Msk  (0x3U << 17U)
#define SYSCTL_IO_DIPLEX1_bs_inter_in_sel_Pos  (19U)
#define SYSCTL_IO_DIPLEX1_bs_inter_in_sel_Msk  (0x3U << 19U)
#define SYSCTL_IO_DIPLEX1_bs_inter_out_sel_Pos  (21U)
#define SYSCTL_IO_DIPLEX1_bs_inter_out_sel_Msk  (0x3U << 21U)
#define SYSCTL_IO_DIPLEX1_time_slot_rx_sel_Pos  (23U)
#define SYSCTL_IO_DIPLEX1_time_slot_rx_sel_Msk  (0x3U << 23U)
#define SYSCTL_IO_DIPLEX1_time_slot_tx_sel_Pos  (25U)
#define SYSCTL_IO_DIPLEX1_time_slot_tx_sel_Msk  (0x3U << 25U)
#define SYSCTL_IO_DIPLEX1_ptb2_sel_Pos  (27U)
#define SYSCTL_IO_DIPLEX1_ptb2_sel_Msk  (0x1U << 27U)
#define SYSCTL_IO_DIPLEX1_ptb3_sel_Pos  (28U)
#define SYSCTL_IO_DIPLEX1_ptb3_sel_Msk  (0x1U << 28U)
#define SYSCTL_IO_DIPLEX1_ptb4_sel_Pos  (29U)
#define SYSCTL_IO_DIPLEX1_ptb4_sel_Msk  (0x1U << 29U)
#define SYSCTL_IO_DIPLEX1_ptb5_sel_Pos  (30U)
#define SYSCTL_IO_DIPLEX1_ptb5_sel_Msk  (0x1U << 30U)
#define SYSCTL_IO_DIPLEX1_ptb6_sel_Pos  (31U)
#define SYSCTL_IO_DIPLEX1_ptb6_sel_Msk  (0x1U << 31U)
#define SYSCTL_IO_DIPLEX2_clk_out_sel_Pos  (0U)
#define SYSCTL_IO_DIPLEX2_clk_out_sel_Msk  (0x3U << 0U)
#define SYSCTL_IO_DIPLEX2_lcd_cs_sel_Pos  (3U)
#define SYSCTL_IO_DIPLEX2_lcd_cs_sel_Msk  (0x3U << 3U)
#define SYSCTL_IO_DIPLEX2_lcd_rs_sel_Pos  (5U)
#define SYSCTL_IO_DIPLEX2_lcd_rs_sel_Msk  (0x3U << 5U)
#define SYSCTL_IO_DIPLEX2_lcd_wr_sel_Pos  (7U)
#define SYSCTL_IO_DIPLEX2_lcd_wr_sel_Msk  (0x1U << 7U)
#define SYSCTL_IO_DIPLEX2_lcd_rd_sel_Pos  (8U)
#define SYSCTL_IO_DIPLEX2_lcd_rd_sel_Msk  (0x1U << 8U)
#define SYSCTL_IO_DIPLEX2_lcd_db0_sel_Pos  (9U)
#define SYSCTL_IO_DIPLEX2_lcd_db0_sel_Msk  (0x3U << 9U)
#define SYSCTL_IO_DIPLEX2_lcd_db1_sel_Pos  (11U)
#define SYSCTL_IO_DIPLEX2_lcd_db1_sel_Msk  (0x3U << 11U)
#define SYSCTL_IO_DIPLEX2_lcd_db2_sel_Pos  (13U)
#define SYSCTL_IO_DIPLEX2_lcd_db2_sel_Msk  (0x1U << 13U)
#define SYSCTL_IO_DIPLEX2_lcd_db3_sel_Pos  (14U)
#define SYSCTL_IO_DIPLEX2_lcd_db3_sel_Msk  (0x1U << 14U)
#define SYSCTL_IO_DIPLEX2_lcd_db4_sel_Pos  (15U)
#define SYSCTL_IO_DIPLEX2_lcd_db4_sel_Msk  (0x1U << 15U)
#define SYSCTL_IO_DIPLEX2_lcd_db5_sel_Pos  (16U)
#define SYSCTL_IO_DIPLEX2_lcd_db5_sel_Msk  (0x1U << 16U)
#define SYSCTL_IO_DIPLEX2_lcd_db6_sel_Pos  (17U)
#define SYSCTL_IO_DIPLEX2_lcd_db6_sel_Msk  (0x1U << 17U)
#define SYSCTL_IO_DIPLEX2_lcd_db7_sel_Pos  (18U)
#define SYSCTL_IO_DIPLEX2_lcd_db7_sel_Msk  (0x1U << 18U)
#define SYSCTL_IO_DIPLEX2_adc0_in_sel_Pos  (19U)
#define SYSCTL_IO_DIPLEX2_adc0_in_sel_Msk  (0x1U << 19U)
#define SYSCTL_IO_DIPLEX2_adc1_in_sel_Pos  (20U)
#define SYSCTL_IO_DIPLEX2_adc1_in_sel_Msk  (0x1U << 20U)
#define SYSCTL_IO_DIPLEX2_adc2_in_sel_Pos  (21U)
#define SYSCTL_IO_DIPLEX2_adc2_in_sel_Msk  (0x1U << 21U)
#define SYSCTL_IO_DIPLEX2_adc3_in_sel_Pos  (22U)
#define SYSCTL_IO_DIPLEX2_adc3_in_sel_Msk  (0x1U << 22U)
#define SYSCTL_IO_DIPLEX2_adc4_in_sel_Pos  (23U)
#define SYSCTL_IO_DIPLEX2_adc4_in_sel_Msk  (0x1U << 23U)
#define SYSCTL_IO_DIPLEX2_adc5_in_sel_Pos  (24U)
#define SYSCTL_IO_DIPLEX2_adc5_in_sel_Msk  (0x1U << 24U)
#define SYSCTL_IO_DIPLEX2_adc6_in_sel_Pos  (25U)
#define SYSCTL_IO_DIPLEX2_adc6_in_sel_Msk  (0x1U << 25U)
#define SYSCTL_IO_DIPLEX2_adc7_in_sel_Pos  (26U)
#define SYSCTL_IO_DIPLEX2_adc7_in_sel_Msk  (0x1U << 26U)
#define SYSCTL_IO_DIPLEX2_dac_vout_mcua_sel_Pos  (27U)
#define SYSCTL_IO_DIPLEX2_dac_vout_mcua_sel_Msk  (0x1U << 27U)
#define SYSCTL_IO_DIPLEX2_dac_vout_mcub_sel_Pos  (28U)
#define SYSCTL_IO_DIPLEX2_dac_vout_mcub_sel_Msk  (0x1U << 28U)
#define SYSCTL_IO_DIPLEX2_dac_vout_mcuc_sel_Pos  (29U)
#define SYSCTL_IO_DIPLEX2_dac_vout_mcuc_sel_Msk  (0x1U << 29U)
#define SYSCTL_AUDIO_CONTROL_tx_voice_source_Pos  (0U)
#define SYSCTL_AUDIO_CONTROL_tx_voice_source_Msk  (0x1U << 0U)
#define SYSCTL_AUDIO_CONTROL_i2s_slave_mode_Pos  (1U)
#define SYSCTL_AUDIO_CONTROL_i2s_slave_mode_Msk  (0x1U << 1U)
#define SYSCTL_AUDIO_CONTROL_sel_i2s_Pos  (2U)
#define SYSCTL_AUDIO_CONTROL_sel_i2s_Msk  (0x1U << 2U)
#define SYSCTL_AUDIO_CONTROL_fm_sidetone_en_Pos  (3U)
#define SYSCTL_AUDIO_CONTROL_fm_sidetone_en_Msk  (0x1U << 3U)
#define SYSCTL_AUDIO_CONTROL_ahb_wr_voice_en_Pos  (4U)
#define SYSCTL_AUDIO_CONTROL_ahb_wr_voice_en_Msk  (0x1U << 4U)
#define SYSCTL_AUDIO_CONTROL_ahb_rd_voice_en_Pos  (5U)
#define SYSCTL_AUDIO_CONTROL_ahb_rd_voice_en_Msk  (0x1U << 5U)
#define SYSCTL_AUDIO_CONTROL_fm_play_ctrl_Pos  (6U)
#define SYSCTL_AUDIO_CONTROL_fm_play_ctrl_Msk  (0x1U << 6U)
#define SYSCTL_AUDIO_CONTROL_ring_play_ctrl_Pos  (7U)
#define SYSCTL_AUDIO_CONTROL_ring_play_ctrl_Msk  (0x1U << 7U)
#define SYSCTL_AUDIO_CONTROL_ring_full_two_Pos  (31U)
#define SYSCTL_AUDIO_CONTROL_ring_full_two_Msk  (0x1U << 31U)
#define SYSCTL_AUDIO_BUFFER_CLR_clr_wr_ram_cpu_Pos  (0U)
#define SYSCTL_AUDIO_BUFFER_CLR_clr_wr_ram_cpu_Msk  (0x1U << 0U)
#define SYSCTL_AUDIO_BUFFER_CLR_clr_rd_ram_cpu_Pos  (1U)
#define SYSCTL_AUDIO_BUFFER_CLR_clr_rd_ram_cpu_Msk  (0x1U << 1U)
#define SYSCTL_LINEOUT_CTRL_line2out_en_Pos  (0U)
#define SYSCTL_LINEOUT_CTRL_line2out_en_Msk  (0x1U << 0U)
#define SYSCTL_LINEOUT_CTRL_line1out_en_Pos  (1U)
#define SYSCTL_LINEOUT_CTRL_line1out_en_Msk  (0x1U << 1U)
#define SYSCTL_LINEOUT_CTRL_standby_lo_Pos  (31U)
#define SYSCTL_LINEOUT_CTRL_standby_lo_Msk  (0x1U << 31U)
#define SYSCTL_CODEC_I2C_MUX_codec_i2c_address_reg_Pos  (0U)
#define SYSCTL_CODEC_I2C_MUX_codec_i2c_address_reg_Msk  (0x7FU << 0U)
#define SYSCTL_CODEC_I2C_MUX_codec_si2c_reg_Pos  (7U)
#define SYSCTL_CODEC_I2C_MUX_codec_si2c_reg_Msk  (0x1U << 7U)
#define SYSCTL_INTERP_CLEAR_clear_time_txslot_inter_Pos  (0U)
#define SYSCTL_INTERP_CLEAR_clear_time_txslot_inter_Msk  (0x1U << 0U)
#define SYSCTL_LAYER2_CONTROL_rx_master_mode_Pos  (0U)
#define SYSCTL_LAYER2_CONTROL_rx_master_mode_Msk  (0x1U << 0U)
#define SYSCTL_LAYER2_CONTROL_tx_master_mode_Pos  (1U)
#define SYSCTL_LAYER2_CONTROL_tx_master_mode_Msk  (0x1U << 1U)
#define SYSCTL_LAYER2_CONTROL_rxen_Pos  (6U)
#define SYSCTL_LAYER2_CONTROL_rxen_Msk  (0x1U << 6U)
#define SYSCTL_LAYER2_CONTROL_txen_Pos  (7U)
#define SYSCTL_LAYER2_CONTROL_txen_Msk  (0x1U << 7U)
#define SYSCTL_LAYER2_SLOTON_dll_tx_slot_on_Pos  (0U)
#define SYSCTL_LAYER2_SLOTON_dll_tx_slot_on_Msk  (0x1U << 0U)
#define SYSCTL_LAYER2_SLOTON_layer2slot_Pos  (5U)
#define SYSCTL_LAYER2_SLOTON_layer2slot_Msk  (0x1U << 5U)
#define SYSCTL_LAYER2_SLOTON_rxen_Pos  (6U)
#define SYSCTL_LAYER2_SLOTON_rxen_Msk  (0x1U << 6U)
#define SYSCTL_LAYER2_SLOTON_txen_Pos  (7U)
#define SYSCTL_LAYER2_SLOTON_txen_Msk  (0x1U << 7U)
#define SYSCTL_LAYER2_TXRX_CTRL_command_Pos  (0U)
#define SYSCTL_LAYER2_TXRX_CTRL_command_Msk  (0xFFU << 0U)
#define SYSCTL_LAYER2_TXRX_CTRL_begin_v_layer2_Pos  (15U)
#define SYSCTL_LAYER2_TXRX_CTRL_begin_v_layer2_Msk  (0x1U << 15U)
#define SYSCTL_LAYER2_TXRX_CTRL_syncfail_layer2_tx_Pos  (22U)
#define SYSCTL_LAYER2_TXRX_CTRL_syncfail_layer2_tx_Msk  (0x1U << 22U)
#define SYSCTL_LAYER2_TXRX_CTRL_syncfail_layer2_rx_Pos  (23U)
#define SYSCTL_LAYER2_TXRX_CTRL_syncfail_layer2_rx_Msk  (0x1U << 23U)
#define SYSCTL_LAYER2_TXRX_CTRL_tx_complete_cpu_Pos  (31U)
#define SYSCTL_LAYER2_TXRX_CTRL_tx_complete_cpu_Msk  (0x1U << 31U)
#define SYSCTL_LAYER2_STATUS_slot_cnt_Pos  (0U)
#define SYSCTL_LAYER2_STATUS_slot_cnt_Msk  (0x1FFU << 0U)

#define SystemControl_BASE  0x11000000UL
#define SystemControl       ((SystemControl_Type *) SystemControl_BASE)
/* ===================================================================================
 * TIMER @ 0x14000000: DesignWare APB timer, 6 channels at a 0x14 stride (DS §4.8 p.187-200).
 * HAND-MAINTAINED. Checked against a live register read of a running radio. Channel 0
 * (TIMER.CH[0]) is the uC/OS-III tick: PIC source 1 (TIMER_1), CPU vector 33 (DS Table 30;
 * hardware-confirmed 2026-10-01). The datasheet prints Timer5/6 at Timer4's offsets; the stride
 * (and the firmware) puts them at 0x50 and 0x64.
 * =================================================================================== */
typedef struct {
  __IO uint32_t LoadCount;     /* +0x00 reload value */
  __I  uint32_t CurrentValue;  /* +0x04 live down-counter */
  __IO uint32_t ControlReg;    /* +0x08 bit0 enable, bit1 mode (1 = periodic), bit2 int_mask */
  __I  uint32_t EOI;           /* +0x0c read to clear this channel's interrupt */
  __I  uint32_t IntStatus;     /* +0x10 this channel's masked interrupt status */
} TIMER_CH_Type;               /* 0x14-byte stride, matches sizeof(TIMER_CH_Type) exactly */

#define TIMER_CH_ControlReg_enable_Pos    (0U)
#define TIMER_CH_ControlReg_enable_Msk    (1U << TIMER_CH_ControlReg_enable_Pos)
#define TIMER_CH_ControlReg_mode_Pos      (1U) /* 1=user/periodic mode */
#define TIMER_CH_ControlReg_mode_Msk      (1U << TIMER_CH_ControlReg_mode_Pos)
#define TIMER_CH_ControlReg_int_mask_Pos  (2U) /* 1=this channel's interrupt is masked */
#define TIMER_CH_ControlReg_int_mask_Msk  (1U << TIMER_CH_ControlReg_int_mask_Pos)

typedef struct {
  TIMER_CH_Type CH[6];              /* Timer1..Timer6 @ +0x00, +0x14, +0x28, +0x3c, +0x50, +0x64 */
  __IO uint32_t RESERVED0[10];      /* 0x78-0x9f */
  __I  uint32_t TimersIntStatus;    /* 0xa0 all-channel masked interrupt status */
  __I  uint32_t TimersEOI;          /* 0xa4 read to clear all channels' interrupts */
  __I  uint32_t TimersRawIntStatus; /* 0xa8 all-channel unmasked (raw) interrupt status */
  __I  uint32_t TIMERS_COMP_VERSION;/* 0xac DesignWare IP component version */
} TIMER_Type;

#define TIMER_BASE  0x14000000UL
#define TIMER       ((TIMER_Type *) TIMER_BASE)

/* BEGIN GENERATED by the hr_c7000_svd register-map generator; do not edit by hand */
/* Registers and fields from the HR_C7000 v2.7 guide plus firmware evidence; the .svd
 * carries the full per-register citations. Field macros follow CMSIS <TYPE>_<REG>_<FIELD>_Pos/_Msk. */

typedef struct {   /* i8080-style parallel LCD bus controller (DS §5.3, p.264-268). Drives the DM-32's ST7789V-class panel controlle */
  __IO uint32_t INDEX;                       /* 0x00 Addressing register. DS §5.3.5.1 p.266. FW: 0 reads, 1 write. Reset 0x0 (DS). */
  __IO uint32_t DATA;                        /* 0x04 Data register. DS §5.3.5.2 p.266. FW: 0 reads, 1 write. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_8[2];               /* 0x8-0xf */
  __IO uint32_t WCFG;                        /* 0x10 Write timing parameter configuration. DS §5.3.5.3 p.266. FW: 0 reads, 1 write. Reset 0x10101 (DS). */
  __IO uint32_t RCFG;                        /* 0x14 Read timing parameter configuration. DS §5.3.5.4 p.266. The datasheet prints the reserved row as [31:0], overl */
  __I  uint32_t RESERVED_18[2];              /* 0x18-0x1f */
  __IO uint32_t SCFG;                        /* 0x20 Configuration registers. DS §5.3.5.5 p.268. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_24[1];              /* 0x24-0x27 */
  __IO uint32_t UNDOC_0x28;                  /* 0x28 Not in the datasheet's I80 register table. The stock firmware reads and writes it (FW: 1 read, 1 write). Role  */
  __IO uint32_t AC_MODE;                     /* 0x2c Bus Mode Register. DS §5.3.5.6 p.268. Reset 0x0 (DS). */
} I80_Type;   /* 0x30 bytes */
#define I80_INDEX_INDEX0_Pos  0u
#define I80_INDEX_INDEX0_Msk  (0xffffffffu << 0u)
#define I80_DATA_DATA0_Pos  0u
#define I80_DATA_DATA0_Msk  (0xffffffffu << 0u)
#define I80_WCFG_TCNT_WHT0_Pos  16u
#define I80_WCFG_TCNT_WHT0_Msk  (0xffu << 16u)
#define I80_WCFG_TCNT_WL0_Pos  8u
#define I80_WCFG_TCNT_WL0_Msk  (0xffu << 8u)
#define I80_WCFG_TCNT_WHF0_Pos  0u
#define I80_WCFG_TCNT_WHF0_Msk  (0xffu << 0u)
#define I80_RCFG_TCNT_RHT0_Pos  16u
#define I80_RCFG_TCNT_RHT0_Msk  (0xffu << 16u)
#define I80_RCFG_TCNT_RL0_Pos  8u
#define I80_RCFG_TCNT_RL0_Msk  (0xffu << 8u)
#define I80_RCFG_RCNT_RHF0_Pos  0u
#define I80_RCFG_RCNT_RHF0_Msk  (0xffu << 0u)
#define I80_SCFG_P0_SCFG_Pos  0u
#define I80_SCFG_P0_SCFG_Msk  (0xffffffffu << 0u)
#define I80_AC_MODE_BUSHS_Pos  0u
#define I80_AC_MODE_BUSHS_Msk  (0xffffffffu << 0u)

typedef struct {   /* Synopsys DesignWare USB 2.0 OTG controller (GSNPSID reads 0x4f54270a), configured device-only with a USB 1.1 f */
  __I  uint32_t RESERVED_0[2];               /* 0x0-0x7 */
  __IO uint32_t GAHBCFG;                     /* 0x08 AHB Configuration , global AHB Configuration. DS §5.6.5.1 p.336. Reset 0x0 (DS). */
  __IO uint32_t GUSBCFG;                     /* 0x0c USB Configuration , Global USB Configuration. DS §5.6.5.2 p.338. Reset 0x1440 (DS). */
  __IO uint32_t GRSTCTL;                     /* 0x10 Reset , global reset control register. DS §5.6.5.3 p.338. Reset 0x80000000 (DS). */
  __IO uint32_t GINTSTS;                     /* 0x14 Interrupt , global interrupt status register. DS §5.6.5.4 p.340. */
  __IO uint32_t GINTMSK;                     /* 0x18 Interrupt Mask , global interrupt mask. DS §5.6.5.5 p.343. Reset 0x0 (DS). */
  __I  uint32_t GRXSTSR;                     /* 0x1c DS §5.6.5.6 p.344. Note: GRXSTSP For POP only The header information seems to be not POPable Data information  */
  __I  uint32_t GRXSTSP;                     /* 0x20 DS §5.6.5.6 p.344. Same layout as GRXSTSR; reading GRXSTSP also pops the entry. Note: GRXSTSP For POP only The */
  __IO uint32_t GRXFSIZ;                     /* 0x24 Receive FIFO Size , RxFIFO Allocate control. DS §5.6.5.7 p.346. Reset 0x80 (DS). */
  __IO uint32_t GNPTXFSIZ;                   /* 0x28 DS §5.6.5.8 p.346. Reset 0x800080 (DS). */
  __I  uint32_t RESERVED_2C[3];              /* 0x2c-0x37 */
  __IO uint32_t GGPIO;                       /* 0x38 General Purpose IO , general IO register. DS §5.6.5.9 p.346. Reset 0x40080000 (DS). */
  __IO uint32_t GUID;                        /* 0x3c User ID , user ID register. DS §5.6.5.10 p.348. Reset 0x45700322 (DS). */
  __I  uint32_t GSNPSID;                     /* 0x40 Synopsys ID , version number read-only. DS §5.6.5.11 p.348. Reset 0x4f54270a (DS). */
  __I  uint32_t GHWCFG1;                     /* 0x44 User HW Config1 , soft core configuration. DS §5.6.5.12 p.349. Reset 0x264 (DS). */
  __I  uint32_t GHWCFG2;                     /* 0x48 User HW Config2 , soft core configuration. DS §5.6.5.13 p.349. Reset 0x2288d114 (DS). */
  __I  uint32_t GHWCFG3;                     /* 0x4c User HW Config3 , soft core configuration. DS §5.6.5.14 p.349. Reset 0x7a0400 (DS). */
  __I  uint32_t GHWCFG4;                     /* 0x50 User HW Config4 , soft core configuration. DS §5.6.5.15 p.351. Reset 0xa300020 (DS). */
  __I  uint32_t GUSRSTS;                     /* 0x54 User States , user-defined observation signals. DS §5.6.5.16 p.351. Reset 0x10700000 (DS). */
  __I  uint32_t RESERVED_58[43];             /* 0x58-0x103 */
  __IO uint32_t DIEPTXF1;                    /* 0x104 DS §5.6.5.17 p.353. IN endpoint 1 TxFIFO size/start. Register Table 19 places DIEPTXF1 at 0x104 and DIEPTXF3 a */
  __IO uint32_t DIEPTXF3;                    /* 0x108 DS §5.6.5.17 p.353. IN endpoint 3 TxFIFO size/start. Register Table 19 places DIEPTXF1 at 0x104 and DIEPTXF3 a */
  __I  uint32_t RESERVED_10C[445];           /* 0x10c-0x7ff */
  __IO uint32_t DCFG;                        /* 0x800 Device Configuration , device overall. DS §5.6.5.18 p.353. Reset 0x200000 (DS). */
  __IO uint32_t DCTL;                        /* 0x804 Device Control , device overall control. DS §5.6.5.19 p.355. Reset 0x0 (DS). */
  __I  uint32_t DSTS;                        /* 0x808 Device Status , device overall status. DS §5.6.5.20 p.357. Reset 0x2 (DS). */
  __I  uint32_t RESERVED_80C[1];             /* 0x80c-0x80f */
  __IO uint32_t DIEPMSK;                     /* 0x810 equipment. DS §5.6.5.21 p.358. Reset 0x0 (DS). */
  __IO uint32_t DOEPMSK;                     /* 0x814 DS §5.6.5.22 p.359. Reset 0x0 (DS). */
  __I  uint32_t DAINT;                       /* 0x818 the device. DS §5.6.5.23 p.359. Reset 0x0 (DS). */
  __I  uint32_t DAINTMSK;                    /* 0x81c DS §5.6.5.24 p.360. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_820[4];             /* 0x820-0x82f */
  __IO uint32_t DTHRCTL;                     /* 0x830 Device Threshold Control , device threshold. DS §5.6.5.25 p.360. Reset 0x8100020 (DS). */
  __I  uint32_t DIEPEMPMSK;                  /* 0x834 DS §5.6.5.26 p.360. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_838[50];            /* 0x838-0x8ff */
  __IO uint32_t DIEPCTL0;                    /* 0x900 EP0. DS §5.6.5.27 p.361. Reset 0x8000 (DS). */
  __I  uint32_t RESERVED_904[1];             /* 0x904-0x907 */
  __IO uint32_t DIEPINT0;                    /* 0x908 DS §5.6.5.28 p.363. Endpoint 0 instance of DIEPINT0/1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_90C[1];             /* 0x90c-0x90f */
  __IO uint32_t DIEPTSIZ0;                   /* 0x910 Device IN Endpoint0 Transfer Size , device IN. DS §5.6.5.29 p.363. Reset 0x0 (DS). */
  __IO uint32_t DIEPDMA0;                    /* 0x914 DS §5.6.5.30 p.365. Endpoint 0 instance of DIEPDMA0/1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t DTXFSTS0;                    /* 0x918 DS §5.6.5.31 p.365. Endpoint 0 instance of DTXFSTS0/1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_91C[1];             /* 0x91c-0x91f */
  __IO uint32_t DIEPCTL1;                    /* 0x920 DS §5.6.5.36 p.369. Endpoint 1 instance of DIEPCTL1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_924[1];             /* 0x924-0x927 */
  __IO uint32_t DIEPINT1;                    /* 0x928 DS §5.6.5.28 p.363. Endpoint 1 instance of DIEPINT0/1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_92C[1];             /* 0x92c-0x92f */
  __IO uint32_t DIEPTSIZ1;                   /* 0x930 DS §5.6.5.37 p.373. Endpoint 1 instance of DIEPTSIZ1/3 (stride 0x20). Reset 0x0 (DS). */
  __IO uint32_t DIEPDMA1;                    /* 0x934 DS §5.6.5.30 p.365. Endpoint 1 instance of DIEPDMA0/1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t DTXFSTS1;                    /* 0x938 DS §5.6.5.31 p.365. Endpoint 1 instance of DTXFSTS0/1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_93C[9];             /* 0x93c-0x95f */
  __IO uint32_t DIEPCTL3;                    /* 0x960 DS §5.6.5.36 p.369. Endpoint 3 instance of DIEPCTL1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_964[1];             /* 0x964-0x967 */
  __IO uint32_t DIEPINT3;                    /* 0x968 DS §5.6.5.28 p.363. Endpoint 3 instance of DIEPINT0/1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_96C[1];             /* 0x96c-0x96f */
  __IO uint32_t DIEPTSIZ3;                   /* 0x970 DS §5.6.5.37 p.373. Endpoint 3 instance of DIEPTSIZ1/3 (stride 0x20). Reset 0x0 (DS). */
  __IO uint32_t DIEPDMA3;                    /* 0x974 DS §5.6.5.30 p.365. Endpoint 3 instance of DIEPDMA0/1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t DTXFSTS3;                    /* 0x978 DS §5.6.5.31 p.365. Endpoint 3 instance of DTXFSTS0/1/3 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_97C[97];            /* 0x97c-0xaff */
  __IO uint32_t DOEPCTL0;                    /* 0xb00 DS §5.6.5.32 p.365. Reset 0x8000 (DS). */
  __I  uint32_t RESERVED_B04[1];             /* 0xb04-0xb07 */
  __IO uint32_t DOEPINT0;                    /* 0xb08 DS §5.6.5.33 p.367. Endpoint 0 instance of DOEPINT0/2/4 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_B0C[1];             /* 0xb0c-0xb0f */
  __IO uint32_t DOEPTSIZ0;                   /* 0xb10 OUT. DS §5.6.5.34 p.369. Reset 0x0 (DS). */
  __IO uint32_t DOEPDMA0;                    /* 0xb14 DS §5.6.5.35 p.369. Endpoint 0 instance of DOEPDMA0/2/4 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_B18[10];            /* 0xb18-0xb3f */
  __IO uint32_t DOEPCTL2;                    /* 0xb40 DS §5.6.5.38 p.373. Endpoint 2 instance of DOEPCTL2/4 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_B44[1];             /* 0xb44-0xb47 */
  __IO uint32_t DOEPINT2;                    /* 0xb48 DS §5.6.5.33 p.367. Endpoint 2 instance of DOEPINT0/2/4 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_B4C[1];             /* 0xb4c-0xb4f */
  __IO uint32_t DOEPTSIZ2;                   /* 0xb50 DS §5.6.5.39 p.376. Endpoint 2 instance of DOEPTSIZ2/4 (stride 0x20). Reset 0x0 (DS). */
  __IO uint32_t DOEPDMA2;                    /* 0xb54 DS §5.6.5.35 p.369. Endpoint 2 instance of DOEPDMA0/2/4 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_B58[10];            /* 0xb58-0xb7f */
  __IO uint32_t DOEPCTL4;                    /* 0xb80 DS §5.6.5.38 p.373. Endpoint 4 instance of DOEPCTL2/4 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_B84[1];             /* 0xb84-0xb87 */
  __IO uint32_t DOEPINT4;                    /* 0xb88 DS §5.6.5.33 p.367. Endpoint 4 instance of DOEPINT0/2/4 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_B8C[1];             /* 0xb8c-0xb8f */
  __IO uint32_t DOEPTSIZ4;                   /* 0xb90 DS §5.6.5.39 p.376. Endpoint 4 instance of DOEPTSIZ2/4 (stride 0x20). Reset 0x0 (DS). */
  __IO uint32_t DOEPDMA4;                    /* 0xb94 DS §5.6.5.35 p.369. Endpoint 4 instance of DOEPDMA0/2/4 (stride 0x20). Reset 0x0 (DS). */
  __I  uint32_t RESERVED_B98[154];           /* 0xb98-0xdff */
  __IO uint32_t PCGCCTL;                     /* 0xe00 gating. DS §5.6.5.40 p.377. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_E04[127];           /* 0xe04-0xfff */
  __IO uint32_t DEVEP0FF;                    /* 0x1000 DS §5.6.4 p.334. Endpoint 0 data FIFO push/pop window (4 KB at 0x1000). Listed in Register Table 19 only. */
  __I  uint32_t RESERVED_1004[1023];         /* 0x1004-0x1fff */
  __IO uint32_t DEVEP1FF;                    /* 0x2000 DS §5.6.4 p.334. Endpoint 1 data FIFO push/pop window (4 KB at 0x2000). Listed in Register Table 19 only. */
  __I  uint32_t RESERVED_2004[1023];         /* 0x2004-0x2fff */
  __IO uint32_t DEVEP2FF;                    /* 0x3000 DS §5.6.4 p.334. Endpoint 2 data FIFO push/pop window (4 KB at 0x3000). Listed in Register Table 19 only. */
  __I  uint32_t RESERVED_3004[1023];         /* 0x3004-0x3fff */
  __IO uint32_t DEVEP3FF;                    /* 0x4000 DS §5.6.4 p.334. Endpoint 3 data FIFO push/pop window (4 KB at 0x4000). Listed in Register Table 19 only. */
  __I  uint32_t RESERVED_4004[1023];         /* 0x4004-0x4fff */
  __IO uint32_t DEVEP4FF;                    /* 0x5000 DS §5.6.4 p.334. Endpoint 4 data FIFO push/pop window (4 KB at 0x5000). Listed in Register Table 19 only. */
} USB_Type;   /* 0x5004 bytes */
#define USB_GAHBCFG_NPTxFEmpLvl_Pos  7u
#define USB_GAHBCFG_NPTxFEmpLvl_Msk  (0x1u << 7u)
#define USB_GAHBCFG_DMAEn_Pos  5u
#define USB_GAHBCFG_DMAEn_Msk  (0x1u << 5u)
#define USB_GAHBCFG_HBstLen_Pos  1u
#define USB_GAHBCFG_HBstLen_Msk  (0xfu << 1u)
#define USB_GAHBCFG_GlbIntrMsk_Pos  0u
#define USB_GAHBCFG_GlbIntrMsk_Msk  (0x1u << 0u)
#define USB_GUSBCFG_corrtxpkt_Pos  31u
#define USB_GUSBCFG_corrtxpkt_Msk  (0x1u << 31u)
#define USB_GUSBCFG_USBTrdTim_Pos  10u
#define USB_GUSBCFG_USBTrdTim_Msk  (0xfu << 10u)
#define USB_GUSBCFG_PHYSel_Pos  6u
#define USB_GUSBCFG_PHYSel_Msk  (0x1u << 6u)
#define USB_GUSBCFG_FSIntf_Pos  5u
#define USB_GUSBCFG_FSIntf_Msk  (0x1u << 5u)
#define USB_GUSBCFG_TOutCal_Pos  0u
#define USB_GUSBCFG_TOutCal_Msk  (0x7u << 0u)
#define USB_GRSTCTL_AHBIdle_Pos  31u
#define USB_GRSTCTL_AHBIdle_Msk  (0x1u << 31u)
#define USB_GRSTCTL_DMAReq_Pos  30u
#define USB_GRSTCTL_DMAReq_Msk  (0x1u << 30u)
#define USB_GRSTCTL_TxFNum_Pos  6u
#define USB_GRSTCTL_TxFNum_Msk  (0x1fu << 6u)
#define USB_GRSTCTL_TxFFlsh_Pos  5u
#define USB_GRSTCTL_TxFFlsh_Msk  (0x1u << 5u)
#define USB_GRSTCTL_RxFFlsh_Pos  4u
#define USB_GRSTCTL_RxFFlsh_Msk  (0x1u << 4u)
#define USB_GRSTCTL_HSftRst_Pos  1u
#define USB_GRSTCTL_HSftRst_Msk  (0x1u << 1u)
#define USB_GRSTCTL_CSftRst_Pos  0u
#define USB_GRSTCTL_CSftRst_Msk  (0x1u << 0u)
#define USB_GINTSTS_WkUpInt_Pos  31u
#define USB_GINTSTS_WkUpInt_Msk  (0x1u << 31u)
#define USB_GINTSTS_ConIDStsChng_Pos  28u
#define USB_GINTSTS_ConIDStsChng_Msk  (0x1u << 28u)
#define USB_GINTSTS_FetSusp_Pos  22u
#define USB_GINTSTS_FetSusp_Msk  (0x1u << 22u)
#define USB_GINTSTS_incomplSOOUT_Pos  21u
#define USB_GINTSTS_incomplSOOUT_Msk  (0x1u << 21u)
#define USB_GINTSTS_incompleSOIN_Pos  20u
#define USB_GINTSTS_incompleSOIN_Msk  (0x1u << 20u)
#define USB_GINTSTS_OEPInt_Pos  19u
#define USB_GINTSTS_OEPInt_Msk  (0x1u << 19u)
#define USB_GINTSTS_IEPInt_Pos  18u
#define USB_GINTSTS_IEPInt_Msk  (0x1u << 18u)
#define USB_GINTSTS_EPMis_Pos  17u
#define USB_GINTSTS_EPMis_Msk  (0x1u << 17u)
#define USB_GINTSTS_EOPF_Pos  15u
#define USB_GINTSTS_EOPF_Msk  (0x1u << 15u)
#define USB_GINTSTS_ISOOutDrip_Pos  14u
#define USB_GINTSTS_ISOOutDrip_Msk  (0x1u << 14u)
#define USB_GINTSTS_EnumDone_Pos  13u
#define USB_GINTSTS_EnumDone_Msk  (0x1u << 13u)
#define USB_GINTSTS_USBRst_Pos  12u
#define USB_GINTSTS_USBRst_Msk  (0x1u << 12u)
#define USB_GINTSTS_USBSusp_Pos  11u
#define USB_GINTSTS_USBSusp_Msk  (0x1u << 11u)
#define USB_GINTSTS_ErlySusp_Pos  10u
#define USB_GINTSTS_ErlySusp_Msk  (0x1u << 10u)
#define USB_GINTSTS_GOUTNakEff_Pos  7u
#define USB_GINTSTS_GOUTNakEff_Msk  (0x1u << 7u)
#define USB_GINTSTS_GINNakEff_Pos  6u
#define USB_GINTSTS_GINNakEff_Msk  (0x1u << 6u)
#define USB_GINTSTS_RxFv_Pos  4u
#define USB_GINTSTS_RxFv_Msk  (0x1u << 4u)
#define USB_GINTSTS_Sof_Pos  3u
#define USB_GINTSTS_Sof_Msk  (0x1u << 3u)
#define USB_GINTSTS_OTGInt_Pos  2u
#define USB_GINTSTS_OTGInt_Msk  (0x1u << 2u)
#define USB_GINTSTS_ModeMis_Pos  1u
#define USB_GINTSTS_ModeMis_Msk  (0x1u << 1u)
#define USB_GINTSTS_CurMod_Pos  0u
#define USB_GINTSTS_CurMod_Msk  (0x1u << 0u)
#define USB_GINTMSK_WkUpIntMsk_Pos  31u
#define USB_GINTMSK_WkUpIntMsk_Msk  (0x1u << 31u)
#define USB_GINTMSK_ConIDStsChngMsk_Pos  28u
#define USB_GINTMSK_ConIDStsChngMsk_Msk  (0x1u << 28u)
#define USB_GINTMSK_FetSuspMsk_Pos  22u
#define USB_GINTMSK_FetSuspMsk_Msk  (0x1u << 22u)
#define USB_GINTMSK_incomplSOOUTMsk_Pos  21u
#define USB_GINTMSK_incomplSOOUTMsk_Msk  (0x1u << 21u)
#define USB_GINTMSK_incompleSOINMsk_Pos  20u
#define USB_GINTMSK_incompleSOINMsk_Msk  (0x1u << 20u)
#define USB_GINTMSK_OEPIntMsk_Pos  19u
#define USB_GINTMSK_OEPIntMsk_Msk  (0x1u << 19u)
#define USB_GINTMSK_IEPIntMsk_Pos  18u
#define USB_GINTMSK_IEPIntMsk_Msk  (0x1u << 18u)
#define USB_GINTMSK_EPMisMsk_Pos  17u
#define USB_GINTMSK_EPMisMsk_Msk  (0x1u << 17u)
#define USB_GINTMSK_EOPFMsk_Pos  15u
#define USB_GINTMSK_EOPFMsk_Msk  (0x1u << 15u)
#define USB_GINTMSK_ISOOutDripMsk_Pos  14u
#define USB_GINTMSK_ISOOutDripMsk_Msk  (0x1u << 14u)
#define USB_GINTMSK_EnumDoneMsk_Pos  13u
#define USB_GINTMSK_EnumDoneMsk_Msk  (0x1u << 13u)
#define USB_GINTMSK_USBRstMsk_Pos  12u
#define USB_GINTMSK_USBRstMsk_Msk  (0x1u << 12u)
#define USB_GINTMSK_USBSuspMsk_Pos  11u
#define USB_GINTMSK_USBSuspMsk_Msk  (0x1u << 11u)
#define USB_GINTMSK_ErlySuspMsk_Pos  10u
#define USB_GINTMSK_ErlySuspMsk_Msk  (0x1u << 10u)
#define USB_GINTMSK_GOUTNakEffMsk_Pos  7u
#define USB_GINTMSK_GOUTNakEffMsk_Msk  (0x1u << 7u)
#define USB_GINTMSK_GINNakEffMsk_Pos  6u
#define USB_GINTMSK_GINNakEffMsk_Msk  (0x1u << 6u)
#define USB_GINTMSK_NPTxFEmpMsk_Pos  5u
#define USB_GINTMSK_NPTxFEmpMsk_Msk  (0x1u << 5u)
#define USB_GINTMSK_RxFLvlMsk_Pos  4u
#define USB_GINTMSK_RxFLvlMsk_Msk  (0x1u << 4u)
#define USB_GINTMSK_SofMsk_Pos  3u
#define USB_GINTMSK_SofMsk_Msk  (0x1u << 3u)
#define USB_GINTMSK_OTGIntMsk_Pos  2u
#define USB_GINTMSK_OTGIntMsk_Msk  (0x1u << 2u)
#define USB_GINTMSK_ModeMisMsk_Pos  1u
#define USB_GINTMSK_ModeMisMsk_Msk  (0x1u << 1u)
#define USB_GRXSTSR_FrmNum_Pos  21u
#define USB_GRXSTSR_FrmNum_Msk  (0xfu << 21u)
#define USB_GRXSTSR_PktSts_Pos  17u
#define USB_GRXSTSR_PktSts_Msk  (0xfu << 17u)
#define USB_GRXSTSR_DPID_Pos  15u
#define USB_GRXSTSR_DPID_Msk  (0x3u << 15u)
#define USB_GRXSTSR_BCnt_Pos  4u
#define USB_GRXSTSR_BCnt_Msk  (0x7ffu << 4u)
#define USB_GRXSTSR_EPNum_Pos  0u
#define USB_GRXSTSR_EPNum_Msk  (0xfu << 0u)
#define USB_GRXSTSP_FrmNum_Pos  21u
#define USB_GRXSTSP_FrmNum_Msk  (0xfu << 21u)
#define USB_GRXSTSP_PktSts_Pos  17u
#define USB_GRXSTSP_PktSts_Msk  (0xfu << 17u)
#define USB_GRXSTSP_DPID_Pos  15u
#define USB_GRXSTSP_DPID_Msk  (0x3u << 15u)
#define USB_GRXSTSP_BCnt_Pos  4u
#define USB_GRXSTSP_BCnt_Msk  (0x7ffu << 4u)
#define USB_GRXSTSP_EPNum_Pos  0u
#define USB_GRXSTSP_EPNum_Msk  (0xfu << 0u)
#define USB_GRXFSIZ_RxFDep_Pos  0u
#define USB_GRXFSIZ_RxFDep_Msk  (0xffffu << 0u)
#define USB_GNPTXFSIZ_INEPTxF0Dep_Pos  16u
#define USB_GNPTXFSIZ_INEPTxF0Dep_Msk  (0xffffu << 16u)
#define USB_GNPTXFSIZ_INEPTxF0StAddr_Pos  0u
#define USB_GNPTXFSIZ_INEPTxF0StAddr_Msk  (0xffffu << 0u)
#define USB_GGPIO_PADRcvEn_Pos  30u
#define USB_GGPIO_PADRcvEn_Msk  (0x1u << 30u)
#define USB_GGPIO_PADDPPullUp_Pos  28u
#define USB_GGPIO_PADDPPullUp_Msk  (0x3u << 28u)
#define USB_GGPIO_PADDPPullUpLO_Pos  26u
#define USB_GGPIO_PADDPPullUpLO_Msk  (0x3u << 26u)
#define USB_GGPIO_PADDMPullUp_Pos  24u
#define USB_GGPIO_PADDMPullUp_Msk  (0x3u << 24u)
#define USB_GGPIO_PADDMPullUpLO_Pos  22u
#define USB_GGPIO_PADDMPullUpLO_Msk  (0x3u << 22u)
#define USB_GGPIO_PADPullDown_Pos  21u
#define USB_GGPIO_PADPullDown_Msk  (0x1u << 21u)
#define USB_GGPIO_PADSpeed_Pos  19u
#define USB_GGPIO_PADSpeed_Msk  (0x1u << 19u)
#define USB_GGPIO_PADSuspend_Pos  17u
#define USB_GGPIO_PADSuspend_Msk  (0x3u << 17u)
#define USB_GGPIO_PADPowerDown_Pos  16u
#define USB_GGPIO_PADPowerDown_Msk  (0x1u << 16u)
#define USB_GUID_UserID_Pos  0u
#define USB_GUID_UserID_Msk  (0xffffffffu << 0u)
#define USB_GSNPSID_SynopsysID_Pos  0u
#define USB_GSNPSID_SynopsysID_Msk  (0xffffffffu << 0u)
#define USB_GHWCFG1_EP4Dir_Pos  8u
#define USB_GHWCFG1_EP4Dir_Msk  (0x3u << 8u)
#define USB_GHWCFG1_EP3Dir_Pos  6u
#define USB_GHWCFG1_EP3Dir_Msk  (0x3u << 6u)
#define USB_GHWCFG1_EP2Dir_Pos  4u
#define USB_GHWCFG1_EP2Dir_Msk  (0x3u << 4u)
#define USB_GHWCFG1_EP1Dir_Pos  2u
#define USB_GHWCFG1_EP1Dir_Msk  (0x3u << 2u)
#define USB_GHWCFG1_EP0Dir_Pos  0u
#define USB_GHWCFG1_EP0Dir_Msk  (0x3u << 0u)
#define USB_GHWCFG2_DynFifoSizing_Pos  19u
#define USB_GHWCFG2_DynFifoSizing_Msk  (0x1u << 19u)
#define USB_GHWCFG2_NumDevEps_Pos  10u
#define USB_GHWCFG2_NumDevEps_Msk  (0xfu << 10u)
#define USB_GHWCFG2_FSPhyType_Pos  8u
#define USB_GHWCFG2_FSPhyType_Msk  (0x3u << 8u)
#define USB_GHWCFG2_HSPhyType_Pos  6u
#define USB_GHWCFG2_HSPhyType_Msk  (0x3u << 6u)
#define USB_GHWCFG2_SingPnt_Pos  5u
#define USB_GHWCFG2_SingPnt_Msk  (0x1u << 5u)
#define USB_GHWCFG2_OtgArch_Pos  3u
#define USB_GHWCFG2_OtgArch_Msk  (0x3u << 3u)
#define USB_GHWCFG2_OtgMode_Pos  0u
#define USB_GHWCFG2_OtgMode_Msk  (0x7u << 0u)
#define USB_GHWCFG3_DfifoDepth_Pos  16u
#define USB_GHWCFG3_DfifoDepth_Msk  (0xffffu << 16u)
#define USB_GHWCFG3_RstType_Pos  11u
#define USB_GHWCFG3_RstType_Msk  (0x1u << 11u)
#define USB_GHWCFG3_OptFeature_Pos  10u
#define USB_GHWCFG3_OptFeature_Msk  (0x1u << 10u)
#define USB_GHWCFG3_VndctlSupt_Pos  9u
#define USB_GHWCFG3_VndctlSupt_Msk  (0x1u << 9u)
#define USB_GHWCFG3_I2CINtSel_Pos  8u
#define USB_GHWCFG3_I2CINtSel_Msk  (0x1u << 8u)
#define USB_GHWCFG3_OtgEn_Pos  7u
#define USB_GHWCFG3_OtgEn_Msk  (0x1u << 7u)
#define USB_GHWCFG3_PktSizeWidth_Pos  4u
#define USB_GHWCFG3_PktSizeWidth_Msk  (0x7u << 4u)
#define USB_GHWCFG3_XferSizeWidth_Pos  0u
#define USB_GHWCFG3_XferSizeWidth_Msk  (0xfu << 0u)
#define USB_GHWCFG4_SGDMA_Pos  31u
#define USB_GHWCFG4_SGDMA_Msk  (0x1u << 31u)
#define USB_GHWCFG4_SGDMAConfig_Pos  30u
#define USB_GHWCFG4_SGDMAConfig_Msk  (0x1u << 30u)
#define USB_GHWCFG4_INEPs_Pos  26u
#define USB_GHWCFG4_INEPs_Msk  (0xfu << 26u)
#define USB_GHWCFG4_DedFifoMode_Pos  25u
#define USB_GHWCFG4_DedFifoMode_Msk  (0x1u << 25u)
#define USB_GHWCFG4_NumCtlEps_Pos  16u
#define USB_GHWCFG4_NumCtlEps_Msk  (0xfu << 16u)
#define USB_GHWCFG4_PhyDataWidth_Pos  14u
#define USB_GHWCFG4_PhyDataWidth_Msk  (0x3u << 14u)
#define USB_GHWCFG4_AhbFreq_Pos  5u
#define USB_GHWCFG4_AhbFreq_Msk  (0x1u << 5u)
#define USB_GHWCFG4_EnablePwrOpt_Pos  4u
#define USB_GHWCFG4_EnablePwrOpt_Msk  (0x1u << 4u)
#define USB_GUSRSTS_RxRevSpc_Pos  24u
#define USB_GUSRSTS_RxRevSpc_Msk  (0xffu << 24u)
#define USB_GUSRSTS_RxAvailSpc_Pos  16u
#define USB_GUSRSTS_RxAvailSpc_Msk  (0xffu << 16u)
#define USB_GUSRSTS_DFBusy_Pos  14u
#define USB_GUSRSTS_DFBusy_Msk  (0x1u << 14u)
#define USB_GUSRSTS_RxPktNum_Pos  9u
#define USB_GUSRSTS_RxPktNum_Msk  (0x1fu << 9u)
#define USB_GUSRSTS_RxTknPID_Pos  5u
#define USB_GUSRSTS_RxTknPID_Msk  (0xfu << 5u)
#define USB_GUSRSTS_TxRxFSMState_Pos  0u
#define USB_GUSRSTS_TxRxFSMState_Msk  (0x1fu << 0u)
#define USB_DIEPTXF1_INEPnTxFDep_Pos  16u
#define USB_DIEPTXF1_INEPnTxFDep_Msk  (0xffffu << 16u)
#define USB_DIEPTXF1_INEPnTxFStAddr_Pos  0u
#define USB_DIEPTXF1_INEPnTxFStAddr_Msk  (0xffffu << 0u)
#define USB_DIEPTXF3_INEPnTxFDep_Pos  16u
#define USB_DIEPTXF3_INEPnTxFDep_Msk  (0xffffu << 16u)
#define USB_DIEPTXF3_INEPnTxFStAddr_Pos  0u
#define USB_DIEPTXF3_INEPnTxFStAddr_Msk  (0xffffu << 0u)
#define USB_DCFG_PerFrInt_Pos  11u
#define USB_DCFG_PerFrInt_Msk  (0x3u << 11u)
#define USB_DCFG_DevAddr_Pos  4u
#define USB_DCFG_DevAddr_Msk  (0x7fu << 4u)
#define USB_DCFG_NZStsOUTHshk_Pos  2u
#define USB_DCFG_NZStsOUTHshk_Msk  (0x1u << 2u)
#define USB_DCFG_DevSpd_Pos  0u
#define USB_DCFG_DevSpd_Msk  (0x3u << 0u)
#define USB_DCTL_PWROnPrgDone_Pos  11u
#define USB_DCTL_PWROnPrgDone_Msk  (0x1u << 11u)
#define USB_DCTL_CGOUTNak_Pos  10u
#define USB_DCTL_CGOUTNak_Msk  (0x1u << 10u)
#define USB_DCTL_SGOUTNak_Pos  9u
#define USB_DCTL_SGOUTNak_Msk  (0x1u << 9u)
#define USB_DCTL_CGNPInNak_Pos  8u
#define USB_DCTL_CGNPInNak_Msk  (0x1u << 8u)
#define USB_DCTL_SGNPInNak_Pos  7u
#define USB_DCTL_SGNPInNak_Msk  (0x1u << 7u)
#define USB_DCTL_TstCtl_Pos  4u
#define USB_DCTL_TstCtl_Msk  (0x7u << 4u)
#define USB_DCTL_GOUTNakSts_Pos  3u
#define USB_DCTL_GOUTNakSts_Msk  (0x1u << 3u)
#define USB_DCTL_GNPINNakSts_Pos  2u
#define USB_DCTL_GNPINNakSts_Msk  (0x1u << 2u)
#define USB_DCTL_SftDiscon_Pos  1u
#define USB_DCTL_SftDiscon_Msk  (0x1u << 1u)
#define USB_DCTL_RmtWkUpSig_Pos  0u
#define USB_DCTL_RmtWkUpSig_Msk  (0x1u << 0u)
#define USB_DSTS_SOFFrmNum_Pos  8u
#define USB_DSTS_SOFFrmNum_Msk  (0x3fffu << 8u)
#define USB_DSTS_ErrticErr_Pos  3u
#define USB_DSTS_ErrticErr_Msk  (0x1u << 3u)
#define USB_DSTS_EnumSpd_Pos  1u
#define USB_DSTS_EnumSpd_Msk  (0x3u << 1u)
#define USB_DSTS_SuspSts_Pos  0u
#define USB_DSTS_SuspSts_Msk  (0x1u << 0u)
#define USB_DIEPMSK_BNAInIntrMsk_Pos  9u
#define USB_DIEPMSK_BNAInIntrMsk_Msk  (0x1u << 9u)
#define USB_DIEPMSK_TxfifoUndrnMsk_Pos  8u
#define USB_DIEPMSK_TxfifoUndrnMsk_Msk  (0x1u << 8u)
#define USB_DIEPMSK_INEPNakEffMSK_Pos  6u
#define USB_DIEPMSK_INEPNakEffMSK_Msk  (0x1u << 6u)
#define USB_DIEPMSK_INTknEPMisMsk_Pos  5u
#define USB_DIEPMSK_INTknEPMisMsk_Msk  (0x1u << 5u)
#define USB_DIEPMSK_INTknTXFEEmpMsk_Pos  4u
#define USB_DIEPMSK_INTknTXFEEmpMsk_Msk  (0x1u << 4u)
#define USB_DIEPMSK_TimeOUTMsk_Pos  3u
#define USB_DIEPMSK_TimeOUTMsk_Msk  (0x1u << 3u)
#define USB_DIEPMSK_AHBErrMsk_Pos  2u
#define USB_DIEPMSK_AHBErrMsk_Msk  (0x1u << 2u)
#define USB_DIEPMSK_EPDisbldMsk_Pos  1u
#define USB_DIEPMSK_EPDisbldMsk_Msk  (0x1u << 1u)
#define USB_DIEPMSK_XferComplMsk_Pos  0u
#define USB_DIEPMSK_XferComplMsk_Msk  (0x1u << 0u)
#define USB_DOEPMSK_BNAInIntrMsk_Pos  9u
#define USB_DOEPMSK_BNAInIntrMsk_Msk  (0x1u << 9u)
#define USB_DOEPMSK_OutPktErrMsk_Pos  8u
#define USB_DOEPMSK_OutPktErrMsk_Msk  (0x1u << 8u)
#define USB_DOEPMSK_Back2BackSETup_Pos  6u
#define USB_DOEPMSK_Back2BackSETup_Msk  (0x1u << 6u)
#define USB_DOEPMSK_OUTTknEPdisMsk_Pos  4u
#define USB_DOEPMSK_OUTTknEPdisMsk_Msk  (0x1u << 4u)
#define USB_DOEPMSK_SetUPMsk_Pos  3u
#define USB_DOEPMSK_SetUPMsk_Msk  (0x1u << 3u)
#define USB_DOEPMSK_AHBErrMsk_Pos  2u
#define USB_DOEPMSK_AHBErrMsk_Msk  (0x1u << 2u)
#define USB_DOEPMSK_EPDisbldMsk_Pos  1u
#define USB_DOEPMSK_EPDisbldMsk_Msk  (0x1u << 1u)
#define USB_DOEPMSK_XferComplMsk_Pos  0u
#define USB_DOEPMSK_XferComplMsk_Msk  (0x1u << 0u)
#define USB_DAINT_OutEPInt_Pos  16u
#define USB_DAINT_OutEPInt_Msk  (0xffffu << 16u)
#define USB_DAINT_InEpInt_Pos  0u
#define USB_DAINT_InEpInt_Msk  (0xffffu << 0u)
#define USB_DAINTMSK_OutEPIntMSK_Pos  16u
#define USB_DAINTMSK_OutEPIntMSK_Msk  (0xffffu << 16u)
#define USB_DAINTMSK_InEpIntMSK_Pos  0u
#define USB_DAINTMSK_InEpIntMSK_Msk  (0xffffu << 0u)
#define USB_DTHRCTL_ArbPrkEn_Pos  27u
#define USB_DTHRCTL_ArbPrkEn_Msk  (0x1u << 27u)
#define USB_DTHRCTL_RxThrLen_Pos  17u
#define USB_DTHRCTL_RxThrLen_Msk  (0x1ffu << 17u)
#define USB_DTHRCTL_RxThrEn_Pos  16u
#define USB_DTHRCTL_RxThrEn_Msk  (0x1u << 16u)
#define USB_DTHRCTL_TxThrLen_Pos  2u
#define USB_DTHRCTL_TxThrLen_Msk  (0x1ffu << 2u)
#define USB_DTHRCTL_ISOThrEn_Pos  1u
#define USB_DTHRCTL_ISOThrEn_Msk  (0x1u << 1u)
#define USB_DTHRCTL_NonISOThrEn_Pos  0u
#define USB_DTHRCTL_NonISOThrEn_Msk  (0x1u << 0u)
#define USB_DIEPEMPMSK_InEpTxfEmpMsk_Pos  0u
#define USB_DIEPEMPMSK_InEpTxfEmpMsk_Msk  (0xffffu << 0u)
#define USB_DIEPCTL0_EPEna_Pos  31u
#define USB_DIEPCTL0_EPEna_Msk  (0x1u << 31u)
#define USB_DIEPCTL0_EPDis_Pos  30u
#define USB_DIEPCTL0_EPDis_Msk  (0x1u << 30u)
#define USB_DIEPCTL0_SNAK_Pos  27u
#define USB_DIEPCTL0_SNAK_Msk  (0x1u << 27u)
#define USB_DIEPCTL0_CNAK_Pos  26u
#define USB_DIEPCTL0_CNAK_Msk  (0x1u << 26u)
#define USB_DIEPCTL0_TxFNum_Pos  22u
#define USB_DIEPCTL0_TxFNum_Msk  (0xfu << 22u)
#define USB_DIEPCTL0_Stall_Pos  21u
#define USB_DIEPCTL0_Stall_Msk  (0x1u << 21u)
#define USB_DIEPCTL0_EPType_Pos  18u
#define USB_DIEPCTL0_EPType_Msk  (0x3u << 18u)
#define USB_DIEPCTL0_NAKSts_Pos  17u
#define USB_DIEPCTL0_NAKSts_Msk  (0x1u << 17u)
#define USB_DIEPCTL0_USBActEP_Pos  15u
#define USB_DIEPCTL0_USBActEP_Msk  (0x1u << 15u)
#define USB_DIEPCTL0_NextEp_Pos  11u
#define USB_DIEPCTL0_NextEp_Msk  (0xfu << 11u)
#define USB_DIEPCTL0_MPS_Pos  0u
#define USB_DIEPCTL0_MPS_Msk  (0x3u << 0u)
#define USB_DIEPINT0_TxfifoUndrn_Pos  8u
#define USB_DIEPINT0_TxfifoUndrn_Msk  (0x1u << 8u)
#define USB_DIEPINT0_TxFEmp_Pos  7u
#define USB_DIEPINT0_TxFEmp_Msk  (0x1u << 7u)
#define USB_DIEPINT0_INEPNakEff_Pos  6u
#define USB_DIEPINT0_INEPNakEff_Msk  (0x1u << 6u)
#define USB_DIEPINT0_INTknEPMis_Pos  5u
#define USB_DIEPINT0_INTknEPMis_Msk  (0x1u << 5u)
#define USB_DIEPINT0_INTknTXFEmp_Pos  4u
#define USB_DIEPINT0_INTknTXFEmp_Msk  (0x1u << 4u)
#define USB_DIEPINT0_Timeout_Pos  3u
#define USB_DIEPINT0_Timeout_Msk  (0x1u << 3u)
#define USB_DIEPINT0_AHBErr_Pos  2u
#define USB_DIEPINT0_AHBErr_Msk  (0x1u << 2u)
#define USB_DIEPINT0_EPDisbld_Pos  1u
#define USB_DIEPINT0_EPDisbld_Msk  (0x1u << 1u)
#define USB_DIEPINT0_XferCompl_Pos  0u
#define USB_DIEPINT0_XferCompl_Msk  (0x1u << 0u)
#define USB_DIEPTSIZ0_PktCnt_Pos  19u
#define USB_DIEPTSIZ0_PktCnt_Msk  (0x3u << 19u)
#define USB_DIEPTSIZ0_XferSize_Pos  0u
#define USB_DIEPTSIZ0_XferSize_Msk  (0x7fu << 0u)
#define USB_DIEPDMA0_DMAAddr_Pos  0u
#define USB_DIEPDMA0_DMAAddr_Msk  (0xffffffffu << 0u)
#define USB_DTXFSTS0_InEpTxFSpcAvail_Pos  0u
#define USB_DTXFSTS0_InEpTxFSpcAvail_Msk  (0xffffu << 0u)
#define USB_DIEPCTL1_EPEna_Pos  31u
#define USB_DIEPCTL1_EPEna_Msk  (0x1u << 31u)
#define USB_DIEPCTL1_EPDis_Pos  30u
#define USB_DIEPCTL1_EPDis_Msk  (0x1u << 30u)
#define USB_DIEPCTL1_SetD1PID_Pos  29u
#define USB_DIEPCTL1_SetD1PID_Msk  (0x1u << 29u)
#define USB_DIEPCTL1_SetD0PID_Pos  28u
#define USB_DIEPCTL1_SetD0PID_Msk  (0x1u << 28u)
#define USB_DIEPCTL1_SNAK_Pos  27u
#define USB_DIEPCTL1_SNAK_Msk  (0x1u << 27u)
#define USB_DIEPCTL1_CNAK_Pos  26u
#define USB_DIEPCTL1_CNAK_Msk  (0x1u << 26u)
#define USB_DIEPCTL1_TxFNum_Pos  22u
#define USB_DIEPCTL1_TxFNum_Msk  (0xfu << 22u)
#define USB_DIEPCTL1_Stall_Pos  21u
#define USB_DIEPCTL1_Stall_Msk  (0x1u << 21u)
#define USB_DIEPCTL1_EPType_Pos  18u
#define USB_DIEPCTL1_EPType_Msk  (0x3u << 18u)
#define USB_DIEPCTL1_NAKSts_Pos  17u
#define USB_DIEPCTL1_NAKSts_Msk  (0x1u << 17u)
#define USB_DIEPCTL1_DPID_Pos  16u
#define USB_DIEPCTL1_DPID_Msk  (0x1u << 16u)
#define USB_DIEPCTL1_USBActEP_Pos  15u
#define USB_DIEPCTL1_USBActEP_Msk  (0x1u << 15u)
#define USB_DIEPCTL1_MPS_Pos  0u
#define USB_DIEPCTL1_MPS_Msk  (0x7ffu << 0u)
#define USB_DIEPINT1_TxfifoUndrn_Pos  8u
#define USB_DIEPINT1_TxfifoUndrn_Msk  (0x1u << 8u)
#define USB_DIEPINT1_TxFEmp_Pos  7u
#define USB_DIEPINT1_TxFEmp_Msk  (0x1u << 7u)
#define USB_DIEPINT1_INEPNakEff_Pos  6u
#define USB_DIEPINT1_INEPNakEff_Msk  (0x1u << 6u)
#define USB_DIEPINT1_INTknEPMis_Pos  5u
#define USB_DIEPINT1_INTknEPMis_Msk  (0x1u << 5u)
#define USB_DIEPINT1_INTknTXFEmp_Pos  4u
#define USB_DIEPINT1_INTknTXFEmp_Msk  (0x1u << 4u)
#define USB_DIEPINT1_Timeout_Pos  3u
#define USB_DIEPINT1_Timeout_Msk  (0x1u << 3u)
#define USB_DIEPINT1_AHBErr_Pos  2u
#define USB_DIEPINT1_AHBErr_Msk  (0x1u << 2u)
#define USB_DIEPINT1_EPDisbld_Pos  1u
#define USB_DIEPINT1_EPDisbld_Msk  (0x1u << 1u)
#define USB_DIEPINT1_XferCompl_Pos  0u
#define USB_DIEPINT1_XferCompl_Msk  (0x1u << 0u)
#define USB_DIEPTSIZ1_MC_Pos  29u
#define USB_DIEPTSIZ1_MC_Msk  (0x3u << 29u)
#define USB_DIEPTSIZ1_PktCnt_Pos  19u
#define USB_DIEPTSIZ1_PktCnt_Msk  (0x3ffu << 19u)
#define USB_DIEPTSIZ1_XferSize_Pos  0u
#define USB_DIEPTSIZ1_XferSize_Msk  (0x7ffffu << 0u)
#define USB_DIEPDMA1_DMAAddr_Pos  0u
#define USB_DIEPDMA1_DMAAddr_Msk  (0xffffffffu << 0u)
#define USB_DTXFSTS1_InEpTxFSpcAvail_Pos  0u
#define USB_DTXFSTS1_InEpTxFSpcAvail_Msk  (0xffffu << 0u)
#define USB_DIEPCTL3_EPEna_Pos  31u
#define USB_DIEPCTL3_EPEna_Msk  (0x1u << 31u)
#define USB_DIEPCTL3_EPDis_Pos  30u
#define USB_DIEPCTL3_EPDis_Msk  (0x1u << 30u)
#define USB_DIEPCTL3_SetD1PID_Pos  29u
#define USB_DIEPCTL3_SetD1PID_Msk  (0x1u << 29u)
#define USB_DIEPCTL3_SetD0PID_Pos  28u
#define USB_DIEPCTL3_SetD0PID_Msk  (0x1u << 28u)
#define USB_DIEPCTL3_SNAK_Pos  27u
#define USB_DIEPCTL3_SNAK_Msk  (0x1u << 27u)
#define USB_DIEPCTL3_CNAK_Pos  26u
#define USB_DIEPCTL3_CNAK_Msk  (0x1u << 26u)
#define USB_DIEPCTL3_TxFNum_Pos  22u
#define USB_DIEPCTL3_TxFNum_Msk  (0xfu << 22u)
#define USB_DIEPCTL3_Stall_Pos  21u
#define USB_DIEPCTL3_Stall_Msk  (0x1u << 21u)
#define USB_DIEPCTL3_EPType_Pos  18u
#define USB_DIEPCTL3_EPType_Msk  (0x3u << 18u)
#define USB_DIEPCTL3_NAKSts_Pos  17u
#define USB_DIEPCTL3_NAKSts_Msk  (0x1u << 17u)
#define USB_DIEPCTL3_DPID_Pos  16u
#define USB_DIEPCTL3_DPID_Msk  (0x1u << 16u)
#define USB_DIEPCTL3_USBActEP_Pos  15u
#define USB_DIEPCTL3_USBActEP_Msk  (0x1u << 15u)
#define USB_DIEPCTL3_MPS_Pos  0u
#define USB_DIEPCTL3_MPS_Msk  (0x7ffu << 0u)
#define USB_DIEPINT3_TxfifoUndrn_Pos  8u
#define USB_DIEPINT3_TxfifoUndrn_Msk  (0x1u << 8u)
#define USB_DIEPINT3_TxFEmp_Pos  7u
#define USB_DIEPINT3_TxFEmp_Msk  (0x1u << 7u)
#define USB_DIEPINT3_INEPNakEff_Pos  6u
#define USB_DIEPINT3_INEPNakEff_Msk  (0x1u << 6u)
#define USB_DIEPINT3_INTknEPMis_Pos  5u
#define USB_DIEPINT3_INTknEPMis_Msk  (0x1u << 5u)
#define USB_DIEPINT3_INTknTXFEmp_Pos  4u
#define USB_DIEPINT3_INTknTXFEmp_Msk  (0x1u << 4u)
#define USB_DIEPINT3_Timeout_Pos  3u
#define USB_DIEPINT3_Timeout_Msk  (0x1u << 3u)
#define USB_DIEPINT3_AHBErr_Pos  2u
#define USB_DIEPINT3_AHBErr_Msk  (0x1u << 2u)
#define USB_DIEPINT3_EPDisbld_Pos  1u
#define USB_DIEPINT3_EPDisbld_Msk  (0x1u << 1u)
#define USB_DIEPINT3_XferCompl_Pos  0u
#define USB_DIEPINT3_XferCompl_Msk  (0x1u << 0u)
#define USB_DIEPTSIZ3_MC_Pos  29u
#define USB_DIEPTSIZ3_MC_Msk  (0x3u << 29u)
#define USB_DIEPTSIZ3_PktCnt_Pos  19u
#define USB_DIEPTSIZ3_PktCnt_Msk  (0x3ffu << 19u)
#define USB_DIEPTSIZ3_XferSize_Pos  0u
#define USB_DIEPTSIZ3_XferSize_Msk  (0x7ffffu << 0u)
#define USB_DIEPDMA3_DMAAddr_Pos  0u
#define USB_DIEPDMA3_DMAAddr_Msk  (0xffffffffu << 0u)
#define USB_DTXFSTS3_InEpTxFSpcAvail_Pos  0u
#define USB_DTXFSTS3_InEpTxFSpcAvail_Msk  (0xffffu << 0u)
#define USB_DOEPCTL0_EPEna_Pos  31u
#define USB_DOEPCTL0_EPEna_Msk  (0x1u << 31u)
#define USB_DOEPCTL0_EPDis_Pos  30u
#define USB_DOEPCTL0_EPDis_Msk  (0x1u << 30u)
#define USB_DOEPCTL0_SNAK_Pos  27u
#define USB_DOEPCTL0_SNAK_Msk  (0x1u << 27u)
#define USB_DOEPCTL0_CNAK_Pos  26u
#define USB_DOEPCTL0_CNAK_Msk  (0x1u << 26u)
#define USB_DOEPCTL0_Stall_Pos  21u
#define USB_DOEPCTL0_Stall_Msk  (0x1u << 21u)
#define USB_DOEPCTL0_Snp_Pos  20u
#define USB_DOEPCTL0_Snp_Msk  (0x1u << 20u)
#define USB_DOEPCTL0_EPType_Pos  18u
#define USB_DOEPCTL0_EPType_Msk  (0x3u << 18u)
#define USB_DOEPCTL0_NAKSts_Pos  17u
#define USB_DOEPCTL0_NAKSts_Msk  (0x1u << 17u)
#define USB_DOEPCTL0_USBActEP_Pos  15u
#define USB_DOEPCTL0_USBActEP_Msk  (0x1u << 15u)
#define USB_DOEPCTL0_MPS_Pos  0u
#define USB_DOEPCTL0_MPS_Msk  (0x3u << 0u)
#define USB_DOEPINT0_OutPktErr_Pos  8u
#define USB_DOEPINT0_OutPktErr_Msk  (0x1u << 8u)
#define USB_DOEPINT0_Back2BackSETup_Pos  6u
#define USB_DOEPINT0_Back2BackSETup_Msk  (0x1u << 6u)
#define USB_DOEPINT0_OUTTknEPdis_Pos  4u
#define USB_DOEPINT0_OUTTknEPdis_Msk  (0x1u << 4u)
#define USB_DOEPINT0_SetUp_Pos  3u
#define USB_DOEPINT0_SetUp_Msk  (0x1u << 3u)
#define USB_DOEPINT0_AHBErr_Pos  2u
#define USB_DOEPINT0_AHBErr_Msk  (0x1u << 2u)
#define USB_DOEPINT0_EPDisbld_Pos  1u
#define USB_DOEPINT0_EPDisbld_Msk  (0x1u << 1u)
#define USB_DOEPINT0_XferCompl_Pos  0u
#define USB_DOEPINT0_XferCompl_Msk  (0x1u << 0u)
#define USB_DOEPTSIZ0_SUPCnt_Pos  29u
#define USB_DOEPTSIZ0_SUPCnt_Msk  (0x3u << 29u)
#define USB_DOEPTSIZ0_PktCnt_Pos  19u
#define USB_DOEPTSIZ0_PktCnt_Msk  (0x1u << 19u)
#define USB_DOEPTSIZ0_XferSize_Pos  0u
#define USB_DOEPTSIZ0_XferSize_Msk  (0x7fu << 0u)
#define USB_DOEPDMA0_DMAAddr_Pos  0u
#define USB_DOEPDMA0_DMAAddr_Msk  (0xffffffffu << 0u)
#define USB_DOEPCTL2_EPEna_Pos  31u
#define USB_DOEPCTL2_EPEna_Msk  (0x1u << 31u)
#define USB_DOEPCTL2_EPDis_Pos  30u
#define USB_DOEPCTL2_EPDis_Msk  (0x1u << 30u)
#define USB_DOEPCTL2_SetD1PID_Pos  29u
#define USB_DOEPCTL2_SetD1PID_Msk  (0x1u << 29u)
#define USB_DOEPCTL2_SetD0PID_Pos  28u
#define USB_DOEPCTL2_SetD0PID_Msk  (0x1u << 28u)
#define USB_DOEPCTL2_SNAK_Pos  27u
#define USB_DOEPCTL2_SNAK_Msk  (0x1u << 27u)
#define USB_DOEPCTL2_CNAK_Pos  26u
#define USB_DOEPCTL2_CNAK_Msk  (0x1u << 26u)
#define USB_DOEPCTL2_Stall_Pos  21u
#define USB_DOEPCTL2_Stall_Msk  (0x1u << 21u)
#define USB_DOEPCTL2_Snp_Pos  20u
#define USB_DOEPCTL2_Snp_Msk  (0x1u << 20u)
#define USB_DOEPCTL2_EPType_Pos  18u
#define USB_DOEPCTL2_EPType_Msk  (0x3u << 18u)
#define USB_DOEPCTL2_NAKSts_Pos  17u
#define USB_DOEPCTL2_NAKSts_Msk  (0x1u << 17u)
#define USB_DOEPCTL2_DPID_Pos  16u
#define USB_DOEPCTL2_DPID_Msk  (0x1u << 16u)
#define USB_DOEPCTL2_USBActEP_Pos  15u
#define USB_DOEPCTL2_USBActEP_Msk  (0x1u << 15u)
#define USB_DOEPCTL2_MPS_Pos  0u
#define USB_DOEPCTL2_MPS_Msk  (0x7ffu << 0u)
#define USB_DOEPINT2_OutPktErr_Pos  8u
#define USB_DOEPINT2_OutPktErr_Msk  (0x1u << 8u)
#define USB_DOEPINT2_Back2BackSETup_Pos  6u
#define USB_DOEPINT2_Back2BackSETup_Msk  (0x1u << 6u)
#define USB_DOEPINT2_OUTTknEPdis_Pos  4u
#define USB_DOEPINT2_OUTTknEPdis_Msk  (0x1u << 4u)
#define USB_DOEPINT2_SetUp_Pos  3u
#define USB_DOEPINT2_SetUp_Msk  (0x1u << 3u)
#define USB_DOEPINT2_AHBErr_Pos  2u
#define USB_DOEPINT2_AHBErr_Msk  (0x1u << 2u)
#define USB_DOEPINT2_EPDisbld_Pos  1u
#define USB_DOEPINT2_EPDisbld_Msk  (0x1u << 1u)
#define USB_DOEPINT2_XferCompl_Pos  0u
#define USB_DOEPINT2_XferCompl_Msk  (0x1u << 0u)
#define USB_DOEPTSIZ2_RxDPID_Pos  29u
#define USB_DOEPTSIZ2_RxDPID_Msk  (0x3u << 29u)
#define USB_DOEPTSIZ2_PktCnt_Pos  19u
#define USB_DOEPTSIZ2_PktCnt_Msk  (0x3ffu << 19u)
#define USB_DOEPTSIZ2_XferSize_Pos  0u
#define USB_DOEPTSIZ2_XferSize_Msk  (0x7ffffu << 0u)
#define USB_DOEPDMA2_DMAAddr_Pos  0u
#define USB_DOEPDMA2_DMAAddr_Msk  (0xffffffffu << 0u)
#define USB_DOEPCTL4_EPEna_Pos  31u
#define USB_DOEPCTL4_EPEna_Msk  (0x1u << 31u)
#define USB_DOEPCTL4_EPDis_Pos  30u
#define USB_DOEPCTL4_EPDis_Msk  (0x1u << 30u)
#define USB_DOEPCTL4_SetD1PID_Pos  29u
#define USB_DOEPCTL4_SetD1PID_Msk  (0x1u << 29u)
#define USB_DOEPCTL4_SetD0PID_Pos  28u
#define USB_DOEPCTL4_SetD0PID_Msk  (0x1u << 28u)
#define USB_DOEPCTL4_SNAK_Pos  27u
#define USB_DOEPCTL4_SNAK_Msk  (0x1u << 27u)
#define USB_DOEPCTL4_CNAK_Pos  26u
#define USB_DOEPCTL4_CNAK_Msk  (0x1u << 26u)
#define USB_DOEPCTL4_Stall_Pos  21u
#define USB_DOEPCTL4_Stall_Msk  (0x1u << 21u)
#define USB_DOEPCTL4_Snp_Pos  20u
#define USB_DOEPCTL4_Snp_Msk  (0x1u << 20u)
#define USB_DOEPCTL4_EPType_Pos  18u
#define USB_DOEPCTL4_EPType_Msk  (0x3u << 18u)
#define USB_DOEPCTL4_NAKSts_Pos  17u
#define USB_DOEPCTL4_NAKSts_Msk  (0x1u << 17u)
#define USB_DOEPCTL4_DPID_Pos  16u
#define USB_DOEPCTL4_DPID_Msk  (0x1u << 16u)
#define USB_DOEPCTL4_USBActEP_Pos  15u
#define USB_DOEPCTL4_USBActEP_Msk  (0x1u << 15u)
#define USB_DOEPCTL4_MPS_Pos  0u
#define USB_DOEPCTL4_MPS_Msk  (0x7ffu << 0u)
#define USB_DOEPINT4_OutPktErr_Pos  8u
#define USB_DOEPINT4_OutPktErr_Msk  (0x1u << 8u)
#define USB_DOEPINT4_Back2BackSETup_Pos  6u
#define USB_DOEPINT4_Back2BackSETup_Msk  (0x1u << 6u)
#define USB_DOEPINT4_OUTTknEPdis_Pos  4u
#define USB_DOEPINT4_OUTTknEPdis_Msk  (0x1u << 4u)
#define USB_DOEPINT4_SetUp_Pos  3u
#define USB_DOEPINT4_SetUp_Msk  (0x1u << 3u)
#define USB_DOEPINT4_AHBErr_Pos  2u
#define USB_DOEPINT4_AHBErr_Msk  (0x1u << 2u)
#define USB_DOEPINT4_EPDisbld_Pos  1u
#define USB_DOEPINT4_EPDisbld_Msk  (0x1u << 1u)
#define USB_DOEPINT4_XferCompl_Pos  0u
#define USB_DOEPINT4_XferCompl_Msk  (0x1u << 0u)
#define USB_DOEPTSIZ4_RxDPID_Pos  29u
#define USB_DOEPTSIZ4_RxDPID_Msk  (0x3u << 29u)
#define USB_DOEPTSIZ4_PktCnt_Pos  19u
#define USB_DOEPTSIZ4_PktCnt_Msk  (0x3ffu << 19u)
#define USB_DOEPTSIZ4_XferSize_Pos  0u
#define USB_DOEPTSIZ4_XferSize_Msk  (0x7ffffu << 0u)
#define USB_DOEPDMA4_DMAAddr_Pos  0u
#define USB_DOEPDMA4_DMAAddr_Msk  (0xffffffffu << 0u)
#define USB_PCGCCTL_RstPdwnModule_Pos  3u
#define USB_PCGCCTL_RstPdwnModule_Msk  (0x1u << 3u)
#define USB_PCGCCTL_GateHclk_Pos  1u
#define USB_PCGCCTL_GateHclk_Msk  (0x1u << 1u)
#define USB_PCGCCTL_StopPclk_Pos  0u
#define USB_PCGCCTL_StopPclk_Msk  (0x1u << 0u)

typedef struct {   /* Watchdog (DS §4.10, p.212-218). Write 0x5ada7200 to WDG_LOCK to unlock; feed by writing 0x55aadd22 to WDG_KNOC */
  __IO uint32_t WDG_LOCK;                    /* 0x00 Watchdog Lock Register. DS §4.10.5.1 p.216. Reset 0x1 (DS). */
  __IO uint32_t WDG_OT_LOAD_H;               /* 0x04 DS §4.10.5.2 p.216. Reset 0x7 (DS). */
  __I  uint32_t WDG_OT_LOAD_L;               /* 0x08 DS §4.10.5.3 p.216. The datasheet marks WDG_OT_LOAD_L read-only while its high half (WDG_OT_LOAD_H) is read-wr */
  __IO uint32_t WDG_RST_LOAD;                /* 0x0c Watchdog reset time initial value. DS §4.10.5.4 p.218. */
  __IO uint32_t WDG_EN;                      /* 0x10 Watchdog enable. DS §4.10.5.5 p.218. Reset 0x0 (DS). */
  __IO uint32_t WDG_KNOCK;                   /* 0x14 Watchdog feeding register. DS §4.10.5.6 p.218. Reset 0x0 (DS). */
} WDG_Type;   /* 0x18 bytes */
#define WDG_WDG_LOCK_WDG_LOCK_Pos  0u
#define WDG_WDG_LOCK_WDG_LOCK_Msk  (0xffffffffu << 0u)
#define WDG_WDG_OT_LOAD_H_WDG_OT_LOAD_H_Pos  0u
#define WDG_WDG_OT_LOAD_H_WDG_OT_LOAD_H_Msk  (0x7u << 0u)
#define WDG_WDG_OT_LOAD_L_WDG_OT_LOAD_L_Pos  0u
#define WDG_WDG_OT_LOAD_L_WDG_OT_LOAD_L_Msk  (0xffffffffu << 0u)
#define WDG_WDG_RST_LOAD_WDG_RST_LOAD_Pos  0u
#define WDG_WDG_RST_LOAD_WDG_RST_LOAD_Msk  (0x1ffffffu << 0u)
#define WDG_WDG_EN_WDG_EN_Pos  0u
#define WDG_WDG_EN_WDG_EN_Msk  (0x1u << 0u)
#define WDG_WDG_KNOCK_WDG_KNOCK_Pos  0u
#define WDG_WDG_KNOCK_WDG_KNOCK_Msk  (0xffffffffu << 0u)

typedef struct {   /* GPIO bank A, Synopsys DesignWare APB GPIO (DS §5.7, p.377-385). Every register is one bit per pin. Pin functio */
  __IO uint32_t SWPORTA_DR;                  /* 0x00 Port A output data. DS §5.7.5.1 p.381. FW: 16 reads, 11 writes. Reset 0x0 (DS). */
  __IO uint32_t SWPORTA_DDR;                 /* 0x04 Control port A data direction. DS §5.7.5.2 p.381. FW: 22 reads, 19 writes. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_8[10];              /* 0x8-0x2f */
  __IO uint32_t INTEN;                       /* 0x30 Interrupt enable. DS §5.7.5.3 p.383. FW: 10 reads, 10 writes. Reset 0x0 (DS). */
  __IO uint32_t INTMASK;                     /* 0x34 Controls whether to mask interrupts. DS §5.7.5.4 p.383. FW: 3 reads, 3 writes. Reset 0x0 (DS). */
  __IO uint32_t INTTYPE_LEVEL;               /* 0x38 Controls the interrupt type of port A. DS §5.7.5.5 p.383. FW: 9 reads, 9 writes. Reset 0x0 (DS). */
  __IO uint32_t INT_POLARITY;                /* 0x3c Controls the polarity of the interrupt on port A. DS §5.7.5.6 p.383. FW: 11 reads, 11 writes. Reset 0x0 (DS). */
  __I  uint32_t INTSTATUS;                   /* 0x40 Port A interrupt status. DS §5.7.5.7 p.383. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
  __I  uint32_t RAW_INTSTATUS;               /* 0x44 port A before masking. DS §5.7.5.8 p.383. Reset 0x0 (DS). */
  __IO uint32_t DEBOUNCE;                    /* 0x48 Debounce Enable Register. DS §5.7.5.9 p.385. FW: 0 reads, 2 writes. Printed RO; the stock firmware writes it ( */
  __O  uint32_t PORTA_EOI;                   /* 0x4c PORTA interrupt clear register. 0 : Do not clear interrupt; 1 : Clearing Break. DS §5.7.5.10 p.385. FW: 0 read */
  __I  uint32_t EXT_PORTA;                   /* 0x50 When port A is configured as input, read this register to read the input data. DS §5.7.5.11 p.385. FW: 7 reads */
  __I  uint32_t RESERVED_54[9];              /* 0x54-0x77 */
  __IO uint32_t INTR_BOTH_EDGE;              /* 0x78 1 : Dual-edge triggered interrupt 0 : Non-double-edge triggered interrupt. DS §5.7.5.12 p.385. FW: 6 reads, 6  */
} GPIO_Type;   /* 0x7c bytes */

typedef struct {   /* UART0, Synopsys DesignWare APB UART, 16550-compatible (DS §5.4, p.268-285). Offsets 0x00/0x04/0x08 are shared: */
  __IO uint32_t RBR_THR_DLL;                 /* 0x00 Receive buffer register. DS §5.4.5.1 p.274. FW: 2 reads, 7 writes. Reset 0x0 (DS). */
  __IO uint32_t IER_DLH;                     /* 0x04 Interrupt enable register. DS §5.4.5.5 p.275. FW: 0 reads, 2 writes. Reset 0x0 (DS). */
  __IO uint32_t IIR_FCR;                     /* 0x08 Interrupt Flag Register. DS §5.4.5.6 p.277. FW: 0 reads, 2 writes. Reset 0x1 (DS). */
  __IO uint32_t LCR;                         /* 0x0c Line Control Register. DS §5.4.5.8 p.279. FW: 4 reads, 2 writes. Bit 5 (stick parity) is reserved and reads as */
  __IO uint32_t MCR;                         /* 0x10 Modem Control registers. DS §5.4.5.9 p.281. Reset 0x0 (DS). */
  __I  uint32_t LSR;                         /* 0x14 Line Status Register. DS §5.4.5.10 p.281. FW: 5 reads, 0 writes. Reset 0x60 (DS). */
  __I  uint32_t RESERVED_18[25];             /* 0x18-0x7b */
  __I  uint32_t USR;                         /* 0x7c FIFO Status Flags. DS §5.4.5.11 p.283. FW: 4 reads, 0 writes. Reset 0x0 (DS). */
  __I  uint32_t TFL;                         /* 0x80 The amount of data in the transmit FIFO. DS §5.4.5.12 p.285. Reset 0x0 (DS). */
  __I  uint32_t RFL;                         /* 0x84 DS §5.4.5.13 p.285. Reset 0x0 (DS). */
} UART_Type;   /* 0x88 bytes */
#define UART_RBR_RBR_Pos  0u
#define UART_RBR_RBR_Msk  (0xffu << 0u)
#define UART_THR_THR_Pos  0u
#define UART_THR_THR_Msk  (0xffu << 0u)
#define UART_DLL_DLL_Pos  0u
#define UART_DLL_DLL_Msk  (0xffu << 0u)
#define UART_IER_PTIME_Pos  7u
#define UART_IER_PTIME_Msk  (0x1u << 7u)
#define UART_IER_EDSSI_Pos  3u
#define UART_IER_EDSSI_Msk  (0x1u << 3u)
#define UART_IER_ELSI_Pos  2u
#define UART_IER_ELSI_Msk  (0x1u << 2u)
#define UART_IER_ETBEI_Pos  1u
#define UART_IER_ETBEI_Msk  (0x1u << 1u)
#define UART_IER_ERBFI_Pos  0u
#define UART_IER_ERBFI_Msk  (0x1u << 0u)
#define UART_DLH_DLH_Pos  0u
#define UART_DLH_DLH_Msk  (0xffu << 0u)
#define UART_IIR_FIFOSE_Pos  6u
#define UART_IIR_FIFOSE_Msk  (0x3u << 6u)
#define UART_IIR_IID_Pos  0u
#define UART_IIR_IID_Msk  (0xfu << 0u)
#define UART_FCR_RT_Pos  6u
#define UART_FCR_RT_Msk  (0x3u << 6u)
#define UART_FCR_TET_Pos  4u
#define UART_FCR_TET_Msk  (0x3u << 4u)
#define UART_FCR_DMAM_Pos  3u
#define UART_FCR_DMAM_Msk  (0x1u << 3u)
#define UART_FCR_XFIFOR_Pos  2u
#define UART_FCR_XFIFOR_Msk  (0x1u << 2u)
#define UART_FCR_RFIFOR_Pos  1u
#define UART_FCR_RFIFOR_Msk  (0x1u << 1u)
#define UART_FCR_FIFOE_Pos  0u
#define UART_FCR_FIFOE_Msk  (0x1u << 0u)
#define UART_LCR_DLAB_Pos  7u
#define UART_LCR_DLAB_Msk  (0x1u << 7u)
#define UART_LCR_BC_Pos  6u
#define UART_LCR_BC_Msk  (0x1u << 6u)
#define UART_LCR_EPS_Pos  4u
#define UART_LCR_EPS_Msk  (0x1u << 4u)
#define UART_LCR_PEN_Pos  3u
#define UART_LCR_PEN_Msk  (0x1u << 3u)
#define UART_LCR_STOP_Pos  2u
#define UART_LCR_STOP_Msk  (0x1u << 2u)
#define UART_LCR_DLS_Pos  0u
#define UART_LCR_DLS_Msk  (0x3u << 0u)
#define UART_MCR_SIRE_Pos  6u
#define UART_MCR_SIRE_Msk  (0x1u << 6u)
#define UART_MCR_AFCE_Pos  5u
#define UART_MCR_AFCE_Msk  (0x1u << 5u)
#define UART_MCR_LoopBack_Pos  4u
#define UART_MCR_LoopBack_Msk  (0x1u << 4u)
#define UART_MCR_OUT2_Pos  3u
#define UART_MCR_OUT2_Msk  (0x1u << 3u)
#define UART_MCR_OUT1_Pos  2u
#define UART_MCR_OUT1_Msk  (0x1u << 2u)
#define UART_MCR_RTS_Pos  1u
#define UART_MCR_RTS_Msk  (0x1u << 1u)
#define UART_MCR_DTR_Pos  0u
#define UART_MCR_DTR_Msk  (0x1u << 0u)
#define UART_LSR_RFE_Pos  7u
#define UART_LSR_RFE_Msk  (0x1u << 7u)
#define UART_LSR_TEMT_Pos  6u
#define UART_LSR_TEMT_Msk  (0x1u << 6u)
#define UART_LSR_THRE_Pos  5u
#define UART_LSR_THRE_Msk  (0x1u << 5u)
#define UART_LSR_BI_Pos  4u
#define UART_LSR_BI_Msk  (0x1u << 4u)
#define UART_LSR_FE_Pos  3u
#define UART_LSR_FE_Msk  (0x1u << 3u)
#define UART_LSR_PE_Pos  2u
#define UART_LSR_PE_Msk  (0x1u << 2u)
#define UART_LSR_OE_Pos  1u
#define UART_LSR_OE_Msk  (0x1u << 1u)
#define UART_LSR_DR_Pos  0u
#define UART_LSR_DR_Msk  (0x1u << 0u)
#define UART_USR_RFF_Pos  4u
#define UART_USR_RFF_Msk  (0x1u << 4u)
#define UART_USR_RFNE_Pos  3u
#define UART_USR_RFNE_Msk  (0x1u << 3u)
#define UART_USR_TFE_Pos  2u
#define UART_USR_TFE_Msk  (0x1u << 2u)
#define UART_USR_TFNF_Pos  1u
#define UART_USR_TFNF_Msk  (0x1u << 1u)
#define UART_USR_BUSY_Pos  0u
#define UART_USR_BUSY_Msk  (0x1u << 0u)
#define UART_TFL_TFL_Pos  0u
#define UART_TFL_TFL_Msk  (0x1fu << 0u)
#define UART_RFL_RFL_Pos  0u
#define UART_RFL_RFL_Msk  (0x1fu << 0u)

typedef struct {   /* I2C0, Synopsys DesignWare APB I2C master/slave (DS §5.1, p.218-243). FW: no direct access or base literal foun */
  __IO uint32_t IC_CON;                      /* 0x00 I2C Control registers. DS §5.1.6.1 p.226. Reset 0x7d (DS). */
  __IO uint32_t IC_TAR;                      /* 0x04 I2C Destination Address Register. DS §5.1.6.2 p.228. Reset 0x55 (DS). */
  __I  uint32_t RESERVED_8[2];               /* 0x8-0xf */
  __IO uint32_t IC_DATA_CMD;                 /* 0x10 I2C Send and receive data buffers and. DS §5.1.6.3 p.228. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_14[2];              /* 0x14-0x1b */
  __IO uint32_t IC_FS_SCL_HCNT;              /* 0x1c Fast SCL High level count. DS §5.1.6.4 p.228. Reset 0x5a (DS). */
  __IO uint32_t IC_FS_SCL_LCNT;              /* 0x20 Fast SCL Low level count. DS §5.1.6.5 p.228. Reset 0xa0 (DS). */
  __I  uint32_t RESERVED_24[2];              /* 0x24-0x2b */
  __I  uint32_t IC_INTR_STAT;                /* 0x2c Interrupt Status. DS §5.1.6.6 p.230. Reset 0x0 (DS). */
  __IO uint32_t IC_INTR_MASK;                /* 0x30 Interrupt mask. DS §5.1.6.7 p.230. Reset 0x8ff (DS). */
  __I  uint32_t IC_RAW_INTR_STAT;            /* 0x34 Raw interrupt status. DS §5.1.6.8 p.230. Reset 0x0 (DS). */
  __IO uint32_t IC_RX_TL;                    /* 0x38 Receive FIFO threshold. DS §5.1.6.9 p.232. Reset 0x6 (DS). */
  __IO uint32_t IC_TX_TL;                    /* 0x3c Transmit FIFO threshold. DS §5.1.6.10 p.233. Reset 0x6 (DS). */
  __I  uint32_t IC_CLR_INTR;                 /* 0x40 Clear Interrupt. DS §5.1.6.11 p.233. Reset 0x0 (DS). */
  __I  uint32_t IC_CLR_RX_UNDER;             /* 0x44 Clear interrupt RX_UNDER. DS §5.1.6.12 p.234. Reset 0x0 (DS). */
  __I  uint32_t IC_CLR_RX_OVER;              /* 0x48 Clear interrupt RX_OVER. DS §5.1.6.13 p.234. Reset 0x0 (DS). */
  __I  uint32_t IC_CLR_TX_OVER;              /* 0x4c Clear interrupt TX_OVER. DS §5.1.6.14 p.234. Reset 0x0 (DS). */
  __I  uint32_t IC_CLR_RD_REQ;               /* 0x50 Clear interrupt RD_REQ. DS §5.1.6.15 p.234. Reset 0x0 (DS). */
  __I  uint32_t IC_CLR_TX_ABRT;              /* 0x54 Clear interrupt TX_ABRT. DS §5.1.6.16 p.234. Reset 0x0 (DS). */
  __I  uint32_t IC_CLR_RX_DONE;              /* 0x58 Clear interrupt RX_DONE. DS §5.1.6.17 p.236. Reset 0x0 (DS). */
  __I  uint32_t IC_CLR_ACTIVITY;             /* 0x5c Clear interrupt activity. DS §5.1.6.18 p.236. Reset 0x0 (DS). */
  __I  uint32_t IC_CLR_STOP_DET;             /* 0x60 Clear interrupt STOP_DET. DS §5.1.6.19 p.236. Reset 0x0 (DS). */
  __I  uint32_t IC_CLR_START_DET;            /* 0x64 Clear interrupt START_DET. DS §5.1.6.20 p.236. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_68[1];              /* 0x68-0x6b */
  __IO uint32_t IC_ENABLE;                   /* 0x6c I2C Enable register. DS §5.1.6.21 p.236. Reset 0x0 (DS). */
  __I  uint32_t IC_STATUS;                   /* 0x70 I2C Status Register. DS §5.1.6.22 p.238. Reset 0x6 (DS). */
  __I  uint32_t IC_TXFLR;                    /* 0x74 Transmit FIFO water level register. DS §5.1.6.23 p.238. Reset 0x0 (DS). */
  __I  uint32_t IC_RXFLR;                    /* 0x78 Receive FIFO water level register. DS §5.1.6.24 p.238. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_7C[1];              /* 0x7c-0x7f */
  __I  uint32_t IC_TX_ABRT_SOURCE;           /* 0x80 I2C Transfer end status register. DS §5.1.6.25 p.240. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_84[6];              /* 0x84-0x9b */
  __I  uint32_t IC_ENABLE_STATUS;            /* 0x9c I2C Enable Status Register. DS §5.1.6.26 p.242. Reset 0x0 (DS). */
  __IO uint32_t IC_START;                    /* 0xa0 Control data starts sending. DS §5.1.6.27 p.242. Reset 0x0 (DS). */
} I2C_Type;   /* 0xa4 bytes */
#define I2C_IC_CON_IC_SLAVE_DISABLE_Pos  6u
#define I2C_IC_CON_IC_SLAVE_DISABLE_Msk  (0x1u << 6u)
#define I2C_IC_CON_IC_RESTART_EN_Pos  5u
#define I2C_IC_CON_IC_RESTART_EN_Msk  (0x1u << 5u)
#define I2C_IC_CON_IC_10BITADDR_MASTER_Pos  4u
#define I2C_IC_CON_IC_10BITADDR_MASTER_Msk  (0x1u << 4u)
#define I2C_IC_CON_IC_10BITADDR_SLAVE_Pos  3u
#define I2C_IC_CON_IC_10BITADDR_SLAVE_Msk  (0x1u << 3u)
#define I2C_IC_CON_SPEED_Pos  1u
#define I2C_IC_CON_SPEED_Msk  (0x3u << 1u)
#define I2C_IC_CON_MASTER_MODE_Pos  0u
#define I2C_IC_CON_MASTER_MODE_Msk  (0x1u << 0u)
#define I2C_IC_TAR_SPECIAL_Pos  11u
#define I2C_IC_TAR_SPECIAL_Msk  (0x1u << 11u)
#define I2C_IC_TAR_GC_OR_START_Pos  10u
#define I2C_IC_TAR_GC_OR_START_Msk  (0x1u << 10u)
#define I2C_IC_TAR_IC_TAR_Pos  0u
#define I2C_IC_TAR_IC_TAR_Msk  (0x3ffu << 0u)
#define I2C_IC_DATA_CMD_CMD_Pos  8u
#define I2C_IC_DATA_CMD_CMD_Msk  (0x1u << 8u)
#define I2C_IC_DATA_CMD_DAT_Pos  0u
#define I2C_IC_DATA_CMD_DAT_Msk  (0xffu << 0u)
#define I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Pos  0u
#define I2C_IC_FS_SCL_HCNT_IC_FS_SCL_HCNT_Msk  (0xffffu << 0u)
#define I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Pos  0u
#define I2C_IC_FS_SCL_LCNT_IC_FS_SCL_LCNT_Msk  (0xffffu << 0u)
#define I2C_IC_INTR_STAT_R_GEN_CALL_Pos  11u
#define I2C_IC_INTR_STAT_R_GEN_CALL_Msk  (0x1u << 11u)
#define I2C_IC_INTR_STAT_R_START_DET_Pos  10u
#define I2C_IC_INTR_STAT_R_START_DET_Msk  (0x1u << 10u)
#define I2C_IC_INTR_STAT_R_STOP_DET_Pos  9u
#define I2C_IC_INTR_STAT_R_STOP_DET_Msk  (0x1u << 9u)
#define I2C_IC_INTR_STAT_R_ACTIVITY_Pos  8u
#define I2C_IC_INTR_STAT_R_ACTIVITY_Msk  (0x1u << 8u)
#define I2C_IC_INTR_STAT_R_RX_DONE_Pos  7u
#define I2C_IC_INTR_STAT_R_RX_DONE_Msk  (0x1u << 7u)
#define I2C_IC_INTR_STAT_R_TX_ABRT_Pos  6u
#define I2C_IC_INTR_STAT_R_TX_ABRT_Msk  (0x1u << 6u)
#define I2C_IC_INTR_STAT_R_RD_REQ_Pos  5u
#define I2C_IC_INTR_STAT_R_RD_REQ_Msk  (0x1u << 5u)
#define I2C_IC_INTR_STAT_R_TX_EMPTY_Pos  4u
#define I2C_IC_INTR_STAT_R_TX_EMPTY_Msk  (0x1u << 4u)
#define I2C_IC_INTR_STAT_R_TX_OVER_Pos  3u
#define I2C_IC_INTR_STAT_R_TX_OVER_Msk  (0x1u << 3u)
#define I2C_IC_INTR_STAT_R_RX_FULL_Pos  2u
#define I2C_IC_INTR_STAT_R_RX_FULL_Msk  (0x1u << 2u)
#define I2C_IC_INTR_STAT_R_RX_OVER_Pos  1u
#define I2C_IC_INTR_STAT_R_RX_OVER_Msk  (0x1u << 1u)
#define I2C_IC_INTR_STAT_R_RX_UNDER_Pos  0u
#define I2C_IC_INTR_STAT_R_RX_UNDER_Msk  (0x1u << 0u)
#define I2C_IC_INTR_MASK_M_GEN_CALL_Pos  11u
#define I2C_IC_INTR_MASK_M_GEN_CALL_Msk  (0x1u << 11u)
#define I2C_IC_INTR_MASK_M_START_DET_Pos  10u
#define I2C_IC_INTR_MASK_M_START_DET_Msk  (0x1u << 10u)
#define I2C_IC_INTR_MASK_M_STOP_DET_Pos  9u
#define I2C_IC_INTR_MASK_M_STOP_DET_Msk  (0x1u << 9u)
#define I2C_IC_INTR_MASK_M_ACTIVITY_Pos  8u
#define I2C_IC_INTR_MASK_M_ACTIVITY_Msk  (0x1u << 8u)
#define I2C_IC_INTR_MASK_M_RX_DONE_Pos  7u
#define I2C_IC_INTR_MASK_M_RX_DONE_Msk  (0x1u << 7u)
#define I2C_IC_INTR_MASK_M_TX_ABRT_Pos  6u
#define I2C_IC_INTR_MASK_M_TX_ABRT_Msk  (0x1u << 6u)
#define I2C_IC_INTR_MASK_M_RD_REQ_Pos  5u
#define I2C_IC_INTR_MASK_M_RD_REQ_Msk  (0x1u << 5u)
#define I2C_IC_INTR_MASK_M_TX_EMPTY_Pos  4u
#define I2C_IC_INTR_MASK_M_TX_EMPTY_Msk  (0x1u << 4u)
#define I2C_IC_INTR_MASK_M_TX_OVER_Pos  3u
#define I2C_IC_INTR_MASK_M_TX_OVER_Msk  (0x1u << 3u)
#define I2C_IC_INTR_MASK_M_RX_FULL_Pos  2u
#define I2C_IC_INTR_MASK_M_RX_FULL_Msk  (0x1u << 2u)
#define I2C_IC_INTR_MASK_M_RX_OVER_Pos  1u
#define I2C_IC_INTR_MASK_M_RX_OVER_Msk  (0x1u << 1u)
#define I2C_IC_INTR_MASK_M_RX_UNDER_Pos  0u
#define I2C_IC_INTR_MASK_M_RX_UNDER_Msk  (0x1u << 0u)
#define I2C_IC_RAW_INTR_STAT_GEN_CALL_Pos  11u
#define I2C_IC_RAW_INTR_STAT_GEN_CALL_Msk  (0x1u << 11u)
#define I2C_IC_RAW_INTR_STAT_START_DET_Pos  10u
#define I2C_IC_RAW_INTR_STAT_START_DET_Msk  (0x1u << 10u)
#define I2C_IC_RAW_INTR_STAT_STOP_DET_Pos  9u
#define I2C_IC_RAW_INTR_STAT_STOP_DET_Msk  (0x1u << 9u)
#define I2C_IC_RAW_INTR_STAT_ACTIVITY_NEGE_Pos  8u
#define I2C_IC_RAW_INTR_STAT_ACTIVITY_NEGE_Msk  (0x1u << 8u)
#define I2C_IC_RAW_INTR_STAT_RX_DONE_Pos  7u
#define I2C_IC_RAW_INTR_STAT_RX_DONE_Msk  (0x1u << 7u)
#define I2C_IC_RAW_INTR_STAT_TX_ABRT_Pos  6u
#define I2C_IC_RAW_INTR_STAT_TX_ABRT_Msk  (0x1u << 6u)
#define I2C_IC_RAW_INTR_STAT_RD_REQ_Pos  5u
#define I2C_IC_RAW_INTR_STAT_RD_REQ_Msk  (0x1u << 5u)
#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_Pos  4u
#define I2C_IC_RAW_INTR_STAT_TX_EMPTY_Msk  (0x1u << 4u)
#define I2C_IC_RAW_INTR_STAT_TX_OVER_Pos  3u
#define I2C_IC_RAW_INTR_STAT_TX_OVER_Msk  (0x1u << 3u)
#define I2C_IC_RAW_INTR_STAT_RX_FULL_Pos  2u
#define I2C_IC_RAW_INTR_STAT_RX_FULL_Msk  (0x1u << 2u)
#define I2C_IC_RAW_INTR_STAT_RX_OVER_Pos  1u
#define I2C_IC_RAW_INTR_STAT_RX_OVER_Msk  (0x1u << 1u)
#define I2C_IC_RAW_INTR_STAT_RX_UNDER_Pos  0u
#define I2C_IC_RAW_INTR_STAT_RX_UNDER_Msk  (0x1u << 0u)
#define I2C_IC_RX_TL_RX_TL_Pos  0u
#define I2C_IC_RX_TL_RX_TL_Msk  (0xffu << 0u)
#define I2C_IC_TX_TL_TX_TL_Pos  0u
#define I2C_IC_TX_TL_TX_TL_Msk  (0xffu << 0u)
#define I2C_IC_CLR_INTR_CLR_INTR_Pos  0u
#define I2C_IC_CLR_INTR_CLR_INTR_Msk  (0x1u << 0u)
#define I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Pos  0u
#define I2C_IC_CLR_RX_UNDER_CLR_RX_UNDER_Msk  (0x1u << 0u)
#define I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Pos  0u
#define I2C_IC_CLR_RX_OVER_CLR_RX_OVER_Msk  (0x1u << 0u)
#define I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Pos  0u
#define I2C_IC_CLR_TX_OVER_CLR_TX_OVER_Msk  (0x1u << 0u)
#define I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Pos  0u
#define I2C_IC_CLR_RD_REQ_CLR_RD_REQ_Msk  (0x1u << 0u)
#define I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Pos  0u
#define I2C_IC_CLR_TX_ABRT_CLR_TX_ABRT_Msk  (0x1u << 0u)
#define I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Pos  0u
#define I2C_IC_CLR_RX_DONE_CLR_RX_DONE_Msk  (0x1u << 0u)
#define I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Pos  0u
#define I2C_IC_CLR_ACTIVITY_CLR_ACTIVITY_Msk  (0x1u << 0u)
#define I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Pos  0u
#define I2C_IC_CLR_STOP_DET_CLR_STOP_DET_Msk  (0x1u << 0u)
#define I2C_IC_CLR_START_DET_CLR_START_DET_Pos  0u
#define I2C_IC_CLR_START_DET_CLR_START_DET_Msk  (0x1u << 0u)
#define I2C_IC_ENABLE_ENABLE_Pos  0u
#define I2C_IC_ENABLE_ENABLE_Msk  (0x1u << 0u)
#define I2C_IC_STATUS_SLV_ACTIVITY_Pos  6u
#define I2C_IC_STATUS_SLV_ACTIVITY_Msk  (0x1u << 6u)
#define I2C_IC_STATUS_MST_ACTIVITY_Pos  5u
#define I2C_IC_STATUS_MST_ACTIVITY_Msk  (0x1u << 5u)
#define I2C_IC_STATUS_RFF_Pos  4u
#define I2C_IC_STATUS_RFF_Msk  (0x1u << 4u)
#define I2C_IC_STATUS_RFNE_Pos  3u
#define I2C_IC_STATUS_RFNE_Msk  (0x1u << 3u)
#define I2C_IC_STATUS_TFE_Pos  2u
#define I2C_IC_STATUS_TFE_Msk  (0x1u << 2u)
#define I2C_IC_STATUS_TFNF_Pos  1u
#define I2C_IC_STATUS_TFNF_Msk  (0x1u << 1u)
#define I2C_IC_STATUS_ACTIVITY_Pos  0u
#define I2C_IC_STATUS_ACTIVITY_Msk  (0x1u << 0u)
#define I2C_IC_TXFLR_TXFLR_Pos  0u
#define I2C_IC_TXFLR_TXFLR_Msk  (0xfu << 0u)
#define I2C_IC_RXFLR_RXFLR_Pos  0u
#define I2C_IC_RXFLR_RXFLR_Msk  (0xfu << 0u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Pos  15u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_Msk  (0x1u << 15u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Pos  14u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_Msk  (0x1u << 14u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Pos  13u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_Msk  (0x1u << 13u)
#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Pos  12u
#define I2C_IC_TX_ABRT_SOURCE_ARB_LOST_Msk  (0x1u << 12u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Pos  11u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_MASTER_DIS_Msk  (0x1u << 11u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Pos  10u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_Msk  (0x1u << 10u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Pos  9u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_Msk  (0x1u << 9u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Pos  8u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_Msk  (0x1u << 8u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Pos  7u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_Msk  (0x1u << 7u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Pos  6u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_HS_ACKDET_Msk  (0x1u << 6u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Pos  5u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_READ_Msk  (0x1u << 5u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Pos  4u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_Msk  (0x1u << 4u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Pos  3u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_Msk  (0x1u << 3u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Pos  2u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_Msk  (0x1u << 2u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Pos  1u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_Msk  (0x1u << 1u)
#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Pos  0u
#define I2C_IC_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_Msk  (0x1u << 0u)
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Pos  2u
#define I2C_IC_ENABLE_STATUS_SLV_RX_DATA_LOST_Msk  (0x1u << 2u)
#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Pos  1u
#define I2C_IC_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_Msk  (0x1u << 1u)
#define I2C_IC_ENABLE_STATUS_IC_EN_Pos  0u
#define I2C_IC_ENABLE_STATUS_IC_EN_Msk  (0x1u << 0u)
#define I2C_IC_START_START_Pos  0u
#define I2C_IC_START_START_Msk  (0x1u << 0u)

typedef struct {   /* SPI master 0, Synopsys DesignWare APB SSI (DS §5.2, p.243-264; FIFO depth 128). On the DM-32 this is the bus t */
  __IO uint32_t CTRLR0;                      /* 0x00 Transmission mode and frame length. DS §5.2.5.1 p.254. The datasheet gives master and slave interpretations of */
  __IO uint32_t CTRLR1;                      /* 0x04 Number of received data frames. DS §5.2.5.2 p.256. Reset 0x0 (DS). */
  __IO uint32_t SSIENR;                      /* 0x08 SPI module enable. DS §5.2.5.3 p.256. FW: 0 reads, 1 write. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_C[1];               /* 0xc-0xf */
  __IO uint32_t SER;                         /* 0x10 slave Chip select enable. DS §5.2.5.4 p.256. Reset 0x0 (DS). */
  __IO uint32_t BAUDR;                       /* 0x14 Clock enable and frequency division. DS §5.2.5.5 p.256. Reset 0x0 (DS). */
  __IO uint32_t TXFTLR;                      /* 0x18 Transmit FIFO threshold. DS §5.2.5.6 p.258. FW: 0 reads, 1 write. Reset 0x0 (DS). */
  __IO uint32_t RXFTLR;                      /* 0x1c Receive FIFO threshold. DS §5.2.5.7 p.258. FW: 0 reads, 1 write. Reset 0x0 (DS). */
  __I  uint32_t TXFLR;                       /* 0x20 Number of data in the transmit FIFO. DS §5.2.5.8 p.258. Reset 0x0 (DS). */
  __I  uint32_t RXFLR;                       /* 0x24 Number of data in receive FIFO. DS §5.2.5.9 p.258. Reset 0x0 (DS). */
  __I  uint32_t SR;                          /* 0x28 SPI module status. DS §5.2.5.10 p.258. Reset 0x6 (DS). */
  __IO uint32_t IMR;                         /* 0x2c Interrupt mask register. DS §5.2.5.11 p.260. FW: 0 reads, 1 write. Reset 0x3f (DS). */
  __I  uint32_t ISR;                         /* 0x30 Masked interrupt register. DS §5.2.5.12 p.260. Reset 0x0 (DS). */
  __I  uint32_t RISR;                        /* 0x34 Unmasked interrupt register. DS §5.2.5.13 p.260. Reset 0x0 (DS). */
  __I  uint32_t TXOICR;                      /* 0x38 Transmit FIFO overflow Interrupt clear. DS §5.2.5.14 p.260. Reset 0x0 (DS). */
  __I  uint32_t RXOICR;                      /* 0x3c Receive FIFO overflow Interrupt clear. DS §5.2.5.15 p.262. Reset 0x0 (DS). */
  __I  uint32_t RXUICR;                      /* 0x40 Receive FIFO underflow Interrupt clear. DS §5.2.5.16 p.262. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_44[1];              /* 0x44-0x47 */
  __I  uint32_t ICR;                         /* 0x48 Clear ssi_txo_intr , ssi_rxu_intr , ssi_rxo_intr. DS §5.2.5.17 p.262. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_4C[3];              /* 0x4c-0x57 */
  __I  uint32_t IDR;                         /* 0x58 Module ID Register. DS §5.2.5.18 p.262. Reset 0x11223344 (DS). */
  __I  uint32_t SSI_COMP_VERSION;            /* 0x5c Version number. DS §5.2.5.19 p.262. Reset 0x3331312a (DS). */
  __IO uint32_t DR;                          /* 0x60 Data transmit / receive FIFO interface. DS §5.2.5.20 p.263. Printed RO in the datasheet, but it is the TX/RX F */
} SSI_Type;   /* 0x64 bytes */
#define SSI_CTRLR0_SRL_Pos  11u
#define SSI_CTRLR0_SRL_Msk  (0x1u << 11u)
#define SSI_CTRLR0_ENDIAN_Pos  10u
#define SSI_CTRLR0_ENDIAN_Msk  (0x1u << 10u)
#define SSI_CTRLR0_TMOD_Pos  8u
#define SSI_CTRLR0_TMOD_Msk  (0x3u << 8u)
#define SSI_CTRLR0_SCPOL_Pos  7u
#define SSI_CTRLR0_SCPOL_Msk  (0x1u << 7u)
#define SSI_CTRLR0_SCPH_Pos  6u
#define SSI_CTRLR0_SCPH_Msk  (0x1u << 6u)
#define SSI_CTRLR0_M2L_Pos  5u
#define SSI_CTRLR0_M2L_Msk  (0x1u << 5u)
#define SSI_CTRLR0_DFS_Pos  0u
#define SSI_CTRLR0_DFS_Msk  (0x1fu << 0u)
#define SSI_CTRLR1_NDF_Pos  0u
#define SSI_CTRLR1_NDF_Msk  (0xffffu << 0u)
#define SSI_SSIENR_SSI_EN_Pos  0u
#define SSI_SSIENR_SSI_EN_Msk  (0x1u << 0u)
#define SSI_SER_SER_Pos  0u
#define SSI_SER_SER_Msk  (0x3u << 0u)
#define SSI_BAUDR_SCKDV_Pos  0u
#define SSI_BAUDR_SCKDV_Msk  (0xffffu << 0u)
#define SSI_TXFTLR_TFT_Pos  0u
#define SSI_TXFTLR_TFT_Msk  (0xffu << 0u)
#define SSI_RXFTLR_RFT_Pos  0u
#define SSI_RXFTLR_RFT_Msk  (0xffu << 0u)
#define SSI_TXFLR_TXTFL_Pos  0u
#define SSI_TXFLR_TXTFL_Msk  (0xffu << 0u)
#define SSI_RXFLR_RXTFL_Pos  0u
#define SSI_RXFLR_RXTFL_Msk  (0xffu << 0u)
#define SSI_SR_RFF_Pos  4u
#define SSI_SR_RFF_Msk  (0x1u << 4u)
#define SSI_SR_RFNE_Pos  3u
#define SSI_SR_RFNE_Msk  (0x1u << 3u)
#define SSI_SR_TFE_Pos  2u
#define SSI_SR_TFE_Msk  (0x1u << 2u)
#define SSI_SR_TFNF_Pos  1u
#define SSI_SR_TFNF_Msk  (0x1u << 1u)
#define SSI_SR_BUSY_Pos  0u
#define SSI_SR_BUSY_Msk  (0x1u << 0u)
#define SSI_IMR_RXFIM_Pos  4u
#define SSI_IMR_RXFIM_Msk  (0x1u << 4u)
#define SSI_IMR_RXOIM_Pos  3u
#define SSI_IMR_RXOIM_Msk  (0x1u << 3u)
#define SSI_IMR_RXUIM_Pos  2u
#define SSI_IMR_RXUIM_Msk  (0x1u << 2u)
#define SSI_IMR_TXOIM_Pos  1u
#define SSI_IMR_TXOIM_Msk  (0x1u << 1u)
#define SSI_IMR_TXEIM_Pos  0u
#define SSI_IMR_TXEIM_Msk  (0x1u << 0u)
#define SSI_ISR_RXFIS_Pos  4u
#define SSI_ISR_RXFIS_Msk  (0x1u << 4u)
#define SSI_ISR_RXOIS_Pos  3u
#define SSI_ISR_RXOIS_Msk  (0x1u << 3u)
#define SSI_ISR_RXUIS_Pos  2u
#define SSI_ISR_RXUIS_Msk  (0x1u << 2u)
#define SSI_ISR_TXOIS_Pos  1u
#define SSI_ISR_TXOIS_Msk  (0x1u << 1u)
#define SSI_ISR_TXEIS_Pos  0u
#define SSI_ISR_TXEIS_Msk  (0x1u << 0u)
#define SSI_RISR_RXFIR_Pos  4u
#define SSI_RISR_RXFIR_Msk  (0x1u << 4u)
#define SSI_RISR_RXOIR_Pos  3u
#define SSI_RISR_RXOIR_Msk  (0x1u << 3u)
#define SSI_RISR_RXUIR_Pos  2u
#define SSI_RISR_RXUIR_Msk  (0x1u << 2u)
#define SSI_RISR_TXOIR_Pos  1u
#define SSI_RISR_TXOIR_Msk  (0x1u << 1u)
#define SSI_RISR_TXEIR_Pos  0u
#define SSI_RISR_TXEIR_Msk  (0x1u << 0u)
#define SSI_TXOICR_TXOICR_Pos  0u
#define SSI_TXOICR_TXOICR_Msk  (0x1u << 0u)
#define SSI_RXOICR_RXOICR_Pos  0u
#define SSI_RXOICR_RXOICR_Msk  (0x1u << 0u)
#define SSI_RXUICR_RXUICR_Pos  0u
#define SSI_RXUICR_RXUICR_Msk  (0x1u << 0u)
#define SSI_ICR_ICR_Pos  0u
#define SSI_ICR_ICR_Msk  (0x1u << 0u)
#define SSI_IDR_IDR_Pos  0u
#define SSI_IDR_IDR_Msk  (0xffffffffu << 0u)
#define SSI_SSI_COMP_VERSION_SSI_COMP_VERSION_Pos  0u
#define SSI_SSI_COMP_VERSION_SSI_COMP_VERSION_Msk  (0xffffffffu << 0u)
#define SSI_DR_DR_Pos  0u
#define SSI_DR_DR_Msk  (0xffffffffu << 0u)

typedef struct {   /* PWM, three channels at a 0x20 stride plus a shared interrupt status at 0xff0 (DS §5.8, p.385-400). FW: the bas */
  __IO uint32_t PWM0_CFG;                    /* 0x00 PWM0 Configuration registers. DS §5.8.5.1 p.391. Reset 0x0 (DS). */
  __IO uint32_t PWM0_RPT;                    /* 0x04 PWM0 ONE_SHOT Number of. DS §5.8.5.2 p.392. Reset 0x0 (DS). */
  __IO uint32_t PWM0_PER;                    /* 0x08 PWM0 The periodic waveform lasts for. DS §5.8.5.3 p.393. Reset 0x0 (DS). */
  __IO uint32_t PWM0_FP;                     /* 0x0c PWM0 The number of beats that the. DS §5.8.5.4 p.393. Reset 0x0 (DS). */
  __IO uint32_t PWM0_STATUS;                 /* 0x10 PWM0 Status Register. DS §5.8.5.5 p.393. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_14[3];              /* 0x14-0x1f */
  __IO uint32_t PWM1_CFG;                    /* 0x20 PWM1 Configuration registers. DS §5.8.5.6 p.393. Reset 0x0 (DS). */
  __IO uint32_t PWM1_RPT;                    /* 0x24 PWM1 ONE_SHOT Number of. DS §5.8.5.7 p.395. Reset 0x0 (DS). */
  __IO uint32_t PWM1_PER;                    /* 0x28 PWM1 The periodic waveform lasts for. DS §5.8.5.8 p.395. Reset 0x0 (DS). */
  __IO uint32_t PWM1_FP;                     /* 0x2c PWM1 The number of beats that the. DS §5.8.5.9 p.395. Reset 0x0 (DS). */
  __IO uint32_t PWM1_STATUS;                 /* 0x30 PWM1 Status Register. DS §5.8.5.10 p.396. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_34[3];              /* 0x34-0x3f */
  __IO uint32_t PWM2_CFG;                    /* 0x40 PWM2 Configuration registers. DS §5.8.5.11 p.397. Reset 0x0 (DS). */
  __IO uint32_t PWM2_RPT;                    /* 0x44 PWM2 ONE_SHOT Number of. DS §5.8.5.12 p.397. Reset 0x0 (DS). */
  __IO uint32_t PWM2_PER;                    /* 0x48 PWM2 The periodic waveform lasts for. DS §5.8.5.13 p.399. Reset 0x0 (DS). */
  __IO uint32_t PWM2_FP;                     /* 0x4c PWM2 The number of beats that the. DS §5.8.5.14 p.399. Reset 0x0 (DS). */
  __IO uint32_t PWM2_STATUS;                 /* 0x50 PWM2 Status Register. DS §5.8.5.15 p.399. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_54[999];            /* 0x54-0xfef */
  __I  uint32_t PWM_INTR_STA;                /* 0xff0 DS §5.8.5.16 p.399. Reset 0x0 (DS). */
} PWM_Type;   /* 0xff4 bytes */
#define PWM_PWM0_CFG_inactout_Pos  9u
#define PWM_PWM0_CFG_inactout_Msk  (0x1u << 9u)
#define PWM_PWM0_CFG_fpout_Pos  8u
#define PWM_PWM0_CFG_fpout_Msk  (0x1u << 8u)
#define PWM_PWM0_CFG_evtrig_Pos  6u
#define PWM_PWM0_CFG_evtrig_Msk  (0x3u << 6u)
#define PWM_PWM0_CFG_mode_Pos  4u
#define PWM_PWM0_CFG_mode_Msk  (0x3u << 4u)
#define PWM_PWM0_CFG_inten_Pos  3u
#define PWM_PWM0_CFG_inten_Msk  (0x1u << 3u)
#define PWM_PWM0_CFG_cfg_update_Pos  2u
#define PWM_PWM0_CFG_cfg_update_Msk  (0x1u << 2u)
#define PWM_PWM0_CFG_soft_rst_Pos  1u
#define PWM_PWM0_CFG_soft_rst_Msk  (0x1u << 1u)
#define PWM_PWM0_CFG_start_Pos  0u
#define PWM_PWM0_CFG_start_Msk  (0x1u << 0u)
#define PWM_PWM0_RPT_pwm_rpt_Pos  0u
#define PWM_PWM0_RPT_pwm_rpt_Msk  (0xffffu << 0u)
#define PWM_PWM0_PER_pwm_per_Pos  0u
#define PWM_PWM0_PER_pwm_per_Msk  (0xffffffffu << 0u)
#define PWM_PWM0_FP_pwm_fp_Pos  0u
#define PWM_PWM0_FP_pwm_fp_Msk  (0xffffffffu << 0u)
#define PWM_PWM0_STATUS_pwm_out_Pos  9u
#define PWM_PWM0_STATUS_pwm_out_Msk  (0x1u << 9u)
#define PWM_PWM0_STATUS_pwm_busy_Pos  8u
#define PWM_PWM0_STATUS_pwm_busy_Msk  (0x1u << 8u)
#define PWM_PWM0_STATUS_pwm_cycle_Pos  0u
#define PWM_PWM0_STATUS_pwm_cycle_Msk  (0xffu << 0u)
#define PWM_PWM1_CFG_inactout_Pos  9u
#define PWM_PWM1_CFG_inactout_Msk  (0x1u << 9u)
#define PWM_PWM1_CFG_fpout_Pos  8u
#define PWM_PWM1_CFG_fpout_Msk  (0x1u << 8u)
#define PWM_PWM1_CFG_evtrig_Pos  6u
#define PWM_PWM1_CFG_evtrig_Msk  (0x3u << 6u)
#define PWM_PWM1_CFG_mode_Pos  4u
#define PWM_PWM1_CFG_mode_Msk  (0x3u << 4u)
#define PWM_PWM1_CFG_inten_Pos  3u
#define PWM_PWM1_CFG_inten_Msk  (0x1u << 3u)
#define PWM_PWM1_CFG_cfg_update_Pos  2u
#define PWM_PWM1_CFG_cfg_update_Msk  (0x1u << 2u)
#define PWM_PWM1_CFG_soft_rst_Pos  1u
#define PWM_PWM1_CFG_soft_rst_Msk  (0x1u << 1u)
#define PWM_PWM1_CFG_start_Pos  0u
#define PWM_PWM1_CFG_start_Msk  (0x1u << 0u)
#define PWM_PWM1_RPT_pwm_rpt_Pos  0u
#define PWM_PWM1_RPT_pwm_rpt_Msk  (0xffffu << 0u)
#define PWM_PWM1_PER_pwm_per_Pos  0u
#define PWM_PWM1_PER_pwm_per_Msk  (0xffffffffu << 0u)
#define PWM_PWM1_FP_pwm_fp_Pos  0u
#define PWM_PWM1_FP_pwm_fp_Msk  (0xffffffffu << 0u)
#define PWM_PWM1_STATUS_pwm_out_Pos  9u
#define PWM_PWM1_STATUS_pwm_out_Msk  (0x1u << 9u)
#define PWM_PWM1_STATUS_pwm_busy_Pos  8u
#define PWM_PWM1_STATUS_pwm_busy_Msk  (0x1u << 8u)
#define PWM_PWM1_STATUS_pwm_cycle_Pos  0u
#define PWM_PWM1_STATUS_pwm_cycle_Msk  (0xffu << 0u)
#define PWM_PWM2_CFG_inactout_Pos  9u
#define PWM_PWM2_CFG_inactout_Msk  (0x1u << 9u)
#define PWM_PWM2_CFG_fpout_Pos  8u
#define PWM_PWM2_CFG_fpout_Msk  (0x1u << 8u)
#define PWM_PWM2_CFG_evtrig_Pos  6u
#define PWM_PWM2_CFG_evtrig_Msk  (0x3u << 6u)
#define PWM_PWM2_CFG_mode_Pos  4u
#define PWM_PWM2_CFG_mode_Msk  (0x3u << 4u)
#define PWM_PWM2_CFG_inten_Pos  3u
#define PWM_PWM2_CFG_inten_Msk  (0x1u << 3u)
#define PWM_PWM2_CFG_cfg_update_Pos  2u
#define PWM_PWM2_CFG_cfg_update_Msk  (0x1u << 2u)
#define PWM_PWM2_CFG_soft_rst_Pos  1u
#define PWM_PWM2_CFG_soft_rst_Msk  (0x1u << 1u)
#define PWM_PWM2_CFG_start_Pos  0u
#define PWM_PWM2_CFG_start_Msk  (0x1u << 0u)
#define PWM_PWM2_RPT_pwm_rpt_Pos  0u
#define PWM_PWM2_RPT_pwm_rpt_Msk  (0xffffu << 0u)
#define PWM_PWM2_PER_pwm_per_Pos  0u
#define PWM_PWM2_PER_pwm_per_Msk  (0xffffffffu << 0u)
#define PWM_PWM2_FP_pwm_fp_Pos  0u
#define PWM_PWM2_FP_pwm_fp_Msk  (0xffffffffu << 0u)
#define PWM_PWM2_STATUS_pwm_out_Pos  9u
#define PWM_PWM2_STATUS_pwm_out_Msk  (0x1u << 9u)
#define PWM_PWM2_STATUS_pwm_busy_Pos  8u
#define PWM_PWM2_STATUS_pwm_busy_Msk  (0x1u << 8u)
#define PWM_PWM2_STATUS_pwm_cycle_Pos  0u
#define PWM_PWM2_STATUS_pwm_cycle_Msk  (0xffu << 0u)
#define PWM_PWM_INTR_STA_pwm2_intr_Pos  2u
#define PWM_PWM_INTR_STA_pwm2_intr_Msk  (0x1u << 2u)
#define PWM_PWM_INTR_STA_pwm1_intr_Pos  1u
#define PWM_PWM_INTR_STA_pwm1_intr_Msk  (0x1u << 1u)
#define PWM_PWM_INTR_STA_pwm0_intr_Pos  0u
#define PWM_PWM_INTR_STA_pwm0_intr_Msk  (0x1u << 0u)

typedef struct {   /* CPU-side 10-bit ADC controller, 8 channels A-H in pairs per data register (DS §5.9, p.400-423). Distinct from  */
  __IO uint32_t ADC_CTRL;                    /* 0x00 ADC Control registers. DS §5.9.5.1 p.411. FW: 0 reads, 3 writes. Reset 0x0 (DS). */
  __IO uint32_t ADC_INTR_DELTA;              /* 0x04 ADC Interruption error range. DS §5.9.5.2 p.411. Reset 0x0 (DS). */
  __IO uint32_t ADC_INTR;                    /* 0x08 ADC Interrupt Control Register. DS §5.9.5.3 p.411. FW: 0 reads, 1 write. Reset 0x0 (DS). */
  __I  uint32_t ADC_INTR_STA;                /* 0x0c ADC Interrupt Status Register. DS §5.9.5.4 p.413. */
  __IO uint32_t ADC_SCAN_TIME;               /* 0x10 ADC Scan interval setting. DS §5.9.5.5 p.415. Reset 0x2c (DS). */
  __O  uint32_t ADC_START;                   /* 0x14 ADC start up. DS §5.9.5.6 p.415. FW: 0 reads, 1 write. Reset 0x0 (DS). */
  __IO uint32_t ADC_CTRL_STATE;              /* 0x18 ADC Control and Status Registers. DS §5.9.5.7 p.415. FW: 3 reads, 0 writes. Reset 0x0 (DS). */
  __IO uint32_t ADC_INTR_THRESHOLD;          /* 0x1c ADC Interrupt initial value. DS §5.9.5.8 p.417. Printed ADC_INTR_THRESHOLE (typo); the reserved row is printed */
  __O  uint32_t ADC_CTRL_STOP;               /* 0x20 ADC Configuration registers. DS §5.9.5.9 p.417. FW: 0 reads, 3 writes. Reset 0x0 (DS). */
  __IO uint32_t ADC_CH_VLD;                  /* 0x24 ADC Channel Configuration Register. DS §5.9.5.10 p.419. FW: 0 reads, 2 writes. Note: Single scan mode, ADC_CH_ */
  __IO uint32_t ADC_PD_SEOC_TIME;            /* 0x28 ADC Power-off time register. DS §5.9.5.11 p.419. FW: 0 reads, 1 write. Reset 0xa20 (DS). */
  __IO uint32_t ADC_P2S_EN;                  /* 0x2c ADC Serial data output register. DS §5.9.5.12 p.419. FW: 0 reads, 1 write. Reset 0x0 (DS). */
  __I  uint32_t ADC_DATA_AB;                 /* 0x30 ADC Channel AB Scan Value. DS §5.9.5.13 p.420. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
  __I  uint32_t ADC_DATA_CD;                 /* 0x34 ADC Channel CD Scan Value. DS §5.9.5.14 p.421. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
  __I  uint32_t ADC_DATA_EF;                 /* 0x38 ADC Channel EF Scan Value. DS §5.9.5.15 p.421. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
  __I  uint32_t ADC_DATA_GH;                 /* 0x3c ADC Channel GH Scan Value. DS §5.9.5.16 p.421. FW: 2 reads, 0 writes. Reset 0x0 (DS). */
  __I  uint32_t ADC_CTRL_VERID;              /* 0x40 ADC Version Register. DS §5.9.5.17 p.421. Reset 0x20151216 (DS). */
  __I  uint32_t ADC_DIR_DAT_OP;              /* 0x44 ADC EOC Then directly output ADC. DS §5.9.5.18 p.421. Reset 0x0 (DS). */
} ADC_Type;   /* 0x48 bytes */
#define ADC_ADC_CTRL_PD_FORCE_HIGH_Pos  3u
#define ADC_ADC_CTRL_PD_FORCE_HIGH_Msk  (0x1u << 3u)
#define ADC_ADC_CTRL_MODE_SEL_Pos  2u
#define ADC_ADC_CTRL_MODE_SEL_Msk  (0x1u << 2u)
#define ADC_ADC_CTRL_GLITCH_Pos  1u
#define ADC_ADC_CTRL_GLITCH_Msk  (0x1u << 1u)
#define ADC_ADC_CTRL_POWER_DOWN_Pos  0u
#define ADC_ADC_CTRL_POWER_DOWN_Msk  (0x1u << 0u)
#define ADC_ADC_INTR_DELTA_ADC_DATA_DELTA_Pos  0u
#define ADC_ADC_INTR_DELTA_ADC_DATA_DELTA_Msk  (0x3ffu << 0u)
#define ADC_ADC_INTR_INTR_EN_Pos  16u
#define ADC_ADC_INTR_INTR_EN_Msk  (0x1u << 16u)
#define ADC_ADC_INTR_INTR_ADC_ERR_Pos  8u
#define ADC_ADC_INTR_INTR_ADC_ERR_Msk  (0x1u << 8u)
#define ADC_ADC_INTR_INTR_EN_H_Pos  7u
#define ADC_ADC_INTR_INTR_EN_H_Msk  (0x1u << 7u)
#define ADC_ADC_INTR_INTR_EN_G_Pos  6u
#define ADC_ADC_INTR_INTR_EN_G_Msk  (0x1u << 6u)
#define ADC_ADC_INTR_INTR_EN_F_Pos  5u
#define ADC_ADC_INTR_INTR_EN_F_Msk  (0x1u << 5u)
#define ADC_ADC_INTR_INTR_EN_E_Pos  4u
#define ADC_ADC_INTR_INTR_EN_E_Msk  (0x1u << 4u)
#define ADC_ADC_INTR_INTR_EN_D_Pos  3u
#define ADC_ADC_INTR_INTR_EN_D_Msk  (0x1u << 3u)
#define ADC_ADC_INTR_INTR_EN_C_Pos  2u
#define ADC_ADC_INTR_INTR_EN_C_Msk  (0x1u << 2u)
#define ADC_ADC_INTR_INTR_EN_B_Pos  1u
#define ADC_ADC_INTR_INTR_EN_B_Msk  (0x1u << 1u)
#define ADC_ADC_INTR_INTR_EN_A_Pos  0u
#define ADC_ADC_INTR_INTR_EN_A_Msk  (0x1u << 0u)
#define ADC_ADC_INTR_STA_ADC_ERR_RAW_Pos  24u
#define ADC_ADC_INTR_STA_ADC_ERR_RAW_Msk  (0x1u << 24u)
#define ADC_ADC_INTR_STA_CHANNEL_H_INTR_RAW_Pos  23u
#define ADC_ADC_INTR_STA_CHANNEL_H_INTR_RAW_Msk  (0x1u << 23u)
#define ADC_ADC_INTR_STA_CHANNEL_G_INTR_RAW_Pos  22u
#define ADC_ADC_INTR_STA_CHANNEL_G_INTR_RAW_Msk  (0x1u << 22u)
#define ADC_ADC_INTR_STA_CHANNEL_F_INTR_RAW_Pos  21u
#define ADC_ADC_INTR_STA_CHANNEL_F_INTR_RAW_Msk  (0x1u << 21u)
#define ADC_ADC_INTR_STA_CHANNEL_E_INTR_RAW_Pos  20u
#define ADC_ADC_INTR_STA_CHANNEL_E_INTR_RAW_Msk  (0x1u << 20u)
#define ADC_ADC_INTR_STA_CHANNEL_D_INTR_RAW_Pos  19u
#define ADC_ADC_INTR_STA_CHANNEL_D_INTR_RAW_Msk  (0x1u << 19u)
#define ADC_ADC_INTR_STA_CHANNEL_C_INTR_RAW_Pos  18u
#define ADC_ADC_INTR_STA_CHANNEL_C_INTR_RAW_Msk  (0x1u << 18u)
#define ADC_ADC_INTR_STA_CHANNEL_B_INTR_RAW_Pos  17u
#define ADC_ADC_INTR_STA_CHANNEL_B_INTR_RAW_Msk  (0x1u << 17u)
#define ADC_ADC_INTR_STA_CHANNEL_A_INTR_RAW_Pos  16u
#define ADC_ADC_INTR_STA_CHANNEL_A_INTR_RAW_Msk  (0x1u << 16u)
#define ADC_ADC_INTR_STA_ADC_ERR_INTR_Pos  8u
#define ADC_ADC_INTR_STA_ADC_ERR_INTR_Msk  (0x1u << 8u)
#define ADC_ADC_INTR_STA_CHANNEL_H_INTR_Pos  7u
#define ADC_ADC_INTR_STA_CHANNEL_H_INTR_Msk  (0x1u << 7u)
#define ADC_ADC_INTR_STA_CHANNEL_G_INTR_Pos  6u
#define ADC_ADC_INTR_STA_CHANNEL_G_INTR_Msk  (0x1u << 6u)
#define ADC_ADC_INTR_STA_CHANNEL_F_INTR_Pos  5u
#define ADC_ADC_INTR_STA_CHANNEL_F_INTR_Msk  (0x1u << 5u)
#define ADC_ADC_INTR_STA_CHANNEL_E_INTR_Pos  4u
#define ADC_ADC_INTR_STA_CHANNEL_E_INTR_Msk  (0x1u << 4u)
#define ADC_ADC_INTR_STA_CHANNEL_D_INTR_Pos  3u
#define ADC_ADC_INTR_STA_CHANNEL_D_INTR_Msk  (0x1u << 3u)
#define ADC_ADC_INTR_STA_CHANNEL_C_INTR_Pos  2u
#define ADC_ADC_INTR_STA_CHANNEL_C_INTR_Msk  (0x1u << 2u)
#define ADC_ADC_INTR_STA_CHANNEL_B_INTR_Pos  1u
#define ADC_ADC_INTR_STA_CHANNEL_B_INTR_Msk  (0x1u << 1u)
#define ADC_ADC_INTR_STA_CHANNEL_A_INTR_Pos  0u
#define ADC_ADC_INTR_STA_CHANNEL_A_INTR_Msk  (0x1u << 0u)
#define ADC_ADC_SCAN_TIME_SCAN_TIME_Pos  0u
#define ADC_ADC_SCAN_TIME_SCAN_TIME_Msk  (0xffffffffu << 0u)
#define ADC_ADC_START_ADC_START_Pos  0u
#define ADC_ADC_START_ADC_START_Msk  (0x1u << 0u)
#define ADC_ADC_CTRL_STATE_EOC_WIDTH_ERR_Pos  8u
#define ADC_ADC_CTRL_STATE_EOC_WIDTH_ERR_Msk  (0x1u << 8u)
#define ADC_ADC_CTRL_STATE_SOC_EOC_TIME_OUT_Pos  7u
#define ADC_ADC_CTRL_STATE_SOC_EOC_TIME_OUT_Msk  (0x1u << 7u)
#define ADC_ADC_CTRL_STATE_SCAN_TIME_ERROR_Pos  6u
#define ADC_ADC_CTRL_STATE_SCAN_TIME_ERROR_Msk  (0x1u << 6u)
#define ADC_ADC_CTRL_STATE_SAMP_FSM_STATE_Pos  1u
#define ADC_ADC_CTRL_STATE_SAMP_FSM_STATE_Msk  (0x1fu << 1u)
#define ADC_ADC_CTRL_STATE_ADC_CTRL_BUSY_Pos  0u
#define ADC_ADC_CTRL_STATE_ADC_CTRL_BUSY_Msk  (0x1u << 0u)
#define ADC_ADC_INTR_THRESHOLD_ADC_INTR_THRESHOLD_Pos  0u
#define ADC_ADC_INTR_THRESHOLD_ADC_INTR_THRESHOLD_Msk  (0x3ffu << 0u)
#define ADC_ADC_CTRL_STOP_ADC_CTRL_RESET_Pos  1u
#define ADC_ADC_CTRL_STOP_ADC_CTRL_RESET_Msk  (0x1u << 1u)
#define ADC_ADC_CTRL_STOP_ADC_CTRL_STOP_Pos  0u
#define ADC_ADC_CTRL_STOP_ADC_CTRL_STOP_Msk  (0x1u << 0u)
#define ADC_ADC_CH_VLD_ADC_CHH_VLD_Pos  7u
#define ADC_ADC_CH_VLD_ADC_CHH_VLD_Msk  (0x1u << 7u)
#define ADC_ADC_CH_VLD_ADC_CHG_VLD_Pos  6u
#define ADC_ADC_CH_VLD_ADC_CHG_VLD_Msk  (0x1u << 6u)
#define ADC_ADC_CH_VLD_ADC_CHF_VLD_Pos  5u
#define ADC_ADC_CH_VLD_ADC_CHF_VLD_Msk  (0x1u << 5u)
#define ADC_ADC_CH_VLD_ADC_CHE_VLD_Pos  4u
#define ADC_ADC_CH_VLD_ADC_CHE_VLD_Msk  (0x1u << 4u)
#define ADC_ADC_CH_VLD_ADC_CHD_VLD_Pos  3u
#define ADC_ADC_CH_VLD_ADC_CHD_VLD_Msk  (0x1u << 3u)
#define ADC_ADC_CH_VLD_ADC_CHC_VLD_Pos  2u
#define ADC_ADC_CH_VLD_ADC_CHC_VLD_Msk  (0x1u << 2u)
#define ADC_ADC_CH_VLD_ADC_CHB_VLD_Pos  1u
#define ADC_ADC_CH_VLD_ADC_CHB_VLD_Msk  (0x1u << 1u)
#define ADC_ADC_CH_VLD_ADC_CHA_VLD_Pos  0u
#define ADC_ADC_CH_VLD_ADC_CHA_VLD_Msk  (0x1u << 0u)
#define ADC_ADC_PD_SEOC_TIME_EOC_PD_TIME_Pos  8u
#define ADC_ADC_PD_SEOC_TIME_EOC_PD_TIME_Msk  (0xffu << 8u)
#define ADC_ADC_PD_SEOC_TIME_PD_SOC_TIME_Pos  0u
#define ADC_ADC_PD_SEOC_TIME_PD_SOC_TIME_Msk  (0xffu << 0u)
#define ADC_ADC_P2S_EN_ADC_P2S_EN_Pos  0u
#define ADC_ADC_P2S_EN_ADC_P2S_EN_Msk  (0x1u << 0u)
#define ADC_ADC_DATA_AB_CHANNEL_B_DATA_Pos  16u
#define ADC_ADC_DATA_AB_CHANNEL_B_DATA_Msk  (0x3ffu << 16u)
#define ADC_ADC_DATA_AB_CHANNEL_A_DATA_Pos  0u
#define ADC_ADC_DATA_AB_CHANNEL_A_DATA_Msk  (0x3ffu << 0u)
#define ADC_ADC_DATA_CD_CHANNEL_D_DATA_Pos  16u
#define ADC_ADC_DATA_CD_CHANNEL_D_DATA_Msk  (0x3ffu << 16u)
#define ADC_ADC_DATA_CD_CHANNEL_C_DATA_Pos  0u
#define ADC_ADC_DATA_CD_CHANNEL_C_DATA_Msk  (0x3ffu << 0u)
#define ADC_ADC_DATA_EF_CHANNEL_F_DATA_Pos  16u
#define ADC_ADC_DATA_EF_CHANNEL_F_DATA_Msk  (0x3ffu << 16u)
#define ADC_ADC_DATA_EF_CHANNEL_E_DATA_Pos  0u
#define ADC_ADC_DATA_EF_CHANNEL_E_DATA_Msk  (0x3ffu << 0u)
#define ADC_ADC_DATA_GH_CHANNEL_H_DATA_Pos  16u
#define ADC_ADC_DATA_GH_CHANNEL_H_DATA_Msk  (0x3ffu << 16u)
#define ADC_ADC_DATA_GH_CHANNEL_G_DATA_Pos  0u
#define ADC_ADC_DATA_GH_CHANNEL_G_DATA_Msk  (0x3ffu << 0u)
#define ADC_ADC_CTRL_VERID_ADC_CTRL_VERID_Pos  0u
#define ADC_ADC_CTRL_VERID_ADC_CTRL_VERID_Msk  (0xffffffffu << 0u)
#define ADC_ADC_DIR_DAT_OP_ADC_DIR_DAT_OP_Pos  0u
#define ADC_ADC_DIR_DAT_OP_ADC_DIR_DAT_OP_Msk  (0x3ffu << 0u)

typedef struct {   /* CPU-side 12-bit DAC controller, three channels A-C (DS §5.10, p.423-426). Distinct from the baseband TX DAC (S */
  __IO uint32_t DAC_PD_CTRL;                 /* 0x00 DAC Enable. DS §5.10.5.1 p.423. FW: 0 reads, 1 write. Reset 0x7 (DS). */
  __IO uint32_t DAC_PD_MODE_EN;              /* 0x04 DAC Low power enable. DS §5.10.5.2 p.423. FW: 0 reads, 1 write. Reset 0x7 (DS). */
  __IO uint32_t DAC_DATA_A;                  /* 0x08 DAC Channel A data. DS §5.10.5.3 p.425. FW: 0 reads, 2 writes. Reset 0x0 (DS). */
  __IO uint32_t DAC_DATA_B;                  /* 0x0c DAC Channel B data. DS §5.10.5.4 p.425. FW: 0 reads, 2 writes. Reset 0x0 (DS). */
  __IO uint32_t DAC_DATA_C;                  /* 0x10 DAC Channel C data. DS §5.10.5.5 p.425. FW: 0 reads, 2 writes. Reset 0x0 (DS). */
  __IO uint32_t DAC_CTRL_VERID;              /* 0x14 DAC Controller version. DS §5.10.5.6 p.425. Reset 0x20160229 (DS). */
} DAC_Type;   /* 0x18 bytes */
#define DAC_DAC_PD_CTRL_DAC_PD_C_Pos  2u
#define DAC_DAC_PD_CTRL_DAC_PD_C_Msk  (0x1u << 2u)
#define DAC_DAC_PD_CTRL_DAC_PD_B_Pos  1u
#define DAC_DAC_PD_CTRL_DAC_PD_B_Msk  (0x1u << 1u)
#define DAC_DAC_PD_CTRL_DAC_PD_A_Pos  0u
#define DAC_DAC_PD_CTRL_DAC_PD_A_Msk  (0x1u << 0u)
#define DAC_DAC_PD_MODE_EN_DAC_PD_MODE_CEN_Pos  2u
#define DAC_DAC_PD_MODE_EN_DAC_PD_MODE_CEN_Msk  (0x1u << 2u)
#define DAC_DAC_PD_MODE_EN_DAC_PD_MODE_BEN_Pos  1u
#define DAC_DAC_PD_MODE_EN_DAC_PD_MODE_BEN_Msk  (0x1u << 1u)
#define DAC_DAC_PD_MODE_EN_DAC_PD_MODE_AEN_Pos  0u
#define DAC_DAC_PD_MODE_EN_DAC_PD_MODE_AEN_Msk  (0x1u << 0u)
#define DAC_DAC_DATA_A_DAC_DATA_A_Pos  0u
#define DAC_DAC_DATA_A_DAC_DATA_A_Msk  (0xfffu << 0u)
#define DAC_DAC_DATA_B_DAC_DATA_B_Pos  0u
#define DAC_DAC_DATA_B_DAC_DATA_B_Msk  (0xfffu << 0u)
#define DAC_DAC_DATA_C_DAC_DATA_C_Pos  0u
#define DAC_DAC_DATA_C_DAC_DATA_C_Msk  (0xfffu << 0u)
#define DAC_DAC_CTRL_VERID_DAC_CTRL_VERID_Pos  0u
#define DAC_DAC_CTRL_VERID_DAC_CTRL_VERID_Msk  (0xffffffffu << 0u)

typedef struct {   /* SD/SDIO host, Synopsys DesignWare Mobile Storage (DS §5.5, p.285-325; FIFO depth 128, data FIFO window from +0 */
  __IO uint32_t CTRL;                        /* 0x00 Control registers. DS §5.5.5.1 p.305. Note: H/S Represents hardware reset and software reset Reset 0x0 (DS). */
  __IO uint32_t PWREN;                       /* 0x04 Power-on enable register. DS §5.5.5.2 p.307. Reset 0x0 (DS). */
  __IO uint32_t CLKDIV;                      /* 0x08 Clock divider register. DS §5.5.5.3 p.307. Reset 0x0 (DS). */
  __I  uint32_t CLKSRC;                      /* 0x0c Clock source register. DS §5.5.5.4 p.307. Reset 0x0 (DS). */
  __IO uint32_t CLKENA;                      /* 0x10 Clock enable register. DS §5.5.5.5 p.309. Reset 0x0 (DS). */
  __IO uint32_t TMOUT;                       /* 0x14 Timeout register. DS §5.5.5.6 p.309. Reset 0xffffff40 (DS). */
  __IO uint32_t CTYPE;                       /* 0x18 Card Type Register. DS §5.5.5.7 p.309. Reset 0x0 (DS). */
  __IO uint32_t BLKSIZ;                      /* 0x1c Block size register. DS §5.5.5.8 p.310. Reset 0x200 (DS). */
  __IO uint32_t BYTCNT;                      /* 0x20 Byte Count Register. DS §5.5.5.9 p.310. Reset 0x200 (DS). */
  __IO uint32_t INTMASK;                     /* 0x24 Interrupt Mask Register. DS §5.5.5.10 p.311. Reset 0x0 (DS). */
  __IO uint32_t CMDARG;                      /* 0x28 Instruction content segment register. DS §5.5.5.11 p.311. Reset 0x0 (DS). */
  __IO uint32_t CMD;                         /* 0x2c Command register. DS §5.5.5.12 p.311. Reset 0x20000000 (DS). */
  __I  uint32_t RESP0;                       /* 0x30 Response reply register 0. DS §5.5.5.13 p.314. Reset 0x0 (DS). */
  __I  uint32_t RESP1;                       /* 0x34 Response reply register 1. DS §5.5.5.14 p.315. Reset 0x0 (DS). */
  __I  uint32_t RESP2;                       /* 0x38 Response reply register 2. DS §5.5.5.15 p.315. Reset 0x0 (DS). */
  __I  uint32_t RESP3;                       /* 0x3c Response reply register 3. DS §5.5.5.16 p.315. Reset 0x0 (DS). */
  __I  uint32_t MINTSTS;                     /* 0x40 Interrupt Mask Register. DS §5.5.5.17 p.315. Note: MISTATUS = RINTSTS and INTMASK Reset 0x0 (DS). */
  __IO uint32_t RINTSTS;                     /* 0x44 Interrupt Status Register. DS §5.5.5.18 p.317. Reset 0x0 (DS). */
  __I  uint32_t STATUS;                      /* 0x48 Status register, mainly used to check the. DS §5.5.5.19 p.318. Reset 0x406 (DS). */
  __IO uint32_t FIFOTH;                      /* 0x4c FIFO Threshold Register. DS §5.5.5.20 p.319. Bit 27 is not listed in the datasheet (reserved). Reset 0x7f0000  */
  __I  uint32_t CDETECT;                     /* 0x50 Card detection register. DS §5.5.5.21 p.321. */
  __I  uint32_t WRTPRT;                      /* 0x54 Write protection register. DS §5.5.5.22 p.321. */
  __I  uint32_t RESERVED_58[1];              /* 0x58-0x5b */
  __I  uint32_t TCBCNT;                      /* 0x5c CIU Byte transmitted by the module Number. DS §5.5.5.23 p.321. Reset 0x0 (DS). */
  __I  uint32_t TBBCNT;                      /* 0x60 Host with BIU_FIFO byte of interaction data. DS §5.5.5.24 p.321. Reset 0x0 (DS). */
  __IO uint32_t DEBNCE;                      /* 0x64 Card detection bounce register ( unit is. DS §5.5.5.25 p.322. Reset 0xffffff (DS). */
  __IO uint32_t USRID;                       /* 0x68 User ID Register. DS §5.5.5.26 p.323. Reset 0x45700311 (DS). */
  __I  uint32_t VERID;                       /* 0x6c Soft core version ID register. DS §5.5.5.27 p.323. Reset 0x5342250a (DS). */
  __I  uint32_t HCON;                        /* 0x70 Hardware Configuration Registers. DS §5.5.5.28 p.323. Reset 0xc44cc1 (DS). */
  __I  uint32_t RESERVED_74[1];              /* 0x74-0x77 */
  __IO uint32_t RST_n;                       /* 0x78 Hard reset register. DS §5.5.5.29 p.323. Reset 0x1 (DS). */
  __I  uint32_t RESERVED_7C[33];             /* 0x7c-0xff */
  __IO uint32_t CardThrCtl;                  /* 0x100 Card read threshold enable register. DS §5.5.5.30 p.323. Reset 0x0 (DS). */
  __IO uint32_t Back_end_power;              /* 0x104 Back_end Power register. DS §5.5.5.31 p.325. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_108[2];             /* 0x108-0x10f */
  __IO uint32_t ENABLE_SHIFT;                /* 0x110 Conversion Phase Control Register. DS §5.5.5.32 p.325. Reset 0x0 (DS). */
  __I  uint32_t RESERVED_114[59];            /* 0x114-0x1ff */
  __IO uint32_t DATA;                        /* 0x200 DS §5.5.5.33 p.325. Reset 0x0 (DS). */
} SDIO_Type;   /* 0x204 bytes */
#define SDIO_CTRL_enable_OD_pullup_Pos  24u
#define SDIO_CTRL_enable_OD_pullup_Msk  (0x1u << 24u)
#define SDIO_CTRL_card_voltage_b_Pos  20u
#define SDIO_CTRL_card_voltage_b_Msk  (0xfu << 20u)
#define SDIO_CTRL_card_voltage_a_Pos  16u
#define SDIO_CTRL_card_voltage_a_Msk  (0xfu << 16u)
#define SDIO_CTRL_ceata_device_interrupt_status_Pos  11u
#define SDIO_CTRL_ceata_device_interrupt_status_Msk  (0x1u << 11u)
#define SDIO_CTRL_send_auto_stop_ccsd_Pos  10u
#define SDIO_CTRL_send_auto_stop_ccsd_Msk  (0x1u << 10u)
#define SDIO_CTRL_send_ccsd_Pos  9u
#define SDIO_CTRL_send_ccsd_Msk  (0x1u << 9u)
#define SDIO_CTRL_abort_read_data_Pos  8u
#define SDIO_CTRL_abort_read_data_Msk  (0x1u << 8u)
#define SDIO_CTRL_send_irq_response_Pos  7u
#define SDIO_CTRL_send_irq_response_Msk  (0x1u << 7u)
#define SDIO_CTRL_read_wait_Pos  6u
#define SDIO_CTRL_read_wait_Msk  (0x1u << 6u)
#define SDIO_CTRL_dma_enable_Pos  5u
#define SDIO_CTRL_dma_enable_Msk  (0x1u << 5u)
#define SDIO_CTRL_int_enable_Pos  4u
#define SDIO_CTRL_int_enable_Msk  (0x1u << 4u)
#define SDIO_CTRL_dma_reset_Pos  2u
#define SDIO_CTRL_dma_reset_Msk  (0x1u << 2u)
#define SDIO_CTRL_fifo_reset_Pos  1u
#define SDIO_CTRL_fifo_reset_Msk  (0x1u << 1u)
#define SDIO_CTRL_controller_reset_Pos  0u
#define SDIO_CTRL_controller_reset_Msk  (0x1u << 0u)
#define SDIO_PWREN_power_enable_Pos  0u
#define SDIO_PWREN_power_enable_Msk  (0x1u << 0u)
#define SDIO_CLKDIV_clk_divider0_Pos  0u
#define SDIO_CLKDIV_clk_divider0_Msk  (0xffu << 0u)
#define SDIO_CLKSRC_clk_source_Pos  0u
#define SDIO_CLKSRC_clk_source_Msk  (0xffffffffu << 0u)
#define SDIO_CLKENA_cclk_low_power_Pos  16u
#define SDIO_CLKENA_cclk_low_power_Msk  (0xffffu << 16u)
#define SDIO_CLKENA_cclk_enable_Pos  0u
#define SDIO_CLKENA_cclk_enable_Msk  (0xffffu << 0u)
#define SDIO_TMOUT_data_timeout_Pos  8u
#define SDIO_TMOUT_data_timeout_Msk  (0xffffffu << 8u)
#define SDIO_TMOUT_response_timeout_Pos  0u
#define SDIO_TMOUT_response_timeout_Msk  (0xffu << 0u)
#define SDIO_CTYPE_card_width1_Pos  16u
#define SDIO_CTYPE_card_width1_Msk  (0xffffu << 16u)
#define SDIO_CTYPE_card_width0_Pos  0u
#define SDIO_CTYPE_card_width0_Msk  (0xffffu << 0u)
#define SDIO_BLKSIZ_block_size_Pos  0u
#define SDIO_BLKSIZ_block_size_Msk  (0xffffu << 0u)
#define SDIO_BYTCNT_byte_count_Pos  0u
#define SDIO_BYTCNT_byte_count_Msk  (0xffffffffu << 0u)
#define SDIO_INTMASK_sdio_int_mask_Pos  16u
#define SDIO_INTMASK_sdio_int_mask_Msk  (0xffffu << 16u)
#define SDIO_INTMASK_int_mask_Pos  0u
#define SDIO_INTMASK_int_mask_Msk  (0xffffu << 0u)
#define SDIO_CMDARG_cmd_arg_Pos  0u
#define SDIO_CMDARG_cmd_arg_Msk  (0xffffffffu << 0u)
#define SDIO_CMD_start_cmd_Pos  31u
#define SDIO_CMD_start_cmd_Msk  (0x1u << 31u)
#define SDIO_CMD_use_hold_reg_Pos  29u
#define SDIO_CMD_use_hold_reg_Msk  (0x1u << 29u)
#define SDIO_CMD_volt_switch_Pos  28u
#define SDIO_CMD_volt_switch_Msk  (0x1u << 28u)
#define SDIO_CMD_boot_mode_Pos  27u
#define SDIO_CMD_boot_mode_Msk  (0x1u << 27u)
#define SDIO_CMD_disable_boot_Pos  26u
#define SDIO_CMD_disable_boot_Msk  (0x1u << 26u)
#define SDIO_CMD_expect_boot_ack_Pos  25u
#define SDIO_CMD_expect_boot_ack_Msk  (0x1u << 25u)
#define SDIO_CMD_enable_boot_Pos  24u
#define SDIO_CMD_enable_boot_Msk  (0x1u << 24u)
#define SDIO_CMD_ccs_expected_Pos  23u
#define SDIO_CMD_ccs_expected_Msk  (0x1u << 23u)
#define SDIO_CMD_read_ceata_device_Pos  22u
#define SDIO_CMD_read_ceata_device_Msk  (0x1u << 22u)
#define SDIO_CMD_update_clock_registers_only_Pos  21u
#define SDIO_CMD_update_clock_registers_only_Msk  (0x1u << 21u)
#define SDIO_CMD_card_number_Pos  16u
#define SDIO_CMD_card_number_Msk  (0x1fu << 16u)
#define SDIO_CMD_send_initialization_Pos  15u
#define SDIO_CMD_send_initialization_Msk  (0x1u << 15u)
#define SDIO_CMD_stop_abort_cmd_Pos  14u
#define SDIO_CMD_stop_abort_cmd_Msk  (0x1u << 14u)
#define SDIO_CMD_wait_prvdata_complete_Pos  13u
#define SDIO_CMD_wait_prvdata_complete_Msk  (0x1u << 13u)
#define SDIO_CMD_send_auto_stop_Pos  12u
#define SDIO_CMD_send_auto_stop_Msk  (0x1u << 12u)
#define SDIO_CMD_transfer_mode_Pos  11u
#define SDIO_CMD_transfer_mode_Msk  (0x1u << 11u)
#define SDIO_CMD_read_write_Pos  10u
#define SDIO_CMD_read_write_Msk  (0x1u << 10u)
#define SDIO_CMD_data_expected_Pos  9u
#define SDIO_CMD_data_expected_Msk  (0x1u << 9u)
#define SDIO_CMD_check_response_crc_Pos  8u
#define SDIO_CMD_check_response_crc_Msk  (0x1u << 8u)
#define SDIO_CMD_response_length_Pos  7u
#define SDIO_CMD_response_length_Msk  (0x1u << 7u)
#define SDIO_CMD_response_expect_Pos  6u
#define SDIO_CMD_response_expect_Msk  (0x1u << 6u)
#define SDIO_CMD_cmd_index_Pos  0u
#define SDIO_CMD_cmd_index_Msk  (0x3fu << 0u)
#define SDIO_RESP0_response0_Pos  0u
#define SDIO_RESP0_response0_Msk  (0xffffffffu << 0u)
#define SDIO_RESP1_response1_Pos  0u
#define SDIO_RESP1_response1_Msk  (0xffffffffu << 0u)
#define SDIO_RESP2_response2_Pos  0u
#define SDIO_RESP2_response2_Msk  (0xffffffffu << 0u)
#define SDIO_RESP3_response3_Pos  0u
#define SDIO_RESP3_response3_Msk  (0xffffffffu << 0u)
#define SDIO_MINTSTS_sdio_interrupt_Pos  16u
#define SDIO_MINTSTS_sdio_interrupt_Msk  (0xffffu << 16u)
#define SDIO_MINTSTS_int_status_Pos  0u
#define SDIO_MINTSTS_int_status_Msk  (0xffffu << 0u)
#define SDIO_RINTSTS_sdio_interrupt_Pos  16u
#define SDIO_RINTSTS_sdio_interrupt_Msk  (0xffffu << 16u)
#define SDIO_RINTSTS_int_status_Pos  0u
#define SDIO_RINTSTS_int_status_Msk  (0xffffu << 0u)
#define SDIO_STATUS_dma_req_Pos  31u
#define SDIO_STATUS_dma_req_Msk  (0x1u << 31u)
#define SDIO_STATUS_dma_ack_Pos  30u
#define SDIO_STATUS_dma_ack_Msk  (0x1u << 30u)
#define SDIO_STATUS_fifo_count_Pos  17u
#define SDIO_STATUS_fifo_count_Msk  (0x1fffu << 17u)
#define SDIO_STATUS_response_index_Pos  11u
#define SDIO_STATUS_response_index_Msk  (0x3fu << 11u)
#define SDIO_STATUS_data_state_mc_busy_Pos  10u
#define SDIO_STATUS_data_state_mc_busy_Msk  (0x1u << 10u)
#define SDIO_STATUS_data_busy_Pos  9u
#define SDIO_STATUS_data_busy_Msk  (0x1u << 9u)
#define SDIO_STATUS_data_3_status_Pos  8u
#define SDIO_STATUS_data_3_status_Msk  (0x1u << 8u)
#define SDIO_STATUS_command_fsm_states_Pos  4u
#define SDIO_STATUS_command_fsm_states_Msk  (0xfu << 4u)
#define SDIO_STATUS_fifo_full_Pos  3u
#define SDIO_STATUS_fifo_full_Msk  (0x1u << 3u)
#define SDIO_STATUS_fifo_empty_Pos  2u
#define SDIO_STATUS_fifo_empty_Msk  (0x1u << 2u)
#define SDIO_STATUS_fifo_tx_watermark_Pos  1u
#define SDIO_STATUS_fifo_tx_watermark_Msk  (0x1u << 1u)
#define SDIO_STATUS_fifo_rx_watermark_Pos  0u
#define SDIO_STATUS_fifo_rx_watermark_Msk  (0x1u << 0u)
#define SDIO_FIFOTH_DW_DMA_Multiple_Transaction_Size_Pos  28u
#define SDIO_FIFOTH_DW_DMA_Multiple_Transaction_Size_Msk  (0x7u << 28u)
#define SDIO_FIFOTH_RX_WMark_Pos  16u
#define SDIO_FIFOTH_RX_WMark_Msk  (0x7ffu << 16u)
#define SDIO_FIFOTH_TX_WMark_Pos  0u
#define SDIO_FIFOTH_TX_WMark_Msk  (0xfffu << 0u)
#define SDIO_CDETECT_card_detect_n_Pos  0u
#define SDIO_CDETECT_card_detect_n_Msk  (0x3fffffffu << 0u)
#define SDIO_WRTPRT_write_protect_Pos  0u
#define SDIO_WRTPRT_write_protect_Msk  (0x3fffffffu << 0u)
#define SDIO_TCBCNT_trans_card_byte_count_Pos  0u
#define SDIO_TCBCNT_trans_card_byte_count_Msk  (0xffffffffu << 0u)
#define SDIO_TBBCNT_trans_fifo_byte_count_Pos  0u
#define SDIO_TBBCNT_trans_fifo_byte_count_Msk  (0xffffffffu << 0u)
#define SDIO_DEBNCE_debounce_count_Pos  0u
#define SDIO_DEBNCE_debounce_count_Msk  (0xffffffu << 0u)
#define SDIO_USRID_usrid_Pos  0u
#define SDIO_USRID_usrid_Msk  (0xffffffffu << 0u)
#define SDIO_VERID_Verid_Pos  0u
#define SDIO_VERID_Verid_Msk  (0xffffffffu << 0u)
#define SDIO_HCON_hcon_Pos  0u
#define SDIO_HCON_hcon_Msk  (0xffffffffu << 0u)
#define SDIO_RST_n_card_reset_Pos  0u
#define SDIO_RST_n_card_reset_Msk  (0xffffu << 0u)
#define SDIO_CardThrCtl_CardRdThreshold_Pos  16u
#define SDIO_CardThrCtl_CardRdThreshold_Msk  (0xfffu << 16u)
#define SDIO_CardThrCtl_BsyClrIntEn_Pos  1u
#define SDIO_CardThrCtl_BsyClrIntEn_Msk  (0x1u << 1u)
#define SDIO_CardThrCtl_CardRdThrEn_Pos  0u
#define SDIO_CardThrCtl_CardRdThrEn_Msk  (0x1u << 0u)
#define SDIO_Back_end_power_back_end_power_Pos  0u
#define SDIO_Back_end_power_back_end_power_Msk  (0xffffu << 0u)
#define SDIO_ENABLE_SHIFT_Enable_shift_Pos  0u
#define SDIO_ENABLE_SHIFT_Enable_shift_Msk  (0xffffffffu << 0u)
#define SDIO_DATA_FIFO_Pos  0u
#define SDIO_DATA_FIFO_Msk  (0xffffffffu << 0u)

typedef struct {   /* Audio codec control registers, byte-wide (DS §6.5, Register Table 26, p.443-472; base 0x1600_09C0, inside the  */
  __I  uint8_t  SR1;                         /* 0x00 Status Register. DS §6.5.2.1 p.443. Reset 0x0 (DS). */
  __I  uint8_t  SR2;                         /* 0x01 Status Register. DS §6.5.2.2 p.445. Reset 0x0 (DS). */
  __I  uint8_t  RESERVED_2[5];               /* 0x2-0x6 */
  __I  uint8_t  MR;                          /* 0x07 ADC Mute control. DS §6.5.2.3 p.445. Reset 0x0 (DS). */
  __IO uint8_t  AICR_DAC;                    /* 0x08 DAC Audio interface control. DS §6.5.2.4 p.446. Reset 0xd3 (DS). */
  __IO uint8_t  AICR_ADC;                    /* 0x09 ADC Audio interface control. DS §6.5.2.5 p.447. Reset 0xd3 (DS). */
  __I  uint8_t  RESERVED_A[1];               /* 0xa-0xa */
  __IO uint8_t  CR_MIC1;                     /* 0x0b MIC1 Control registers. DS §6.5.2.6 p.448. Reset 0x30 (DS). */
  __IO uint8_t  CR_MIC2;                     /* 0x0c MIC2 Control registers. DS §6.5.2.7 p.449. Reset 0x30 (DS). */
  __IO uint8_t  CR_DAC;                      /* 0x0d DAC Control registers. DS §6.5.2.8 p.449. Reset 0xb0 (DS). */
  __I  uint8_t  RESERVED_E[1];               /* 0xe-0xe */
  __IO uint8_t  CR_ADC;                      /* 0x0f ADC Control registers. DS §6.5.2.9 p.449. Reset 0xb0 (DS). */
  __IO uint8_t  CR_MIX;                      /* 0x10 Digital Aliasing Control Register. DS §6.5.2.10 p.450. Window onto four indirect mixer registers (address in m */
  __IO uint8_t  DR_MIX;                      /* 0x11 Digital Aliasing Control Indirect. DS §6.5.2.11 p.452. Reset 0x0 (DS). */
  __IO uint8_t  CR_VIC;                      /* 0x12 Codec sleep Mode Control Register. DS §6.5.2.12 p.454. Reset 0xf (DS). */
  __IO uint8_t  CR_CK;                       /* 0x13 MCLK Control registers. DS §6.5.2.13 p.454. Reset 0x40 (DS). */
  __IO uint8_t  FCR_DAC;                     /* 0x14 DAC Sampling Clock Configuration. DS §6.5.2.14 p.454. Reset 0x0 (DS). */
  __IO uint8_t  SFCCR_DAC;                   /* 0x15 DS §6.5.2.15 p.454. Reset 0x0 (DS). */
  __IO uint8_t  SFFCR_DAC;                   /* 0x16 DS §6.5.2.16 p.455. Reset 0x0 (DS). */
  __IO uint8_t  FCR_ADC;                     /* 0x17 ADC Sampling Clock Configuration. DS §6.5.2.17 p.456. Reset 0x0 (DS). */
  __IO uint8_t  CR_TIMER_h;                  /* 0x18 Counter high 8 bits. DS §6.5.2.18 p.456. Reset 0x0 (DS). */
  __IO uint8_t  CR_TIMER_l;                  /* 0x19 Counter lower 8 bits. DS §6.5.2.19 p.456. Reset 0x0 (DS). */
  __IO uint8_t  ICR;                         /* 0x1a Interrupt Control Register. DS §6.5.2.20 p.456. Reset 0x0 (DS). */
  __IO uint8_t  IMR;                         /* 0x1b Interrupt Mask Control registers. DS §6.5.2.21 p.458. Reset 0xff (DS). */
  __IO uint8_t  IFR;                         /* 0x1c Interrupt flag definition. DS §6.5.2.22 p.458. Reset 0x0 (DS). */
  __IO uint8_t  IMR2;                        /* 0x1d Timer flag MASK Control registers. DS §6.5.2.23 p.458. Reset 0xff (DS). */
  __IO uint8_t  IFR2;                        /* 0x1e Timer flag definition. DS §6.5.2.24 p.459. Reset 0x0 (DS). */
  __IO uint8_t  GCR_DACL;                    /* 0x1f DAC Gain Control. DS §6.5.2.25 p.460. Reset 0x0 (DS). */
  __IO uint8_t  GCR_DACR;                    /* 0x20 DS §6.5.2.26 p.460. Reset 0x0 (DS). */
  __I  uint8_t  RESERVED_21[2];              /* 0x21-0x22 */
  __IO uint8_t  GCR_MIC1;                    /* 0x23 Mic1 Gain Control. DS §6.5.2.27 p.462. Reset 0x0 (DS). */
  __I  uint8_t  RESERVED_24[1];              /* 0x24-0x24 */
  __IO uint8_t  GCR_ADCL;                    /* 0x25 ADC Gain Control. DS §6.5.2.28 p.462. Reset 0x0 (DS). */
  __IO uint8_t  GCR_ADCR;                    /* 0x26 DS §6.5.2.29 p.462. Reset 0x0 (DS). */
  __IO uint8_t  GCR_MIXDACL;                 /* 0x27 Aliasing DAC Gain Control. DS §6.5.2.30 p.463. Reset 0x0 (DS). */
  __IO uint8_t  GCR_MIXDACR;                 /* 0x28 DS §6.5.2.31 p.464. Reset 0x0 (DS). */
  __IO uint8_t  GCR_MIXADCL;                 /* 0x29 Aliasing ADC Gain Control. DS §6.5.2.32 p.464. Reset 0x0 (DS). */
  __IO uint8_t  GCR_MIXADCR;                 /* 0x2a DS §6.5.2.33 p.465. Reset 0x0 (DS). */
  __IO uint8_t  CR_DAC_AGC;                  /* 0x2b DAC Gain Control Register. DS §6.5.2.34 p.466. Reset 0x0 (DS). */
  __IO uint8_t  DR_DAC_AGC;                  /* 0x2c DAC AGC Read and write data of indirect. DS §6.5.2.35 p.466. Indirect DAC1 DRC registers (index in CR_DAC_AGC) */
  __I  uint8_t  RESERVED_2D[2];              /* 0x2d-0x2e */
  __IO uint8_t  CR_ADC_AGC;                  /* 0x2f ADC Gain Control Register. DS §6.5.2.36 p.468. Reset 0x0 (DS). */
  __IO uint8_t  DR_ADC_AGC;                  /* 0x30 ADC AGC Read and write data of indirect. DS §6.5.2.37 p.468. Indirect ADC AGC registers (index in CR_ADC_AGC): */
} CODEC_Type;   /* 0x31 bytes */
#define CODEC_SR1_pon_ack_Pos  7u
#define CODEC_SR1_pon_ack_Msk  (0x1u << 7u)
#define CODEC_SR1_irq_ack_Pos  6u
#define CODEC_SR1_irq_ack_Msk  (0x1u << 6u)
#define CODEC_SR1_dac_locked_Pos  4u
#define CODEC_SR1_dac_locked_Msk  (0x1u << 4u)
#define CODEC_SR2_dac_unknown_fs_Pos  4u
#define CODEC_SR2_dac_unknown_fs_Msk  (0x1u << 4u)
#define CODEC_MR_adc_mute_Pos  3u
#define CODEC_MR_adc_mute_Msk  (0x3u << 3u)
#define CODEC_MR_dac_mute_Pos  0u
#define CODEC_MR_dac_mute_Msk  (0x3u << 0u)
#define CODEC_AICR_DAC_dac_adwl_Pos  6u
#define CODEC_AICR_DAC_dac_adwl_Msk  (0x3u << 6u)
#define CODEC_AICR_DAC_dac_slave_Pos  5u
#define CODEC_AICR_DAC_dac_slave_Msk  (0x1u << 5u)
#define CODEC_AICR_DAC_sb_aicr_dac_Pos  4u
#define CODEC_AICR_DAC_sb_aicr_dac_Msk  (0x1u << 4u)
#define CODEC_AICR_DAC_dac_audioif_Pos  0u
#define CODEC_AICR_DAC_dac_audioif_Msk  (0x3u << 0u)
#define CODEC_AICR_ADC_adc_adwl_Pos  6u
#define CODEC_AICR_ADC_adc_adwl_Msk  (0x3u << 6u)
#define CODEC_AICR_ADC_adc_slave_Pos  5u
#define CODEC_AICR_ADC_adc_slave_Msk  (0x1u << 5u)
#define CODEC_AICR_ADC_sb_aicr_adc_Pos  4u
#define CODEC_AICR_ADC_sb_aicr_adc_Msk  (0x1u << 4u)
#define CODEC_AICR_ADC_adc_audioif_Pos  0u
#define CODEC_AICR_ADC_adc_audioif_Msk  (0x3u << 0u)
#define CODEC_CR_MIC1_micdiff1_Pos  6u
#define CODEC_CR_MIC1_micdiff1_Msk  (0x1u << 6u)
#define CODEC_CR_MIC1_sb_micbias1_Pos  5u
#define CODEC_CR_MIC1_sb_micbias1_Msk  (0x1u << 5u)
#define CODEC_CR_MIC1_sb_mic1_Pos  4u
#define CODEC_CR_MIC1_sb_mic1_Msk  (0x1u << 4u)
#define CODEC_CR_MIC1_micbias1_v_Pos  3u
#define CODEC_CR_MIC1_micbias1_v_Msk  (0x1u << 3u)
#define CODEC_CR_MIC2_micdiff2_Pos  6u
#define CODEC_CR_MIC2_micdiff2_Msk  (0x1u << 6u)
#define CODEC_CR_DAC_dac_soft_mute_Pos  7u
#define CODEC_CR_DAC_dac_soft_mute_Msk  (0x1u << 7u)
#define CODEC_CR_DAC_sb_dac_Pos  4u
#define CODEC_CR_DAC_sb_dac_Msk  (0x1u << 4u)
#define CODEC_CR_DAC_dac_zero_n_Pos  0u
#define CODEC_CR_DAC_dac_zero_n_Msk  (0x1u << 0u)
#define CODEC_CR_ADC_adc_soft_mute_Pos  7u
#define CODEC_CR_ADC_adc_soft_mute_Msk  (0x1u << 7u)
#define CODEC_CR_ADC_adc_dmic_sel_Pos  6u
#define CODEC_CR_ADC_adc_dmic_sel_Msk  (0x1u << 6u)
#define CODEC_CR_ADC_adc_left_only_Pos  5u
#define CODEC_CR_ADC_adc_left_only_Msk  (0x1u << 5u)
#define CODEC_CR_ADC_sb_adc_Pos  4u
#define CODEC_CR_ADC_sb_adc_Msk  (0x1u << 4u)
#define CODEC_CR_MIX_mix_en_Pos  7u
#define CODEC_CR_MIX_mix_en_Msk  (0x1u << 7u)
#define CODEC_CR_MIX_mix_load_Pos  6u
#define CODEC_CR_MIX_mix_load_Msk  (0x1u << 6u)
#define CODEC_CR_MIX_mix_add_Pos  0u
#define CODEC_CR_MIX_mix_add_Msk  (0x3fu << 0u)
#define CODEC_DR_MIX_mix_data_Pos  0u
#define CODEC_DR_MIX_mix_data_Msk  (0xffu << 0u)
#define CODEC_CR_VIC_sb_sleep_Pos  1u
#define CODEC_CR_VIC_sb_sleep_Msk  (0x1u << 1u)
#define CODEC_CR_VIC_sb_Pos  0u
#define CODEC_CR_VIC_sb_Msk  (0x1u << 0u)
#define CODEC_CR_CK_mclk_div_Pos  6u
#define CODEC_CR_CK_mclk_div_Msk  (0x1u << 6u)
#define CODEC_CR_CK_shutdown_clock_Pos  4u
#define CODEC_CR_CK_shutdown_clock_Msk  (0x1u << 4u)
#define CODEC_CR_CK_crystal_Pos  0u
#define CODEC_CR_CK_crystal_Msk  (0xfu << 0u)
#define CODEC_FCR_DAC_dac_freq_Pos  0u
#define CODEC_FCR_DAC_dac_freq_Msk  (0xfu << 0u)
#define CODEC_SFCCR_DAC_dac_freq_valid_Pos  7u
#define CODEC_SFCCR_DAC_dac_freq_valid_Msk  (0x1u << 7u)
#define CODEC_SFCCR_DAC_dac_freq_adj_h_Pos  0u
#define CODEC_SFCCR_DAC_dac_freq_adj_h_Msk  (0x7fu << 0u)
#define CODEC_SFFCR_DAC_dac_freq_adj_l_Pos  0u
#define CODEC_SFFCR_DAC_dac_freq_adj_l_Msk  (0xffu << 0u)
#define CODEC_FCR_ADC_adc_hpf_Pos  6u
#define CODEC_FCR_ADC_adc_hpf_Msk  (0x1u << 6u)
#define CODEC_FCR_ADC_adc_wnf_Pos  4u
#define CODEC_FCR_ADC_adc_wnf_Msk  (0x3u << 4u)
#define CODEC_FCR_ADC_adc_freq_Pos  0u
#define CODEC_FCR_ADC_adc_freq_Msk  (0xfu << 0u)
#define CODEC_CR_TIMER_h_count_h_Pos  0u
#define CODEC_CR_TIMER_h_count_h_Msk  (0xffu << 0u)
#define CODEC_CR_TIMER_l_count_l_Pos  0u
#define CODEC_CR_TIMER_l_count_l_Msk  (0xffu << 0u)
#define CODEC_ICR_int_form_Pos  6u
#define CODEC_ICR_int_form_Msk  (0x3u << 6u)
#define CODEC_IMR_adas_lock_mask_Pos  7u
#define CODEC_IMR_adas_lock_mask_Msk  (0x1u << 7u)
#define CODEC_IMR_adc_mute_mask_Pos  2u
#define CODEC_IMR_adc_mute_mask_Msk  (0x1u << 2u)
#define CODEC_IMR_dac_mute_mask_Pos  0u
#define CODEC_IMR_dac_mute_mask_Msk  (0x1u << 0u)
#define CODEC_IFR_adas_lock_event_Pos  7u
#define CODEC_IFR_adas_lock_event_Msk  (0x1u << 7u)
#define CODEC_IFR_adc_mute_event_Pos  2u
#define CODEC_IFR_adc_mute_event_Msk  (0x1u << 2u)
#define CODEC_IFR_dac_mute_event_Pos  0u
#define CODEC_IFR_dac_mute_event_Msk  (0x1u << 0u)
#define CODEC_IMR2_TIMER_END_MASK_Pos  4u
#define CODEC_IMR2_TIMER_END_MASK_Msk  (0x1u << 4u)
#define CODEC_IFR2_TIMER_END_Pos  4u
#define CODEC_IFR2_TIMER_END_Msk  (0x1u << 4u)
#define CODEC_GCR_DACL_lrgod_Pos  7u
#define CODEC_GCR_DACL_lrgod_Msk  (0x1u << 7u)
#define CODEC_GCR_DACL_godl_Pos  0u
#define CODEC_GCR_DACL_godl_Msk  (0x3fu << 0u)
#define CODEC_GCR_DACR_godr_Pos  0u
#define CODEC_GCR_DACR_godr_Msk  (0x3fu << 0u)
#define CODEC_GCR_MIC1_gim1_Pos  0u
#define CODEC_GCR_MIC1_gim1_Msk  (0x7u << 0u)
#define CODEC_GCR_ADCL_lrgid_Pos  7u
#define CODEC_GCR_ADCL_lrgid_Msk  (0x1u << 7u)
#define CODEC_GCR_ADCL_gidl_Pos  0u
#define CODEC_GCR_ADCL_gidl_Msk  (0x3fu << 0u)
#define CODEC_GCR_ADCR_gidr_Pos  0u
#define CODEC_GCR_ADCR_gidr_Msk  (0x3fu << 0u)
#define CODEC_GCR_MIXDACL_lrgomix_Pos  7u
#define CODEC_GCR_MIXDACL_lrgomix_Msk  (0x1u << 7u)
#define CODEC_GCR_MIXDACL_gomixl_Pos  0u
#define CODEC_GCR_MIXDACL_gomixl_Msk  (0x3fu << 0u)
#define CODEC_GCR_MIXDACR_gomixr_Pos  0u
#define CODEC_GCR_MIXDACR_gomixr_Msk  (0x3fu << 0u)
#define CODEC_GCR_MIXADCL_lrgimix_Pos  7u
#define CODEC_GCR_MIXADCL_lrgimix_Msk  (0x1u << 7u)
#define CODEC_GCR_MIXADCL_gimixl_Pos  0u
#define CODEC_GCR_MIXADCL_gimixl_Msk  (0x3fu << 0u)
#define CODEC_GCR_MIXADCR_gimixr_Pos  0u
#define CODEC_GCR_MIXADCR_gimixr_Msk  (0x3fu << 0u)
#define CODEC_CR_DAC_AGC_dac_agc_en_Pos  7u
#define CODEC_CR_DAC_AGC_dac_agc_en_Msk  (0x1u << 7u)
#define CODEC_CR_DAC_AGC_dac_agc_load_Pos  6u
#define CODEC_CR_DAC_AGC_dac_agc_load_Msk  (0x1u << 6u)
#define CODEC_CR_DAC_AGC_dac_agc_add_Pos  0u
#define CODEC_CR_DAC_AGC_dac_agc_add_Msk  (0x3fu << 0u)
#define CODEC_DR_DAC_AGC_dac_agc_data_Pos  0u
#define CODEC_DR_DAC_AGC_dac_agc_data_Msk  (0xffu << 0u)
#define CODEC_CR_ADC_AGC_adc_agc_en_Pos  7u
#define CODEC_CR_ADC_AGC_adc_agc_en_Msk  (0x1u << 7u)
#define CODEC_CR_ADC_AGC_adc_agc_load_Pos  6u
#define CODEC_CR_ADC_AGC_adc_agc_load_Msk  (0x1u << 6u)
#define CODEC_CR_ADC_AGC_adc_agc_add_Pos  0u
#define CODEC_CR_ADC_AGC_adc_agc_add_Msk  (0x3fu << 0u)
#define CODEC_DR_ADC_AGC_adc_agc_data_Pos  0u
#define CODEC_DR_ADC_AGC_adc_agc_data_Msk  (0xffu << 0u)

typedef struct {   /* Programmable interrupt controller, 64 sources of which Table 30 assigns 38 (DS §4.7, p.166-187; Register Table */
  __IO uint32_t PIC_MODE;                    /* 0x00 Trigger mode select, sources 0-31. DS §4.7.6.1 p.172. FW: 0 reads, 2 writes. Bit n is source 0+n (sources 0-31 */
  __IO uint32_t PIC_PO;                      /* 0x04 Trigger polarity select, sources 0-31. DS §4.7.6.2 p.172. FW: 0 reads, 2 writes. Bit n is source 0+n (sources  */
  __IO uint32_t PIC_MASK;                    /* 0x08 Interrupt mask, sources 0-31. DS §4.7.6.3 p.173. FW: 2 reads, 4 writes. Bit n is source 0+n (sources 0-31). Th */
  __IO uint32_t PIC_VECTOR;                  /* 0x0c Interrupt vector base address. DS §4.7.6.4 p.174. Source x is delivered to the CPU as vector x + vector0; with */
  __O  uint32_t PIC_COW1;                    /* 0x10 End of interruption. DS §4.7.6.5 p.174. The hand-maintained entry this replaced guessed a 'clear-on-write ack' */
  __IO uint32_t PIC_PRIOR0_3;                /* 0x14 Priority counter initial values, sources 0-3. DS §4.7.6.6 p.174. Sources 0-3 are unassigned, TIMER_1, TIMER_2, */
  __IO uint32_t PIC_PRIOR4_7;                /* 0x18 Priority counter initial values, sources 4-7. DS §4.7.6.7 p.176. Sources 4-7 are TIMER_4, TIMER_5, TIMER_6, I2 */
  __IO uint32_t PIC_PRIOR8_11;               /* 0x1c Priority counter initial values, sources 8-11. DS §4.7.6.8 p.176. Sources 8-11 are I2C0, I2C2, UART1, UART2; o */
  __IO uint32_t PIC_PRIOR12_15;              /* 0x20 Priority counter initial values, sources 12-15. DS §4.7.6.9 p.176. Sources 12-15 are UART0, UART3, GPIOB, GPIO */
  __IO uint32_t PIC_PRIOR16_19;              /* 0x24 Priority counter initial values, sources 16-19. DS §4.7.6.10 p.176. Sources 16-19 are SPI0, GPIOC, PWM, RTC; o */
  __IO uint32_t PIC_PRIOR20_23;              /* 0x28 Priority counter initial values, sources 20-23. DS §4.7.6.11 p.177. Sources 20-23 are SDIO, USB, SPI1, SPI2; o */
  __IO uint32_t PIC_PRIOR24_27;              /* 0x2c Priority counter initial values, sources 24-27. DS §4.7.6.12 p.178. Sources 24-27 are LCSFC, DAC, ADC, PCM_rd_ */
  __IO uint32_t PIC_PRIOR28_31;              /* 0x30 Priority counter initial values, sources 28-31. DS §4.7.6.13 p.178. Sources 28-31 are PCM_wr_data_interp, Syst */
  __IO uint32_t PIC_COW2;                    /* 0x34 Control registers. DS §4.7.6.14 p.178. Not an upper-bank sibling of PIC_COW1, as the hand-maintained entry thi */
  __IO uint32_t PIC_SYNC;                    /* 0x38 Asynchronous Process Control Register. DS §4.7.6.15 p.179. Offset also in DRV bsp_vic.h. Reset 0x0 (DS). */
  __IO uint32_t PIC_FFLAG_L;                 /* 0x3c Fast-interrupt select, sources 0-31. DS §4.7.6.16 p.180. Bit n is source 0+n (sources 0-31). The datasheet pri */
  __IO uint32_t PIC_RECORD_SEL;              /* 0x40 Selects the source whose requests PIC_INT_CNT counts. DS §4.7.6.17 p.180. Section heading prints PIC_INT_RECOR */
  __IO uint32_t PIC_INT_ST;                  /* 0x44 Interrupt request record, sources 0-31. DS §4.7.6.18 p.180. FW: 0 reads, 2 writes. Bit n is source 0+n (source */
  __IO uint32_t PIC_INT_ST_1;                /* 0x48 Interrupt request record, sources 32-63. DS §4.7.6.19 p.181. FW: 0 reads, 2 writes. Bit n is source 32+n (sour */
  __I  uint32_t PIC_INT_CNT;                 /* 0x4c Interrupt source interrupt count. DS §4.7.6.20 p.181. Section heading prints PIC_INT_ST_CNT at offset 0x48, wh */
  __I  uint32_t RESERVED_50[4];              /* 0x50-0x5f */
  __IO uint32_t PIC_MODE_1;                  /* 0x60 Trigger mode select, sources 32-63 (Register Table 5 prints 'Height 32', i.e. the high 32). DS §4.7.6.21 p.182 */
  __IO uint32_t PIC_PO_1;                    /* 0x64 Trigger polarity select, sources 32-63 (Register Table 5 prints 'Height 32', i.e. the high 32). DS §4.7.6.22 p */
  __IO uint32_t PIC_MASK_1;                  /* 0x68 Interrupt mask, sources 32-63 (Register Table 5 prints 'Height 32', i.e. the high 32). DS §4.7.6.23 p.182. FW: */
  __IO uint32_t PIC_PRIOR32_35;              /* 0x6c Priority counter initial values, sources 32-35. DS §4.7.6.24 p.182. Sources 32-35 are Rf_tx_inter, Rf_rx_inter */
  __IO uint32_t PIC_PRIOR36_39;              /* 0x70 Priority counter initial values, sources 36-39. DS §4.7.6.25 p.184. Sources 36-39 are SlaveSPI2, Codec_interp, */
  __IO uint32_t PIC_PRIOR40_43;              /* 0x74 Priority counter initial values, sources 40-43. DS §4.7.6.26 p.184. Sources 40-43 are unassigned, unassigned,  */
  __IO uint32_t PIC_PRIOR44_47;              /* 0x78 Priority counter initial values, sources 44-47. DS §4.7.6.27 p.184. Sources 44-47 are unassigned, unassigned,  */
  __IO uint32_t PIC_PRIOR48_51;              /* 0x7c Priority counter initial values, sources 48-51. DS §4.7.6.28 p.185. Sources 48-51 are unassigned, unassigned,  */
  __IO uint32_t PIC_PRIOR52_55;              /* 0x80 Priority counter initial values, sources 52-55. DS §4.7.6.29 p.185. Sources 52-55 are unassigned, unassigned,  */
  __IO uint32_t PIC_PRIOR56_59;              /* 0x84 Priority counter initial values, sources 56-59. DS §4.7.6.30 p.186. Sources 56-59 are unassigned, unassigned,  */
  __IO uint32_t PIC_PRIOR60_63;              /* 0x88 Priority counter initial values, sources 60-63. DS §4.7.6.31 p.186. Sources 60-63 are unassigned, unassigned,  */
  __IO uint32_t PIC_FFLAG_H;                 /* 0x8c Fast-interrupt select, sources 32-63 (Register Table 5 prints 'Height 32', i.e. the high 32). DS §4.7.6.32 p.1 */
} PIC_Type;   /* 0x90 bytes */
#define PIC_PIC_MODE_Time_slot_inter_rx_Pos  31u
#define PIC_PIC_MODE_Time_slot_inter_rx_Msk  (0x1u << 31u)
#define PIC_PIC_MODE_Time_slot_inter_tx_Pos  30u
#define PIC_PIC_MODE_Time_slot_inter_tx_Msk  (0x1u << 30u)
#define PIC_PIC_MODE_System_inter_Pos  29u
#define PIC_PIC_MODE_System_inter_Msk  (0x1u << 29u)
#define PIC_PIC_MODE_PCM_wr_data_interp_Pos  28u
#define PIC_PIC_MODE_PCM_wr_data_interp_Msk  (0x1u << 28u)
#define PIC_PIC_MODE_PCM_rd_data_interp_Pos  27u
#define PIC_PIC_MODE_PCM_rd_data_interp_Msk  (0x1u << 27u)
#define PIC_PIC_MODE_ADC_Pos  26u
#define PIC_PIC_MODE_ADC_Msk  (0x1u << 26u)
#define PIC_PIC_MODE_DAC_Pos  25u
#define PIC_PIC_MODE_DAC_Msk  (0x1u << 25u)
#define PIC_PIC_MODE_LCSFC_Pos  24u
#define PIC_PIC_MODE_LCSFC_Msk  (0x1u << 24u)
#define PIC_PIC_MODE_SPI2_Pos  23u
#define PIC_PIC_MODE_SPI2_Msk  (0x1u << 23u)
#define PIC_PIC_MODE_SPI1_Pos  22u
#define PIC_PIC_MODE_SPI1_Msk  (0x1u << 22u)
#define PIC_PIC_MODE_USB_Pos  21u
#define PIC_PIC_MODE_USB_Msk  (0x1u << 21u)
#define PIC_PIC_MODE_SDIO_Pos  20u
#define PIC_PIC_MODE_SDIO_Msk  (0x1u << 20u)
#define PIC_PIC_MODE_RTC_Pos  19u
#define PIC_PIC_MODE_RTC_Msk  (0x1u << 19u)
#define PIC_PIC_MODE_PWM_Pos  18u
#define PIC_PIC_MODE_PWM_Msk  (0x1u << 18u)
#define PIC_PIC_MODE_GPIOC_Pos  17u
#define PIC_PIC_MODE_GPIOC_Msk  (0x1u << 17u)
#define PIC_PIC_MODE_SPI0_Pos  16u
#define PIC_PIC_MODE_SPI0_Msk  (0x1u << 16u)
#define PIC_PIC_MODE_GPIOA_Pos  15u
#define PIC_PIC_MODE_GPIOA_Msk  (0x1u << 15u)
#define PIC_PIC_MODE_GPIOB_Pos  14u
#define PIC_PIC_MODE_GPIOB_Msk  (0x1u << 14u)
#define PIC_PIC_MODE_UART3_Pos  13u
#define PIC_PIC_MODE_UART3_Msk  (0x1u << 13u)
#define PIC_PIC_MODE_UART0_Pos  12u
#define PIC_PIC_MODE_UART0_Msk  (0x1u << 12u)
#define PIC_PIC_MODE_UART2_Pos  11u
#define PIC_PIC_MODE_UART2_Msk  (0x1u << 11u)
#define PIC_PIC_MODE_UART1_Pos  10u
#define PIC_PIC_MODE_UART1_Msk  (0x1u << 10u)
#define PIC_PIC_MODE_I2C2_Pos  9u
#define PIC_PIC_MODE_I2C2_Msk  (0x1u << 9u)
#define PIC_PIC_MODE_I2C0_Pos  8u
#define PIC_PIC_MODE_I2C0_Msk  (0x1u << 8u)
#define PIC_PIC_MODE_I2C1_Pos  7u
#define PIC_PIC_MODE_I2C1_Msk  (0x1u << 7u)
#define PIC_PIC_MODE_TIMER_6_Pos  6u
#define PIC_PIC_MODE_TIMER_6_Msk  (0x1u << 6u)
#define PIC_PIC_MODE_TIMER_5_Pos  5u
#define PIC_PIC_MODE_TIMER_5_Msk  (0x1u << 5u)
#define PIC_PIC_MODE_TIMER_4_Pos  4u
#define PIC_PIC_MODE_TIMER_4_Msk  (0x1u << 4u)
#define PIC_PIC_MODE_TIMER_3_Pos  3u
#define PIC_PIC_MODE_TIMER_3_Msk  (0x1u << 3u)
#define PIC_PIC_MODE_TIMER_2_Pos  2u
#define PIC_PIC_MODE_TIMER_2_Msk  (0x1u << 2u)
#define PIC_PIC_MODE_TIMER_1_Pos  1u
#define PIC_PIC_MODE_TIMER_1_Msk  (0x1u << 1u)
#define PIC_PIC_PO_Time_slot_inter_rx_Pos  31u
#define PIC_PIC_PO_Time_slot_inter_rx_Msk  (0x1u << 31u)
#define PIC_PIC_PO_Time_slot_inter_tx_Pos  30u
#define PIC_PIC_PO_Time_slot_inter_tx_Msk  (0x1u << 30u)
#define PIC_PIC_PO_System_inter_Pos  29u
#define PIC_PIC_PO_System_inter_Msk  (0x1u << 29u)
#define PIC_PIC_PO_PCM_wr_data_interp_Pos  28u
#define PIC_PIC_PO_PCM_wr_data_interp_Msk  (0x1u << 28u)
#define PIC_PIC_PO_PCM_rd_data_interp_Pos  27u
#define PIC_PIC_PO_PCM_rd_data_interp_Msk  (0x1u << 27u)
#define PIC_PIC_PO_ADC_Pos  26u
#define PIC_PIC_PO_ADC_Msk  (0x1u << 26u)
#define PIC_PIC_PO_DAC_Pos  25u
#define PIC_PIC_PO_DAC_Msk  (0x1u << 25u)
#define PIC_PIC_PO_LCSFC_Pos  24u
#define PIC_PIC_PO_LCSFC_Msk  (0x1u << 24u)
#define PIC_PIC_PO_SPI2_Pos  23u
#define PIC_PIC_PO_SPI2_Msk  (0x1u << 23u)
#define PIC_PIC_PO_SPI1_Pos  22u
#define PIC_PIC_PO_SPI1_Msk  (0x1u << 22u)
#define PIC_PIC_PO_USB_Pos  21u
#define PIC_PIC_PO_USB_Msk  (0x1u << 21u)
#define PIC_PIC_PO_SDIO_Pos  20u
#define PIC_PIC_PO_SDIO_Msk  (0x1u << 20u)
#define PIC_PIC_PO_RTC_Pos  19u
#define PIC_PIC_PO_RTC_Msk  (0x1u << 19u)
#define PIC_PIC_PO_PWM_Pos  18u
#define PIC_PIC_PO_PWM_Msk  (0x1u << 18u)
#define PIC_PIC_PO_GPIOC_Pos  17u
#define PIC_PIC_PO_GPIOC_Msk  (0x1u << 17u)
#define PIC_PIC_PO_SPI0_Pos  16u
#define PIC_PIC_PO_SPI0_Msk  (0x1u << 16u)
#define PIC_PIC_PO_GPIOA_Pos  15u
#define PIC_PIC_PO_GPIOA_Msk  (0x1u << 15u)
#define PIC_PIC_PO_GPIOB_Pos  14u
#define PIC_PIC_PO_GPIOB_Msk  (0x1u << 14u)
#define PIC_PIC_PO_UART3_Pos  13u
#define PIC_PIC_PO_UART3_Msk  (0x1u << 13u)
#define PIC_PIC_PO_UART0_Pos  12u
#define PIC_PIC_PO_UART0_Msk  (0x1u << 12u)
#define PIC_PIC_PO_UART2_Pos  11u
#define PIC_PIC_PO_UART2_Msk  (0x1u << 11u)
#define PIC_PIC_PO_UART1_Pos  10u
#define PIC_PIC_PO_UART1_Msk  (0x1u << 10u)
#define PIC_PIC_PO_I2C2_Pos  9u
#define PIC_PIC_PO_I2C2_Msk  (0x1u << 9u)
#define PIC_PIC_PO_I2C0_Pos  8u
#define PIC_PIC_PO_I2C0_Msk  (0x1u << 8u)
#define PIC_PIC_PO_I2C1_Pos  7u
#define PIC_PIC_PO_I2C1_Msk  (0x1u << 7u)
#define PIC_PIC_PO_TIMER_6_Pos  6u
#define PIC_PIC_PO_TIMER_6_Msk  (0x1u << 6u)
#define PIC_PIC_PO_TIMER_5_Pos  5u
#define PIC_PIC_PO_TIMER_5_Msk  (0x1u << 5u)
#define PIC_PIC_PO_TIMER_4_Pos  4u
#define PIC_PIC_PO_TIMER_4_Msk  (0x1u << 4u)
#define PIC_PIC_PO_TIMER_3_Pos  3u
#define PIC_PIC_PO_TIMER_3_Msk  (0x1u << 3u)
#define PIC_PIC_PO_TIMER_2_Pos  2u
#define PIC_PIC_PO_TIMER_2_Msk  (0x1u << 2u)
#define PIC_PIC_PO_TIMER_1_Pos  1u
#define PIC_PIC_PO_TIMER_1_Msk  (0x1u << 1u)
#define PIC_PIC_MASK_Time_slot_inter_rx_Pos  31u
#define PIC_PIC_MASK_Time_slot_inter_rx_Msk  (0x1u << 31u)
#define PIC_PIC_MASK_Time_slot_inter_tx_Pos  30u
#define PIC_PIC_MASK_Time_slot_inter_tx_Msk  (0x1u << 30u)
#define PIC_PIC_MASK_System_inter_Pos  29u
#define PIC_PIC_MASK_System_inter_Msk  (0x1u << 29u)
#define PIC_PIC_MASK_PCM_wr_data_interp_Pos  28u
#define PIC_PIC_MASK_PCM_wr_data_interp_Msk  (0x1u << 28u)
#define PIC_PIC_MASK_PCM_rd_data_interp_Pos  27u
#define PIC_PIC_MASK_PCM_rd_data_interp_Msk  (0x1u << 27u)
#define PIC_PIC_MASK_ADC_Pos  26u
#define PIC_PIC_MASK_ADC_Msk  (0x1u << 26u)
#define PIC_PIC_MASK_DAC_Pos  25u
#define PIC_PIC_MASK_DAC_Msk  (0x1u << 25u)
#define PIC_PIC_MASK_LCSFC_Pos  24u
#define PIC_PIC_MASK_LCSFC_Msk  (0x1u << 24u)
#define PIC_PIC_MASK_SPI2_Pos  23u
#define PIC_PIC_MASK_SPI2_Msk  (0x1u << 23u)
#define PIC_PIC_MASK_SPI1_Pos  22u
#define PIC_PIC_MASK_SPI1_Msk  (0x1u << 22u)
#define PIC_PIC_MASK_USB_Pos  21u
#define PIC_PIC_MASK_USB_Msk  (0x1u << 21u)
#define PIC_PIC_MASK_SDIO_Pos  20u
#define PIC_PIC_MASK_SDIO_Msk  (0x1u << 20u)
#define PIC_PIC_MASK_RTC_Pos  19u
#define PIC_PIC_MASK_RTC_Msk  (0x1u << 19u)
#define PIC_PIC_MASK_PWM_Pos  18u
#define PIC_PIC_MASK_PWM_Msk  (0x1u << 18u)
#define PIC_PIC_MASK_GPIOC_Pos  17u
#define PIC_PIC_MASK_GPIOC_Msk  (0x1u << 17u)
#define PIC_PIC_MASK_SPI0_Pos  16u
#define PIC_PIC_MASK_SPI0_Msk  (0x1u << 16u)
#define PIC_PIC_MASK_GPIOA_Pos  15u
#define PIC_PIC_MASK_GPIOA_Msk  (0x1u << 15u)
#define PIC_PIC_MASK_GPIOB_Pos  14u
#define PIC_PIC_MASK_GPIOB_Msk  (0x1u << 14u)
#define PIC_PIC_MASK_UART3_Pos  13u
#define PIC_PIC_MASK_UART3_Msk  (0x1u << 13u)
#define PIC_PIC_MASK_UART0_Pos  12u
#define PIC_PIC_MASK_UART0_Msk  (0x1u << 12u)
#define PIC_PIC_MASK_UART2_Pos  11u
#define PIC_PIC_MASK_UART2_Msk  (0x1u << 11u)
#define PIC_PIC_MASK_UART1_Pos  10u
#define PIC_PIC_MASK_UART1_Msk  (0x1u << 10u)
#define PIC_PIC_MASK_I2C2_Pos  9u
#define PIC_PIC_MASK_I2C2_Msk  (0x1u << 9u)
#define PIC_PIC_MASK_I2C0_Pos  8u
#define PIC_PIC_MASK_I2C0_Msk  (0x1u << 8u)
#define PIC_PIC_MASK_I2C1_Pos  7u
#define PIC_PIC_MASK_I2C1_Msk  (0x1u << 7u)
#define PIC_PIC_MASK_TIMER_6_Pos  6u
#define PIC_PIC_MASK_TIMER_6_Msk  (0x1u << 6u)
#define PIC_PIC_MASK_TIMER_5_Pos  5u
#define PIC_PIC_MASK_TIMER_5_Msk  (0x1u << 5u)
#define PIC_PIC_MASK_TIMER_4_Pos  4u
#define PIC_PIC_MASK_TIMER_4_Msk  (0x1u << 4u)
#define PIC_PIC_MASK_TIMER_3_Pos  3u
#define PIC_PIC_MASK_TIMER_3_Msk  (0x1u << 3u)
#define PIC_PIC_MASK_TIMER_2_Pos  2u
#define PIC_PIC_MASK_TIMER_2_Msk  (0x1u << 2u)
#define PIC_PIC_MASK_TIMER_1_Pos  1u
#define PIC_PIC_MASK_TIMER_1_Msk  (0x1u << 1u)
#define PIC_PIC_VECTOR_vector0_Pos  0u
#define PIC_PIC_VECTOR_vector0_Msk  (0x7fu << 0u)
#define PIC_PIC_COW1_feoi_Pos  3u
#define PIC_PIC_COW1_feoi_Msk  (0x1u << 3u)
#define PIC_PIC_COW1_eoi_Pos  2u
#define PIC_PIC_COW1_eoi_Msk  (0x1u << 2u)
#define PIC_PIC_PRIOR0_3_prior_irq3_Pos  24u
#define PIC_PIC_PRIOR0_3_prior_irq3_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR0_3_prior_irq2_Pos  16u
#define PIC_PIC_PRIOR0_3_prior_irq2_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR0_3_prior_irq1_Pos  8u
#define PIC_PIC_PRIOR0_3_prior_irq1_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR0_3_prior_irq0_Pos  0u
#define PIC_PIC_PRIOR0_3_prior_irq0_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR4_7_prior_irq7_Pos  24u
#define PIC_PIC_PRIOR4_7_prior_irq7_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR4_7_prior_irq6_Pos  16u
#define PIC_PIC_PRIOR4_7_prior_irq6_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR4_7_prior_irq5_Pos  8u
#define PIC_PIC_PRIOR4_7_prior_irq5_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR4_7_prior_irq4_Pos  0u
#define PIC_PIC_PRIOR4_7_prior_irq4_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR8_11_prior_irq11_Pos  24u
#define PIC_PIC_PRIOR8_11_prior_irq11_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR8_11_prior_irq10_Pos  16u
#define PIC_PIC_PRIOR8_11_prior_irq10_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR8_11_prior_irq9_Pos  8u
#define PIC_PIC_PRIOR8_11_prior_irq9_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR8_11_prior_irq8_Pos  0u
#define PIC_PIC_PRIOR8_11_prior_irq8_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR12_15_prior_irq15_Pos  24u
#define PIC_PIC_PRIOR12_15_prior_irq15_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR12_15_prior_irq14_Pos  16u
#define PIC_PIC_PRIOR12_15_prior_irq14_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR12_15_prior_irq13_Pos  8u
#define PIC_PIC_PRIOR12_15_prior_irq13_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR12_15_prior_irq12_Pos  0u
#define PIC_PIC_PRIOR12_15_prior_irq12_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR16_19_prior_irq19_Pos  24u
#define PIC_PIC_PRIOR16_19_prior_irq19_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR16_19_prior_irq18_Pos  16u
#define PIC_PIC_PRIOR16_19_prior_irq18_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR16_19_prior_irq17_Pos  8u
#define PIC_PIC_PRIOR16_19_prior_irq17_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR16_19_prior_irq16_Pos  0u
#define PIC_PIC_PRIOR16_19_prior_irq16_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR20_23_prior_irq23_Pos  24u
#define PIC_PIC_PRIOR20_23_prior_irq23_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR20_23_prior_irq22_Pos  16u
#define PIC_PIC_PRIOR20_23_prior_irq22_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR20_23_prior_irq21_Pos  8u
#define PIC_PIC_PRIOR20_23_prior_irq21_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR20_23_prior_irq20_Pos  0u
#define PIC_PIC_PRIOR20_23_prior_irq20_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR24_27_prior_irq27_Pos  24u
#define PIC_PIC_PRIOR24_27_prior_irq27_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR24_27_prior_irq26_Pos  16u
#define PIC_PIC_PRIOR24_27_prior_irq26_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR24_27_prior_irq25_Pos  8u
#define PIC_PIC_PRIOR24_27_prior_irq25_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR24_27_prior_irq24_Pos  0u
#define PIC_PIC_PRIOR24_27_prior_irq24_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR28_31_prior_irq31_Pos  24u
#define PIC_PIC_PRIOR28_31_prior_irq31_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR28_31_prior_irq30_Pos  16u
#define PIC_PIC_PRIOR28_31_prior_irq30_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR28_31_prior_irq29_Pos  8u
#define PIC_PIC_PRIOR28_31_prior_irq29_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR28_31_prior_irq28_Pos  0u
#define PIC_PIC_PRIOR28_31_prior_irq28_Msk  (0xffu << 0u)
#define PIC_PIC_COW2_avec_Pos  1u
#define PIC_PIC_COW2_avec_Msk  (0x1u << 1u)
#define PIC_PIC_COW2_priority_Pos  0u
#define PIC_PIC_COW2_priority_Msk  (0x1u << 0u)
#define PIC_PIC_SYNC_min_interval_Pos  0u
#define PIC_PIC_SYNC_min_interval_Msk  (0xffu << 0u)
#define PIC_PIC_FFLAG_L_Time_slot_inter_rx_Pos  31u
#define PIC_PIC_FFLAG_L_Time_slot_inter_rx_Msk  (0x1u << 31u)
#define PIC_PIC_FFLAG_L_Time_slot_inter_tx_Pos  30u
#define PIC_PIC_FFLAG_L_Time_slot_inter_tx_Msk  (0x1u << 30u)
#define PIC_PIC_FFLAG_L_System_inter_Pos  29u
#define PIC_PIC_FFLAG_L_System_inter_Msk  (0x1u << 29u)
#define PIC_PIC_FFLAG_L_PCM_wr_data_interp_Pos  28u
#define PIC_PIC_FFLAG_L_PCM_wr_data_interp_Msk  (0x1u << 28u)
#define PIC_PIC_FFLAG_L_PCM_rd_data_interp_Pos  27u
#define PIC_PIC_FFLAG_L_PCM_rd_data_interp_Msk  (0x1u << 27u)
#define PIC_PIC_FFLAG_L_ADC_Pos  26u
#define PIC_PIC_FFLAG_L_ADC_Msk  (0x1u << 26u)
#define PIC_PIC_FFLAG_L_DAC_Pos  25u
#define PIC_PIC_FFLAG_L_DAC_Msk  (0x1u << 25u)
#define PIC_PIC_FFLAG_L_LCSFC_Pos  24u
#define PIC_PIC_FFLAG_L_LCSFC_Msk  (0x1u << 24u)
#define PIC_PIC_FFLAG_L_SPI2_Pos  23u
#define PIC_PIC_FFLAG_L_SPI2_Msk  (0x1u << 23u)
#define PIC_PIC_FFLAG_L_SPI1_Pos  22u
#define PIC_PIC_FFLAG_L_SPI1_Msk  (0x1u << 22u)
#define PIC_PIC_FFLAG_L_USB_Pos  21u
#define PIC_PIC_FFLAG_L_USB_Msk  (0x1u << 21u)
#define PIC_PIC_FFLAG_L_SDIO_Pos  20u
#define PIC_PIC_FFLAG_L_SDIO_Msk  (0x1u << 20u)
#define PIC_PIC_FFLAG_L_RTC_Pos  19u
#define PIC_PIC_FFLAG_L_RTC_Msk  (0x1u << 19u)
#define PIC_PIC_FFLAG_L_PWM_Pos  18u
#define PIC_PIC_FFLAG_L_PWM_Msk  (0x1u << 18u)
#define PIC_PIC_FFLAG_L_GPIOC_Pos  17u
#define PIC_PIC_FFLAG_L_GPIOC_Msk  (0x1u << 17u)
#define PIC_PIC_FFLAG_L_SPI0_Pos  16u
#define PIC_PIC_FFLAG_L_SPI0_Msk  (0x1u << 16u)
#define PIC_PIC_FFLAG_L_GPIOA_Pos  15u
#define PIC_PIC_FFLAG_L_GPIOA_Msk  (0x1u << 15u)
#define PIC_PIC_FFLAG_L_GPIOB_Pos  14u
#define PIC_PIC_FFLAG_L_GPIOB_Msk  (0x1u << 14u)
#define PIC_PIC_FFLAG_L_UART3_Pos  13u
#define PIC_PIC_FFLAG_L_UART3_Msk  (0x1u << 13u)
#define PIC_PIC_FFLAG_L_UART0_Pos  12u
#define PIC_PIC_FFLAG_L_UART0_Msk  (0x1u << 12u)
#define PIC_PIC_FFLAG_L_UART2_Pos  11u
#define PIC_PIC_FFLAG_L_UART2_Msk  (0x1u << 11u)
#define PIC_PIC_FFLAG_L_UART1_Pos  10u
#define PIC_PIC_FFLAG_L_UART1_Msk  (0x1u << 10u)
#define PIC_PIC_FFLAG_L_I2C2_Pos  9u
#define PIC_PIC_FFLAG_L_I2C2_Msk  (0x1u << 9u)
#define PIC_PIC_FFLAG_L_I2C0_Pos  8u
#define PIC_PIC_FFLAG_L_I2C0_Msk  (0x1u << 8u)
#define PIC_PIC_FFLAG_L_I2C1_Pos  7u
#define PIC_PIC_FFLAG_L_I2C1_Msk  (0x1u << 7u)
#define PIC_PIC_FFLAG_L_TIMER_6_Pos  6u
#define PIC_PIC_FFLAG_L_TIMER_6_Msk  (0x1u << 6u)
#define PIC_PIC_FFLAG_L_TIMER_5_Pos  5u
#define PIC_PIC_FFLAG_L_TIMER_5_Msk  (0x1u << 5u)
#define PIC_PIC_FFLAG_L_TIMER_4_Pos  4u
#define PIC_PIC_FFLAG_L_TIMER_4_Msk  (0x1u << 4u)
#define PIC_PIC_FFLAG_L_TIMER_3_Pos  3u
#define PIC_PIC_FFLAG_L_TIMER_3_Msk  (0x1u << 3u)
#define PIC_PIC_FFLAG_L_TIMER_2_Pos  2u
#define PIC_PIC_FFLAG_L_TIMER_2_Msk  (0x1u << 2u)
#define PIC_PIC_FFLAG_L_TIMER_1_Pos  1u
#define PIC_PIC_FFLAG_L_TIMER_1_Msk  (0x1u << 1u)
#define PIC_PIC_RECORD_SEL_irq_record_sel_Pos  0u
#define PIC_PIC_RECORD_SEL_irq_record_sel_Msk  (0x7fu << 0u)
#define PIC_PIC_INT_ST_Time_slot_inter_rx_Pos  31u
#define PIC_PIC_INT_ST_Time_slot_inter_rx_Msk  (0x1u << 31u)
#define PIC_PIC_INT_ST_Time_slot_inter_tx_Pos  30u
#define PIC_PIC_INT_ST_Time_slot_inter_tx_Msk  (0x1u << 30u)
#define PIC_PIC_INT_ST_System_inter_Pos  29u
#define PIC_PIC_INT_ST_System_inter_Msk  (0x1u << 29u)
#define PIC_PIC_INT_ST_PCM_wr_data_interp_Pos  28u
#define PIC_PIC_INT_ST_PCM_wr_data_interp_Msk  (0x1u << 28u)
#define PIC_PIC_INT_ST_PCM_rd_data_interp_Pos  27u
#define PIC_PIC_INT_ST_PCM_rd_data_interp_Msk  (0x1u << 27u)
#define PIC_PIC_INT_ST_ADC_Pos  26u
#define PIC_PIC_INT_ST_ADC_Msk  (0x1u << 26u)
#define PIC_PIC_INT_ST_DAC_Pos  25u
#define PIC_PIC_INT_ST_DAC_Msk  (0x1u << 25u)
#define PIC_PIC_INT_ST_LCSFC_Pos  24u
#define PIC_PIC_INT_ST_LCSFC_Msk  (0x1u << 24u)
#define PIC_PIC_INT_ST_SPI2_Pos  23u
#define PIC_PIC_INT_ST_SPI2_Msk  (0x1u << 23u)
#define PIC_PIC_INT_ST_SPI1_Pos  22u
#define PIC_PIC_INT_ST_SPI1_Msk  (0x1u << 22u)
#define PIC_PIC_INT_ST_USB_Pos  21u
#define PIC_PIC_INT_ST_USB_Msk  (0x1u << 21u)
#define PIC_PIC_INT_ST_SDIO_Pos  20u
#define PIC_PIC_INT_ST_SDIO_Msk  (0x1u << 20u)
#define PIC_PIC_INT_ST_RTC_Pos  19u
#define PIC_PIC_INT_ST_RTC_Msk  (0x1u << 19u)
#define PIC_PIC_INT_ST_PWM_Pos  18u
#define PIC_PIC_INT_ST_PWM_Msk  (0x1u << 18u)
#define PIC_PIC_INT_ST_GPIOC_Pos  17u
#define PIC_PIC_INT_ST_GPIOC_Msk  (0x1u << 17u)
#define PIC_PIC_INT_ST_SPI0_Pos  16u
#define PIC_PIC_INT_ST_SPI0_Msk  (0x1u << 16u)
#define PIC_PIC_INT_ST_GPIOA_Pos  15u
#define PIC_PIC_INT_ST_GPIOA_Msk  (0x1u << 15u)
#define PIC_PIC_INT_ST_GPIOB_Pos  14u
#define PIC_PIC_INT_ST_GPIOB_Msk  (0x1u << 14u)
#define PIC_PIC_INT_ST_UART3_Pos  13u
#define PIC_PIC_INT_ST_UART3_Msk  (0x1u << 13u)
#define PIC_PIC_INT_ST_UART0_Pos  12u
#define PIC_PIC_INT_ST_UART0_Msk  (0x1u << 12u)
#define PIC_PIC_INT_ST_UART2_Pos  11u
#define PIC_PIC_INT_ST_UART2_Msk  (0x1u << 11u)
#define PIC_PIC_INT_ST_UART1_Pos  10u
#define PIC_PIC_INT_ST_UART1_Msk  (0x1u << 10u)
#define PIC_PIC_INT_ST_I2C2_Pos  9u
#define PIC_PIC_INT_ST_I2C2_Msk  (0x1u << 9u)
#define PIC_PIC_INT_ST_I2C0_Pos  8u
#define PIC_PIC_INT_ST_I2C0_Msk  (0x1u << 8u)
#define PIC_PIC_INT_ST_I2C1_Pos  7u
#define PIC_PIC_INT_ST_I2C1_Msk  (0x1u << 7u)
#define PIC_PIC_INT_ST_TIMER_6_Pos  6u
#define PIC_PIC_INT_ST_TIMER_6_Msk  (0x1u << 6u)
#define PIC_PIC_INT_ST_TIMER_5_Pos  5u
#define PIC_PIC_INT_ST_TIMER_5_Msk  (0x1u << 5u)
#define PIC_PIC_INT_ST_TIMER_4_Pos  4u
#define PIC_PIC_INT_ST_TIMER_4_Msk  (0x1u << 4u)
#define PIC_PIC_INT_ST_TIMER_3_Pos  3u
#define PIC_PIC_INT_ST_TIMER_3_Msk  (0x1u << 3u)
#define PIC_PIC_INT_ST_TIMER_2_Pos  2u
#define PIC_PIC_INT_ST_TIMER_2_Msk  (0x1u << 2u)
#define PIC_PIC_INT_ST_TIMER_1_Pos  1u
#define PIC_PIC_INT_ST_TIMER_1_Msk  (0x1u << 1u)
#define PIC_PIC_INT_ST_1_Codec_interp_Pos  5u
#define PIC_PIC_INT_ST_1_Codec_interp_Msk  (0x1u << 5u)
#define PIC_PIC_INT_ST_1_SlaveSPI2_Pos  4u
#define PIC_PIC_INT_ST_1_SlaveSPI2_Msk  (0x1u << 4u)
#define PIC_PIC_INT_ST_1_SlaveSPI1_Pos  3u
#define PIC_PIC_INT_ST_1_SlaveSPI1_Msk  (0x1u << 3u)
#define PIC_PIC_INT_ST_1_SlaveSPI0_Pos  2u
#define PIC_PIC_INT_ST_1_SlaveSPI0_Msk  (0x1u << 2u)
#define PIC_PIC_INT_ST_1_Rf_rx_inter_Pos  1u
#define PIC_PIC_INT_ST_1_Rf_rx_inter_Msk  (0x1u << 1u)
#define PIC_PIC_INT_ST_1_Rf_tx_inter_Pos  0u
#define PIC_PIC_INT_ST_1_Rf_tx_inter_Msk  (0x1u << 0u)
#define PIC_PIC_INT_CNT_int_cnt_Pos  0u
#define PIC_PIC_INT_CNT_int_cnt_Msk  (0xffffffffu << 0u)
#define PIC_PIC_MODE_1_Codec_interp_Pos  5u
#define PIC_PIC_MODE_1_Codec_interp_Msk  (0x1u << 5u)
#define PIC_PIC_MODE_1_SlaveSPI2_Pos  4u
#define PIC_PIC_MODE_1_SlaveSPI2_Msk  (0x1u << 4u)
#define PIC_PIC_MODE_1_SlaveSPI1_Pos  3u
#define PIC_PIC_MODE_1_SlaveSPI1_Msk  (0x1u << 3u)
#define PIC_PIC_MODE_1_SlaveSPI0_Pos  2u
#define PIC_PIC_MODE_1_SlaveSPI0_Msk  (0x1u << 2u)
#define PIC_PIC_MODE_1_Rf_rx_inter_Pos  1u
#define PIC_PIC_MODE_1_Rf_rx_inter_Msk  (0x1u << 1u)
#define PIC_PIC_MODE_1_Rf_tx_inter_Pos  0u
#define PIC_PIC_MODE_1_Rf_tx_inter_Msk  (0x1u << 0u)
#define PIC_PIC_PO_1_Codec_interp_Pos  5u
#define PIC_PIC_PO_1_Codec_interp_Msk  (0x1u << 5u)
#define PIC_PIC_PO_1_SlaveSPI2_Pos  4u
#define PIC_PIC_PO_1_SlaveSPI2_Msk  (0x1u << 4u)
#define PIC_PIC_PO_1_SlaveSPI1_Pos  3u
#define PIC_PIC_PO_1_SlaveSPI1_Msk  (0x1u << 3u)
#define PIC_PIC_PO_1_SlaveSPI0_Pos  2u
#define PIC_PIC_PO_1_SlaveSPI0_Msk  (0x1u << 2u)
#define PIC_PIC_PO_1_Rf_rx_inter_Pos  1u
#define PIC_PIC_PO_1_Rf_rx_inter_Msk  (0x1u << 1u)
#define PIC_PIC_PO_1_Rf_tx_inter_Pos  0u
#define PIC_PIC_PO_1_Rf_tx_inter_Msk  (0x1u << 0u)
#define PIC_PIC_MASK_1_Codec_interp_Pos  5u
#define PIC_PIC_MASK_1_Codec_interp_Msk  (0x1u << 5u)
#define PIC_PIC_MASK_1_SlaveSPI2_Pos  4u
#define PIC_PIC_MASK_1_SlaveSPI2_Msk  (0x1u << 4u)
#define PIC_PIC_MASK_1_SlaveSPI1_Pos  3u
#define PIC_PIC_MASK_1_SlaveSPI1_Msk  (0x1u << 3u)
#define PIC_PIC_MASK_1_SlaveSPI0_Pos  2u
#define PIC_PIC_MASK_1_SlaveSPI0_Msk  (0x1u << 2u)
#define PIC_PIC_MASK_1_Rf_rx_inter_Pos  1u
#define PIC_PIC_MASK_1_Rf_rx_inter_Msk  (0x1u << 1u)
#define PIC_PIC_MASK_1_Rf_tx_inter_Pos  0u
#define PIC_PIC_MASK_1_Rf_tx_inter_Msk  (0x1u << 0u)
#define PIC_PIC_PRIOR32_35_prior_irq35_Pos  24u
#define PIC_PIC_PRIOR32_35_prior_irq35_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR32_35_prior_irq34_Pos  16u
#define PIC_PIC_PRIOR32_35_prior_irq34_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR32_35_prior_irq33_Pos  8u
#define PIC_PIC_PRIOR32_35_prior_irq33_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR32_35_prior_irq32_Pos  0u
#define PIC_PIC_PRIOR32_35_prior_irq32_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR36_39_prior_irq39_Pos  24u
#define PIC_PIC_PRIOR36_39_prior_irq39_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR36_39_prior_irq38_Pos  16u
#define PIC_PIC_PRIOR36_39_prior_irq38_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR36_39_prior_irq37_Pos  8u
#define PIC_PIC_PRIOR36_39_prior_irq37_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR36_39_prior_irq36_Pos  0u
#define PIC_PIC_PRIOR36_39_prior_irq36_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR40_43_prior_irq43_Pos  24u
#define PIC_PIC_PRIOR40_43_prior_irq43_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR40_43_prior_irq42_Pos  16u
#define PIC_PIC_PRIOR40_43_prior_irq42_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR40_43_prior_irq41_Pos  8u
#define PIC_PIC_PRIOR40_43_prior_irq41_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR40_43_prior_irq40_Pos  0u
#define PIC_PIC_PRIOR40_43_prior_irq40_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR44_47_prior_irq47_Pos  24u
#define PIC_PIC_PRIOR44_47_prior_irq47_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR44_47_prior_irq46_Pos  16u
#define PIC_PIC_PRIOR44_47_prior_irq46_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR44_47_prior_irq45_Pos  8u
#define PIC_PIC_PRIOR44_47_prior_irq45_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR44_47_prior_irq44_Pos  0u
#define PIC_PIC_PRIOR44_47_prior_irq44_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR48_51_prior_irq51_Pos  24u
#define PIC_PIC_PRIOR48_51_prior_irq51_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR48_51_prior_irq50_Pos  16u
#define PIC_PIC_PRIOR48_51_prior_irq50_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR48_51_prior_irq49_Pos  8u
#define PIC_PIC_PRIOR48_51_prior_irq49_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR48_51_prior_irq48_Pos  0u
#define PIC_PIC_PRIOR48_51_prior_irq48_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR52_55_prior_irq55_Pos  24u
#define PIC_PIC_PRIOR52_55_prior_irq55_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR52_55_prior_irq54_Pos  16u
#define PIC_PIC_PRIOR52_55_prior_irq54_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR52_55_prior_irq53_Pos  8u
#define PIC_PIC_PRIOR52_55_prior_irq53_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR52_55_prior_irq52_Pos  0u
#define PIC_PIC_PRIOR52_55_prior_irq52_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR56_59_prior_irq59_Pos  24u
#define PIC_PIC_PRIOR56_59_prior_irq59_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR56_59_prior_irq58_Pos  16u
#define PIC_PIC_PRIOR56_59_prior_irq58_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR56_59_prior_irq57_Pos  8u
#define PIC_PIC_PRIOR56_59_prior_irq57_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR56_59_prior_irq56_Pos  0u
#define PIC_PIC_PRIOR56_59_prior_irq56_Msk  (0xffu << 0u)
#define PIC_PIC_PRIOR60_63_prior_irq63_Pos  24u
#define PIC_PIC_PRIOR60_63_prior_irq63_Msk  (0xffu << 24u)
#define PIC_PIC_PRIOR60_63_prior_irq62_Pos  16u
#define PIC_PIC_PRIOR60_63_prior_irq62_Msk  (0xffu << 16u)
#define PIC_PIC_PRIOR60_63_prior_irq61_Pos  8u
#define PIC_PIC_PRIOR60_63_prior_irq61_Msk  (0xffu << 8u)
#define PIC_PIC_PRIOR60_63_prior_irq60_Pos  0u
#define PIC_PIC_PRIOR60_63_prior_irq60_Msk  (0xffu << 0u)
#define PIC_PIC_FFLAG_H_Codec_interp_Pos  5u
#define PIC_PIC_FFLAG_H_Codec_interp_Msk  (0x1u << 5u)
#define PIC_PIC_FFLAG_H_SlaveSPI2_Pos  4u
#define PIC_PIC_FFLAG_H_SlaveSPI2_Msk  (0x1u << 4u)
#define PIC_PIC_FFLAG_H_SlaveSPI1_Pos  3u
#define PIC_PIC_FFLAG_H_SlaveSPI1_Msk  (0x1u << 3u)
#define PIC_PIC_FFLAG_H_SlaveSPI0_Pos  2u
#define PIC_PIC_FFLAG_H_SlaveSPI0_Msk  (0x1u << 2u)
#define PIC_PIC_FFLAG_H_Rf_rx_inter_Pos  1u
#define PIC_PIC_FFLAG_H_Rf_rx_inter_Msk  (0x1u << 1u)
#define PIC_PIC_FFLAG_H_Rf_tx_inter_Pos  0u
#define PIC_PIC_FFLAG_H_Rf_tx_inter_Msk  (0x1u << 0u)

#define i8080_BASE       0x12000000UL
#define i8080            ((I80_Type *) i8080_BASE)
#define USB_BASE         0x13000000UL  /* PIC source 21 */
#define USB              ((USB_Type *) USB_BASE)
#define WDG_BASE         0x14010000UL
#define WDG              ((WDG_Type *) WDG_BASE)
#define GPIOA_BASE       0x14020000UL  /* PIC source 15 */
#define GPIOA            ((GPIO_Type *) GPIOA_BASE)
#define UART0_BASE       0x14030000UL  /* PIC source 12 */
#define UART0            ((UART_Type *) UART0_BASE)
#define UART1_BASE       0x14040000UL  /* PIC source 10 */
#define UART1            ((UART_Type *) UART1_BASE)
#define UART2_BASE       0x14050000UL  /* PIC source 11 */
#define UART2            ((UART_Type *) UART2_BASE)
#define UART3_BASE       0x14090000UL  /* PIC source 13 */
#define UART3            ((UART_Type *) UART3_BASE)
#define I2C0_BASE        0x14060000UL  /* PIC source 8 */
#define I2C0             ((I2C_Type *) I2C0_BASE)
#define I2C1_BASE        0x14070000UL  /* PIC source 7 */
#define I2C1             ((I2C_Type *) I2C1_BASE)
#define I2C2_BASE        0x14080000UL  /* PIC source 9 */
#define I2C2             ((I2C_Type *) I2C2_BASE)
#define SPI_Master0_BASE 0x140a0000UL  /* PIC source 16 */
#define SPI_Master0      ((SSI_Type *) SPI_Master0_BASE)
#define SPI_Master1_BASE 0x140b0000UL  /* PIC source 22 */
#define SPI_Master1      ((SSI_Type *) SPI_Master1_BASE)
#define PWM_BASE         0x140c0000UL  /* PIC source 18 */
#define PWM              ((PWM_Type *) PWM_BASE)
#define ADC_BASE         0x140d0000UL  /* PIC source 26 */
#define ADC              ((ADC_Type *) ADC_BASE)
#define SPI2_BASE        0x140e0000UL  /* PIC source 23 */
#define SPI2             ((SSI_Type *) SPI2_BASE)
#define DAC_BASE         0x140f0000UL  /* PIC source 25 */
#define DAC              ((DAC_Type *) DAC_BASE)
#define GPIOB_BASE       0x14100000UL  /* PIC source 14 */
#define GPIOB            ((GPIO_Type *) GPIOB_BASE)
#define GPIOC_BASE       0x14110000UL  /* PIC source 17 */
#define GPIOC            ((GPIO_Type *) GPIOC_BASE)
#define SPI_Slave0_BASE  0x14120000UL  /* PIC source 34 */
#define SPI_Slave0       ((SSI_Type *) SPI_Slave0_BASE)
#define SPI_Slave1_BASE  0x14130000UL  /* PIC source 35 */
#define SPI_Slave1       ((SSI_Type *) SPI_Slave1_BASE)
#define SPI_Slave2_BASE  0x14140000UL  /* PIC source 36 */
#define SPI_Slave2       ((SSI_Type *) SPI_Slave2_BASE)
#define SPI_Master3_BASE 0x14150000UL
#define SPI_Master3      ((SSI_Type *) SPI_Master3_BASE)
#define SDIO_BASE        0x15000000UL  /* PIC source 20 */
#define SDIO             ((SDIO_Type *) SDIO_BASE)
#define Modem_Buffer_BASE 0x16000000UL
#define CODEC_BASE       0x160009c0UL  /* PIC source 37 */
#define CODEC            ((CODEC_Type *) CODEC_BASE)
#define PIC_BASE         0x17000000UL
#define PIC              ((PIC_Type *) PIC_BASE)
/* END GENERATED by the hr_c7000_svd register-map generator */

#endif /* HR_C7000_DM32_H */
