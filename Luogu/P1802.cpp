#include <iostream>
#include <algorithm>
using namespace std;
long long dp[1005];
int main()
{
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		int lose, win, usd;
		cin >> lose >> win >> usd;
		for (int j = x; j >= 0; j--)
		{
			if (j >= usd)
			{
				dp[j] = max(dp[j] + lose, dp[j - usd] + win);
			}
			else
			{
				dp[j] += lose;
			}
		}
	}
	cout << dp[x] * 5;
	return 0;
}