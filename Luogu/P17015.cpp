#include <algorithm>
#include <iostream>
using namespace std;
long long n, a[105], dp[105][105];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			for (int k = i; k <= j; k++)
			{
				long long res = a[i - 1] + a[j + 1];
				if (k - 1 >= i)
				{
					res += dp[i][k - 1];
				}
				if (k + 1 <= j)
				{
					res += dp[k + 1][j];
				}
				dp[i][j] = max(dp[i][j], res);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}