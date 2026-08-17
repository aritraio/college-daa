import sys

MAX = 100
s = [[0] * MAX for _ in range(MAX)]


def print_order(i, j):
    if i == j:
        print(f"A{i}", end="")
        return
    print("(", end="")
    print_order(i, s[i][j])
    print_order(s[i][j] + 1, j)
    print(")", end="")


def main():
    data = list(map(int, sys.stdin.read().split()))
    n = data[0]
    p = data[1:n + 2]
    m = [[0] * MAX for _ in range(MAX)]

    for length in range(2, n + 1):
        for i in range(1, n - length + 2):
            j = i + length - 1
            m[i][j] = float("inf")
            for k in range(i, j):
                cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if cost < m[i][j]:
                    m[i][j] = cost
                    s[i][j] = k

    print(f"Minimum cost: {m[1][n]}")
    print("Optimal parenthesization: ", end="")
    print_order(1, n)
    print()


if __name__ == "__main__":
    main()
