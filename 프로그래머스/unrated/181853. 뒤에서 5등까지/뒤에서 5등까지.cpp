#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(5);
    copy(num_list.begin(), num_list.begin()+5, answer.begin());
    sort(answer.begin(), answer.end());
    
    for (int i=5; i<num_list.size(); i++)
    {
        if (answer.back()>num_list[i])
        {
            answer.pop_back();
            answer.push_back(num_list[i]);
            sort(answer.begin(), answer.end());
        }
    }
    
    return answer;
}