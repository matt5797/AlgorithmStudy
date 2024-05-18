# import sys
# sys.stdin = open("input.txt", "r")

T = int(input())

def promising(Queens, row, col):
    for r, c in Queens:
        if c == col or abs(r-row) == abs(c-col):
            return False
    return True

def n_queen(Queens, N):
    row = len(Queens)
    if row == N:
        return 1

    result = 0
    for col in range(N):
        if promising(Queens, row, col):
            result += n_queen(Queens + [(row, col)], N)
    return result


for test_case in range(1, T + 1):
    N = int(input())

    Queens = []

    result = n_queen(Queens, N)

    print("#%d %s" % (test_case, result))
