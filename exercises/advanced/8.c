/*
Pensar si existe una diferencia entre definir un string como str1 o como str2 en el
siguiente código:

int main(){
    char *str1 = "Hola";
    char str2[] = "Hola";
    printf("%s\n", str1);
    printf("%s\n", str2);
    return 0;
}

1. str1 es un puntero a un literal de cadena. La cadena "Hola" se almacena normalmente en memoria de solo lectura. Si intentás modificar algo el comportamiento puede ser indeseado. Podés cambiar a otra dirección (otro literal), ej.: str1 = "Adios" vale.
2. Es un array de caracteres que se inicializa con los caracteres de "Hola". La cadean se copia en la memoria local (stack) o heap si se crea de manera dinámica. Se puede modificar caracter a caracter pero no la podés reasignar.
*/