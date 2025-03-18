#include <stdio.h>
// EOF pertenece a la libreria stdio.h , es una constante especial que puede ser usada

int main()
{
                                    // lectura inicial del archivo 

     // conectamos el tipo de archivo FILE con el puntero que apuntara al archivo en cuestion
     // fopen nos permite seleccionar nuestro archivo y dar el parametro "r" para leer, "w" para escribir etc (consultar)
     // llamamos a *prueba  DESCRIPTOR 
    FILE *prueba = fopen("prueba.txt" , "r");
    if(!prueba){ // si el puntero no almaceno nada
        printf("no he podido encontrar el archivo\n");
        return 1;
    }

                                    // ftell para señalar el cursor
    long pos = ftell(prueba);
    printf("el cursor inicia en %ld\n" , pos);

                                    // fget para recorrer el archivo

    // La funcion fgetc ubica el cursor(el mouse) en cada caracter del archivo, por eso lo leemos con un while
    do{ 
        // fgetc devuelve un char pero se almacena como un entero para evitar errores de memoria
        // aplicamos fgetc al puntero
        int leido = fgetc(prueba); 

        // feof(prueba) es igual a leido == EOF | que es cuando el cursor llega al ultimo caracer del archivo
        if ((!feof(prueba)) && (leido != EOF)){ 

            // imprimimos lo leido por la funcon fgetc
            printf("%c", (char) leido); 
            pos = ftell(prueba);

            
        }else{
            printf("\n === FIN === \n");
            printf("el cursor termina en %ld\n" , pos);
        }
        
        
    }while (!feof(prueba)); 

                                // fseek y fteell

    // con fseek podemos mover el cursor (SEEK_END para final , SEEK_SET al inicio etc)
    fseek(prueba, 0 , SEEK_END);
    // guardamos la posicion del cursor en una variable
    long tamaño = ftell(prueba);
    // enviarmos al cursor al principio
    rewind(prueba);

    // imprimimos el valor final del cursor 
    printf("el tamaño del archivo es %ld caracteres \n", tamaño);

                            // fgets para leer archivo por renglones

    char buffer[80];



    do{
        if(fgets(buffer,80,prueba)){
                printf("resnglon: %s\n", buffer);
        }
    }while (!feof(prueba));


                                // fclose para cierre del archivo

    fclose(prueba);  
    
}
