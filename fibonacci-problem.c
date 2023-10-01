#include <stdio.h>

// Function to calculate Fibonacci using recursion
int fibonacci_with_recu(int n){
    if(n < 2) return n; // Base case: Return n if it's 0 or 1
    return (fibonacci_with_recu(n-1) + fibonacci_with_recu(n-2)); // Recursively calculate Fibonacci
}

// Function to calculate Fibonacci using a for loop
int fibonacci_with_for_loop(int n){
    if((n == 0 ) || (n == 1)) return n; // Base case: Return n if it's 0 or 1
    int i;
    long long u_0 = 0, u_1 = 1 , u;
    for (i = 2; i <= n; i++){
        u = u_0 + u_1; // Calculate the next Fibonacci number
        u_0 = u_1; // Update u_0
        u_1 = u; // Update u_1
    }
    return u; // Return the final Fibonacci number
}

// Function to multiply two 2x2 matrices
void matrix_multiply(int a[2][2], int b[2][2], int result[2][2]){
    int temp[2][2];
    // Perform matrix multiplication and store the result in 'temp'
    temp[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    temp[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    temp[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    temp[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    // Copy the result from 'temp' to 'result'
    result[0][0] = temp[0][0];
    result[0][1] = temp[0][1];
    result[1][0] = temp[1][0];
    result[1][1] = temp[1][1];
}

// Function to calculate Fibonacci using matrix exponentiation
int fibonacci_with_matrix_exponentiation(int n){
    if(n <= 0) return 0; // Return 0 if n is non-positive

    int base_matrix[2][2] = {{1, 1}, {1, 0}}; // Define the base matrix
    int result[2][2] = {{1, 0}, {0, 1}}; // Initialize the result matrix as the identity matrix

    while(n > 0){
        if (n % 2 == 1) matrix_multiply(result, base_matrix, result); // Multiply result by base_matrix if n is odd
        matrix_multiply(base_matrix, base_matrix, base_matrix); // Square the base_matrix
        n /= 2; // Halve n
    }
    return result[0][1]; // Return the Fibonacci number in the result matrix
}

int main(){
    int n;

    do{
        printf("Enter a positive number: ");
        scanf("%d", &n);
        if (n < 0){
            printf("%d is < 0\n", n);
        }
    }while(n < 0);

    printf("Fibonacci series with recursion equals to %d.\n", fibonacci_with_recu(n)); // Print Fibonacci with recursion
    printf("Fibonacci sequence with for loop equals to %d.\n", fibonacci_with_for_loop(n)); // Print Fibonacci with for loop
    printf("Fibonacci sequence with matrix exponentiation equals to %d.\n", fibonacci_with_matrix_exponentiation(n)); // Print Fibonacci with matrix exponentiation
    return 0;
}
