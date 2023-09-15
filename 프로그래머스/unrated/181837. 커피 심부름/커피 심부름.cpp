#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    for (string menu: order)
    {
        if (menu.find("cafelatte")!=-1)
            answer += 5000;
        else
            answer += 4500;
    }
    
    return answer;
}