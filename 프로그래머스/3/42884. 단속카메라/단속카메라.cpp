#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int start=-30000, end=30000;
    
    sort(routes.begin(), routes.end());
    
    for (int i=0; i<routes.size(); i++)
    {
        if (routes[i][1]<start || end<routes[i][0]) // 수용 불가능
        {
            answer++;
            start=routes[i][0];
            end=routes[i][1];
        }
        else // 수용 가능
        {
            start = max(start, routes[i][0]);
            end = min(end, routes[i][1]);
        }
    }
    
    return answer;
}