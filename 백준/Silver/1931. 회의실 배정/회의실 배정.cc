// Hello world! Cplayground is an online sandbox that makes it easy to try out
// code.

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct schedule
{
    int start;
    int end;
};

bool compare (const schedule& s1, const schedule& s2)
{
    // 끝나는 시간 기준으로 정렬
    if (s1.end == s2.end)
        return s1.start <= s2.start;
    return s1.end < s2.end;
}

int main() {
    int N;
    schedule s;
    vector<schedule> temp, booking;
    
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> s.start;
        cin >> s.end;
        temp.push_back(s);
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    booking.push_back(temp[0]);
    for (int i=1; i<N; i++)
    {
        if (temp[i].start >= booking.back().end)
        {
            booking.push_back(temp[i]);
        }
    }
    
    cout << booking.size() << '\n';
    
    return 0;
}