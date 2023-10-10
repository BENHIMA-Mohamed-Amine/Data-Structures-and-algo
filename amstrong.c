#include <stdio.h>
#include <math.h>

// Define a constant for the maximum array size
#define NMAX 100

// Function to calculate the number of digits in an integer
int getLength(int x) {
    int l = 1;
    while (x > 9) {
        x /= 10;
        l++;
    }
    return l;
}

// Function to get a specific digit from an integer
int getDigit(int x, int i) {
    return (x / (int)pow(10, i)) % 10;
}

// Function to calculate the sum of the cubes of its digits
int getSum(int x) {
    int l = getLength(x), i, s = 0;
    for (i = 0; i < l; i++) {
        s += pow(getDigit(x, i), 3);
    }
    return s;
}

// Function to find the next number where the sum of cubes of its digits equals itself
int findNext(int x) {
    int s;
    do {
        x++;
        s = getSum(x);
    } while (s != x);
    return x;
}

int main() {
    int n, cmp = 0, x = 0, i;
    int list[NMAX];

    // Get a positive number from the user
    do {
        printf("Write a positive number: ");
        scanf("%d", &n);
    } while (n <= 0);

    // Find and store the next numbers with the desired property
    while (cmp < n) {
        x = findNext(x);
        list[cmp++] = x;
    }

    // Print the list of numbers
    for (i = 0; i < cmp; i++)
        printf("%d\t", list[i]);

    return 0;
}
