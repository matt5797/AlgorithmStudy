#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    vector<int>::iterator iter;
    
    for (int i=0; i<arr.size(); i++)
    {
        if (answer.size()>=k) break;
        
        iter = find(answer.begin(), answer.end(), arr[i]);
        if (iter==answer.end())
            answer.push_back(arr[i]);
    }
    
    for (int i=answer.size(); i<k; i++)
        answer.push_back(-1);
    
    return answer;
}