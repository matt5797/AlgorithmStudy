#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 1;
    
    if (ineq==">" && eq=="=" && n >= m) { }
    else if (ineq=="<" && eq=="=" && n <= m) { }
    else if (ineq==">" && eq=="!" && n > m) { }
    else if (ineq=="<" && eq=="!" && n < m) { }
    else { answer = 0; }
    
    return answer;
}