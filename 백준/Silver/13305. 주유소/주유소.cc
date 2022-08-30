#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long int N;
	long long int v, w, min_value;
	long long int *value, *weight;
	long long int result=0;
	
	cin >> N;

	weight = new long long int[N-1];
	for (int i = 0; i < N-1; i++)
	{
		cin >> w;
		weight[i] = w;
	}
	value = new long long int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> v;
		value[i] = v;
	}

	min_value = value[0];
	for (int i = 0; i < N-1; i++)
	{
		if (value[i] < min_value)
			min_value = value[i];
		result += min_value * weight[i];
	}
	
	cout << result;
	
	return 0;
}