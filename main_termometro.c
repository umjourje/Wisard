#include <stdio.h>
#include <stdlib.h>

#include "termometro.h"


int arrayWisard [N_BITS];
int valorTermometro;

int flag = 1;


int main ()
{

    while (flag != 0){
    
        printf("Entre seu valor termometro: ");
        scanf ("%d", &valorTermometro);

        if (valorTermometro == -1)
            break;
            
        termometerCoding(valorTermometro, arrayWisard);

        for (int i=0; i < (N_BITS); ++i)
            printf("%d", arrayWisard[i]);

        
        printf ("\n\n");
        
        //printf("Valor de Flag: ");
        //scanf ("%d", &flag);
    }
    
    return 0;
}
