#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string queue = "";
    
    for (int i=0; i<my_string.size(); i++)
    {
        if (my_string[i]==' ' && queue.size()>0)
        {
            answer.push_back(queue);
            queue = "";
        }
        if (my_string[i]!=' ')
            queue += my_string[i];
    }
    if (queue.size()>0) answer.push_back(queue);
    
    return answer;
}