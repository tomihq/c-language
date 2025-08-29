/*
    Explicar qué sucedería si la firma de la función swap fuera 
    void swap(int a, int b).

    En ese caso, ¿podríamos intercambiar los valores de x e y?
    
    No, no podríamos. Si el tipado de la función requiere dos números, y no los punteros ni tampoco dirección
    a memoria a los datos originales, como todo pasa por copia, los valores de a y b
    se modificarían solamente en el ámbito de la función swap pero seguirían
    con su valor original en main.
*/

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
}