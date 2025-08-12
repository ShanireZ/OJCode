#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[300005];
long long h[300005][55], anc[300005][20], dp[300005], n, m, mod = 998244353;
void dfs(int now)
{
	for (int nxt : to[now])
	{
		if (nxt == anc[now][0])
		{
			continue;
		}
		anc[nxt][0] = now, h[nxt][1] = h[now][1] + 1;
		dp[nxt] = dp[now] + 1;
		dfs(nxt);
	}
}
int lca(int x, int y)
{
	if (dp[x] < dp[y])
	{
		swap(x, y);
	}
	for (int i = 18; i >= 0; i--)
	{
		if (dp[anc[x][i]] >= dp[y])
		{
			x = anc[x][i];
		}
	}
	if (x == y)
	{
		return x;
	}
	for (int i = 18; i >= 0; i--)
	{
		if (anc[x][i] != anc[y][i])
		{
			x = anc[x][i], y = anc[y][i];
		}
	}
	return anc[x][0];
}
void dfs2(int now)
{
	for (int nxt : to[now])
	{
		if (nxt == anc[now][0])
		{
			continue;
		}
		for (int i = 1; i <= 50; i++)
		{
			h[nxt][i] = (h[nxt][i] + h[now][i]) % mod;
		}
		dfs2(nxt);
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		to[u].push_back(v), to[v].push_back(u);
	}
	dfs(1);
	for (int j = 1; j <= 18; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
	for (int j = 2; j <= 50; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			h[i][j] = (h[i][j - 1] * h[i][1]) % mod;
		}
	}
	dfs2(1);
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		int ca = lca(u, v);
		int cb = anc[ca][0];
		if (cb == 0)
		{
			cout << (h[u][w] + h[v][w] - h[ca][w] + mod) % mod << endl;
		}
		else
		{
			cout << (h[u][w] + h[v][w] - h[ca][w] - h[cb][w] + mod + mod) % mod << endl;
		}
	}
	return 0;
}