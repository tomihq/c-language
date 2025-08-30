#include <stdio.h>
#include <stdint.h>

int main(){
	int z = 42;
	int *p = &z;

	printf("z: %d, &&z: %p, p: %p, *p: %d \n", z, &z, p, *p);
	*p = 200;
	printf("z: %d, &&z: %p, p: %p, *p: %d \n", z, &z, p, *p);
	return 0;
}
