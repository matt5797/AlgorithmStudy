#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int age) {
    string answer = to_string(age);
    for (int i=0; i<answer.size(); i++)
        answer[i] = 'a' + (answer[i]-'0');
    return answer;
}