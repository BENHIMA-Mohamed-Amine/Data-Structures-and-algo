#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void allocateMatrix(int*** arr, int rows, int cols) {
    *arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        (*arr)[i] = (int*)malloc(cols * sizeof(int));
    // printf("matrix allocated\n");
}

void freeMatrix(int** arr, int rows){
    for (int i = 0; i < rows; i++)
        free(arr[i]);
    free(arr);
}

void fillMatrixWithRandomNumbers(int** matrix, int rows, int cols) {
    // Setting the seed for the random number generator based on the current time.
    srand(time(NULL));

    // Filling the matrix with random numbers.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Generating a random number within the specified range.
            matrix[i][j] = ((int)(rand()) % 100) + 1;
        }
    }
    // printf("matrix filled\n");
}

void fillMatrixWithWritingNumbers(int** matrix, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Arr[%d][%d]= ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}


void displayMatrix(int** arr, int rows, int cols) {
    printf("Matrix Contents:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", arr[i][j]);  // Adjust the format as needed
        }
        printf("\n");
    }
}

int getTraceMatrix(int** arr, int rows, int cols){
    if(rows == cols){
        int trace = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(i == j)
                    trace += arr[i][j];
            }
        }
        return trace;
    }
    else{
        printf("row != cols\n");
        exit(1);
    }
}

void slicingMatrix(int** arr, int** slicedArr, int rowsStartingIdx, int colsStartingIdx, int rowsEndingIdx, int colsEndingIdx){
    int row=0, col;
    for(int i=rowsStartingIdx; i<rowsEndingIdx; i++){
        col=0;
        for(int j=colsStartingIdx; j<colsEndingIdx; j++){
            slicedArr[row][col] = arr[i][j];
            col++;
        }
        row++;
    }
}

int elementWiseMultiplication(int** slicedArr, int** filter, int frows, int fcols){
    int sum=0;
    for(int i=0; i<frows; i++){
        for(int j=0; j<fcols; j++){
            sum += slicedArr[i][j] * filter[i][j];
        }
    }
    return sum;
}

void paddingArray(int **paddedResults, int **results, int rows, int cols, int n_w, int n_h, int paddedLignes){
    int row=0, col;
    for(int i=0; i<rows; i++){
        col=0;
        for(int j=0; j<cols; j++){
            if((i >= paddedLignes) && (i <= n_w) && (j >= paddedLignes) && (j <= n_h)){
                paddedResults[i][j] = results[row][col];
                col++;
            } else{
                paddedResults[i][j] = 0;
            }
        }
        if(col == n_h)
            row++;
    }
}

void matrixConvolution(int** arr, int** filter, int** paddedResults, int rows, int cols, int frows, int fcols){
    // Dimensions of results matrix:
    // results (n_h, n_h)
    // n_w = (rows + 2 * padding - frows) / stride + 1
    // n_h = (cols + 2 * padding - fcols) / stride + 1

    int** results;
    int n_w, n_h, rowsEndingIdx = frows, colsEndingIdx;;
    n_w = (rows + 2 * 0 - frows) / 1 + 1;
    n_h = (cols + 2 * 0 - fcols) / 1 + 1;
    allocateMatrix(&results, n_w, n_h);
    for(int i=0; i<n_w; i++){
        colsEndingIdx = fcols;
        for(int j=0; j<n_h; j++){
            int** slicedArr;
            allocateMatrix(&slicedArr, frows, fcols);
            slicingMatrix(arr, slicedArr, i, j, rowsEndingIdx, colsEndingIdx);
            results[i][j] = elementWiseMultiplication(slicedArr, filter, frows, fcols);
            freeMatrix(slicedArr, frows);
            colsEndingIdx++;
        }
        rowsEndingIdx++;
    }

    paddingArray(paddedResults, results, rows, cols, n_w, n_h, (rows-n_w)/2);
    freeMatrix(results, n_w);
}

int main() {
    int** arr = NULL;
    int rows, cols;
    printf("Enter the dimension of the matrix: ");
    scanf("%d", &rows);
    cols = rows;
    allocateMatrix(&arr, rows, cols);
    fillMatrixWithRandomNumbers(arr, rows, cols);
    // fillMatrixWithWritingNumbers(arr, rows, cols);
    displayMatrix(arr, rows, cols);
    printf("trace of the matrix is %d.\n", getTraceMatrix(arr, rows, cols));
    int** filter, **paddedResults;
    int frows, fcols;
    printf("Enter the dimension of the filter matrix: ");
    scanf("%d", &frows);
    fcols = frows;
    allocateMatrix(&filter, frows, fcols);
    fillMatrixWithRandomNumbers(filter, frows, fcols);
    // fillMatrixWithWritingNumbers(filter, frows, fcols);
    displayMatrix(filter, frows, fcols);

    allocateMatrix(&paddedResults, rows, cols);
    matrixConvolution(arr, filter, paddedResults, rows, cols, frows, fcols);
    displayMatrix(paddedResults, rows, cols);
    // Don't forget to free the allocated memory when done.
    freeMatrix(arr, rows);

    return 0;
}
