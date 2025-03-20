#include <stdio.h>

int main()
{
    // abrimos los archivos con fopen y el caracter "w" para escribir
    FILE *archivo_escribir = fopen("15 -esritura.txt" , "w");
    if(!archivo_escribir){ // si el puntero no almaceno nada
        printf("no he podido encontrar el archivo\n");
        return 1;
    }

    FILE *archivo_frase = fopen("15 -frase.txt" , "w");
    if(!archivo_frase){ // si el puntero no almaceno nada
        printf("no he podido encontrar el archivo\n");
        return 1;
    }
    
                    // futc para letras 

    // inicializamos un entero con fputc para poner nuestra letra
    int palabra = fputc('h',archivo_escribir);

    if (palabra == EOF){ // si sale mal
        printf("la letra no se escribio");

    }else{
        printf("se escribio  %c\n" , palabra);
    }

                    // fputs para palabras 

    // inicializamos un entero con fputs para poner nuestra frase
    int frase = fputs("un texto mas largo",archivo_frase);

    if (frase == EOF){ // si sale mal
        printf("la letra no se escribio");

    }else{
        printf("se escribio la frase  %c\n" , frase);
    }
    

                        // cerramos la conextion con ambos archivos
    fclose(archivo_escribir);
    fclose(archivo_frase);
    // notaremos que aunque borremos los archivos estos se crean autormaicamente

    // borro el archivo del compilador
    int borrado1 = remove("15 - escribir");
}
