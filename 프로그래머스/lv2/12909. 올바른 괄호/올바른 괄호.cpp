#include<string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    bool answer = true;
    
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='(') stk.push(s[i]);
        else if (!stk.empty()) stk.pop();
        else answer = false;
    }
    if (!stk.empty()) answer = false;

    return answer;
}