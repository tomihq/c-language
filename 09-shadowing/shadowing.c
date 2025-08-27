#include <stdio.h>
#include <stdint.h>

const uint32_t i = 0; //global-scope static variable

void shadowing(){
	const int i = 4; //block-scope automatic variable
	printf("i shadowing: %d\n", i); //will return 4 (local value)
	return; 
}

int main(){
	shadowing();
	printf("i: %d\n", i); //will return 0 (global value)
	return 0;
}

