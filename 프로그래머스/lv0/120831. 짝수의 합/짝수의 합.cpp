#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    n = (n%2==0)? n: n-1;
    for (int i=n; i>1; i-=2)
        answer += i;
    return answer;
}