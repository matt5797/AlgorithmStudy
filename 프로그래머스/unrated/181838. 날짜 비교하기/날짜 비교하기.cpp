#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2) {
    string date1_str, date2_str;
    
    for (int i=0;i<3;i++)
    {
        if (date1[i]<10)
            date1_str += "0";
        if (date2[i]<10)
            date2_str += "0";
        date1_str += to_string(date1[i]);
        date2_str += to_string(date2[i]);
    }
    
    return date1_str<date2_str? 1: 0;
}