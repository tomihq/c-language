#include <stdio.h>
#include <stdint.h>


int main(){
	void* ptr; //pointer to null, cannot be desreferenced (aka: access his value)
	int x = 42;
	ptr = &x; //pointer to &x dir. address

	//Convert the void pointer to an int* pointer to allow access to his value
	int* p = (int*) ptr;
	printf("Value: %d \n", *p);

	return 0;
}
