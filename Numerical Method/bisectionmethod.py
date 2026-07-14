def f(x, a3, a2, a1, a0):
    return (a3 * x**3 + a2 * x**2 + a1 * x + a0)

def bisection_method():
    a3, a2, a1, a0 = map(float, input("Enter the coefficients (a3, a2, a1, a0): ").split())
    xn, xp = map(float, input("Enter two initial guesses (xn xp): ").split())
    fxn = f(xn, a3, a2, a1, a0)
    fxp = f(xp, a3, a2, a1, a0)
    print(f"f(xn) = {fxn}, f(xp) = {fxp}")
    Ea = float(input("Enter the allowed error: "))
    if fxn * fxp < 0:
        while True:
            xr = (xn + xp) / 2.0
            fxr = f(xr, a3, a2, a1, a0)
            print(f"xn = {xn}, xp = {xp}, xr = {xr}, f(xr) = {fxr}")
            if fxn * fxr < 0:
                xp = xr
                fxp = fxr
            else:
                xn = xr
                fxn = fxr
            E0 = abs(xp - xn)
            if E0 <= Ea:
                break
        print(f"The root is approximately: {xr}")
    else:
        print("Invalid initial guesses. f(xn) and f(xp) must have opposite signs.")

bisection_method()
