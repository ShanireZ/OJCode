#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int g[200005];
int dfn(int x)
{
	if (g[x] != x)
	{
		g[x] = dfn(g[x]);
	}
	return g[x];
}
vector<int> farm[200005];
int order[200005];
int link[200005];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		farm[a].push_back(b);
		farm[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> order[i];
	}
	int area = 0;
	for (int i = n; i >= 1; i--)
	{
		int id = order[i];
		g[id] = id;
		area++;
		for (int j = 0; j < farm[id].size(); j++)
		{
			int to = farm[id][j];
			if (g[to] != 0)
			{
				int gx = dfn(id), gy = dfn(to);
				if (gx != gy)
				{
					area--;
					g[gx] = gy;
				}
			}
		}
		if (area == 1)
		{
			link[i - 1] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (link[i] == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}