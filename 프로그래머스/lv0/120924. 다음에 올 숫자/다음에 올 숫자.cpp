#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int k;
    bool flag = true;
    
    k = common[1] - common[0];
    for (int i=1; i<common.size(); i++)
    {
        if (common[i] != common[i-1] + k)
        {
            k = common[i] / common[i-1];
            flag = false;
        }
    }
    if (flag)
        return common.back() + k;
    return common.back() * k;
}