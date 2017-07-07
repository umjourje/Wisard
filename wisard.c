#include "wisard.h"

#include <math.h>
#include <stdlib.h>
#include<stdio.h>

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


    if (inputSize%numBits != 0)
    {
        printf("O valor de inputSize nao e multiplo de numBits\n");
        exit(1);
    }
    
    this->numRams = (inputSize / numBits);
    

	// Inicializar.
	for (int i = 0; i < numDiscriminators; ++i)
		discriminator_create (&this->discriminators[i], this->numRams, numBits);

    // criando vetor de indices embaralhados.
    this->vectorIndexes = wisard_create_shuffled_indexes ((*this).inputSize);

    // Alloquei memória no create. Vou inicializar com zero na função.
    this->vectorAddresses = (int *) malloc (sizeof(int) * (*this).numRams);

}

/*
    Destrói a wisard e seus objetos associados
*/
void wisard_destroy (WISARD *this)
{
    for (int i=0; i < (this->numDiscriminators); ++i)
        discriminator_destroy(&this->discriminators[i]);

	free(this->discriminators);
	
	free(this->vectorIndexes);
  	free(this->vectorAddresses);
}

/*------------------------------------------------------------------------------------------*/

// apresentar a entrada ao discriminador que quero treinar
void wisard_train (WISARD *this, int *entradaBin, int tagClasse)
{
    int *address_array;

    // Gerar o Array de Endereços!
    address_array = wisard_decode_input (this, entradaBin);
    
    /* 
    for (int i=0; i<(*this).numRams; i++)
        printf("%d ", address_array[i]);
    
    printf("\n");
    */
    
    // Usar o vetor de endereços. lol
    discriminator_train (&(*this).discriminators [tagClasse], address_array);
    
}


// Entrada é apresentada à todos os discriminadores
int wisard_classify (WISARD *this, int *entradaBin)
{
    int bestActivation = -1;
    int *address_array;
    int activation;
    int class = 0;

    // Gerar o Array de Endereços, de novo. ='(
    address_array = wisard_decode_input (this, entradaBin);
    
    // Chamar o método de leituraaa
    for (int i = 0; i < (*this).numDiscriminators; ++i)
    {
        activation = dicriminator_read (&(*this).discriminators [i], address_array);

        //printf("Activation for class %d was %d\n", i, activation);
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
    int i, j, k;
    
    // inicializando o vetorEndereços COM ZERO sempre que for decodificar. =)
   
    for (i = 0, j = 0; j < (*this).numRams; i += (*this).numBits, j++)
    {
        this->vectorAddresses [j] =0;
        
        for (k = 0; k < (*this).numBits; k++)
            this->vectorAddresses [j] += pow (2, k) * entradaBin [ (*this).vectorIndexes [i+k] ];
    }
    
    return this->vectorAddresses;

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


