def main():
    n = int(input("Enter the number of data points: "))
    xv = float(input("Enter the value of x: "))
    
    x = []
    fx = []
    
    for i in range(n):
        xi, fxi = map(float, input(f"Enter the x[{i}] and f(x[{i}]): ").split())
        x.append(xi)
        fx.append(fxi)
    
    # Initialize the forward difference table
    a = [fx]
    
    # Calculate the forward differences
    for i in range(1, n):
        temp = []
        for j in range(n - i):
            temp.append(a[i-1][j+1] - a[i-1][j])
        a.append(temp)
    
    # Apply Newton's Forward formula
    result = fx[0]
    p = 1
    for i in range(1, n):
        p *= (xv - x[i-1])
        result += (a[i][0] * p) / (math.factorial(i))
    
    print(f"The value of f({xv}) is {result}")

if __name__ == "__main__":
    import math
    main()
