#include "tdt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main (void){

tdt *tabla= tdt_crear("sa");
uint8_t clave1[3] = {1,2,3};
uint8_t valor1[15] = {3,4,5,6,7,8,4,5,63,2,3,4,5,6,5};
uint8_t clave2[3] = {2,2,2};
uint8_t valor2[15] = {3,4,5,3,7,8,4,5,63,2,3,4,5,6,5};
uint8_t clave3[3] = {3,2,3};
uint8_t valor3[15] = {3,4,5,6,7,8,4,5,0,2,3,4,5,6,5};
uint8_t clave4[3] = {8,9,3};
uint8_t valor4[15] = {3,4,5,6,7,8,4,5,63,2,3,4,5,6,5};
uint8_t clave5[3] = {0,2,2};
uint8_t valor5[15] = {63,4,5,2,7,8,4,5,0,2,3,4,5,6,5};
uint8_t clave6[3] = {7,2,3};
uint8_t valor6[15] = {3,4,5,6,7,8,4,5,63,2,3,4,5,6,5};
uint8_t clave7[3] = {8,2,3};
uint8_t valor7[15] = {9,4,5,6,7,8,4,5,63,2,3,4,5,6,5};

tdt_agregar(tabla, clave1, valor1);
   tdt_agregar(tabla, clave2, valor2);
 tdt_agregar(tabla, clave3, valor3);
   tdt_agregar(tabla, clave4, valor4);
   tdt_agregar(tabla, clave5, valor5);
     tdt_agregar(tabla, clave6, valor6);
    tdt_agregar(tabla, clave7, valor7);  

   // printf("%p,%p\n", tabla->primera->entradas[clave4[0]]->entradas[2],tabla->primera->entradas[clave4[0]]->entradas[9] );

tdt_borrar(tabla,clave1);
 tdt_borrar(tabla,clave2);
    tdt_borrar(tabla,clave3);
    tdt_borrar(tabla,clave4);
    
     tdt_borrar(tabla,clave5);
   tdt_borrar(tabla,clave6);
      tdt_borrar(tabla,clave7);


tdt_destruir(&tabla);







































//     //  FILE *pFile;
//     // tdt *tabla = tdt_crear("sa");
    
//     // pFile = fopen( "archivoCasoprueba", "a" );
//   tdt *tabla =tdt_crear("sa");
//          uint8_t clave[3]= {1,2,3};
// uint8_t valor[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

// // char* hola= "te odio asm";
// //         tdt_recrear(&tabla, hola );
// //      printf("%s\n", tabla->identificacion );

//     //  tdt * tabla = tdt_crear("m");
//     //  uint8_t clave[3]= {1,2,3};
//     //  uint8_t valor[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
//           uint8_t clave1[3]= {2,3,5};
//      uint8_t clave2[3]= {5,5,5};
//      uint8_t clave3[3]= {255,255,255};
//      uint8_t clave4[3]= {83,255,170};
//      uint8_t clave5[3]= {16,238,5};
//      uint8_t clave6[3]= {255,2,3};
// //tdt_agregar(tabla,clave2,valor);
//       // bloque* b;
//       // b->clave[0]=3;
//      //bloque b1 = {{1,5,3},{3,4,5,6,7,8,4,5,6,2,3,4,5,0,5}};
//       // for(int i=0; i<3; i++){
//       //    b->clave[i]= clave2[i];
//       // }
//      // for (int i = 0; i < 15; ++i)
//      // {
//      //        b->valor[i]=valor[i];     }


//     bloque b1 = {{5,5,5},{18,52,86,120,154,188,222,241,35,69,103,137,171,205,239}};
//     bloque b2 = {{255,255,255},{17,34,51,68,85,102,119,136,153,170,187,204,221,238,255}};
//     bloque b3 = {{83,255,170},{17, 18, 34, 51, 52, 68, 85, 86, 102, 119, 120, 136, 153, 154, 170}};
//     bloque b4 = {{16,238,5},{17, 17, 34, 34, 51, 51, 68, 68, 85, 85, 102, 102, 119, 119, 136}};

//     bloque* b[5] = {&b1,&b2,&b3,&b4,0};

//         tdt_agregarBloque(tabla,&b1);
//           tdt_agregarBloque(tabla,&b2);
//        tdt_agregarBloque(tabla,&b3);
//        tdt_agregarBloque(tabla,&b4);

//        tdt_traducir(tabla,clave2,valor);
//             for (int i = 0; i < 15; ++i)
//      {
//          printf("ANDA %i\n", tabla->primera->entradas[clave2[0]]->entradas[clave2[1]]->entradas[clave2[2]].valor.val[i]);
//      }

// maxmin *mm= tdt_obtenerMaxMin(tabla);
// for (int i = 0; i < 3; ++i)
// {
// printf(" min clave %i\n", mm->min_clave[i]);
// printf(" max clave %i\n", mm->max_clave[i]);

// }

// for (int i = 0; i < 15; ++i)
// {
// printf(" max valor %i\n", mm->min_valor[i]);
// }

// //tdt_agregarBloques(tabla,&b);   
// uint8_t valor2[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
   
      // tdt_traducirBloques(tabla,&b);
      

       //tdt_imprimirTraducciones(tabla, pFile); 
    //tdt_borrarBloques(tabla,&b);
 //     for (int i = 0; i < 15; ++i)
 //     {
 //         printf("%i\n", tabla->primera->entradas[clave2[0]]->entradas[clave2[1]]->entradas[clave2[2]].valor.val[i]);
 //     }
 //     printf("%s\n", " ");
 //      for (int i = 0; i < 15; ++i)
 //     {
 //         printf("%i\n", tabla->primera->entradas[clave3[0]]->entradas[clave3[1]]->entradas[clave3[2]].valor.val[i]);
 //     }
 //  printf("%s\n", " ");
 // for (int i = 0; i < 15; ++i)
 //     {
 //         printf("%i\n", tabla->primera->entradas[clave4[0]]->entradas[clave4[1]]->entradas[clave4[2]].valor.val[i]);
 //     }
 //  printf("%s\n", " ");
 // for (int i = 0; i < 15; ++i)
 //     {
 //         printf("%i\n", tabla->primera->entradas[clave5[0]]->entradas[clave5[1]]->entradas[clave5[2]].valor.val[i]);
 //     }

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
