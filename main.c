#include "tdt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void){


// CREO QUE NO TENGO QUE PEDIR MEMORIA PARA LOS VALORES !!!!!!!!!
     tdt * tabla = tdt_crear("meto vacia");
     uint8_t clave[3]= {0,1,2};
     uint8_t valor[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
     tdt_agregar(tabla,clave,valor);
     for (int i = 0; i < 15; ++i)
     {
          printf("el valor es%p\n", valor[i]);
     }
    
     tdt_traducir(tabla,clave,valor);
 for (int i = 0; i < 15; ++i)
     {
          printf("el valor es%p\n", valor[i]);
     }
    //tdt_destruir(&(tabla));
    
    return 0;    
}
