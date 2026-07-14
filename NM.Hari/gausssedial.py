import math

def gauss_seidel(n, a, b, error):
    x = [0] * n
    E = [0] * n
    
    while True:
        converged = True
        
        for i in range(n):
            sum_val = b[i]
            
            for j in range(n):
                if i != j:
                    sum_val -= a[i][j] * x[j]
            
            new_x = sum_val / a[i][i]
            E[i] = abs(new_x - x[i]) / abs(new_x)
            x[i] = new_x
            
            if E[i] > error:
                converged = False
        
        if converged:
            break
    
    return x

def main():
    n = int(input("Enter Dimension of System of Equations: "))
    a = []
    
    print("Enter the coefficients row by row (each row space separated):")
    for i in range(n):
        row = list(map(float, input().split()))
        a.append(row)
    
    b = []
    print("Enter the RHS Vector:")
    for i in range(n):
        b.append(float(input()))
    
    error = float(input("Enter Accuracy Limit: "))
    
    solution = gauss_seidel(n, a, b, error)
    
    print("Solution:")
    for i in range(n):
        print(f"x{i+1} = {solution[i]:.4f}")

if __name__ == "__main__":
    main()
