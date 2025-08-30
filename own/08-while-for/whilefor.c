#include <stdio.h>
#include <stdint.h>

int main(){
	const int32_t limit = 10;
	int32_t counter = 0;

	while(counter<=limit){
		printf("Counter While: %d\n", counter);	
		counter++;
	}
	
	counter = 0;

	for(int i = 0; i<=limit; i++){
		printf("Counter For: %d\n", counter);
		counter++;
	}

	return 0;
}
