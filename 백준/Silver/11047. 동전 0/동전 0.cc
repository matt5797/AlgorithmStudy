#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, index=0, count=0;
    int *a;
    
    cin >> n >> k;
    a = new int[n];
    // 오름차순으로 주는데, 내림차순으로 받기
    for (int i=n-1;i>-1;i--)
    {
        cin >> a[i];
        // k보다 크면 필요없으니까 인덱트 저장해두자
        if (index==0 && a[i]>k)
            index = i+1;
    }
    
    for (int i=index; i<n;i++)
    {
        // 몫이 필요 개수가 됨
        count += k / a[i];
        // 나머지가 없을때까지 나머지 계산
        k = k % a[i];
        if (k==0)
            break;
    }
    cout << count << '\n';
    
    return 0;
}