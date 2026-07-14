def gauss_jordan_inverse():
    n = int(input("Enter Dimension of System of equations: "))
    
    a = []
    
    print("Enter coefficients Matrix:")
    for i in range(n):
        row = list(map(float, input().split()))
        a.append(row)
    
    # Augment the matrix with the identity matrix
    for i in range(n):
        for j in range(n, 2*n):
            if i == j - n:
                a[i].append(1)
            else:
                a[i].append(0)
    
    # Gauss-Jordan Elimination
    for k in range(n):
        pivot = a[k][k]
        
        # Normalize the pivot row
        for p in range(2*n):
            a[k][p] /= pivot
        
        # Make other rows zero
        for i in range(n):
            if i != k:
                term = a[i][k]
                for j in range(2*n):
                    a[i][j] -= a[k][j] * term
    
    # Display Inverse Matrix
    print("Matrix Inverse is:")
    for i in range(n):
        for j in range(n, 2*n):
            print(f"{a[i][j]:.6f}", end="\t")
        print()

if __name__ == "__main__":
    gauss_jordan_inverse()

