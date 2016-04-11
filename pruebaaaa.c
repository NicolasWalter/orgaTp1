#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>



typedef struct maxmin_t {
  uint8_t max_clave[3];
  uint8_t min_clave[3];
  uint8_t max_valor[15];
  uint8_t min_valor[15];
} __attribute__((__packed__)) maxmin;



int main(int argc, char const *argv[])
{
maxmin *result = malloc(sizeof(maxmin));

// for (int i = 0; i < 3; ++i)
// {
// 	m->max_clave[i]=5;
// printf("era %i\n",m->max_clave[i] );
// }

// uint8_t caca[3] = {1,1,1};
// //m->max_clave= &caca;

// for (int i = 0; i < 3; ++i)
// {
	
// printf("es %i\n",m->max_clave[i] );
// }
	return 0;
}