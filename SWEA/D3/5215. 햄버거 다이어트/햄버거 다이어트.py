#import sys
#sys.stdin = open("input.txt", "r")

T = int(input())

# L 이하의 칼로리를 사용 하여 낼 수 있는 최고 점수
def solve(n, L, foods, dp):
    # 만약 메모에 이미 있으면 그거 반환
    if dp[n][L] != -1:
        return dp[n][L]
    # 베이스
    if n<=0 or L<=0:
        dp[n][L] = 0
        return dp[n][L]

    # 음식을 선택 하지 않는 경우
    not_take = solve(n-1, L, foods, dp)
    take = 0

    # 칼로리가 남았으면
    if foods[n-1][1] <= L:
        take = foods[n-1][0] + solve(n-1, L-foods[n-1][1], foods, dp)
    dp[n][L] = max(not_take, take)

    # 가장 높은 점수를 반환
    return dp[n][L]

for test_case in range(1, T + 1):
    N, L = map(int, input().split())
    foods = []
    for _ in range(N):
        foods.append(list(map(int, input().split())))

    # n개의 음식 중에서 L 이하의 칼로리로 얻을 수 있는 최고 점수
    dp = [[-1] * (L + 1) for _ in range(N + 1)]
    score = solve(N, L, foods, dp)

    print("#%d %s" % (test_case, score))
