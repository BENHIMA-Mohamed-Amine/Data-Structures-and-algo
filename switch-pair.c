#include <stdio.h>

// To read the pair to switch
void ReadPair(float *x, float *y){
    printf("Write x and y:");
    scanf("%f%f", x, y);
}

// To switch the value of a pair 
void SwitchPair(float *x, float *y){
    float tmp = *x;
    *x = *y;
    *y=tmp;  //swaping values of two variables
}

// to display two variables
void Display(float a, float b){
    printf("a = %.2f and b = %.2f", a, b);
}
int main() {
    float a, b;
    ReadPair(&a, &b);
    Display(a, b);
    SwitchPair(&a, &b);
    printf("\nAfter switching:\n");
    Display(a, b);
    return 0;
}