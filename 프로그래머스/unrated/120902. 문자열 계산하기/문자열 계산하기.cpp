#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    char op = '.';
    string temp = "";
        
    for (char c : my_string)
    {
        if (isdigit(c))
            temp.push_back(c);
        else if (c!=' ')
        {
            if (op=='.')
                answer = stoi(temp);
            if (op=='+')
                answer += stoi(temp);
            if (op=='-')
                answer -= stoi(temp);
            if (c=='+')
                op = '+';
            if (c=='-')
                op = '-';
            temp.clear();
        }
    }
    if (op=='+')
        answer += stoi(temp);
    if (op=='-')
        answer -= stoi(temp);
    
    return answer;
}