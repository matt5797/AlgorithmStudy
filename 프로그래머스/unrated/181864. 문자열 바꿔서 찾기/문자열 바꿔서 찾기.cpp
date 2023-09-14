#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for (int i=0; i<myString.size(); i++)
        myString[i] = (myString[i]=='A')? 'B': 'A';
    return (myString.find(pat)!=-1)? 1: 0;
}