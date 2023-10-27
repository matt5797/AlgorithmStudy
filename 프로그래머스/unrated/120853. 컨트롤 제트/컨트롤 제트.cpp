#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int l=0, r=0;
    
    for (int i=1; i<=s.size(); i++)
    {
        if (s[i]==' ' || i==s.size())
        {
            if (s[i-1]=='Z')
            {
                answer -= stoi(s.substr(l, r-l));
                l = r;
                r = i;
            }
            else
            {
                answer += stoi(s.substr(r, i-l));
                l = r;
                r = i;
            }
        }
    }
    
    return answer;
}