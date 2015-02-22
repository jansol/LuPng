#include <stdio.h>

#include "lupng.h"

/*
 * A simple example demonstrating the use of LuPNG for reading and writing
 * PNG images. Reads and decodes an image and re-encodes and writes it to a
 * new file.
 */

int main(int argc, char **argv)
{
    LuImage *img;
    int ret = 1;

    if (argc < 3)
    {
        printf("usage: %s from to\nDecode PNG file 'from'"
                "and re-encode it to 'to'.\n", argv[0]);
        return 1;
    }

    img = luPngReadFile(argv[1]);
    if (img)
    {
        ret = luPngWriteFile(argv[2], img);
        luImageRelease(img, NULL);
    }

    return ret;
}

