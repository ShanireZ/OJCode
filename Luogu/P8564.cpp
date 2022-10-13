#include <iostream>
#include <vector>
using namespace std;
int n, fa[5005], sz[5005];
long long f[5005], dp[5005][5005];
vector<int> to[5005];
void dfs(int now)
{
	sz[now] = 1, dp[now][1] = 0;
	for (int i = 0; i < int(to[now].size()); i++)
	{
		int nxt = to[now][i];
		if (nxt == fa[now])
		{
			continue;
		}
		fa[nxt] = now;
		dfs(nxt);
		for (int j = sz[now] + sz[nxt]; j > 0; j--)
		{
			dp[now][j] = 0x3f3f3f3f3f3f3f3f;
			for (int k = max(1, j - sz[now]); k <= sz[nxt] && j - k > 0; k++) // 剪枝
			{
				dp[now][j] = min(dp[now][j], dp[now][j - k] + dp[nxt][k]);
			}
		}
		sz[now] += sz[nxt];
	}
	for (int i = 1; i < sz[now]; i++)
	{
		dp[now][1] = min(dp[now][1], dp[now][i + 1] + f[i]);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> f[i];
	}
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		to[a].push_back(b), to[b].push_back(a);
	}
	dfs(1);
	cout << dp[1][1] << endl;
	return 0;
}