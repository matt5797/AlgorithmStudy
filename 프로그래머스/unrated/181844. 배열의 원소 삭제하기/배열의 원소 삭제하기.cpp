#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    for (int i=0; i<arr.size(); i++)
    {
        if (find(delete_list.begin(), delete_list.end(), arr[i])!=delete_list.end())
        {
            arr.erase(arr.begin()+i, arr.begin()+i+1);
            i--;
        }
    }
    return arr;
}