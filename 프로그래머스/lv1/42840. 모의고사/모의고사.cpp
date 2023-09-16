#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    map<int, int> scores = {{1,0}, {2,0}, {3,0}};
    vector<vector<int>> students = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    
    for (int i=0; i<answers.size(); i++)
    {
        if (students[0][(i % students[0].size())]==answers[i])
            scores[1]++;
        if (students[1][(i % students[1].size())]==answers[i])
            scores[2]++;
        if (students[2][(i % students[2].size())]==answers[i])
            scores[3]++;
    }
    
    int max = 0;
    for (int i=1; i<=3; i++)
        if (max<scores[i]) max = scores[i];
    
    for (int i=1; i<=3; i++)
        if (max==scores[i]) answer.push_back(i);
        
    return answer;
}