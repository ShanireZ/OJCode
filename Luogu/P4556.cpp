#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
struct Node
{
	int lc, rc, v, t;
};
Node ns[MX * 40];
int n, m, pos, ans[MX], h[MX], root[MX], anc[MX][20];
vector<int> g[MX];
void dfs(int now, int from)
{
	h[now] = h[from] + 1, anc[now][0] = from;
	for (int nxt : g[now])
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
	for (int i = 16; i >= 0; i--)
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
	for (int i = 16; i >= 0; i--)
	{
		if (anc[x][i] != anc[y][i])
		{
			x = anc[x][i], y = anc[y][i];
		}
	}
	return anc[x][0];
}
void update(int now)
{
	if (ns[ns[now].lc].t >= ns[ns[now].rc].t)
	{
		ns[now].t = ns[ns[now].lc].t;
		ns[now].v = ns[ns[now].lc].v;
	}
	else
	{
		ns[now].t = ns[ns[now].rc].t;
		ns[now].v = ns[ns[now].rc].v;
	}
}
void edit(int &now, int l, int r, int p, int k)
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
	p <= mid ? edit(ns[now].lc, l, mid, p, k) : edit(ns[now].rc, mid + 1, r, p, k);
	update(now);
}
void merge(int from, int &to, int l, int r)
{
	if (from == 0 || to == 0)
	{
		to = from + to;
		return;
	}
	if (l == r)
	{
		ns[to].t += ns[from].t;
		return;
	}
	int mid = (l + r) / 2;
	merge(ns[from].lc, ns[to].lc, l, mid);
	merge(ns[from].rc, ns[to].rc, mid + 1, r);
	update(to);
}
void dfs2(int now, int from)
{
	for (int nxt : g[now])
	{
		if (nxt == from)
		{
			continue;
		}
		dfs2(nxt, now);
		merge(root[nxt], root[now], 1, 100000);
	}
	ans[now] = (ns[root[now]].t == 0 ? 0 : ns[root[now]].v);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			anc[j][i] = anc[anc[j][i - 1]][i - 1];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int p = lca(a, b);
		edit(root[a], 1, 100000, c, 1);
		edit(root[b], 1, 100000, c, 1);
		edit(root[p], 1, 100000, c, -1);
		edit(root[anc[p][0]], 1, 100000, c, -1);
	}
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}