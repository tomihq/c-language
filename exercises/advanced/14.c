/* 
    Queremos crear una lista de nodos donde cada lista particular almacenará punteros a diferentes archivos en un file system.

    La lista tendrá la siguiente información:
        1. tipo de archivo que almacena (type_t).
        2. tamaño de la lista.
        3. puntero al primer nodo (archivo).

    Cada nodo tendrá la siguiente información:
        1. puntero a la información que se desconoce su tipo (apropósito para el ej)
        2. puntero al siguiente nodo.

    El tipo de los archivos que almacenará la lista puede ser alguno de los siguientes:
    typedef enum e_type {
        TypeFAT32 = 0,
        TypeEXT4 = 1,
        TypeNTFS = 2
    } type_t;

    Se pide: implementar las siguientes funciones
    list_t* listNew(type_t t);
    void listAddFirst(list_t* l, void* data);
    void* listGet(list_t* l, uint8_t i); //se asume: i < l->size
    void* listRemove(list_t* l, uint8_t i); //se asume: i < l->size
    void listDelete(list_t* l);

    listNew: Instancia una nueva lista en memoria y devuelve el puntero hacia la lista.
    listAddFirst: Agrega un nuevo nodo a la lista y lo coloca en primer lugar adjuntando la información del archivo que está en void* data. 
    listGet: Obtiene un puntero a los datos del nodo i en la lista.
    listRemove: Elimina un nodo de la lista y devuelve el puntero a los datos del nodo eliminado. 
    listDelete: Elimina la lista y libera la memoria reservada para los nodos y los datos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum e_type {
    TypeFAT32 = 0,
    TypeEXT4 = 1,
    TypeNTFS = 2
} type_t;

typedef struct node {
    void* data;
    struct node* next; 
} node_t; 

typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
} list_t;

list_t* listNew(type_t t);
void listAddFirst(list_t* l, void* data);
void* listGet(list_t* l, uint8_t i); //se asume: i < l->size
void* listRemove(list_t* l, uint8_t i); //se asume: i < l->size
void listDelete(list_t* l);

int main(){
    list_t* l = listNew(0);
    if(l == NULL){
        printf("ERR assigning dynamic memory. Leaving program...");
        return 1;
    }
    printf("---List Created--- \n");
    printf("Type: %d | Size: %d | First: %p \n", l->type, l->size, (void*) l->first);
    return 0; 
}

list_t* listNew(type_t t){
    list_t* list = malloc(sizeof(list_t));
    if(list == NULL){
        printf("ERR assigning dynamic memory");
        return NULL;
    }
    list -> type = t; 
    list -> size = 0; 
    list -> first = NULL;
    return list; 
}
