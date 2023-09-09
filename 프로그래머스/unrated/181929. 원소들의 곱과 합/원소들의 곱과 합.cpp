#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum = 0;
    int mul = 1;
    
    for (int n: num_list)
    {
        sum += n;
        mul *= n;
    }
    
    return (mul<sum*sum)? 1: 0;
}