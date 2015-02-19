#include <stdio.h>

#include "lupng.h"

/*
 * A simple example demonstrating the use of LuPNG for reading and writing
 * PNG images. Reads and decodes an image and re-encodes and writes it to a
 * new file.
 */


static size_t myFread(void *ptr, size_t size, size_t count, void *userPtr)
{
    return fread(ptr, size, count, (FILE *)userPtr);
}

static size_t myFwrite(const void *ptr, size_t size, size_t count, void *userPtr)
{
    return fwrite(ptr, size, count, (FILE *)userPtr);
}

int main(int argc, char **argv)
{
    LuImage *img;
    FILE *f;
    int ret = 1;

    if (argc < 3)
    {
        printf("usage: %s from to\nDecode PNG file 'from'"
                "and re-encode it to 'to'.\n", argv[0]);
        return 1;
    }

    f = fopen(argv[1], "rb");
    img = luPngRead(myFread, f, 0);
    fclose(f);
    if (img)
    {
        f = fopen(argv[2], "wb");
        ret = luPngWrite(myFwrite, f, img);
        fclose(f);
        return ret;
    }

    return ret;
}

