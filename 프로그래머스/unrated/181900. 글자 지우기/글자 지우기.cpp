#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    sort(indices.rbegin(), indices.rend());
    for (int index: indices)
        my_string.erase(index, 1);
    return my_string;
}