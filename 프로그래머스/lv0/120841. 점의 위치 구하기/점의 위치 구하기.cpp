#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 0;
    if (dot[0]>0 && dot[1]>0)
        answer = 1;
    if (dot[0]>0 && dot[1]<0)
        answer = 4;
    if (dot[0]<0 && dot[1]>0)
        answer = 2;
    if (dot[0]<0 && dot[1]<0)
        answer = 3;
    return answer;
}