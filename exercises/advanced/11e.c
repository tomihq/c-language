#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
static uint16_t *secuencia(uint16_t n);

int main(){
	const int n = 10;
	uint16_t *arr = secuencia(n);
	for(uint16_t i = 0; i<n; i++){
		printf("%d \n", arr[i]);
	}
	return 0;
}


uint16_t *secuencia(uint16_t n){
	uint16_t arr[n];
	for(uint16_t i=0; i < n; i++){
		arr[i] = i;
	}

	return arr;

}


