from itertools import combinations, permutations, product

def solution(users, emoticons):
    discounts = [10, 20, 30, 40]
    discount_cases = list(product(*[discounts for _ in range(len(emoticons))]))
    
    answer = [0,0]
    for case in discount_cases:
        temp_answer = [0,0]
        for user in users:
            cost = 0
            for i, emoticon in enumerate(emoticons):
                if user[0] <= case[i]:
                    cost += int(emoticon*(100-case[i])/100)
            if cost >= user[1]:
                temp_answer[0] += 1
            else:
                temp_answer[1] += cost
        if temp_answer[0]>answer[0]:
            answer = temp_answer
        elif temp_answer[0]==answer[0] and temp_answer[1]>answer[1]:
            answer = temp_answer
    
    return answer