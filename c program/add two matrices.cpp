 #include<stdio.h>
 int main() { 
    int m, n; 
    printf("Enter dimensions of matrices (m n): "); 
    scanf("%d%d", &m, &n); 
    int mat1[m][n], mat2[m][n], result[m][n]; 
    printf("Enter elements of the first matrix:\n"); 
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &mat1[i][j]); 
    printf("Enter elements of the second matrix:\n"); 
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &mat2[i][j]); 
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            result[i][j] = mat1[i][j] + mat2[i][j]; 
    printf("Resultant matrix after addition:\n"); 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) 
            printf("%d ", result[i][j]); 
        printf("\n"); 
    } 
    return 0;   
} 
 
 
 
 

