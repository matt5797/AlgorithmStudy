#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

bool compare(string s1, string s2) {
    if (s1.length()==s2.length())
    {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main()
{
	int N;
	vector<string> numbers = vector<string>();
	string input, temp = "";
	int index = 0;
	char c;
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		
		temp = "";
		for (int i=0; i<input.length(); i++)
		{
		    c = input[i];
			// 숫자면 temp에 붙이기
			if (isdigit(c))
			{
				temp += c;
			}
			// 숫자가 끝났으면 정산
			if (!isdigit(c) || i == input.length()-1)
			{
			    if (temp == "")
			    {
			        continue;
			    }
				// 숫자로 바꿔서 리스트에 넣기
			    // 0 빼기
			    index = 0;
			    while(temp[index]=='0')
			    {
			        index++;
			    }
			    if (temp.length()==index)
			        temp = '0';
			    else
			        temp = temp.substr(index);
				numbers.push_back(temp);
				temp = "";
			}
		}
	}

	// 오름차순 정렬
	sort(numbers.begin(), numbers.end(), compare);
	
	for (string num : numbers)
	{
		cout << num << '\n';
	}
	
	return 0;
}