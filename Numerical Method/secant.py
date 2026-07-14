

def secant_method(f, x0, x1, tol=1e-6, max_iter=100):
    iter_count = 0
    while iter_count < max_iter:
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        if abs(f(x2)) < tol:
            print(f"Root found: {x2}")
            return x2
        x0, x1 = x1, x2
        iter_count += 1
    print("Maximum iterations reached")
    return None

def func(x):
    return x**2 - 4

x0 = 1
x1 = 3

root = secant_method(func, x0, x1)
print(f"Root: {root}")


