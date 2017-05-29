/* Código teste de tentativa de aplicação masi básica da wisard. =)


Definições:
- Matriz de 1 dimensao (1 linha), tamnho 'N';                                                       FEITO
- Matriz binária;                                                                                   Não

Embaralhar [NUNCA é opcional]:
- Mas sempre da mesma forma;                                                                        FEITO

SEPARAR:
- Separar grupos de mesmo tamanho [upgrade: diferentes tamanhos];                                   Não

Treinar:
- Associar o tamanho das uplas à valores binários [TAG] dentro do intervalo (tamanho da upla);
- Associar cada TAG do intervalo à um "Score";


Resultado(?):
- 
- 

Entrada:
vetor unidimensional binário GRANDE;
Separar em N grupos.
______________________________________________

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


/*Essa função está funfando! lol*/
void 
CriarVetorEmbaralhado (ull *vetorEmbaralhado)
{
	int indiceVetor, indiceAleatorio1, indiceAleatorio2, valorIndice;
 
   // Criando o Vetor Ordenado.
   printf ("Vetor Ordenado: \n");
	for (indiceVetor = 0; indiceVetor < TAMANHO_VETOR_ENTRADA; indiceVetor++)
	{	
		vetorEmbaralhado [indiceVetor] = indiceVetor;
    	printf ("%llu ", vetorEmbaralhado [indiceVetor]);
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
	    valorIndice = vetorEmbaralhado [indiceAleatorio1];

	    
	    vetorEmbaralhado [indiceAleatorio1] = vetorEmbaralhado [indiceAleatorio2];
	    
	    vetorEmbaralhado [indiceAleatorio2] = valorIndice;
	}
}


/*__________________________________________________________________________________________*/


void valorDiscriminadores (ull **vetorUplas, ull **vetorDiscriminadores)
{
    ull vetorUplas [QUANTIDADE_UPLAS] [TAMANHO_UPLA];

    // cada vetor associado a CADA Upla tem tamanho = 2 ^ TAMANHO_UPLA 
    ull vetorDiscriminadores [QUANTIDADE_UPLAS] [ pow(2, TAMANHO_UPLA) ];
    
    int indiceUplas, indiceBit, contadorDePadrao;
    
    for (indiceUplas = 0; indiceVetor < QUANTIDADE_UPLAS; indiceVetor++)
    {
        // Essa linha descobre o valor do índice ao qual deve ser somado 1 no vetorDiscriminador.
        contadorDePadrao = BinToDec (vetorUplas [indiceVetor]);
        
        for (indiceBit = 0; indiceBit < TAMANHO_UPLA; indiceBit++)
        {   
            
        }

    }
    
    
}

/* Gera cada elemento de 'vetorUPLAS'. No caso, uplas com NBits. Com TODAS as possibilidades de score!
Essa função devolve uma Tabela com todos os Scores possíveis.

Upla É um vetor de elementos. =)
tá.

vetorUplas é um vetor de vetores. que contém todas as Uplas! lol

*/
void GerarUPLAS (ull *vetorEmbaralhado, ull **vetorUplas)
{
    int indiceUplas, indiceBit;

   /* Vou TENTAR dividir em tamanhos de 8 bits ( TAMANHO_UPLA ).
    MAS Tenho que dividir SEMPRE por um múltiplo do tamanho.
    por isso, vou tentar gerar uma entrada múltipĺa de 8.*/

    // Primeiro for percorre até o tamanho total do vetor de entrada (vetorEmbaralhado) pulando pelo comprimento total de cada upla.
    for (indiceUplas = 0; indiceUplas < TAMANHO_VETOR_ENTRADA; indiceUplas += (TAMANHO_UPLA-1))
    {
        // Segundo for percorre até o tamanho total da upla. 0-7!  E preenche a posição com o bit correnpondente do vetorEmbralhado.
        for (indiceBit = 0; indiceBit < TAMANHO_UPLA; indiceBit++)
        {
            vetorUplas [indiceUplas] [indiceBit] = vetorEmbaralhado [indiceBit];
        }    
    }

}

/* Essa Função converte um número binário para um número decimal.*/
ull BinToDec (ull upla[TAMANHO_UPLA])
{
    int indiceVetor;
    ull valorDecimal = 0;
    
        /* para o vetor, os menores índices representam os maiores valores. [0] = 2^(TAMANHO_VETOR_ENTRADA)
         então temos dois índices para que a transição aconteça de forma correta.*/
    for (indiceVetor = 0; indiceVetor < TAMANHO_UPLA; indiceVetor++)
    {
        //  quero fazer: valorDecimal += valorBinario [indiceVetor]*(2^TAMANHO_UPLA);

        valorDecimal += valorBinario [indiceVetor] * ( pow(2, TAMANHO_UPLA) );
    }

    return valorDecimal;
}


/*-----------------------------------------------------------------------------------------*/


int main ()
{

    int indiceVetor;
    int semente = VALOR_SEMENTE;
   	srand (semente);

	ull vetorEmbaralhado [TAMANHO_VETOR_ENTRADA];

	CriarVetorEmbaralhado (vetorEmbaralhado);

	printf ("\n\n");
	
	for (indiceVetor = 0; indiceVetor < TAMANHO_VETOR_ENTRADA; indiceVetor++)
	{	
        printf ("%llu ", vetorEmbaralhado[indiceVetor]);
	}
	
	printf ("\n\n");

	return OK;
}
