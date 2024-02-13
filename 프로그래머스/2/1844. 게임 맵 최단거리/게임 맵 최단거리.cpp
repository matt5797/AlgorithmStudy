#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    queue<vector<int>> queue;
    queue.push({0,0,1});
    maps[0][0] = 0;
    
    // BFS
    while(queue.size()>0)
    {
        // 맨 앞의 노드를 추출
        auto node = queue.front();
        queue.pop();
        
        // 도착점이면 끝
        if (node[0]==maps.size()-1 && node[1]==maps[0].size()-1) {
            answer = node[2];
            break;
        }
        
        // 추출한 노드 근처의 노드들을 큐에 삽입
        if (node[0]<maps.size()-1 && maps[node[0]+1][node[1]]==1) {
            maps[node[0]+1][node[1]] = 0;
            queue.push({node[0]+1, node[1], node[2]+1});
        }
        if (node[1]<maps[0].size()-1 && maps[node[0]][node[1]+1]==1) {
            maps[node[0]][node[1]+1] = 0;
            queue.push({node[0], node[1]+1, node[2]+1});
        }
        if (node[0]-1>=0 && maps[node[0]-1][node[1]]==1) {
            maps[node[0]-1][node[1]] = 0;
            queue.push({node[0]-1, node[1], node[2]+1});
        }
        if (node[1]-1>=0 && maps[node[0]][node[1]-1]==1) {
            maps[node[0]][node[1]-1] = 0;
            queue.push({node[0], node[1]-1, node[2]+1});
        }
    }
    
    return answer;
}