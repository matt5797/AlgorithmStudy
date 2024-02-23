#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void DFS(vector<vector<string>> tickets, vector<string> route, vector<string>& result) {
    vector<vector<string>> temp;
    
    if (tickets.size()==0 && result.size()<2)
        result = route;
    
    for (int i=0; i<tickets.size(); i++) {
        if (tickets[i][0]==route.back()) {
            temp = tickets;
            temp.erase(temp.begin()+i);
            route.push_back(tickets[i][1]);
            DFS(temp, route, result);
            route.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer = {"ICN"};
    
    sort(tickets.begin(), tickets.end());
    
    for (int i=0;i<tickets.size();i++) {
        cout << tickets[i][0] << ", " << tickets[i][1] << endl;
    }
    
    DFS(tickets, answer, answer);
    
    return answer;
}
