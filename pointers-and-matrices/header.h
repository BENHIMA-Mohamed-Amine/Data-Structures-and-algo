#include "./helper.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./matrixSum.c"
#include "./matrixMult.c"


double** MatrixAlloucation(int);
void DisplayMatrix(double**, int);
void DisplayMenu(double**, int);
double** matrixSum(double**, double**, int);
double** matrixMult(double**, double**, int);