#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    string temp;
    
    // 가로로 늘리고
    for (int i=0; i<picture.size(); i++)
    {
        temp = "";
        for (char c: picture[i])
            temp += string(k, c);
        picture[i] = temp;
    }
    // 세로로 늘리고
    for (int i=0; i<picture.size(); i++)
    {
        for (int j=0; j<k; j++)
        {
            answer.push_back(picture[i]);
        }
    }
    
    return answer;
}