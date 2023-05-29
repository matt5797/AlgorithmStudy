lenght = input()

players = []
for _ in range(int(lenght)):
    players.append(input())

players_dict = {x[0]:0 for x in players}
for player in players:
    players_dict[player[0]] += 1

players_list = [x for x in players_dict if players_dict[x] >= 5]
players_list.sort()

if len(players_list) == 0:
    print("PREDAJA")
else:
    print("".join(players_list))