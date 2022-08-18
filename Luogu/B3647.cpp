#include <iostream>
using namespace std;
int n, m, dis[105][105];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				dis[i][j] = 0x3f3f3f3f;
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v], w), dis[v][u] = min(dis[v][u], w);
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}