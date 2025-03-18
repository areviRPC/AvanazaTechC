
#include <stdio.h>


// definimos una estructura
struct medicion
{
    unsigned short año;
    unsigned char mes;
    unsigned char dia;
    float temperatura;
    unsigned char uv;
    unsigned char viento;
};

// funcion para imprimir los datos de una estructura con un apuntador a su espacio
void print_medicion(struct medicion *medicion){
    printf("Fecha: %d - %d - %d, Registro: %fC , UV: %d , Viento: %d Km/h: \n",
    medicion->año , medicion->mes , medicion->dia,
    medicion->temperatura , medicion->uv , medicion->viento);
}


int main()
{
    // rellenamos un objeto nuevo
    struct medicion obj_medida = {
        .año = 2020, .mes = 11 , .dia = 9,
        .temperatura = 12.5 , .uv = 4, .viento = 15.0
    };

                            // fwrite
    // fwrite nos sirve para enviar todo tipo de variables (incluso objetos) a un 
    // archivo de tipo bin que luego podremos leer

    // FILE y fopen para abrir el docuemnto con el caracter "wb"
    FILE *documento = fopen("16 - temperatura.bin" , "wb");

    // fwrite arroja un entero que es el numero de veces de la accion (1 en este caso)
    // usamos el "sizeof(structura)" para garantizar que haya espacio suficiente
    // fwrite(objeto , tamaño del objeto , numero de veces a enviar, a dodne se va a enviar)
    int total = fwrite(&obj_medida , sizeof(struct medicion), 1 , documento);
    if (total != 1){
        printf("Error de escritura");
    }



    printf("objeto original \n");
    print_medicion(&obj_medida);

    return 0;
}
