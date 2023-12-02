double** matrixMult(double** mat1, double** mat2, int dim){
    double** result = MatrixAlloucation(dim);
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++) {
            result[i][j] = 0.0;
            for (int k=0; k<dim; k++) {
                result[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }
    return result;
}