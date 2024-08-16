#include <string>
#include <vector>
#include <queue>

using namespace std;

struct comp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        if (a[1]>b[1])
            return true;
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q_jobs(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    vector<int> results;
    
    vector<int> work = {0, 0};
    while (!q_jobs.empty() || !pq.empty())
    {
        while (!q_jobs.empty() && q_jobs.top()[0]==time)
        {
            pq.push(q_jobs.top());
            q_jobs.pop();
        }
        
        if (work[1]==0 && !pq.empty())
        {
            work = pq.top();
            pq.pop();
            results.push_back((time - work[0]) + work[1]);
        }
        
        if (work[1]>0)
            work[1]--;
        time++;
    }
    
    int acc = 0;
    for (auto t: results)
        acc = acc + t;
    
    answer = acc/results.size();
    
    return answer;
}