#include <algorithm>
#include <iostream>
using namespace std;
#define MX 2000005
int a[MX], c[MX], read();
int main()
{
	int t = read();
	while (t--)
	{
		int n = read();
		for (int i = 1; i <= n; i++)
		{
			a[i] = read();
		}
		for (int i = 1; i <= n; i++)
		{
			c[i] = read();
		}
		long long ans = 1e18;
		if (c[1] == c[n])
		{
			ans = a[1] + a[n];
		}
		else
		{
			for (int i = 1; i < n; i++)
			{
				if (c[1] == c[i] && c[i + 1] == c[n])
				{
					ans = min(ans, 0ll + a[1] + a[i] + a[i + 1] + a[n]);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}