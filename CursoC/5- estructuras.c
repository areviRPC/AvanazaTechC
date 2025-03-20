#include <stdio.h> 

                        // debemos declarar las estructuras al inicio del programa

struct perro // se declara cada atributo con su tipo de dato en orden
{
    char nombre[30];
    int edadMeses;
    float peso;
} // se pueden crear objetos de esta forma debajo de la declaracion de la estructura
perro1 = {"chicorita",10,3.50}, 
perro2 = {"Caiser",5,6.50};

struct cat 
{
    char name[30];
    int edad;
} // Tambien podemos declarar varios objetos como una lista. Esta no puede estar vacia
cats[2],
gato1 = {"ana",5}; // se pueden combinar ambas maneras 



int main()
{
    // podemos leer los objetos creados accediendo directamente a ellos
    printf("Ep peso de %s es: %.2f kg y tiene %i meses\n" , perro2.nombre , perro2.peso , perro2.edadMeses);
    
    for(int i = 0; i<2 ; i++){ // creamos un ciclo para rellenar los datos de los gatos
        printf("ingrese el nombre de un gato: ");
        scanf("%s", cats[i].name); // sintaxis de asignacion 
        printf("ingrese la edad del gato: ");
        scanf("%i", &cats[i].edad);
    }

    // al final es posible leer estos datos accediendo a su indice de la lista que declaramos al inicio
    printf("el nombre del gato 1 es: %s y su edad es %i \n", cats[0].name , cats[0].edad); 
    // o si es el caso accediendo diretamente a ellos 
    printf("el nombre del gato 3 es: %s y su edad es %i \n", gato1.name , gato1.edad); 

    // borro el archivo del compilador
    int borrado1 = remove("5- estructuras");

    return 0;
}
