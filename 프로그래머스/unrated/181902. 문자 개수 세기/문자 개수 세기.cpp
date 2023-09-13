#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    for (char c: my_string)
    {
        if (c<'a')  answer[c-'A'] += 1;
        else        answer[c-'a'+26] += 1;
    }
    return answer;
}