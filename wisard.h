#ifndef WISARD_H
#define WISARD_H

#include "discriminator.h"

typedef struct _WISARD
{
	int numDiscriminators;
	int numRams;
	int inputSize;
	int numBits;
	int * vetorIndices;
	DISCRIMINATOR * discriminators;
} WISARD;

void wisard_create(WISARD *this, int numDiscriminators, int inputSize, int numBits);

void wisard_destroy (WISARD *this);

void wisard_train (WISARD *this, int *entradaBin, int tagClasse);

// Passar a resposta da classificação por referência para *tagClasse.
int wisard_classify (WISARD *this, int *entradaBin);

int *wisard_create_shuffled_indexes (int inputSize);

int *wisard_decode_input (WISARD *this, int *entradaBin);


#endif
