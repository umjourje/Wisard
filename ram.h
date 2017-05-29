#ifndef RAM_H
#define RAM_H   

#include "basico_wisard.h"

typedef struct _RAM
{
    ull * mem;
} RAM;

void ram_create (RAM *this, int numBits);

void ram_destroy (RAM *this);

#endif
