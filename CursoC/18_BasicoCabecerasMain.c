#include <stdio.h>
#include <string.h>

#include "18_BasicoCabeceras.h" // inclusion del arcchivo cabecera 


int main()
{
    // definicion de variables y ejecucion de funciones
    int a=3 , b=2, c;
    float area;
    char inicial;

    c = suma(a,b);
    printf("c: %d\n",c);

    c = resta(a,b);
    printf("c: %d\n",c);

    area = area_circulo(2);
    printf("El area del circulo es %f\n", area);

    inicial = primer_caracter("moneda");
    printf("El primer caracter es: %c\n", inicial);

    return 0;
}

                                                    /* NOTA 
Puede que el compilador no reconozca la ejecucion por sepaado de ambos arvhcios. 
Para esto desplegamos la consola y en la carpeta usamos los comandos 

gcc 18_BasicoCabecerasMain.c 18_BasicoCabecerasFun.c -o BasicoMain (para ejecutar ambos archivos en uno solo) 

./BasicoMain (para ejecutar dicho archivo (si ya existe solo ejecutar)) 

*/ 
