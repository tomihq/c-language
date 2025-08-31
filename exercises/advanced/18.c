#include <stdio.h>
#include <stdlib.h>

void allocateArray(int* arr, int size, int value); 

int main(){
    int* vector = NULL;
    allocateArray(vector, 5, 45);
    for(int i = 0; i < 5; i++)
        printf("%d\n", vector[i]);
    free(vector);
    return 0; 
}

/* 
Estamos mandando directamente el puntero (no la dirección donde se encuentra).
Hacer arr = (int*) malloc(size * sizeof(int)) sería "pisar el puntero" con otro de manera local.

Luego, se llena la información de ese array.

El problema es que cuando se sale de la función, esa información se pierde porque es como que definimos "un nuevo puntero".

Finalizando, al hacer printf(vector[i]) estas accediendo a tu puntero original NULL y explota.
*/
void allocateArray(int* arr, int size, int value) {
    arr = (int*)malloc(size * sizeof(int));
    if(arr != NULL) {
        for(int i=0; i<size; i++) {
            arr[i] = value;
        }
    }
}