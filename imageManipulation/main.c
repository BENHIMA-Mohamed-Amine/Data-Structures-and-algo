#include "./header.h"


#define M 2
#define N 3
#define O 4

void getDimensions(int*** image, int* dimensions) {
    dimensions[0] = sizeof(image) / sizeof(image[0]);        // Dimension in the first direction
    dimensions[1] = sizeof(image[0]) / sizeof(image[0][0]);  // Dimension in the second direction
    dimensions[2] = sizeof(image[0][0]) / sizeof(image[0][0][0]);  // Dimension in the third direction
}


int main(){
    int*** matrix=NULL;
    int w=2, h=2, r=2;
    int dimensions[3];
    printf("----\n");
    imageCreation(matrix, M, N, O);
    printf("----\n");
    getDimensions(matrix, dimensions);

    printf("Dimensions: %d x %d x %d\n", dimensions[0], dimensions[1], dimensions[2]);
    // writeToMatrixRandomly(matrix, w, h, r);
    printf("----\n");
    display(matrix, w, h, r);
    printf("----\n");
}
