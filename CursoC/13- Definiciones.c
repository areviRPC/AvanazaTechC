#include <stdio.h>
#define AZUL 1 << 7
#define VERDE 1 << 6
#define ROJO 1 << 5
#define NARANJA 1 << 4
#define AMARILLO 1 << 3
#define PARDO 1 << 2
#define BLANCO 1 << 1
#define NEGRO 1 << 0 

void operacion (unsigned char colores){

    if (colores & AZUL){
        printf("AZUL\n");
    }
    if (colores & VERDE){
        printf("VERED\n");
    }
    if (colores & ROJO){
        printf("ROJO\n");
    }
    if (colores & NARANJA){
        printf("NARANAJA\n");
    }
    if (colores & AMARILLO){
        printf("AMARILLO\n");
    }
    if (colores & PARDO){
        printf("PARDO\n");
    }
    if (colores & BLANCO){
        printf("BLANCO\n");
    }
    if (colores & NEGRO){
        printf("NEGRO\n");
    }
}

void menos_verde (unsigned char colores){
    colores = colores & ~(VERDE);
    printf("sin el verde %u\n" , colores);
    operacion(colores); 
}

int main()
{
    operacion(AZUL | VERDE | PARDO);
    return 0;

    // borro el archivo del compilador
    int borrado1 = remove("13- Definiciones");

}


