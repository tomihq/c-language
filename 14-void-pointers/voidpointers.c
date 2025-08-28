#include <stdio.h>
#include <stdint.h>

int main(){
	void* ptr = NULL; //pointer to null, cannot be desreferenced (aka: access his value)
	
	if(ptr == NULL){
		printf("Pointer is null. Cannot be desreferenced \n");
	}else{
		printf("zz");
	}
	
	int x = 42;
	ptr = &x; //pointer to &x dir. address
	printf("Pointer assigned to: %p\n", ptr);
	//Convert the void pointer to an int* pointer to allow access to his value
	int* p = (int*) ptr;
	printf("Pointer value: %d \n", *p);

	return 0;
}
