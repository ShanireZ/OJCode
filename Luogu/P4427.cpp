#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 300005
vector<int> to[MX];
long long n, m, mod = 998244353, h[MX], anc[MX][20], th[MX][55];
int lca(int x, int y)
{
	if (h[x] < h[y])
	{
		swap(x, y);
	}
	for (int i = 18; i >= 0; i--)
	{
		if (h[anc[x][i]] >= h[y])
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
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
void dfs(int now, int from)
{
	h[now] = h[from] + 1;
	long long base = h[now] - 1;
	for (int i = 1; i <= 50; i++)
	{
		th[now][i] = th[from][i] + base;
		base = (base * (h[now] - 1)) % mod;
	}
	for (int nxt : to[now])
	{
		if (nxt == from)
		{
			continue;
		}
		anc[nxt][0] = now;
		dfs(nxt, now);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs(1, 0);
	for (int j = 1; j <= 18; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
	cin >> m;
	while (m--)
	{
		int u, v, k;
		cin >> u >> v >> k;
		int x = lca(u, v);
		cout << (th[u][k] + th[v][k] - th[x][k] - th[anc[x][0]][k] + mod + mod) % mod << endl;
	}
	return 0;
}