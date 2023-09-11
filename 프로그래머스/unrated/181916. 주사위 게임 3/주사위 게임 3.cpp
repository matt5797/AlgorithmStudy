#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    vector<int> dices = {a,b,c,d};
    map<int, int> cnt;
    
    for (int dice: dices)
    {
        if (cnt.find(dice)!=cnt.end())
            cnt[dice]++;
        else
            cnt.insert(make_pair(dice, 1));
    }
    
    if (cnt.size()==1)
        answer = 1111 * cnt.begin()->first;
    else if (cnt.size()==2 && cnt.begin()->second==1)
        answer = ((10 * (++cnt.begin())->first) + cnt.begin()->first) * ((10 * (++cnt.begin())->first) + cnt.begin()->first);
    else if (cnt.size()==2 && cnt.begin()->second==3)
        answer = ((10 * cnt.begin()->first) + (++cnt.begin())->first) * ((10 * cnt.begin()->first) + (++cnt.begin())->first);
    else if (cnt.size()==2 && cnt.begin()->second==2)
    {
        answer = (cnt.begin()->first + (++cnt.begin())->first) * (cnt.begin()->first - (++cnt.begin())->first);
        if (answer<0) answer *= -1;
    }
    else if (cnt.size()==3)
    {
        answer = 1;
        for (auto iter=cnt.begin(); iter!=cnt.end(); iter++)
            if (iter->second==1)
                answer *= iter->first;
        
    }
    else if (cnt.size()==4)
    {
        answer = 7;
        for (auto iter=cnt.begin(); iter!=cnt.end(); iter++)
            if (iter->first<answer)
                answer = iter->first;
    }
    
    return answer;
}