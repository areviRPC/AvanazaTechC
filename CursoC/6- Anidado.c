#include <stdio.h>
#define lengt 2 // definimos una constante afuera que definira el numero de perros y dueños

struct owner // definimos la estructura de los dueños (vemos que no hay ninguno)
{
    char nombre[20];
    char direccoion[20];
};

struct dog // definimos los perros
{
    char name[20];
    int edadMeses;
    struct owner ownerDog; // los dueños son un atributo mas de los perros y ahi se llenan
}dogos[lengt], // declaramos una lista de perros definida por nuestra constante
peluchin = {"jose", 35 , {"anibal" , "calle 65"} }; 
// podemos rellenar los atributos del un perro y su dueño como un solo objeto, 
// respetando el orden. (cuidado con la declaracion)



int main()
{
    // asi podemos imprimir un objeto que ya existe fuera de la lista
    printf("el nombre es %s y el nombre del dueño es %s \n" , peluchin.name , peluchin.ownerDog.nombre); 

    for(int i = 0;i< lengt ; ++i){ // ciclo definido por la constante
        // accedemos a cada indice de los perros y asignamos valores
        printf("nombre del perro: \n");
        scanf("%s",dogos[i].name); 
        printf("edad del perro en meses: \n");
        scanf("%i",&dogos[i].edadMeses);
        printf("Nombre del dueño: \n");
        scanf("%s",dogos[i].ownerDog.nombre); // como el dueño es un atributo mas podemos asignarlo como tal
        printf("direccion: \n");
        scanf("%s",dogos[i].ownerDog.direccoion);
        printf("\n");
    }

    for(int i = 0;i< lengt ; ++i){ // ciclo para leer los perros
        // accedemos a todos los atributos del perro y del dueño mediante indices
        printf("nombre del perro: %s\n" , dogos[i].name);
        printf("edad del perro en meses: %i\n", dogos[i].edadMeses);
        printf("Nombre del dueño: %s\n" , dogos[i].ownerDog.nombre);
        printf("direccion: %s\n" , dogos[i].ownerDog.direccoion);
        printf("\n");
    }

    // borro el archivo del compilador
    int borrado1 = remove("6- Anidado");


    return 0;
}
