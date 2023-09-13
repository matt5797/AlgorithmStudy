#include <string>
#include <vector>

using namespace std;

int compare(string s1, string s2)
{
    int cnt = 0;
    for (int i=0; i<s1.size(); i++)
    {
        if (s1[i]==s2[i]) cnt++;
    }
    return cnt;
}

int DFS(string begin, string target, vector<string> words, vector<int> logs, int cnt)
{
    if (cnt>words.size()) return 51;
    if (begin.compare(target)==0) return cnt;
    
    int res;
    int min = 51;
    bool isLoged = false;
    for (int i=0; i<words.size(); i++)
    {
        isLoged = false;
        for (auto l: logs)
                if (l==i) 
                    isLoged = true;
        if (!isLoged && compare(begin, words[i])==begin.size()-1)
        {
            logs.push_back(i);
            res = DFS(words[i], target, words, logs, cnt+1);
            if (res<min)
                min = res;
        }
    }
    
    return min;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> logs;
    answer = DFS(begin, target, words, logs, 0);
    if (answer==51) answer = 0;
    return answer;
}