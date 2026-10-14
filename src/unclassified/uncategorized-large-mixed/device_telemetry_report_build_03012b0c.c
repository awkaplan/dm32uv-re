/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: device_telemetry_report_build @ 03012b0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 496 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void device_telemetry_report_build(void)

{
  void *dest;
  undefined4 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  uint uVar7;
  
  dest = p_text_entry_buffer;
  memset_bytes(p_text_entry_buffer,0,0x154);
  puVar2 = p_dm32_settings_block04;
  puVar1 = PTR_PTR_03012d08;
  pvVar5 = *(void **)PTR_PTR_03012d08[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2];
  uVar3 = strlen_ck803s(pvVar5);
  uVar3 = uVar3 & 0xff;
  memcpy_ck803s(dest,pvVar5,uVar3);
  *(undefined1 *)((int)dest + uVar3) = 10;
  uVar3 = uVar3 + 1 & 0xff;
  iVar4 = uVar3 + (int)dest;
  radio_telemetry_format_dispatch(0,iVar4);
  *(undefined1 *)(iVar4 + 10) = 10;
  uVar7 = uVar3 + 0xb & 0xff;
  pvVar6 = *(void **)(puVar1[((byte)puVar2[0x30] >> 6 & 1) * 2] + 4);
  uVar3 = strlen_ck803s(pvVar6);
  uVar3 = uVar3 & 0xff;
  pvVar5 = (void *)(uVar7 + (int)dest);
  memcpy_ck803s(pvVar5,pvVar6,uVar3);
  *(undefined1 *)((int)pvVar5 + uVar3) = 10;
  uVar3 = uVar3 + 1 + uVar7 & 0xff;
  iVar4 = uVar3 + (int)dest;
  radio_telemetry_format_dispatch(1,iVar4);
  *(undefined1 *)(iVar4 + 0xb) = 10;
  uVar7 = uVar3 + 0xc & 0xff;
  pvVar6 = *(void **)(puVar1[((byte)puVar2[0x30] >> 6 & 1) * 2] + 8);
  uVar3 = strlen_ck803s(pvVar6);
  uVar3 = uVar3 & 0xff;
  pvVar5 = (void *)(uVar7 + (int)dest);
  memcpy_ck803s(pvVar5,pvVar6,uVar3);
  *(undefined1 *)((int)pvVar5 + uVar3) = 10;
  uVar3 = uVar3 + 1 + uVar7 & 0xff;
  iVar4 = uVar3 + (int)dest;
  radio_telemetry_format_dispatch(2,iVar4);
  *(undefined1 *)(iVar4 + 8) = 10;
  uVar7 = uVar3 + 9 & 0xff;
  pvVar6 = *(void **)(puVar1[((byte)puVar2[0x30] >> 6 & 1) * 2] + 0xc);
  uVar3 = strlen_ck803s(pvVar6);
  uVar3 = uVar3 & 0xff;
  pvVar5 = (void *)(uVar7 + (int)dest);
  memcpy_ck803s(pvVar5,pvVar6,uVar3);
  *(undefined1 *)((int)pvVar5 + uVar3) = 10;
  uVar3 = uVar3 + 1 + uVar7 & 0xff;
  iVar4 = uVar3 + (int)dest;
  radio_telemetry_format_dispatch(3,iVar4);
  *(undefined1 *)(iVar4 + 5) = 10;
  uVar7 = uVar3 + 6 & 0xff;
  pvVar6 = *(void **)(puVar1[((byte)puVar2[0x30] >> 6 & 1) * 2] + 0x10);
  uVar3 = strlen_ck803s(pvVar6);
  uVar3 = uVar3 & 0xff;
  pvVar5 = (void *)(uVar7 + (int)dest);
  memcpy_ck803s(pvVar5,pvVar6,uVar3);
  *(undefined1 *)((int)pvVar5 + uVar3) = 10;
  uVar3 = uVar3 + 1 + uVar7 & 0xff;
  iVar4 = uVar3 + (int)dest;
  radio_telemetry_format_dispatch(4,iVar4);
  *(undefined1 *)(iVar4 + 2) = 10;
  uVar7 = uVar3 + 3 & 0xff;
  pvVar6 = *(void **)(puVar1[((byte)puVar2[0x30] >> 6 & 1) * 2] + 0x14);
  uVar3 = strlen_ck803s(pvVar6);
  uVar3 = uVar3 & 0xff;
  pvVar5 = (void *)(uVar7 + (int)dest);
  memcpy_ck803s(pvVar5,pvVar6,uVar3);
  *(undefined1 *)((int)pvVar5 + uVar3) = 10;
  uVar3 = uVar3 + 1 + uVar7 & 0xff;
  iVar4 = uVar3 + (int)dest;
  radio_telemetry_format_dispatch(5,iVar4);
  *(undefined1 *)(iVar4 + 8) = 10;
  uVar7 = uVar3 + 9 & 0xff;
  pvVar6 = *(void **)(puVar1[((byte)puVar2[0x30] >> 6 & 1) * 2] + 0x18);
  uVar3 = strlen_ck803s(pvVar6);
  uVar3 = uVar3 & 0xff;
  pvVar5 = (void *)(uVar7 + (int)dest);
  memcpy_ck803s(pvVar5,pvVar6,uVar3);
  *(undefined1 *)((int)pvVar5 + uVar3) = 10;
  iVar4 = (int)dest + (uVar7 + uVar3 + 1 & 0xff);
  radio_telemetry_format_dispatch(6,iVar4);
  *(undefined1 *)(iVar4 + 10) = 10;
  return;
}

