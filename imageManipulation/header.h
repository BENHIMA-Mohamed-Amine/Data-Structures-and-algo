#include <stdio.h>
#include <stdlib.h>
#include "./imageCreation.c"
#include "./writeToMatrix/writeToMatrixRandomly.c"
#include "./writeToMatrix/writeToMatrixByHand.c"
#include "./display.c"


void imageCreation(int***, int, int, int);
void writeToMatrixRandomly(int***, int, int, int);
void writeToMatrixByHand(int***, int, int, int);
void display(int***, int, int, int);