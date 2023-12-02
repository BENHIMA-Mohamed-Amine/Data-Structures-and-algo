void display(int*** matrix, int w, int h, int r){
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            for(int k=0; k<r; k++){
                printf("Arr[%d][%d][%d]: %d\t", i+1, j+1, k+1, matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}