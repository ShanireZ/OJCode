#include <iostream>
#include <vector>
using namespace std;
vector<int> es[500005], qst[500005];
int n, m, s, g[500005], tot[500005], cnt[500005], ans[500005];
int dfn(int x)
{
	return x == g[x] ? x : g[x] = dfn(g[x]);
}
void dfs(int now, int from)
{
	for (int id : qst[now])
	{
		cnt[id]++;
		if (cnt[id] == 2)
		{
			ans[id] = dfn(tot[id] - now);
		}
	}
	for (int nxt : es[now])
	{
		if (nxt == from)
		{
			continue;
		}
		dfs(nxt, now);
		g[nxt] = now;
	}
}
int main()
{
	cin >> n >> m >> s;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[i] = i;
		es[u].push_back(v), es[v].push_back(u);
	}
	g[n] = n;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		qst[u].push_back(i), qst[v].push_back(i);
		tot[i] = u + v;
	}
	dfs(s, 0);
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}