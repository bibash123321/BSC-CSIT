def newtons_divided_difference():
    n = int(input("Enter the number of data points: "))
    xu = float(input("Enter the value of x: "))
    
    x = []
    fx = []
    a = []

    for i in range(n):
        xi, fxi = map(float, input(f"Enter the x[{i}] and f(x[{i}]): ").split())
        x.append(xi)
        fx.append(fxi)

    for i in range(n):
        a.append(fx[i])
    
    # Construct the divided difference table
    for i in range(1, n):
        for j in range(n - 1, i - 1, -1):
            a[j] = (a[j] - a[j - 1]) / (x[j] - x[j - i])

    # Calculate the interpolated value using the divided difference table
    v = a[n - 1]
    for i in range(n - 2, -1, -1):
        v = v * (xu - x[i]) + a[i]

    print(f"The value of f({xu}) is {v}")

newtons_divided_difference()

