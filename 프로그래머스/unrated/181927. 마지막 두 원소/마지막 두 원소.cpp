#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int element = num_list[num_list.size()-1] - num_list[num_list.size()-2];
    if (element>0)
        num_list.push_back(element);
    else
        num_list.push_back(num_list[num_list.size()-1]*2);
    
    return num_list;
}