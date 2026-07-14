def func(x):
    return x * x  # Example function: f(x) = x^2

def main():
    x = float(input("Enter the point x: "))
    h = float(input("Enter the step size h: "))

    forward = (func(x + h) - func(x)) / h
    backward = (func(x) - func(x - h)) / h

    print(f"Forward Difference Approximation: {forward:.4f}")
    print(f"Backward Difference Approximation: {backward:.4f}")

if __name__ == "__main__":
    main()
