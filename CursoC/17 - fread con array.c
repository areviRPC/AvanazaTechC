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

// definimos una estructura para array
struct arrayStruct
{
    char nombre[30];
    int notas;
    float altura;
};

// funcion para imprimir los datos de una estructura con un apuntador a su espacio
void print_medicion(struct medicion *medicion){
    printf("Fecha: %d - %d - %d, Registro: %fC , UV: %d , Viento: %d Km/h: \n",
    medicion->año , medicion->mes , medicion->dia,
    medicion->temperatura , medicion->uv , medicion->viento);
}

// funcoin para imprimir array 
// (tipo de dato - dato - apuntador)
void print_array(struct arrayStruct *arrayStruct){
    printf("nombre: %s , notas: %i , altura: %.2f \n",
    arrayStruct->nombre ,arrayStruct->notas , arrayStruct->altura);
}


int main()
{
                                        // fread
    // nos sirve para recuperar informacion de un archivo binario e insertarlo en donde digamos

    // creamos un objeto vacio el cual vamos a llenar con el fread


                                        // objeto individual
    struct medicion toread;            

    // usamos fopen para acceder al archivo donde queremos recuperar los datos
    // importante que el archivo si exista y tener la estructura "rb"                        
    FILE *docread = fopen("16 - temperatura.bin" , "rb");
    
    // vemos el que objeto se imprime con datos aleatorios
    printf("objeto sin iniciar \n");
    print_medicion(&toread);

    // tiene la misma estrcutrua que fwrite (objeto , tamaño del objeto , numero de veces a leer, de donde se va a leer)
    int numero_read = fread(&toread , sizeof(struct medicion), 1 , docread);

    if(numero_read != 1){
        // si falla
        printf("Hemos tenido un problema \n");
    }

                                        // fread con array

    // creamos una lista de objetos vacia
    struct arrayStruct nombres[5];

    // usamos FILE y fopen para elegir el archivo que vamos a leer (con "rb")
    FILE *docArray = fopen("16 - listaobjetos.bin" , "rb");

    // imprimimos el primer objeto (se llena mal)
    printf("objeto array sin vacio: \n");
    print_array(&nombres[0]);

    // usamos fread para llenar los datos (5 veces)
    //(objeto a llenar - tamaño(y tipo) - numero de veces , documento elegido)
    int numArray = fread(&nombres , sizeof(struct arrayStruct), 5 , docArray);
    if(numArray != 5){
        // se debe hacer exactamente 5 veces
        printf("erorr en la lectura de la lista \n");
    }

    // ciclo para imprimir el array
    printf("impresion de la lista de nombres: \n");
    for(int i = 0; i<5 ; i++){
        printf("objeto %i : \n" , i+1);
        print_array(&nombres[i]);
    }

    // imprimimos el objeto unitario con la informaicon correcta
    printf("objeto lleno: \n");
    print_medicion(&toread);

    // cierre de conexion
    fclose(docread);
    fclose(docArray);

                            // Borrado de archivos 

    printf("borrado de archivos");

    // usamos remove para borrar archivos. da como retorno un entero = 0
    int borrado1 = remove("16 - listaobjetos.bin");
    int borrado2 = remove("16 - temperatura.bin");

    if(borrado1 && borrado2 != 0){
        printf("archivos no borrados");
    }

    return 0;
}