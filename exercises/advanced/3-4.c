/*
    Sin correr el código, responder:
    ¿Cuál es la diferencia entre x y p? ¿Y entre x y &x? ¿Y entre p y *p?
    La diferencia entre x y p es que x tiene es una variable que almacena un int (42) mientras que p es un puntero que apunta a la dirección de memoria donde se encuentra x. Es decir, si la variable x está en la posición de memoria 0x01 entonces p tiene 0x01 (nótese que la posición de memoria es irreal, es solamente un ejemplo.)

    La diferencia entre x y &x es que x es literalmente el valor que representa la variable (42) mientras que &x es la dirección de memoria donde está almacenada la variable con el valor, siguiendo el parráfo anterior, sería 0x01.

    La diferencia entre p y *p es que p es el puntero a la dirección de x, es decir, siguiendo los párrafos anteriores, p es 0x01 mientras que *p es el valor que tiene esa dirección de memoria (42).

    ¿Qué valores creen que se van a imprimir por terminal?
    Direccion de x: 0x01 Valor: 42
    Dirección de p: 0x03 (donde esté guardado el puntero p) Valor: 0x01
    Valor de lo que apunta p: 42

*/
#include <stdio.h>

int main(){
    int x = 42;
    int *p = &x; //equivale a int* p = &x
    printf("Direccion de x: %p Valor: %d\n", (void*) &x, x);
    printf("Direccion de p: %p Valor: %p\n", (void*) &p, (void*) p);
    printf("Valor de lo que apunta p: %d\n", *p);
}