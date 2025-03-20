#include <stdio.h>

int main()
{
    // las operaciones con binario se definen por el tipo "unsigned char" en 8 bits
    unsigned char a = 185, b = 52;

    // debo poner tambien unsigned char en la impresion y %u en el texto
    printf("a = %u\n", (unsigned char) a); 

    // si imprimo solo "(char) a" se expresa en otra base (lo mismo si pongo %i)
    printf("a = %u\n", (char) a); 

    // invierte todos los bits de "a"
    printf("a complemento = %u\n", (unsigned char) ~a); 

    printf("b = %u\n", (unsigned char) b);
    
    // AND que asigna 1 si ambos numeros son 1 y de lo contrario 0
    printf("a AND b = %u\n", (unsigned char) (a & b));
    
    // OR si alguno de los dos es 1
    printf("a OR b %u\n", (unsigned char) (a | b));
    
    // XOR que asigna 1 si y solo si uno de los dos es 1 
    printf("a XOR b = %u\n", (unsigned char) (a ^ b)); 

    // borro el archivo del compilador
    int borrado1 = remove("12- binarios");

    return 0;
}
