import sys

MAX = 100
board = [0] * MAX


def is_safe(row, col):
    for i in range(row):
        if board[i] == col or abs(board[i] - col) == abs(i - row):
            return False
    return True


def solve(row):
    global count
    if row == n:
        print(" ".join(str(board[i] + 1) for i in range(n)))
        count += 1
        return
    for col in range(n):
        if is_safe(row, col):
            board[row] = col
            solve(row + 1)


n = int(sys.stdin.read().split()[0])
count = 0
solve(0)
print(f"Total solutions: {count}")
