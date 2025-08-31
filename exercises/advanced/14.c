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

/* MOCKS and DUMMY TYPES*/
/* DUMMY TYPES */
typedef uint32_t fat32_t;
typedef uint32_t ext4_t;
typedef uint32_t ntfs_t;
/* MOCKS */
fat32_t* new_fat32();
fat32_t* copy_fat32(fat32_t* file); 
void rm_fat32(fat32_t* file);
ext4_t* new_ext();
ext4_t* copy_ext4(ext4_t* f);
void rm_ext4(ext4_t* f);
ntfs_t* new_ntfs();
ntfs_t* copy_ntfs(ntfs_t* f);
void rm_ntfs(ntfs_t* f);


int main(){
    list_t* l = listNew(TypeFAT32);
    if(l == NULL){
        printf("ERR assigning dynamic memory. Leaving program...");
        return 1;
    }
    printf("---List Created--- \n");
    printf("Type: %d | Size: %d | First: %p \n", l->type, l->size, (void*) l->first);
    fat32_t* f1 = new_fat32();
    fat32_t* f2 = new_fat32();
    listAddFirst(l, f1);
    printf("Type: %d | Size: %d | First: %p \n", l->type, l->size, (void*) l->first);
    listAddFirst(l, f2);
    printf("Type: %d | Size: %d | First: %p \n", l->type, l->size, (void*) l->first);
    listDelete(l);
    rm_fat32(f1);
    rm_fat32(f2);
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

void listAddFirst(list_t* l, void* data){
    node_t* n = malloc(sizeof(node_t));
    if(n == NULL){
        printf("ERR assigning dynamic memory to node_t"); 
    }

    switch(l->type) {
        case TypeFAT32:
            n->data = (void*) copy_fat32((fat32_t*) data);
            break;
        case TypeEXT4:
            n->data = (void*) copy_ext4((ext4_t*) data);
            break;
        case TypeNTFS:
            n->data = (void*) copy_ntfs((ntfs_t*) data);
            break;
    }
    
    n -> next = l -> first;
    l -> size += 1;
    l -> first = n; 
}

void* listGet(list_t* l, uint8_t i){
    node_t* n = l -> first;
    for(uint8_t j=0; j<i; j++){
        n = n -> next;
    }
    return n -> data;
}

void* listRemove(list_t* l, uint8_t i){
    node_t* tmp = NULL;
    void* data = NULL; 
    if(i == 0){
        data = l -> first -> data;
        tmp = l -> first;
        l -> first = l -> first -> next;
    }else{
        node_t* n = l -> first;
        //vamos hasta el anterior al que queremos eliminar para jugar con los next.
        for(uint8_t j=0; j<i; j++){
            n = n -> next;
            data = n -> next -> data;
            tmp = n -> next;
            n -> next = n -> next -> next; //nos "salteamos" el que eliminamos
        }
    }
    free(tmp);
    l -> size--;

    return data; 
}

/* listDelete: Elimina todos los datos de la lista y su información. La idea es primero liberar la memoria de cada uno de los nodos, y por último, la de la lista. No se puede hacer en el orden inverso porque si borramos la lista perdemos el puntero hacia el primer nodo, y por ende, hasta los otros */

void listDelete(list_t* l){
    node_t* n = l->first;
    while(n){
    node_t* tmp = n;n = n->next;
    switch(l->type) {
        case TypeFAT32:
            rm_fat32((fat32_t*) tmp->data);
            break;
        case TypeEXT4:
            rm_ext4((ext4_t*) tmp->data);
            break;
        case TypeNTFS:
            rm_ntfs((ntfs_t*) tmp->data);
            break;
    }
        free(tmp);
    }
    free(l);
}


fat32_t* new_fat32(){
    fat32_t* p = malloc(sizeof(fat32_t));
    if(p == NULL){
        printf("ERR assigning dynamic memory to fat32_t* p");
        return NULL; 
    }
    *p = 123; //just a dummy value. 
    return p; 
}

fat32_t* copy_fat32(fat32_t* file){
    if (!file) return NULL;
    fat32_t* copy = malloc(sizeof(fat32_t));
    if (!copy) return NULL;
    *copy = *file; //copy dummy value
    return copy;
}

void rm_fat32(fat32_t* file){
    free(file);
}

ext4_t* new_ext4() { 
    ext4_t* f = malloc(sizeof(ext4_t)); 
    *f = 111; return f; 
}
ext4_t* copy_ext4(ext4_t* f) { 
    ext4_t* c = malloc(sizeof(ext4_t)); 
    *c = *f; 
    return c; 
}
void rm_ext4(ext4_t* f) { 
    free(f); 
}

ntfs_t* new_ntfs() { 
    ntfs_t* f = malloc(sizeof(ntfs_t)); 
    *f = 222; 
    return f; 
}

ntfs_t* copy_ntfs(ntfs_t* f) { 
    ntfs_t* c = malloc(sizeof(ntfs_t)); 
    *c = *f; 
    return c; 
}

void rm_ntfs(ntfs_t* f) { 
    free(f); 
}