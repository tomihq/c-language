/* fix this code 
int main(){
	int arr[] = {1, 2, 3};
	printArr(arr);
	return 0;
}

void printArr(int c[]){
	const uint32_t size = sizeof(c) / sizeof(c[0]);
	
	for(int i = 0; i<size; i++){
		printf(c[i]);
	}
}
*/

#include <stdio.h>
static void printArr(int* c, int size);

int main(){
	int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
	printArr(arr, size);
	return 0;
}

void printArr(int* c, int size){
	for(int i = 0; i<size; i++){
		printf("elem: %d | ", c[i]);
        printf("2da forma, mostrar elem: %d \n", *(c+i));
	}
}