#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    for (int i=0; i<ingredient.size(); i++)
    {
        if (i>2 && ingredient[i]==1 && ingredient[i-1]==3 && ingredient[i-2]==2 && ingredient[i-3]==1)
        {
            ingredient.erase(ingredient.begin() + i - 3, ingredient.begin() + i + 1);
            i = i - 4;
            answer++;
        }
    }
    
    return answer;
}