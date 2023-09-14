#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    int last = 0;
    for (int i=0; i<my_string.size(); i++)
    {
        if (my_string[i]==' ')
        {
            answer.push_back(my_string.substr(last, i-last));
            last = i+1;
        }
    }
    answer.push_back(my_string.substr(last, my_string.size()));
    return answer;
}