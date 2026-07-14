 #include<stdio.h>
int main() { 
    int m, n, p; 
    printf("Enter dimensions of first matrix (m n): "); 
    scanf("%d%d", &m, &n); 
    printf("Enter dimensions of second matrix (n p): "); 
    scanf("%d%d", &n, &p); 
    int mat1[m][n], mat2[n][p], result[m][p]; 
    printf("Enter elements of first matrix:\n"); 
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &mat1[i][j]); 
    printf("Enter elements of second matrix:\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < p; j++) 
            scanf("%d", &mat2[i][j]); 
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < p; j++) {    
            result[i][j] = 0; 
            for (int k = 0; k < n; k++) 
                result[i][j] += mat1[i][k] * mat2[k][j];    
       } 
    printf("Resultant matrix after multiplication:\n"); 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < p; j++) 
            printf("%d ", result[i][j]); 
        printf("\n"); 
    } 
    return 0;}
    
    
