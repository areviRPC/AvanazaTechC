#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1 Ordenamiento burburja
void burbuja(int arreglo[],int tamano);
// 2 ordenamiento de menor a mayor
void seleccion(int arreglo[], int tamano);
// 3 NN
int ordenarQsort(const void *a,const void *b);
// 4 Busqueda lineal, retorna el indice 
int busquedaLineal(int arrreglo[], int tamano, int valor);
// 5 Busca un valor tomando los extremos 
int busquedaBinaria(int arreglo[], int tamano, int valor);
// 6 asigna memoria, copia un arreglo y retorna un nuevo arreglo
int* copiarArreglo(int arreglo[], int tamano);
// 7 busca el valor maximo de un arreglo
int max(int arreglo[],int tamano);
// 8 busca el valor minimo de un arreglo
int min(int arreglo[],int tamano);
// 9 elimina un elemento de la lista y reasigna tamaño
int eliminarElemento(int arr[], int *tamano, int indice);
// 10 corta un array como lista de caracteres
// retorna una lista de char
char **split(char *str, char delimiter, int *token_count);
// 11 imprimme la palabara mas larga
void LongestWord(char * sen);//iMPRIME PALABRA MAS GRANDE
// 12 suma todos los elementos de un arrelgo
int sumaArreglo(int arr[], int tamano);
void imprimirArreglo(int arr[], int size);
// 13 invierte un arreglo con un recopiente temporal
void invertirArreglo(int arr[], int tamano);


int main(){
    int arrOriginal[]={11,8,-2,0,-1,1,5};
    int segundo[]={9,8,7,6,5,4};
    int tamano= sizeof(arrOriginal)/sizeof(arrOriginal[0]);
    int valor=11;
    int* copiaDeArreglo=copiarArreglo(arrOriginal,tamano);
    //burbuja(arrOriginal,tamano);
    printf("Array original: ");
    imprimirArreglo(arrOriginal,tamano);
    qsort(arrOriginal,tamano,sizeof(arrOriginal[0]),ordenarQsort);
    printf("\nArray ordenado: ");
    imprimirArreglo(arrOriginal,tamano);
    int maximo=max(arrOriginal,tamano);
    printf("\nElemento mayor: %d",maximo);
    int minimo=min(arrOriginal,tamano);
    printf("\nElemento menor: %d",minimo);
    printf("\nCopia con valor eliminado: ");
    int dato=eliminarElemento(copiaDeArreglo,&tamano,0); //&tamano modifica la variable original
    imprimirArreglo(copiaDeArreglo,tamano);
    //int tamanomodificado= sizeof(copiaDeArreglo)/sizeof(copiaDeArreglo[0]);
    printf("\nTamano modificado: %d\n",tamano);
    printf("Valor eliminado: %d\n",dato);
    printf("Suma de los elementos del arreglo modificado: %d\n", sumaArreglo(copiaDeArreglo,tamano));
    printf("Invertir Arreglo modificado: ");
    invertirArreglo(copiaDeArreglo,tamano);
    imprimirArreglo(copiaDeArreglo,tamano);
    printf("\n");
    invertirArreglo(segundo,6);
    imprimirArreglo(segundo,6);
    //int indice=busquedaLineal(arrOriginal, tamano,valor);
    //int indice=busquedaBinaria(arrOriginal, tamano,valor);
    //printf("\nEl elemento %d esta en el indice %d de la lista\n",valor,indice);
    return 0;
}


// 1 ordena los elementos de una lista
void burbuja(int arreglo[],int tamano){
    for (int i = 0; i < tamano-1; i++)
    {
        //-i para no comparar elementos ya ordenados, 
        // -1 para no salirse del limite del array
        for (int j = 0; j < tamano-i-1; j++) 
        {
            if (arreglo[j]>arreglo[j+1]){
                int temp=arreglo[j+1];
                arreglo[j+1]=arreglo[j];
                arreglo[j]=temp;
            }
        }    
    }
}

// 2 ordena de menor a mayor con el indice minimo
void seleccion(int arreglo[], int tamano){
    for (int i = 0; i < tamano-1; i++)
    {
        int indiceMinimo=i;
        for (int j = i+1; j < tamano; j++)
        {
            if(arreglo[j] < arreglo[indiceMinimo])
            {
                indiceMinimo=j;
            }
        }
        if(indiceMinimo!=i){
            int temp=arreglo[i];
            arreglo[i]=arreglo[indiceMinimo];
            arreglo[indiceMinimo]=temp;
        }   
    }
}

// nn
int ordenarQsort(const void *a,const void *b){
    //int *valA=a;
    //int *valB=b;
    //return *valA - *valB;
    return (*(int*)a - *(int*)b); //otra opcion
}

// 4 realiza busqueda retornando el indice 
int busquedaLineal(int arrreglo[], int tamano, int valor){
    for (int i = 0; i < tamano; i++)
    {
        if (arrreglo[i]==valor)
        {
            return i;
        }
    }
    return -1;
}

// 5 busca un elemento comparando los extremos 
int busquedaBinaria(int arreglo[], int tamano, int valor){
    int izquierda=0;
    int derecha=tamano-1;

    while (izquierda<=derecha)
    {
        int pivote=izquierda+(derecha-izquierda)/2;
        if (arreglo[pivote]==valor)
        {
            return pivote;
        }
        if (valor<arreglo[pivote])
        {
            derecha=pivote-1;
        }
        else{
            izquierda=pivote+1;
        }
    }
    return -1;
}

// 6 copia un arreglo y retorna un nuevo arreglo
int* copiarArreglo(int arreglo[], int tamano){
    // uso de malloc
    int *copia=(int*)malloc(tamano*sizeof(int));
    if (copia==NULL)
    {
        printf("No se pudo asignar memoria.\n");
        return NULL;
    }
    for (int i = 0; i < tamano; i++)
    {
        copia[i]=arreglo[i];
    }
    return copia;
}

// 7 busca el valor maximo de un arreglo
int max(int arreglo[],int tamano){
    int valorMax=arreglo[0];
    for (int i = 0; i < tamano; i++)
    {
        if (arreglo[i]>valorMax)
        {
            valorMax=arreglo[i];
        }
    }
    return valorMax;
}

// 8 busca el valor minimo de un arreglo
int min(int arreglo[],int tamano){
    int valorMin=arreglo[0];
    for (int i = 0; i < tamano; i++)
    {
        if (arreglo[i]<valorMin)
        {
            valorMin=arreglo[i];
        }
    }
    return valorMin;
}

// 9 elimina el elemento seleccionado y reduce el tamaño de la lista
int eliminarElemento(int arr[], int *tamano, int indice) {
    if (indice < 0 || indice >= *tamano) {
        printf("Índice fuera de rango.\n");
        return -1;
    }
    int eliminado=arr[indice];
    for (int i = indice; i < *tamano - 1; i++) {
        arr[i] = arr[i + 1]; // Desplazar elementos hacia la izquierda
    }
    (*tamano)--; // Reducir el tamaño lógico del arreglo
    return eliminado;

    //Warning: Esta funcion modifica la variable tamano
}

// 10 corta un string como lista de caracteres
// devuelve una lista de char
char **split(char *str, char delimiter, int *token_count) {
    char **tokens = NULL;
    int count = 0;
    char *token = strtok(str, &delimiter);
    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char *) * (count + 1));
        if (tokens == NULL) {
            // Manejo de error si falla la asignación de memoria
            fprintf(stderr, "Error: No se pudo asignar memoria\n");
            exit(EXIT_FAILURE);
        }
        // Duplicar la cadena para evitar problemas de memoria
        tokens[count] = strdup(token); 
        count++;
        token = strtok(NULL, &delimiter);
    }
    *token_count = count;
    return tokens;
}

// 11 devuelve el tamaño de la palabra mas larga
void LongestWord(char * sen){
    int tamaño = strlen(sen);
    int largo = 0;
    int largom = 0;
    int indicef = 0;
    for (int i = 0; i <= tamaño; i++){
        // printf("%c", sen[i]);
        if(sen[i]==' ' || sen[i]=='\0' || !isalnum(sen[i])){
            // printf(" space ");
            if (largo > largom){
                largom = largo;
                indicef = i;}
            largo = 0;
        } else {
            largo++;
        }
    }
    //printf("La palabra más larga está antes del índice: %i\n", indicef);
    //printf("La palabra más larga es:\n");
    for (int i = (indicef-largom); i < indicef; i++){
        printf("%c", sen[i]);
    }
    printf("\n");
}

// 12 suma todos los elementos de un arreglo
int sumaArreglo(int arr[], int tamano){
    int resultado=0;
    for (int i = 0; i < tamano; i++)
    {
        resultado+=arr[i];
    }
    return resultado;
}

// 13 usa un recipiente temporal para invertir el arreglo
void invertirArreglo(int arr[], int tamano) {
    int inicio = 0;
    int fin = tamano - 1;
    int temp;

    while (inicio < fin) {
        // Intercambiar elementos
        temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;

        // Mover los índices hacia el centro
        inicio++;
        fin--;
    }
}

void imprimirArreglo(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    //printf("\n");
}
