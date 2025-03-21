
#include <stdio.h> 
#include <string.h>
// la libreria ctype
#include <ctype.h> 


// la funcion recibe el texto y el puntero al objeto
void LongestWord(char * sen) {
  
    // tamaño del array (unsigned long )

    size_t tamaño = strlen(sen);

    printf("La longirud de la cadena es: %zu\n", tamaño);

    // inicializamos los contadores
    int palabraMax = 0;
    int TamañoMax = 0;
    int indice = 0;

    // recorre toda la lista
    for(int i = 0; i <= tamaño ; i++){
        printf(" -%c ", sen[i]);
        
        // esto garantiza que reciba solo letras y numeros
        if ( isalnum(sen[i]) )  {
            
            // si es un caracter valido aumenta el contador
            TamañoMax = TamañoMax + 1;
        
        }else{

            // si es un espacio o un caracter no valido se reinicia el contador
            printf("omite\n");
            if (TamañoMax > palabraMax){
                palabraMax = TamañoMax;
                indice = i-TamañoMax; // se guarda el primer indice de la palabra mas larga
            }
            TamañoMax = 0;
        }
      
    }
    
    printf("indice %d\n" , indice);
    printf("la palabra mas larga mide %d, en el indice %d , inice: %c \n", palabraMax , (indice), sen[indice]);

    // creamos un ciclo que imprima la palabra mas larga iniciando en el indice donde esta
    for(int n = indice; (n-indice) < palabraMax ; n++){
        printf("%c" , sen[n]);
    }



}

// main para ejecutar la funcion 
int main(void) { 
   
    // caso de prueba
    char c[] = "s1 /jooooooooo&&& $hola";


    // borro el archivo del compilador
    int borrado1 = remove("21- prueba");

    LongestWord(c);
    return 0;
    
}