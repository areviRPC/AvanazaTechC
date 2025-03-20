
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

// definimos una estructura para el array
struct arrayStruc
{
    char nombre[30];
    int notas;
    float altura;
};


// funcion para imprimir los datos de la  estructura con un apuntador a su espacio
void print_medicion(struct medicion *medicion){
    printf("Fecha: %d - %d - %d, Registro: %fC , UV: %d , Viento: %d Km/h: \n",
    medicion->año , medicion->mes , medicion->dia,
    medicion->temperatura , medicion->uv , medicion->viento);
}

// funcoin para imprimir array 
// (tipo de dato - dato - apuntador)
void print_array(struct arrayStruc *arrayStruc){
    printf("nombre: %s , notas: %i , altura: %.2f \n",
    arrayStruc->nombre ,arrayStruc->notas , arrayStruc->altura);
}



int main()
{
    // rellenamos un objeto nuevo
    struct medicion obj_medida = {
        .año = 2020, .mes = 11 , .dia = 9,
        .temperatura = 12.5 , .uv = 4, .viento = 15.0
    };

    // rellenamos una lista de objetos
    struct arrayStruc listaObj[] = {
        {
             .nombre = "jose",
             .notas = 4,
             .altura = 1.3
        },
        {
            .nombre = "ana",
            .notas = 5,
            .altura = 1.5
        },
        {
            .nombre = "joel",
            .notas = 6,
            .altura = 1.3
        },
        {
            .nombre = "juan",
            .notas = 7,
            .altura = 1.6
       
        },
        {
            .nombre = "ximena",
            .notas = 8,
            .altura = 1.7
        },    
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
        printf("Error de escritura unica\n");
    }

    // fopen para con el indicativo "wb" para crear un documento
    // fwrite para enviar la lista de objetos al archivo (el numero es 5)
    FILE *doclista = fopen("16 - listaobjetos.bin" ,  "wb");
    
    int total_lista = fwrite(&listaObj , sizeof(struct arrayStruc), 5 , doclista);
    if (total_lista != 5){
        printf("Error de escritura array \n");
    }

    // imprimimos el objeto
    printf("objeto original: \n");
    print_medicion(&obj_medida);

    // imprimimos el array (por el momento con un indice)
    printf("prueba del array: \n");
    print_array(&listaObj[2]);

    int borrado3 = remove("16 - fwrite y array");


    return 0;
}
