#include <stdio.h>
#include <stdlib.h>
#include "./WriteMatrix/WriteMatrixUsingKeyboard.c"
#include "./WriteMatrix/FillMatrixRandomly.c"
#include "./WriteMatrix/writeMatrixToBinaryFile.c"
#include "./WriteMatrix/readMatrixFromBinaryFile.c"
#include "./MatrixAlloucation.c"

void DisplayMatrix(double** arr, int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%.3lf\t", arr[i][j]);
        }
        printf("\n");
    }
}

void readFileName(char* fileName){
    printf("Write the file name: ");
    scanf("%s", fileName);
    fflush(stdin);
}

void DisplayMenu(double **arr, int dim){
    int choice, fillByFileChoice;
    double** newArr = MatrixAlloucation(dim);
    printf("******************Choose a method to fill your matrix******************\n");
    printf("To fill Randomly choose 1\n");
    printf("To fill manually choose 2\n");
    printf("To fill from a file choose 3\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            FillMatrixRandomly(arr, dim);
            break;
        case 2:
            WriteMatrixUsingKeyboard(arr, dim);
            break;
        case 3:
            printf("To write to a file and initialize the matrix from it choose 1\n");
            printf("To fill from the existing file choose 2\n");
            printf("Your choice:");
            scanf("%d", &fillByFileChoice);
            char fileName[20];
            readFileName(fileName);
            fflush(stdin);
            switch (fillByFileChoice){
                case 1:
                    WriteMatrixUsingKeyboard(newArr, dim);
                    writeMatrixToBinaryFile(fileName, newArr, dim, dim);
                    readMatrixFromBinaryFile(fileName, arr);
                    break;
                case 2:
                    readMatrixFromBinaryFile(fileName, arr);
                    break;
                default: 
                    printf("This choice not available right now 1.\n");
            }
            break;
        default:
            printf("This choice not available right now.\n");
    }
}