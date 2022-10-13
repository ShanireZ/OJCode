#include <algorithm>
#include <cstdio>
using namespace std;
#define MX 1000005
int n, epos, ans, fa[MX], last[MX], to[MX * 2], pre[MX * 2];
long long dp[MX], sz[MX];
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
void addEdge(int u, int v, int eid)
{
	pre[eid] = last[u], to[eid] = v;
	last[u] = eid;
}
void dfs1(int now)
{
	sz[now] = 1;
	for (int i = last[now]; i; i = pre[i])
	{
		int nxt = to[i];
		if (fa[now] == nxt)
		{
			continue;
		}
		fa[nxt] = now;
		dfs1(nxt);
		sz[now] += sz[nxt];
	}
	dp[1] += sz[now];
}
void dfs2(int now)
{
	ans = (dp[now] > dp[ans]) ? now : ans;
	for (int i = last[now]; i; i = pre[i])
	{
		int nxt = to[i];
		if (fa[now] == nxt)
		{
			continue;
		}
		dp[nxt] = dp[now] + (n - sz[nxt]) - sz[nxt];
		dfs2(nxt);
	}
}
int main()
{
	n = read();
	for (int i = 1; i < n; i++)
	{
		int a = read(), b = read();
		addEdge(a, b, ++epos);
		addEdge(b, a, ++epos);
	}
	dfs1(1);
	dp[1] -= n;
	dfs2(1);
	printf("%d\n", ans);
	return 0;
}