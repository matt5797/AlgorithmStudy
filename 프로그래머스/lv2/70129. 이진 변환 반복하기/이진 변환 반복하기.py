def solution(s):
    answer = [0, 0]
    
    while (s!="1"):
        length = len(s)
        s = "".join([c for c in s if c=='1'])
        length -= len(s)
        s = format(int(len(s)), 'b')
        
        answer = [answer[0] + 1, answer[1] + length]
    
    return answer
