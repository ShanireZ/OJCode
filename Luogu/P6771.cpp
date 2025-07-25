#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	int h, a, c;
	bool operator<(const Node &oth) const
	{
		return a < oth.a;
	}
};
Node ns[405];
int n, ans, dp[40005];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].h >> ns[i].a >> ns[i].c;
	}
	sort(ns + 1, ns + n + 1);
	for (int i = 1; i <= n; i++)
	{
		int h = ns[i].h, a = ns[i].a, c = ns[i].c, b = 1;
		while (c - b > 0)
		{
			int nh = h * b;
			for (int j = a; j >= nh; j--)
			{
				dp[j] = max(dp[j], dp[j - nh] + nh);
				ans = max(ans, dp[j]);
			}
			c -= b, b *= 2;
		}
		int nh = h * c;
		for (int j = a; j >= nh; j--)
		{
			dp[j] = max(dp[j], dp[j - nh] + nh);
			ans = max(ans, dp[j]);
		}
	}
	cout << ans << endl;
	return 0;
}