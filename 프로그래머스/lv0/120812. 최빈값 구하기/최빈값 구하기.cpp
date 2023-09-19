#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    int answer, max = 0;
    
    map<int, int> count_map;
    for (int n: array)
        count_map[n]++;
        
    for (auto it=count_map.begin();it!=count_map.end();it++)
    {
        if (max==it->second)
            answer = -1;
        else if (max<it->second)
        {
            answer = it->first;
            max = it->second;
        }
    }
    return answer;
}