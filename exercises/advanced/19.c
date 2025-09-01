#include <stdio.h>

int main() {
    
    //matriz de 3*4 = 12 elementos (0 a 11)
    int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
    };
    
    int *p = &matrix[0][0]; //*1
    int (*reshape)[2] = (int (*)[2]) p; //*2
    
    printf("%d\n", p[0]); //4
    printf("%d\n", reshape[2][0]); //4
    printf("%d \n", matrix[2][4]); //comportamiento indefinido

    //A partir de acá agrego ejemplos para demostrar que vos podés recorrer la matriz como quieras. La diferencia es que a veces necesitamos ciertas "propiedades" y el casteo nos da ese poder.

    //Recorremos la matriz casteada de manera redimensionada. Consideramos 6 filas de 2 elementos.
    printf("FOR reshape \n");
    //El computo que hace reshape es: *((int*) reshape + i*2 + j)
    for(int i=0; i<6; i++){
        for(int j = 0 ; j<2; j++){
            printf("%d ", reshape[i][j]); //Parece flashero, pero está explicado abajo. 
        }
       
    }
    
    printf("\n");

    //Recorremos desde la primera fila, todos los valores hacia abajo en memoria. Al recordar que están en orden, estarías viendo f1c1, f1c2, f1c3, f1c4, f2c1 pero acá no le importa. Va a barrer la memoria. El cuidado que tenés que tener es que no te pases del tamaño total. En este caso funciona porque al ser una matriz, tenés garantía que si te "pasás" de columna, estás en la siguiente fila. Por eso, vale siempre y cuando no te pases de la cantidad de elementos de la matriz. NO usar esta forma. No es segura ni legible. Estás abusando de muchas cosas. En todo caso, usá p para empezar desde &matrix[0][0] que el lenguaje lo entiende mejor.
    printf("FOR matrix lineal \n");
    for(int i=0; i<12; i++){
        printf("%d ", matrix[0][i]); //Parece flashero, pero está explicado abajo. 
    }
    

    printf("\n");

    //Recorremos con el puntero posicionado en f1c1 hacia el final.  Lo mismo que arriba, estás barriendo la memoria hacia abajo.
    printf("FOR p lineal (puntero a fil 0 col 0) \n"); 
    for(int i=0; i<12; i++){
        printf("%d ", p[i]);
    }

    printf("\n");
    
    return 0;
}

/* 
    *1: Almacena la dirección de memoria de la fila 1 columna 1. Es decir estamos apuntando a específicamente ese lugar. Si nos movemos, estamos moviendonos en la memoria. ¡Podemos recorrer la matriz entera de un solo saque! Lo recomendable es que sepas cuantas posiciones podés moverte porque sino caerías en info basura. En este caso te moverías máximo hasta 11 (12 elems)
    *2: Castea el puntero p a querer tratar p como un puntero a array de enteros de longitud 2 (6 filas de 2 elementos).
    El reshape es una técnica de bajo nivel para obtener flexibilidad y control total sobre cómo se manipula la memoria. En este caso particular le estamos diciendo que trate a matrix como una matriz de 2 filas.
    Entonces, si queremos recorrer la matriz podemos jugar con la idea de que "cada fila tiene longitud 2"
        1: {1, 2}
        2: {3, 4}
        3: {5, 6}
        4: {6, 7}
        ... pero en realidad, en la memoria eso así no existe.
    Si hacés reshape[2][0] con este cast, se va a mover al 5: En realidad lo que hace es lo mismo que haría matrix[1][0] que te daría 5 también ¿por qué? porque al ser una matriz.
    
    TLDR: Siempre que tengas un puntero a una matriz, podés recorrer esa matriz como vos quieras. Lo que sí, procurá que no te pases nunca del último elemento porque el comportamiento es indefinido.
    reshape no es más una forma "amigable" para el programador que te permite "re-entender" una matriz con un poco más o menos de filas, pero el recorrido que hacés es el mismo que &matrix

    Imaginate que ahora querés hacer un reshape y castear de manera que querés que sean 4 filas
    Entonces, podés hacer el for así :
    for(int i=0; i<4; i++){
        for(int j = 0; j<3; j++){
            printf("%d ", reshape[i][j]);
        }
       
    }
    Al reshape NO le importa qué indices ponés, al final del día hace la misma cuenta que todos pero con un pequeño cambio de "como trata el array" para mantenerse en tu array original: *((int*)reshape + i*4 + j)

    En C, la memoria de un array multidimensional es contigua y lineal.
    Un int* te deja recorrerlo como vector plano.
    Un int (*)[N] te deja verlo como una tabla de N columnas, pero el límite real siempre es la cantidad total de elementos.
    Los corchetes son solo azúcar sintáctica para aritmética de punteros:
    a[i][j] == *((int*)a + i*N + j).
    El compilador no hace chequeos → si te pasás, es comportamiento indefinido.

*/