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

//    matrix_change_row_with_vector(matriz1,pepe,1);
    matrix_change_col_with_vector(matriz1,pepe,0);

    puts("Asi quedo la nueva matriz intercambiando pepe");
    matrix_print(matriz1, print_int);

    Matrix* matriz2=matrix_new(3,3);
    matrix_add_random(matriz2);
    puts("Matriz2:");
    matrix_print(matriz2, print_int);

    Matrix* pepito=matrix_sum(matriz1,matriz2);
    puts("Asi queda pepito:");
    matrix_print(pepito,print_int);


    vector* vectorsin=vector_init(3);
    vector_add_random2(vectorsin);
    puts("Asi queda vectorsin:");
    vector_print2(vectorsin);

    puts("Matriz1 se suma con vectorsin");
    matrix_print(matriz1,print_int);

    Matrix* pepinero=matrix_sum_vector(matriz1,vectorsin);
    puts("Asi queda pepinero:");
    matrix_print(pepinero,print_int);

    Matrix* matriz3=matrix_new(2,3);
    matrix_add_random(matriz3);
    puts("Matriz3 queda asi:");
    matrix_print(matriz3, print_int);
    Matrix* matriz4=matrix_new(3,2);
    matrix_add_random(matriz4);
    puts("Matriz4 queda asi:");
    matrix_print(matriz4, print_int);
    

    Matrix* papon=matrix_mult(matriz3,matriz4);
    puts("Asi queda papon:");
    matrix_print(papon,print_int);


    free_matrix(matriz1);
    
    return 0;
}