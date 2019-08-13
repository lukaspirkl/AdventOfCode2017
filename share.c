#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "share.h"

char* read(char* filename)
{
    char* buffer = 0;
    long length;
    FILE* f = fopen(filename, "rb");

    if(f)
    {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc (length + 1); // +1 for null terminator
        if (buffer)
        {
            fread(buffer, 1, length, f);
        }
        fclose(f);
        buffer[length] = '\0'; // add terminator at the end
    }

    return buffer;
}
