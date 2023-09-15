#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    map<int, int> answer;
    
    for (int i=0; i<rank.size(); i++)
        if (attendance[i])
            answer[rank[i]] = i;
    
    return 10000 * answer.begin()->second + 100 * next(answer.begin(), 1)->second + next(answer.begin(), 2)->second;
}