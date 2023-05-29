def solution(dartResult):
    nums = [str(i) for i in range(11)]
    bonus = ('S', 'D', 'T')
    options = ('*', '#')
    
    for r in bonus+options:
        dartResult = dartResult.replace(r, " %s " % r)
    dartResult = dartResult.split()
    
    answer = []
    for res in dartResult:
        if res in nums:
            answer.append(int(res))
        elif res in bonus:
            answer[-1] **= bonus.index(res) + 1
        elif res in options:
            if res == options[0]:
                if len(answer)>0: answer[-1] *= 2
                if len(answer)>1: answer[-2] *= 2
            elif res == options[1]:
                answer[-1] *= -1
    
    return sum(answer)