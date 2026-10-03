#include <algorithm>
#include <iostream>
using namespace std;
int dp[2005][15], f[15], n, v;
int main()
{
	while (cin >> v)
	{
		cin >> n;
		for (int i = 1; i <= v; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				dp[i][j] = 1e9;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> f[i];
			for (int j = f[i]; j <= v; j++)
			{
				if (dp[j][0] > dp[j - f[i]][0] + 1)
				{
					dp[j][0] = dp[j - f[i]][0] + 1;
					for (int k = 1; k <= n; k++)
					{
						dp[j][k] = dp[j - f[i]][k] + (k == i);
					}
				}
				else if (dp[j][0] == dp[j - f[i]][0] + 1)
				{
					int ok = 0;
					for (int k = 1; k <= n; k++)
					{
						if (dp[j][k] != dp[j - f[i]][k] + (k == i))
						{
							ok = (dp[j][k] < dp[j - f[i]][k] + (k == i));
							break;
						}
					}
					for (int k = 1; k <= n && ok; k++)
					{
						dp[j][k] = dp[j - f[i]][k] + (k == i);
					}
				}
			}
		}
		if (dp[v][0] == 1e9)
		{
			cout << -1 << endl;
			continue;
		}
		for (int k = 1; k <= n; k++)
		{
			cout << dp[v][k] << " ";
		}
		cout << endl;
	}
	return 0;
}