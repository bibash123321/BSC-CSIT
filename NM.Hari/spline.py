import math

def cubic_spline_interpolation():
    n = int(input("Enter Number of Points: \n"))
    x = []
    fx = []
    for i in range(n):
        xi, fxi = map(float, input(f"Enter x[{i}] and fx[{i}]: ").split())
        x.append(xi)
        fx.append(fxi)

    xp = float(input("Enter Interpolation Point: "))

    h = [0] * (n - 1)
    b = [0] * (n - 1)
    u = [0] * (n - 1)
    v = [0] * (n - 1)
    m = [[0] * (n - 1) for _ in range(n - 1)]
    r = [0] * (n - 1)
    e = [0] * (n - 1)

    for i in range(n - 1):
        h[i] = x[i + 1] - x[i]
        b[i] = (fx[i + 1] - fx[i]) / h[i]

    for i in range(1, n - 1):
        u[i] = 2 * (h[i - 1] + h[i])
        v[i] = 6 * (b[i] - b[i - 1])

    for i in range(1, n - 1):
        m[i][i] = u[i]
        if i != 1:
            m[i][i - 1] = h[i - 1]
            m[i - 1][i] = h[i - 1]
        r[i] = v[i]

    for k in range(1, n - 2):
        pivot = m[k][k]
        if pivot < 0.000001:
            print("Method failed: pivot too small")
            return
        else:
            for i in range(k + 1, n - 1):
                factor = m[i][k] / pivot
                for j in range(k, n - 1):
                    m[i][j] -= m[k][j] * factor
                r[i] -= r[k] * factor

    e[n - 2] = r[n - 2] / m[n - 2][n - 2]
    for i in range(n - 3, 0, -1):
        sum_ = 0
        for j in range(i + 1, n - 1):
            sum_ += m[i][j] * e[j]
        e[i] = (r[i] - sum_) / m[i][i]

    for i in range(n - 1):
        if xp <= x[i + 1]:
            xp_index = i
            break

    val = (e[xp_index + 1] / (6 * h[xp_index]) * (xp - x[xp_index])**3) + \
          (e[xp_index] / (6 * h[xp_index]) * (x[xp_index + 1] - xp)**3) + \
          (((fx[xp_index + 1] / h[xp_index]) - (e[xp_index + 1] * h[xp_index] / 6)) * (xp - x[xp_index])) + \
          (((fx[xp_index] / h[xp_index]) - (e[xp_index] * h[xp_index] / 6)) * (x[xp_index + 1] - xp))

    print(f"Interpolated Value = {val}")

if __name__ == "__main__":
    cubic_spline_interpolation()
