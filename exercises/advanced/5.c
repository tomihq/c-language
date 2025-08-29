/*
    ¿Por qué x e y tienen distintos tipos? ¿Qué representan?
    Empecemos con x.
    x es un puntero, específicamente un puntero que va a apuntar a un valor de la memoria que será un entero de 8 bits sin signo. Veamos la definición. La posición de memoria que almacenará el puntero x será la 0xF0. ¿Por qué 0xF0 es una dirección de memoria y no un simple número en hexadecimal? Porque estamos diciendo específicamente en el código, al castear, que lo trate como una dirección. De ahí el (uint8_t*).

    Análogo pasa con y. La única diferencia es que es un puntero a una dirección de memoria que tendrá almacenado un valor entero de 8 bits.

    Gracias a que x, e y, tienen un puntero con un tipo diferente a void, tenemos permitido desreferenciar estos punteros y acceder al valor que tienen en memoria.

    No ejecutar el código. Va a fallar. Es apropósito. Lo más probable es que esas posiciones de memoria no hayan sido reservadas por nuestro programa y el error ha producirse sea un SegmentationFault.
*/

#include <stdio.h>
#include <stdint.h>

int main(){
    uint8_t *x = (uint8_t*) 0xF0;
    int8_t *y = (int8_t*) 0xF6;
    printf("Dir de x: %p Valor: %d\n", (void*) x, *x);
    printf("Dir de y: %p Valor: %d\n", (void*) y, *y);

}