#include <iostream>
using namespace std;
int n, king, pos, s[1000], cnt[1000];
long long dp[10][1000][100];
int count(int x)
{
	int c = 0;
	while (x)
	{
		c += x % 2;
		x /= 2;
	}
	return c;
}
int main()
{
	cin >> n >> king;
	for (int i = 1; i < (1 << n); i++)
	{
		if ((i & (i << 1)) && (i & (i >> 1)))
		{
			continue;
		}
		s[++pos] = i;
		cnt[pos] = count(i);
	}
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= pos; j++)
		{
			for (int k = 0; k <= pos; k++)
			{
				if ((s[j] & s[k]) || (s[j] & (s[k] << 1)) || (s[j] & (s[k] >> 1)))
				{
					continue;
				}
				for (int x = cnt[j]; x <= king; x++)
				{
					dp[i][j][x] = dp[i][j][x] + dp[i - 1][k][x - cnt[j]];
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= pos; i++)
	{
		ans = ans + dp[n][i][king];
	}
	cout << ans << endl;
	return 0;
}