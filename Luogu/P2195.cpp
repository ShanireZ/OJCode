#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, q, pos, dis[300005], dm[300005], vis[300005];
vector<int> to[300005];
void dfs(int now, int from, int gpos)
{
	vis[now] = gpos;
	for (int nxt : to[now])
	{
		if (nxt == from)
		{
			continue;
		}
		dis[nxt] = dis[now] + 1;
		if (dis[nxt] > dis[pos])
		{
			pos = nxt;
		}
		dfs(nxt, now, gpos);
	}
}
int dfn(int now)
{
	if (vis[now] != now)
	{
		vis[now] = dfn(vis[now]);
	}
	return vis[now];
}
int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
		{
			continue;
		}
		pos = i, dfs(i, 0, i);
		int s = pos;
		dis[s] = 0, dfs(s, 0, i);
		dm[i] = dis[pos];
	}
	while (q--)
	{
		int opt, x, y;
		cin >> opt >> x;
		if (opt == 1)
		{
			cout << dm[dfn(x)] << endl;
		}
		else
		{
			cin >> y;
			int gx = dfn(x), gy = dfn(y);
			if (gx != gy)
			{
				dm[gy] = max({dm[gx], dm[gy], (dm[gx] + 1) / 2 + (dm[gy] + 1) / 2 + 1});
				vis[gx] = gy;
			}
		}
	}
	return 0;
}