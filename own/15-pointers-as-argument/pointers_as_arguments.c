#include <stdio.h>
static void swap(int* a, int* b);
static void print_int(const int* a);
static void print_arr(const int* a, int size);

int main(){
	int x = 10, y = 20;
	swap(&x, &y);
	printf("x: %d, y: %d \n", x, y);
	print_int(&x);
	int arr[3] = {1, 2, 3};
	print_arr(arr, 3);
	return 0;
}


void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_arr(const int* arr, int size){
  for(int i=0; i<size; i++){
	printf("%d", *(arr+i));
	if(i == size-1){
		printf("");
	}else{
		printf(", ");
	}
  }
  printf("\n");
}

void print_int(const int* a){
	printf("print_int, value: %d \n", *a);
}


