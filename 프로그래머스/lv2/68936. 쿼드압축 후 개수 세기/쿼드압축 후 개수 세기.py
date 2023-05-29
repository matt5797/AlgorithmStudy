class DFS:
    def __init__(self):
        self.cnt_0 = 0
        self.cnt_1 = 0
        
    def get_result(self):
        return [self.cnt_0, self.cnt_1]

    def dfs(self, arr):
        # 0이나 1로 통일 되면 각 값을 반환하고 끝낸다
        sum_arr = sum([sum(a) for a in arr])
        if sum_arr==0: 
            self.cnt_0+=1
            return
        if sum_arr==len(arr)**2: 
            self.cnt_1+=1
            return

        # 4개로 쪼개서 재귀
        length = int(len(arr)/2)
        self.dfs([x[:length] for x in arr[:length]])
        self.dfs([x[:length] for x in arr[length:]])
        self.dfs([x[length:] for x in arr[:length]])
        self.dfs([x[length:] for x in arr[length:]])

def solution(arr):
    dfs = DFS()
    dfs.dfs(arr)
    
    return dfs.get_result()