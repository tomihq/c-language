#include <stdio.h>

static void multiply_by_two(int* n);

int main(){
    int n = 2;
    printf("n: %d \n", n);
    multiply_by_two(&n);
    printf("n: %d \n", n);
    return 0; 
}

void multiply_by_two(int* n){
    *n *= 2;
    return;
}
