void WriteMatrixUsingKeyboard(double** arr, int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("Write Arr[%d][%d]: ", i+1, j+1);
            scanf("%lf", &arr[i][j]);
        }
    }
}