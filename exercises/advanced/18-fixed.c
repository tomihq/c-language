#include <stdio.h>
#include <stdlib.h>

void allocateArray(int** arr, int size, int value); 

int main(){
    int* vector = NULL;
    allocateArray(&vector, 2, 45);
    printf("Dirección al puntero: %p \n", (void*) vector);
    for(int i = 0; i < 2; i++)
        printf("%d\n", *(vector+i));
    free(vector);
    return 0; 
}

/* 
En la dirección a la que apunta el puntero que recibimos (*arr), guardamos la dirección de un bloque de memoria en el heap donde se almacenará un array de enteros.
*/
void allocateArray(int** arr, int size, int value) {
    *arr = (int*) malloc(size * sizeof(int)); 
    if(*arr != NULL) {
        for(int i=0; i<size; i++) {
            (*arr)[i] = value;
        }
    }
}