#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, i=0, res=0;
    int *t;
    
    cin >> n;
    
    t = new int[n];
    for (int i=0;i<n;i++)
    {
        cin >> t[i];
    }
    
    // 최소가 되려면 오름차순으로 정렬해야함
    sort(t, t+n);
    
    // 뒷 사람 수만큼 곱해서 더해줌, 총 5명인데 2번째면 X4
    for (int i=0;i<n;i++)
    {
        res += t[i] * (n-i);
    }
    cout << res;
    
    return 0;
}