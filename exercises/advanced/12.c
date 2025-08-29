#include <stdio.h>

typedef struct persona {
    char nombre[50];
    int edad;
} persona_t;

persona_t* crearPersona(char nombre[], int edad);

int main(void){

    return 0;
}

persona_t* crearPersona(char nombre[], int edad){
    persona_t *p = malloc(sizeof(persona_t));
    if(p == NULL){
        return NULL;
    }

    
}