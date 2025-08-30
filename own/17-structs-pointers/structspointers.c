#include <stdio.h>
#define NAME_LEN 50


typedef struct persona_s {
	char nombre[NAME_LEN+1];
	int edad;
	struct persona_s* hijo;

} persona_t;

int main(){
	persona_t hijo = {"Pablo", 4, NULL};
	persona_t padre = {"Juan", 35, &hijo};

	printf("----Padre----");
	printf("Nombre: %s, Edad: %d, Nombre del hijo: %s, Edad del hijo: %d \n", padre.nombre, padre.edad, padre.hijo -> nombre, padre.hijo -> edad); //padre.hijo es un puntero (*), para acceder a un campo de un puntero es * -> prop. De lo contrario, el puntero solo es una direccion, no un valor.
	
	printf("----Hijo----");
	printf("Nombre: %s, Edad: %d, Nombre del hijo: %s, Edad del hijo: %d \n", hijo.nombre, hijo.edad); //no tiene sentido buscar el hijo del hijo, va a estallar porque el puntero es NULL. 
	
		return 0;
}

