#include <stdlib.h>

double** MatrixAlloucation(int dim){
    double** arr = (double**)malloc(dim * sizeof(double*));
    for(int i=0; i<dim; i++)
        arr[i] = (double*)malloc(dim * sizeof(double));
    return arr;
}
