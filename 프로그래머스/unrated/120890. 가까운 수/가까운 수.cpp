#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int min = 101;
    
    for(int i=0; i<array.size(); i++)
    {
        if (abs(n - array[i])==min && array[answer]>array[i])
        {
            answer = i;
        }
        else if (abs(n - array[i])<min)
        {
            answer = i;
            min = abs(n - array[i]);
        }
    }
    
    return array[answer];
}