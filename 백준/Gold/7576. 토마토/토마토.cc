#include <iostream>
#include <queue>
#include <vector>

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
	Node node;

	// 인풋 데이터 받아서 배열로 만들기
	cin >> m >> n;
	Node** arr = new Node * [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new Node[m];
		for (int j = 0; j < m; j++)
		{
			cin >> node.value;
			node.x = i;
			node.y = j;
			node.level = 0;
			arr[i][j] = node;
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
				if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y].value != -1)
				{
					arr[i][j].neighbors.push_back(&arr[x][y]);
				}
			}
		}
	}

	/*cout << "graph: \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j].value << " ";
		}
		cout << endl;
	}*/

	// BFS
	int level = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j].value == 1)
			{
				q.push(arr[i][j]);
			}
		}
	}
	
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();
		if (node.level > level)
		{
			level++;
			//cout << level << " graph: \n";
			//for (int j = 0; j < m; j++)
			//{
			//	for (int i = 0; i < n; i++)
			//	{
			//		//cout << " " << arr[i][j].value << " ";
			//		printf("%2d ", arr[i][j].value);
			//	}
			//	cout << endl;
			//}
		}
		for (Node* neighbor : node.neighbors)
		{
			if (neighbor->value == 0 && neighbor->level == 0)
			{
				neighbor->value = 1;
				neighbor->level = level + 1;
				q.push(*neighbor);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j].value == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << level;

	return 0;
}