#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    auto iter=number.begin();
    
    while(iter!=number.end() && k>0)
    {
        // 이전 값이 나보다 작으면 제거
        if (iter!=number.begin() && *prev(iter)<*iter)
        {
            number.erase(prev(iter--));
            k--;
        }
        // 다음 값보다 작으면 나를 제거
        else if (iter!=number.end()-1 && *iter<*next(iter))
        {
            number.erase(iter);
            k--;
        }
        else
            iter++;
    }
    
    iter = number.end()-1;
    while(iter!=number.begin() && k>0)
    {
        // 다음 값이 나보다 작으면 제거
        if (iter!=number.end()-1 && *next(iter)<*iter)
        {
            number.erase(next(iter));
            k--;
        }
        // 이전 값보다 작으면 나를 제거
        else if (iter!=number.begin() && *iter<*prev(iter))
        {
            number.erase(iter--);
            k--;
        }
        else
            iter--;
    }
    return number;
}