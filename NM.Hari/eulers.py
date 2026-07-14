import math

def f(x, y):
    return 2.0 * y / x

def main():
    x0, y0 = map(float, input("Enter initial values of x & y (x0 y0): ").split())
    xp = float(input("Enter x at which function to be evaluated: "))
    h = float(input("Enter the step size: "))

    x = x0
    y = y0

    while x < xp:
        y = y + f(x, y) * h
        x += h

    print(f"Function value at x = {xp} is {y}")

if __name__ == "__main__":
    main()
