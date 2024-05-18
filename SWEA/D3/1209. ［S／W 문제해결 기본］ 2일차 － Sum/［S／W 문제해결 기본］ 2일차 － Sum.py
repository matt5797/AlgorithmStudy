#import sys
#sys.stdin = open("input.txt", "r")

T = 10

for test_case in range(1, T + 1):
    _ = input()
    Map = [list(map(int, input().split())) for _ in range(100)]

    row_acc = [0] * 100
    col_acc = [0] * 100
    cross_acc1 = 0
    cross_acc2 = 0

    # 전부 돌고, 해당하는 행, 열 누적기에 누적
    for i, row in enumerate(Map):
        for j, cell in enumerate(row):
            row_acc[i] += cell
            col_acc[j] += cell
            if i==j:
                cross_acc1 += cell
            if (99-i) == j:
                cross_acc2 += cell

    max_value = max(max(row_acc), max(col_acc), cross_acc1, cross_acc2)

    print("#%d %d" % (test_case, max_value))
