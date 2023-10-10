#include <stdio.h>
#include "square-root.h"

int main(){
    double x, y;

    printf("Write a positive number: ");
    scanf("%lf", &y);
    x = SquareRoot(y);

    printf("The square root of %.1f is %.10f", y, x);
    return 0;
}