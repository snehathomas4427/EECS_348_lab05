/*
Author: Sneha Thomas
KUID: 3124266
Lab: 05
Lab Session: 1pm Friday
Purpose: matrix manipulation
*/

#include <stdio.h>
#define SIZE 5

void printMatrix(int array[SIZE][SIZE]){
    for (int i = 0; i < 5; i++) { // Loop through each row
        for (int j = 0; j < 5; j++) { // Loop through each col
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    int array[5][5] = {0}; // Initialize a new matrix to store the sum
    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++) {
            array[i][j] = m1[i][j] + m2[i][j];
        }
    }
    //prints the matrix
    printf("Sum of matrices: \n");
    printMatrix(array);
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    int array[5][5] = {0}; // Initialize a new matrix to store the product

    for(int i = 0; i < 5; i++){ //row
        for (int j = 0; j < 5; j++) { //col
            int sum = 0;
            for (int k = 0; k<5; k++){
                sum += m1[i][k] * m2[k][j]; 
            }
            array[i][j] = sum;
        }
    }

    //prints the matrix
    printf("Product of matrices: \n");
    printMatrix(array);
}

void transposeMatrix (int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    int m1_transpose[5][5] = {0}; // Initialize a new matrix to store the transpose of m1
    int m2_transpose[5][5] = {0}; // Initialize a new matrix to store the transpose of m2

    //transpose of m1
    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++) {
            m1_transpose[i][j] = m1[j][i]; // Transpose m1 by swapping rows and columns
            m2_transpose[i][j] = m2[j][i]; // Transpose m2 by swapping rows and columns
        }
    }
    printf("Transpose of matrix 1: \n");
    printMatrix(m1_transpose);

    printf("\nTranspose of matrix 2: \n");
    printMatrix(m2_transpose);
}

int main() {
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };

    addMatrices(m1,m2);
    printf("\n");
    multiplyMatrices(m1,m2);
    printf("\n");
    transposeMatrix(m1,m2);
    printf("\n");
    return 0; 
}