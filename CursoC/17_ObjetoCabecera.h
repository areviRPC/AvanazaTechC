

/* 
17_ArCabeceraAr.h

- Aqui se incluyen los prototipos de las funciones y las estructuras
- si usamos los "guards" evitamos que una region de código se compile multiples veces como es el casode los .h
*/

#pragma once

// definicion del tipo enum dentro del objeto
typedef enum cargo_t {
    ANALISTA, DESARROLLO, SISTEMAS
} Cargo;

// definicion del objeto empleado_t (se nombra _t para mencionar que es prototipo)
typedef struct empleado_t {
    char nombre[30];
    char apellido[40];
    char identificador[9];
    Cargo cargo;
} Empleado;

// prototipo de la funcion "print_empleado" cuya funcion se define en las funciones
void print_empleado(Empleado* empl);