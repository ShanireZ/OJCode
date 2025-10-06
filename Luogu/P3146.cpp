#include <cstring>
#include <iostream>
using namespace std;
int dp[255][255], n, ans;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		dp[i][i] = x, ans = max(ans, x);
	}
	for (int len = 2; len <= n; len++)
	{
		for (int l = 1, r = len; r <= n; l++, r++)
		{
			for (int mid = l; mid < r; mid++)
			{
				if (dp[l][mid] && dp[l][mid] == dp[mid + 1][r]) // dp为0表示该区间之前没合并
				{
					dp[l][r] = max(dp[l][r], dp[l][mid] + 1);
				}
			}
			ans = max(ans, dp[l][r]);
		}
	}
	cout << ans << endl;
	return 0;
}