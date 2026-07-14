def f(x):
    return x ** 3 + 1

def simpsons_3_8_rule(x0, x3):
    n = 3  # Fixed number of segments for Simpson's 3/8 Rule
    h = (x3 - x0) / n
    
    x1 = x0 + h
    x2 = x0 + 2 * h
    
    fx0 = f(x0)
    fx1 = f(x1)
    fx2 = f(x2)
    fx3 = f(x3)
    
    v = (3 / 8) * h * (fx0 + 3 * fx1 + 3 * fx2 + fx3)
    return v

x0 = float(input("Enter Lower Limit: "))
x3 = float(input("Enter Upper Limit: "))

result = simpsons_3_8_rule(x0, x3)
print("Value of Integration:", result)
