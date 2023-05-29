#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, cnt;
    int number, temp;
    string s;
    
    while (cin >> n)
    {
        cnt=0;
        temp = 0;
        s = string(to_string(n).length()+1, '1');
        number = stoi(s);
        
        do
        {
            cnt++;
            temp = (number + (temp*10)) % n;
        } while (temp);
        
        cout << cnt << "\n";
    }
    
    return 0;
}