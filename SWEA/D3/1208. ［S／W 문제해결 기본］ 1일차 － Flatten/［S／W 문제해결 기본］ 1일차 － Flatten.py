# import sys
# sys.stdin = open("input.txt", "r")

T = 10

for test_case in range(1, T + 1):
    dump = int(input())
    boxs = list(map(int, input().split()))

    for _ in range(dump):
        boxs = sorted(boxs)
        boxs[0] += 1
        boxs[-1] -= 1

    print("#%d %s" % (test_case, (max(boxs)-min(boxs))))
