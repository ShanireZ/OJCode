#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[155];
int n, p, root = 1, dp[155][155], sz[155];
// dp[a][b] 以a為根大小為b且連接至父節點的子樹,所需的最小刪邊數
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
				// 將以t為根大小為k的子樹連上,刪除的邊數少一
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
	int ans = dp[root][p]; // 根節點得到p大小的子樹,不需要斷開與父節點的邊
	for (int i = 2; i <= n; i++)
	{
		// 其他點要得到p大小的子樹,都需要斷開與父節點連接的邊
		ans = min(ans, dp[i][p] + 1);
	}
	cout << ans << endl;
	return 0;
}