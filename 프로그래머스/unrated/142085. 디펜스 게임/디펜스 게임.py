import heapq

def solution(n, k, enemy):
    heap = []
    for i, e in enumerate(enemy):
        heapq.heappush(heap, -e)
        n -= e
        while (n<0 and k>0 and len(heap)>0):
            n += -heapq.heappop(heap)
            k -= 1
        if n<0:
            i -= 1
            break
    return i+1