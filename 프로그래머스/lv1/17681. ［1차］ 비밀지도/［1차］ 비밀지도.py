def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        arr = "".join(['#' if x=='1' else ' ' for x in format((arr1[i] | arr2[i]), 'b')])
        arr = ' ' * (n - len(arr)) + arr
        answer.append(arr)
    
    return answer