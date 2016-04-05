#include "tdt.h"


// typedef struct tdt_t {
//   char* identificacion;
//   struct tdtN1_t* primera;
//   uint32_t cantidad;
// } __attribute__((__packed__)) tdt;


void crearTablas(tdt* tabla, uint8_t* clave, uint8_t* valorete){
	tdtN1* nueva1= calloc(1,sizeof(tdtN1));
	 tdtN2* nueva2= calloc(1,sizeof(tdtN2));
	 tdtN3* nueva3= calloc(1,sizeof(tdtN3));
	 // valorValido* valorN= malloc((sizeof(valorValido)));
	 // valor* valorcito= malloc(sizeof(valor));

tabla->primera=nueva1;
tdtN1* prim= tabla->primera;

prim->entradas[clave[0]]=nueva2;
tdtN2* seg=prim->entradas[clave[0]];

seg->entradas[clave[1]]=nueva3;
tdtN3* ter= seg->entradas[clave[1]];

ter->entradas[clave[2]].valido=1;
 for(int i=0;i<15;i++){

 	ter->entradas[clave[2]].valor.val[i]=valorete[i];
	}
tabla->cantidad++;
//prim=nueva1;


// tdtN3* ter= seg->entradas[clave[1]];

// prim=nueva1;
// seg=nueva2;
//ter=nueva3;

//(ter->entradas[clave[2]].valor[);

	 // valorN->valido=1;
	 // valorN->valor=*valorcito;


	 //  for(int i=0; i<256; i++){
	 // 	if(i!=clave[0]){
	 // 	prim->entradas[i]=0;}
	 // 		 	if(i!=clave[1]){

	 // 	seg->entradas[i]=0;}
	 // 		 	if(i!=clave[2]){

	 // 	ter->entradas[i].valido=0;
	 // 			}else{
	 // 				ter->entradas[i].valido=1;
	 // 				ter->entradas[i].
	 // 			}
	 // }


	 // for(int i=0;i<15;i++){
	 // valorcito->val[i]=valorete[i];}

	 // valorN->valido=1;
	 // valorN->valor=*valorcito;
	

	 // ter->entradas[clave[2]]=*valorN;



}

void crear23(tdt* tabla, uint8_t* clave, uint8_t* valorete){
	 tdtN2* nueva2= calloc(1,sizeof(tdtN2));
	 tdtN3* nueva3= calloc(1,sizeof(tdtN3));

tdtN1* prim= tabla->primera;

prim->entradas[clave[0]]=nueva2;
tdtN2* seg=prim->entradas[clave[0]];

seg->entradas[clave[1]]=nueva3;
tdtN3* ter= seg->entradas[clave[1]];

ter->entradas[clave[2]].valido=1;
 for(int i=0;i<15;i++){
	 //valorcito->val[i]=valorete[i];
 	ter->entradas[clave[2]].valor.val[i]=valorete[i];
	}
tabla->cantidad++;

	// tdtN2* nueva2= malloc(256 * (sizeof(tdtN2*)));
 //   		tdtN3* nueva3= malloc(256* (sizeof(tdtN3*)));
	//  valorValido* valorN= malloc((sizeof(valorValido)));
	//  valor* valorcito= malloc(sizeof(valor));
	//  for(int i=0; i<256; i++){
	//  	nueva2->entradas[i]=0;
	//  	nueva3->entradas[i].valido=0;}


 //  		for(int i=0;i<15;i++){
 //  			valorcito->val[i]=valorete[i];
 //  		}
 //  		 valorN->valido=1;
	//  valorN->valor=*valorcito;
	
	// tabla->primera->entradas[clave[0]] =nueva2;
	//  nueva2->entradas[clave[1]] =nueva3;
	//  nueva3->entradas[clave[2]]=*valorN;
	//  tabla->cantidad++;

}

void crear3(tdt* tabla, uint8_t* clave, uint8_t* valorete){
tdtN3* nueva3= calloc(1,sizeof(tdtN3));

tdtN1* prim= tabla->primera;
tdtN2* seg=prim->entradas[clave[0]];

seg->entradas[clave[1]]=nueva3;
tdtN3* ter= seg->entradas[clave[1]];

ter->entradas[clave[2]].valido=1;
 for(int i=0;i<15;i++){
	 //valorcito->val[i]=valorete[i];
 	ter->entradas[clave[2]].valor.val[i]=valorete[i];
	}
tabla->cantidad++;

}

void tdt_agregar(tdt* tabla, uint8_t* clave, uint8_t* valorete) {
	 
if(tabla->primera==0){ //TODO VACIO
	crearTablas(tabla,clave,valorete);
  }else if(tabla->primera->entradas[clave[0]]==0 ){ // NECESITO CREAR TABLA 2 Y 3	
  	crear23(tabla,clave,valorete);
  	}else if(tabla->primera->entradas[clave[0]]->entradas[clave[1]]==0){ //crear tabla 3
  	crear3(tabla,clave,valorete);
  			}else{ // NO CREO NADA

  			
  

  int booleano=	(tabla->primera->entradas[clave[0]]!=0 && tabla->primera->entradas[clave[0]]->entradas[clave[1]]!=0
  	&& tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valido==1);
  	if(booleano==0){
  		tabla->cantidad++;}
  
  	for(int i=0;i<15;i++){
	  tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valor.val[i]=valorete[i];
  	tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valido=1;
  		
  }
}

}


void tdt_borrar(tdt* tabla, uint8_t* clave) {
	valor* valorcito =&(tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valor);
	
	free(valorcito);

	int todosnull = 1;
	int i=0;
	while(i<256 && todosnull){
		if(i!=clave[2]){
		todosnull = !(tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[i].valido);
			}
			i++;

	}

valor* valorcito =&(tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valor);
valorValido* valorA= &(tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]]);
tdtN3* tabla3 =tabla->primera->entradas[clave[0]]->entradas[clave[1]];
tdtN2* tabla2= tabla->primera->entradas[clave[0]];
tdtN1* tabla1= tabla->primera;
	if(todosnull){  //la tabla 3 solo tenia un valor valido
		free(valorcito);
		free(valorA); 
		free(tabla3);
		i=0;
		while(i<256 && todosnull){ 
			if(i!=clave[1]){
			todosnull = (0==tabla2->entradas[clave[i]]);
			}
			i++;
		}
		
		if(todosnull){ 
			free(tabla2);
			i=0;
			while(i<256 && todosnull){
				if(i!=clave[0]){
					todosnull = (0==tabla1->entradas[clave[i]]);
				}
				i++;
				}
				
				if(todosnull){ 
					free(tabla1);
				}	
		}
	}else{
		valorA->valido=0;
		tabla3=0;
		tabla2=0;
	}

}
void tdt_imprimirTraducciones(tdt* tabla, FILE *pFile) {
}

maxmin* tdt_obtenerMaxMin(tdt* tabla) {
  return 0;
}
