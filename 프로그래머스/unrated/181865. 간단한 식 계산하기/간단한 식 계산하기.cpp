#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    int a, b, op;
    
    for (char c: "+-*")
        op = (binomial.find(c)!=-1)? binomial.find(c): op;
    
    a = stoi(binomial.substr(0, op));
    b = stoi(binomial.substr(op+1, binomial.size()-op));
    
    if (binomial[op]=='+')
        answer = a + b;
    if (binomial[op]=='-')
        answer = a - b;
    if (binomial[op]=='*')
        answer = a * b;
    
    return answer;
}