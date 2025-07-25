#include <algorithm>
#include <iostream>
using namespace std;
int n, m, dp[2005], dpg[2005];
int main()
{
	cin >> n >> m;
	while (n--)
	{
		int opt, a, b, c;
		cin >> opt >> a >> b;
		if (opt == 1)
		{
			for (int j = 0; j <= m; j++)
			{
				int v = a * j * j - b * j;
				for (int k = j; k <= m; k++)
				{
					dpg[k] = max(dpg[k], dp[k - j] + v);
				}
			}
			for (int j = 1; j <= m; j++)
			{
				dp[j] = max(dp[j], dpg[j]);
				dpg[j] = 0;
			}
		}
		else
		{
			c = m / b;
			if (opt == 2)
			{
				cin >> c;
			}
			while (c--)
			{
				for (int j = m; j >= b; j--)
				{
					dp[j] = max(dp[j], dp[j - b] + a);
				}
			}
		}
	}
	cout << dp[m] << endl;
	return 0;
}