def horner_method():
    n = int(input("Enter degree of polynomial: "))
    a = [0] * (n + 1)
    
    print("Enter coefficients of the dividend polynomial:")
    for i in range(n, -1, -1):
        a[i] = float(input(f"Enter coefficient for x^{i}: "))
    
    x = float(input("Enter the value at which polynomial to be evaluated: "))
    
    result = a[n]
    for i in range(n - 1, -1, -1):
        result = result * x + a[i]
    
    print(f"Value of polynomial p({x}) = {result}")

horner_method()
