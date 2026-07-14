 #include<stdio.h>
int main() { 
    int m, n; 
    printf("Enter the number of rows and columns of the matrix: "); 
    scanf("%d %d", &m, &n); 
    int matrix[m][n]; 
    printf("Enter the elements of the matrix:\n"); 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) { 
            scanf("%d", &matrix[i][j]); 
        } 
    } 
    printf("Sum of each row:\n"); 
    for (int i = 0; i < m; i++) { 
        int rowSum = 0; 
        for (int j = 0; j < n; j++) { 
            rowSum += matrix[i][j]; 
        } 
        printf("Row %d: %d\n", i + 1, rowSum);  
    } 
    printf("Sum of each column:\n");  
    for (int j = 0; j < n; j++) { 
        int colSum = 0; 
        for (int i = 0; i < m; i++) { 
            colSum += matrix[i][j]; 
        } 
        printf("Column %d: %d\n", j + 1, colSum); 
    } 
    return 0;
}
