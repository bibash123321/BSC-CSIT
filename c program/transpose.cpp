 #include<stdio.h>
int main() { 
    int m, n; 
    printf("Enter the number of rows and columns of the matrix: "); 
    scanf("%d %d", &m, &n); 
    int matrix[m][n], transpose[n][m]; 
    printf("Enter the elements of the matrix:\n"); 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) { 
            scanf("%d", &matrix[i][j]); 
        } 
    } 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            transpose[i][j] = matrix[j][i]; 
        } 
    } 
    printf("Transpose of the matrix:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            printf("%d ", transpose[i][j]); 
        } 
        printf("\n");   
    } 
    return 0; 
} 
 
 
 
 

