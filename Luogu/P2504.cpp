#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, p, mk[505], g[1005];
struct Node
{
	int x, y;
};
Node ns[1005];
struct Line
{
	int from, to;
	double d;
};
Line ls[1000005];
bool cmp(Line x, Line y)
{
	return x.d < y.d;
}
int dfn(int x)
{
	if (x != g[x])
	{
		g[x] = dfn(g[x]);
	}
	return g[x];
}
int main()
{
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> mk[i];
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
		cin >> ns[i].x >> ns[i].y;
		for (int j = 1; j < i; j++)
		{
			ls[++p].d = sqrt(pow(ns[i].x - ns[j].x, 2) + pow(ns[i].y - ns[j].y, 2));
			ls[p].from = i;
			ls[p].to = j;
		}
	}
	sort(ls + 1, ls + 1 + p, cmp);
	int cnt = 0;
	double maxd = 0;
	for (int i = 1; cnt != n - 1; i++)
	{
		int ga = dfn(ls[i].from);
		int gb = dfn(ls[i].to);
		if (ga != gb)
		{
			cnt++;
			maxd = ls[i].d;
			g[ga] = gb;
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		if (mk[i] >= maxd)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}