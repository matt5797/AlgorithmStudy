#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    bool flag;
    
    for (int i=l; i<=r; i++)
    {
        flag = true;
        for (char c: to_string(i))
            if (c!='0' && c!='5')
                flag = false;
        if (flag)
            answer.push_back(i);
    }
    
    if (answer.size()==0) answer = {-1};
    return answer;
}