#include <algorithm>
#include <iostream>
using namespace std;
int n, m, t, a, dp[105], c[105][105];
int main()
{
	cin >> n >> m >> t >> a;
	int lmt = min(t, a - 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int k, dis = (i + j) * 2;
			cin >> k;
			while (k--)
			{
				for (int y = lmt; y >= dis; y--)
				{
					dp[y] = max(dp[y], dp[y - dis] + c[i][j]);
				}
			}
		}
	}
	cout << dp[lmt] << endl;
	return 0;
}