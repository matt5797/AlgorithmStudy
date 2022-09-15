#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	struct Node
	{
		int value;
		int level;
        int x, y;
		vector<Node*> neighbors;
	};
	
	int n, m;
	queue<Node> q;
	vector<pair<int, int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} };
	string s;
	
	// 인풋 데이터 받아서 배열로 만들기
	cin >> n >> m;
	Node** arr = new Node *[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		arr[i] = new Node[m];
		for (int j = 0; j < m; j++)
		{
			arr[i][j].value = s[j] - '0';
			arr[i][j].x = i;
			arr[i][j].y = j;
			arr[i][j].level = 0;
		}
	}
	
	// 그래프 만들기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (pair<int, int> d : dir)
			{
				int x = i + d.first;
				int y = j + d.second;
				if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y].value == 1)
				{
					arr[i][j].neighbors.push_back(&arr[x][y]);
				}
			}
		}
	}

	// BFS
	int level = 1;
	q.push(arr[0][0]);
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();
		if (node.level > level)
			level++;
		for (Node * neighbor : node.neighbors)
		{
			if (neighbor->level==0)
			{
				if (neighbor->x == n - 1 && neighbor->y == m - 1)
				{
					cout << level + 1;
					return 0;
				}
				neighbor->level = level + 1;
				q.push(*neighbor);
			}
		}
	}
	cout << level;
	
	return 0;
}