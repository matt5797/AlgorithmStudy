#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int denom;
    
    if (denom1%denom2==0)
        denom = denom1;
    else if (denom2%denom1==0)
        denom = denom2;
    else
        denom = denom1 * denom2;
    
    answer.push_back((numer1*(denom/denom1))+(numer2*(denom/denom2)));
    answer.push_back(denom);
    
    for (int i=2; i<=denom; i++)
    {
        while ((answer[0]%i==0) && (answer[1]%i==0))
        {
            answer[0] /= i;
            answer[1] /= i;
        }
    }
    
    return answer;
}