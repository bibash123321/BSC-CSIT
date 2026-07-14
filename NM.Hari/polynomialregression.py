import numpy as np

def polynomial_regression():
    # Input the number of data points and degree of polynomial
    n = int(input("Enter the number of data points: "))
    m = int(input("Enter the degree of polynomial to be fitted: "))

    # Input the values of x and fx (the independent and dependent variables)
    x = np.zeros(n)
    fx = np.zeros(n)

    print("Enter the value of x and fx: ")
    for i in range(n):
        x[i], fx[i] = map(float, input().split())

    # Create the matrix 'a' and vector 'b'
    a = np.zeros((m + 1, m + 1))
    b = np.zeros(m + 1)

    # Construct matrix 'a'
    for i in range(m + 1):
        for j in range(m + 1):
            a[i][j] = sum([x[k]**(i + j) for k in range(n)])

    # Construct vector 'b'
    for i in range(m + 1):
        b[i] = sum([fx[k] * x[k]**i for k in range(n)])

    # Perform Gaussian Elimination to solve for the coefficients
    z = np.zeros(m + 1)
    
    for i in range(m + 1):
        pivot = a[i][i]
        for j in range(m + 1):
            a[i][j] /= pivot
        b[i] /= pivot

        for k in range(m + 1):
            if k != i:
                term = a[k][i]
                for j in range(m + 1):
                    a[k][j] -= term * a[i][j]
                b[k] -= term * b[i]

    z[m] = b[m] / a[m][m]
    for i in range(m - 1, -1, -1):
        sum_term = sum([a[i][j] * z[j] for j in range(i + 1, m + 1)])
        z[i] = (b[i] - sum_term) / a[i][i]

    # Display the polynomial equation
    print("The polynomial regression is: ")
    print(f"y = {z[0]} + {z[1]}x", end="")
    for i in range(2, m + 1):
        print(f" + {z[i]}x^{i}", end="")
    print()

# Call the function to execute
polynomial_regression()
