#include "tdt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void){

tdt * tabla = tdt_crear("m");
     uint8_t clave[3]= {1,2,3};
uint8_t valor[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

char* hola= '\0';
         tdt_recrear(&tabla, hola );
     printf("%s\n", tabla->identificacion );

    //  tdt * tabla = tdt_crear("m");
    //  uint8_t clave[3]= {1,2,3};
    //  uint8_t valor[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    //       uint8_t clave1[3]= {2,3,5};
    //  uint8_t clave2[3]= {8,1,2};
    //  uint8_t clave3[3]= {3,2,3};
    //  uint8_t clave4[3]= {45,200,32};
    //  uint8_t clave5[3]= {11,235,234};
    //  uint8_t clave6[3]= {1,2,3};


    //  tdt_agregar(tabla,clave,valor);
    //  tdt_agregar(tabla, clave1, valor);
    //       tdt_agregar(tabla,clave2,valor);

    //  tdt_agregar(tabla,clave3,valor);

    // tdt_agregar(tabla,clave4,valor);

    //  tdt_agregar(tabla,clave5,valor);
    //  tdt_agregar(tabla,clave6,valor);


// printf("LA ID ES %s\n", tabla->identificacion );

 //tdt_destruir(&(tabla));


    return 0;    
}
