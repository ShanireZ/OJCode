#include <iostream>
#include <algorithm>
using namespace std;
int mp[105][105];
int ord[10005];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> ord[i];
	}
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
	long long dis = 0;
	for (int i = 2; i <= m; i++)
	{
		int from = ord[i - 1], to = ord[i];
		dis += mp[from][to];
	}
	cout << dis;
	return 0;
}