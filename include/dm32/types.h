/* GENERATED FILE - do not edit by hand. */
#ifndef DM32_TYPES_H
#define DM32_TYPES_H

/* Decompiler primitive types, mapped to fixed-width C.
 *
 * `undefinedN` means "N bytes wide, semantics unknown". It is rendered here as an unsigned
 * integer of that exact width: faithful to what the decompiler asserts (a size) without inventing
 * a meaning it never claimed. Do not read `undefined4` as "uint32_t the firmware treats as a
 * number" - it frequently holds a pointer, a packed bitfield, or a struct the analysis has not
 * yet recovered. */
typedef unsigned char      undefined;
typedef unsigned char      undefined1;
typedef unsigned short     undefined2;
typedef unsigned int       undefined3;   /* 3-byte field; widened to 4 for addressability */
typedef unsigned int       undefined4;
typedef unsigned long long undefined5;
typedef unsigned long long undefined6;
typedef unsigned long long undefined7;
typedef unsigned long long undefined8;

typedef unsigned char      byte;
typedef unsigned char      uchar;
typedef unsigned short     ushort;
typedef unsigned short     word;
typedef unsigned int       uint;
typedef unsigned int       uint3;   /* 3-byte unsigned value; widened to 4 like undefined3 */
typedef unsigned int       dword;
typedef unsigned long long ulonglong;
typedef long long          longlong;
typedef unsigned long long qword;

/* `code` is the decompiler's placeholder for "executable code lives at this address". The corpus
 * uses it exclusively in the indirect-call idiom `(*(code *)(...))(args)` - a call through a
 * recovered function-pointer table. Typedef'd to `int` that idiom is a hard error ("called object
 * type 'code' is not a function or function pointer") in ~84 files, because you cannot call an int.
 * Declaring it as an unprototyped FUNCTION type makes `code *` a function pointer, which is what
 * the idiom means and what the call sites already assume.
 *
 * `()` rather than `(void)` is deliberate: the real signatures are genuinely unknown, and an
 * unprototyped function type accepts the varying argument lists the call sites pass without
 * asserting a parameter list the analysis has not recovered. */
typedef int                code();

/* The decompiler emits `bool` for a value it proved is used only as a truth value. That is
 * a decompiler CONCLUSION, not evidence the firmware's own source used a boolean type -
 * the C-SKY ABI returns it in a full register either way. */
typedef unsigned char      bool;
#define true  1
#define false 0

/* ---- Decompiler pseudo-operations ---------------------------------------------------------
 *
 * The decompiler emits these where the ISA has no single C equivalent: a value assembled from
 * narrower pieces, or a flag the hardware computes as a side effect. They are NOT firmware
 * functions - no such symbol exists in the image - so they must be defined here or every file
 * using one fails to compile. Their semantics are exact and documented, which is why they can be
 * defined rather than merely declared.
 *
 * CONCATab(hi, lo): an (a+b)-byte value with `hi` in the high bytes and `lo` in the low bytes.
 * The operand order is high-then-low, as the decompiler emits it, NOT the little-endian byte order
 * the value has in memory - `CONCAT11(p[1], p[0])` is the usual idiom for a 16-bit LE load.
 * CARRYn / SUB4n are the unsigned carry-out of an n-byte add, and a truncation to n bytes. */
#define CONCAT11(hi, lo) ((ushort)(((ushort)(uchar)(hi) << 8) | (uchar)(lo)))
#define CONCAT12(hi, lo) ((uint)(((uint)(uchar)(hi) << 16) | (ushort)(lo)))
#define CONCAT13(hi, lo) ((uint)(((uint)(uchar)(hi) << 24) | ((lo) & 0xffffffU)))
#define CONCAT21(hi, lo) ((uint)(((uint)(ushort)(hi) << 8) | (uchar)(lo)))
#define CONCAT22(hi, lo) ((uint)(((uint)(ushort)(hi) << 16) | (ushort)(lo)))
#define CONCAT31(hi, lo) ((uint)((((uint)(hi) & 0xffffffU) << 8) | (uchar)(lo)))
#define CONCAT44(hi, lo) ((ulonglong)(((ulonglong)(uint)(hi) << 32) | (uint)(lo)))
#define CARRY4(a, b)     ((uint)(b) > (uint)(0xffffffffU - (uint)(a)))
#define SUB41(v, n)      ((uchar)((uint)(v) >> ((n) * 8)))

/* `halt_baddata()` is emitted where the decompiler could not lift an instruction, so it marks a
 * HOLE IN THE RECONSTRUCTION rather than a call the firmware makes - no such symbol exists in the
 * image. Several of these holes have since been identified as real control-register code: the
 * mfcr/mtcr PSR sequences of the uC/OS-III CPU_SR_Save / CPU_SR_Restore pair, which this
 * architecture's lifter does not model. Declared so those functions still type-check; a body that
 * calls it is incomplete, and the comment above the call says which instruction was dropped. */
void halt_baddata(void);

/* `stub()` is the same kind of marker for a call the decompiler could not resolve to any target
 * at all (seen in stub_trap_halt_baddata @0x030bf698). Also not a firmware symbol. */
void stub(void);

/* SUB-PIECE access. The decompiler writes `x._N_M_` for "the M bytes at byte offset N of x", in
 * x's own byte order; that is not C, so it is rewritten to these macros when the source tree is
 * built. Byte 0 is the LEAST significant byte - this core is little-endian, confirmed by
 * composing 11 22 33 44 and getting 0x44332211. The arithmetic is exact: no union, no type
 * punning, and the value is unchanged. A 4-byte piece is the whole word, special-cased because
 * `1u << 32` is undefined. */
#define _DM32_SUBPIECE_MASK(n) ((n) >= 4 ? 0xffffffffu : ((1u << ((n) * 8)) - 1u))
#define SUBPIECE(v, off, n)    (((v) >> ((off) * 8)) & _DM32_SUBPIECE_MASK(n))
#define SUBPIECE_SET(v, off, n, x)     ((v) = ((v) & ~(_DM32_SUBPIECE_MASK(n) << ((off) * 8)))          | ((((unsigned)(x)) & _DM32_SUBPIECE_MASK(n)) << ((off) * 8)))

#endif /* DM32_TYPES_H */
