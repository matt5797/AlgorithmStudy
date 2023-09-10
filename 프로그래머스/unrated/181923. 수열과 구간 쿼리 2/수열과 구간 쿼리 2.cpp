#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    int min;
    
    for (vector<int> query: queries)
    {
        min = 1000000;
        for (int i=query[0]; i<=query[1]; i++)
        {
            if (arr[i]>query[2] && arr[i]<min)
            {
                min = arr[i];
            }
        }
        if (min==1000000) answer.push_back(-1);
        else answer.push_back(min);
    }
    
    return answer;
}