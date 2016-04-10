#include "tdt.h"
#define TAB_1  tabla->primera
#define TAB_2  TAB_1->entradas
#define TAB_3  TAB_2->entradas
#define VAL_  TAB_3->entradas

int definido(tdt* tabla, uint8_t cero, uint8_t uno, uint8_t dos){
	// tdtN1* pri= tabla->primera;
	// tdtN2* sec= pri->entradas[cero];
	// tdtN3* ter = sec->entradas[uno];
	// uint8_t va= ter->entradas[dos].valido;
	 uint8_t cero8= 0;

	if(tabla->primera==0 || tabla->primera->entradas[cero]==0 || tabla->primera->entradas[cero]->entradas[uno]==0 || 
		tabla->primera->entradas[cero]->entradas[uno]->entradas[dos].valido ==cero8){
		return 0;
	} else{
		return 1;
	}

}

void crearTablas(tdt* tabla, uint8_t* clave, uint8_t* valor){
	tdtN1* nueva1= calloc(1,sizeof(tdtN1));
	 tdtN2* nueva2= calloc(1,sizeof(tdtN2));
	 tdtN3* nueva3= calloc(1,sizeof(tdtN3));

tabla->primera=nueva1;
tdtN1* prim= tabla->primera;

prim->entradas[clave[0]]=nueva2;
tdtN2* seg=prim->entradas[clave[0]];

seg->entradas[clave[1]]=nueva3;
tdtN3* ter= seg->entradas[clave[1]];

ter->entradas[clave[2]].valido=1;
 for(int i=0;i<15;i++){

 	ter->entradas[clave[2]].valor.val[i]=valor[i];
	}
tabla->cantidad++;

}

void crear23(tdt* tabla, uint8_t* clave, uint8_t* valor){
	 tdtN2* nueva2= calloc(1,sizeof(tdtN2));
	 tdtN3* nueva3= calloc(1,sizeof(tdtN3));

tdtN1* prim= tabla->primera;

prim->entradas[clave[0]]=nueva2;
tdtN2* seg=prim->entradas[clave[0]];

seg->entradas[clave[1]]=nueva3;
tdtN3* ter= seg->entradas[clave[1]];

ter->entradas[clave[2]].valido=1;
 for(int i=0;i<15;i++){
	 //valorcito->val[i]=valor[i];
 	ter->entradas[clave[2]].valor.val[i]=valor[i];
	}
tabla->cantidad++;

}

void crear3(tdt* tabla, uint8_t* clave, uint8_t* valor){
tdtN3* nueva3= calloc(1,sizeof(tdtN3));

tdtN1* prim= tabla->primera;
tdtN2* seg=prim->entradas[clave[0]];

seg->entradas[clave[1]]=nueva3;
tdtN3* ter= seg->entradas[clave[1]];

ter->entradas[clave[2]].valido=1;
 for(int i=0;i<15;i++){
	 //valorcito->val[i]=valor[i];
 	ter->entradas[clave[2]].valor.val[i]=valor[i];
	}
tabla->cantidad++;

}

void tdt_agregar(tdt* tabla, uint8_t* clave, uint8_t* valor) {
	 
if(tabla->primera==0){ //TODO VACIO
	crearTablas(tabla,clave,valor);
  }else if(tabla->primera->entradas[clave[0]]==0 ){ // NECESITO CREAR TABLA 2 Y 3	
  	crear23(tabla,clave,valor);
  	}else if(tabla->primera->entradas[clave[0]]->entradas[clave[1]]==0){ //crear tabla 3
  	crear3(tabla,clave,valor);
  			}else{ // NO CREO NADA

  			
  

  int booleano=	(tabla->primera->entradas[clave[0]]!=0 && tabla->primera->entradas[clave[0]]->entradas[clave[1]]!=0
  	&& tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valido==1);
  	if(booleano==0){
  		tabla->cantidad++;}
  
  	for(int i=0;i<15;i++){
	  tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valor.val[i]=valor[i];
  	tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[clave[2]].valido=1;
  		
  }
}

}


void tdt_borrar(tdt* tabla, uint8_t* clave) {
	printf("%s\n","entre loro" );
if(definido(tabla, clave[0], clave[1], clave[2])){
tabla->cantidad--;
	int todosnull = 1;
	int i=0;
	while(i<256 && todosnull){
		if(i!=clave[2]){
		todosnull = todosnull && !(tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[i].valido);
			}
			i++;

	}


tdtN3* tabla3 =tabla->primera->entradas[clave[0]]->entradas[clave[1]];
tdtN2* tabla2= tabla->primera->entradas[clave[0]];
tdtN1* tabla1= tabla->primera;
	if(todosnull){  //la tabla 3 solo tenia un valor valido
		free(tabla->primera->entradas[clave[0]]->entradas[clave[1]]);
		

		i=0;
		while(i<256 && todosnull){ 
			if(i!=clave[1]){
				todosnull = todosnull && (0==tabla2->entradas[i]);
				}
			i++;
			}
			
		if(todosnull){ 
			free(tabla->primera->entradas[clave[0]]);
			i=0;
			while(i<256 && todosnull){
				if(i!=clave[0]){
					todosnull = todosnull && (0==tabla1->entradas[i]);
				}
				i++;
				}
				
				if(todosnull){ 
					free(tabla->primera);
				}else{
					tabla->primera=0;
				}
		}else{
			tabla->primera->entradas[clave[0]]=0;
		}
	}else{
		tabla3->entradas[clave[2]].valido=0;
		tabla3=0;
		tabla2=0;
	}
}
}
void tdt_imprimirTraducciones(tdt* tabla, FILE *pFile) {


//pFile= fopen("porfavor.txt", "w");

char *id= tabla->identificacion;
fprintf(pFile, "- %s %s\n",id,"-");

for(int i=0; i<256; i++){
	for(int j=0; j<256; j++){
		for(int k=0; k<256; k++){
			if(definido(tabla,i,j,k)){
				uint8_t val[15];
				uint8_t clave[3]={i,j,k};
				tdt_traducir(tabla,clave,val);
				fprintf(pFile, "%X%X%X%s",i,j,k," => ");
				for(int l=0; l<15;++l){
					if(l!=14){
				fprintf(pFile,"%X",val[l]);
					}else{
						fprintf(pFile,"%X\n",val[l]);
					}


				}
			}
		}
	}
	
}


fclose(pFile);

}

maxmin* tdt_obtenerMaxMin(tdt* tabla) {
  return 0;
}
