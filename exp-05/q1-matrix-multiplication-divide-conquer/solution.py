def sub_matrix(M, r0, c0, size):
    return [row[c0:c0 + size] for row in M[r0:r0 + size]]


def put_quad(S, M, r0, c0):
    size = len(S)
    for i in range(size):
        for j in range(size):
            M[r0 + i][c0 + j] = S[i][j]


def add_mat(A, B):
    n = len(A)
    return [[A[i][j] + B[i][j] for j in range(n)] for i in range(n)]


def mat_mul(A, B, n):
    if n == 1:
        return [[A[0][0] * B[0][0]]]
    s = n // 2
    A11 = sub_matrix(A, 0, 0, s)
    A12 = sub_matrix(A, 0, s, s)
    A21 = sub_matrix(A, s, 0, s)
    A22 = sub_matrix(A, s, s, s)
    B11 = sub_matrix(B, 0, 0, s)
    B12 = sub_matrix(B, 0, s, s)
    B21 = sub_matrix(B, s, 0, s)
    B22 = sub_matrix(B, s, s, s)

    M1 = mat_mul(A11, B11, s)
    M2 = mat_mul(A12, B21, s)
    M3 = mat_mul(A11, B12, s)
    M4 = mat_mul(A12, B22, s)
    M5 = mat_mul(A21, B11, s)
    M6 = mat_mul(A22, B21, s)
    M7 = mat_mul(A21, B12, s)
    M8 = mat_mul(A22, B22, s)

    C11 = add_mat(M1, M2)
    C12 = add_mat(M3, M4)
    C21 = add_mat(M5, M6)
    C22 = add_mat(M7, M8)

    C = [[0] * n for _ in range(n)]
    put_quad(C11, C, 0, 0)
    put_quad(C12, C, 0, s)
    put_quad(C21, C, s, 0)
    put_quad(C22, C, s, s)
    return C


n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(n)]
C = mat_mul(A, B, n)
for row in C:
    print(" ".join(map(str, row)))
