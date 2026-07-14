import math

def f(x):
    return 1.0 / x

def romberg_integration(x0, xn, p, q):
    T = [[0 for _ in range(q + 1)] for _ in range(p + 1)]
    h = xn - x0
    
    T[0][0] = (h / 2) * (f(x0) + f(xn))
    
    for i in range(1, p + 1):
        sl = 2 ** (i - 1)
        sm = sum(f(x0 + ((2 * k - 1) * h) / (2 ** i)) for k in range(1, sl + 1))
        T[i][0] = T[i - 1][0] / 2 + sm * h / (2 ** i)
    
    for c in range(1, p + 1):
        for k in range(1, min(c, q) + 1):
            m = c - k
            T[m + k][k] = (4 ** k * T[m + k][k - 1] - T[m + k - 1][k - 1]) / (4 ** k - 1)
    
    return T[p][q]

x0 = float(input("Enter Lower Limit: "))
xn = float(input("Enter Upper Limit: "))
p = int(input("Enter p (order of Romberg method): "))
q = int(input("Enter q (refinement level): "))

result = romberg_integration(x0, xn, p, q)
print("Romberg Estimate of Integration:", result)