#include <stdio.h>
#define SIZE 3

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void joinMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = A[i][j] || B[i][j];
}

void productMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result[i][j] = A[i][j] && B[i][j];
}

void booleanProductMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
                result[i][j] = result[i][j] || (A[i][k] && B[k][j]);
        }
}

int main() {
    int A[SIZE][SIZE] = {{1, 0, 1}, {0, 1, 0}, {1, 1, 0}};
    int B[SIZE][SIZE] = {{1, 1, 0}, {0, 0, 1}, {1, 0, 1}};
    int joinResult[SIZE][SIZE], productResult[SIZE][SIZE], booleanProductResult[SIZE][SIZE];

    joinMatrices(A, B, joinResult);
    productMatrices(A, B, productResult);
    booleanProductMatrices(A, B, booleanProductResult);

    printf("Matrix A:\n");
    printMatrix(A);
    printf("\nMatrix B:\n");
    printMatrix(B);
    printf("\nJoin of A and B (A OR B):\n");
    printMatrix(joinResult);
    printf("\nProduct of A and B (A AND B):\n");
    printMatrix(productResult);
    printf("\nBoolean Product of A and B:\n");
    printMatrix(booleanProductResult);

    return 0;
}

