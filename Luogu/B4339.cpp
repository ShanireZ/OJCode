#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define MX 1000005
#define LG 19
map<int, int> vis[MX];
vector<int> to[MX];
int n, h[MX], t[MX], anc[MX][20];
void dfs(int now, int from)
{
	h[now] = h[from] + 1;
	anc[now][0] = from;
	for (int nxt : to[now])
	{
		if (nxt == from)
		{
			continue;
		}
		dfs(nxt, now);
	}
}
int lca(int x, int y)
{
	if (h[x] < h[y])
	{
		swap(x, y);
	}
	for (int i = LG; i >= 0; i--)
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
	for (int i = LG; i >= 0; i--)
	{
		if (anc[x][i] != anc[y][i])
		{
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
void dfs2(int now, int from)
{
	for (int nxt : to[now])
	{
		if (nxt == from)
		{
			continue;
		}
		dfs2(nxt, now);
	}
	t[from] += t[now];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
		vis[u][v] = vis[v][u] = 1;
	}
	dfs(1, 0);
	for (int j = 1; j <= LG; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		if (vis[u][v])
		{
			continue;
		}
		int x = lca(u, v);
		t[anc[u][0]]++, t[anc[v][0]]++;
		t[x]--, t[anc[x][0]]--;
	}
	dfs2(1, 0);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += (t[i] != 0);
	}
	cout << ans << endl;
	return 0;
}