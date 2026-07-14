def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

def newton_backward_derivative(x, fx, xp):
    n = len(x)
    bd = fx.copy()

    h = x[1] - x[0]  
    s = (xp - x[-1]) / h  

    for j in range(1, n):
        for i in range(n - 1, j - 1, -1):
            bd[i] = bd[i] - bd[i - 1]

    val = bd[n - 1] / h  
    prev = 1

    for i in range(2, n):
        term = 1
        for k in range(1, i):
            term *= (s + k - 1)

        prev = term
        val += (bd[n - 1] * prev) / (factorial(i) * h)

    return val

def main():
    n = int(input("Enter the number of points: "))

    x = []
    fx = []

    print("Enter values of x & f(x):")
    for _ in range(n):
        xi, fxi = map(float, input().split())
        x.append(xi)
        fx.append(fxi)

    xp = float(input("\nEnter the value at which Derivative is needed: "))

    derivative = newton_backward_derivative(x, fx, xp)

    print(f"\nValue of First Derivative = {derivative:.6f}")

if __name__ == "__main__":
    main()
