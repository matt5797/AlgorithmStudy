def solution(citations):
    citations.sort(reverse=True)
    
    h_min, h_max = 0, 0
    for i, j in enumerate(citations):
        if (i+1>=j):
            h_min = j
            break
        h_max = j
    
    for i in range(h_max, h_min-1, -1):
        if len(citations)>=i and citations[i-1] >= i:
            return i