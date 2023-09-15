#include <string>

using namespace std;

string solution(string n_str) {
    int index = -1;
    
    for (int i=0; i<n_str.size(); i++)
        if (index==-1 && n_str[i]!='0')
            index = i;
        
    return n_str.substr(index);
}