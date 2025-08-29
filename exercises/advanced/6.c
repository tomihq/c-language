/* 
    Completar los ?? en el siguiente código.
    
    El único objetivo de este ejercicio es que notes que si estás definiendo un puntero
    lo único que podés almacenar ahí es una dirección de memoria.

    En este caso, como x almacena un puntero hacia un valor unsigned hice un array
    con 1 valor positivo y negativo justamente para justificar esos tipos.
*/

#include <stdio.h>
#include <stdint.h>

int main(){
    int8_t memoria[2] = {1, -2};
    uint8_t *x = (uint8_t*) &memoria[0];
    int8_t *y = &memoria[1];
    printf("Dir de x: %p Valor: %d\n", (void*) x, *x);
    printf("Dir de y: %p Valor: %d\n", (void*) y, *y);
}