#include "wisard.h"

#include <stdlib.h>


void wisard_create(WISARD *this, int numDiscriminators, int inputSize, int numBits)
{
	(*this).numDiscriminators = numDiscriminators;
	
	// Alocar não é inicializar.
	this->discriminators = (DISCRIMINATOR*) malloc(sizeof(DISCRIMINATOR) * numDiscriminators);

    this->numRams = (inputSize / numBits);

	// Inicializar.
	for (int i = 0; i < numDiscriminators; ++i)
		discriminator_create (&this->discriminators[i], this->numRams, numBits);


    ull *vetorIndices, vetorEnderecos;
    // criando vetor de indices embaralhados.
    vetorIndices = wisard_create_shuffled_indexes (inputSize);

}

void wisard_destroy (WISARD *this)
{
    for (int i=0; i < (this->numDiscriminators); ++i)
        discriminator_destroy(&this->discriminators[i]);

	free(this->discriminators);
}

/*------------------------------------------------------------------------------------------*/

// apresentar a entrada ao discriminador que quero treinar
void wisard_train (WISARD *this, ull *entradaBin, int tagClasse)
{
    // entrar no discriminador dado e chamar o método do discriminador que, realiza os processos necessários com a entrada.
    if (tagClasse >= 0 && tagClasse < this->numDiscriminators)
        discriminator_train (&this->discriminator[tagClasse], this->inputSize);
    
    
    // Gerar uplas
    wisard_create_tuple ();

}



// Entrada é apresentada à todos os discriminadores
void wisard_classify (WISARD *this, ull *entradaBin, int *tagClasse)
{


    // Gerar uplas
    wisard_create_tuple ();

}

/*------------------------------------------------------------------------------------------*/

ull *
wisard_create_shuffled_indexes (int inputSize)
{

    ull *vetorIndices;
    
    int indiceVetor, indiceAleatorio, valorIndiceContinuo;
    
    // allocando o vetor de indices.
    vetorIndices = (ull*) malloc (sizeof(ull) * inputSize);
    
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

/*------------------------------------------------------------------------------------------*/

ull *
wisard_decode (WISARD *this, ull *vetorEntrada, ull *vetorIndices, inputSize, numBits)
{

    ull *vetorEnderecos;
    
    vetorEnderecos = (ull *) malloc (sizeof(ull) * numRams);

    int i, j;

    // preencher um vetor com numRams Posições.
    // percorre o comprimento total da entrada.
    // depois preenche com a soma de cada um dos indices daquela parte.
    
    for (i = 0; i < inputSize; i += numBits)
    {
    
    
        for (j = i; j < (i+numBits); ++j)
        {
        
            wisard_bin_to_dec (vetorEntrada [(vetorIndices[i])]);
            
        
        
        }
    
    }
    
    




    return vetorEnderecos;

}

int 
wisard_bin_to_dec (WISARD *this, ull *upla)
{
    int indiceVetor;
    int valorDecimal = 0;
    
        /* para o vetor, os menores índices representam os maiores valores. [0] = 2^(TAMANHO_VETOR_ENTRADA)
         então temos dois índices para que a transição aconteça de forma correta.*/
    for (indiceVetor = 0; indiceVetor < numBits; indiceVetor++)
    {
        //  quero fazer: valorDecimal += valorBinario [indiceVetor]*(2^TAMANHO_UPLA);

        valorDecimal += (upla [indiceVetor] * ( pow(2, numBits) ) );
    }

    return valorDecimal;
}











