#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int i=1;
    
    while (answer<=n)
    {
        answer *= i;
        i = i + 1;
    }
    
    return i-2;
}