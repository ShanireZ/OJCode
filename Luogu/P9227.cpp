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
long long a[100005];
int main()
{
	long long t = read();
	while (t--)
	{
		long long n = read(), k = read(), all = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i] = read();
			all ^= a[i];
		}
		if (n % 2 == 0 && k % 2 == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%lld ", a[i]);
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%lld ", all ^ a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}