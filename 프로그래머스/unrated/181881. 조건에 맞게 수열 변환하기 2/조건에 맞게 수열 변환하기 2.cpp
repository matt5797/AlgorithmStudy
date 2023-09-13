#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    vector<int> pre = arr;
    int answer = 0;
    while(true)
    {
        for (int i=0; i<arr.size(); i++)
        {
            if (arr[i]>=50 && arr[i]%2==0)
                arr[i] /= 2;
            else if (arr[i]<50 && arr[i]%2==1)
                arr[i] = (arr[i] * 2) + 1;
        }
        if (pre==arr)
            break;
        pre = arr;
        answer++;
    }
    return answer;
}