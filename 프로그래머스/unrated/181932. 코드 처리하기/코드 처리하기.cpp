#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret = "";
    int mode = 0;
    
    for (int i=0; i<code.length(); i++)
    {
        if (code[i]=='1')
            mode = (mode==0)? 1: 0;
        else if (i%2==mode)
            ret += code[i];
    }
    
    if (ret.length()==0) { ret = "EMPTY"; }
    
    return ret;
}