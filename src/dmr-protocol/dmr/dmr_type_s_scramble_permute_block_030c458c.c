/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_type_s_scramble_permute_block @ 030c458c (file base 0x03000000; code starts at 0x03001000)
 * Size: 2234 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_type_s_scramble_permute_block(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  uint uVar21;
  uint uVar22;
  byte bVar23;
  byte bVar24;
  uint uVar25;
  uint uVar26;
  byte bVar27;
  uint uVar28;
  byte bVar29;
  byte bVar30;
  byte bVar31;
  uint uVar32;
  uint uVar33;
  byte bVar34;
  byte bVar35;
  byte bVar36;
  uint uVar37;
  uint uVar38;
  byte bVar39;
  byte bVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  byte bVar45;
  byte bVar46;
  byte bVar47;
  byte bVar48;
  byte bVar49;
  byte bVar50;
  byte bVar51;
  byte bStack_ec;
  byte bStack_e4;
  
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) << 0xc;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) << 0xc;
  bVar1 = param_1[6];
  bVar18 = bVar1 >> 2 & 1;
  *(int *)param_1 = *(int *)param_1 << 0xc;
  bVar36 = param_1[9] >> 7;
  bVar2 = param_1[2];
  bVar17 = param_1[10];
  bVar40 = param_1[5] >> 7;
  uVar12 = bVar2 >> 2 & 1;
  uVar28 = bVar17 >> 2 & 1;
  bVar3 = param_1[1] >> 7;
  bVar4 = bVar18 ^ bVar40;
  uVar32 = bVar3 ^ uVar12;
  uVar41 = bVar36 ^ uVar28;
  bVar23 = bVar1 >> 1 & 1;
  bVar19 = bVar2 >> 1 & 1;
  bVar27 = bVar17 >> 1 & 1;
  bVar48 = param_1[1] >> 6 & 1;
  bVar10 = param_1[5] >> 6 & 1;
  bVar15 = param_1[9] >> 6 & 1;
  bVar29 = param_1[1] >> 4 & 1;
  bVar34 = bVar2 >> 3 & 1;
  bVar39 = param_1[5] >> 4 & 1;
  bVar45 = bVar1 >> 3 & 1;
  bVar11 = bVar17 >> 3 & 1;
  bVar16 = bVar2 >> 4 & 1;
  bVar24 = bVar17 >> 4 & 1;
  bVar49 = param_1[9] >> 4 & 1;
  bVar20 = bVar1 >> 4 & 1;
  bVar5 = bVar2 >> 7;
  bVar6 = bVar1 >> 7;
  uVar25 = bVar2 >> 5 & 1;
  bVar7 = bVar17 >> 7;
  uVar21 = bVar1 >> 5 & 1;
  uVar13 = bVar17 >> 5 & 1;
  bVar50 = bVar2 & 1;
  bVar46 = param_1[1] >> 5 & 1;
  bVar30 = param_1[5] >> 5 & 1;
  bVar47 = bVar1 & 1;
  bVar31 = bVar17 & 1;
  bVar51 = param_1[9] >> 5 & 1;
  uVar8 = bVar2 >> 6 & 1;
  uVar37 = bVar17 >> 6 & 1;
  uVar38 = uVar25 ^ bVar5;
  uVar33 = uVar13 ^ bVar7;
  bVar2 = bVar29 ^ bVar3 ^ bVar19 ^ bVar34;
  bVar35 = bVar39 ^ bVar40 ^ bVar23 ^ bVar45;
  uVar14 = bVar1 >> 6 & 1;
  bVar17 = bVar36 ^ bVar49 ^ bVar27 ^ bVar11;
  uVar42 = uVar8 ^ bVar5;
  uVar43 = uVar14 ^ bVar6;
  uVar9 = uVar21 ^ bVar6;
  uVar44 = uVar37 ^ bVar7;
  bStack_ec = (byte)uVar12;
  uVar26 = uVar25 ^ bVar16 ^ uVar42;
  uVar22 = uVar21 ^ bVar20 ^ uVar43;
  uVar12 = uVar13 ^ bVar24 ^ uVar44;
  bStack_e4 = (byte)uVar28;
  bVar1 = bVar48 ^ bVar3 ^ bVar46;
  bVar40 = bVar10 ^ bVar40 ^ bVar30;
  bVar36 = bVar15 ^ bVar36 ^ bVar51;
  param_1[1] = param_1[1] & 0xf0 | (byte)(((bVar29 ^ bVar46) ^ uVar38 ^ uVar32 ^ bVar48) << 3) |
               (byte)((uVar32 ^ bVar19 ^ uVar26) << 2) |
               (byte)(((bVar19 ^ bVar16) ^ uVar32 ^ uVar8 ^ uVar25) << 1) |
               bVar16 ^ (byte)uVar25 ^ bVar34 ^ bVar46 ^ bVar50 ^ (byte)uVar32;
  *param_1 = (byte)(((uint)(bVar19 ^ bVar29) ^ uVar32 ^ bVar48 ^ (uint)(bVar34 ^ bVar16)) << 7) |
             (byte)((uVar38 ^ bVar50 ^ (uint)bVar2) << 6) |
             (byte)(((byte)(bVar29 ^ bVar46 ^ bVar50) ^ uVar26) << 5) |
             (byte)(((byte)(bVar48 ^ bStack_ec ^ bVar46 ^ bVar16 ^ bVar34) ^ uVar42) << 4) |
             (byte)(((uint)(byte)(bVar46 ^ bStack_ec ^ bVar29 ^ bVar19 ^ bVar34) ^ uVar8 ^ uVar25)
                   << 3) | (bVar50 ^ bVar19 ^ bVar16 ^ bVar5 ^ bVar1) << 2 |
             (byte)((bVar34 ^ uVar8 ^ (uint)(byte)(bVar50 ^ bVar29 ^ bVar1)) << 1) |
             bVar2 ^ (byte)uVar42;
  param_1[5] = param_1[5] & 0xf0 | (byte)(((bVar39 ^ bVar30) ^ uVar9 ^ (uint)(bVar4 ^ bVar10)) << 3)
               | (byte)(((bVar4 ^ bVar23) ^ uVar22) << 2) |
               (byte)(((uint)(byte)(bVar23 ^ bVar20 ^ bVar4) ^ uVar14 ^ uVar21) << 1) |
               bVar45 ^ bVar30 ^ bVar47 ^ bVar4 ^ bVar20 ^ (byte)uVar21;
  param_1[4] = (bVar23 ^ bVar39 ^ bVar4 ^ bVar10 ^ bVar45 ^ bVar20) << 7 |
               (byte)((uVar9 ^ bVar47 ^ (uint)bVar35) << 6) |
               (byte)(((byte)(bVar39 ^ bVar30 ^ bVar47) ^ uVar22) << 5) |
               (byte)(((byte)(bVar10 ^ bVar18 ^ bVar30 ^ bVar20 ^ bVar45) ^ uVar43) << 4) |
               (byte)(((uint)(byte)(bVar30 ^ bVar18 ^ bVar39 ^ bVar23 ^ bVar45) ^ uVar14 ^ uVar21)
                     << 3) | (bVar40 ^ bVar20 ^ bVar6 ^ bVar47 ^ bVar23) << 2 |
               (byte)(((uint)(byte)(bVar47 ^ bVar39 ^ bVar40) ^ bVar45 ^ uVar14) << 1) |
               bVar35 ^ (byte)uVar43;
  param_1[9] = param_1[9] & 0xf0 | (byte)(((bVar49 ^ bVar51) ^ uVar33 ^ uVar41 ^ bVar15) << 3) |
               (byte)((uVar41 ^ bVar27 ^ uVar12) << 2) |
               (byte)(((bVar27 ^ bVar24) ^ uVar41 ^ uVar37 ^ uVar13) << 1) |
               bVar11 ^ bVar51 ^ bVar31 ^ (byte)uVar41 ^ bVar24 ^ (byte)uVar13;
  param_1[8] = (byte)(((uint)(bVar11 ^ bVar24) ^ uVar41 ^ bVar15 ^ (uint)(bVar27 ^ bVar49)) << 7) |
               (byte)((uVar33 ^ bVar31 ^ (uint)bVar17) << 6) |
               (byte)(((byte)(bVar49 ^ bVar51 ^ bVar31) ^ uVar12) << 5) |
               (byte)(((byte)(bVar15 ^ bStack_e4 ^ bVar51 ^ bVar24 ^ bVar11) ^ uVar44) << 4) |
               (byte)(((uint)(byte)(bVar51 ^ bStack_e4 ^ bVar49 ^ bVar27 ^ bVar11) ^ uVar37 ^ uVar13
                      ) << 3) | (bVar31 ^ bVar27 ^ bVar24 ^ bVar7 ^ bVar36) << 2 |
               (byte)(((uint)(byte)(bVar31 ^ bVar49 ^ bVar36) ^ bVar11 ^ uVar37) << 1) |
               bVar17 ^ (byte)uVar44;
  return;
}

