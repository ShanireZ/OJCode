#include <iostream>
using namespace std;
#define MX 500005
int read(), dp[MX], to[MX * 2], pre[MX * 2], last[MX], cnt[MX], maxh, ans;
void addEdge(int u, int v, int eid)
{
	to[eid] = v, pre[eid] = last[u];
	last[u] = eid;
}
void dfs(int now, int fa, int h)
{
	maxh = max(maxh, h), cnt[h]++;
	for (int i = last[now]; i; i = pre[i])
	{
		if (to[i] != fa)
		{
			dfs(to[i], now, h + 1);
		}
	}
}
int main()
{
	int n = read();
	for (int i = 1; i < n; i++)
	{
		int u = read(), v = read();
		addEdge(u, v, i * 2 - 1), addEdge(v, u, i * 2);
	}
	dfs(1, 0, 1);
	int minc = 0x3f3f3f3f; // 当前层最多取几个点
	for (int i = maxh; i > 0; i--)
	{
		minc = min(minc, cnt[i]);
		if (cnt[i] >= dp[i + 1] + minc) // 从此层开始更优
		{
			dp[i] = minc = cnt[i];
		}
		else // 继续满足要求在限制下选点
		{
			dp[i] = dp[i + 1] + minc;
		}
	}
	printf("%d\n", dp[1]);
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