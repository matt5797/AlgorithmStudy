#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<long long, long long>> points(N);
    for(int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    long long area = 0;
    for(int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        area += points[i].first * points[j].second;
        area -= points[j].first * points[i].second;
    }
    
    area = abs(area);
    double result = area / 2.0;
    
    cout << fixed;
    cout.precision(1);
    cout << result << endl;
    
    return 0;
}