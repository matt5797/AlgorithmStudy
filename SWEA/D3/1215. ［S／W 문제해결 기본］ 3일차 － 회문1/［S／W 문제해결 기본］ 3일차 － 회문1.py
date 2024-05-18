#import sys
#sys.stdin = open("input.txt", "r")

T = 10

for test_case in range(1, T + 1):
    N = int(input())
    Map = [[x for x in input()] for _ in range(8)]

    count = 0
    
    for i in range(8):
        for j in range(8-N+1):
            flags = [True, True]
            for k in range(N):
                if flags[0] and Map[i][j+k] != Map[i][j+N-k-1]:
                    flags[0] = False
                if flags[1] and Map[j+k][i] != Map[j+N-k-1][i]:
                    flags[1] = False
            if flags[0]:
                count += 1
            if flags[1]:
                count += 1

    print("#%d %d" % (test_case, count))
