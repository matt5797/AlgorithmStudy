#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 1000000};
    
    int s=0, e=0, acc=sequence[0];
        
    while (s<sequence.size() && e<sequence.size())
    {
        if (acc==k)
            if ((answer[1]-answer[0])>(e-s))
                answer = {s, e};
        
        // 한칸 앞으로 줄이는게 k에 가까워지면
        if (abs(k-acc)>abs(k-(acc-sequence[e])))
            acc = acc - sequence[--e];
        // 한칸 뒤까지 더하는게 k에 가까워지면
        else if (abs(k-acc)>abs(k-(acc+sequence[e+1])))
            acc = acc + sequence[++e];
        // 현재가 최상의 상태이면
        else
            acc = acc - sequence[s++];
    }
    
    return answer;
}