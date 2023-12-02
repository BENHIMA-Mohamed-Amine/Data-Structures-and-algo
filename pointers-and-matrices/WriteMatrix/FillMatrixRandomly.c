#include <stdlib.h>
void FillMatrixRandomly(double **arr, int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            arr[i][j] = rand() % 100 + 1;
        }
    }
}