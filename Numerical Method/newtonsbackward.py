def fact(n):
    if n == 0:
        return 1
    else:
        return n * fact(n - 1)

def newtons_backward_difference_method():
    n = int(input("Enter the number of data points: "))
    xp = float(input("Enter the value at which interpolated value is needed: "))
    
    x = []
    fx = []
    
    for i in range(n):
        xi, fxi = map(float, input(f"Enter the x[{i}] and f(x[{i}]): ").split())
        x.append(xi)
        fx.append(fxi)

    h = x[1] - x[0]
    s = (xp - x[-1]) / h
    fd = fx.copy()

    for i in range(1, n):
        for j in range(n - 1, i - 1, -1):
            fd[j] = fd[j] - fd[j - 1]

    v = fd[-1]
    for i in range(1, n):
        p = 1
        for j in range(i):
            p *= (s + j)
        v += (p / fact(i)) * fd[n - 1 - i]

    print(f"The value of f({xp}) is {v}")

if __name__ == "__main__":
    newtons_backward_difference_method()
