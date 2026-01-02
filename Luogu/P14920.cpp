#include <algorithm>
#include <iostream>
using namespace std;
long long dp[250005], n, k, ans;
int main()
{
	cin >> n >> k;
	fill(dp + 1, dp + n * 500 + 1, 1e15);
	for (int i = 1; i <= n; i++)
	{
		long long a, c;
		cin >> a >> c;
		for (int j = n * 500; j >= 1; j--)
		{
			dp[j] = min(dp[j], dp[j - a] + c);
			if (dp[j] <= k)
			{
				ans = max(ans, 1ll * j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}