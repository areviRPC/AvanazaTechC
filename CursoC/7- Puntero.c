#include <stdio.h>
#include <string.h> 
// esta cabecera nos sirve para asignar texto ya que C lo entiende como array 

// el tipo enum nos permite declarar una lista de valores posibles para un atributo

enum tipo_empleado {
    Analista,  
    programador}; 

struct cuenta{ // definidmos la estructura cuenta 
    char nombre[30];
    char apellido[40];
    int identificador;
    int saldo;
    enum tipo_empleado tipo; 
    // el enum dentro de una estructura se debe declarar asi
};

// creamos la funcion de imprimir pasando el objeto cuenta como puntero (*cuenta)
void imprimir(struct cuenta *micuenta){ 
    printf("El cliente %s %s tiene %i euros en la cuenta. \n",
    micuenta->nombre , micuenta->apellido , micuenta->saldo); 
    // sintaxis para mostrar cosas (en vez de cuenta.nombre cuenta->nombre)

    // el enum nos permite filtrar segun una categoria concreta
    if (micuenta->tipo == Analista){ 
        printf("el clinete es de tipo analista\n");

    }else{
        printf("el cliente es no es analista\n");
    }
    
}


int main()
{
    // podemos asignar valores dentro de la main creando un objeto 
    struct cuenta c1; 
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

