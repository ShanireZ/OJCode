#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[205];
long long n, m, s, t, ans, vis[205], f[205][205], rd[205][205];
long long dfs(int now, long long flow)
{
	if (now == t)
	{
		return flow;
	}
	vis[now] = 1;
	long long ex = 0;
	for (int nxt : to[now])
	{
		long long cap = min(f[now][nxt], flow);
		if (vis[nxt] == 0 && cap)
		{
			ex = dfs(nxt, cap);
			f[now][nxt] -= ex, f[nxt][now] += ex;
			if (ex)
			{
				break;
			}
		}
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
	long long ex = dfs(s, 1e15);
	while (ex)
	{
		ans += ex;
		fill(vis, vis + n + 1, 0);
		ex = dfs(s, 1e15);
	}
	cout << ans << endl;
	return 0;
}