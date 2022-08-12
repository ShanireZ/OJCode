#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 200005
int n, m, epos, x, y, pre[MX * 2], to[MX * 2], d[MX * 2], last[MX];
long long dis[MX][5];
queue<int> q;
void addEdge(int u, int v, int w, int id)
{
	pre[id] = last[u], to[id] = v, d[id] = w;
	last[u] = id;
}
int bfs(int st, int id)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i][id] = 0x3f3f3f3f3f3f3f3f;
	}
	dis[st][id] = 0, q.push(st);
	while (q.size())
	{
		int f = q.front();
		q.pop();
		for (int i = last[f]; i; i = pre[i])
		{
			int t = to[i], w = d[i];
			if (dis[t][id] == 0x3f3f3f3f3f3f3f3f)
			{
				dis[t][id] = dis[f][id] + w, q.push(t);
			}
		}
	}
	long long maxp = st;
	for (int i = 1; i <= n; i++)
	{
		maxp = (dis[i][id] > dis[maxp][id]) ? i : maxp;
	}
	return maxp;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		addEdge(u, v, t, ++epos), addEdge(v, u, t, ++epos);
	}
	x = bfs(1, 1);
	y = bfs(x, 2);
	bfs(y, 3);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, min(dis[i][2], dis[i][3]));
	}
	cout << ans + dis[y][2] << endl;
	return 0;
}