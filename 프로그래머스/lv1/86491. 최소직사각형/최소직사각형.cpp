#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int mx = 0, my = 0;
    
    for (int i=0; i<sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
            swap(sizes[i][0], sizes[i][1]);
        if (sizes[i][0] > mx)
            mx = sizes[i][0];
        if (sizes[i][1] > my)
            my = sizes[i][1];
    }
    
    return mx * my;
}