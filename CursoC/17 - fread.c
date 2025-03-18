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
                                        // fread
    // nos sirve para recuperar informacion de un archivo binario e insertarlo en donde digamos

    // creamos un objeto vacio el cual vamos a llenar con el read
    struct medicion toread;

    // usamos fopen para acceder al archivo donde queremos recuperar los datos
    // importante que el archivo si exista y tener la estructura "rb"                        
    FILE *docread = fopen("16 - temperatura.bin" , "rb");
    
    // vemos el que objeto se imprime con datos aleatorios
    printf("objeto sin iniciar \n");
    print_medicion(&toread);

    // tiene la misma estrcutrua que fwrite (objeto , tamaño del objeto , numero de veces a enviar, a dodne se va a enviar)
    int numero_read = fread(&toread , sizeof(struct medicion), 1 , docread);

    if(numero_read != 1){
        // si falla
        printf("Hemos tenido un problema \n");
    }

    // imprimimos el objeto con la informaicon correcta
    printf("objeto lleno \n");
    print_medicion(&toread);

    // cierre de conexion
    fclose(docread);

    return 0;
}