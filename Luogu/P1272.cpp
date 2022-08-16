#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[155];
int n, p, root = 1, dp[155][155], sz[155];
// dp[a][b] 以a为根大小为b且连接至父节点的子树,所需的最小删边数
void dfs(int now)
{
	sz[now] = 1, dp[now][1] = to[now].size();
	for (int i = 0; i < to[now].size(); i++)
	{
		int t = to[now][i];
		dfs(t);
		sz[now] += sz[t];
		for (int j = sz[now]; j >= 1; j--)
		{
			for (int k = 1; k < j; k++)
			{
				// 将以t为根大小为k的子树连上,删除的边数少一
				dp[now][j] = min(dp[now][j], dp[now][j - k] + dp[t][k] - 1);
			}
		}
	}
}
int main()
{
	cin >> n >> p;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		to[a].push_back(b);
	}
	memset(dp, 0x3f, sizeof(dp));
	dfs(root);
	int ans = dp[root][p]; // 根节点得到p大小的子树,不需要断开与父节点的边
	for (int i = 2; i <= n; i++)
	{
		// 其他点要得到p大小的子树,都需要断开与父节点连接的边
		ans = min(ans, dp[i][p] + 1);
	}
	cout << ans << endl;
	return 0;
}