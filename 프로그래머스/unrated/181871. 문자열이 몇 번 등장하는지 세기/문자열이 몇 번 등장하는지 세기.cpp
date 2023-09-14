#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    bool flag;
    for (int i=0; i<myString.size(); i++)
    {
        flag = true;
        for (int j=0; j<pat.size(); j++)
            if (myString[i+j]!=pat[j])
                flag = false;
        if (flag)
            answer++;
    }
    return answer;
}