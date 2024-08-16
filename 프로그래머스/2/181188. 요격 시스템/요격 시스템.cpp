#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if (a[1]>b[1])
        return true;
    return false;
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), comp);
    
    int s=0, e=100000000;
    for (auto t: targets)
    {        
        s = max(t[0], s);
        e = min(t[1], e);
        
        if (s>=e)
        {
            answer++;
            s=t[0];
            e=t[1];
        }
    }
    
    return answer;
}