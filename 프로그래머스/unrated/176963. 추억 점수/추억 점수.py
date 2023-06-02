def solution(names, yearning, photo):
    yearning_dic = {n:y for n, y in zip(names, yearning)}
    
    answer = []
    for p in photo:
        acc = 0
        for name in p:
            if name in names:
                acc += yearning_dic[name]
        answer.append(acc)
    
    return answer