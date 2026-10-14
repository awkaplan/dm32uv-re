/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0301d27c @ 0301d27c (file base 0x03000000; code starts at 0x03001000)
 * Size: 508 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0301d27c(uint param_1,int param_2,int param_3)

{
  dword dVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 < 0x20) {
    if (param_2 == 0) {
      dVar1 = GPIOA_14020000.INTTYPE_LEVEL;
      GPIOA_14020000.INTTYPE_LEVEL =
           (-2 << (param_1 & 0x3f) | 0xfffffffeU >> 0x20 - (param_1 & 0x3f)) & dVar1;
    }
    else {
      dVar1 = GPIOA_14020000.INTTYPE_LEVEL;
      GPIOA_14020000.INTTYPE_LEVEL = 1 << (param_1 & 0x3f) | dVar1;
    }
    if (param_3 == 2) {
      dVar1 = GPIOA_14020000.INTR_BOTH_EDGE;
      GPIOA_14020000.INTR_BOTH_EDGE = 1 << (param_1 & 0x3f) | dVar1;
    }
    else if (param_3 == 1) {
      dVar1 = GPIOA_14020000.INT_POLARITY;
      uVar2 = 1 << (param_1 & 0x3f);
      GPIOA_14020000.INT_POLARITY = dVar1 | uVar2;
      dVar1 = GPIOA_14020000.INTR_BOTH_EDGE;
      GPIOA_14020000.INTR_BOTH_EDGE = dVar1 & ~uVar2;
    }
    else {
      dVar1 = GPIOA_14020000.INT_POLARITY;
      uVar2 = -2 << (param_1 & 0x3f) | 0xfffffffeU >> 0x20 - (param_1 & 0x3f);
      GPIOA_14020000.INT_POLARITY = dVar1 & uVar2;
      dVar1 = GPIOA_14020000.INTR_BOTH_EDGE;
      GPIOA_14020000.INTR_BOTH_EDGE = uVar2 & dVar1;
    }
    dVar1 = GPIOA_14020000.SWPORTA_DDR;
    uVar2 = 1 << (param_1 & 0x3f);
    uVar3 = ~uVar2;
    GPIOA_14020000.SWPORTA_DDR = dVar1 & uVar3;
    dVar1 = GPIOA_14020000.INTMASK;
    GPIOA_14020000.INTMASK = uVar3 & dVar1;
    dVar1 = GPIOA_14020000.INTEN;
    GPIOA_14020000.INTEN = uVar2 | dVar1;
  }
  else if (param_1 < 0x40) {
    if (param_2 == 0) {
      dVar1 = GPIOB_14100000.INTTYPE_LEVEL;
      uVar2 = param_1 - 0x20 & 0x3f;
      GPIOB_14100000.INTTYPE_LEVEL = (-2 << uVar2 | 0xfffffffeU >> 0x20 - uVar2) & dVar1;
    }
    else {
      dVar1 = GPIOB_14100000.INTTYPE_LEVEL;
      GPIOB_14100000.INTTYPE_LEVEL = 1 << (param_1 - 0x20 & 0x3f) | dVar1;
    }
    if (param_3 == 2) {
      dVar1 = GPIOB_14100000.INTR_BOTH_EDGE;
      GPIOB_14100000.INTR_BOTH_EDGE = 1 << (param_1 - 0x20 & 0x3f) | dVar1;
    }
    else if (param_3 == 1) {
      dVar1 = GPIOB_14100000.INT_POLARITY;
      uVar2 = 1 << (param_1 - 0x20 & 0x3f);
      GPIOB_14100000.INT_POLARITY = dVar1 | uVar2;
      dVar1 = GPIOB_14100000.INTR_BOTH_EDGE;
      GPIOB_14100000.INTR_BOTH_EDGE = dVar1 & ~uVar2;
    }
    else {
      dVar1 = GPIOB_14100000.INT_POLARITY;
      uVar2 = param_1 - 0x20 & 0x3f;
      uVar2 = -2 << uVar2 | 0xfffffffeU >> 0x20 - uVar2;
      GPIOB_14100000.INT_POLARITY = dVar1 & uVar2;
      dVar1 = GPIOB_14100000.INTR_BOTH_EDGE;
      GPIOB_14100000.INTR_BOTH_EDGE = uVar2 & dVar1;
    }
    dVar1 = GPIOB_14100000.SWPORTA_DDR;
    uVar2 = 1 << (param_1 - 0x20 & 0x3f);
    uVar3 = ~uVar2;
    GPIOB_14100000.SWPORTA_DDR = dVar1 & uVar3;
    dVar1 = GPIOB_14100000.INTMASK;
    GPIOB_14100000.INTMASK = uVar3 & dVar1;
    dVar1 = GPIOB_14100000.INTEN;
    GPIOB_14100000.INTEN = uVar2 | dVar1;
  }
  else {
    if (param_2 == 0) {
      dVar1 = GPIOC_14110000.INTTYPE_LEVEL;
      uVar2 = param_1 - 0x40 & 0x3f;
      GPIOC_14110000.INTTYPE_LEVEL = (-2 << uVar2 | 0xfffffffeU >> 0x20 - uVar2) & dVar1;
    }
    else {
      dVar1 = GPIOC_14110000.INTTYPE_LEVEL;
      GPIOC_14110000.INTTYPE_LEVEL = 1 << (param_1 - 0x40 & 0x3f) | dVar1;
    }
    if (param_3 == 2) {
      dVar1 = GPIOC_14110000.INTR_BOTH_EDGE;
      GPIOC_14110000.INTR_BOTH_EDGE = 1 << (param_1 - 0x40 & 0x3f) | dVar1;
    }
    else if (param_3 == 1) {
      dVar1 = GPIOC_14110000.INT_POLARITY;
      uVar2 = 1 << (param_1 - 0x40 & 0x3f);
      GPIOC_14110000.INT_POLARITY = dVar1 | uVar2;
      dVar1 = GPIOC_14110000.INTR_BOTH_EDGE;
      GPIOC_14110000.INTR_BOTH_EDGE = dVar1 & ~uVar2;
    }
    else {
      dVar1 = GPIOC_14110000.INT_POLARITY;
      uVar2 = param_1 - 0x40 & 0x3f;
      uVar2 = -2 << uVar2 | 0xfffffffeU >> 0x20 - uVar2;
      GPIOC_14110000.INT_POLARITY = dVar1 & uVar2;
      dVar1 = GPIOC_14110000.INTR_BOTH_EDGE;
      GPIOC_14110000.INTR_BOTH_EDGE = uVar2 & dVar1;
    }
    dVar1 = GPIOC_14110000.SWPORTA_DDR;
    uVar2 = 1 << (param_1 - 0x40 & 0x3f);
    uVar3 = ~uVar2;
    GPIOC_14110000.SWPORTA_DDR = dVar1 & uVar3;
    dVar1 = GPIOC_14110000.INTMASK;
    GPIOC_14110000.INTMASK = uVar3 & dVar1;
    dVar1 = GPIOC_14110000.INTEN;
    GPIOC_14110000.INTEN = uVar2 | dVar1;
  }
  return;
}

