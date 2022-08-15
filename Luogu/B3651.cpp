#include <cstdio>
using namespace std;
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch > '9' || ch < '0')
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
int main()
{
	int n = read(), k = read();
	long long ans = 0;
	for (register int i = 1; i <= n; i++)
	{
		register int x = read();
		ans += (i == k) ? -x : x;
	}
	printf("%lld\n", ans);
	return 0;
}