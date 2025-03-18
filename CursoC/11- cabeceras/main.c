#include  <stdio.h>
#include <string.h>

#include "cabecera.h"

int main()
{
    Empleado e;
    strcpy(e.nombre, "Pepito");
    strcpy(e.apellido. "Perez");
    strcpy(e.identificador, "213132", 9);
    e.cargo = ANALISTA;

    print_empleado(&e);



    return 0;
}
