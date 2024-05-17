# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, 10 + 1):
    N = int(input())
    buildings = list(map(int, input().split()))

    count = 0

    for i in range(2, N-2):
        nears = buildings[i - 2:i + 3]
        nears.remove(buildings[i])
        m = max(nears)
        if (buildings[i]>m):
            count += buildings[i] - m

    print("#%d %d" % (test_case, count))
