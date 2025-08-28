#include <stdio.h>
#include <stdint.h>

int main(){
	/*int8_t memoria[9] = {255, 31, 42, 0, 55, 67, -128, 127, -99}; 
	const int32_t size = sizeof(memoria) / sizeof(memoria[0]);
	uint8_t *x = (uint8_t*) memoria[0];
	int8_t *y = (uint8_t*) memoria[size];

	printf("Dir de x: %p Valor: %d\n", (void*) x, *x);
	printf("Dir de y: %p Valor: %d\n", (void*) y, *y);
	*/
	int z = 42;
	int *p = &z;

	printf("z: %d, &&z: %p, p: %p, *p: %d \n", z, &z, p, *p);
	*p = 200;
	printf("z: %d, &&z: %p, p: %p, *p: %d \n", z, &z, p, *p);
	return 0;
}
