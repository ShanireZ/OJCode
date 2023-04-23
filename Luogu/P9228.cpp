#include <algorithm>
#include <iostream>
using namespace std;
long long read()
{
	long long ans = 0;
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
long long a[1000005], ans, pos;
int main()
{
	long long n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++)
	{
		long long x = read();
		if (x > k)
		{
			a[++pos] = x;
		}
		ans += x;
	}
	for (int i = 1; i <= m; i++)
	{
		ans += read();
	}
	sort(a + 1, a + 1 + pos);
	long long teams = min(n, m);
	for (int i = 1; i <= teams; i++)
	{
		if (pos > 0)
		{
			ans += a[pos--];
		}
		else
		{
			ans += k;
		}
	}
	printf("%lld\n", ans);
	return 0;
}