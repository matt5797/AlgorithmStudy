#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (int i=0; i<str.length(); i++)
    {
        if (str[i]<'a')
        {
            cout << char(str[i] + ('a' - 'A'));
        }
        else
        {
            cout << char(str[i] - ('a' - 'A'));
        }
    }
    
    return 0;
}