from itertools import combinations
from collections import Counter

def solution(clothes):
    clothes_dict = dict(Counter(list(zip(*clothes))[1]))
    
    answer = 1  
    
    for value in clothes_dict.values():
        answer *= (value + 1)
        
    return answer - 1