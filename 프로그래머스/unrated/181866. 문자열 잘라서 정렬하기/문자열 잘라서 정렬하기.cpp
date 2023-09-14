#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    int last = 0;
    
    for (int i=0; i<myString.size(); i++)
    {
        if (i>0 && myString[i]=='x' && myString[i-1]!='x')
        {
            answer.push_back(myString.substr(last, i-last));
            last = i + 1;
        }
        else if (myString[i]=='x') last = i + 1;
    }
    
    if (myString.size()-last>0)
        answer.push_back(myString.substr(last, myString.size()-last));
    sort(answer.begin(), answer.end());
    
    return answer;
}