#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "wisard.h"
#include "discriminator.h"
#include "ram.h"

int* criaPadraoAleatorio (int sizeOfPattern);
void printPadrao (int * padrao, int sizeOfPattern );
void copiaComRuido(int *padrao, int *tmp, double ruido);

#define TAMANHO_VETOR_ENTRADA   256
#define NUM_DISCRIMINATORS      2
#define NUM_BITS                4
#define TREINAMENTOS            100
#define CLASSIFICACOES          100
#define NIVEIS_RUIDO            11

int main()
{
    srand(time(NULL));
    int *padrao1 = criaPadraoAleatorio (TAMANHO_VETOR_ENTRADA);
    int *padrao2 = criaPadraoAleatorio (TAMANHO_VETOR_ENTRADA);
    int *tmp = (int*) malloc(sizeof(int) * TAMANHO_VETOR_ENTRADA);
    
    for (int w = 0; w < NIVEIS_RUIDO; ++w)
    {
        double ruido = w / (double)(NIVEIS_RUIDO - 1);
        
        // Cria
        WISARD wisard;
        wisard_create(&wisard, NUM_DISCRIMINATORS, TAMANHO_VETOR_ENTRADA, NUM_BITS);
        
        // tREINA
        for (int z =0; z < TREINAMENTOS; ++z)
        {
            
            copiaComRuido(padrao1, tmp, ruido);
            wisard_train (&wisard, tmp, 0);
            //printPadrao(tmp, TAMANHO_VETOR_ENTRADA);

            copiaComRuido(padrao2, tmp, ruido);
            wisard_train (&wisard, tmp, 1);
            //printPadrao(tmp, TAMANHO_VETOR_ENTRADA);

        }
        
        int acertos = 0, erros = 0;
        int resposta;
        
        for (int z =0; z < CLASSIFICACOES; ++z)
        {
        
            copiaComRuido(padrao1, tmp, ruido);
            resposta = wisard_classify (&wisard, tmp);
            resposta == 0 ? acertos++ : erros++;
            //printPadrao(tmp, TAMANHO_VETOR_ENTRADA);
            //printf("Respondeu %d para 0\n", resposta);

            copiaComRuido(padrao2, tmp, ruido);
            resposta = wisard_classify (&wisard, tmp);
            resposta == 1 ? acertos++ : erros++;
            //printPadrao(tmp, TAMANHO_VETOR_ENTRADA);
            //printf("Respondeu %d para 1\n", resposta);
            
        }
        
        //getchar();
        printf ("Percentual de acertos: %.2f para ruido %.2f \n", acertos/(float)(acertos+erros), ruido);

        // Destrói.
        wisard_destroy (&wisard);
        
    }
    
    free (padrao1);
    free (padrao2);
    free (tmp);
    
    return 0;
}

int* criaPadraoAleatorio (int sizeOfPattern)
{
    int *padrao = (int*) malloc(sizeof(int) * sizeOfPattern);

    for (int indiceVetor = 0; indiceVetor < sizeOfPattern; indiceVetor++)
	{	
		padrao [indiceVetor] = rand() % 2;
	}

	return padrao;
}

void printPadrao (int * padrao, int sizeOfPattern )
{
    printf ("Padrao: [ ");
    
    for (int i = 0; i < sizeOfPattern; ++i)
	{	
        printf ("%d", padrao[i]);
	}
    
    printf ("] \n\n");

}

void copiaComRuido(int *padrao, int *tmp, double ruido)
{
    for (int i = 0; i < TAMANHO_VETOR_ENTRADA; ++i)
    {
        if (rand() / (double)(RAND_MAX) < ruido)
            tmp [i] = padrao[i] == rand()%2;
        else
            tmp [i] = padrao[i];
    }
}


