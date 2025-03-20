/*ARCHIVOS DE CABECERA
Trabajar con nuestro propio archivo .h 

si necesitamos por ejepmlo trabajar con muchas funciones y no tener que recorrer todo el codigo buscandola para modificarla o analizarla creamos un archivo .c donde se van a guardar las estructuras y funciones que voy a utilizar en el archivo main

* Paso las lineas de codigo a el archivo 17_ArCabeceraAr.c

una forma de llamarlo al main sería #include "17_ArCabeceraAr.c" pero lo que hace es copiar todo de 17_ArCabeceraAr al main y puede generar errores
Debemos importar una version del .c que solo contiene definiciones de estructuras y prototipos (Es una manera de anticiparle al compilador como se va a llamar uan funcion y que funciones existen en general):

se escribe la misma declaracion de la funcion pero no tiene cuerpo

- void print_empleado(Empleado* empl);
Pero para esto se crea un archivo de cabecera .h
17_ArCabeceraAr.h

si usamos los "guards" evitamos que una region de código se compile multiples veces como es el casode los .h

#include "17_ArCabeceraAr.h"
#include "17_ArCabeceraAr.h"

utilizamos #pragma once le dice al .h que resuelva una sola vez

*/
#include <stdio.h>
#include <string.h>

#include "17_ObjetoCabecera.h" // importacion del archivo cabecera

int main()
{
    // creamos y llenamos los campos del objeto "e" tipo empleado
    Empleado e;
    strncpy(e.nombre, "Pepito", 30);
    strncpy(e.apellido, "Perez", 40);
    strncpy(e.identificador, "223178", 9);
    e.cargo = ANALISTA;
    print_empleado(&e);
    return 0;
}

/*                                                  NOTA
Puede que el compilador no reconozca la ejecucion por sepaado de ambos arvhcios. 
Para esto desplegamos la consola y en la carpeta usamos los comandos 

gcc 17_ObjetoCabeceraMain.c 17_ObjetoCabeceraFun.c -o ObjetoMain (para ejecutar ambos archivos en uno solo) 

./ObjetoMain (para ejecutar dicho archivo (si ya existe solo ejecutar)) 
*/ 