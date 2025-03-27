#include "Matrix.h"
#include "vector.h"
#include <time.h>


int main()
{
    srand(time(NULL));
    Matrix* matriz1=matrix_new(3,3);
    matrix_add_random(matriz1);



    matrix_print(matriz1,print_int);

    vector* pepe=vector_init(3);
    vector_add_random2(pepe);

    puts("Asi se ve pepe:");
    vector_print2(pepe);
    
    matrix_change_row_with_vector(matriz1,pepe,1);

    puts("Asi quedo la nueva matriz intercambiando pepe");
    matrix_print(matriz1, print_int);

    free_matrix(matriz1);
    
    return 0;
}