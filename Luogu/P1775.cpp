#include <algorithm>
#include <iostream>
using namespace std;
int dp[305][305], m[305], qz[305];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i];
		qz[i] = qz[i - 1] + m[i];
	}
	for (int len = 2; len <= n; len++)
	{
		for (int st = 1, ed = len; ed <= n; st++, ed++)
		{
			dp[st][ed] = 0x3f3f3f3f;
			for (int i = st; i < ed; i++)
			{
				dp[st][ed] = min(dp[st][ed], dp[st][i] + dp[i + 1][ed] + qz[ed] - qz[st - 1]);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}