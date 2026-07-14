def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n - 1)

def newton_forward_derivative(x, fx, xp):
    n = len(x)
    fd = fx.copy()
    
    h = x[1] - x[0]  
    s = (xp - x[0]) / h  

    for j in range(1, n):
        for i in range(n - 1, j - 1, -1):
            fd[i] = fd[i] - fd[i - 1]

    val = fd[1] / h  
    prev = 1

    for i in range(2, n):
        term1 = 1
        for k in range(1, i):
            term1 *= (s - k + 1)

        term2 = term1 * prev
        prev = term2
        val += (fd[i] * term2) / (factorial(i) * h)

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

    derivative = newton_forward_derivative(x, fx, xp)

    print(f"\nValue of First Derivative = {derivative:.6f}")

if __name__ == "__main__":
    main()
