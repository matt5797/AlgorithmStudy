#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num, int k) {
    int answer = to_string(num).find(to_string(k));
    if (answer!=-1)
        answer++;
    return answer;
}