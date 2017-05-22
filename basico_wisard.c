/* Código teste de tentativa de aplicação masi básica da wisard. =)


Definições:
- Matriz de 1 dimensao (1 linha), tamnho 'N';
- Matriz binária;

Embaralhar [NUNCA é opcional]:
- Separar grupos de mesmo tamanho [upgrade: diferentes tamanhos];
- Mas sempre da mesma forma;

Treinar:
- Associar o tamanho das uplas à valores binários [TAG] dentro do intervalo (tamanho da upla);
- Associar cada TAG do intervalo à um "Score";


Resultado(?):
- 
- 


______________________________________________

Funcao enbaralhar

saber o tamanho da entrada n
criar um vetor de indices com n valores
embaralhar o vetor de indices


associar o vetor embaralhado de indices às entradas da RAM. CAda ram pega uma quantidade B
*/

/*
	Universidade Federal do Rio de Janeiro
	Programa de Engenharia e Sistemas de computação
	

	Autora: 	Juliana Fernandes Dal Piaz
	Data: 		05/05/2017
*/

#include "basico_wisard.h"
#include <stdlib.h>
#include <stdio.h>


#define TAMANHO_ENTRADA     10
#define VALOR_SEMENTE       4

#define OK					0


void
Embaralhar (ull *vetorEmbaralhado)
{
	us indiceVetor;
   
	for (indiceVetor = 0; indiceVetor < TAMANHO_ENTRADA; indiceVetor++)
	{	
    	printf ("%i ", rand () % 11);
		vetorEmbaralhado [indiceVetor] = rand() % 11;
	}

}

int main ()
{

    int indiceVetor;
    int semente = VALOR_SEMENTE;
   	srand (semente);
   	
    
	ull vetorEmbaralhado [TAMANHO_ENTRADA];	
	for (indiceVetor = 0; indiceVetor < TAMANHO_ENTRADA; indiceVetor++)
	{	
        printf ("%llu ", vetorEmbaralhado[indiceVetor]);
	}
	
	printf ("\n\n");


	Embaralhar(vetorEmbaralhado);
	
	printf ("\n\n");

	return OK;
}






