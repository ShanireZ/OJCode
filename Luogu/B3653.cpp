#include <algorithm>
#include <cstdio>
using namespace std;
long long read()
{
	long long ans = 0;
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
long long b[55][55];
int ans[55][55];
int main()
{
	int n = read(), m = read();
	for (register int i = 1; i <= n; i++)
	{
		for (register int j = 1; j <= m; j++)
		{
			b[i][j] = read();
		}
	}
	for (register int i = 1; i <= n; i++)
	{
		for (register int j = 1; j <= m; j++)
		{
			for (register int x = i; x <= n; x++)
			{
				for (register int y = 1; y <= m; y++)
				{
					if (b[i][j] == b[x][y])
					{
						register int d = (i - x) * (i - x) + (j - y) * (j - y);
						ans[i][j] = max(ans[i][j], d);
						ans[x][y] = max(ans[x][y], d);
					}
				}
			}
		}
	}
	for (register int i = 1; i <= n; i++)
	{
		for (register int j = 1; j <= m; j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}