#include <stdio.h>
#include <string.h> // esta cabecera nos sirve para asignar texto ya que C lo entiende como array 


enum tipo_empleado { // el tipo enum nos permite declarar una lista de valores posibles para un atributo
    Analista, 
    programador}; 

struct cuenta{ // definidmos la estructura cuenta 
    char nombre[30];
    char apellido[40];
    int identificador;
    int saldo;
    enum tipo_empleado tipo; // el enum dentro de una estructura se debe declarar asi
};

void imprimir(struct cuenta *micuenta){ // creamos la funcion de imprimir pasando el objeto cuenta como puntero (*cuenta)
    printf("El cliente %s %s tiene %i euros en la cuenta. \n",
    micuenta->nombre , micuenta->apellido , micuenta->saldo); // sintaxis para mostrar cosas (en vez de cuenta.nombre cuenta->nombre)

    if (micuenta->tipo == Analista){ // el enum nos permite filtrar segun una categoria concreta
        printf("el clinete es de tipo analista\n");

    }else{
        printf("el cliente es no es analista\n");
    }
    
}


int main()
{
    struct cuenta c1; // podemos asignar valores dentro de la main creando un objeto 
    c1.identificador = 1234;
    strcpy(c1.nombre , "jann");
    strcpy(c1.apellido, "lopez");
    c1.saldo = 100; 
    c1.tipo = Analista; // el enum puede ser declarado de esta forma


    imprimir(&c1); //aplicamos la funcion imprimir con el puntero de c1 como argumento "&c1"


    // borro el archivo del compilador
    int borrado1 = remove("7- Puntero");


    return 0;
}

