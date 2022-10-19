#include <iostream>
using namespace std;
int r[1000005];
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
int main()
{
	int n = read(), c = read();
	for (int i = 1; i <= n; i++)
	{
		r[i] = read();
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += max(read() - r[i], 0);
	}
	printf("%lld\n", ans * c);
	return 0;
}