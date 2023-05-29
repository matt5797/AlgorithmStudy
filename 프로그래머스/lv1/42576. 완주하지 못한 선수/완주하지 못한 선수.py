def solution(participant, completion):
    hash = dict().fromkeys(participant)
    answer = ""
    for person in participant:
        hash[person] = 0
    for person in participant:
        if hash[person]:
            hash[person] += 1
        else:
            hash[person] = 1
    for person in completion:
        hash[person] -= 1
    for person in hash.items():
        if person[1]>0:
            answer = person[0]
    return answer