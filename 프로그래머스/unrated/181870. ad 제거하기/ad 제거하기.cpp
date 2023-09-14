#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    for (auto iter=strArr.begin(); iter!=strArr.end(); iter++)
        if (iter->find("ad")!=-1)
            strArr.erase(iter--);
    return strArr;
}