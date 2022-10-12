#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 2005
int n, m, pre[MX], to[MX], last[MX], vis[MX];
long long d[MX], dis[MX];
queue<int> q;
void addEdge(int u, int v, int w, int eid)
{
	pre[eid] = last[u], to[eid] = v, d[eid] = w;
	last[u] = eid;
}
int main()
{
	memset(dis, 0x3f, sizeof(dis));
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w, i);
	}
	q.push(1), vis[1] = 1, dis[1] = 0;
	while (q.size())
	{
		int now = q.front();
		q.pop(), vis[now] = 0;
		for (int i = last[now]; i; i = pre[i])
		{
			int nxt = to[i], w = d[i];
			if (dis[now] + w < dis[nxt])
			{
				dis[nxt] = dis[now] + w;
				if (vis[nxt] == 0)
				{
					q.push(nxt), vis[nxt] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] == 0x3f3f3f3f3f3f3f3f)
		{
			dis[i] = -1;
		}
		cout << dis[i] << " ";
	}
	return 0;
}