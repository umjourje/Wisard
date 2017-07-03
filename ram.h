#ifndef RAM_H
#define RAM_H   

typedef struct _RAM
{
    int * mem;
} RAM;

void ram_create (RAM *this, int numBits);

void ram_destroy (RAM *this);

void ram_train (RAM *this, int address);

int ram_read (RAM *this, int address);

#endif
