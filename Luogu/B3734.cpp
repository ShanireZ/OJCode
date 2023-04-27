#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dp[105][105], a[105];
int main()
{
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; i++)
	{
		a[i] = r % 100;
		r = (r * 6807 + 2831) % 201701;
	}
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i < 100; i++)
	{
		int cost = min(abs(a[1] - i), 100 - abs(a[1] - i));
		dp[1][i] = cost * cost;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < j; k++)
			{
				int cost = min(abs(a[i] - j), 100 - abs(a[i] - j));
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost * cost);
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 100; i++)
	{
		ans = min(ans, dp[n][i]);
	}
	cout << ans << "\n";
	return 0;
}