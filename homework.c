#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    // Set random with current time
    srand((unsigned int)time(NULL));

    // Get user input for array size
    printf("Enter the size of the arrays: ");
    int userInput;
    scanf("%d", &userInput);

    // Create two arrays
    int *array1 = (int *)malloc(userInput * sizeof(int));
    int *array2 = (int *)malloc(userInput * sizeof(int));

    // Fill the arrays with random numbers between 1 and 99
    for (int i = 0; i < userInput; ++i) {
        array1[i] = rand() % 99 + 1;
        array2[i] = rand() % 99 + 1;
    }

    // Display the arrays
    printf("\nArray 1: ");
    for (int i = 0; i < userInput; ++i) {
        printf("%d ", array1[i]);
    }

    printf("\nArray 2: ");
    for (int i = 0; i < userInput; ++i) {
        printf("%d ", array2[i]);
    }

    int *sumArray = (int *)malloc(userInput * sizeof(int));

    // Calculate the sum of elements at corresponding indices
#pragma omp parallel
    for (int i = 0; i < userInput; ++i) {
        sumArray[i] = array1[i] + array2[i];
    }

    // Display the sum array
    printf("\nSum Array: ");
    for (int i = 0; i < userInput; ++i) {
        printf("%d ", sumArray[i]);
    }

    // Free memory
    free(array1);
    free(array2);
    free(sumArray);

    return 0;
}
