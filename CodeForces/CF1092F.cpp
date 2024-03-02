#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[200005];
long long sz[200005], tot[200005], ans, n;
void dfs1(int now, int fa, int dp)
{
	tot[1] += sz[now] * dp;
	for (int nxt : to[now])
	{
		if (nxt == fa)
		{
			continue;
		}
		dfs1(nxt, now, dp + 1);
		sz[now] += sz[nxt];
	}
}
void dfs2(int now, int fa)
{
	if (now != 1)
	{
		tot[now] = tot[fa] - sz[now] + sz[1] - sz[now];
		ans = max(ans, tot[now]);
	}
	for (int nxt : to[now])
	{
		if (nxt == fa)
		{
			continue;
		}
		dfs2(nxt, now);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> sz[i];
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		to[u].push_back(v), to[v].push_back(u);
	}
	dfs1(1, 0, 0);
	ans = tot[1];
	dfs2(1, 0);
	cout << ans << endl;
	return 0;
}
// TAG: 树的重心 树上DP