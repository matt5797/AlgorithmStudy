#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    int temp;
    for (vector<int> q: queries)
    {
        for (int i=0; i<=((q[1]-q[0])/2); i++)
        {
            temp = my_string[q[0]+i];
            my_string[q[0]+i] = my_string[q[1]-i];
            my_string[q[1]-i] = temp;
        }
    }
    return my_string;
}