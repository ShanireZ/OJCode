#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> chs[200005];
int n, k, root, a[200005], h[200005], anc[200005][20], ans[100005], x[100005];
void dfs(int now)
{
	for (int i = 1; i < 18; i++)
	{
		anc[now][i] = anc[anc[now][i - 1]][i - 1];
	}
	int pt = a[now];
	if (h[now] > h[x[pt]])
	{
		x[pt] = now;
	}
	for (int nxt : chs[now])
	{
		h[nxt] = h[now] + 1;
		dfs(nxt);
	}
}
int lca(int u, int v)
{
	if (h[u] < h[v])
	{
		swap(u, v);
	}
	for (int i = 17; i >= 0; i--)
	{
		if (h[anc[u][i]] >= h[v])
		{
			u = anc[u][i];
		}
	}
	if (u == v)
	{
		return u;
	}
	for (int i = 17; i >= 0; i--)
	{
		if (anc[u][i] != anc[v][i])
		{
			u = anc[u][i], v = anc[v][i];
		}
	}
	return anc[u][0];
}
void dfs2(int now)
{
	int pt = a[now];
	ans[pt] = max(ans[pt], h[now] + h[x[pt]] - 2 * h[lca(now, x[pt])]);
	for (int nxt : chs[now])
	{
		dfs2(nxt);
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> anc[i][0];
		chs[anc[i][0]].push_back(i);
	}
	root = chs[0][0];
	h[root] = 1, dfs(root);
	dfs2(root);
	for (int i = 1; i <= k; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}