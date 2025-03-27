#include <stdio.h>
#include <stdlib.h>

// podemos definir estructuras que van enlazadas una con otra 

// definimos una estrcutrua de tipo NODO que funciona como un objeto
typedef struct Nodo{
    int valor;
    int peso;
    struct Nodo *siguiente; // uno de sus atributos sera otro objeto del mismo tipo 
}Nodo; //declaramos minimo un objeto

int main(){
    
    Nodo cabeza; // definimos dos objetos de tipo nodo
    Nodo segundo;
    Nodo tercero;

    // llenamos sus atributos
    cabeza.valor = 13;
    cabeza.peso = 23;
    cabeza.siguiente = &segundo; 
    // el ultimo atributo apunta al espacio de memoria del siguiente nodo

    // llenamos el segundo nodo
    segundo.valor = 2;
    segundo.peso = 22;
    segundo.siguiente = &tercero; 
    // el ultimo atributo apunta al siguiente nodo 

    // llenamos el tercer nodo
    tercero.valor = 0;
    tercero.peso = 0;
    tercero.siguiente = NULL; 
    // el ultimo atributo es NUll por lo que es el final de nuestra fila de nodos

    // definimos un iterador de tipo NODO. Este apunta al primer nodo de nuestra fila 
    Nodo *iterador = &cabeza; 

    // recorremos todos los nodos con un ciclo
    while (iterador) // como el iterador empieza con todos sus valores llenos va a leer cada atributo
    {
        printf("valor: %d\n", iterador->valor);
        printf("peso: %d\n", iterador->peso);
        iterador = iterador->siguiente; 
        // convertimos al iterador en el "siguiente" nodo que esta guardado en el ultimo atributo del objeto
        printf("siguiente nodo \n");
    }
    // borro el archivo del compilador
    int borrado1 = remove("10- nodos");

    return 0;
}
