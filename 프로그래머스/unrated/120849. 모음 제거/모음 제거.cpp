#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    string vowel = "aeiou";
    
    for (char c : my_string)
    {
        if (vowel.find(c) == string::npos)
            answer += c;
    }
    
    return answer;
}