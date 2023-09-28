#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    long long answer = 1;
    int j = 1;
    
    for (int i=share+1; i<=balls; i++)
    {
        if (j<=(balls-share))
            answer = answer * i / j++;
        else
            answer = answer * i;
    }
    
    return answer;
}