#include <stdio.h>

// dado una lista de binarios queremos saber cuantas 
// veces debo invertir el valor de grupos de 3 para que todos sean 1.
// si es imposible decirlo tambien

int main()
{
    //  declaramos una lista (no necesariamente el tamaño)
    int lista[] = {0,1,0,0,1,1};

    // tamaño de la lista
    int n = (sizeof(lista)/sizeof(lista[0]));

    // contador de repeticiones
    int repeticiones = 0;

    // recorro toda la lista sin salirme del tamaño i<(n-2)
    for (int i = 0; i < (n-2); i++){
        
        // si me encuentro un 0 debo invertir esa posicion y las 2 siguientes
        if(lista[i] == 0){
            for(int j = 0; j < 3; j++){

                // la operacion XOR reemplaza cada indice con su contrario 
                // XOR retorna 1 si y solo si unicamente uno de 
                // los dos es 1, de lo contrario retorna 0  
                lista[i + j] = lista[i + j] ^ 1;
            }
                     
            repeticiones = repeticiones + 1;
            
            // imprimo la lista en cada repeticion
            for (int i = 0; i < n; i++) {
                printf("- %d ", lista[i]);
            }
            printf("\n");
        }
    }

    // Si alguna de las ultimas dos posiciones es 0 es imposible 
    if (lista[n-2] == 0 || lista[n-1] == 0){
        printf("es imposible \n");
    }else{
        printf("cambio exitoso \n");
    } 
    // borro el archivo del compilador
    int borrado1 = remove("19- ejercico binarios");

    return printf("el numero de operaciones fue %d\n", repeticiones);

}
