#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string odd = "";
    string even = "";
    
    for (int n: num_list)
        (n%2==0)? even+=to_string(n): odd+=to_string(n);
    
    return stoi(odd)+stoi(even);
}