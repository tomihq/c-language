/*
    Definir una funcion que reciba un string y lo pase a mayúsculas.
    Pista: alcanza con sumar la diferencia entre 'A' y 'a' a cada letra.

    Sólo aplicar la conversión si lo que llega es una letra minúscula.

    Si la función recibe un string en realidad recibe un puntero a la primera letra.
    La idea sería recorrer ese char* hasta que nos encontremos con '\0'.
    Si encuentro una minúscula entonces, cambio ese caracter por el caracter: c + 'A' - 'a'  
*/

#include <stdio.h>

void pasarAMayusculas(char* ptr);

int main(){
    char c[] = "aBc1De";
    pasarAMayusculas(c);
    printf("string: %s \n", c);
    return 0;
}


void pasarAMayusculas(char* ptr){
    while(*ptr != '\0'){
        if(*ptr >= 'a' && *ptr <= 'z'){
            *ptr += 'A' - 'a';
        }
        ptr++;
    }
}