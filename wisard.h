#ifndef WISARD_H
#define WISARD_H

#include "discriminator.h"

typedef struct _WISARD
{
	int numDiscriminators;
	int numRams;
	int inputSize;
	int numBits;
	DISCRIMINATOR * discriminators;
} WISARD;

void wisard_create(WISARD *this, int numDiscriminators, int inputSize ,int numBits);

void wisard_destroy (WISARD *this);

void wisard_train (WISARD *this, ull *entradaBin, int tagClasse);

// Passar a resposta da classificação por referência para *tagClasse.
void wisard_classify (WISARD *this, ull *entradaBin, int *tagClasse);


typedef unsigned long long  ull;

#endif
