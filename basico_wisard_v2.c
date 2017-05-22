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


#define OK					0


void 
CriarVetorEmbaralhado (ull *vetorEmbaralhado)
{
	int indiceVetor, indiceAleatorio1, indiceAleatorio2, valorIndice;
 
   // Criando o Vetor Ordenado.
   printf ("Vetor Ordenado: \n");
	for (indiceVetor = 0; indiceVetor < TAMANHO_VETOR; indiceVetor++)
	{	
		vetorEmbaralhado [indiceVetor] = indiceVetor;
    	printf ("%llu ", vetorEmbaralhado [indiceVetor]);
	}

    printf ("\n\n");
	
    printf ("Vetor Embaralhado: \n");
    
	for (indiceVetor = 0; indiceVetor < EMBARALHAMENTO_MAXIMO; indiceVetor++)
	{
	
    	// Variável que recebe o indice Aleatório.
    	indiceAleatorio1 = rand() % TAMANHO_VETOR;

        // Variável que recebe o valor apontado pelo indice Aleatório.
        indiceAleatorio2 = rand() %TAMANHO_VETOR;
	    
	    // Colocando o Valor de outro índice dentro do primeiro.
	    valorIndice = vetorEmbaralhado [indiceAleatorio1];

	    
	    vetorEmbaralhado [indiceAleatorio1] = vetorEmbaralhado [indiceAleatorio2];
	    
	    vetorEmbaralhado [indiceAleatorio2] = valorIndice;
	}
}

/* Gera a Tabela correspondente à cada elemento de 'vetorUPLAS'. Com TODAS as possibilidades de score!
Essa função devolve uma Tabela com todos os Scores possíveis.

Upla É um vetor de elementos. =)
tá.

vetorUplas é um vetor de vetores. que contém todas as Uplas! lol

*/

void GerarTabelaIndices (ull *vetorUplas, ull *discriminadores)
{
    ull vetorUplas [TAMANHO_VETOR] [TAMANHO_UPLA];
    int indiceVetor;
    
    
    for (indiceVetor = 0; indiceVetor < TAMANHO_VETOR; indiceVetor++)
    {
        /* o Elemento apresentado abaixo é uma UPLA. lol
         Ou seja, essa é a entrada correta e necessária. */        
        BinToDec (vetorUplas [indiceVetor]);

    
    }
    
    
}

/* Dividir o 'vetorEmbaralhado' de Tamanho = TAMANHO_VETOR
*/
void GerarUPLAS (ull *vetorEmbaralhado, ull *vetorUplas)
{
    
}

/* Essa Função converte um número binário para um número decimal.*/
ull BinToDec (ull upla[TAMANHO_UPLA])
{
    int indiceVetor, indicePeso, indiceInterno;
    ull valorDecimal = 0;
    ull potencia = 2;
    
        /* para o vetor, os menores índices representam os maiores valores. [0] = 2^(TAMANHO_VETOR)
         então temos dois índices para que a transição aconteça de forma correta.*/
    for (indicePeso = TAMANHO_VETOR, indiceVetor = 0; indiceVetor < TAMANHO_VETOR; indiceVetor++, indicePeso)
    {
        //  queo fazer: valorDecimal += valorBinario [indiceVetor]*(2^indicePeso);

        for (indiceInterno = 1; indiceInterno < indicePeso; indiceInterno++)
        {
            potencia *= 2;
            // Aqui pode existir um printf ("%llu ", potencia); 
            // com o valor atual da variável.
        }

        valorDecimal += valorBinario [indiceVetor]*potencia;
    }
        
    return valorDecimal;
}


/*-----------------------------------------------------------------------------------------*/


int main ()
{

    int indiceVetor;
    int semente = VALOR_SEMENTE;
   	srand (semente);

	ull vetorEmbaralhado [TAMANHO_VETOR];

	CriarVetorEmbaralhado (vetorEmbaralhado);

	printf ("\n\n");
	
	for (indiceVetor = 0; indiceVetor < TAMANHO_VETOR; indiceVetor++)
	{	
        printf ("%llu ", vetorEmbaralhado[indiceVetor]);
	}
	
	printf ("\n\n");

	return OK;
}
