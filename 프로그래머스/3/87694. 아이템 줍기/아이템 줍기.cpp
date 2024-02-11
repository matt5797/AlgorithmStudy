#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> lines;
    
    for (int i=0; i<rectangle.size(); i++)
    {
        lines.push_back({rectangle[i][0], rectangle[i][1], rectangle[i][0], rectangle[i][3]});
        lines.push_back({rectangle[i][2], rectangle[i][1], rectangle[i][2], rectangle[i][3]});
        lines.push_back({rectangle[i][0], rectangle[i][1], rectangle[i][2], rectangle[i][1]});
        lines.push_back({rectangle[i][0], rectangle[i][3], rectangle[i][2], rectangle[i][3]});
    }
    
    for (int i=0; i<lines.size(); i++)
    {
        for (int j=0; j<rectangle.size(); j++)
        {
            // x축 선이 겹칠때
            if (lines[i][1]==lines[i][3] && rectangle[j][1]<lines[i][1] && lines[i][1]<rectangle[j][3])
            {
                bool inside = false;
                if (rectangle[j][0]<lines[i][0] && lines[i][2]<rectangle[j][2])
                    inside = true;
                if (lines[i][0]<rectangle[j][0] && rectangle[j][0]<lines[i][2]) {
                    lines.push_back({lines[i][0], lines[i][1], rectangle[j][0], lines[i][3]});
                    inside = true;
                }
                if (lines[i][2]>rectangle[j][2] && rectangle[j][2]>lines[i][0]) {
                    lines.push_back({rectangle[j][2], lines[i][1], lines[i][2], lines[i][3]});
                    inside = true;
                }
                if (inside) {
                    lines.erase(lines.begin()+i--);
                    break;
                }
            }
            // y축 선이 겹칠때
            if (lines[i][0]==lines[i][2] && rectangle[j][0]<lines[i][0] && lines[i][0]<rectangle[j][2])
            {
                bool inside = false;
                if (rectangle[j][1]<lines[i][1] && lines[i][3]<rectangle[j][3])
                    inside = true;
                if (lines[i][1]<rectangle[j][1] && rectangle[j][1]<lines[i][3]) {
                    lines.push_back({lines[i][0], lines[i][1], lines[i][2], rectangle[j][1]});
                    inside = true;
                }
                if (lines[i][3]>rectangle[j][3] && rectangle[j][3]>lines[i][1]) {
                    lines.push_back({lines[i][0], rectangle[j][3], lines[i][2], lines[i][3]});
                    inside = true;
                }
                if (inside) {
                    lines.erase(lines.begin()+i--);
                    break;
                }
            }
        }
    }
    
    int startLine;
    
    for (int i=0; i<lines.size(); i++)
    {
        if ((lines[i][0]==lines[i][2] && lines[i][0]==characterX && lines[i][1]<=characterY && lines[i][3]>=characterY) || 
            (lines[i][1]==lines[i][3] && lines[i][1]==characterY && lines[i][0]<=characterX && lines[i][2]>=characterX))
            startLine = i;
    }
    
    vector<vector<int>> cycles;
    
    cycles.push_back(lines[startLine]);
    lines.erase(lines.begin()+startLine);
    while (lines.size()>0)
    {
        for (int i=0; i<lines.size(); i++)
        {
            if (cycles.back()[2]==lines[i][0] && cycles.back()[3]==lines[i][1])
            {
                cycles.push_back(lines[i]);
                lines.erase(lines.begin()+i);
                break;
            }
            else if (cycles.back()[2]==lines[i][2] && cycles.back()[3]==lines[i][3])
            {
                cycles.push_back({lines[i][2],lines[i][3],lines[i][0],lines[i][1]});
                lines.erase(lines.begin()+i);
                break;
            }
        }
        if (cycles[0][0]==cycles.back()[2] && cycles[0][1]==cycles.back()[3])
            break;
    }
    
    int total=0, forward=0;
    
    for (int i=0; i<cycles.size(); i++)
    {
        total += abs(cycles[i][2]-cycles[i][0]) + abs(cycles[i][3]-cycles[i][1]);
    }
    
    for (int i=0; i<cycles.size(); i++)
    {
        if (i==0)
            forward += abs(characterX-cycles[i][2]) + abs(characterY-cycles[i][3]);
        else if ((cycles[i][0]==itemX && cycles[i][2]==itemX && cycles[i][1]<=itemY && cycles[i][3]>=itemY) || 
                 (cycles[i][0]==itemX && cycles[i][2]==itemX && cycles[i][1]>=itemY && cycles[i][3]<=itemY) ||
                 (cycles[i][1]==itemY && cycles[i][3]==itemY && cycles[i][0]<=itemX && cycles[i][2]>=itemX) ||
                 (cycles[i][1]==itemY && cycles[i][3]==itemY && cycles[i][0]>=itemX && cycles[i][2]<=itemX))
        {
            forward += abs(itemX-cycles[i][0]) + abs(itemY-cycles[i][1]);
            break;
        }
        else
            forward += abs(cycles[i][2]-cycles[i][0]) + abs(cycles[i][3]-cycles[i][1]);
    }
    
    if ((total-forward)>forward)
        return forward;
    else
        return (total-forward);
}