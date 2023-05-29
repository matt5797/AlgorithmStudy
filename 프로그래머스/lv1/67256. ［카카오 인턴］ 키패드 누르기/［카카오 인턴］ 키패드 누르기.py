from math import floor

def distance(_from, to):
    return abs(floor(_from/3) - floor(to/3)) + abs((_from%3) - (to%3))

def solution(numbers, hand):
    hand_pos = [9,11]
    
    answer = ''
    for number in numbers:
        # 몫, 나머지 계산을 위해 -1하고 0은 11로 친다.
        if number==0:
            number = 11
        number -= 1
        if number in [0,3,6]:
            answer += 'L'
        elif number in [2,5,8]:
            answer += 'R'
        else:
            # 양손 거리를 계산
            l, r = distance(hand_pos[0], number), distance(hand_pos[1], number)
            if l<r:
                answer += 'L'
            elif l>r:
                answer += 'R'
            elif hand=='left':
                answer += 'L'
            elif hand=='right':
                answer += 'R'
        
        # 손 위치를 최신화
        if answer[-1] == 'L':
            hand_pos[0] = number
        if answer[-1] == 'R':
            hand_pos[1] = number
    
    return answer