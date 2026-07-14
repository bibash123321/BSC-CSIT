import math

def gaussian_elimination():
    n = int(input("Enter Dimension of System of equations: "))
    
    a = []
    b = []
    x = [0] * n
    
    print("Enter coefficients row-wise:")
    for i in range(n):
        row = list(map(float, input().split()))
        a.append(row)
    
    print("Enter RHS vector:")
    b = list(map(float, input().split()))
    
    for k in range(n - 1):
        pivot = a[k][k]
        if abs(pivot) < 1e-6:
            print("Method failed")
            return
        else:
            for i in range(k + 1, n):
                term = a[i][k] / pivot
                for j in range(n):
                    a[i][j] -= a[k][j] * term
                b[i] -= b[k] * term
    
    x[n - 1] = b[n - 1] / a[n - 1][n - 1]
    
    for i in range(n - 2, -1, -1):
        sum = 0
        for j in range(i + 1, n):
            sum += a[i][j] * x[j]
        x[i] = (b[i] - sum) / a[i][i]
    
    print("Solution:")
    for i in range(n):
        print(f"x{i + 1} = {x[i]:.2f}")

if __name__ == "__main__":
    gaussian_elimination()
