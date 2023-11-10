#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

long long solution(string numbers) {
    map<string, int> _map = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    
    for (auto iter=_map.begin(); iter!=_map.end(); iter++)
    {
        int n = numbers.find(iter->first);
        while (n!=-1)
        {
            numbers.replace(n, iter->first.size(), to_string(iter->second));
            n = numbers.find(iter->first);
        }
    }
    
    return stoll(numbers);
}