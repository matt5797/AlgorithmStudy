#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer(my_string.rbegin(), my_string.rend());
    return answer;
}