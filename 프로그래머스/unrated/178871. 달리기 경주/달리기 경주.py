
def solution(players, callings):
    d_player = {player:rank for rank, player in enumerate(players)}
    d_rank = {rank:player for rank, player in enumerate(players)}
    
    for call in callings:
        i, j = d_player[call], d_rank[d_player[call]-1]
        d_player[call], d_player[j] = d_player[j], d_player[call]
        d_rank[i-1], d_rank[i] = d_rank[i], d_rank[i-1]
    
    return [x for x in d_rank.values()]
