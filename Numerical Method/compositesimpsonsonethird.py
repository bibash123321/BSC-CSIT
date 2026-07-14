def f(x):
    return 1.0 / (1 + x)

def simpsons_rule(x0, xn, k):
    h = (xn - x0) / k
    fx0 = f(x0)
    fxn = f(xn)
    term = fx0 + fxn
    
    for i in range(1, k, 2):
        a = x0 + i * h
        term += 4 * f(a)
    
    for i in range(2, k - 1, 2):
        a = x0 + i * h
        term += 2 * f(a)
    
    v = (h / 3) * term
    return v

x0 = float(input("Enter Lower Limit: "))
xn = float(input("Enter Upper Limit: "))
k = int(input("Enter Number of Segments (even number required): "))

if k % 2 != 0:
    print("Error: Number of segments must be even for Simpson's 1/3 Rule.")
else:
    result = simpsons_rule(x0, xn, k)
    print("Value of Integration:", result)
