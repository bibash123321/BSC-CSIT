def lagrange_interpolation():
    n = int(input("Enter the number of points: "))
    x = float(input("Enter the value of x: "))
    
    ax = []
    fx = []
    
    for i in range(n):
        xi, fxi = map(float, input(f"Enter the value of x and fx at i = {i}: ").split())
        ax.append(xi)
        fx.append(fxi)
    
    v = 0
    
    for i in range(n):
        l = 1.0
        for j in range(n):
            if j != i:
                l *= (x - ax[j]) / (ax[i] - ax[j])  # Lagrange basis polynomial formula
        v += fx[i] * l
    
    print(f"Interpolated Value = {v}")

lagrange_interpolation()
