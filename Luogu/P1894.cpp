#include <iostream>
using namespace std;
int n, m, ans, epos, vis[205], back[205], last[205], pre[40005], to[40005];
void addEdge(int u, int v, int id)
{
	pre[id] = last[u], to[id] = v;
	last[u] = id;
}
int dfs(int now, int tag)
{
	if (vis[now] == tag)
	{
		return 0;
	}
	vis[now] = tag;
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		if (back[t] == 0 || dfs(back[t], tag))
		{
			back[t] = now;
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++)
		{
			int t;
			cin >> t;
			addEdge(i, t, ++epos);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans += dfs(i, i);
	}
	cout << ans << endl;
	return 0;
}