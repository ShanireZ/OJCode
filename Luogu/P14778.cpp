#include <algorithm>
#include <iostream>
using namespace std;
long long n, k, dp[5005][5005], mod = 1e9 + 7;
int main()
{
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + (dp[i - 1][j] * (i - 1))) % mod;
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}