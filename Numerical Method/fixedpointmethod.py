def G(x, a3, a2, a1, a0):
    return (a3 * x**3 + a2 * x**2 + a1 * x + a0) / (-a1)

def fixed_point_iteration():
    a3, a2, a1, a0 = map(float, input("Enter coefficients a3, a2, a1 and a0: ").split())
    x0, E = map(float, input("Enter initial guess and E: ").split())
    
    while True:
        x1 = G(x0, a3, a2, a1, a0)
        Er = abs((x1 - x0) / x1)
        
        if Er < E:
            print(f"Root = {x1}")
            break
        
        x0 = x1

fixed_point_iteration()
