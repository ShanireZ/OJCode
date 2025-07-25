#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	int a, b, c;
};
Node ns[1005];
int dp[1005], dp2[1005], ans, n, m;
bool cmp(Node x, Node y)
{
	return x.c < y.c;
}
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].a >> ns[i].b >> ns[i].c;
	}
	sort(ns + 1, ns + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		int st = i, ed = i;
		while (ns[ed + 1].c == ns[st].c)
		{
			ed++;
		}
		fill(dp2, dp2 + m + 1, 0);
		for (int j = st; j <= ed; j++)
		{
			for (int k = m; k >= ns[j].a; k--)
			{
				dp2[k] = max(dp2[k], dp[k - ns[j].a] + ns[j].b);
			}
		}
		for (int j = 1; j <= m; j++)
		{
			dp[j] = max(dp[j], dp2[j]);
		}
		i = ed;
	}
	cout << dp[m] << endl;
	return 0;
}