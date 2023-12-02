#include "./header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a submatrix by excluding a specified row and column
double** createSubmatrix(double** matrix, int size, int excludeRow, int excludeColumn) {
    double** submatrix = (double**)malloc((size - 1) * sizeof(double*));
    for (int i = 1; i < size; ++i) {
        submatrix[i - 1] = (double*)malloc((size - 1) * sizeof(double));
        for (int j = 0, subcol = 0; j < size; ++j) {
            if (j == excludeColumn) {
                continue; // Skip the excluded column
            }
            submatrix[i - 1][subcol++] = matrix[i][j];
        }
    }
    return submatrix;
}

// Function to calculate the determinant of a submatrix
double determinant(double** matrix, int size) {
    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        double det = 0;
        for (int i = 0; i < size; ++i) {
            // Calculate the determinant using cofactor expansion
            double sign = (i % 2 == 0) ? 1.0 : -1.0;
            double subDet = determinant(createSubmatrix(matrix, size, 0, i), size - 1);
            det += sign * matrix[0][i] * subDet;
        }
        return det;
    }
}

// Function to free memory allocated for a matrix
void freeMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i)
        free(matrix[i]);
    free(matrix);
}

// Function to perform Gauss-Jordan elimination for matrix inversion
double** invertMatrix(double **matrix, int size) {
    // Create an augmented matrix [matrix | I]
    double **augmentedMatrix = MatrixAlloucation(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            augmentedMatrix[i][j] = matrix[i][j];
            augmentedMatrix[i][j + size] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Apply Gauss-Jordan elimination
    for (int i = 0; i < size; i++) {
        // Make the diagonal element 1
        double pivot = augmentedMatrix[i][i];
        for (int j = 0; j < 2 * size; j++) {
            augmentedMatrix[i][j] /= pivot;
        }

        // Make other elements in the column 0
        for (int k = 0; k < size; k++) {
            if (k != i) {
                double factor = augmentedMatrix[k][i];
                for (int j = 0; j < 2 * size; j++) {
                    augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
                }
            }
        }
    }

    // Allocate memory for the inverse matrix
    double** inverse = MatrixAlloucation(size);

    // Copy the inverse from the augmented matrix [I | inverse]
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inverse[i][j] = augmentedMatrix[i][j + size];
        }
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(augmentedMatrix[i]);
    }
    free(augmentedMatrix);

    return inverse;
}


int main(){
    int dim;
    printf("Enter the dimension of your array: ");
    scanf("%d", &dim);
    double** arr = MatrixAlloucation(dim);
    DisplayMenu(arr, dim);
    DisplayMatrix(arr, dim);
    printf("---------------------------------------------------\n");
    // printf("Determinant: %f\n", determinant(arr, dim));
    double** inverseMatrix = invertMatrix(arr, dim);
    DisplayMatrix(inverseMatrix, dim);
    // DisplayMatrix(arr, dim);
    // printf("---------------------------------------------------\n");
    // double** sumArr = matrixSum(arr, arr, dim);
    // DisplayMatrix(sumArr, dim);
    // printf("---------------------------------------------------\n");
    // double** matMulResult = matrixMult(arr, arr, dim);
    // DisplayMatrix(matMulResult, dim);
    return 0;
}