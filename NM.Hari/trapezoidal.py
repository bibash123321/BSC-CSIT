import math

def f(x):
    return x*x + 3*x + 1

def trapezoidal_rule(x0, x1):
    h = x1 - x0
    fx0 = f(x0)
    fx1 = f(x1)
    v = (h / 2) * (fx0 + fx1)
    return v

x0 = float(input("Enter Lower Limit: "))
x1 = float(input("Enter Upper Limit: "))

result = trapezoidal_rule(x0, x1)
print("Value of Integration:", result)
