import numpy as np

def lu_decomposition():
    n = int(input("Enter Dimension of Matrix: "))

    a = []
    print("Enter Elements of Matrix:")
    for i in range(n):
        row = list(map(float, input().split()))
        a.append(row)

    a = np.array(a)

    l = np.eye(n)
    u = np.zeros((n, n))

    for j in range(n):
        for i in range(j+1):
            sum_ = 0
            for k in range(i):
                sum_ += l[i][k] * u[k][j]
            u[i][j] = a[i][j] - sum_

        for i in range(j+1, n):
            sum_ = 0
            for k in range(j):
                sum_ += l[i][k] * u[k][j]
            l[i][j] = (a[i][j] - sum_) / u[j][j]

    print("\n********** L Matrix **********")
    for row in l:
        print("\t".join(f"{val:.2f}" for val in row))

    print("\n********** U Matrix **********")
    for row in u:
        print("\t".join(f"{val:.2f}" for val in row))

if __name__ == "__main__":
    lu_decomposition()
