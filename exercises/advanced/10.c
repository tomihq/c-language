#include <stdio.h>
#include <string.h>

int main(){
    char s[] = "hola";
    size_t s_size = strlen(s);
    printf("s_size: %ld \n", s_size); 
    
    char s_copy[10]; //lo defino de 10 para primero copiar s a s_copy. Luego, para usarlo de concat.
    strcpy(s_copy, s);
    printf("s_copy: %s \n", s_copy);
    printf("Posicion de s en memoria: %p | Posicion de s_copy en memoria: %p \n", (void*) &s, (void*) &s_copy);

    if(strcmp(s, s_copy)){
        printf("Son iguales! \n");
    }

    strcat(s_copy, " adios");
    printf("Concat s y s_copy: %s \n", s_copy);
}