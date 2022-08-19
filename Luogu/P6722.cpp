#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define MX 100005
queue<int> q;
int vis[MX], last[MX], to[MX * 2], pre[MX * 2], d[MX * 2], dis[MX][3];
void addEdge(int u, int v, int w, int id)
{
	to[id] = v, d[id] = w, pre[id] = last[u];
	last[u] = id;
}
int bfs(int st, int turn)
{
	int far = 0;
	dis[st][turn] = 0, q.push(st), vis[st] = turn;
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int i = last[now]; i; i = pre[i])
		{
			int nxt = to[i];
			if (vis[nxt] == turn)
			{
				continue;
			}
			q.push(nxt), vis[nxt] = turn, dis[nxt][turn] = dis[now][turn] + d[i];
			if (dis[nxt][turn] > dis[far][turn])
			{
				far = nxt;
			}
		}
	}
	return far;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(last, 0, sizeof(last)), memset(dis, 0, sizeof(dis));
		int epos = 0, ans = 0, n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			addEdge(x, y, z, ++epos), addEdge(y, x, z, ++epos);
		}
		int l = bfs(1, 2);
		int r = bfs(l, 0);
		bfs(r, 1);
		for (int i = 1; i <= n; i++)
		{
			if (i == l || i == r)
			{
				continue;
			}
			if (dis[i][0] >= k && dis[i][1] >= k)
			{
				ans = 1;
				break;
			}
		}
		if (ans)
		{
			cout << "Baka Chino" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}