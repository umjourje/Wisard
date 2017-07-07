#include "discriminator.h"

#include <stdlib.h>

void discriminator_create (DISCRIMINATOR *this, int numRams, int numBits)
{
	// Aloquei a memória
	(*this).numRams = numRams;
	(*this).rams = (RAM*) malloc (sizeof(RAM) * numRams);

	// Inicializar só.
	for (int i=0; i < numRams; ++i)
		ram_create (&this->rams[i], numBits);
}

void discriminator_destroy (DISCRIMINATOR *this)
{
    for (int i=0; i < this->numRams; ++i)
		ram_destroy (&this->rams[i]);

	free(this->rams);
}

void discriminator_train (DISCRIMINATOR *this, int *address_array)
{
    int i;
    
    for (i = 0; i < (*this).numRams; ++i)
    {
        ram_train (&(*this).rams[i], address_array[i]);
    }
}

int dicriminator_read (DISCRIMINATOR *this, int *address_array)
{
    int i;
    int somatorio = 0;
    
    for (i = 0; i < (*this).numRams; ++i)
    {
        somatorio += ram_read(&(*this).rams[i], address_array[i]);
    }
    
    return somatorio;
}

