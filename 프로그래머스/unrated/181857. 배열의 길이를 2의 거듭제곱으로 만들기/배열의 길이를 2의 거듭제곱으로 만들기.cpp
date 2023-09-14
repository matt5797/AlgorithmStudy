#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> arr) {
    int expo = 0;
    
    while (true)
        if (arr.size()<=pow(2, expo++))
            break;
    
    for (int i=arr.size(); i<pow(2, expo-1); i++)
        arr.push_back(0);
    
    return arr;
}