/* same 15 pero con lista doblemente enlazada */
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
    struct node* prev; 
} node_t; 

typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
    node_t* last; 
} list_t;


list_t* listNew(type_t t);
void listAddLast(list_t* l, void* data);
void listAddFirst(list_t* l, void* data);
void* listGet(list_t* l, uint8_t i); //se asume: i < l->size
void* listRemove(list_t* l, uint8_t i); //se asume: i < l->size
void listDelete(list_t* l);
void listSwapNodes(list_t* l, node_t* n, node_t* m); //asumo que me piden sin ser adyacentes.

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
    listAddLast(l, f2);
    printf("Type: %d | Size: %d | First: %p \n", l->type, l->size, (void*) l->first);
    printf("Type: %d | Size: %d | Last: %p \n", l->type, l->size, (void*) l->last);
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
    list -> last = NULL;
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
    n->prev = NULL;         
    if (l->first != NULL) {  
        l->first->prev = n; 
    }
    l -> size += 1;
    l -> first = n; 
}

void listAddLast(list_t* l, void* data){
    node_t* new_last_node = malloc(sizeof(node_t));
    if(new_last_node == NULL){
        printf("ERR assigning dynamic memory to node_t"); 
    }
    switch(l->type) {
        case TypeFAT32:
            new_last_node->data = (void*) copy_fat32((fat32_t*) data);
            break;
        case TypeEXT4:
            new_last_node->data = (void*) copy_ext4((ext4_t*) data);
            break;
        case TypeNTFS:
            new_last_node->data = (void*) copy_ntfs((ntfs_t*) data);
            break;
    }

    if(l -> size == 0){
        l -> first = new_last_node; 
        new_last_node -> prev = NULL; 
        new_last_node -> next = NULL;
    }else {
        node_t* old_last_node = l -> first; 
        //si llegamos al ultimo nodo no tiene siguiente.
        while(old_last_node -> next != NULL){
            old_last_node = old_last_node -> next;  
        }
        new_last_node -> prev = old_last_node;
        old_last_node -> next = new_last_node; 
    }

    l -> last = new_last_node; 
    l -> size += 1; 

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
        if(tmp -> prev != NULL){
            l -> first -> prev = NULL;
        }
    }else{
        node_t* n = l -> first;
        //vamos hasta el anterior al que queremos eliminar para jugar con los next.
        for(uint8_t j=0; j< i-1; j++){
            n = n -> next;
        }
        tmp = n->next;
        data = tmp->data;

        n->next = tmp->next;
        if (tmp->next != NULL) {        
            tmp->next->prev = n;     
        }
    }
    free(tmp);
    l -> size--;

    return data; 
}

/* 
    Si la lista esta vacia o tiene un solo nodo no hago nada.
    Sino:
        1. n y m no son adyacentes:
            Busco el antecesor y el sucesor de n.
            Busco el antecesor y el sucesor de m.

            Como tengo que swapear n con m hago:
                ant_n -> next = m;
                m -> next = suc_n;

                ant_m -> next = n;
                n -> next = suc_m;
        2. n y m son adyacentes:

    Puede aparecer n primero o m primero. 

*/

//refactorizar a DLL
void listSwapNodes(list_t* list, node_t* n, node_t* m) {
    if (!list || !n || !m || n == m)
        return;

    node_t *prev_n = NULL, *prev_m = NULL, *curr = list->first;

    while (curr) {
        if (curr->next == n) prev_n = curr;
        if (curr->next == m) prev_m = curr;
        curr = curr->next;
    }

    if (list->first == n) prev_n = NULL;
    if (list->first == m) prev_m = NULL;

    /* Adyacentes*/
    if (n->next == m) {
        if (prev_n) prev_n->next = m;
        else list->first = m;
        n->next = m->next;
        m->next = n;
        return;
    }
    
    if (m->next == n) {
        if (prev_m) prev_m->next = n;
        else list->first = n;
        m->next = n->next;
        n->next = m;
        return;
    }

    /* Caso no adyacentes */
    if (prev_n) prev_n->next = m;
    else list->first = m;

    if (prev_m) prev_m->next = n;
    else list->first = n;

    node_t* tmp = n->next;
    n->next = m->next;
    m->next = tmp;
}

/* listDelete: Elimina todos los datos de la lista y su información. La idea es primero liberar la memoria de cada uno de los nodos, y por último, la de la lista. No se puede hacer en el orden inverso porque si borramos la lista perdemos el puntero hacia el primer nodo, y por ende, hasta los otros */

void listDelete(list_t* l){
    if(l->size == 0) return; 
    node_t* n = l->first;
    while(n != NULL){
        node_t* tmp = n;
        n = n->next;
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
        /*free(tmp); para forzar fuga en valgrind*/
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