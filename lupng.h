#pragma once

#include <stdint.h>

typedef struct {
    int32_t width;
    int32_t height;
    uint8_t channels;
    uint8_t depth; // must be 8 or 16
    size_t dataSize;
    uint8_t *data;
} LuImage;

typedef size_t (*PngReadProc)(void *outPtr, size_t size, size_t count, void *userPtr);
typedef size_t (*PngWriteProc)(const void *inPtr, size_t size, size_t count, void *userPtr);

/**
 * Creates a new Image object with the specified attributes.
 * The data store of the Image is allocated but its contents are undefined.
 * Only 8 and 16 bits deep images with 1-4 channels are supported.
 */
LuImage *luImageCreate(size_t width, size_t height, uint8_t channels, uint8_t depth);

/**
 * Releases the memory associated with the given Image object.
 */
void luImageRelease(LuImage *img);

/**
 * Decodes a PNG image with the provided read function into a LuImage struct
 *
 * @param readProc a function pointer to a user-defined function to use for
 * reading the PNG data.
 * @param userPtr an opaque pointer provided as an argument to readProc
 */
LuImage *luPngRead(PngReadProc readProc, void *userPtr);

/**
 * Encodes a LuImage struct to PNG and writes it out using a user-defined write
 * function.
 *
 * @param writeProc a function pointer to a user-defined function that will be
 * used for writing the final PNG data.
 * @param userPtr an opaque pointer provided as an argument to writeProc
 * @param img the LuImage to encode
 */
int luPngWrite(PngWriteProc writeProc, void *userPtr, LuImage *img);
