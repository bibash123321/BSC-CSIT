def f(x):
    return 3 * x * x + 2 * x - 5

def simpsons_rule(x0, x2):
    n = 2  # Fixed number of segments for Simpson's 1/3 Rule
    h = (x2 - x0) / n
    x1 = x0 + h
    
    fx0 = f(x0)
    fx1 = f(x1)
    fx2 = f(x2)
    
    v = (h / 3) * (fx0 + 4 * fx1 + fx2)
    return v

x0 = float(input("Enter Lower Limit: "))
x2 = float(input("Enter Upper Limit: "))

result = simpsons_rule(x0, x2)
print("Value of Integration:", result)
