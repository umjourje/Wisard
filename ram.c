#include "ram.h"

#include <math.h>
#include <stdlib.h>

void ram_create (RAM *this, int numBits)
{
	// Alocando memória
	(*this).mem = (int*) malloc(sizeof(int) * pow(2, numBits));

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


// Para implementar o Bleaching, usar += 1;
void ram_train (RAM *this, int address)
{
    (*this).mem [address] = 1;
}


int ram_read (RAM *this, int address)
{
    return (*this).mem [address];
}
