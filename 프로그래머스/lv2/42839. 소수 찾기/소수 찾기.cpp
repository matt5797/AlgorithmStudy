#include <string>
#include <set>

using namespace std;

set<int> results;

bool isPrimeNumber(int number)
{
    if (number<2 || number==4) return false;
    for (int i=2; i*i<=number; i++)
        if (number % i == 0) return false;
    return true;
}

void DFS(string numbers, string logs, int n)
{
    if (n==0)
    {
        if (isPrimeNumber(stoi(logs))) results.insert(stoi(logs));
        return;
    }
    
    int answer = 0;
    string temp;
    if (!logs.empty())
        if (isPrimeNumber(stoi(logs))) results.insert(stoi(logs));
    for (int i=0; i<numbers.size(); i++)
    {
        temp = numbers;
        logs += numbers[i];
        temp.erase(i, 1);
        DFS(temp, logs, n-1);
        logs.pop_back();
    }
}

int solution(string numbers) {
    DFS(numbers, {}, numbers.size());
    return results.size();
}