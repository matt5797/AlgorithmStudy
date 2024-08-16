#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

vector<pair<int,int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int id = 1; // 구분자
    map<int, int> m_size; // id:크기
    
    queue<pair<int,int>> q;
    
    for (int n=0; n<land.size(); n++)
    {
        for (int m=0; m<land[0].size(); m++)
        {
            if (land[n][m]==1)
            {
                int size=0, nn, nm;
                id++;
                q.push({n, m});
                land[n][m] = id;
                while (!q.empty())
                {
                    for (auto d: dir)
                    {
                        int nn = q.front().first + d.first;
                        int nm = q.front().second + d.second;
                        if (!(nn<0 || nn>=land.size() || nm<0 || nm>=land[0].size()))
                        {
                            if (land[nn][nm]==1)
                            {
                                q.push({nn, nm});
                                land[nn][nm] = id;
                            }
                        }
                    }
                    size++;
                    q.pop();
                }
                m_size[id] = size;
            }
        }
    }
    
    for (int m=0; m<land[0].size(); m++)
    {
        int acc = 0;
        set<int> temp;
        for (int n = 0; n<land.size(); n++)
            temp.insert(land[n][m]);
        for (auto t: temp)
            acc += m_size[t];
        answer = max(answer, acc);
    }
    
    return answer;
}