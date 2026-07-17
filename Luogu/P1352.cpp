#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[6005];
int dp[6005][2], r[6005], fa[6005], n, root;
void dfs(int now)
{
	for (int nxt : to[now])
	{
		dfs(nxt);
		dp[now][1] += dp[nxt][0];
		dp[now][0] += max(dp[nxt][0], dp[nxt][1]);
	}
	dp[now][1] += r[now];
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> r[i];
	}
	for (int i = 1; i < n; i++)
	{
		int l, k;
		cin >> l >> k;
		to[k].push_back(l);
		fa[l] = k;
	}
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] == 0)
		{
			root = i;
		}
	}
	dfs(root);
	cout << max(dp[root][0], dp[root][1]) << endl;
	return 0;
}