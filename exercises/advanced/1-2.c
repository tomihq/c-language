/*
    Definir una estructura monstruo_t que contenga los siguientes campos:
        nombre (string)
        vida (entero)
        ataque (double)
        defensa (double)
    Luego, inicializar un array de monstruos y mostrar por pantalla el nombre y la vida de
    cada uno de ellos.
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct monstruo {
    char nombre[50];
    uint8_t vida;
    double ataque;
    double defensa;
} monstruo_t;

monstruo_t evolution(monstruo_t m){
    monstruo_t monstruo_evolucionado = m;
    monstruo_evolucionado.ataque += 10;
    monstruo_evolucionado.defensa += 10;
    return monstruo_evolucionado;
}

int main(void){
    const uint8_t size = 2;
    monstruo_t monstruos[] = {{"Birkin", 100, 100, 400}, {"Snake", 80, 90, 400}};
    for(int i=0; i<size; i++){
        printf("Nombre: %s, vida: %d \n", monstruos[i].nombre, monstruos[i].vida);
    }

    monstruo_t monstruo_evolucionar = monstruos[0];
    monstruo_t monstruo_evolucionado = evolution(monstruo_evolucionar);
    printf("El monstruo %s ha evolucionado!. Ataque: %f, Defensa: %f \n", monstruo_evolucionado.nombre, monstruo_evolucionado.ataque, monstruo_evolucionado.defensa);

    return 0; 
}
