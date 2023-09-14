#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    string queue = "";
    
    for (int i=0; i<myStr.size(); i++)
    {
        if (myStr[i]=='a' || myStr[i]=='b' || myStr[i]=='c')
        {
            if (queue.size()>0) answer.push_back(queue);
            queue = "";
        }
        else
            queue += myStr[i];
    }
    if (queue.size()>0) answer.push_back(queue);
    else answer = {"EMPTY"};
    
    return answer;
}