#include <iostream>
using namespace std;
int n, m, pos, mod = 1e8, ans, g[20], s[4200], dp[20][4200];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			g[i] = g[i] * 2 + (!x);
		}
	}
	for (int i = 1; i < (1 << m); i++)
	{
		if ((i & (i << 1)) || (i & (i >> 1)))
		{
			continue;
		}
		s[++pos] = i;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= pos; j++)
		{
			if (g[i] & s[j])
			{
				continue;
			}
			for (int k = 0; k <= pos; k++)
			{
				if (s[j] & s[k])
				{
					continue;
				}
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
			}
		}
	}
	for (int j = 0; j <= pos; j++)
	{
		ans = (ans + dp[n][j]) % mod;
	}
	cout << ans << endl;
	return 0;
}