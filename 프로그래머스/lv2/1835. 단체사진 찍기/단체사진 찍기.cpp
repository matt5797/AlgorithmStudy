#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void DFS(vector<char> people, vector<char> result, vector<vector<char>> &results)
{
    if (result.size()>7)
    {
        results.push_back(result);
    }
    else
    {
        vector<char> temp = people;
        for (int i=0; i<people.size(); i++)
        {
            result.push_back(people[i]);
            people.erase(people.begin() + i);
            DFS(people, result, results);
            people.insert(people.begin() + i, result.back());
            result.pop_back();
        }
    }
}

int solution(int n, vector<string> data) {
    vector<char> people = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<vector<char>> results;
    vector<char> result;
    int t1, t2, cnt;
    
    DFS(people, result, results);
    
    int answer = 0;
    for (vector<char> result: results)
    {
        cnt = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<8; j++)
            {
                if (data[i][0]==result[j]) { t1 = j; }
                if (data[i][2]==result[j]) { t2 = j; }
            }
            
            if (data[i][3]=='=' && abs(t1-t2)-1==data[i][4]-'0') { cnt++; }
            else if (data[i][3]=='<' && abs(t1-t2)-1<data[i][4]-'0') { cnt++; }
            else if (data[i][3]=='>' && abs(t1-t2)-1>data[i][4]-'0') { cnt++; }
        }
        if (cnt==n) { answer++; }
    }
    
    return answer;
}