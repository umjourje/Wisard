/*
Universidade Federal do Rio de Janeiro
Instituito Luis Coimbra de Pesquisa e pós Graduação em Engenharia - COPPE

Autora: Juliana Fernandes Dal Piaz
Data: 17/08/2017

*/

#include <math.h>
#include "termometro.h"

#define QTD_SENSORS    8
#define BITS_SIZE      1023

int *termometroLinear (int)
{
    int arrayEntrada [QTD_SENSORS * BITS_SIZE];

    int max = 1023;
    
    for (int i = 0; i <= QTD_SENSORS; i++)
    {
        int x = proxResult[i];
    
        for (int j = 0; j < max; j++)
        {
            if (j < x)
                arrayEntrada [j] = 1;
                
            else
            {
                arrayEntrada [j] = 0;
            }
        }
    }
}
