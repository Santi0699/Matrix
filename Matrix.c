#include "Matrix.h"
#include "vector.h"
//16
typedef struct _Matrix
{
    t_elem_matrix** a;
    int col;
    int row;
}Matrix;

Matrix* matrix_new(int row, int col)
{
    Matrix* m= (Matrix*)malloc(sizeof(Matrix));

    if(m==NULL){

        puts("Error al reservar memoria para la matriz");
        return NULL;
    }

    m->a = (t_elem_matrix**)malloc(row * sizeof(t_elem_matrix*)); // Reservar punteros a filas
    for (int i = 0; i < row; i++) {
        m->a[i] = (t_elem_matrix*)malloc(col * sizeof(t_elem_matrix)); // Reservar cada fila
    }
    m->row=row;
    m->col=col;


    return m;

}

void free_matrix(Matrix* m)
{
    free(m->a);
    free(m);

}

int matrix_rows(Matrix* m)
{
    return m->row;
}

int matrix_columns(Matrix* m)
{
    return m->col;
}

t_elem_matrix matrix_get(Matrix* m, int row, int col)
{
    return m->a[row][col];
}

void matrix_set (Matrix* m, int row, int col, t_elem_matrix value)
{

    m->a[row][col]=value;
}

void matrix_print(Matrix* m, void (*print)(t_elem_matrix))
{    
    for (int i = 0; i < m->row; i++) {
        for(int j=0; j<m->col; j++)
        {
            print(m->a[i][j]);
        }   // Se imprime cada elemento usando la función pasada
        puts("");
    }
    printf("\n");

}
//17
void matrix_add_random(Matrix* m)
{
    int row=matrix_rows(m);
    int col=matrix_columns(m);


    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
        {
            t_elem_matrix value=rand()%10;
            matrix_set(m,i,j,value);
        }
    }

}

void print_int(t_elem_matrix x) {
    printf("|%d| ", x);
}

//18
void matrix_change_row_with_vector(Matrix* m, vector* v,int row_change)
{

    if(m==NULL && v==NULL) return;

    int size = vector_size(v);
    int row=matrix_rows(m);
    int col=matrix_columns(m);

    if(size==col)
    {
        for(int i=0; i<col; i++)
        {
            t_elem_vector value=vector_get(v,i);
            matrix_set(m,row_change,i,(t_elem_matrix)value);
        }
    }

}
//19
void matrix_change_col_with_vector(Matrix* m, vector* v,int col_change)
{

    if(m==NULL && v==NULL) return;

    int size = vector_size(v);
    int row=matrix_rows(m);
    int col=matrix_columns(m);

    if(size==col)
    {
        for(int i=0; i<row; i++)
        {
            t_elem_vector value=vector_get(v,i);
            matrix_set(m,i,col_change,(t_elem_matrix)value);
        }
    }

}
//21
