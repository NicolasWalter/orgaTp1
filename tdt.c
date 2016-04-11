#include "tdt.h"
#define TAB_1  tabla->primera
#define TAB_2  TAB_1->entradas
#define TAB_3  TAB_2->entradas
#define VAL_  TAB_3->entradas

int definido(tdt* tabla, int cero, int uno, int dos){
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
	printf("%s,%i,%i,%i,%i\n","entre loro clave ", clave[0],clave[1], clave[2], tabla->primera->entradas[clave[0]]==0);

if(!(tabla->primera==0 || tabla->primera->entradas[clave[0]]==0 || tabla->primera->entradas[clave[0]]->entradas[clave[1]]==0)){
tabla->cantidad--;
	int todosnull = 1;
	int i=0;
	while(i<256 && todosnull){
		if(i!=clave[2]){
		todosnull = todosnull && !(tabla->primera->entradas[clave[0]]->entradas[clave[1]]->entradas[i].valido);
			}
			i++;

	}
	printf("NULL ES %i\n", todosnull);


tdtN3* tabla3 =tabla->primera->entradas[clave[0]]->entradas[clave[1]];
tdtN2* tabla2= tabla->primera->entradas[clave[0]];
tdtN1* tabla1= tabla->primera;
	if(todosnull){  //la tabla 3 solo tenia un valor valido
		free(tabla->primera->entradas[clave[0]]->entradas[clave[1]]);
		tabla->primera->entradas[clave[0]]->entradas[clave[1]]=0;

		i=0;
		while(i<256 && todosnull){ 
			if(i!=clave[1]){
				todosnull = todosnull && (0==tabla2->entradas[i]);
				}
			i++;
			}
			
		if(todosnull){ 
			free(tabla->primera->entradas[clave[0]]);
			tabla->primera->entradas[clave[0]]=0;
			i=0;
			while(i<256 && todosnull){
				if(i!=clave[0]){
					todosnull = todosnull && (0==tabla1->entradas[i]);
				}
				i++;
				}
				
				if(todosnull){ 
					free(tabla->primera);
					tabla->primera=0;
				}else{
					//tabla->primera=0;
				}
		}else{
			//tabla->primera->entradas[clave[0]]=0;
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

void cambiarMaxClave(tdt* tabla, maxmin* m, int i, int j, int k){
	int a=i>m->max_clave[0];
	int b= i==m->max_clave[0] && j>m->max_clave[1];
	int c= i==m->max_clave[0] && j==m->max_clave[1] && k>m->max_clave[2];
	if(a || b || c){
		m->max_clave[0]=i;
		m->max_clave[1]=j;
		m->max_clave[2]=k;
	}
}

void cambiarMinClave(tdt* tabla, maxmin* m, int i, int j, int k){
	int a= i<m->min_clave[0];
	int b= i==m->min_clave[0] && j<m->min_clave[1];
	int c= i==m->min_clave[0] && j==m->min_clave[1] && k<m->min_clave[2];
	if(a || b || c){
		m->min_clave[0]=i;
		m->min_clave[1]=j;
		m->min_clave[2]=k;

	}
}

void cambiarMaxValor(tdt* tabla, maxmin* m, int i, int j, int k){
uint8_t clave[3]={i,j,k};
valorValido valorcito= tabla->primera->entradas[i]->entradas[j]->entradas[k];
tdt_traducir(tabla,clave,valorcito.valor.val);
uint8_t flag=0;
uint8_t l=0;
	while(!flag && l<15){
		if(valorcito.valor.val[l]!= m->max_valor[l]){
			if(valorcito.valor.val[l]>m->max_valor[l]){
				flag=1;
	  	   	}else{
	  	   		break;
	  	    }
		
			}
			l++;
	}

if(flag == 1){
	for (int l = 0; l < 15; ++l)
	{
		m->max_valor[l]=valorcito.valor.val[l];
	}
	
}


}

void cambiarMinValor(tdt* tabla, maxmin* m, int i, int j, int k){
uint8_t clave[3]={i,j,k};
valorValido valorcito= tabla->primera->entradas[i]->entradas[j]->entradas[k];

tdt_traducir(tabla,clave,valorcito.valor.val);

uint8_t flag=0;
uint8_t l=0;
	while(!flag && l<15){
		if(valorcito.valor.val[l]!= m->min_valor[l]){
			if(valorcito.valor.val[l]<m->min_valor[l]){
				flag=1;
	  	   	}else{
	  	   		break;
	  	    }
		
			}
			l++;
	}

if(flag == 1){
	for (int l = 0; l < 15; ++l)
	{
		m->min_valor[l]=valorcito.valor.val[l];
	}
	
}


}


maxmin* tdt_obtenerMaxMin(tdt* tabla) {

maxmin* m =malloc(sizeof(maxmin));
for (int l = 0; l< 15; ++l)
{
	if(l<3){
	m->max_clave[l]=0;
	m->min_clave[l]=255;
	}

	m->max_valor[l]=0;
	m->min_valor[l]=255;
}


	if(tabla->primera!=0){
		for (int i = 0; i < 256; ++i){
			if(tabla->primera->entradas[i]!=0){
				for (int j = 0; j < 256; ++j){
					if (tabla->primera->entradas[i]->entradas[j]!=0){		
						for (int k = 0; k < 256; ++k){
							if(definido(tabla, i,j,k)){
								cambiarMaxClave(tabla,m,i,j,k);
								cambiarMinClave(tabla,m,i,j,k);
								 cambiarMaxValor(tabla,m,i,j,k);
								  cambiarMinValor(tabla,m,i,j,k);
							}
						}
					}
				}
			}
		 }
	}
	return m;
}

 
