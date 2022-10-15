#include <iostream>
using namespace std;
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
int pos[1500005];
int main()
{
	int now = 0;
	for (int i = 1; i < 1000; i++)
	{
		int x = i, len = 0, a[5] = {0};
		while (x)
		{
			a[++len] = x % 10;
			x /= 10;
		}
		for (int j = 1; j <= i; j++)
		{
			for (int k = len; k > 0; k--)
			{
				now++;
				pos[now] = pos[now - 1] + a[k];
			}
		}
	}
	int t = read();
	while (t--)
	{
		int l = read(), r = read();
		printf("%d\n", pos[r] - pos[l - 1]);
	}
	return 0;
}