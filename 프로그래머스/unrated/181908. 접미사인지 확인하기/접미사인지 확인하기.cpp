#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    for (int i=0; i<my_string.size(); i++)
        if (is_suffix.compare(my_string.substr(i))==0)
            return 1;
    return 0;
}