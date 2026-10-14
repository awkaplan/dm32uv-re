/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: display_scroll_task_loop @ 0002f000 (IRAM address; the boot stub copies these bytes from program flash 0x030dec20)
 * Size: 986 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_scroll_task_loop(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined *puVar4;
  undefined2 uVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  ushort *puVar9;
  uint in_r3;
  int unaff_r4;
  ushort *unaff_r5;
  int unaff_r6;
  int unaff_r8;
  byte *unaff_r10;
  
  stub();
code_r0x0002f002:
  func_0x0002f06c(PTR_DAT_0002f060,PTR_DAT_0002f05c + in_r3 * 0x1b,0x1b);
  if (*unaff_r10 == 0) {
    *PTR_DAT_0002f064 = 1;
  }
  else {
    *PTR_DAT_0002f064 = 0;
  }
LAB_0002ed76:
  func_0x0002e3f0(PTR_DAT_0002eed0,unaff_r4 + *(byte *)(unaff_r4 + 0x1493) + 0x1478,0x48);
  puVar4 = PTR_DAT_0002f050;
  if (((*(char *)(unaff_r4 + 0x1497) == '\0') || (*(char *)(unaff_r8 + 0x1498) == '\0')) &&
     (*(char *)(unaff_r4 + 0x1495) == '\0')) {
    sVar6 = *(short *)(unaff_r8 + 0x1164);
    *(undefined2 *)(unaff_r8 + 0x1154) = *(undefined2 *)(unaff_r8 + 0x1152);
    bVar1 = *unaff_r10;
    uVar5 = func_0x000182bc(puVar4,(int)*(short *)(unaff_r8 + 0x1168),puVar4,1);
    uVar3 = *(ushort *)(unaff_r8 + 0x1164);
    bVar2 = *unaff_r10;
    *(undefined2 *)(unaff_r8 + ((uint)bVar1 * 3 + (int)sVar6 + 0x8aa) * 2 + 2) = uVar5;
    func_0x000188a4(PTR_DAT_0002f058 + (uint)uVar3 * 0x34 + (uint)bVar2 * 0x9c,PTR_DAT_0002f054);
  }
  func_0x00016ca4(PTR_DAT_0002eed4,
                  PTR_DAT_0002eec8 +
                  (uint)*(ushort *)(unaff_r4 + 0x1164) * 0x34 + (uint)*unaff_r10 * 0x9c);
  iVar8 = unaff_r4 + *(short *)(unaff_r4 + 0x1164) * 0x34 + (uint)*unaff_r10 * 0x9c;
  uVar5 = *(undefined2 *)(iVar8 + 0x1038);
  *(undefined2 *)(unaff_r4 + 0x1476) = *(undefined2 *)(iVar8 + 0x1048);
  *(undefined2 *)(unaff_r4 + 0x1474) = uVar5;
  puVar9 = (ushort *)PTR_DAT_0002eed0;
  do {
    *puVar9 = *puVar9 ^ puVar9[0x48];
    puVar9 = puVar9 + 1;
  } while (puVar9 != unaff_r5);
  if (*(char *)(unaff_r4 + 0x1495) == '\0') {
    func_0x00016cdc((*(short *)(unaff_r8 + 0x134e) + 0x8b6) * 2 + unaff_r8 + 2,0x50,PTR_DAT_0002eed0
                    ,(int)*(short *)(unaff_r8 + 0x1166));
  }
  else {
    func_0x00016cdc((*(short *)(unaff_r8 + 0x134e) + 0x8b6) * 2 + unaff_r8 + 2,0x50,PTR_DAT_0002f050
                    ,(int)*(short *)(unaff_r8 + 0x1166));
  }
  sVar7 = *(short *)(unaff_r4 + 0x1352) + 0x50;
  sVar6 = (short)(*(short *)(unaff_r4 + 0x134e) + 0x50) % 0xa0;
  *(undefined2 *)(unaff_r4 + 0x1162) = 1;
  *(short *)(unaff_r4 + 0x134e) = sVar6;
  *(short *)(unaff_r4 + 0x1352) = sVar7;
  if (0x9f < sVar7) goto LAB_0002ec5c;
  if (*(char *)(unaff_r8 + 0x1495) != '\0') goto LAB_0002eee2;
  do {
    sVar7 = *(short *)(unaff_r8 + 0x1166);
    while( true ) {
      func_0x00016cdc((sVar6 + 0x8b6) * 2 + unaff_r8 + 2,0x50,PTR_DAT_0002eed0,(int)sVar7);
      sVar6 = *(short *)(unaff_r4 + 0x1164) + 1;
      *(undefined2 *)(unaff_r4 + 0x1162) = 0;
      *(short *)(unaff_r4 + 0x134e) = (short)(*(short *)(unaff_r4 + 0x134e) + 0x50) % 0xa0;
      *(short *)(unaff_r4 + 0x1352) = *(short *)(unaff_r4 + 0x1352) + 0x50;
      *(short *)(unaff_r4 + 0x1164) = sVar6;
      *(char *)(unaff_r4 + 0x1493) = *(char *)(unaff_r4 + 0x1493) + '\t';
      if (2 < sVar6) {
        *(undefined2 *)(unaff_r8 + 0x1164) = 0;
        *(undefined1 *)(unaff_r8 + 0x1493) = 0;
      }
LAB_0002ec5c:
      do {
        OSTaskSemPend(0,0);
      } while (*(char *)(unaff_r4 + unaff_r6) == '\0');
      if (*(short *)(unaff_r8 + 0x1162) == 0) {
        if (*(short *)(unaff_r8 + 0x1164) != 0) goto LAB_0002ed76;
        if (*(char *)(unaff_r8 + 0x1497) == '\x01') {
          if (*(char *)(unaff_r8 + 0x1494) != '\x01') {
            func_0x000172cc(0,PTR_DAT_0002f060,0x1b);
            if (*(char *)(unaff_r8 + 0x1498) == '\x01') {
              func_0x00016890(PTR_DAT_0002f060);
            }
            func_0x0002ebe0();
            in_r3 = (uint)*unaff_r10;
            goto code_r0x0002f002;
          }
        }
        else if (*(char *)(unaff_r8 + 0x1494) != '\x01') {
          func_0x000172cc(0,PTR_DAT_0002eed8,0x1b);
          if (*(char *)(unaff_r8 + 0x1496) == '\x01') {
            func_0x0002ebe0();
          }
          goto LAB_0002ed76;
        }
        func_0x0002f06c(PTR_DAT_0002f060,PTR_DAT_0002f05c + (uint)*unaff_r10 * 0x1b,0x1b);
        if (*unaff_r10 == 0) {
          *PTR_DAT_0002f064 = 1;
        }
        else {
          *PTR_DAT_0002f064 = 0;
        }
        func_0x00016294(PTR_DAT_0002f068);
        goto LAB_0002ed76;
      }
      if (*(char *)(unaff_r8 + 0x1495) == '\0') break;
      sVar6 = *(short *)(unaff_r8 + 0x134e);
LAB_0002eee2:
      sVar7 = *(short *)(unaff_r8 + 0x1166);
    }
    sVar6 = *(short *)(unaff_r8 + 0x134e);
  } while( true );
}

