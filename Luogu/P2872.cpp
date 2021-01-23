#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node
{
	int x, y;
};
struct Line
{
	int a, b;
	double d;
};
Node f[1005];
Line ls[500005];
int g[1005];
int dfn(int x)
{
	if (g[x] != x)
	{
		g[x] = dfn(g[x]);
	}
	return g[x];
}
bool cmp(Line a, Line b)
{
	return a.d < b.d;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i].x >> f[i].y;
		for (int j = 1; j < i; j++)
		{
			ls[p].d = sqrt(1.0 * (f[i].x - f[j].x) * (f[i].x - f[j].x) + 1.0 * (f[i].y - f[j].y) * (f[i].y - f[j].y));
			ls[p].a = i, ls[p].b = j;
			p++;
		}
		g[i] = i;
	}
	sort(ls + 1, ls + p, cmp);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		int ga = dfn(a), gb = dfn(b);
		if (ga != gb)
		{
			g[ga] = gb;
		}
	}
	double ans = 0;
	for (int i = 1; i < p; i++)
	{
		int ga = dfn(ls[i].a), gb = dfn(ls[i].b);
		if (ga != gb)
		{
			g[ga] = gb;
			ans += ls[i].d;
			m++;
		}
	}
	cout << fixed << setprecision(2) << ans;
	return 0;
}