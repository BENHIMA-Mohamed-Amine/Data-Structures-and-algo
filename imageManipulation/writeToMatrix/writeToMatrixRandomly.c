void writeToMatrixRandomly(int*** arr, int w, int h, int r){
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            for(int k=0; k<r; k++){
                arr[i][j][k] = rand() % 100 + 1;
            }
        }
    }
}