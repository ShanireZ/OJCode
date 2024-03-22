#include <algorithm>
#include <iostream>
using namespace std;
long long dp[100] = {1}, n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		if (i >= 2)
		{
			dp[i] += dp[i - 2];
		}
		if (i >= 3)
		{
			dp[i] += dp[i - 3];
		}
	}
	cout << dp[n] << endl;
	return 0;
}