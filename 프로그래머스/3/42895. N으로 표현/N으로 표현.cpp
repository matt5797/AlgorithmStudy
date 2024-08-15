#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    vector<vector<int>> tb(9);
    tb[1].push_back(N);
    
    for (int i=1; i<=8; i++)
    {
        int n = N;
        for (int j=1; j<i; j++)
        {
            for (auto q: tb[i-j])
            {
                if (q!=0)
                    tb[i].push_back(n / q);
                tb[i].push_back(q + n);
                tb[i].push_back(q - n);
                tb[i].push_back(n - q);
                tb[i].push_back(q * n);
                tb[i].push_back(q / n);
            }
            n = (n * 10) + N;
        }
        tb[i].push_back(n);
        for (auto q: tb[i])
            if (q==number)
                return i;
    }
    
    return -1;
}