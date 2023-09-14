#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for (int i=0; i<myString.size(); i++)
        myString[i] = (myString[i]=='a' || myString[i]=='A')? 'A': tolower(myString[i]);
    return myString;
}