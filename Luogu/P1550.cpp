#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
	int a, b, w;
	bool operator<(const Edge oth) const
	{
		return w < oth.w;
	}
};
Edge es[100005];
int n, pos, ans, g[100005];
int dfn(int now)
{
	return (now == g[now]) ? now : g[now] = dfn(g[now]);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		es[++pos] = Edge{n + 1, i, x};
		g[i] = i;
	}
	g[n + 1] = n + 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			if (j < i)
			{
				es[++pos] = Edge{i, j, x};
			}
		}
	}
	sort(es + 1, es + 1 + pos);
	for (int i = 1; i <= pos; i++)
	{
		int ga = dfn(es[i].a), gb = dfn(es[i].b);
		if (ga == gb)
		{
			continue;
		}
		g[ga] = gb;
		ans += es[i].w;
	}
	cout << ans << endl;
	return 0;
}