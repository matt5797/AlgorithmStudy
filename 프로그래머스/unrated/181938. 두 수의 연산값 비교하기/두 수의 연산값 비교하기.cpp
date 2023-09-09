#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int ab = stoi(to_string(a)+to_string(b));
    return (ab>2*a*b)? ab: 2*a*b;
}