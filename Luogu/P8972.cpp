#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 200005
struct Edge
{
	int v, c2, c5, xs, c0;
};
vector<Edge> es[MX];
int n, q, a2[MX], a5[MX], a0[MX], h[MX], s2[MX], s5[MX], s0[MX], sxs[MX], anc[MX][20];
int ct(int x, int base)
{
	int cnt = 0;
	while (x && x % base == 0)
	{
		cnt++, x /= base;
	}
	return cnt;
}
void dfs(int now, int from)
{
	h[now] = h[from] + 1;
	anc[now][0] = from;
	for (Edge e : es[now])
	{
		int nxt = e.v;
		if (nxt == from)
		{
			continue;
		}
		s2[nxt] = s2[now] + e.c2;
		s5[nxt] = s5[now] + e.c5;
		sxs[nxt] = sxs[now] + e.xs;
		s0[nxt] = s0[now] + e.c0;
		dfs(nxt, now);
	}
}
int lca(int x, int y)
{
	if (h[x] < h[y])
	{
		swap(x, y);
	}
	for (int j = 17; j >= 0; j--)
	{
		if (h[anc[x][j]] >= h[y])
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
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		a2[i] = ct(a, 2), a5[i] = ct(a, 5);
		a0[i] = (a == 0);
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		string w;
		cin >> u >> v >> w;
		int c2 = 0, c5 = 0, c0 = 0, xs = 0;
		int pos = w.find('.');
		if (pos == string::npos)
		{
			c2 = ct(stoi(w), 2), c5 = ct(stoi(w), 5);
			c0 = (w == "0");
			es[u].push_back({v, c2, c5, xs, c0});
			es[v].push_back({u, c2, c5, xs, c0});
			continue;
		}
		int now1 = stoi(w.substr(0, pos));
		int now2 = stoi(w.substr(pos + 1));
		c2 = ct(now1, 2) + ct(now2, 2);
		c5 = ct(now1, 5) + ct(now2, 5);
		if (now2 != 0)
		{
			xs = w.substr(pos + 1).size();
		}
		es[u].push_back({v, c2, c5, xs, 0});
		es[v].push_back({u, c2, c5, xs, 0});
		if (now1 == 0 && now2 == 0)
		{
			es[u].back().c0 = 1;
			es[v].back().c0 = 1;
		}
	}
	dfs(1, 0);
	for (int j = 1; j <= 17; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		int p = lca(u, v);
		int c2 = s2[u] + s2[v] - s2[p] * 2 + a2[u];
		int c5 = s5[u] + s5[v] - s5[p] * 2 + a5[u];
		int c0 = s0[u] + s0[v] - s0[p] * 2 + a0[u];
		int xs = sxs[u] + sxs[v] - sxs[p] * 2;
		if (c0 || min(c2, c5) >= xs)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}