#ifndef DISCRIMINATOR_H
#define DISCRIMINATOR_H

#include "ram.h"

typedef struct _DISCRIMINATOR 
{
    int numRams;
    RAM * rams;
} DISCRIMINATOR;

void discriminator_create (DISCRIMINATOR *this, int numRams, int numBits);

void discriminator_destroy (DISCRIMINATOR *this);

void discriminator_train (DISCRIMINATOR *this, int *address_array);

int dicriminator_read (DISCRIMINATOR *this, int *address_array);

#endif
