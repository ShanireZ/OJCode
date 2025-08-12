#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
struct Node
{
	int lc, rc, v, t; //! v种类 t个数
};
Node ns[8000005];
int root[100005], pos, n, m, anc[100005][20], dp[100005], ans[100005];
void dfs(int now)
{
	for (int nxt : to[now])
	{
		if (nxt == anc[now][0])
		{
			continue;
		}
		anc[nxt][0] = now, dp[nxt] = dp[now] + 1;
		dfs(nxt);
	}
}
int lca(int x, int y)
{
	if (dp[x] < dp[y])
	{
		swap(x, y);
	}
	for (int j = 17; j >= 0; j--)
	{
		if (dp[anc[x][j]] >= dp[y])
		{
			x = anc[x][j];
		}
	}
	if (x == y)
	{
		return x;
	}
	for (int j = 17; j >= 0; j--)
	{
		if (anc[x][j] != anc[y][j])
		{
			x = anc[x][j], y = anc[y][j];
		}
	}
	return anc[x][0];
}
void edit(int &now, int l, int r, int z, int k)
{
	if (now == 0)
	{
		now = ++pos;
	}
	if (l == r)
	{
		ns[now].t += k, ns[now].v = l;
		return;
	}
	int mid = (l + r) / 2;
	if (z <= mid)
	{
		edit(ns[now].lc, l, mid, z, k);
	}
	else
	{
		edit(ns[now].rc, mid + 1, r, z, k);
	}
	if (ns[ns[now].lc].t >= ns[ns[now].rc].t)
	{
		ns[now].v = ns[ns[now].lc].v;
		ns[now].t = ns[ns[now].lc].t;
	}
	else
	{
		ns[now].v = ns[ns[now].rc].v;
		ns[now].t = ns[ns[now].rc].t;
	}
}
void merge(int &now, int nxt, int l, int r)
{
	if (now == 0 || nxt == 0)
	{
		now = now + nxt;
		return;
	}
	if (l == r)
	{
		ns[now].v = l, ns[now].t += ns[nxt].t;
		return;
	}
	int mid = (l + r) / 2;
	merge(ns[now].lc, ns[nxt].lc, l, mid);
	merge(ns[now].rc, ns[nxt].rc, mid + 1, r);
	if (ns[ns[now].lc].t >= ns[ns[now].rc].t)
	{
		ns[now].v = ns[ns[now].lc].v;
		ns[now].t = ns[ns[now].lc].t;
	}
	else
	{
		ns[now].v = ns[ns[now].rc].v;
		ns[now].t = ns[ns[now].rc].t;
	}
}
void dfs2(int now)
{
	for (int nxt : to[now])
	{
		if (nxt == anc[now][0])
		{
			continue;
		}
		dfs2(nxt);
		merge(root[now], root[nxt], 1, 100000);
	}
	if (ns[root[now]].t == 0)
	{
		ans[now] = 0;
	}
	else
	{
		ans[now] = ns[root[now]].v;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		to[a].push_back(b), to[b].push_back(a);
	}
	dp[1] = 1, dfs(1);
	for (int j = 1; j <= 17; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edit(root[x], 1, 100000, z, 1);
		edit(root[y], 1, 100000, z, 1);
		int ca = lca(x, y);
		edit(root[ca], 1, 100000, z, -1);
		edit(root[anc[ca][0]], 1, 100000, z, -1);
	}
	dfs2(1);
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}