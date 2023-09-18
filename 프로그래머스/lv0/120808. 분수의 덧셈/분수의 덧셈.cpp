#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    answer.push_back((numer1*denom2)+(numer2*denom1));
    answer.push_back(denom1 * denom2);
    
    for (int i=2; i<=denom1 * denom2; i++)
    {
        while ((answer[0]%i==0) && (answer[1]%i==0))
        {
            answer[0] /= i;
            answer[1] /= i;
        }
    }
    
    return answer;
}