#include "wisard.h"

#include <stdlib.h>

void wisard_create(WISARD *this, int numDiscriminators, int inputSize ,int numBits)
{
	(*this).numDiscriminators = numDiscriminators;
	
	// Alocar não é inicializar.
	this->discriminators = (DISCRIMINATOR*) malloc(sizeof(DISCRIMINATOR) * numDiscriminators);


    int numRams = (inputSize / numBits);
	// Inicializar.
	for (int i = 0; i < numDiscriminators; ++i)
		discriminator_create (&this->discriminators[i], numRams, numBits);
}

void wisard_destroy (WISARD *this)
{
    for (int i=0; i < (this->numDiscriminators); ++i)
        discriminator_destroy(&this->discriminators[i]);

	free(this->discriminators);
}

