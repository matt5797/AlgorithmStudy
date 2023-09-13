#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> indexs;
    
    for (int i=0; i<arr.size(); i++)
        if (arr[i]==2) indexs.push_back(i);
    
    if (indexs.size()==0)
        answer.push_back(-1);
    else
    {
        for (int i=indexs.front(); i<=indexs.back(); i++)
            answer.push_back(arr[i]);
    }
    
    return answer;
}