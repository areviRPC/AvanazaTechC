#include  <stdio.h>
#include <string.h>

#include "cabecera.h"

void print_empleado(Empleado* empl){

    char* cargo;
    printf("-----------------------------")
    printf("Nombre %-40s\n" , empl->nombre );
    printf("apellido %-40s\n" , empl->apellido );
    printf("id %-40s\n" , empl->identificador );


    
}