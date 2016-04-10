#include "tdt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void){

tdt * tabla = tdt_crear("m");
     uint8_t clave[3]= {1,2,3};
uint8_t valor[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

// char* hola= "te odio asm";
//         tdt_recrear(&tabla, hola );
//      printf("%s\n", tabla->identificacion );

    //  tdt * tabla = tdt_crear("m");
    //  uint8_t clave[3]= {1,2,3};
    //  uint8_t valor[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
          uint8_t clave1[3]= {2,3,5};
     uint8_t clave2[3]= {5,5,5};
     uint8_t clave3[3]= {255,255,255};
     uint8_t clave4[3]= {83,255,170};
     uint8_t clave5[3]= {16,238,5};
     uint8_t clave6[3]= {255,2,3};
//tdt_agregar(tabla,clave2,valor);
      // bloque* b;
      // b->clave[0]=3;
     //bloque b1 = {{1,5,3},{3,4,5,6,7,8,4,5,6,2,3,4,5,0,5}};
      // for(int i=0; i<3; i++){
      //    b->clave[i]= clave2[i];
      // }
     // for (int i = 0; i < 15; ++i)
     // {
     //        b->valor[i]=valor[i];     }


    bloque b1 = {{5,5,5},{18,52,86,120,154,188,222,241,35,69,103,137,171,205,239}};
    bloque b2 = {{255,255,255},{17,34,51,68,85,102,119,136,153,170,187,204,221,238,255}};
    bloque b3 = {{83,255,170},{17, 18, 34, 51, 52, 68, 85, 86, 102, 119, 120, 136, 153, 154, 170}};
    bloque b4 = {{16,238,5},{17, 17, 34, 34, 51, 51, 68, 68, 85, 85, 102, 102, 119, 119, 136}};

    bloque* b[5] = {&b1,&b2,&b3,&b4,0};


//tdt_agregarBloques(tabla,&b);   
// uint8_t valor2[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
       // tdt_agregarBloque(tabla,&b1);
       //        tdt_agregarBloque(tabla,&b2);
       // tdt_agregarBloque(tabla,&b3);
       // tdt_agregarBloque(tabla,&b4);
tdt_agregarBloques(tabla,&b);
       tdt_traducirBloques(tabla,&b);
    tdt_borrarBloques(tabla,&b);
     // for (int i = 0; i < 15; ++i)
     // {
     //     printf("%i\n", tabla->primera->entradas[clave2[0]]->entradas[clave2[1]]->entradas[clave2[2]].valor.val[i]);
     // }
    //  tdt_agregar(tabla, clave1, valor);
    //       tdt_agregar(tabla,clave2,valor);

    //  tdt_agregar(tabla,clave3,valor);

    // tdt_agregar(tabla,clave4,valor);

    //  tdt_agregar(tabla,clave5,valor);
    //  tdt_agregar(tabla,clave6,valor);


// printf("LA ID ES %s\n", tabla->identificacion );

tdt_destruir(&(tabla));


    return 0;    
}
