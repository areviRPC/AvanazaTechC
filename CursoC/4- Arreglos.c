#include <stdio.h>

int main()
{
    /* se debe declarar el valor del arreglo siempre*/
    int arreglo[4] = {3,4,1,5};
    // si no declaro todos los valores de un arreglo estos se guardan en 0
    printf("la posicion 2 de arreglo es %i\n",arreglo[2]); 

    int sizeA;
    printf("tamaño del arreglo \n");
    scanf("%i",&sizeA); /* El usuario ingresaa el tamaño del arreglo*/
    int age[sizeA]; 

    for(int i=0 ; i<sizeA;i++){ /* usamos el valor del arreglo para rellenar los valores*/
        printf("ingresa el valor %i\n",i+1);
        scanf("%i",&age[i]); /*Se rellenan los valores por teclado*/
    }
    printf("los valores del arreglo son: \n");

    for(int i = 0;i<sizeA ; i++){
        printf("%i-\n",age[i]); /*se imprimen los valores uno a uno*/
    }

                    /* break and continue */

    int num_break = 0;
    printf("con break \n");
    while(num_break <= 7){

        num_break++;
        if(num_break == 2){
            break; /* la sentencia break hace que el ciclo while se corte cuando el if se cumple */
        }
        printf("%i\n",num_break);
    }

    int num = 0;
    printf("con continue \n");
    while(num <= 4){
        
        num++; // importante cambiar el valor de la variable fuera del continue o break
        if(num == 2){
            continue; // La sentencia continue hace que el codigo se salte ese paso del ciclo cuando el if se cumple 
        }
        printf("%i\n",num);

    }

    // borro el archivo del compilador
    int borrado1 = remove("4- Arreglos");
    
    return 0;
}

