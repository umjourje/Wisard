/*
    Universidade Federal do Rio de Janeiro
    Programa de Engenharia e Sistemas de computação
    

    Autora:     Juliana Fernandes Dal Piaz
    Data:       05/05/2017
*/

#ifndef BASICO01H
#define BASICO01H	"@(#)basico_wisard.h $Revision: $"

#define TAMANHO_VETOR_ENTRADA		    256
#define TAMANHO_UPLA					8
#define QUANTIDADE_UPLAS     		    TAMANHO_VETOR_ENTRADA/TAMANHO_UPLA

#define VALOR_SEMENTE		    		42
#define EMBARALHAMENTO_MAXIMO   		VALOR_SEMENTE*10

typedef unsigned short		us;
/*Definição de tipo ULL. 
Uso de TYPEDEF: VALOR 	VARIÁVEL
*/
typedef unsigned long long ull;


void
embaralharEntrada (ull *vetorEntradaEmbaralhado);

void
embaralharEntrada2 (ull *vetorEntrada);

void 
escreverContador (ull **vetorUplas, ull **vetorDescritorClasse);

void 
GerarUPLAS (ull *vetorEntradaEmbaralhado, ull **vetorUplas);

int 
BinToDec (ull *upla);
  

/*
int main() {
  	RAM r;
  	RAM * ptr = &r;	
  	ram_create(&r);

	int num = r.numRams;
	int num2 = ptr->numRams;
}	
*/

#endif
