
// Aqui se incluyen los procesos de las funciones

#include <stdio.h>
#include "17_ObjetoCabecera.h" // inclusion de la cabecera

void print_empleado(Empleado* empl){
    char* cargo;

    printf("---Empleado---\n");
    printf("|    Nombre: %-40s  |\n",  empl->nombre);
    printf("|  Apellido: %-40s  |\n",  empl->apellido);
    printf("|       PID: %-40s  |\n", empl->identificador);
    
    // switch case para el enum de empleado
    switch (empl->cargo){
        case ANALISTA: cargo = "Analista"; break;
        case SISTEMAS: cargo = "Sistemas"; break;
        case DESARROLLO: cargo = "Desarrollo"; break;
    }
    printf("      Cargo: %-40s |\n", cargo);
    printf("-----------------------------------------\n");
}
