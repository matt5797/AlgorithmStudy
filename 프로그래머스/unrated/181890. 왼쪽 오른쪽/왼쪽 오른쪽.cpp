#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    for (auto iter=str_list.begin(); iter!=str_list.end(); iter++)
    {
        if (*iter=="r")
        {
            answer.resize(str_list.end()-(++iter));
            copy((iter), str_list.end(), answer.begin());
            break;
        }
        else if (*iter=="l")
        {
            answer.resize(iter-str_list.begin());
            copy(str_list.begin(), iter, answer.begin());
            break;
        }
    }
    return answer;
}