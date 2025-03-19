#include <stdio.h>

/* existen 32 palabras reservadas que no debemos usar*/

int main()
{

    /* es posible escribir una misma variable de diferentes maneras en una sola linea*/
    int a = 80;
    float f = 28.5;
    float suma = (float)a + f; /* convertimos el dato "a" a flotante antes de sumarlo*/

    printf("%.2f",suma);

    printf("entero %i\n flotante %.2f\n double %.3f\n caracter %c\n",a, (float)a , (double)a , (char)a);
    
                        /* ciclo for */

    int contador;

    for(contador = 1;contador <= 2; contador++){
        printf("ciclo for %i\n",contador); /* imprime cada una de los valores del contador como numero*/
    }
    

                        /* ciclo while */

    int contador_while = 1; /* defino el contador */

    while(contador <= 3){
        printf("ciclo while %i\n",contador_while);
        contador++; /* le agrego 1 al contador en cada vuelta*/
    }


                        /* ciclo do while*/

    int ciclo_do = 1; 

    do{
        printf("ciclo do while %i\n",ciclo_do);
        ciclo_do++;
    } while (ciclo_do <= 3); /* ejecuta primero una accion y luego verifica la condicion*/
    

                        /* switch */
                        
    /* Se define una variable que controle los casos, para texto se debe poner entre comillas*/
    int casos; 
    printf("ingresa un numero\n");
    scanf("%i",&casos); /* el usuario ingresa una variable entera*/
    switch (casos)
    {
        case 1:
        printf("elejiste el primer caso\n");
        break;

        case 2:
        printf("elejiste el segundo caso\n");
        break;
    
        default:
        printf("no encontramos tu caso\n");
        break;
    }

    return 0;
}
