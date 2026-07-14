def divided_difference(x, fx):
    n = len(x)
    a = fx.copy()

    for i in range(1, n):
        for j in range(n - 1, i - 1, -1):
            a[j] = (a[j] - a[j - 1]) / (x[j] - x[j - i])
    
    return a  

def newton_derivative(x, fx, xv):
    n = len(x)
    a = divided_difference(x, fx)

    derivative = a[1]  # First-order divided difference

    product_term = 1  
    for i in range(2, n):
        product_term *= (xv - x[i - 2])  
        derivative += a[i] * i * product_term  

    return derivative

def main():
    n = int(input("Enter the number of points (n): "))

    x = []
    fx = []
    
    print("Enter values of data points (x and f(x)):")
    for _ in range(n):
        xi, fxi = map(float, input().split())
        x.append(xi)
        fx.append(fxi)

    xv = float(input("Enter the value at which derivative is required: "))

    derivative = newton_derivative(x, fx, xv)

    print(f"Value of First Derivative = {derivative:.6f}")

if __name__ == "__main__":
    main()
