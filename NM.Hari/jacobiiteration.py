import math

def main():
    n = int(input("Enter Dimension of System of Equations: "))
    a = [[0 for _ in range(n)] for _ in range(n)]
    b = [0 for _ in range(n)]
    new_x = [0 for _ in range(n)]
    old_x = [0 for _ in range(n)]
    E = [0 for _ in range(n)]
    
    print("Enter Coefficients (Row-wise):")
    for i in range(n):
        for j in range(n):
            a[i][j] = float(input(f"a[{i}][{j}] = "))
    
    print("Enter RHS Vector:")
    for i in range(n):
        b[i] = float(input(f"b[{i}] = "))
    
    error = float(input("Enter Accuracy Limit: "))
    
    while True:
        converged = True
        
        for i in range(n):
            sum_val = b[i]
            
            for j in range(n):
                if i != j:
                    sum_val -= a[i][j] * old_x[j]
            
            new_x[i] = sum_val / a[i][i]
            E[i] = abs(new_x[i] - old_x[i]) / abs(new_x[i])
            
            if E[i] > error:
                converged = False
        
        for i in range(n):
            old_x[i] = new_x[i]
        
        if converged:
            break
    
    print("Solution:")
    for i in range(n):
        print(f"x{i+1} = {new_x[i]:.4f}")

if __name__ == "__main__":
    main()
