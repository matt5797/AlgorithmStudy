#import sys
#sys.stdin = open("input.txt", "r")

T = int(input())


def is_same(source_bit, target_bit):
    flag = source_bit[0] == target_bit[0]
    for i in range(1, len(source_bit)):
        if (source_bit[i] == target_bit[i]) != flag:
            return False
    return True


for test_case in range(1, T + 1):
    target_bit = [True if x == "1" else False for x in input()]
    N = len(target_bit)
    source_bit = [False] * N
    count = 0

    for i in range(N-1, -1, -1):
        if not is_same(source_bit[i:], target_bit[i:]):
            for j in range(i + 1, N):
                source_bit[j] = not source_bit[j]
            count += 1

    if source_bit[0] != target_bit[0]:
        count += 1

    print("#%d %d" % (test_case, count))
