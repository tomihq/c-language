#include <stdio.h>

int main(void){
    char a = 'a';
    unsigned char b = 'b';
    short c = -150;
    unsigned short d = 150;
    int e = -1000;
    unsigned int f = 2000;
    long g = -100000;
    unsigned long h = 20000;
    void* p = NULL;

    printf("a: %c, size: %lu \n", a, sizeof(a));
    printf("b: %c, size: %lu \n", b, sizeof(b));
    printf("c: %d, size: %lu \n", c, sizeof(c));
    printf("d: %d, size: %lu \n", d, sizeof(d));
    printf("e: %d, size: %lu \n", e, sizeof(e));
    printf("f: %d, size: %lu \n", f, sizeof(f));
    printf("g: %ld, size: %lu \n", g, sizeof(g));
    printf("h: %lu, size: %lu \n", h, sizeof(h));
    printf("p: %p, size: %lu \n", p, sizeof(p));

    return 0;
}