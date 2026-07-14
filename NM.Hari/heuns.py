def f(x, y):
    return 2.0 * y / x

def main():
    x0, y0 = map(float, input("Enter initial values of x & y (x0 y0): ").split())
    xp = float(input("Enter x at which function to be evaluated: "))
    h = float(input("Enter the step size: "))

    y = y0
    x = x0

    while x < xp:
        m1 = f(x, y)
        m2 = f(x + h, y + h * m1)
        y = y + (h / 2) * (m1 + m2)
        x += h

    print(f"Function value at x = {xp} is {y}")

if __name__ == "__main__":
    main()
