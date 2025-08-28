#include <stdio.h>
void swap(int* a, int* b);
void print_arr(const int* a[]);

int main(){
	int x = 10, y = 20;
	swap(&x, &y);
	printf("x: %d, y: %d \n", x, y);
	int arr[3] = {1, 2, 3};
	print_arr(&arr);
	return 0;
}


void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_arr(const int* arr[]){
  const int arr_size = sizeof(*arr) / sizeof(*arr[0]);
  for(int i=0; i<arr_size; i++){
	printf("%d", *arr[i]);
	if(i == arr_size-1){
		printf("");
	}else{
		printf(", ");
	}
  }
}


