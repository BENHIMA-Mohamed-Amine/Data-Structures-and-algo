#include <stdio.h>
#include <math.h>

double image(float x){
    return ((2 * pow(x, 3) + 3) * (pow(x, 2) - 1)) / (sqrt(3 * pow(x, 2) + 1));
}

int main(){
    printf("image de 2 = %.3lf.", image(2));
    return 0;
}