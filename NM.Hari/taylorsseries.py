import math

def fact(n):
    return 1 if n in (0, 1) else n * fact(n - 1)

def evaluate_function(x0, yx0, x):
    fdy = x0 ** 2 + yx0 ** 2
    sdy = 2 * x0 + 2 * yx0 * fdy
    tdy = 2 + 2 * yx0 * sdy + 2 * fdy ** 2
    
    yx = (yx0 + (x - x0) * fdy + 
          (x - x0) ** 2 * sdy / fact(2) + 
          (x - x0) ** 3 * tdy / fact(3))
    
    return yx

x0 = float(input("Enter initial value of x: "))
yx0 = float(input("Enter initial value of y: "))
x = float(input("Enter x at which function to be evaluated: "))

result = evaluate_function(x0, yx0, x)
print(f"Function value at x = {x} is {result}")