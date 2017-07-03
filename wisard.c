#include "wisard.h"

#include <math.h>
#include <stdlib.h>

/*
    Inicializa um objeto wisard
*/
void wisard_create(WISARD *this, int numDiscriminators, int inputSize, int numBits)
{
    // Inicializando os valores recebidos para dentro da Estrutura (this)
	this->numDiscriminators = numDiscriminators;
	this->inputSize = inputSize;
	this->numBits = numBits;
	
	// Alocar não é inicializar.
	this->discriminators = (DISCRIMINATOR*) malloc(sizeof(DISCRIMINATOR) * numDiscriminators);

    this->numRams = (inputSize / numBits);

	// Inicializar.
	for (int i = 0; i < numDiscriminators; ++i)
		discriminator_create (&this->discriminators[i], this->numRams, numBits);

    // criando vetor de indices embaralhados.
    this->vetorIndices = wisard_create_shuffled_indexes ((*this).inputSize);

}

/*
    Destrói a wisard e seus objetos associados
*/
void wisard_destroy (WISARD *this)
{
    for (int i=0; i < (this->numDiscriminators); ++i)
        discriminator_destroy(&this->discriminators[i]);

	free(this->discriminators);
}

/*------------------------------------------------------------------------------------------*/

// apresentar a entrada ao discriminador que quero treinar
void wisard_train (WISARD *this, int *entradaBin, int tagClasse)
{
    int *address_array;

    // Gerar o Array de Endereços!
    address_array = wisard_decode_input (this, entradaBin);
    
    
    // Usar o vetor de endereços. lol
    discriminator_train (&(*this).discriminators [tagClasse], address_array);
    
}


// Entrada é apresentada à todos os discriminadores
int wisard_classify (WISARD *this, int *entradaBin)
{
    int *address_array;
    int bestActivation = -1, activation, class, i;
    

    // Gerar o Array de Endereços, de novo. =(
    address_array = wisard_decode_input (this, entradaBin);
    
    // Chamar o método de leituraaa
    for (i = 0; i < (*this).numDiscriminators; ++i)
    {
        activation = dicriminator_read (&(*this).discriminators [i], address_array);

        if (bestActivation < activation)
        {   
            bestActivation = activation;
            class = i;
        }
        
    }

    return class;
}



/*------------------------------------------------------------------------------------------*/

int *wisard_decode_input (WISARD *this, int *entradaBin)
{

    // dar free depois!
    int *vetorEnderecos = (int *) malloc (sizeof(int) * (*this).numRams);

    int i, j, k;

    for (i = 0, j = 0; i < (*this).numRams; i += (*this).numBits, j++)
    {
        for (k =0; k < (*this).numBits; k++)
            vetorEnderecos [i] = pow (2, k) * entradaBin [ (*this).vetorIndices [j] ];
    }
    
    return vetorEnderecos;

}

/*------------------------------------------------------------------------------------------*/

int *wisard_create_shuffled_indexes (int inputSize)
{

    int *vetorIndices;
    
    int indiceVetor, indiceAleatorio, valorIndiceContinuo;
    
    // allocando o vetor de indices.
    vetorIndices = (int*) malloc (sizeof(int) * inputSize);
    
    // Criando o Vetor Ordenado.
	for (indiceVetor = 0; indiceVetor < inputSize; indiceVetor++)
		vetorIndices [indiceVetor] = indiceVetor;
    
    
    // Método do Diego.
    for (indiceVetor = 0; indiceVetor < (inputSize-1); indiceVetor++)
    {

    	// Variável que recebe o indice Aleatório.
    	indiceAleatorio = rand() % (inputSize - indiceVetor);

        
        // Colocando o Valor do índice sorteado dentro do primeiro.
        valorIndiceContinuo = vetorIndices [indiceVetor];
        
        // Colocar o valor da posição randômica na posição de indiceVetor.
        vetorIndices [indiceVetor] = vetorIndices [indiceAleatorio];
        
        
        // Colocando o valor Salvo numa variavel temporária dentro do lugar que foi sorteado.
        vetorIndices [indiceAleatorio] = valorIndiceContinuo;
    }

    return vetorIndices;

}


