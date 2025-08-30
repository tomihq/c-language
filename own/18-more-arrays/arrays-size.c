#include <stdio.h>

int main(){
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("arr size: %d \n", size);
}