#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> strArr) {
    int max = 0;
    map<int, int> count;
    
    for (string s: strArr)
        count[s.size()]++;
    
    for (auto iter=count.begin(); iter!=count.end(); iter++)
        if (max<iter->second)
            max = iter->second;
    
    return max;
}