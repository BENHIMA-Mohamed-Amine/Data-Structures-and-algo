#include <stdlib.h>
void readMatrixFromBinaryFile(const char* filename, double** arr) {
    int *rows=(int*)malloc(sizeof(int)), *cols=(int*)malloc(sizeof(int));
    FILE* file = fopen(filename, "rb");

    if (file != NULL) {
        // Read the dimensions of the matrix
        fread(rows, sizeof(int), 1, file);
        fread(cols, sizeof(int), 1, file);

        // Read the matrix data
        for (int i = 0; i < *rows; ++i) {
            fread(arr[i], sizeof(double), *cols, file);
        }

        fclose(file);
    } else {
        printf("Error opening file %s for reading.\n", filename);
        exit(1);
    }
}
