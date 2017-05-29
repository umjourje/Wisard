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
	free(this->rams);
}

