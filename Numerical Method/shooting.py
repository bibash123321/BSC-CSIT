import math

def fl(x, y, z):
    return z

def fz(x, y, z):
    return 6 * x

def main():
    xa, ya, xb, yb = map(float, input("Enter Boundary Conditions (xa ya xb yb): ").split())
    xp = float(input("Enter x at which value is required: "))
    h = float(input("Enter the step size: "))
    E = float(input("Enter accuracy limit: "))

    iteration = 0
    g = [0, 0, 0]
    v = [0, 0, 0]

    g[1] = z = (yb - ya) / (xb - xa)
    print(f"Initial guess for z = {g[1]}")

    x = xa
    y = ya
    while x < xb + 1e-6:
        ny = y + fl(x, y, z) * h
        nz = z + fz(x, y, z) * h
        x = x + h
        y = ny
        z = nz

        if abs(x - xp) < 1e-6:
            sol = y

    v[1] = y

    g[2] = g[1] + 0.1
    print(f"Second guess for z = {g[2]}")

    x = xa
    y = ya
    z = g[2]
    while x < xb + 1e-6:
        ny = y + fl(x, y, z) * h
        nz = z + fz(x, y, z) * h
        x = x + h
        y = ny
        z = nz

        if abs(x - xp) < 1e-6:
            sol = y

    v[2] = y

    while True:
        iteration += 1
        x = xa
        y = ya
        z = g[2] - (v[2] - yb) / (v[2] - v[1]) * (g[2] - g[1])

        while x < xb + 1e-6:
            ny = y + fl(x, y, z) * h
            nz = z + fz(x, y, z) * h
            x = x + h
            y = ny
            z = nz

            if abs(x - xp) < 1e-6:
                sol = y

        error = abs(y - yb) / abs(yb)
        print(f"Iteration {iteration}: y = {y}, error = {error}")

        if error < E:
            print(f"Converged! y({xp}) = {sol}")
            break

        v[1] = v[2]
        g[1] = g[2]
        v[2] = y
        g[2] = z

        if iteration > 100:
            print("Warning: Maximum iterations reached. Solution may not have converged.")
            break

if __name__ == "__main__":
    main()
