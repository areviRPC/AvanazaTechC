#include <stdio.h>
#include <stdlib.h>

int main(){

                            // malloc 

    // declaro un apuntador
    int *ptr_array; 

    // uso malloc para separar un epsacio de memoria cuyo argumento es el espacio de la variable por la cantidad de elementos
    ptr_array = (int*) malloc(sizeof(int)* 6);

    // asigno dos valores a las primeras posiciones
    *ptr_array = 2;
    *(ptr_array + 1) = 10;

    // ptr_array[2] es otra forma de acceder al valor como si fuera un array

    // imprimo los valores guardados 
    printf("direccion de memoria primer elemento malloc %p\n", ptr_array);
    printf("valor de [0] asignado: %i\n", *ptr_array);
    printf("valor de [1] asignado: %i\n", *(ptr_array + 1));
    printf("\n");

                            // sin inicializar 

    // declaor un apuntador malloc 
    int *ptr_malloc;

    // uso malloc para separar un epsacio de memoria cuyo argumento es el espacio de la variable por la cantidad de elementos
    ptr_malloc = (int*) malloc(sizeof(int)* 6);

    // no importa si asigno o no valores a los elementos declarados. igual se van a guardar en espacios al azar
    printf("direccion de memoria primer elemento malloc %p\n", ptr_malloc);
    printf("valor de [0] sin asignar: %i\n", *ptr_malloc);
    printf("valor de [1] sin asignar: %i\n", *(ptr_malloc + 1));
    printf("\n");

                            // calloc

    // declaro un apuntador calloc
    int *ptr_calloc;

    // recibe como argumentos la cantidad de elementos y el tamaño de espacio que voy a guardar
    ptr_calloc = (int*) calloc(6, sizeof(int));

    // con calloc separo el espacio de memoria y todos los elementos son 0
    printf("direccion de memoria del primer elemento calloc %p\n", ptr_calloc);
    printf("direccion de memoria del primer elemento calloc (+4) %p\n", (ptr_calloc + 1));
    printf("valor de [0] en calloc: %i\n", *ptr_calloc);
    printf("valor de [1] en calloc: %i\n", *(ptr_calloc + 1));
    printf("\n");

                            // realloc

    // realloc reasigna el espacio de memoria. Si trato de acceder a  un elemento que no existe saca un null
    ptr_calloc = (int*) realloc(ptr_calloc , 2);
    printf("reasignacion de direccion de memoria del calloc %p\n", ptr_malloc);

    // libera el espacio de memoria que paso por argumento. este no se puede volver a usar ni a borrar 
    free(ptr_calloc);

    // borro el archivo del compilador
    int borrado1 = remove("9- Malloc - calloc - realloc - free");


    return 0;
}
