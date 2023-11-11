#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> _map;
    
    for (int i=0; i<s.size(); i++)
    {
        _map[s[i]]++;
    }
    
    for (auto iter=_map.begin(); iter!=_map.end(); iter++)
    {
        if (iter->second==1)
            answer += iter->first;
    }
    
    return answer;
}