def solution(genres, plays):
    answer = []
    res = dict()
    total = dict()
    for i in range(len(genres)):
        if (genres[i] not in res.keys()):
            total[genres[i]] = plays[i]
            res[genres[i]] = {i: plays[i]}
        else:
            total[genres[i]] += plays[i]
            res[genres[i]][i] = plays[i]
    total = sorted(total.items(), key = lambda item: item[1], reverse = True)
    for genre, _ in total:
        items = sorted(res[genre].items(), key = lambda item: (item[1], -item[0]), reverse = False)
        answer.append(items.pop()[0])
        if (len(items)>0):
            answer.append(items.pop()[0])
    return answer