#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, tip;
    long long result=0;
    int *tips;
    
    cin >> N;
    
    tips = new int[N];
    for (int i=0; i<N; i++)
        cin >> tips[i];
    
    // 내림차순으로 정렬
    sort(tips, tips+N);
    reverse(tips, tips+N);
    for (int i=0; i<N; i++)
    {
        // 뒤로 갈수록 1씩 빼서 받아냄
        tip = tips[i] - i;
        if (tip>=0)
            result += tip;
    }
    cout << result;
    
    return 0;
}