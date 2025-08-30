#include <stdio.h>

static void a(int c[]);
static void b(int* c);

int main(){
    int c[10] = {1, 2, 3};
    printf("-----Función a(c)----- \n");
    a(c);
    printf("-----Función b(c)----- \n");
    b(c);
    printf("-----Función a(&c[0])----- \n");
    a(&c[0]);
    printf("-----Función b(&[0])----- \n");
    b(&c[0]);
    return 0;
}


void a(int c[]){
    printf("c está en la posición de memoria: %p\n", (void*) c);
    printf("Primer elemento, *c: %d, c[0]: %d \n", *c, c[0]);
    printf("Segundo elemento, *c: %d, c[0]: %d \n", *(c+1), c[1]);
    return;
}

void b(int* c){
    printf("c está en la posición de memoria: %p \n", (void*) c);
    printf("Primer elemento, *c: %d, c[0]: %d \n", *c, c[0]);
    printf("Segundo elemento, *c: %d, c[0]: %d \n", *(c+1), c[1]);
    return;
}