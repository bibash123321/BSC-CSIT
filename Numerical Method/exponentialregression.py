import math

def exponential_regression():
    n = int(input("Enter the number of data points: "))
    
    x = []
    y = []
    sx = slgy = sxy = sx2 = 0
    
    print("Enter the value of x and fx: ")
    for i in range(n):
        xi, yi = map(float, input().split())
        x.append(xi)
        y.append(yi)
    
    for i in range(n):
        sx += x[i]
        slgy += math.log(y[i])
        sxy += x[i] * math.log(y[i])
        sx2 += x[i] * x[i]
    
    b = (n * sxy - sx * slgy) / (n * sx2 - sx * sx)
    r = (slgy / n) - (b * sx / n)
    a = math.exp(r)
    
    print(f"Fitted line is: {a} * e^({b}x)")

if __name__ == "__main__":
    exponential_regression()
