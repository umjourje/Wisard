/*
    Universidade Federal do Rio de Janeiro
    Programa de Engenharia e Sistemas de computação
    

    Autora:     Juliana Fernandes Dal Piaz
    Data:       05/05/2017
*/

#ifndef BASICO01H
#define BASICO01H	"@(#)basico_wisard.h $Revision: $"

#define TAMANHO_VETOR		    15
#define VALOR_SEMENTE		    42
#define EMBARALHAMENTO_MAXIMO   VALOR_SEMENTE*10
// #define TAMANHO_UPLA         N_BITS
// #define QUANTIDADE_UPLAS     TAMANHO_UPLAS/TAMANHO_VETOR

typedef unsigned short		us;
/*Definição de tipo ULL. 
Uso de TYPEDEF: VALOR 	VARIÁVEL
*/
typedef unsigned long long ull;

void
CriarVetorEmbaralhado (ull *vetorEmbaralhado);

void 
GerarTabelaIndices (ull *uplas, ull *discriminadores);

void 
GerarUPLAS (ull *vetorEmbaralhado, ull *vetorUplas);

void 
BinToDec (ull valorBinario [TAMANHO_VETOR], ull valorDecimal);
  

#endif
