#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n);
    vector<pair<int,int>> dir = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    int index = 0;
    int x = -1, y = 0;
    int nx, ny;
    
    for (int i=0; i<n; i++) answer[i] = vector<int>(n);
    
    for (int i=1; i<=n*n; )
    {
        nx = x + dir[index].first;
        ny = y + dir[index].second;
        
        if (nx>=0 && nx<n && ny>=0 && ny<n && answer[ny][nx]==0)
        {
            x = nx;
            y = ny;
            answer[y][x] = i++;
        }
        else
            index = (++index % dir.size());
    }
    
    return answer;
}