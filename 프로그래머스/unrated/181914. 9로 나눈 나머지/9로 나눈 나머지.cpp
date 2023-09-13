#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    for (char c: number)
        answer += atoi(&c);
    return (answer%9);
}