#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	if (a.second.first == b.second.first) {
		return a.second.second < b.second.second;
	}
	return a.second.first > b.second.first;
}

int main()
{
	int N, C;
	int num, index=0;
	map<int, pair<int, int>> m;	// num, count, index
	
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		m[num].first++;
		// 첫 삽입이면 인덱스 카운트
		if (m[num].first == 1)
			m[num].second = index++;
	}

	// 정렬해서 벡터로 옮기기
	vector<pair<int, pair<int, int>>> vec(m.begin(), m.end());

	sort(vec.begin(), vec.end(), cmp);

	/*cout << "------------------sorted---------------" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second << endl;
	}*/
	
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].second.first; j++)
		{
			cout << vec[i].first << " ";
		}
	}

	return 0;
}