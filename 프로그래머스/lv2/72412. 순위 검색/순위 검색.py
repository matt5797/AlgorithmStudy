from itertools import product
from bisect import bisect_left

def solution(info, query):
    info = [x.split() for x in info]
    info = [x[:-1] + [int(x[-1])] for x in info]
    info = sorted(info, key=lambda x: x[-1])
    
    query = [x.split(" and ") for x in query]
    query = [x[:-1] + x[-1].split() for x in query]
    query = [x[:-1] + [int(x[-1])] for x in query]
    
    template = [['cpp', 'java', 'python', '-'], ['backend', 'frontend', '-'], ['junior', 'senior', '-'], ['chicken', 'pizza', '-']]
    template = list(product(*template))
    template = {"".join(x):[] for x in template}
    
    for i in info:
        for x in list(product(*[[i[0], '-'], [i[1], '-'], [i[2], '-'], [i[3], '-']])):
            index = "".join(x)
            if index not in template.keys():
                template[index] = [i[4]]
            else:
                template[index].append(i[4])
    
    answer = []
    for q in query:
        scores = template[q[0] + q[1] + q[2] + q[3]]
        answer.append(len(scores) - bisect_left(scores, q[4]))
    
    return answer