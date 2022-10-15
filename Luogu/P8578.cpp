#include <cstdio>
using namespace std;
#define MX 1000005
int epos, cnt, last[MX], pre[MX * 2], to[MX * 2], val[MX];
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
void dfs(int now, int fa)
{
	for (int i = last[now]; i; i = pre[i])
	{
		int nxt = to[i];
		if (nxt == fa)
		{
			continue;
		}
		dfs(nxt, now);
	}
	val[now] = ++cnt;
}
int main()
{
	int n = read();
	for (int i = 1; i < n; i++)
	{
		int a = read(), b = read();
		addEdge(a, b, ++epos);
		addEdge(b, a, ++epos);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", val[i]);
	}
	return 0;
}