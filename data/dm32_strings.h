/*
 * Source binary: DM32.00.01.048.bin (whole image, load base 0x03000000)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Generated output - DO NOT EDIT BY HAND; regenerate instead.
 * Confidence: STRUCTURAL
 */

#ifndef DM32_STRINGS_H
#define DM32_STRINGS_H

struct dm32_string {
    unsigned int addr;      /* flash CPU address */
    int          referenced;/* address appears as a word elsewhere in the image */
    const char  *text;
};

extern const struct dm32_string dm32_strings[];
extern const unsigned dm32_strings_count;

#endif
