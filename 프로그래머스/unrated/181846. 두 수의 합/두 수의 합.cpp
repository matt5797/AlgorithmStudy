#include <string>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    int x, y, left = 0;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    for (int i=0; i<max(a.size(), b.size()); i++)
    {
        x = (i<a.size())? a[i]-'0': 0;
        y = (i<b.size())? b[i]-'0': 0;
        
        answer += to_string((x+y+left) % 10);
        left = ((x+y+left) / 10);
    }
    if (left>0) answer += to_string(left);
    
    reverse(answer.begin(), answer.end());    
        
    return answer;
}