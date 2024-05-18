#import sys
#sys.stdin = open("input.txt", "r")

T = int(input())

for test_case in range(1, T + 1):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    # dp[i] : i를 만들 수 있는 수열의 수
    dp = [0] * (K+1)
    dp[0] = 1

    for a in A:
        for i in range(K, a-1, -1):
            dp[i] += dp[i-a]

    print("#%d %d" % (test_case, dp[K]))
