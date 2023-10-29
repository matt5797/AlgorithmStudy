#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n) {
    set<int> s;
    int m = n;
    
    for (int i=2; i<=m; i++)
    {
        if (n%i==0)
        {
            s.insert(i);
            n = n / i--;
        }
    }
    
    vector<int> answer(s.begin(), s.end());
    
    return answer;
}