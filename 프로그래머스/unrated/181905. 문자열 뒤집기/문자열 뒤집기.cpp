#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    char temp;
    for (int i=0; i<=(e-s)/2; i++)
    {
        temp = my_string[s+i];
        my_string[s+i] = my_string[e-i];
        my_string[e-i] = temp;
    }
    return my_string;
}