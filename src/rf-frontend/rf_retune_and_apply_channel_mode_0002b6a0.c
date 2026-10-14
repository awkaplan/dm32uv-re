/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: rf_retune_and_apply_channel_mode @ 0002b6a0 (IRAM address; the boot stub copies these bytes from program flash 0x030db2c0)
 * Size: 318 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rf_retune_and_apply_channel_mode(uint param_1)

{
  undefined *puVar1;
  byte bVar2;
  
  fd6818b_driver_state_reset();
  fd6818_set_frequency(param_1 >> 0x10,param_1 & 0xffff);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X32,0x244);
  puVar1 = PTR_DAT_0002b7e0;
  if ((PTR_DAT_0002b7e0[8] & 0xf0) == 0x10) {
    if ((PTR_DAT_0002b7ec[0x11] & 0x20) == 0) {
      stage_hook_dispatch(4);
      gpio_interrupt_disable_bit(0x3b);
      fd6818b_filter_select_then_chipmode_normal();
      fd6818b_reg_write(FD6818_PAGE0_REG_47H,0x140);
      *(undefined2 *)PTR_DAT_0002b7f0 = 0;
      fd6818b_reg_write(FD6818_PAGE0_REG_3FH,0);
      return;
    }
  }
  else if ((PTR_DAT_0002b7ec[0x11] & 0x20) == 0) {
    bVar2 = func_0x0300e3b4(*(undefined2 *)(PTR_DAT_0002b7e0 + 0x11));
    PTR_DAT_0002b7f4[0x35] = PTR_DAT_0002b7f4[0x35] & 0xf3 | (bVar2 & 3) << 2;
    func_0x0300e218();
    *(undefined2 *)PTR_DAT_0002b7f0 = 0;
    bVar2 = puVar1[0x16] & 0xe;
    if (bVar2 == 8) {
      func_0x03067564(1);
      *(ushort *)PTR_DAT_0002b7f0 = *(ushort *)PTR_DAT_0002b7f0 | 0x3002;
      PTR_DAT_0002b7fc[8] = PTR_DAT_0002b7f8[7];
    }
    else if (bVar2 == 2) {
      func_0x0300f068();
      func_0x0300f10c();
      memset_bytes(PTR_DAT_0002b800,0xff,0x18);
      *(ushort *)PTR_DAT_0002b7f0 = *(ushort *)PTR_DAT_0002b7f0 | 0x800;
      PTR_DAT_0002b7fc[8] = PTR_DAT_0002b804[4];
    }
    else if (bVar2 == 4) {
      func_0x03067224();
      *(ushort *)PTR_DAT_0002b7f0 = *(ushort *)PTR_DAT_0002b7f0 | 0x800;
      PTR_DAT_0002b7fc[8] = PTR_DAT_0002b808[5];
    }
    else if (bVar2 == 6) {
      memset_bytes(PTR_DAT_0002b800,0xff,0x18);
      func_0x030645ec();
      *(ushort *)PTR_DAT_0002b7f0 = *(ushort *)PTR_DAT_0002b7f0 | 0x800;
      PTR_DAT_0002b7fc[8] = PTR_DAT_0002b80c[8];
    }
    fd6818b_reg_write(FD6818_PAGE0_REG_3FH,*(undefined2 *)PTR_DAT_0002b7f0);
  }
  fd6818b_reg48_cic_mode_write(*PTR_DAT_0002b810);
  fd6818b_filter_select_then_chipmode_normal();
  fd6818b_reg_write(FD6818_PAGE0_REG_47H,0x6042);
  return;
}

