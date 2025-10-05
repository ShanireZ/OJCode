#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> to[205];
queue<pair<int, long long>> q;
long long n, m, s, t, ans, vis[205], f[205][205], rd[205][205], pre[205];
long long bfs(int st)
{
	long long ex = 0;
	q.push({st, 1e15}), vis[st] = 1;
	while (q.size())
	{
		long long now = q.front().first, flow = q.front().second;
		q.pop();
		if (now == t)
		{
			ex = flow;
			break;
		}
		for (int nxt : to[now])
		{
			long long cap = min(flow, f[now][nxt]);
			if (vis[nxt] == 0 && cap)
			{
				q.push({nxt, cap}), vis[nxt] = 1, pre[nxt] = now;
			}
		}
	}
	int now = pre[t], nxt = t;
	while (now && ex)
	{
		f[now][nxt] -= ex, f[nxt][now] += ex;
		nxt = now, now = pre[now];
	}
	return ex;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (rd[u][v] == 0 && w)
		{
			to[u].push_back(v), rd[u][v] = 1;
			to[v].push_back(u), rd[v][u] = 1;
		}
		f[u][v] += w;
	}
	long long ex = bfs(s);
	while (ex)
	{
		ans += ex;
		fill(vis, vis + n + 1, 0);
		fill(pre, pre + n + 1, 0);
		while(q.size())
		{
			q.pop();
		}
		ex = bfs(s);
	}
	cout << ans << endl;
	return 0;
}