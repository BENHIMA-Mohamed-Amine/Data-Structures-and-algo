void writeToMatrixByHand(int*** arr, int w, int h, int r){
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            for(int k=0; k<r; k++){
                printf("Write Arr[%d][%d][%d]: ", i+1, j+1, k+1);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
}