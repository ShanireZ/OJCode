#include <iostream>
#include <algorithm>
using namespace std;
struct Line
{
	int x, y, l;
};
Line ls[10005];
int g[1005];
bool cmp(Line a, Line b)
{
	return a.l < b.l;
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
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> ls[i].x >> ls[i].y >> ls[i].l;
	}
	sort(ls + 1, ls + 1 + m, cmp);
	int link = 0, ans = 0;
	for (int i = 1; i <= m && link < n - k; i++)
	{
		int gx = dfn(ls[i].x);
		int gy = dfn(ls[i].y);
		if (gx != gy)
		{
			link++;
			ans += ls[i].l;
			g[gx] = gy;
		}
	}
	if (link != n - k)
	{
		cout << "No Answer";
	}
	else
	{
		cout << ans;
	}
	return 0;
}