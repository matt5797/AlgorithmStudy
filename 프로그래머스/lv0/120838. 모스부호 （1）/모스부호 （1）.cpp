#include <string>
#include <map>

using namespace std;

map<string, string> morse = { 
    {".-","a"},{"-...","b"},{"-.-.","c"},{"-..","d"},{".","e"},{"..-.","f"},
    {"--.","g"},{"....","h"},{"..","i"},{".---","j"},{"-.-","k"},{".-..","l"},
    {"--","m"},{"-.","n"},{"---","o"},{".--.","p"},{"--.-","q"},{".-.","r"},
    {"...","s"},{"-","t"},{"..-","u"},{"...-","v"},{".--","w"},{"-..-","x"},
    {"-.--","y"},{"--..","z"}
};

string solution(string letter) {
    string answer = "";
    
    int s=0, l=0;
    for (int i=0; i<letter.size(); i++)
    {
        l = i-1;
        if (letter[i]==' ')
        {
            answer += morse[letter.substr(s,l-s+1)];
            s = i+1;
        }
    }
    answer += morse[letter.substr(s,letter.size())];
    
    return answer;
}