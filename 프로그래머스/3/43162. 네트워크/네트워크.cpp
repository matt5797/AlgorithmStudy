#include <string>
#include <vector>
#include <iostream>

using namespace std;

void checkGroup(vector<vector<int>> computers, vector<int>& checks, int vertex)
{
    checks[vertex] = 1;
    for (int i=0; i<computers[vertex].size(); i++)
    {
        if (computers[vertex][i]==1 and checks[i]==0)
        {
            checkGroup(computers, checks, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> checks = vector<int>(computers.size());
    
    for (int i=0; i<checks.size(); i++)
    {
        if (checks[i]==0)
        {
            checkGroup(computers, checks, i);
            answer++;
        }
    }
    
    return answer;
}