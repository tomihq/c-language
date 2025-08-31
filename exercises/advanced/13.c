#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct persona {
    uint8_t edad;
    char nombre[]; //flexible array member
} persona_t;

static persona_t* crearPersona(char* nombre, uint8_t edad);
static void eliminarPersona(persona_t* p);

int main(void){
    persona_t* p = crearPersona("Tomás", 21);
    if(p == NULL){
        //Manejar error de asignación de memoria.
        return 1;
    }
    printf("Nombre: %s, Edad: %d \n", (*p).nombre, (*p).edad);
    printf("sizeof: %lu \n", sizeof(p));
    eliminarPersona(p);
    p = NULL;
    //Comportamiento indefinido. A fines didácticos.
    printf("Nombre: %s, Edad: %d \n", (*p).nombre, (*p).edad);
    return 0;
}

//sizeof(persona_t) te proporciona el tamaño en bytes de los campos que se pueden calcular en tiempo de compilación. En nuestro caso, sizeof(persona_t) solo retorna lo que cuesta en bytes almacenar un uint8_t + padding default.
//¿Y char nombre[]? no cuesta nada en memoria porque no especificamos su tamaño en ningún lado. Lo que tenemos que reservar esa memoria aparte. 
//Esta idea está copada porque estás reservando el tamaño de nombre que necesitás, y no reservás para cada persona un montón de bytes que quizá no le das uso. 
static persona_t* crearPersona(char* nombre, uint8_t edad){
    size_t nombre_size = strlen(nombre);
    persona_t* p = malloc(sizeof(persona_t) + (nombre_size + 1));
    if(p == NULL){
        return NULL;
    }
    (*p).edad = edad;
    strcpy((*p).nombre, nombre);

    return p; 
}

static void eliminarPersona(persona_t* p){
    free(p);
}