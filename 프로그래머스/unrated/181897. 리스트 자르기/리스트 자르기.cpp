#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    int s = 0;
    int e = num_list.size()-1;
    int t = 1;
    
    if (n==1)
        e = slicer[1];
    else if (n==2)
        s = slicer[0];
    else if (n==3)
    {
        s = slicer[0];
        e = slicer[1];
    }
    else if (n==4)
    {
        s = slicer[0];
        e = slicer[1];
        t = slicer[2];
    }
    
    for (int i=s; i<=e; i+=t)
        answer.push_back(num_list[i]);
    return answer;
}