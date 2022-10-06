#include <iostream>

using namespace std;

int main()
{
	int H, W;
	int cnt;
	char** JOI;
	int** cloud;
	
	cin >> H >> W;

	JOI = new char*[H];
	cloud = new int*[H];
	for (int i = 0; i < H; i++)
	{
		JOI[i] = new char[W];
		cloud[i] = new int[W];

		for (int j = 0; j < W; j++)
		{
			cin >> JOI[i][j];
		}
	}
	
	for (int i = 0; i < H; i++)
	{
		cnt = -1;
		for (int j = 0; j < W; j++)
		{
			if (JOI[i][j] == 'c')
			{
				cnt = 0;
			}
			else if (cnt != -1 && JOI[i][j] == '.')
			{
				cnt++;
			}
			cloud[i][j] = cnt;
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << cloud[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}