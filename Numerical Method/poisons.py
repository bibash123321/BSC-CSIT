import math

def g(x, y):
    return 2 * (x**2) * (y**2)

def main():
    n = int(input("Enter Dimension of plate: "))
    h = float(input("Enter Grid size (h): "))
    tl, tr, tb, tu = map(float, input("Enter temperatures at left, right, bottom & upper part of plate: ").split())

    # Initialize coefficient matrix 'a' and right-hand side vector 'b'
    a = [[0 for _ in range(n)] for _ in range(n)]
    b = [0 for _ in range((n-1) * (n-1))]  # Adjusting size for b
    new_x = [0 for _ in range(n)]
    old_x = [0 for _ in range(n)]
    E = [0 for _ in range(n)]

    # Initializing coefficient matrix 'a' for the Poisson equation
    for i in range(n):
        for j in range(n):
            if i == j:
                a[i][j] = -4
            else:
                a[i][j] = 1

    # Constructing the right-hand side vector 'b'
    k = 0
    for i in range(1, n-1):
        for j in range(1, n-1):
            b[k] = h * h * g(i, j)
            k += 1

    # Adjusting for boundary conditions
    k = 0
    for i in range(1, n-1):
        for j in range(1, n-1):
            if (i - 1) == 0:
                b[k] -= tl
            if (i + 1) == n:
                b[k] -= tr
            if (j - 1) == 0:
                b[k] -= tb
            if (j + 1) == n:
                b[k] -= tu
            k += 1

    error = float(input("Enter Accuracy Limit: "))

    # Gauss-Seidel Iteration
    while True:
        for i in range(n):
            sum_ = 0
            for j in range(n):
                if i != j:
                    sum_ -= a[i][j] * new_x[j]
            old_x[i] = new_x[i]
            new_x[i] = (b[i] + sum_) / a[i][i]
            E[i] = abs(new_x[i] - old_x[i]) / abs(new_x[i])

        # Checking for convergence
        if all(e <= error for e in E):
            break

    # Printing solution
    print("Solution:")
    for i in range(n):
        print(f"x{i+1} = {new_x[i]:6.2f}")

if __name__ == "__main__":
    main()
