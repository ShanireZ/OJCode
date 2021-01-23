#include <iostream>
#include <cstring>
using namespace std;
int mp[55][55][65];
int d[55][55];
int main()
{
	int n, m;
	cin >> n >> m;
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		mp[a][b][0] = 1;
		d[a][b] = 1;
	}
	for (int t = 1; t < 64; t++)
	{
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (mp[i][k][t - 1] == 1 && mp[k][j][t - 1] == 1)
					{
						mp[i][j][t] = 1;
						d[i][j] = 1;
					}
				}
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][k] != -1 && d[k][j] != -1)
				{
					if (d[i][j] == -1)
					{
						d[i][j] = d[i][k] + d[k][j];
					}
					else
					{
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
		}
	}
	cout << d[1][n];
	return 0;
}