from itertools import product

def solution(numbers, target):
    #print([x for x in list(product(*zip(numbers, [-x for x in numbers]))) if sum(x)==target])
    return len([x for x in list(product(*zip(numbers, [-x for x in numbers]))) if sum(x)==target])