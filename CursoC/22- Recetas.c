#include <stdio.h>






int main(int argc, char const *argv[])
{
    // lista de recetas
    char* recipes[] = {"bread","sandwich"};
    int recipesSize = sizeof(recipes)/sizeof(recipes[0]);


    // lista de ingredientes
    char* ingredients[] = {{"yeast","flour"},{"bread","meat"}};
    int ingredientsSize =  (sizeof(ingredients)/(sizeof(ingredients[0][0]) * sizeof(ingredients[0])) );
    ;
    // tamaño de los subelementos
    int* ingredientsColSize;

    // lista de suministros
    char* supplies[] = {"yeast","flour","meat"};
    int suppliesSize = (sizeof(supplies)/sizeof(supplies[0]));

    // tamaño de la lista de creaciones posibles 
    int* returnSize;

    printf("tamaño recetas: %d ingredientes: %d, elementos: %d \n", recipesSize , ingredientsSize , suppliesSize);


    return 0;
}
