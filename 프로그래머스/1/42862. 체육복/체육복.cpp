#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> cnt(n, 1);
    
    for (auto iter=lost.begin(); iter!=lost.end(); iter++)
        cnt[*iter-1] -= 1;
    for (auto iter=reserve.begin(); iter!=reserve.end(); iter++)
        cnt[*iter-1] += 1;
    
    for (auto iter=cnt.begin(); iter!=cnt.end(); iter++)
    {
        if (*iter>0)
            continue;
        if (iter!=cnt.begin() && *prev(iter)>1)
        {
            *prev(iter) -= 1;
            *iter += 1;
        }
        else if (next(iter)!=cnt.end() && *next(iter)>1)
        {
            *next(iter) -= 1;
            *iter += 1;
        }
    }
    
    for (auto iter=cnt.begin(); iter!=cnt.end(); iter++)
        if (*iter>0)
            answer += 1;
    
    return answer;
}