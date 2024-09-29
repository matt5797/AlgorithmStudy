#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    map<int, set<int>> neighbors;
    vector<bool> visited(n, false);
    map<int, int> costs;
        
    for (vector<int> road : roads)
    {
        neighbors[--road[0]].insert(--road[1]);
        neighbors[road[1]].insert(road[0]);
    }
    
    for (int source: sources)
        costs[source-1] = -1;
    
    queue<pair<int,int>> q;
    q.push({destination-1, 0});
    visited[destination-1] = true;
    
    while(!q.empty())
    {
        pair<int,int> front = q.front();
        q.pop();
        
        for (int node : sources)
            if (node-1==front.first)
                costs[node-1] = front.second;

        for (int node : neighbors[front.first])
        {
            if (!visited[node])
            {
                visited[node] = true;
                q.push({node, front.second+1});
            }
        }
    }
    
    for (int node: sources)
        answer.push_back(costs[node-1]);
    
    return answer;
}