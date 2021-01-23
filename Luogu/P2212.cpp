#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int g[2005], pos, n, c;
int dfn(int x)
{
	if (x != g[x])
	{
		g[x] = dfn(g[x]);
	}
	return g[x];
}
struct Way
{
	int u, v, w;
};
Way way[4000005];
bool cmp(Way a, Way b)
{
	return a.w < b.w;
}
struct Node
{
	int x, y;
};
Node ns[2005];
int countd(int a, int b)
{
	int d = pow(ns[a].x - ns[b].x, 2) + pow(ns[a].y - ns[b].y, 2);
	if (d < c)
	{
		d = -1;
	}
	return d;
}
int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].x >> ns[i].y;
		for (int j = 1; j < i; j++)
		{
			int d = countd(i, j);
			if (d != -1)
			{
				way[++pos].w = countd(i, j);
				way[pos].u = i, way[pos].v = j;
			}
		}
		g[i] = i;
	}
	sort(way + 1, way + 1 + pos, cmp);
	int cnt = 0, d = 0;
	for (int i = 1; i <= pos && cnt < n - 1; i++)
	{
		int ga = dfn(way[i].u);
		int gb = dfn(way[i].v);
		if (ga != gb)
		{
			g[ga] = gb;
			cnt++;
			d += way[i].w;
		}
	}
	if (cnt == n - 1)
	{
		cout << d;
	}
	else
	{
		cout << -1;
	}
	return 0;
}