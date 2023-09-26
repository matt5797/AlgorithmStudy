#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> emergency) {
    map<int, int> answer_map;
    vector<int> answer;
    
    for (int i=0; i<emergency.size(); i++)
        answer_map[emergency[i]] = i;
    for (auto it=answer_map.begin(); it!=answer_map.end(); it++)
        answer.push_back(answer_map.size() - (it->second));
    
    return answer;
}