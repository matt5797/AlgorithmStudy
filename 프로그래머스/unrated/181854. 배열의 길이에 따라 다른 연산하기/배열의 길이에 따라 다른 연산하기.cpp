#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    int s = (arr.size()%2==0)? 1: 0;
    
    for (int i=s; i<arr.size(); i+=2)
        arr[i] += n;
    
    return arr;
}