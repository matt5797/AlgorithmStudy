#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for (int i=0; i<myString.size(); i++)
        myString[i] = toupper(myString[i]);
    for (int i=0; i<pat.size(); i++)
        pat[i] = toupper(pat[i]);
    
    return (myString.find(pat)==-1)? 0: 1;
}