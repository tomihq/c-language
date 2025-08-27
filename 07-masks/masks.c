#include <stdio.h>
#include <stdint.h>
/*
 *	Realizar un programa que compare si los 3 bits más altos de una palabra de 32 bits son
	iguales a los 3 bits más bajos de otra palabra de 32 bits. Si son iguales, informarlo por
	pantalla.
 *
*/
// Voy a usar la mascara 0x7 (0b111) que es basicamente quedarme con los primeros 3 bits de la parte baja.
// Luego, simplemente comparo ambos (porque tengo garantizado que al aplicar la mascara el resto queda en 0)
int main(){
	signed int a = 0xFFFFFFFF;
	signed int b = 0x0000000F;
	unsigned int top3_a = (a >> 29) & 0x7; //shifteo a derecha y aplico mascara. 
	unsigned int low3_b = b & 0x7; 

	if(top3_a == low3_b){
		printf("Son iguales \n");
	}else{
		printf("Son diferentes \n-");
	}

	return 0;
}
