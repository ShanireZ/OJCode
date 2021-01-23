#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
long long mp[105][105];
int w[15];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> mp[i][j];
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
			}
		}
	}
	int p, t = 1;
	cin >> p;
	for (int i = 1; i <= p; i++)
	{
		cin >> w[i];
		t *= i;
	}
	long long mind = LONG_LONG_MAX;
	for (int i = 1; i <= t; i++)
	{
		int from = 1, to;
		long long dis = 0;
		for (int j = 1; j <= p; j++)
		{
			to = w[j];
			dis += mp[from][to];
			from = to;
		}
		mind = min(mind, dis + mp[from][n]);
		next_permutation(w + 1, w + 1 + p);
	}
	cout << mind;
	return 0;
}