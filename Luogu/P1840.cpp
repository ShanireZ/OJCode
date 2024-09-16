#include <algorithm>
#include <iostream>
using namespace std;
int g[200005];
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
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		int now = dfn(l), nxt = dfn(r + 1);
		while (now != nxt)
		{
			g[now] = nxt;
			now = dfn(now + 1);
			n--;
		}
		cout << n << endl;
	}
	return 0;
}
// TAG: 并查集