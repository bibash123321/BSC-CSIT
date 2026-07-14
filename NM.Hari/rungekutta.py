def f(x, y):
    return 2 * x + y

def main():
    x0, y0 = map(float, input("Enter initial values of x0 & y0: ").split())
    xp = float(input("Enter x at which function to be evaluated: "))
    h = float(input("Enter the step size: "))

    y = y0
    x = x0

    while x < xp:
        m1 = f(x, y)
        m2 = f(x + 0.5 * h, y + 0.5 * h * m1)
        m3 = f(x + 0.5 * h, y + 0.5 * h * m2)
        m4 = f(x + h, y + h * m3)

        y = y + (h / 6) * (m1 + 2 * m2 + 2 * m3 + m4)
        x = x + h

        print(f"Function value at x = {x} is {y}")

if __name__ == "__main__":
    main()
