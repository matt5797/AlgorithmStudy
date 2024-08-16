#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if (a[2] < b[2])
        return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<set<int>> groups;
    
    sort(costs.begin(), costs.end(), comp);
    
    for (auto cost: costs)
    {
        int x1 = -1, x2 = -1;        
        for (int i=0; i<groups.size(); i++)
        {
            if (groups[i].count(cost[0]))
                x1 = i;
            if (groups[i].count(cost[1]))
                x2 = i;
        }
        
        if (x1==-1 && x2==-1) // 없으면 새로운 그룹을 생성
        {
            groups.push_back({cost[0], cost[1]});
            answer = answer + cost[2];
        }
        else if (x1==-1 || x2==-1) // 한 그룹에만 속할 때
        {
            int x = (x1!=-1)? x1: x2;
            groups[x].insert(cost[0]);
            groups[x].insert(cost[1]);
            answer = answer + cost[2];
        }
        else if (x1!=x2) // 연결해서 그룹 병합
        {
            set<int> new_set;
            for (auto v: groups[x1])
                new_set.insert(v);
            for (auto v: groups[x2])
                new_set.insert(v);
            
            if (x1 > x2) {
                groups.erase(groups.begin()+x1);
                groups.erase(groups.begin()+x2);
            } else {
                groups.erase(groups.begin()+x2);
                groups.erase(groups.begin()+x1);
            }
            groups.push_back(new_set);
            
            answer = answer + cost[2];
        }
    }
    
    return answer;
}