void writeMatrixToBinaryFile(const char* filename, double** matrix, int rows, int cols) {
    FILE* file = fopen(filename, "wb");

    if (file != NULL) {
        // Write the dimensions of the matrix
        fwrite(&rows, sizeof(int), 1, file);
        fwrite(&cols, sizeof(int), 1, file);

        // Write the matrix data
        for (int i = 0; i < rows; ++i) {
            fwrite(matrix[i], sizeof(double), cols, file);
        }

        fclose(file);
        printf("Matrix written to %s successfully.\n", filename);
    } else {
        printf("Error opening file %s for writing.\n", filename);
    }
}