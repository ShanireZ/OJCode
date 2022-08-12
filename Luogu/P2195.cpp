#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 300005
int n, m, t, epos;
int g[MX], dis[MX], dia[MX], vis[MX], last[MX], pre[MX * 2], to[MX * 2];
queue<int> q;
void addEdge(int u, int v, int id)
{
	pre[id] = last[u], to[id] = v;
	last[u] = id;
}
int dfn(int now)
{
	return (now == g[now]) ? now : g[now] = dfn(g[now]);
}
int bfs(int st, int x)
{
	vis[st] = x, dis[st] = 0, q.push(st);
	int maxp = st;
	while (q.size())
	{
		int f = q.front();
		q.pop();
		for (int i = last[f]; i; i = pre[i])
		{
			int t = to[i];
			if (vis[t] != x)
			{
				vis[t] = x, dis[t] = dis[f] + 1, q.push(t);
				maxp = (dis[t] > dis[maxp]) ? t : maxp;
			}
		}
	}
	return maxp;
}
int main()
{
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		addEdge(x, y, ++epos), addEdge(y, x, ++epos);
		g[dfn(x)] = dfn(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (g[i] == i)
		{
			int p = bfs(bfs(i, 1), 2);
			dia[i] = dis[p];
		}
	}
	for (int i = 1; i <= t; i++)
	{
		int opt, x, y;
		cin >> opt >> x;
		if (opt == 1)
		{
			int gx = dfn(x);
			cout << dia[gx] << endl;
		}
		else
		{
			cin >> y;
			int gx = dfn(x), gy = dfn(y);
			if (gx == gy)
			{
				continue;
			}
			dia[gy] = max((dia[gx] + 1) / 2 + (dia[gy] + 1) / 2 + 1, max(dia[gx], dia[gy]));
			g[gx] = gy;
		}
	}
	return 0;
}