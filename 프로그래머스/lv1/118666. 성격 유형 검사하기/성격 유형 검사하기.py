def solution(survey, choices):
    types = (('R', 'T'), ('C', 'F'), ('J', 'M'), ('A', 'N'))
    score = {x:0 for t in types for x in t}
    
    for s, c in zip(survey, choices):
        if (c-4)<0:
            score[s[0]] += abs(c-4)
        else:
            score[s[1]] += abs(c-4)
    
    answer = ''
    for t in types:
        if score[t[0]] >= score[t[1]]:
            answer += t[0]
        else:
            answer += t[1]
    return answer
