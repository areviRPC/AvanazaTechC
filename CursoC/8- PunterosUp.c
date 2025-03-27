#include <stdio.h>
#include <stdlib.h>

// funcion que modifica el array

void cambio(int *ptr_array){ // creamos una funcion que recibe el valor guardado en la direccion del apuntador
    printf("funcion aplicada \n");
    (*ptr_array)++; // aumentamos en 1 el valor que existe en el apuntador 
}

int main()
{
    int valor = 6; 
    // * para declarar apuntadores (especificamos que tipo de dato va a apuntar)
    // (int *ptr_inutil = valor) esto no tiene sentido porque lo que estamos haciendo es asignarle al apuntador la direccion de "2" 
    int *ptr_valor = &valor; // esto esta bien porque le asignamos al apuntador el espacio de memoria de "valor" con "&"

    int *apuntar = ptr_valor;
    printf("apuntaaaaaar %p\n", &apuntar);
    printf("direccion de memoria de la variable %p\n", &valor);
    printf("valor del apuntador  %p\n", ptr_valor );
    printf("valor de la variable %i\n", valor);

    int array[2]; // declaramos un array de 2 elementos (separa 2 espacios)
    int *ptr_array = array; // el apuntador señalara al primer elemento del array

    array[0] = 5;
    array[1] = 10;

                                    // con un array

    // diferencia entre imprimir la direccion del apuntador y el valor guardado en ese espacio de memoria
    printf("-- array --\n");
    printf("direccion 1: %p\n" , ptr_array); // esto imprime la direccion de memoria
    printf("valor del elemento 1: %i\n" , *ptr_array); // esto imprime el valor de la variable en ese espacio de memoria
    printf("direccion 2 (4 bites arriba 'int'): %p\n" , ptr_array + 1);
    printf("valor del elemento 2: %i\n" , *(ptr_array + 1));

    array[0] = 2;
    printf("nuevo valor de la variable 1: %i\n" , *ptr_array);
    printf("direccion 1 (no cambia): %p\n" , ptr_array);

                                    // con una funcion
    printf("--funcion-- \n");
    printf("direccion 2 orginal: %p\n" , ptr_array + 1); 
    cambio(&array[1]); // pasamos como argumento el apuntador a la 
    printf("valor nuevo del segundo elemento: %i\n" , *(ptr_array + 1)); 

    // borro el archivo del compilador
    int borrado1 = remove("8- PunterosUp");

    return 0;

}


