#include <algorithm>
#include <iostream>
using namespace std;
#define MX 300005
long long c[MX], v[MX], tc[MX], tv[MX], qz[MX], hz[MX];
int to[MX * 2], pre[MX * 2], last[MX], sz[MX], dfn[MX], ids[MX], pos, ans, n, m, read();
void addEdge(int u, int v, int eid)
{
	to[eid] = v, pre[eid] = last[u];
	last[u] = eid;
}
void dfs(int now, int fa)
{
	tc[now] = c[now], sz[now] = 1;
	dfn[now] = ++pos;
	ids[pos] = now;
	for (int i = last[now]; i; i = pre[i])
	{
		int nxt = to[i];
		if (nxt == fa)
		{
			continue;
		}
		dfs(nxt, now);
		tc[now] = tc[now] * tc[nxt] % m, sz[now] += sz[nxt];
	}
}
int main()
{
	n = read(), m = read();
	for (int i = 1; i < n; i++)
	{
		int u = read(), v = read();
		addEdge(u, v, i * 2 - 1), addEdge(v, u, i * 2);
	}
	for (int i = 1; i <= n; i++)
	{
		c[i] = read();
	}
	for (int i = 1; i <= n; i++)
	{
		v[i] = read();
	}
	dfs(1, 0);
	qz[0] = 1, hz[n + 1] = 1;
	for (int i = 1; i <= n; i++)
	{
		qz[i] = qz[i - 1] * v[ids[i]] % m;
	}
	for (int i = n; i >= 1; i--)
	{
		hz[i] = hz[i + 1] * v[ids[i]] % m;
	}
	for (int i = 1; i <= n; i++)
	{
		tv[i] = qz[dfn[i] - 1] * hz[dfn[i] + sz[i]] % m;
		ans = (ans + tc[i] * tv[i] % m) % m;
	}
	printf("%d\n", ans);
	return 0;
}
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}