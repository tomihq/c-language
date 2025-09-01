#define VIDEO_COLS 80
#define VIDEO_FILS 50
// Cada posicion de memoria tiene 2 bytes
typedef struct ca_s {
    uint8_t c; // caracter
    uint8_t a; // atributos
} ca;

void screen_draw_layout(void) {
    // VIDEO es un puntero a la dirección de memoria del buffer de video
    ca(*p)[VIDEO_COLS] = (ca(*)[VIDEO_COLS])VIDEO; //trata a la matriz como 80 elementos por fila, equivale a: *((ca*)p + i*VIDEO_COLS + j)
    uint32_t f,c;
    for (f = 0; f < VIDEO_FILS; f++) {
        for (c = 0; c < VIDEO_COLS; c++) {
            p[f][c].c = ' ';
            p[f][c].a = 0x10;
        }
    }
}
/* 
    ¿Qué hace ca(*p)[VIDEO COLS] = (ca(*)[VIDEO COLS]) VIDEO;?
    Está almacenando un puntero a un array de structs, tratados como 80 elementos por fila. 

    Siendo p el puntero declarado ¿Por qué funciona esto: p[f][c].c = ’ ’;? Explicar detalladamente el proceso de desreferenciación
    p[0][0].a equivale a (*(p[i] + j)).a
    1. p[f] nos otorga un puntero a la fila f apuntando al primer struct de la fila f.
    2. p[f][c] a partir del puntero en la fila f, elegimos qué columna queremos a través del puntero. *(p[f]+c). Accedemos al struct y devuelve el struct ca.
    3. p[f][c].c toma la propiedad c del struct que conseguimos anteriormente y lo setea en vacío.

    ¿Qué pasaría si en vez de ca(*p)[VIDEO COLS] hubiéramos declarado ca** p?
    Explotaría el cast.
    ca **p es un puntero puntero a ca. En este caso, estaría apuntando a una dirección de memoria, que a su vez si se desreferencia nos traería un único valor.
    p   → dirección que contiene otro puntero
    *p  → dirección de un struct ca
    **p → struct ca

    Para que p[i][j] funcione correctamente:
        1. p tiene que apuntar a un arreglo de punteros, uno por fila.
        2. Cada p[i] tiene que apuntar a un bloque contiguo de VIDEO_COLS structs.
    Para usar doble puntero, tendrías que hacer algo así:
    ca **p = malloc(VIDEO_FILS * sizeof(ca*));  // array de punteros a filas
    for (int i = 0; i < VIDEO_FILS; i++) {
        p[i] = &VIDEO[i*VIDEO_COLS];            // cada puntero apunta a su fila
    }

    

*/