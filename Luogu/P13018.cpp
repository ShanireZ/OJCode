#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> dp;
int main()
{
	int n;
	cin >> n;
	for (int i = -50000; i <= 50000; i++)
	{
		dp[i] = -1e9;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		int delta = a - b;
		if (delta >= 0)
		{
			for (int j = 50000 - delta; j >= -50000; j--)
			{
				dp[j + delta] = max(dp[j + delta], dp[j] + a + b);
			}
		}
		else
		{
			for (int j = -50000 - delta; j <= 50000; j++)
			{
				dp[j + delta] = max(dp[j + delta], dp[j] + a + b);
			}
		}
	}
	cout << dp[0] << endl;
	return 0;
}