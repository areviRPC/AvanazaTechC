
#include <stdio.h>
long Factorial(long numero); // la funcion debe ser declarada al inicio 
void cubo(int *n);

// queremos desarrollar la funcion factorial 

int main()
{
    int numero;
    printf("ingresa el numero \n");
    scanf("%i",&numero); // pedimos el numero con & para asignarlo a numero
    
    for(int i = 0;i<= numero; i++){
        printf("%ld\n",Factorial(i)); 
        //aplpica la funcion factorial a todos los numeros del 0 a numero e imprime el resultado
    }

    printf("el valor original del numero es: %i\n", numero);

    cubo(&numero); 
    // la ejecucion de esta funcion por apuntador requiere usar "&" para reasinar el espacio en memoria

    printf("el nuevo valor del numero al cubo es: %i\n",numero);

    return 0;
}

// la funcion se declara fuera del main (main para ejecutar)


long Factorial(long numero){  // tipo de retorno, tipo de dato de entrada , variable de entrada
    if (numero <= 1){
        return 1; // para 1 y 0
    }
    else{
        return(numero * Factorial(numero - 1)); 
        // se llama a si misma multiplicando cada numero por su anterior (hasta 1)
    }

}

                        // funcion por apuntador 

void cubo(int *n){ // esta funcion usa y reasigna el espacio en memoria de la variable que le pasamos
    *n = *n * *n * *n;

}
