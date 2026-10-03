#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans, p[20005], dp[20005];
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i];
	}
	sort(p + 1, p + 1 + m, greater<int>());
	for (int i = 1; i <= 20000; i++)
	{
		p[i] += p[i - 1];
	}
	fill(dp + 1, dp + 20001, 1e9);
	for (int i = 1; i <= n; i++)
	{
		int c, e;
		cin >> c >> e;
		for (int i = 20000; i >= c; i--)
		{
			dp[i] = min(dp[i], dp[i - c] + e);
		}
	}
	for (int i = 1; i <= 20000; i++)
	{
		ans = max(ans, p[i] - dp[i]);
	}
	cout << ans << endl;
	return 0;
}