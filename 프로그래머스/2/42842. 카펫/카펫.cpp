#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    int nm = 0; // n + m을 의미
    
    nm = (brown + 4)/2; // 테두리의 수로부터 n+m을 구함
        
    for (int m=(nm/2); m>=3; m--) // 경우의 수 완전탐색
    {
        int n = nm-m;
        
        if ((n-2) * (m-2) == yellow)
        {
            answer[0] = n;
            answer[1] = m;
        }
    }
    
    return answer;
}