import math

def f(x):
    return 3 * x * x + 2 * x - 5

def trapezoidal_rule(x0, xn, k):
    h = (xn - x0) / k
    fx0 = f(x0)
    fxn = f(xn)
    term = fx0 + fxn
    
    for i in range(1, k):
        a = x0 + i * h
        term += 2 * f(a)
    
    v = (h / 2) * term
    return v

x0 = float(input("Enter Lower Limit: "))
xn = float(input("Enter Upper Limit: "))
k = int(input("Enter Number of Segments: "))

result = trapezoidal_rule(x0, xn, k)
print("Value of Integration:", result)
