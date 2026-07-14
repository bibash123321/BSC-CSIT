import math

def main():
    n = int(input("Enter Dimension of plate (n x n): "))
    tl, tr, tb, tu = map(float, input("Enter temperatures at left, right, bottom & upper part of plate: ").split())

    a = [[0 for _ in range(n)] for _ in range(n)]  # Adjust matrix size for n
    b = [0 for _ in range(n)]  # Adjust vector size for n
    new_x = [0 for _ in range(n)]
    old_x = [0 for _ in range(n)]
    E = [0 for _ in range(n)]

    # Set up the coefficient matrix
    for i in range(n):
        for j in range(n):
            if i == j:
                a[i][j] = -4
            elif abs(i-j) == 1:
                a[i][j] = 1

    # Adjust the boundary conditions in the b vector
    for i in range(n):
        b[i] = 0  # Start with a zero vector
        if i == 0:  # Left side
            b[i] -= tl
        if i == n - 1:  # Right side
            b[i] -= tr
        if i == 1:  # Bottom side
            b[i] -= tb
        if i == n - 2:  # Upper side
            b[i] -= tu

    error = float(input("Enter Accuracy Limit: "))

    # Main loop to solve the system iteratively
    while True:
        for i in range(n):
            sum_val = b[i]
            for j in range(n):
                if i != j:
                    sum_val -= a[i][j] * new_x[j]
            old_x[i] = new_x[i]
            new_x[i] = sum_val / a[i][i]
            if new_x[i] != 0:
                E[i] = abs(new_x[i] - old_x[i]) / abs(new_x[i])
            else:
                E[i] = 0

        # Check if all errors are below the specified accuracy
        if all(e <= error for e in E):
            break

    print("Solution:")
    for i in range(n):
        print(f"x{i+1} = {new_x[i]:.2f}")

if __name__ == "__main__":
    main()
