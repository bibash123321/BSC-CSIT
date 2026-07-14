def gauss_jordan():
    n = int(input("Enter Dimension of System of equations: "))
    
    a = []
    
    print("Enter coefficients Augmented Matrix:")
    for i in range(n):
        row = list(map(float, input().split()))
        a.append(row)
    
    # Gauss-Jordan Elimination
    for k in range(n):
        pivot = a[k][k]
        
        # Normalization of the pivot row
        for p in range(n + 1):
            a[k][p] /= pivot
        
        # Make other rows zero
        for i in range(n):
            if i != k:
                term = a[i][k]
                for j in range(n + 1):
                    a[i][j] -= a[k][j] * term
    
    # Display Solution
    print("Solution:")
    for i in range(n):
        print(f"x{i + 1} = {a[i][n]:.2f}")

if __name__ == "__main__":
    gauss_jordan()
