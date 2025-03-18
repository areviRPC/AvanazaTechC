#include <stdio.h>
/* si escribo  #include "nombre del archivo" el include va a vuscar el archivo en la carpeta */
#define PI 3.1427
/* podemos definir constantes con #define */ 
#define CUBO(x) x*x*x 
/* tambien podemos definir funciones pequeñas dentro de las constantes */


int main(){
   printf("holaaaaa\n");

   /* printf para imprimir en pantalla */
   printf("inicio del programa\n");

   /* creacion de tipo de variable */

   int num1;  
   int num2;
   int resultado; 

   /* scanf para ingresar datos por tecaldo (tiene dos argumentos) */
   /* %d para indicar que debe ser un entero decimal */
   /* &num1 para indicar a cual variable se le asigna el valor*/
   
   printf("ingresa el primer valor \n");
   scanf("%d",&num1); 

   printf("ingresa el segundo valor \n");
   scanf("%d",&num2);

   resultado = num1 + num2;

   /* todas las operaciones matematicas funcionan igual */

   /* %d para que imprima decimales */

   printf("el resultado de la suma es: %d\n",resultado);

   /* if , else if y else para condicionales */

   if(num1 < num2)
   {
      printf("el numero 2 es mayor\n");
   }
   else if(num2 < num1)
   {
      printf("el numero 1 es mayor\n");
   }else{
      printf("los numeros son iguales");
   }

   /* %i para imprimir enteros*/
   /* las constantes definidas el inicio pueden ser definidas y usadas dentro del codigo*/

   int numero = 8;
   int suma;
   suma = PI + numero;
   printf("la suma de 8 y PI es: %i\n",suma);
   printf("el cubo del numero 8 es : %i\n",CUBO(numero));

   /* tipos de datos */
   /* char para declarar variables de texto (se imprime con %c)*/

   char C = 'de tipo numerico'; /*texto*/
   short e = -1; /*negativos*/
   unsigned int u = 25; /* positivos */
   long l = 5932; /* datos grandes (se imrpimen como %li)*/
   float f = 72.534; /* datos decimales /se imprimen com %f*/
   float m = 30.55; /* se dedondea con %.2f si queremos 2 cifras etc */
   double d = 121212.221; /* numeros flotantes muy grandes se imprime con %lf o %.2lf para redondear*/

   printf("variable C: %c\n",C);


   return 0;
}

