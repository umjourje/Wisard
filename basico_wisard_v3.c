/*
Por Enquanto estou fazendo funções modulares que se encaixam para a aplicação da wisard.

A entrada vai ser do tipo binária.
Ainda tneho que descobrir como devolver valores binários do sensoriamento do Elisa 3.

Com os valores todos em binário e unificados em um só elemento tipo 'char *' :

Abordagem do Bernardo (diz ele q é mais genérica):

- DEFINIR o tamanho da entrada binária;
- Embaralhar a entrada;
- Converter de String para elementos TAMANHO N de um vetor;
- Gerar uma matriz de Score;
- Associar a Entrada Binária a tabela de Score;


Abordagem do Diego
- Criar um vetor de indices com n valores
- Embaralhar o vetor de indices

Associar o vetor embaralhado de indices às entradas da RAM. CAda ram pega uma quantidade B
*/

/*
	Universidade Federal do Rio de Janeiro
	Programa de Engenharia e Sistemas de computação
	

	Autora: 	Juliana Fernandes Dal Piaz
	Data: 		22/05/2017
*/

#include "basico_wisard.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define OK					0

/* Essa Função converte um número binário para um número decimal.*/
int BinToDec (ull *upla)
{
    int indiceVetor;
    int valorDecimal = 0;
    
        /* para o vetor, os menores índices representam os maiores valores. [0] = 2^(TAMANHO_VETOR_ENTRADA)
         então temos dois índices para que a transição aconteça de forma correta.*/
    for (indiceVetor = 0; indiceVetor < TAMANHO_UPLA; indiceVetor++)
    {
        //  quero fazer: valorDecimal += valorBinario [indiceVetor]*(2^TAMANHO_UPLA);

        valorDecimal += (upla [indiceVetor] * ( pow(2, TAMANHO_UPLA) ) );
    }

    return valorDecimal;
}


/*  Essa função está funfando! lol
    Essa função usa o método de permutações para um índice sorteado.
*/
void 
embaralharEntrada (ull *vetorEntradaEmbaralhado)
{
	int indiceVetor, indiceAleatorio1, indiceAleatorio2, valorIndice;
 
   // Criando o Vetor Ordenado.
   printf ("Vetor Ordenado: \n");
	for (indiceVetor = 0; indiceVetor < TAMANHO_VETOR_ENTRADA; indiceVetor++)
	{	
		vetorEntradaEmbaralhado [indiceVetor] = indiceVetor;
    	printf ("%llu ", vetorEntradaEmbaralhado [indiceVetor]);
	}

    printf ("\n\n");
	
    printf ("Vetor Embaralhado: \n");
    
	for (indiceVetor = 0; indiceVetor < EMBARALHAMENTO_MAXIMO; indiceVetor++)
	{
	
    	// Variável que recebe o indice Aleatório.
    	indiceAleatorio1 = rand() % TAMANHO_VETOR_ENTRADA;

        // Variável que recebe o valor apontado pelo indice Aleatório.
        indiceAleatorio2 = rand() %TAMANHO_VETOR_ENTRADA;
	    
	    // Colocando o Valor de outro índice dentro do primeiro.
	    valorIndice = vetorEntradaEmbaralhado [indiceAleatorio1];

	    
	    vetorEntradaEmbaralhado [indiceAleatorio1] = vetorEntradaEmbaralhado [indiceAleatorio2];
	    
	    vetorEntradaEmbaralhado [indiceAleatorio2] = valorIndice;
	}
}


/*__________________________________________________________________________________________*/

/* Escreve no vetorContador o padrão que apareceu na upla.*/

void escreverContador (ull **vetorUplas, ull **vetorContador)
{
    int indiceUpla, marcador;
    int valorIndice = 0;
    
    for (indiceUpla = 0; indiceUpla < QUANTIDADE_UPLAS; indiceUpla++)
    {
        // Essa linha descobre o valor do índice ao qual deve ser somado 1 no vetorDiscriminador.
        marcador = BinToDec (vetorUplas [indiceUpla]);
        
        valorIndice = vetorContador [indiceUpla] [marcador];
        
        valorIndice ++;

    }
    
}


/*-----------------------------------------------------------------------------------------------*/
/*
void lerContador (ull **vetorUplas, ull **vetorContador)
{
    
}
*/
/*-----------------------------------------------------------------------------------------------*/

/* Gera cada elemento de 'vetorUPLAS'. No caso, uplas com NBits. Com TODAS as possibilidades de score!
Essa função devolve uma Tabela com todos os Scores possíveis.

Upla É um vetor de elementos. =)
tá.

vetorUplas é um vetor de vetores. que contém todas as Uplas! lol

*/
void GerarUPLAS (ull *vetorEntradaEmbaralhado, ull **vetorUplas)
{
    int indiceUplas, indiceBit, indiceBitAtual = 0;

   /* Vou TENTAR dividir em tamanhos de 8 bits ( TAMANHO_UPLA ).
    MAS Tenho que dividir SEMPRE por um múltiplo do tamanho.
    por isso, vou tentar gerar uma entrada múltipĺa de 8.*/

    // Primeiro for percorre até o tamanho total do vetor de entrada (vetorEntradaEmbaralhado) pulando pelo comprimento total de cada upla.
    for (indiceUplas = 0; indiceUplas < TAMANHO_VETOR_ENTRADA; indiceUplas += (TAMANHO_UPLA-1))
    {
        // Segundo for percorre até o tamanho total da upla. 0-7!  E preenche a posição com o bit correnpondente do vetorEmbralhado.
        for (indiceBit = indiceBitAtual; indiceBit < TAMANHO_UPLA; indiceBit++)
        {
            vetorUplas [indiceUplas] [indiceBit] = vetorEntradaEmbaralhado [indiceBit];
            indiceBitAtual++;
        }    
    }

}


/*-------------------------------------------- OUTRO ARQUIVO ---------------------------------------------*/


int main ()
{

    int indiceVetor, indiceBit;
    int semente = VALOR_SEMENTE;
   	srand (semente);

	ull vetorEntradaEmbaralhado [TAMANHO_VETOR_ENTRADA];

	embaralharEntrada (vetorEntradaEmbaralhado);

	printf ("\n\n");
	
	for (indiceVetor = 0; indiceVetor < TAMANHO_VETOR_ENTRADA; indiceVetor++)
	{	
        printf ("%llu ", vetorEntradaEmbaralhado[indiceVetor]);
	}
	
	printf ("\n\n");

    // Inicializando os dois vetores a serem usados na função.   	
   	ull vetorUplas [QUANTIDADE_UPLAS] [TAMANHO_UPLA];

    // cada vetor associado a CADA Upla tem tamanho = 2 ^ TAMANHO_UPLA 
    // ull vetorContador [QUANTIDADE_UPLAS] [ (int) pow(2, TAMANHO_UPLA) ];

    /*Chamar GerarUPLAS*/
    GerarUPLAS (vetorEntradaEmbaralhado, vetorUplas);
    
    /* Printar o vetorUplas*/
    printf ("Vetor de Uplas: \n");

    for (indiceVetor =0; indiceVetor < QUANTIDADE_UPLAS; indiceVetor++)
    {
        for (indiceBit =0; indiceBit < TAMANHO_UPLA; indiceBit++)
        {
            printf ("%llu ", (vetorUplas [indiceVetor] [indiceBit]) );
        }
        
        printf ("\n");
    }

	return OK;
}
