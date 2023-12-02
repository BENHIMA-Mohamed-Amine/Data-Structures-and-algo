double** matrixSum(double** mat1, double** mat2, int dim){
    double** result = MatrixAlloucation(dim);
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            result[i][j] = mat1[i][j] + mat2[i][j]; 
        }
    }
    return result;
}