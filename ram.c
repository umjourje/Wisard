#include "ram.h"

#include <math.h>
#include <stdlib.h>

void ram_create (RAM *this, int numBits)
{
	// Alocando memória
	(*this).mem = (ull*) malloc(sizeof(ull) * pow(2, numBits));

	// Inicializar com ZERO.
	for (int i=0; i < numBits; ++i)
	{
		this->mem[i] = 0;
	}
}

void ram_destroy (RAM *this)
{
    free (this->mem);
}
