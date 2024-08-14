#include <string>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> dungeons, vector<bool> visit, int k)
{
    vector<int> results;
    for (int i=0; i<visit.size(); i++)
    {
        if (!visit[i] && (k>=dungeons[i][0]))
        {
            visit[i] = true;
            results.push_back(dfs(dungeons, visit, k-dungeons[i][1]));
            visit[i] = false;
        }
    }
    
    int max = 0;
    for (int n : results)
    {
        if (n>max)
            max = n;
    }
    
    if (max==0)
    {
        for (bool v: visit)
            if (v)
                max += 1;
    }
    
    return max;
}

int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = -1;
    
    vector<bool> visit(dungeons.size(), false);
    
    answer = dfs(dungeons, visit, k);
    
    return answer;
}