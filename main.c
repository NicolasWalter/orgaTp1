#include "tdt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void){


// CREO QUE NO TENGO QUE PEDIR MEMORIA PARA LOS VALORES !!!!!!!!!
     tdt * tabla = tdt_crear("meto vacia");
     uint8_t clave[3]= {0,1,2};
     uint8_t valor1[15]={0,5,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
     tdt_agregar(tabla,clave,valor1);
     printf("%i\n", tabla->primera->entradas[0]->entradas[1]->entradas[2].valor.val[1]);
     tdt_borrar(tabla,clave);
     //printf("%p\n", (void*)tabla->primera);
 //printf("%p\n", (void*) tabla->primera);


     // char *id= tabla->identificacion;
     // uint32_t cant= tabla->cantidad;
     // tdtN1* prim= tabla->primera;
     // uint8_t a= prim->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valor.val[1];
     

    //  uint8_t clave2[3]={90,50,39};
    //  uint8_t valor2[15]={10,9,8,7,6,10,9,8,7,6,10,9,8,7,6};
    //  tdt_agregar(tabla,clave2,valor2);
    // // uint32_t numero= tdt_cantidad(tabla);
    // //printf("%i\n", numero );
//     printf("%s,%i,%p, %i \n", id, cant, (void *)prim, a );
//  uint8_t   clave2[3]={95,89,32};
//   uint8_t  valor2[15]={3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
//     tdt_agregar(tabla,clave2,valor2);
//     cant= tabla->cantidad;
//     prim= tabla->primera;
//     a= prim->entradas[clave2[0]]->entradas[clave2[1]]->entradas[clave2[2]].valor.val[1];
    
//     printf("%s,%i,%p, %i \n", id, cant, (void *)prim, a );
//     tdt_borrar(tabla,clave2);
//         cant= tabla->cantidad;
// prim= tabla->primera;
//     a= prim->entradas[clave2[0]]->entradas[clave2[1]]->entradas[clave2[2]].valido;
    
//     printf("%s,%i,%p, %i \n", id, cant, (void *)prim, a);


// printf("%i\n", prim->entradas[clave2[0]]->entradas[clave2[1]]->entradas[129].valido);
// tdt_borrar(tabla,clave);
// cant= tabla->cantidad;
// prim= tabla->primera;
//     a= prim->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valor.val[1];

//         printf("%s,%i,%p, %i \n", id, cant, (void *)prim, a );


    for(int i=0; i<256; i++){
        printf("%i\n", tabla->primera->entradas[0]->entradas[1]->entradas[2].valor.val[1]);
    }
    // tdtN1* primero= tabla->primera;
    // uint32_t canti= tabla->cantidad;
    // uint8_t b=primero->entradas[clave2[0]]->entradas[clave2[1]]->entradas[clave2[2]].valor.val[1];
    // printf("%s,%i,%p, %i \n", id, canti, (void *)primero, b );
    

    //tdt_destruir(&(tabla));
    
    return 0;    
}
