#include <stdio.h>
#include "18_BasicoCabeceras.h" // uso del archivo cabeceras



// declaracion de fuciones (no se declara PI sino en la cabecera)

int suma(int a,int b){
    return a+b;
}

int resta(int a,int b){
    return a-b;
}

char primer_caracter(char* cadena){
    return cadena[0];
}

double area_circulo(int radio){
    return PI *radio*radio;
}