#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    int n;
    cin >> str >> n;
    
    string answer = "";
    for (int i=0; i<n; i++)
    {
        answer += str;
    }
    cout << answer;
    
    return 0;
}