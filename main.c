#include "tdt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void){


// CREO QUE NO TENGO QUE PEDIR MEMORIA PARA LOS VALORES !!!!!!!!!
     tdt * tabla = tdt_crear("meto vacia");
     uint8_t clave[3]= {1,2,3};
     uint8_t valor[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
     tdt_agregar(tabla,clave,valor);
     uint8_t clave2[3]= {160,230,240};
     uint8_t valor2[15]={190,222,232,214,215,156,77,98,129,210,211,112,123,194,185};
     tdt_agregar(tabla,clave2,valor2);

char *caca= "hola.txt";
FILE *pFile = fopen( caca, "w" );
tdt_imprimirTraducciones(tabla,pFile);
    //tdt_destruir(&(tabla));

    
    return 0;    
}
