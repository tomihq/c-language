#include <stdio.h>

void print_int(int x){
    printf("%d \n", x);
}


void pretty_print_int(x){
    printf("Entero [%lu bits]: %d \n", sizeof(x) * 8, x);
}

int main(){
    void (*print)(int) = print_int; //asignamos al puntero de print la direccion de memoria donde se encuentra print_int que toma un entero.
    print(42);
    print = pretty_print_int; //asignamos al puntero de print la direccion de memoria donde se encuentra pretty_print_int que toma un entero.
    print(3);
    return 0; 
}