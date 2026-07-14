import math

def y1(x):
    return 2 + x - (2.0 / 3) * x ** 3

def y2(x):
    return 2 + x + x ** 2 - (2.0 / 3) * x ** 3 + x ** 4 / 4

def y3(x):
    return 2 + x + x ** 2 - (x ** 4 / 3) - (x ** 5 / 15)

def evaluate_function(x0, y0, x):
    y = y0 + y1(x)  # First approximation
    y = y0 + y2(x)  # Second approximation
    y = y0 + y3(x)  # Third approximation
    return y

x0 = float(input("Enter initial value of x: "))
y0 = float(input("Enter initial value of y: "))
x = float(input("Enter x at which function to be evaluated: "))

result = evaluate_function(x0, y0, x)
print(f"Function value at x = {x} is {result}")
