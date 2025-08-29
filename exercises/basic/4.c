#include <stdio.h>
#include <stdint.h>

int main(){
    int8_t a = -125;
    uint8_t b = 255;
    int16_t c = 28000;
    uint16_t d = 65534;
    int32_t e = -100000;
    uint32_t f = 10000000;
    int64_t g = -1400000;
    uint64_t h= 10000000;
    
    printf("a: %d, size: %lu \n", a, sizeof(a));
    printf("b: %d, size: %lu \n", b, sizeof(b));
    printf("c: %d, size: %lu \n", c, sizeof(c));
    printf("d: %d, size: %lu \n", d, sizeof(d));
    printf("e: %d, size: %lu \n", e, sizeof(e));
    printf("f: %d, size: %lu \n", f, sizeof(f));
    printf("g: %ld, size: %lu \n", g, sizeof(g));
    printf("h: %lu, size: %lu \n", h, sizeof(h));



    return 0;
}