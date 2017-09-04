/*
Universidade Federal do Rio de Janeiro
Instituito Luis Coimbra de Pesquisa e pós Graduação em Engenharia - COPPE

Autora: Juliana Fernandes Dal Piaz
Data: 30/08/2017

*/

#ifndef TERMOMETRO_LINEAR_C
#define TERMOMETRO_LINEAR_C

#include <math.h>
#include <stdlib.h>
#include "termometro.h"


void termometerCoding(int valorTermometro, int *arraySensor)
{
    float escalaZeroUm = (valorTermometro - SENSOR_MIN) / (float) (SENSOR_MAX - SENSOR_MIN);
    int treshold = escalaZeroUm > 1.0 ? N_BITS : escalaZeroUm * N_BITS;
    
    for (int i=0; i<treshold; ++i)
        arraySensor [i] = 1;
    
    for (int i = treshold; i<N_BITS; ++i)
        arraySensor [i] = 0;
}

#endif

