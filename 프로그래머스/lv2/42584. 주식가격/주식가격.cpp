#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> stk;
    
    for (int i=0; i<prices.size(); i++)
    {
        while (!stk.empty() && stk.top().second>prices[i])
        {
            answer[stk.top().first] = i - stk.top().first;
            stk.pop();
        }
        stk.push({i, prices[i]});
    }
    while (!stk.empty())
    {
        answer[stk.top().first] = prices.size() - stk.top().first - 1;
        stk.pop();
    }
    
    return answer;
}