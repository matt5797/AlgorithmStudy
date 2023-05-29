#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int same = 0;   // 같은 경우 카운트
    int diff = 0;   // 다른 경우 카운트
    
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]==s[0])
            same++;
        else
            diff++;
        
        if (same==diff)
        {
            s = s.substr(i+1);
            i = -1;
            answer++;
        }
    }
    
    if (!s.empty())
        answer++;
    
    return answer;
}