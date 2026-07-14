def linear_regression():
    n = int(input("Enter the number of data points: "))
    
    x = []
    y = []
    sx = sy = sxy = sx2 = 0
    
    print("Enter the value of x and fx: ")
    for i in range(n):
        xi, yi = map(float, input().split())
        x.append(xi)
        y.append(yi)
    
    for i in range(n):
        sx += x[i]
        sy += y[i]
        sxy += x[i] * y[i]
        sx2 += x[i] * x[i]
    
    b = (n * sxy - sx * sy) / (n * sx2 - sx * sx)
    a = (sy / n) - (b * sx / n)
    
    print(f"Fitted line is: {a} + {b}x")

if __name__ == "__main__":
    linear_regression()
